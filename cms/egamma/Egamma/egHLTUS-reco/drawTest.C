 Double_t etbins[6]={0,30,60,80,200,400};
 Double_t barreletabins[5]={0,0.4,0.8,1.2,1.5};
 Double_t endcapetabins[5]={1.5,1.75,2.0,2.25,2.5};
void draw(int j,int i){
    TString n1 = "50_120_barrel_";
    TString split = Form("%0.f<et<%0.f and %.2f<eta<%.2f",etbins[i],etbins[i+1],barreletabins[j],barreletabins[j+1]);
    TString figname = n1 + Form("et_%0.f_%0.f_eta_%.2f_%.2f",etbins[i],etbins[i+1],barreletabins[j],barreletabins[j+1]);
	TFile* f1 = new TFile("./Splitfiles/"+n1+Form("et_%0.f_%0.f-eta_%.2f_%.2f.root",etbins[i],etbins[i+1],barreletabins[j],barreletabins[j+1]));
//	TFile* f1 = new TFile("120_200_endcap.root");
//	TFile* f1 = new TFile("50_120_barrel.root");
//	TFile* f1 = new TFile("50_120_endcap.root");
	TString filename = f1->GetName();
	TH1D*het[2];
	TH1D*heta[2];
	TH1D*hnrgy[2];
	TH1D*hphi[2];
	TH1D*hdeta[2];
	TH1D*hdphi[2];
	TH1D*hsieie[2];
	TH1D*hmhits[2];
	TH1D*h3[8];
//	TEfficiency* h3[8];
	TLegend *l1[8];
    TCanvas* c1[8];
	vector<TH1D*> hele;vector<TH1D*> hegHLT;
	het[0] = (TH1D*)f1->Get("hclusEt_ele");hele.push_back(het[0]);
	het[1] = (TH1D*)f1->Get("het_eghlt");  hegHLT.push_back(het[1]);
	heta[0] = (TH1D*)f1->Get("hdetEta_ele");hele.push_back(heta[0]);
	heta[1] = (TH1D*)f1->Get("heta_eghlt");hegHLT.push_back(heta[1]);
	hnrgy[0] = (TH1D*)f1->Get("hclusNrgy_ele");hele.push_back(hnrgy[0]);
	hnrgy[1] = (TH1D*)f1->Get("hnrgy_eghlt");hegHLT.push_back(hnrgy[1]);
	hphi[0] = (TH1D*)f1->Get("hdetPhi_ele");hele.push_back(hphi[0]);
	hphi[1] = (TH1D*)f1->Get("hphi_eghlt");hegHLT.push_back(hphi[1]);
	hdeta[0] = (TH1D*)f1->Get("hdEtaInSeed_ele");hele.push_back(hdeta[0]);
	hdeta[1] = (TH1D*)f1->Get("hetain_eghlt");hegHLT.push_back(hdeta[1]);
	hdphi[0] = (TH1D*)f1->Get("hPhiIn_ele");hele.push_back(hdphi[0]);
	hdphi[1] = (TH1D*)f1->Get("hphiin_eghlt");hegHLT.push_back(hdphi[1]);
	hsieie[0] = (TH1D*)f1->Get("hsieie_ele");hele.push_back(hsieie[0]);
	hsieie[1] = (TH1D*)f1->Get("hsieie_eghlt");hegHLT.push_back(hsieie[1]);
	hmhits[0] = (TH1D*)f1->Get("hMHits_ele");hele.push_back(hmhits[0]);
	hmhits[1] = (TH1D*)f1->Get("hMHits_eghlt");hegHLT.push_back(hmhits[1]);
	char hname[51];
	for(int i=0;i<3;i++){
//		if(TEfficiency::CheckConsistency(*hele[i], *hegHLT[i]))
//			h3[i] = new TEfficiency(*hele[i],*hegHLT[i]);

		TString name = hegHLT[i]->GetTitle();
		cout<<name<<endl;
		c1[i] = new TCanvas(hname,name,900,600);
		l1[i] = new TLegend(0.6,0.7,0.9,0.9);

		hele[i]->SetTitle(name+"\t"+split);
		hele[i]->SetLineColor(kAzure+6);
		hele[i]->SetLineWidth(3);
//		hele[i]->SetMarkerStyle(20);
		double norm1 =  hele[i]->GetEntries();
//		hele[i]->Scale(1/norm1);
		hegHLT[i]->SetLineColor(kAzure-2);
		hegHLT[i]->SetLineWidth(4);
		hegHLT[i]->SetLineStyle(5);
//		hegHLT[i]->SetMarkerStyle(20);
		double norm2 =  hegHLT[i]->GetEntries();
//		hegHLT[i]->Scale(1/norm2);
		double elemax  = hele[i]->GetMaximum();
		double egHLTmax  = hegHLT[i]->GetMaximum();
//		hegHLT[i]->DrawNormalized("hist");
//		hele[i]->DrawNormalized("hist same");

        if(elemax > egHLTmax ){
            hele[i]->DrawNormalized("hist");
            hegHLT[i]->DrawNormalized("hist same");
        }
		else{
			hegHLT[i]->DrawNormalized("hist");
			hele[i]->DrawNormalized("hist same");
		}
		l1[i]->AddEntry(hele[i],"reco ele");
		l1[i]->AddEntry(hegHLT[i],"HLT ele");
		l1[i]->SetBorderSize(1);
		l1[i]->SetFillColor(0);

		c1[i]->cd();
		c1[i]->SetGrid();

		l1[i]->Draw();
		c1[i]->Draw();
		c1[i]->Print("./"+figname+name+".pdf");
	}
}
void Style(){
       gStyle->SetPadBorderMode(0);
       gStyle->SetOptStat(0);
       gStyle->SetPadGridX(1);
       gStyle->SetPadGridY(1);
       gStyle->SetPadTickX(1);
       gStyle->SetPadTickY(1);
       gStyle->SetPadTopMargin(0.07);
       gStyle->SetPadBottomMargin(0.3);
       gStyle->SetPadRightMargin(0.05);
       gStyle->SetPadLeftMargin(0.14);
       gStyle->SetPadTickX(1);
       gStyle->SetPadTickY(1);
       gStyle->SetAxisColor(1, "XYZ");
       gStyle->SetStripDecimals(kTRUE);
       gStyle->SetTickLength(0.03, "XYZ");
       gStyle->SetNdivisions(510, "XYZ");
}
int drawTest(){
	Style();
    for(int j=0;j<4;j++){
        for(int i=0;i<5;i++){
            draw(j,i);
        }
    }
	return 1;

}
