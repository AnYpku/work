// Double_t etbins[6]={0,30,60,80,200,400};
// Double_t barreletabins[5]={0,0.4,0.8,1.2,1.5};
// Double_t endcapetabins[5]={1.5,1.75,2.0,2.25,2.5};
   Double_t etabins[7]={0,0.5,1.0,1.4442,1.566,2.0,2.5};
   Double_t etbins[6]={0,20,40,60,100,200};
/*struct VectorPred
{
    bool operator()(const vector<double>& lhs, const vector<double>& rhs)
    {
        return *max_element(lhs.begin(), lhs.end()) < *max_element(rhs.begin(), rhs.end());
    }
};
*/

//#include <sys/stat.h>
/*bool IsPathExist(TString &pathname)
{
	struct stat info;

	if( stat( pathname, &info ) != 0 ){
    	cout<<( "cannot access "+pathname+"\n" );
		return 0;
	}
	else if( info.st_mode & S_IFDIR ){  // S_ISDIR() doesn't exist on my windows 
    	cout<<( pathname+" exists\n", pathname );
    	return 1;
    }
	else{
    	cout<<( "no directory named "+pathname+"\n");
		return 0;
	}
  
}
*/
#include <iterator>
#include <sys/stat.h>


Double_t lower_edge(TH1D *h){

	int nbins=h->GetNbinsX();
	Double_t loweredge;
	//Double_t max_value=h->GetMaximum();
	for ( int i=0; i<nbins+2; i++){

		if (h->GetBinContent(i)>0) {loweredge=h->GetBinLowEdge(i);break;}

	}

	return loweredge;

}

Double_t higher_edge(TH1D *h){

	int nbins=h->GetNbinsX();
	Double_t higheredge;
	//Double_t max_value=h->GetMaximum();
	for ( int i=0; i<nbins+2; i++){
		
		if (h->GetBinContent(nbins+1-i)>0) {higheredge=h->GetBinLowEdge(i+1);break;}

	}

	return higheredge;

}




void draw(int i,TString n1,TString flag){
//    TString n1 = "50_120_barrel_";
//    TString n1 = "120_200_barrel_";
//    TString n1 = "50_120_endcap_";
//    TString n1 = "120_200_endcap_";

    bool electron_in_barrel=0;
    bool electron_in_endcap=0;
    bool flag_is_eta=0;
    bool flag_is_et=0;

    cout<<n1<<" "<<flag<<endl;

//    if (n1.Contains("barrel")) electron_in_barrel=1;
//    else if (n1.Contains("endcap")) electron_in_endcap=1;
//    else cout<<"ntuples error\n";

    if (flag=="eta") flag_is_eta=1;
    else if (flag=="et") flag_is_et=1;
    else cout<<"flag error\n";

    int number_hist;

    Double_t *bins, *histbins;

    if (flag_is_eta){

    	bins=new Double_t[7];
    	copy(etabins,etabins+7,bins);
    	number_hist=5;
    	histbins=new Double_t[number_hist+1];
 		copy(etbins,etbins+6,histbins);

    }

    if (flag_is_et){

    	bins=new Double_t[6];
    	copy(etbins,etbins+6,bins);
    	number_hist=5;
    	histbins=new Double_t[number_hist+1];
    	copy(etabins,etabins+5,histbins);

    }
    TString Tag = Form("%0.2f<"+flag+"<%0.2f",etabins[i],etabins[i+1]);
    cout<<Tag<<endl;
    TString figname;
    TString ntulpename;

    if (flag_is_et) {
    	ntulpename="Splitfiles/"+n1+Form(flag+"_%0.f_%0.f.root",bins[i],bins[i+1]);
    	figname = n1 + Form(flag+"_%0.f_%0.f",bins[i],bins[i+1]);
    }
    if (flag_is_eta) {
    	ntulpename="Splitfiles/"+n1+Form(flag+"_%0.2f_%0.2f.root",etabins[i],etabins[i+1]);
    	figname = n1 + Form(flag+"_%0.2f_%0.2f",etabins[i],etabins[i+1]);
    }
    	
	TFile* f1 = new TFile(ntulpename);

//	TFile* f1 = new TFile("120_200_endcap.root");
//	TFile* f1 = new TFile("50_120_barrel.root");
//	TFile* f1 = new TFile("50_120_endcap.root");
	TString filename = f1->GetName();
	TH1D*het[2][number_hist];
	TH1D*heta[2][number_hist];
	TH1D*hnrgy[2][number_hist];
	TH1D*hphi[2][number_hist];
	TH1D*hdeta[2][number_hist];
	TH1D*hdphi[2][number_hist];
	TH1D*hsieie[2][number_hist];
	TH1D*hmhits[2][number_hist];
//	TH1D*h3[8];
//	TEfficiency* h3[8];
	TLegend *l1[8];
	TLegend *l2[8];
    TCanvas* c1[8];
	vector<vector<TH1D*> > hele(8,vector<TH1D*>(number_hist));
	vector<vector<TH1D*> > hegHLT(8,vector<TH1D*>(number_hist));;
//    vector<vector<double>> maxele(8,vector<double>(4));
//    vector<vector<double>> maxegHLT(8,vector<double>(4));
    for(int i=0;i<number_hist;i++){
        het[0][i] = (TH1D*)f1->Get(Form("hadem_ele_%i",i));
        het[1][i] = (TH1D*)f1->Get(Form("hadem_eghlt_%i",i));  
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
        for(int n=0;n<number_hist;n++){
        hele[0][n]=het[0][n];        hegHLT[0][n]=het[1][n];   
        hele[1][n]=heta[0][n];       hegHLT[1][n]=heta[1][n];
        hele[2][n]=hnrgy[0][n];      hegHLT[2][n]=hnrgy[1][n];
        hele[3][n]=hphi[0][n];       hegHLT[3][n]=hphi[1][n];
        hele[4][n]=hdeta[0][n];      hegHLT[4][n]=hdeta[1][n];
        hele[5][n]=hdphi[0][n];      hegHLT[5][n]=hdphi[1][n];
        hele[6][n]=hsieie[0][n];     hegHLT[6][n]=hsieie[1][n];
        hele[7][n]=hmhits[0][n];     hegHLT[7][n]=hmhits[1][n];
        }
    TString Xtitle[8]={"H/E","Eta","Nrgy","Phi","dEta","dPhi","sieie","missing hits"};
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
    for(int k=0;k<8;k++){
 //       if(k==1) continue;
        sprintf(hname,"h_%d",k);
        cout<<k<<endl;
        name = hele[k][1]->GetName();
        cout<<name<<endl;

		c1[k] = new TCanvas(hname,name,900,600);
//        TPad *top_pad=new TPad("top_pad", "top_pad",0,0.2, 1.0, 1.0);
//        top_pad->Draw();
//        top_pad->cd();
//        top_pad->SetBottomMargin(0.1);
//           l1[k]->SetTextSize(0.06);
//           l2[k]->SetTextSize(0.06);
        if( hegHLT[k][0]->GetMaximumBin()*2>hegHLT[k][0]->GetNbinsX() ){
            l1[k] = new TLegend(0.12,0.5,0.47,0.85);
            l2[k] = new TLegend(0.12,0.35,0.47,0.5);
            l1[k]->SetTextSize(0.06);
            l2[k]->SetTextSize(0.06);
        }
        else{
            l1[k] = new TLegend(0.5,0.5,0.9,0.9);
            l2[k] = new TLegend(0.5,0.35,0.9,0.5);
            l1[k]->SetTextSize(0.06);
            l2[k]->SetTextSize(0.06);
        }
 
        c1[k]->cd();
		//c1[k]->SetGrid();
        //c1[k]->SetTicks(0,1);

        //double maxE = hele[k][0]->GetMaximum();double maxH=hegHLT[k][0]->GetMaximum();
 		double ymax,xmin,xmax;
        vector<double> vec_ymax;
        vector<double> vec_xmax;
        vector<double> vec_xmin;

//        xmin=hegHLT[k][0]->GetBinLowEdge(1);
//       xmax=hegHLT[k][0]->GetBinLowEdge(hegHLT[k][0]->GetNbinsX()+1);
//        ymin=0;

        for(int i=0;i<number_hist;i++){
             
             hegHLT[k][i]->SetTitle(Xtitle[k]+"\t"+Tag);
             cout<<name<<"\t"<<Tag<<endl;
             hegHLT[k][i]->SetLineColor(i+1);
             if(i>=4) hegHLT[k][i]->SetLineColor(i+2);
             hegHLT[k][i]->SetLineStyle(2);
             hegHLT[k][i]->SetLineWidth(2);
             hegHLT[k][i]->GetXaxis()->SetTitle(Xtitle[k]);
             hegHLT[k][i]->GetYaxis()->SetTitle(Form("Normalized/%.2f",hegHLT[k][i]->GetBinWidth(1)));
            if(hegHLT[k][i]->Integral()==0)  hegHLT[k][i]->Scale(1);  
            else hegHLT[k][i]->Scale(1./hegHLT[k][i]->Integral());

             hele[k][i]->SetTitle(Xtitle[k]+"\t"+Tag);            
	         hele[k][i]->SetLineColor(1+i);
             if(i>=4) hele[k][i]->SetLineColor(i+2);
			 hele[k][i]->SetLineStyle(1);
	    	 hele[k][i]->SetLineWidth(2);
             hele[k][i]->GetXaxis()->SetTitle(Xtitle[k]);
             hele[k][i]->GetYaxis()->SetTitle(Form("Normalized/%.2f",hegHLT[k][i]->GetBinWidth(1)));            
            if(hele[k][i]->Integral()==0)   hele[k][i]->Scale(1);
            else hele[k][i]->Scale(1./hele[k][i]->Integral());
 
             vec_ymax.push_back(hegHLT[k][i]->GetMaximum());
             vec_ymax.push_back(hele[k][i]->GetMaximum());
             vec_xmin.push_back(lower_edge(hegHLT[k][i]));
             vec_xmin.push_back(lower_edge(hele[k][i]));
             vec_xmax.push_back(higher_edge(hegHLT[k][i]));
             vec_xmax.push_back(higher_edge(hele[k][i]));

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
             TString split = Form("%0.f<et<%0.f",etbins[i],etbins[i+1]);
             l1[k]->AddEntry(hele[k][i],"reco/HLT "+split);
        }
             l2[k]->AddEntry(hegHLT[k][0],"HLT");
             l2[k]->AddEntry(hele[k][0],"Reco");

 		sort(vec_ymax.begin(), vec_ymax.end(), greater<double>());      
 		sort(vec_xmax.begin(), vec_xmax.end(), greater<double>());      
 		sort(vec_xmin.begin(), vec_xmin.end());      

 		ymax=vec_ymax[0];
 		xmax=vec_xmax[0];
 		xmin=vec_xmin[0];

 		cout<<ymax<<" "<<xmax+8*hele[k][0]->GetBinWidth(1)<<" "<<xmin<<endl;

 		//hele[k][0]->GetXaxis()->SetRangeUser(0,xmax+8*hele[k][0]->GetBinWidth(1));
 		//hegHLT[k][0]->GetXaxis()->SetRangeUser(0,xmax+8*hele[k][0]->GetBinWidth(1));
 
 		TH1D* hratio[number_hist];
//        TPad *bottom_pad=new TPad("bottom_pad", "bottom_pad", 0, 0., 1.0, 0.2);
//        bottom_pad->Draw();
//        bottom_pad->cd();
//        bottom_pad->SetTopMargin(0);
 		for (int i=0; i<number_hist; i++) {

 			hratio[i]=(TH1D*)hele[k][i]->Clone(Form("ratio_plot_%i",i));
 			if(hratio[i]->GetNbinsX()!=hegHLT[k][i]->GetNbinsX()) cout<<"Ratio plot: with different number of bins\n";
 			if(hratio[i]->GetBinWidth(1)!=hegHLT[k][i]->GetBinWidth(1)) cout<<"Ratio plot_path: with different bin width\n";
 			hratio[i]->Divide(hegHLT[k][i]);
 			hratio[i]->SetLineColor(1+i);
            if(i>=4) hratio[i]->SetLineColor(2+i);
 			hratio[i]->SetLineWidth(2);
 			hratio[i]->SetLineStyle(1);	

 		}

		l1[k]->SetBorderSize(1);
        l1[k]->SetFillColor(0);
        l2[k]->SetBorderSize(1);
        l2[k]->SetFillColor(0); 

 		TRatioPlot *rp=new TRatioPlot((TH1D*)hegHLT[k][0]->Clone(),(TH1D*)hele[k][0]->Clone());
  		rp->SetH1DrawOpt("hist");
 		rp->SetH2DrawOpt("hist");

 		rp->Draw();
 		rp->GetUpperRefYaxis()->SetRangeUser(0,ymax*1.4);
 		rp->GetLowerRefYaxis()->SetTitle("reco/HLT");
        //rp->GetLowerRefXaxis()->SetRangeUser(0,(xmax+8*hele[k][0]->GetBinWidth(1)));	
        rp->GetLowerRefYaxis()->SetRangeUser(0.5,1.5);	

		//if (name.Contains("hdetPhi")) rp->GetLowerRefXaxis()->SetRangeUser(-5,8);

 		rp->GetUpperPad()->cd();
//        top_pad->cd(); 
     	for (int i=0; i<number_hist; i++) {

 			hegHLT[k][i]->Draw("hist same");
 			hele[k][i]->Draw("hist same");
 		}

        l1[k]->Draw();
        l2[k]->Draw();

        rp->GetLowerPad()->cd();
//        bottom_pad->cd();
        for (int i=0;i<number_hist;i++) 
        {
//            hratio[i-1]->GetYaxis()->SetRangeUser(0,10);
            hratio[i]->Draw("P,same");
        }

        //rp->GetLowerPad()->SetEditable(0);	

        c1[k]->Update();

//    	TString plot_path="Splitfiles/plots/png/"+figname;
    	TString plot_path="Splitfiles/plots/eps/"+figname;

    	//if (!IsPathExist(plot_path)){
           int status=mkdir(plot_path,0777);
           if (status==0) cout<<"folder create:"<<plot_path<<"/\n";
           else cout<<"folder already exists\n";
//           c1[k]->Print(plot_path+"/"+name+".png");
           c1[k]->Print(plot_path+"/"+name+".eps");


		//}

        
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
int draw_eta(){
	Style();

	vector<TString> vec_region_of_mZ_eta; 
    vec_region_of_mZ_eta.push_back("50_120_");
    vec_region_of_mZ_eta.push_back("120_200_");

    vector<TString> vec_flag={"eta","et"};

    for (int j=0;j<2;j++){

    	for (int k=0;k<1;k++){
    	
    		int imax=6;
    		if(vec_flag[k]=="eta") imax=6;
    		for(int i=0;i<imax;i++) {
                if(etabins[i]==1.4442&&etabins[i+1]==1.566) continue;
                draw(i,vec_region_of_mZ_eta[j],vec_flag[k]);
            }
 
 		}   	
	}


	return 1;

}
