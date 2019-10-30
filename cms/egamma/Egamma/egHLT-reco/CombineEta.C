 Double_t etbins[6]={0,30,60,80,200,400};
 Double_t barreletabins[5]={0,0.4,0.8,1.2,1.5};
 Double_t endcapetabins[5]={1.5,1.75,2.0,2.25,2.5};
void draw(int j){
//    TString n1 = "50_120_barrel_";
//    TString n1 = "120_200_barrel_";
//    TString n1 = "50_120_endcap_";
    TString n1 = "120_200_endcap_";

//    TString etaTag = Form("%.1f<eta<%.1f",barreletabins[j],barreletabins[j+1]);
//    TString figname = n1 + Form("eta_%.1f_%.1f_",barreletabins[j],barreletabins[j+1]);
//	TFile* f1 = new TFile("./Splitfiles/"+n1+Form("eta_%.2f_%.2f.root",barreletabins[j],barreletabins[j+1]));

    TString etaTag = Form("%.2f<eta<%.2f",endcapetabins[j],endcapetabins[j+1]);
    TString figname = n1 + Form("eta_%.2f_%.2f_",endcapetabins[j],endcapetabins[j+1]);
	TFile* f1 = new TFile("./Splitfiles/"+n1+Form("eta_%.2f_%.2f.root",endcapetabins[j],endcapetabins[j+1]));
//	TFile* f1 = new TFile("120_200_endcap.root");
//	TFile* f1 = new TFile("50_120_barrel.root");
//	TFile* f1 = new TFile("50_120_endcap.root");
	TString filename = f1->GetName();
	TH1D*het[2][5];
	TH1D*heta[2][5];
	TH1D*hnrgy[2][5];
	TH1D*hphi[2][5];
	TH1D*hdeta[2][5];
	TH1D*hdphi[2][5];
	TH1D*hsieie[2][5];
	TH1D*hmhits[2][5];
	TH1D*h3[8];
//	TEfficiency* h3[8];
	TLegend *l1[8];
	TLegend *l2[8];
    TCanvas* c1[8];
	vector<vector<TH1D*> > hele(8,vector<TH1D*>(5));
	vector<vector<TH1D*> > hegHLT(8,vector<TH1D*>(5));;
    for(int i=0;i<5;i++){
        het[0][i] = (TH1D*)f1->Get(Form("hclusEt_ele_%i",i));
        het[1][i] = (TH1D*)f1->Get(Form("het_eghlt_%i",i));  
        heta[0][i] = (TH1D*)f1 ->Get(Form("hdetEta_ele_%i",i));
        heta[1][i] = (TH1D*)f1 ->Get(Form("heta_eghlt_%i",i));
        hnrgy[0][i] = (TH1D*)f1->Get(Form("hclusNrgy_ele_%i",i));
	    hnrgy[1][i] = (TH1D*)f1->Get(Form("hnrgy_eghlt_%i",i));
	    hphi[0][i] = (TH1D*)f1 ->Get(Form("hdetPhi_ele_%i",i));
	    hphi[1][i] = (TH1D*)f1 ->Get(Form("hphi_eghlt_%i",i));
	    hdeta[0][i] = (TH1D*)f1->Get(Form("hdEtaInSeed_ele_%i",i));
	    hdeta[1][i] = (TH1D*)f1->Get(Form("hetain_eghlt_%i",i));
	    hdphi[0][i] = (TH1D*)f1->Get(Form("hPhiIn_ele_%i",i));
	    hdphi[1][i] = (TH1D*)f1->Get(Form("hphiin_eghlt_%i",i));
	    hsieie[0][i] =(TH1D*)f1->Get(Form("hsieie_ele_%i",i));
	    hsieie[1][i] =(TH1D*)f1->Get(Form("hsieie_eghlt_%i",i));
	    hmhits[0][i] =(TH1D*)f1->Get(Form("hMHits_ele_%i",i));
	    hmhits[1][i] =(TH1D*)f1->Get(Form("hMHits_eghlt_%i",i));
            }
        for(int n=0;n<5;n++){
        hele[0][n]=het[0][n];        hegHLT[0][n]=het[1][n];   
        hele[1][n]=heta[0][n];       hegHLT[1][n]=heta[1][n];
        hele[2][n]=hnrgy[0][n];      hegHLT[2][n]=hnrgy[1][n];
        hele[3][n]=hphi[0][n];       hegHLT[3][n]=hphi[1][n];
        hele[4][n]=hdeta[0][n];      hegHLT[4][n]=hdeta[1][n];
        hele[5][n]=hdphi[0][n];      hegHLT[5][n]=hdphi[1][n];
        hele[6][n]=hsieie[0][n];     hegHLT[6][n]=hsieie[1][n];
        hele[7][n]=hmhits[0][n];     hegHLT[7][n]=hmhits[1][n];
        }
	char hname[51];
/*    hele[1][0]->SetLineColor(2);
    hele[1][0]->DrawNormalized();
    hele[1][1]->SetLineColor(1);
    hele[1][1]->DrawNormalized("same");*/
//    cout<<hele[1][1]->GetName()<<endl;
//    cout<<hele[2][1]->GetName()<<endl;
    for(int k=0;k<8;k++){
 //       if(k==0) continue;
        sprintf(hname,"h_%d",k);
        cout<<k<<endl;
        TString name = hele[k][1]->GetName();
        cout<<name<<endl;
		c1[k] = new TCanvas(hname,name,900,600);
        l1[k] = new TLegend(0.45,0.7,0.75,0.9);
        l2[k] = new TLegend(0.45,0.5,0.75,0.7);
        c1[k]->cd();
        for(int i=0;i<4;i++){
            TString split = Form("%0.f<et<%0.f",etbins[i],etbins[i+1]);
             hegHLT[k][i]->SetTitle(name+"\t"+etaTag);
             hegHLT[k][i]->SetLineColor(1+i);
             hegHLT[k][i]->SetLineStyle(2);
             hegHLT[k][i]->SetLineWidth(1);
	         hele[k][i]->SetLineColor(1+i);
	    	 hele[k][i]->SetLineWidth(1);
             hele[k][i]->SetLineStyle(1);
             hegHLT[k][i]->DrawNormalized("hist same");
             hele[k][i]->DrawNormalized("hist same");
             l1[k]->AddEntry(hele[k][i],"reco "+split);
             l1[k]->SetBorderSize(1);
             l1[k]->SetFillColor(0);
             l2[k]->AddEntry(hegHLT[k][i],"HLT "+split);
             l2[k]->SetBorderSize(1);
             l2[k]->SetFillColor(0);
        }

		c1[k]->SetGrid();

        l1[k]->Draw();
        l2[k]->Draw();
		c1[k]->Draw();
		c1[k]->Print("./"+figname+name+".pdf");
	}
        hele.clear();
        hegHLT.clear();
}
void Style(){
       gStyle->SetPadBorderMode(0);
       gStyle->SetOptStat(0);
       gStyle->SetPadGridX(1);
       gStyle->SetPadGridY(1);
       gStyle->SetPadTickX(1);
       gStyle->SetPadTickY(1);
       gStyle->SetPadTopMargin(0.07);
       gStyle->SetPadBottomMargin(0.07);
       gStyle->SetPadRightMargin(0.05);
       gStyle->SetPadLeftMargin(0.14);
       gStyle->SetPadTickX(1);
       gStyle->SetPadTickY(1);
       gStyle->SetAxisColor(1, "XYZ");
       gStyle->SetStripDecimals(kTRUE);
       gStyle->SetTickLength(0.03, "XYZ");
       gStyle->SetNdivisions(510, "XYZ");
}
int CombineEta(){
	Style();
    for(int j=3;j<4;j++){
            draw(j);
    }
	return 1;

}
