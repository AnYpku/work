
void try(){	

        gROOT->Reset();
        gROOT->SetStyle("Plain");
//      gStyle->SetOptFit(1111);
        gStyle->SetOptStat(00);
        gStyle->SetStripDecimals(kFALSE);
//      gStyle->SetTitleXOffset(1.1);
//      gStyle->SetTitleYOffset(1.1);
        // No Canvas Border
        gStyle->SetCanvasBorderMode(0);
        gStyle->SetCanvasBorderSize(0);
        // White BG
        gStyle->SetCanvasColor(10);
        // Format for axes
        gStyle->SetLabelFont(42,"xyz");
        gStyle->SetLabelSize(0.06,"xyz");
        gStyle->SetLabelOffset(0.01,"xyz");
        gStyle->SetNdivisions(510,"xyz");
        gStyle->SetTitleFont(42,"xyz");
        gStyle->SetTitleColor(1,"xyz");
        gStyle->SetTitleSize(0.07,"xyz");
        gStyle->SetTitleOffset(1.15,"xyz");
        // No pad borders
        gStyle->SetPadBorderMode(0);
        gStyle->SetPadBorderSize(0);
        // White BG
        gStyle->SetPadColor(10);
        // Margins for labels etc.
        gStyle->SetPadLeftMargin(0.17);
        gStyle->SetPadBottomMargin(0.17);
        gStyle->SetPadRightMargin(0.05);
        gStyle->SetPadTopMargin(0.05);
        // No error bars in x direction
//        gStyle->SetErrorX(0);//SetErrorX(Float_t errorx = 0.5)
        // Format legend
        gStyle->SetLegendBorderSize(0);


	TFile *fsig1 = new TFile("/scratchfs/bes/anying/664/omegaeta/signalMC2012/root/Sig50/omegaeta_signalMC_50W.root");
	TTree *tsig1 = (TTree *) fsig1->Get("fit4c");

	TFile *fbkg = new TFile("/scratchfs/bes/anying/664/omegaeta/analysis/rootfiles/root/omegaeta_data.root");
	TTree *tbkg = (TTree *)fbkg->Get("fit4c");

        TH1F *h = new TH1F("background gammaetap", "", 10, 0, 0.05);
//      TH1F(const char* name, const char* title, Int_t nbinsx, Double_t xlow, Double_t xup);
	Double_t Nsig,Nbkg,Ntot,Nsig1;
	Double_t chicut=0.005;
	double Rmax =90;
	Double_t Chi2_cut = 100;

	int  Npoint = 0;
	ofstream SaveFile("bkg_gametp_Ds_output.txt");

	for (Int_t i = 1; i <11; i+=1, chicut += 0.005) {
		char var[600];
		sprintf(var, "abs(egamma1_eta-1.405)>%f", chicut);
                Nsig1 = tsig1->GetEntries(var);
		Nsig=Nsig1;
		Nbkg=tbkg->GetEntries(var);
		Ntot=Nbkg;

		if (Ntot == 0) {
			continue;
		}
		double ratio = 0;
		ratio = Nsig / sqrt(Ntot);
		cout<<"i = "<< i <<";	Nsig = " << Nsig <<";	Ntot = " << Ntot << ";	Nsig/sqrt(Ntot) = "<< ratio << endl;
		SaveFile<<"i = "<< i <<";Nsig = " << Nsig <<";	Ntot = " << Ntot << ";	Nsig/sqrt(Ntot) = "<< ratio << endl;

		if(ratio>Rmax){
			Rmax = ratio;
			Chi2_cut = chicut;
		}
		Npoint ++;

		//h->Fill(chicut, ratio);
		h->SetBinContent(i, ratio);
	}

//        TGraph *h = new TGraph(10,chi2cut,ratio);

	cout<<"************  Rmax = "<<Rmax<<"  Chi2_cut = "<<Chi2_cut<<"  *************"<<endl;
	SaveFile<<"************  Rmax = "<<Rmax<<"  Chi2_cut = "<<Chi2_cut<<"  *************"<<endl;
	cout<<"************  Npoint= "<<Npoint<<"   **************=====>>"<<endl;
	SaveFile<<"************  Npoint= "<<Npoint<<"   **************=====>>"<<endl;
	SaveFile.close();

        TArrow ar(50, 2000, 50, 100, 0.02, "|>");
        ar.SetLineColor(2);
        ar.SetLineWidth(2);
        ar.SetAngle(40);
        ar.SetFillColor(2);
//      ar.SetFillStyle(3008);

        TCanvas *c1 = new TCanvas("bkgcut_opt", "bkgcut_opt", 0, 0, 900, 600);
	c1->cd();

/*
	h->GetXaxis()->SetNdivisions(510);
	h->GetXaxis()->SetTitle("#chi^{2}_{4c}");
	h->GetYaxis()->SetTitle("#frac{S}{#sqrt{(S+B)}} / 1.0");
	h->GetXaxis()->SetTitleColor(9);
	h->GetYaxis()->SetTitleColor(9);
	h->SetLineWidth(2);
	h->SetLineColor(4);
	h->GetXaxis()->SetLabelColor(2);
	h->GetYaxis()->SetLabelColor(2);
	h->GetXaxis()->SetTitleOffset(1.);
	h->GetYaxis()->SetTitleOffset(1.35);
*/
        h->SetXTitle("bkgcut_{opt}");
        h->SetYTitle("#frac{S}{#sqrt{(S+B)}} / 1.0");
        h->SetLineColor(4);
        h->SetMarkerStyle(20);
        h->SetMarkerSize(0.2);
        h->SetLineWidth(2);
        h->GetXaxis()->SetLabelFont(42);
        h->GetXaxis()->SetLabelSize(0.06);
        h->GetXaxis()->SetLabelOffset(0.01);
        h->GetXaxis()->SetNdivisions(510);
        h->GetXaxis()->SetTitleFont(42);
        h->GetXaxis()->SetTitleColor(1);
        h->GetXaxis()->SetTitleSize(0.06);
        h->GetXaxis()->SetTitleOffset(1.13);
        h->GetXaxis()->CenterTitle();
        h->GetYaxis()->CenterTitle();
        h->GetYaxis()->SetTitleSize(0.06);
        h->GetYaxis()->SetTitleOffset(1.30);

	gPad->SetGrid();
	h->Draw("e1");
//	ar.Draw();
	c1->Update();
	c1->Print("/scratchfs/bes/anying/664/omegaeta/analysis/fit/fit_data/bkg_gammaetap_cutOPT.gif");

}

