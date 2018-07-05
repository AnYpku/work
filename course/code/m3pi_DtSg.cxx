{
	gStyle->SetOptStat(00);
	TCut cut1 = "chi2<50";//100
	TCut cut2 = "abs(mpi0-0.1349766)<0.015";
	TCut cut3 = "abs(meta-0.55)<0.1&&abs(m3pi-0.775)<0.125";
	TCut mycut= cut1&&cut2&&cut3;
	Double_t xlow = 0.5 , xhigh = 1.5 ;//200(0.9,2.1)
	Int_t xbins = 100;
	
	TFile *f1= new TFile("/scratchfs/bes/anying/664/omegaeta/analysis/rootfiles/root/omegaeta_signal09MC.root");//red
	TFile *f2= new TFile("/scratchfs/bes/anying/664/omegaeta/analysis/rootfiles/root/omegaeta_inMC.root");      //green
	TFile *f3= new TFile("/scratchfs/bes/anying/664/omegaeta/analysis/rootfiles/root/gammaetap.root");          //black
	TFile *f4= new TFile("/scratchfs/bes/anying/664/omegaeta/analysis/rootfiles/root/omegaeta_data.root");      //blue

        TTree *tree1=(TTree *)f1->Get("fit4c");
        TTree *tree2=(TTree *)f2->Get("fit4c");
        TTree *tree3=(TTree *)f3->Get("fit4c");
        TTree *tree4=(TTree *)f4->Get("fit4c");

        TH1F *job1 = new TH1F("Entry1", "", xbins, xlow, xhigh);
        TH1F *job2 = new TH1F("Entry2", "", xbins, xlow, xhigh);
        TH1F *job3 = new TH1F("Entry3", "", xbins, xlow, xhigh);
        TH1F *job4 = new TH1F("Entry4", "", xbins, xlow, xhigh);

//        tree1->Project("Entry1","m3pi",mycut);
//        tree2->Project("Entry2","m3pi",mycut);
//        tree3->Project("Entry3","m3pi",mycut);
//        tree4->Project("Entry4","m3pi",mycut);

//        tree1->Project("Entry1","mgamma2omega",mycut);
//        tree2->Project("Entry2","mgamma2omega",mycut);
//        tree3->Project("Entry3","mgamma2omega",mycut);
//        tree4->Project("Entry4","mgamma2omega",mycut);

        tree1->Project("Entry1","egamma1_eta",mycut);
        tree2->Project("Entry2","egamma1_eta",mycut);
        tree3->Project("Entry3","egamma1_eta",mycut);
        tree4->Project("Entry4","egamma1_eta",mycut);

//        tree1->Project("Entry1","egamma2_eta",mycut);
//        tree2->Project("Entry2","egamma2_eta",mycut);
//        tree3->Project("Entry3","egamma2_eta",mycut);
//        tree4->Project("Entry4","egamma2_eta",mycut);

        TArrow arrow1(1.6,4300,1.6, 0,0.02,"|>");
        arrow1.SetLineColor(2);
        arrow1.SetLineWidth(2);
        arrow1.SetAngle(40);
        arrow1.SetFillColor(2);

        TArrow arrow2(1.9,4300,1.9,0,0.02,"|>");
        arrow2.SetLineColor(2);
        arrow2.SetLineWidth(2);
        arrow2.SetAngle(40);
        arrow2.SetFillColor(2);
	
	TCanvas *c1 = new TCanvas("c1","Mass Spectrum",0,0,900,600);
	c1.cd();
//	c1.SetGrid(1,1);// 坐标线
//	job1->SetFillColor(kGreen);
//        job4->SetXTitle("M(#gamma2_{#eta}) (GeV/c^{2})");
        job4->SetXTitle("M(#gamma1_{#eta}) (GeV/c^{2})");
//        job4->SetXTitle("M(#gamma2_{#eta}#omega) (GeV/c^{2})");
//        job4->SetXTitle("M(#pi^{+}#pi^{-}#pi^{0}) (GeV/c^{2})");
        job4->SetYTitle("Events / 9 MeV/c^{2}");
        job4->SetLineColor(2);
        job4->SetMarkerStyle(20);
        job4->SetMarkerSize(1);
        job4->SetLineWidth(2);
        job4->GetXaxis()->SetLabelFont(42);
        job4->GetXaxis()->SetLabelSize(0.06);
        job4->GetXaxis()->SetLabelOffset(0.01);
        job4->GetXaxis()->SetNdivisions(510);
        job4->GetXaxis()->SetTitleFont(42);
        job4->GetXaxis()->SetTitleColor(1);
        job4->GetXaxis()->SetTitleSize(0.07);
        job4->GetXaxis()->SetTitleOffset(1.15);
        job4->GetXaxis()->CenterTitle();
        job4->GetYaxis()->CenterTitle();

        job2->SetLineColor(3);
        job2->SetMarkerStyle(20);
        job2->SetMarkerSize(1);
        job2->SetLineWidth(2);
	job2->Scale(job4->GetMaximum()/job2->GetMaximum());
//	job2->Scale(job3->Integral()/job2->Integral());
//	job2->Scale(0.7*(job1->GetBinContent(64)/job2->GetBinContent(64)));//64=(1.285-0.9)/0.006
	
        job3->SetLineColor(1);
        job3->SetMarkerStyle(20);
        job3->SetMarkerSize(1);
        job3->SetLineWidth(2);
	job3->Scale(job4->GetMaximum()/job3->GetMaximum());
//	job1->Scale(job3->Integral()/job1->Integral());
//	job1->Scale(0.7*(job1->GetBinContent(64)/job3->GetBinContent(64)));//64=(1.285-0.9)/0.006

        job1->SetLineColor(4);
        job1->SetMarkerStyle(20);
        job1->SetMarkerSize(1);
        job1->SetLineWidth(2);
	job1->Scale(job4->GetMaximum()/job1->GetMaximum());
////	job1->Scale(job3->Integral()/job4->Integral());
////	job1->Scale(0.7*(job4->GetBinContent(64)/job1->GetBinContent(64)));//64=(1.285-0.9)/0.006

	TLegend *lg1 = new TLegend(0.2,0.7,0.4,0.9);
        lg1->AddEntry(job1,"signalMC","l");
        lg1->AddEntry(job2,"inMC","l");
        lg1->AddEntry(job3,"gammaetap","l");
        lg1->AddEntry(job4,"data","l");
        lg1->SetFillColor(0);
        lg1->SetTextFont(42);

        job4->Draw();//e1
	job2->Draw("same");
        job3->Draw("same");
	job1->Draw("same");
	lg1->Draw();
//	arrow1.Draw();
//	arrow2.Draw();
	c1->cd();
	c1->Update();
//	c1->Print("./m3pi_DinSg_omegaeta.gif");
//	c1->Print("./mgamma2omega_DinSg_omegaeta.gif");
	c1->Print("./egamma1_eta_DinSg_omegaeta.gif");
//	c1->Print("./egamma2_eta_DinSg_omegaeta.gif");
}

