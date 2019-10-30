 Double_t etbins[6]={0,30,60,80,200,400};
 Double_t barreletabins[5]={0,0.4,0.8,1.2,1.5};
 Double_t endcapetabins[5]={1.5,1.75,2.0,2.25,2.5};
/*struct VectorPred
{
    bool operator()(const vector<double>& lhs, const vector<double>& rhs)
    {
        return *max_element(lhs.begin(), lhs.end()) < *max_element(rhs.begin(), rhs.end());
    }
};
*/

void draw(int i){
//    TString n1 = "50_120_barrel_";
//    TString n1 = "120_200_barrel_";
    TString n1 = "50_120_endcap_";
//    TString n1 = "120_200_endcap_";

    TString etTag = Form("%0.f<et<%0.f",etbins[i],etbins[i+1]);
    TString figname = n1 + Form("et_%0.f_%0.f_",etbins[i],etbins[i+1]);
	TFile* f1 = new TFile(n1+Form("et_%0.f_%0.f.root",etbins[i],etbins[i+1]));

//	TFile* f1 = new TFile("120_200_endcap.root");
//	TFile* f1 = new TFile("50_120_barrel.root");
//	TFile* f1 = new TFile("50_120_endcap.root");
	TString filename = f1->GetName();
	TH1D*het[2][4];
	TH1D*heta[2][4];
	TH1D*hnrgy[2][4];
	TH1D*hphi[2][4];
	TH1D*hdeta[2][4];
	TH1D*hdphi[2][4];
	TH1D*hsieie[2][4];
	TH1D*hmhits[2][4];
	TH1D*h3[8];
//	TEfficiency* h3[8];
	TLegend *l1[8];
	TLegend *l2[8];
    TCanvas* c1[8];
	vector<vector<TH1D*> > hele(8,vector<TH1D*>(4));
	vector<vector<TH1D*> > hegHLT(8,vector<TH1D*>(4));;
//    vector<vector<double>> maxele(8,vector<double>(4));
//    vector<vector<double>> maxegHLT(8,vector<double>(4));
    for(int i=0;i<4;i++){
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
        for(int n=0;n<4;n++){
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
//    int p1k,p2k,p1i,p2i;
    TString name;
//    hele[0][0]->GetYaxis()->SetRangeUser(0,1);
    for(int k=0;k<1;k++){
 //       if(k==1) continue;
        sprintf(hname,"h_%d",k);
        cout<<k<<endl;
        name = hele[k][1]->GetName();
        cout<<name<<endl;

		c1[k] = new TCanvas(hname,name,900,600);
        if(name.Contains("Nrgy")||name.Contains("hdetEta")){
            l1[k] = new TLegend(0.15,0.65,0.35,0.85);
            l2[k] = new TLegend(0.15,0.45,0.35,0.65);
        }
        else{
            l1[k] = new TLegend(0.65,0.65,0.88,0.85);
            l2[k] = new TLegend(0.65,0.45,0.88,0.65);
        }
 
        c1[k]->cd();
		//c1[k]->SetGrid();
        c1[k]->SetTicks(0,1);

        //double maxE = hele[k][0]->GetMaximum();double maxH=hegHLT[k][0]->GetMaximum();
 		double ymax;
        vector<double> vec_ymax;

//        xmin=hegHLT[k][0]->GetBinLowEdge(1);
//       xmax=hegHLT[k][0]->GetBinLowEdge(hegHLT[k][0]->GetNbinsX()+1);
//        ymin=0;

        for(int i=0;i<4;i++){
             
             hegHLT[k][i]->SetTitle(name+"\t"+etTag);
             hegHLT[k][i]->SetLineColor(1+i);
             hegHLT[k][i]->SetLineStyle(2);
             hegHLT[k][i]->SetLineWidth(1);
             hegHLT[k][i]->GetXaxis()->SetTitle(name+"\t"+etTag);
             hegHLT[k][i]->GetYaxis()->SetTitle("Normalized");
             hegHLT[k][i]->Scale(1./hegHLT[k][i]->Integral());

             hele[k][i]->SetTitle(name+"\t"+etTag);            
	         hele[k][i]->SetLineColor(1+i);
			 hele[k][i]->SetLineStyle(1);
	    	 hele[k][i]->SetLineWidth(1);
             hele[k][i]->GetXaxis()->SetTitle(name+"\t"+etTag);
             hele[k][i]->GetYaxis()->SetTitle("Normalized");            
             hele[k][i]->Scale(1./hele[k][i]->Integral());
 
             vec_ymax.push_back(hegHLT[k][i]->GetMaximum());
             vec_ymax.push_back(hele[k][i]->GetMaximum());

             /*maxele[k][i]=hele[k][i]->GetMaximum();
             maxegHLT[k][i]=hegHLT[k][i]->GetMaximum();
             if(maxele[k][i]- maxE > 0)   {maxE = maxele[k][i];p1k=k;p1i=i;}
             if(maxegHLT[k][i]- maxH > 0) {maxH = maxegHLT[k][i];p2k=k;p2i=i;}
             
             if(k==0 && i==0) {
                 hegHLT[k][i]->DrawNormalized("hist");
             }
             else {hegHLT[k][i]->DrawNormalized("hist same");
                   hele[k][i]->DrawNormalized("hist same");}
             hegHLT[k][i]->GetYaxis()->SetRangeUser(0,1);
             hele[k][i]->GetYaxis()->SetRangeUser(0,1);
             */
             TString split = Form("%0.2f<eta<%0.2f",endcapetabins[i],endcapetabins[i+1]);
             l1[k]->AddEntry(hele[k][i],"reco "+split);
             l2[k]->AddEntry(hegHLT[k][i],"HLT "+split);
	

        }

 		sort(vec_ymax.begin(), vec_ymax.end(), greater<double>());       
 		ymax=vec_ymax[0];

 		TRatioPlot *rp=new TRatioPlot(hegHLT[k][0],hele[k][0]);
  		rp->SetH1DrawOpt("hist");
 		rp->SetH2DrawOpt("hist");

 		rp->Draw();
 		rp->GetUpperRefYaxis()->SetRangeUser(0,ymax*1.4);
 		rp->GetLowerRefYaxis()->SetTitle("reco/HLT");

		if (name.Contains("hdetPhi")) rp->GetLowerRefXaxis()->SetRangeUser(-5,8);

 		rp->GetUpperPad()->cd();

 		TH1D* hratio[3];

 		for (int i=1; i<4; i++) {

 			hegHLT[k][i]->Draw("hist same");
 			hele[k][i]->Draw("hist same");
 
 			hratio[i-1]=(TH1D*)hele[k][i]->Clone(Form("ratio_plot_%i",i));
            cout<<hratio[i-1]->GetNbinsX()<<endl;
            cout<<hegHLT[k][i]->GetNbinsX()<<endl;
 			hratio[i-1]->Divide(hegHLT[k][i]);
 			hratio[i-1]->SetLineColor(1+i);
 			hratio[i-1]->SetLineWidth(1);
 			hratio[i-1]->SetLineStyle(1);	

 		}


		l1[k]->SetBorderSize(1);
        l1[k]->SetFillColor(0);
        l2[k]->SetBorderSize(1);
        l2[k]->SetFillColor(0);
        
        l1[k]->Draw();
        l2[k]->Draw();

        rp->GetLowerPad()->cd();

        for (int i=0;i<3;i++) hratio[i]->Draw("P,same");

        c1[k]->Update();
        c1[k]->Print("./"+figname+name+".pdf");
	}
    //cout<<p1k<<" "<<p1i<<endl;
    //cout<<p2k<<" "<<p2i<<endl;
    /*
//    if(hele[p1k][p1i]->GetMaximum()>hegHLT[p2k][p2i]->GetMaximum()){
//        hele[p1k][p1i]->Draw("hist");}
//    else hegHLT[p2k][p2i]->Draw("hist");
    hegHLT[p2k][p2i]->Draw("hist");

    for(int k=0;k<8;k++){
        for(int i=0;i<4;i++){
            if(k!=p2k && i!=p2i) hegHLT[k][i]->DrawNormalized("hist same");
            hele[k][i]->DrawNormalized("hist same");
        }
        name = hele[k][1]->GetName();
        l1[k]->Draw();
        l2[k]->Draw();
		c1[k]->Draw();
		c1[k]->Print("./"+figname+name+".pdf");
    }*/
        hele.clear();
        hegHLT.clear();
    //    maxele.clear();
    //    maxegHLT.clear();
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
    for(int i=3;i<4;i++){
            draw(i);
    }
	return 1;

}
