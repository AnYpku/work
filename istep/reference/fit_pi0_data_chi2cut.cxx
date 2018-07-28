//fit to pi0 from data, to get sigma
//signal PDF: Crystal ball + Gaussian	bkb PDF: Chebyshev
void fit_pi0_data_chi2cut()
{
        gSystem->Load("libRooFit");
        using namespace RooFit;
        gStyle->SetOptStat(00);
//========= Set paraments ===========
        Double_t pi0_bins=170;// 170,0.05,0.22
        Double_t pi0_low=0.05;
        Double_t pi0_up =0.22;
        int dof = 11 ;

        Double_t para[20];
        para[1] = 2.6359e+00 ;  //CB_a:	Crystal ball
        para[2] = 4.5239e-01 ;  //CB_n:	Crystal ball
        para[3] = 1.4371e+06 ;  //Nbkg:	Chebyshev
        para[4] = 3.8146e-01 ;  //Nfrac: 	GS:(GS+CB)
        para[5] = 3.9693e+06 ;  //Nsig:	Gaussian
        para[6] = 1.3453e-01 ;  //mean_CB: 	Crystal ball
        para[7] = 1.3441e-01 ;  //mean_GS:	Gaussian
        para[8] = 2.4042e-01 ;  //p0_Cheby
        para[9] =-2.1140e-01 ;  //p1_Cheby
	para[10]= 3.9178e-03 ;  //sigma_CB
	para[11]= 7.2686e-03 ;  //sigma_GS

//========== input data ============
        TFile *f1 = new TFile("/scratchfs/bes/anying/664/omegaeta/analysis/fit/fit_data/select/omegaeta_data_ONEcut.root");
        TTree *t1 = (TTree *)f1->Get("fit4c");
        RooRealVar mpi0("mpi0", "", pi0_low, pi0_up);

//	RooDataSet data("data", "data", t1, RooArgSet(mpi0));//unbinned fit

	TH1F *h1=new TH1F("h1","",pi0_bins,pi0_low,pi0_up);//binned fit
	t1->Project("h1","mpi0");// binned fit
	RooDataHist data("data","data", mpi0, h1); //binned fit
//========== pi0 pdf =============
        RooRealVar mean1("mean_GS",   "",  para[7],  0.12, 0.15);
        RooRealVar sigma1("sigma_GS", "",  para[11],   0., 0.01);
        RooGaussian gauss1_pdf("gaussian", "", mpi0, mean1, sigma1);

	RooRealVar mean2("mean_CB",  "",  para[6],  0.12, 0.15 );
	RooRealVar sigma2("sigma_CB","",  para[10],  0.0, 0.01 );
	RooRealVar a2("CB_a", "",  para[1], 2.0,  3.0 );
	RooRealVar n2("CB_n", "",  para[2], -1.0,  1.0 );
	RooCBShape CB_pdf("cb", "", mpi0, mean2, sigma2, a2, n2 );

        RooRealVar p0("p0_Cheby", "", para[8], -1, 1 );
        RooRealVar p1("p1_Cheby", "", para[9], -1, 1 );
        RooChebychev bkg_pdf("bkg_pdf", "", mpi0, RooArgList(p0,p1));

        RooRealVar N1("Nsig", "",    para[5], 0,  4000000);
        RooRealVar N3("Nbkg",  "",   para[3], 0,  1500000);
        RooRealVar Nf("Nfrac",  "",  para[4], 0, 1.0);

        RooAddPdf sig_sum("sum of sig","gauss + CB",RooArgList(gauss1_pdf , CB_pdf),RooArgList(Nf));
        RooAddPdf sum("sum","signalPDF + bkgPDF",RooArgList(sig_sum, bkg_pdf),RooArgList(N1,N3));
//        RooAddPdf sum("sum","signalPDF + bkgPDF",RooArgList(gauss1_pdf, bkg_pdf),RooArgList(N1,N3));

        RooFitResult *fitres = sum.fitTo(data, Save(kTRUE), Extended());
	fitres->Print("v");//Need "Save(kTRUE)"
//============== plot pi0 ============
        RooPlot *frame_mpi0 = mpi0.frame(Name("hehe"), Bins(pi0_bins), Range(pi0_low, pi0_up));
        data.plotOn(frame_mpi0,MarkerColor(kBlack), MarkerSize(1.0),DataError(RooAbsData::SumW2));
        sum.plotOn(frame_mpi0,LineColor(kRed) ) ;
        double chi2_mpi0 = frame_mpi0->chiSquare(dof);

        TPaveText *pt2 = new TPaveText(0.20, 0.50, 0.40, 0.60, "BRNDC");
        pt2->SetBorderSize(0);
        pt2->SetFillColor(0);
        pt2->SetTextAlign(12);
        pt2->SetTextSize(0.04);
        pt2->SetTextFont(42);
        TString Par5V2 = Form("%2.1f", frame_mpi0->chiSquare(dof) );
        TString Par52 = "#chi^{2}#/d.o.f = " + Par5V2;
        TText *text2 = pt2->AddText(Par52);

        cout << "chi2_mpi0/ndf = " << chi2_mpi0 << endl;
        sum.plotOn(frame_mpi0, Components(gauss1_pdf), LineColor(3));
//        sum.plotOn(frame_mpi0, Components(CB_pdf), LineColor(7));
//        sum.plotOn(frame_mpi0, Components(bkg_pdf), LineColor(4), LineStyle(2));
//	sum.paramOn(frame_mpi0, Parameters(RooArgSet(N1,Nf,mean1,mean2,sigma1,sigma2 )), RooFit::Layout(0.6, 0.98));
        TCanvas *c_mpi0 = new TCanvas("mpi0", "mpi0",0,0,900,600);
        c_mpi0->SetLeftMargin(0.15);
        c_mpi0->SetRightMargin(0.06);
        c_mpi0->SetTopMargin(0.03);
        c_mpi0->SetBottomMargin(0.16);
        c_mpi0->SetFillColor(0);
        c_mpi0->Divide(1,1);
        c_mpi0->cd(1);

        frame_mpi0->SetTitle("");
        frame_mpi0->SetYTitle("Events / 1.0MeV/c^{2}");
        frame_mpi0->SetXTitle("M(#gamma#gamma) (GeV/c^{2})");
        frame_mpi0->GetXaxis()->SetLabelFont(42);
        frame_mpi0->GetXaxis()->SetLabelSize(0.06);
        frame_mpi0->GetXaxis()->SetLabelOffset(0.01);
        frame_mpi0->GetXaxis()->SetNdivisions(510);
        frame_mpi0->GetXaxis()->SetTitleFont(42);
        frame_mpi0->GetXaxis()->SetTitleColor(1);
        frame_mpi0->GetXaxis()->SetTitleSize(0.07);
        frame_mpi0->GetXaxis()->SetTitleOffset(1.15);
        frame_mpi0->GetXaxis()->CenterTitle();
        frame_mpi0->GetYaxis()->CenterTitle();

        TArrow* myar1 = new TArrow(0.115, 100000, 0.115, 20000, 0.04, "|>");//mpi0=0.135, 3sigma=0.02, [0.115,0.155]
        myar1->SetLineColor(2);
        myar1->SetLineWidth(3);
        myar1->SetAngle(40);
        myar1->SetFillColor(2);
        TArrow* myar2 = new TArrow(0.155, 100000, 0.155, 20000, 0.04, "|>");
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
        frame_mpi0->addObject(myar1);
        frame_mpi0->addObject(myar2);
//        frame_mpi0->addObject(myar3);
//        frame_mpi0->addObject(myar4);
//        frame_mpi0->addObject(myar5);
//        frame_mpi0->addObject(myar6);

        frame_mpi0->Draw();
//        pt2->Draw();
	c_mpi0->Print("/scratchfs/bes/anying/664/omegaeta/analysis/fit_pi0_inMC_chi2cut.pdf");

//        mpi0.setRange("MassWindow",0.11497,0.15497);
//        RooAbsReal* nsig_masswindow = sig_sum.createIntegral(mpi0,NormSet(mpi0),Range("MassWindow"));
//        Int_t Nsig_masswindow = N1.getVal()*(nsig_masswindow->getVal());

//        mpi0.setRange("AllRegion",0.05,0.22);
//        RooAbsReal* nsig_allregion = sig_sum.createIntegral(mpi0,NormSet(mpi0),Range("AllRegion"));
//        Int_t Nsig_allregion = N1.getVal()*(nsig_allregion->getVal());

//        cout<<"================================"<<endl;
//        cout<<"Nsig_masswindow = "<<Nsig_masswindow<<endl;
//        cout<<"Nsig_allregion  = "<<Nsig_allregion<<endl;
//        cout<<"The selection efficiency = "<<(double)(Nsig_masswindow)/(double)(Nsig_allregion)<<endl;

}

