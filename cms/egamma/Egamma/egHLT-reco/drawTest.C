 Double_t etbins[7]={0,20,30,50,100,200,400};     
 Double_t barreletabins[7]={0,0.5,1.0,1.4442,1.566,2.0,2.5};
 Double_t endcapetabins[5]={1.5,1.75,2.0,2.25,2.5};
void draw(int j,int i){
    TString n1 = "50_120_";
    TString split = Form("%0.f<et<%0.f and %.2f<eta<%.2f",etbins[i],etbins[i+1],barreletabins[j],barreletabins[j+1]);
    TString figname = n1 + Form("et_%0.f_%0.f_eta_%.2f_%.2f",etbins[i],etbins[i+1],barreletabins[j],barreletabins[j+1]);
	TFile* f1 = new TFile("./Splitfiles/splits/"+n1+Form("et_%0.f_%0.f-eta_%.2f_%.2f.root",etbins[i],etbins[i+1],barreletabins[j],barreletabins[j+1]));
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
	for(int k=0;k<3;k++){
//		if(TEfficiency::CheckConsistency(*hele[k], *hegHLT[k]))
//			h3[k] = new TEfficiency(*hele[k],*hegHLT[k]);

		TString name = hegHLT[k]->GetTitle();
		cout<<name<<endl;
		c1[k] = new TCanvas(Form("c_%i",k),name,900,600);
		l1[k] = new TLegend(0.6,0.7,0.9,0.9);

		hele[k]->SetTitle(name+"\t"+split);
		hele[k]->SetLineColor(kAzure+6);
		hele[k]->SetLineWidth(3);
		hegHLT[k]->SetTitle(name+"\t"+split);
		hegHLT[k]->SetLineColor(kAzure+6);
		hegHLT[k]->SetLineWidth(3);
		hegHLT[k]->GetXaxis()->SetTitle(name);
        if(name.Contains("et")==1&&name.Contains("eta")==0)
            hegHLT[k]->GetXaxis()->SetRangeUser(etbins[i],2*etbins[i+1]);
        if(name.Contains("eta")==1)
            hegHLT[k]->GetXaxis()->SetRangeUser(barreletabins[i],barreletabins[i+1]);
//		hele[k]->SetMarkerStyle(20);
		double norm1 =  hele[k]->GetEntries();
//		hele[k]->Scale(1/norm1);
		hegHLT[k]->SetLineColor(kAzure-2);
		hegHLT[k]->SetLineWidth(4);
		hegHLT[k]->SetLineStyle(5);
//		hegHLT[k]->SetMarkerStyle(20);
		double norm2 =  hegHLT[k]->GetEntries();
//		hegHLT[k]->Scale(1/norm2);
		double elemax  = hele[k]->GetMaximum();
		double egHLTmax  = hegHLT[k]->GetMaximum();
//		hegHLT[k]->DrawNormalized("hist");
//		hele[k]->DrawNormalized("hist same");

        if(elemax > egHLTmax ){
            hele[k]->DrawNormalized("hist");
            hegHLT[k]->DrawNormalized("hist same");
        }
		else{
			hegHLT[k]->DrawNormalized("hist");
			hele[k]->DrawNormalized("hist same");
		}
		l1[k]->AddEntry(hele[k],"reco ele");
		l1[k]->AddEntry(hegHLT[k],"HLT ele");
		l1[k]->SetBorderSize(1);
		l1[k]->SetFillColor(0);

		c1[k]->cd();
		c1[k]->SetGrid();

		l1[k]->Draw();
		c1[k]->Draw();
		c1[k]->Print("./"+figname+name+".pdf");
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
//       gStyle->SetPadBottomMargin(0.3);
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
    for(int j=0;j<1;j++){
        for(int i=0;i<1;i++){
            draw(j,i);
        }
    }
	return 1;

}
