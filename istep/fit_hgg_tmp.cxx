//fit to hgg from data, to get sigma
//signal PDF: Crystal ball + Gaussian	bkb PDF: Chebyshev
void fit_hgg_tmp()
{
        gSystem->Load("libRooFit");
        using namespace RooFit;
        gStyle->SetOptStat(00);
//========= Set paraments ===========
        Double_t hgg_bins=30;// 100,110,160
        Double_t hgg_low=110;
        Double_t hgg_up =160;
        int dof = 6 ;

        Double_t para[20];
        para[3] = 3.0498e+04 ;  //Nbkg:	expo      N3
        para[5] = 3.3218e+02 ;  //Nsig:	Gaussian  N1
        para[1] = 8.6137e+00 ;  //expo:	a1
        para[2] = 2.0198e+00 ;           //expo:	a2
        para[7] = 1.2419e+02 ;  //mean_GS:	Gaussian
	    para[11]= 1.3614e+00 ;  //sigma_GS

//========== input data ============
        TFile *f1 = new TFile("Hgg.root");
        TTree *t1 = (TTree *)f1->Get("tree");
        RooRealVar hgg("hgg", "", hgg_low, hgg_up);


	TH1F *h1=new TH1F("h1","",hgg_bins,hgg_low,hgg_up);//binned fit
	t1->Project("h1","hgg");// binned fit
	RooDataHist data("data","data", hgg, h1); //binned fit
//========== hgg pdf =============
    RooRealVar mean1("mean_GS",   "", 130,140);
//    RooRealVar mean1("mean_GS",   "",  para[7], 120, 130);
    RooRealVar sigma1("sigma_GS", "",0.25);
    RooGaussian gauss1_pdf("gaussian", "", hgg, mean1, sigma1);

    RooRealVar a1("a1", "",para[1],-500,600);
    RooRealVar a2("a2", "",para[2],-500,500);
    RooGenericPdf expo("expo", "exponential PDF","exp(-(a1*hgg/100)+a2*(hgg/100)^2)",RooArgSet(hgg,a1,a2));

    RooRealVar N3("Nbkg", "", para[3], 20000,  40000);
    RooRealVar N1("Nsig",  "", 10,0,20);
    
    RooRealVar p0("p0_Cheby", "",-7.5382e-01 ,-1, 1 );
    RooRealVar p1("p1_Cheby", "",1.9755e-01 ,-1, 1 );
    RooRealVar p2("p2_Cheby", "",-3.6755e-02 ,-1, 1 );
//    RooRealVar p3("p3_Cheby", "",-3.6755e-02 ,-1, 1 );
    RooChebychev bkg_pdf("bkg_pdf", "", hgg, RooArgList(p0,p1,p2));
//    RooChebychev bkg_pdf("bkg_pdf", "", hgg, RooArgList(p0,p1));
    
    RooAddPdf sum("sum","signalPDF + Cheby PDF",RooArgList(gauss1_pdf, bkg_pdf),RooArgList(N1,N3));

    RooFitResult *fitres = sum.fitTo(data, Save(kTRUE), Extended());
	fitres->Print("v");//Need "Save(kTRUE)"
//============== plot hgg ============
    RooPlot *frame_hgg = hgg.frame(Name("hehe"), Bins(hgg_bins), Range(hgg_low, hgg_up));
    data.plotOn(frame_hgg,Name("data"),MarkerColor(kBlack), MarkerSize(1.0),DataError(RooAbsData::SumW2));
    sum.plotOn(frame_hgg,Name("sum"),LineColor(kRed) ) ;
    double chi2_hgg = frame_hgg->chiSquare(dof);

    TPaveText *pt2 = new TPaveText(0.21, 0.30, 0.31, 0.40, "BRNDC");
    pt2->SetBorderSize(0);
    pt2->SetFillColor(0);
    pt2->SetTextAlign(12);
    pt2->SetTextSize(0.04);
    pt2->SetTextFont(22);
    TString Par5V2 = Form("%2.1f", frame_hgg->chiSquare(dof) );
    TString Par52 = "#chi^{2}#/d.o.f = " + Par5V2;
    TText *text2 = pt2->AddText(Par52);

    cout << "chi2_hgg/ndf = " << chi2_hgg << endl;
    sum.plotOn(frame_hgg, Name("signal"),Components(gauss1_pdf), LineColor(kGreen));
    sum.plotOn(frame_hgg, Name("bkg"),Components(bkg_pdf), LineColor(kBlue),LineStyle(2));
	sum.paramOn(frame_hgg, Parameters(RooArgSet(N1,N3,mean1,sigma1)), RooFit::Layout(0.6, 0.98));
    TCanvas *c_hgg = new TCanvas("hgg", "hgg",0,0,900,600);
    c_hgg->SetLeftMargin(0.15);
    c_hgg->SetRightMargin(0.06);
    c_hgg->SetTopMargin(0.03);
    c_hgg->SetBottomMargin(0.16);
    c_hgg->SetFillColor(0);
    c_hgg->Divide(1,1);
    c_hgg->cd(1);
    TLegend *leg1 = new TLegend(0.62,0.45,0.81,0.66);
    leg1->SetFillColor(kWhite);
    leg1->SetLineColor(kWhite);
    leg1->SetTextFont(32);
    leg1->SetTextSize(0.045);

    TH1D* h2 = new TH1D("h2","h2",100,0,100);h2->SetLineColor(kRed);
    TH1D* hh1 = new TH1D("hh1","h2",100,0,100);hh1->SetLineColor(kBlack);hh1->SetMarkerStyle(20);
    TH1D* h3 = new TH1D("h3","h2",100,0,100);h3->SetLineColor(kBlue);h3->SetLineStyle(2);
    TH1D* h4 = new TH1D("h4","h2",100,0,100);h4->SetLineColor(kGreen);
    leg1->AddEntry(hh1,"Data", "lP");
    leg1->AddEntry(h2,"Signal + background","l");
    leg1->AddEntry(h3,"Background only", "lp");
    leg1->AddEntry(h4,"Signal only", "l");
    leg1->Draw();
    frame_hgg->SetTitle("");
    frame_hgg->SetYTitle("Events / 1.67GeV/c^{2}");
    frame_hgg->SetXTitle("M_{#gamma#gamma} (GeV/c^{2})");
    frame_hgg->GetXaxis()->SetLabelFont(22);
    frame_hgg->GetXaxis()->SetLabelSize(0.04);
    frame_hgg->GetXaxis()->SetLabelOffset(0);
    frame_hgg->GetXaxis()->SetNdivisions(510);
    frame_hgg->GetXaxis()->SetTitleFont(32);
    frame_hgg->GetXaxis()->SetTitleColor(1);
    frame_hgg->GetXaxis()->SetTitleSize(0.05);
    frame_hgg->GetXaxis()->SetTitleOffset(0.73);
    frame_hgg->GetXaxis()->CenterTitle();
    frame_hgg->GetYaxis()->CenterTitle();
    frame_hgg->GetYaxis()->SetLabelFont(22);
    frame_hgg->GetYaxis()->SetLabelSize(0.04);
    frame_hgg->GetYaxis()->SetLabelOffset(0);
    frame_hgg->GetYaxis()->SetNdivisions(510);
    frame_hgg->GetYaxis()->SetTitleFont(32);
    frame_hgg->GetYaxis()->SetTitleColor(1);
    frame_hgg->GetYaxis()->SetTitleSize(0.05);
    frame_hgg->GetYaxis()->SetTitleOffset(0.9);

    TArrow* myar1 = new TArrow(121.455, 431, 121.455, 703.039, 0.03, "<|");//hgg=0.135, 3sigma=0.02, [0.115,0.155]
     myar1->SetLineColor(2);
     myar1->SetLineWidth(3);
     myar1->SetAngle(40);
     myar1->SetFillColor(2);
     TArrow* myar2 = new TArrow(126.973, 360.229, 127, 665.803, 0.03, "<|");
     myar2->SetLineColor(2);
     myar2->SetLineWidth(3);
     myar2->SetAngle(40);
     myar2->SetFillColor(2);
     TArrow* myar3 = new TArrow(0.09, 10000, 0.09, 200, 0.04, "|>");//sideband,[0.09,0.11]
     myar3->SetLineColor(4);
     myar3->SetLineWidth(3);
     myar3->SetAngle(40);
     myar3->SetFillColor(4);
     TArrow* myar4 = new TArrow(0.11, 10000, 0.11, 200, 0.04, "|>");
     myar4->SetLineColor(4);
     myar4->SetLineWidth(3);
     myar4->SetAngle(40);
     myar4->SetFillColor(4);
     TArrow* myar5 = new TArrow(0.16, 10000, 0.16, 200, 0.04, "|>");//sideband,[0.16,0.18]
     myar5->SetLineColor(4);
     myar5->SetLineWidth(3);
     myar5->SetAngle(40);
     myar5->SetFillColor(4);
     TArrow* myar6 = new TArrow(0.18, 10000, 0.18, 200, 0.04, "|>");
     myar6->SetLineColor(4);
     myar6->SetLineWidth(3);
     myar6->SetAngle(40);
     myar6->SetFillColor(4);
//     frame_hgg->addObject(myar1);
//     frame_hgg->addObject(myar2);
//     frame_hgg->addObject(myar3);
//     frame_hgg->addObject(myar4);
//     frame_hgg->addObject(myar5);
     frame_hgg->addObject(leg1);

        frame_hgg->Draw();
        pt2->Draw();
	  c_hgg->Print("fit_hgg-test2.pdf");

//        hgg.setRange("MassWindow",0.11497,0.15497);
//        RooAbsReal* nsig_masswindow = sig_sum.createIntegral(hgg,NormSet(hgg),Range("MassWindow"));
//        Int_t Nsig_masswindow = N1.getVal()*(nsig_masswindow->getVal());

//        hgg.setRange("AllRegion",0.05,0.22);
//        RooAbsReal* nsig_allregion = sig_sum.createIntegral(hgg,NormSet(hgg),Range("AllRegion"));
//        Int_t Nsig_allregion = N1.getVal()*(nsig_allregion->getVal());

//        cout<<"================================"<<endl;
//        cout<<"Nsig_masswindow = "<<Nsig_masswindow<<endl;
//        cout<<"Nsig_allregion  = "<<Nsig_allregion<<endl;
//        cout<<"The selection efficiency = "<<(double)(Nsig_masswindow)/(double)(Nsig_allregion)<<endl;

}

