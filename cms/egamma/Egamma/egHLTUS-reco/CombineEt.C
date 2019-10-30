// Double_t etbins[6]={0,30,60,80,200,400};
// Double_t barreletabins[5]={0,0.4,0.8,1.2,1.5};
// Double_t endcapetabins[5]={1.5,1.75,2.0,2.25,2.5};
Double_t etabins[7]={0,0.5,1.0,1.4442,1.566,2.0,2.5};
Double_t etbins[7]={0,20,30,50,100,200,400};

struct VectorPred
{
    bool operator()(const vector<double>& lhs, const vector<double>& rhs)
    {
        return *max_element(lhs.begin(), lhs.end()) < *max_element(rhs.begin(), rhs.end());
    }
};
void draw(int i){
//    TString n1 = "50_120_barrel_";
//    TString n1 = "120_200_barrel_";
//    TString n1 = "50_120_endcap_";
    TString n1 = "120_200_";

    TString etTag = Form("%0.f<et<%0.f",etbins[i],etbins[i+1]);
    TString figname = n1 + Form("et_%0.f_%0.f_",etbins[i],etbins[i+1]);
	TFile* f1 = new TFile("./Splitfiles/"+n1+Form("et_%0.f_%0.f.root",etbins[i],etbins[i+1]));

	TString filename = f1->GetName();
	TH1D*het[2][6];
	TH1D*heta[2][6];
	TH1D*hnrgy[2][6];
	TH1D*hphi[2][6];
	TH1D*hdeta[2][6];
	TH1D*hdphi[2][6];
	TH1D*hsieie[2][6];
	TH1D*hmhits[2][6];
	TH1D*h3[8];
//	TEfficiency* h3[8];
	TLegend *l1[8];
	TLegend *l2[8];
    TCanvas* c1[8];
	vector<vector<TH1D*> > hele(8,vector<TH1D*>(6));
	vector<vector<TH1D*> > heghltUS(8,vector<TH1D*>(6));;
    vector<vector<double>> maxele(8,vector<double>(6));
    vector<vector<double>> maxeghltUS(8,vector<double>(6));
    for(int i=0;i<6;i++){
        het[0][i] = (TH1D*)f1->Get(Form("hclusEt_ele_%i",i));
        het[1][i] = (TH1D*)f1->Get(Form("het_eghltUS_%i",i));  
        heta[0][i] = (TH1D*)f1 ->Get(Form("hdetEta_ele_%i",i));
        heta[1][i] = (TH1D*)f1 ->Get(Form("heta_eghltUS_%i",i));
        hnrgy[0][i] = (TH1D*)f1->Get(Form("hclusNrgy_ele_%i",i));
	    hnrgy[1][i] = (TH1D*)f1->Get(Form("hnrgy_eghltUS_%i",i));
	    hphi[0][i] = (TH1D*)f1 ->Get(Form("hdetPhi_ele_%i",i));
	    hphi[1][i] = (TH1D*)f1 ->Get(Form("hphi_eghltUS_%i",i));
	    hdeta[0][i] = (TH1D*)f1->Get(Form("hdEtaInSeed_ele_%i",i));
	    hdeta[1][i] = (TH1D*)f1->Get(Form("hetain_eghltUS_%i",i));
	    hdphi[0][i] = (TH1D*)f1->Get(Form("hPhiIn_ele_%i",i));
	    hdphi[1][i] = (TH1D*)f1->Get(Form("hphiin_eghltUS_%i",i));
	    hsieie[0][i] =(TH1D*)f1->Get(Form("hsieie_ele_%i",i));
	    hsieie[1][i] =(TH1D*)f1->Get(Form("hsieie_eghltUS_%i",i));
	    hmhits[0][i] =(TH1D*)f1->Get(Form("hMHits_ele_%i",i));
	    hmhits[1][i] =(TH1D*)f1->Get(Form("hMHits_eghltUS_%i",i));
            }
        for(int n=0;n<6;n++){
        hele[0][n]=het[0][n];        heghltUS[0][n]=het[1][n];   
        hele[1][n]=heta[0][n];       heghltUS[1][n]=heta[1][n];
        hele[2][n]=hnrgy[0][n];      heghltUS[2][n]=hnrgy[1][n];
        hele[3][n]=hphi[0][n];       heghltUS[3][n]=hphi[1][n];
        hele[4][n]=hdeta[0][n];      heghltUS[4][n]=hdeta[1][n];
        hele[5][n]=hdphi[0][n];      heghltUS[5][n]=hdphi[1][n];
        hele[6][n]=hsieie[0][n];     heghltUS[6][n]=hsieie[1][n];
        hele[7][n]=hmhits[0][n];     heghltUS[7][n]=hmhits[1][n];
        }
	char hname[51];
    TString name;
    for(int k=0;k<8;k++){
        sprintf(hname,"h_%d",k);
        cout<<k<<endl;
        name = hele[k][1]->GetName();
        cout<<name<<endl;
		c1[k] = new TCanvas(hname,name,900,600);
        if(name.Contains("Nrgy")){
            l1[k] = new TLegend(0.1,0.7,0.4,0.9);
            l2[k] = new TLegend(0.1,0.5,0.4,0.7);
        }
        else{
            l1[k] = new TLegend(0.6,0.7,0.9,0.9);
            l2[k] = new TLegend(0.6,0.5,0.9,0.7);
        }
        c1[k]->cd();
        for(int i=0;i<6;i++){
            TString split = Form("%0.2f<eta<%0.2f",etabins[i],etabins[i+1]);
             heghltUS[k][i]->SetTitle(name+"\t"+etTag);
             heghltUS[k][i]->SetLineColor(i);
             heghltUS[k][i]->SetLineStyle(2);
             heghltUS[k][i]->SetLineWidth(1);
	         hele[k][i]->SetLineColor(i);
	    	 hele[k][i]->SetLineWidth(1);
             hele[k][i]->SetLineStyle(1);

//             heghltUS[k][i]->GetYaxis()->SetRangeUser(0,1);
//             hele[k][i]->GetYaxis()->SetRangeUser(0,1);
             hele[k][i]->DrawNormalized("hist same");
             heghltUS[k][i]->DrawNormalized("hist same");
             l1[k]->AddEntry(hele[k][i],"reco "+split);
             l1[k]->SetBorderSize(1);
             l1[k]->SetFillColor(0);
             l2[k]->AddEntry(heghltUS[k][i],"HLT "+split);
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
        heghltUS.clear();
        maxele.clear();
        maxeghltUS.clear();
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
int CombineEt(){
	Style();
    for(int i=0;i<6;i++){
            draw(i);
    }
	return 1;

}
