void qinn_HistFit_1d()
{
        gSystem->Load("libRooFit"); 
        using namespace RooFit;

        TCanvas *c= new TCanvas("myCanvas");
        c->SetLeftMargin(0.15);
        c->SetRightMargin(0.06);
        c->SetTopMargin(0.03);
        c->SetBottomMargin(0.16);
        c->SetFillColor(0); 
        c->Divide(1,1); 
        TChain *chain1 = new TChain("fit4c");
        chain1->Add("/scratchfs/bes/qinn/run664/PhiGamPiPi/newroot/fit_cut_data_sum.root");
        TTree* t1data = chain1;

        TChain *chain2 = new TChain("fit4c");
        chain2->Add("/scratchfs/bes/qinn/run664/PhiGamPiPi/newroot/fit_cut_signalMC_sum.root");
        TTree* t2mcsig = chain2;

        Double_t nbins=400;
        Double_t xlow=0.99; 
        Double_t xup =1.07; 

        TH1F *h1=new TH1F("h1","data_PhiGamPiPi_kpkm",nbins,xlow,xup);
        TH1F *h2=new TH1F("h2","mcsig_PhiGamPiPi_kpkm",nbins,xlow,xup);        

        TString cut1= "( mkpkm<1.08)";
        TString cut2= "( abs(mgampippim-0.958)<0.02)";
        TString cut3= "( chi2<50)";
        TString cutsd= "( (abs(mgampippim-0.958)>0.05)&&(abs(mgampippim-0.958)<0.07))";

        TString   a  = cut1 + " && " +cut2 + " && " +cut3;
        TString   sd = cut1 + " && " +cutsd+ " && " +cut3;
        c->cd(1);

        t1data ->Draw("mkpkm>>h1",a);
        t2mcsig->Draw("mkpkm>>h2",a);

        RooRealVar mkpkm("mkpkm","m(K^{+}K^{-})(GeV)",xlow,xup) ;

        RooRealVar   mean_1("mean_1",   "mean_1",  1.019455, 1.0,1.03);
        RooRealVar   width("width", "width", 0.00426, 0.0, 0.009);
        RooRealVar   sig("sig",     "sig", 6.16681e-03, 0.0, 0.5 );
        RooVoigtian  bw_hpdf("bw_hpdf","bw_hpdf", mkpkm, mean_1, width,sig);

        RooDataHist mcsig("mcsig","mcsig",mkpkm,h2);
        RooHistPdf mcsig_hpdf("mcsig_hpdf","mcsig_hpdf", RooArgSet(mkpkm), mcsig);

        RooRealVar mean("mean", "mean",   1.78e-4, 0., 0.001);
        RooRealVar sigma("sigma", "sigma",5.18e-4, 0., 0.001);
        RooGaussian gaussian("gaussian", "gaussian", mkpkm, mean, sigma);
        mkpkm.setBins(10000, "cache");
        RooFFTConvPdf sg_x_gauss_hpdf("sg_x_gauss_hpdf", "sg_x_gauss_hpdf", mkpkm, mcsig_hpdf,gaussian);

        RooRealVar c0("c0","coeffiicient #0",6.05137e-01,-10,10.) ;
        RooRealVar c1("c1","coefficienct #1",7.32877e-02,-10,10.) ;
        RooChebychev bkg_pdf("bkg_pdf","bkg_pdf",mkpkm,RooArgList(c0,c1));

        RooRealVar Nbw ("Nbw","Nbw",           0, 40000);
        RooRealVar Nbkg ("Nbkg","Nbkg", 1472,  0, 40000);
        RooRealVar Nsig ("Nsig","Nsig", 29768, 0, 40000);

        RooAddPdf sum("sum","signal + sideband",RooArgList(sg_x_gauss_hpdf,bkg_pdf),RooArgList(Nsig,Nbkg)) ;

        RooDataHist data("data","data", mkpkm,h1); //bin fit
//        RooDataSet data("data", "data", t1data, mkpkm); //unbin fit
        RooFitResult* rx = sum.fitTo(data,Extended(), Save(kTRUE)) ;

        RooPlot* mesframe = mkpkm.frame(Name("mesframe"),Title("Hist Bin Fit")) ;
        data.plotOn(mesframe,MarkerColor(kBlack), MarkerSize(0.8),DataError(RooAbsData::SumW2));
        sum.plotOn(mesframe,LineColor(kRed) ) ;
        Double_t chi2 = mesframe->chiSquare(6);
        
        TPaveText *pt = new TPaveText(0.60, 0.30, 0.90, 0.40, "BRNDC");
        pt->SetBorderSize(1);
        pt->SetFillColor(19);
        pt->SetTextAlign(12);
        pt->SetTextSize(0.04);
        TString Par5V = Form("%2.3f", mesframe->chiSquare(6) );
        TString Par5 = "#chi^{2}#/d.o.f = " + Par5V;
        TText *text = pt->AddText(Par5);
  
        sum.plotOn(mesframe, Components("sg_x_gauss_hpdf"),LineColor(3));
        sum.plotOn(mesframe, Components("bkg_pdf"),LineStyle(kDashed));
	sum.paramOn(mesframe, RooFit::Layout(0.6, 0.98));
        mesframe->Draw() ;
        pt->Draw();
        cout<<"chi2/ndf = "<<chi2<<endl;  
        cout<<"============= Fit Done! ============= "<<endl;  
//        c->Print("test/myfit.eps");

}

