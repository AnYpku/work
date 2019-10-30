// Double_t etbins[6]={0,30,60,80,200,400};
// Double_t barreletabins[5]={0,0.4,0.8,1.2,1.5};
// Double_t endcapetabins[5]={1.5,1.75,2.0,2.25,2.5};
   Double_t etabins[7]={0,0.5,1.0,1.4442,1.566,2.0,2.5};
   Double_t etbins[7]={0,20,30,50,100,200,400};
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

    bool electron_in_barrel=0;
    bool electron_in_endcap=0;
    bool flag_is_eta=0;
    bool flag_is_et=0;

    cout<<n1<<" "<<flag<<endl;

    if (flag=="eta") flag_is_eta=1;
    else if (flag=="et") flag_is_et=1;
    else cout<<"flag error\n";

    int number_hist;

    Double_t *bins, *histbins;

    if (flag_is_eta){

    	bins=new Double_t[7];
    	copy(etabins,etabins+7,bins);
    	number_hist=6;
    	histbins=new Double_t[number_hist+1];
 		copy(etbins,etbins+7,histbins);

    }

    if (flag_is_et){

    	bins=new Double_t[7];
    	copy(etbins,etbins+7,bins);
    	number_hist=6;
    	histbins=new Double_t[number_hist+1];
        copy(etbins,etbins+7,histbins);

    }



    TString Tag = Form("%0.f<"+flag+"<%0.f",bins[i],bins[i+1]);

    cout<<Tag<<endl;

    TString figname;
    TString ntulpename;

    if (flag_is_et) {
    	ntulpename="Splitfiles/"+n1+Form(flag+"_%0.f_%0.f.root",bins[i],bins[i+1]);
    	figname = n1 + Form(flag+"_%0.f_%0.f",bins[i],bins[i+1]);
    }
    if (flag_is_eta) {
    	ntulpename="Splitfiles/"+n1+Form(flag+"_%0.2f_%0.2f.root",bins[i],bins[i+1]);
    	figname = n1 + Form(flag+"_%0.2f_%0.2f",bins[i],bins[i+1]);
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
	vector<vector<TH1D*> > heghltUS(8,vector<TH1D*>(number_hist));;
//    vector<vector<double>> maxele(8,vector<double>(4));
//    vector<vector<double>> maxeghltUS(8,vector<double>(4));
    for(int i=0;i<number_hist;i++){
        if(i==3) continue;
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
        for(int n=0;n<number_hist;n++){
            if(n==3) continue;
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
        if( heghltUS[k][0]->GetMaximumBin()*2>heghltUS[k][0]->GetNbinsX() ){
            l1[k] = new TLegend(0.12,0.65,0.32,0.85);
            l2[k] = new TLegend(0.12,0.45,0.32,0.65);
        }
        else{
            l1[k] = new TLegend(0.65,0.65,0.88,0.85);
            l2[k] = new TLegend(0.65,0.45,0.88,0.65);
        }
 
        c1[k]->cd();
		//c1[k]->SetGrid();
        //c1[k]->SetTicks(0,1);

        //double maxE = hele[k][0]->GetMaximum();double maxH=heghltUS[k][0]->GetMaximum();
 		double ymax,xmin,xmax;
        vector<double> vec_ymax;
        vector<double> vec_xmax;
        vector<double> vec_xmin;

//        xmin=heghltUS[k][0]->GetBinLowEdge(1);
//       xmax=heghltUS[k][0]->GetBinLowEdge(heghltUS[k][0]->GetNbinsX()+1);
//        ymin=0;

        for(int i=0;i<number_hist;i++){
             if(i==3) continue;
             heghltUS[k][i]->SetTitle(name+"\t"+Tag);
             heghltUS[k][i]->SetLineColor(i+1);
             if(i>=4) heghltUS[k][i]->SetLineColor(i+2);
             heghltUS[k][i]->SetLineStyle(2);
             heghltUS[k][i]->SetLineWidth(2);
             heghltUS[k][i]->GetXaxis()->SetTitle(name+"\t"+Tag);
             heghltUS[k][i]->GetYaxis()->SetTitle(Form("Normalized/%.2f",heghltUS[k][i]->GetBinWidth(1)));
             if(heghltUS[k][i]->Integral()==0)  heghltUS[k][i]->Scale(1);
             else heghltUS[k][i]->Scale(1./heghltUS[k][i]->Integral());

             hele[k][i]->SetTitle(name+"\t"+Tag);            
	         hele[k][i]->SetLineColor(1+i);
             if(i>=4) hele[k][i]->SetLineColor(i+2);
			 hele[k][i]->SetLineStyle(1);
	    	 hele[k][i]->SetLineWidth(2);
             hele[k][i]->GetXaxis()->SetTitle(name+"\t"+Tag);
             hele[k][i]->GetYaxis()->SetTitle(Form("Normalized/%.2f",heghltUS[k][i]->GetBinWidth(1)));            
             if(hele[k][i]->Integral()==0)   hele[k][i]->Scale(1);
             else hele[k][i]->Scale(1./hele[k][i]->Integral());
 
             vec_ymax.push_back(heghltUS[k][i]->GetMaximum());
             vec_ymax.push_back(hele[k][i]->GetMaximum());
             vec_xmin.push_back(lower_edge(heghltUS[k][i]));
             vec_xmin.push_back(lower_edge(hele[k][i]));
             vec_xmax.push_back(higher_edge(heghltUS[k][i]));
             vec_xmax.push_back(higher_edge(hele[k][i]));

             /*maxele[k][i]=hele[k][i]->GetMaximum();
             maxeghltUS[k][i]=heghltUS[k][i]->GetMaximum();
             if(maxele[k][i]- maxE > 0)   {maxE = maxele[k][i];p1k=k;p1i=i;}
             if(maxeghltUS[k][i]- maxH > 0) {maxH = maxeghltUS[k][i];p2k=k;p2i=i;}
             
             if(k==0 && i==0) {
                 heghltUS[k][i]->DrawNormalized("hist");
             }
             else {heghltUS[k][i]->DrawNormalized("hist same");
                   hele[k][i]->DrawNormalized("hist same");}
             heghltUS[k][i]->GetYaxis()->SetRangeUser(0,1);
             hele[k][i]->GetYaxis()->SetRangeUser(0,1);
             */
             TString split = Form("%0.2f<eta<%0.2f",etabins[i],etabins[i+1]);
             l1[k]->AddEntry(hele[k][i],"reco "+split);
             l2[k]->AddEntry(heghltUS[k][i],"HLT "+split);
	

        }

 		sort(vec_ymax.begin(), vec_ymax.end(), greater<double>());      
 		sort(vec_xmax.begin(), vec_xmax.end(), greater<double>());      
 		sort(vec_xmin.begin(), vec_xmin.end());      

 		ymax=vec_ymax[0];
 		xmax=vec_xmax[0];
 		xmin=vec_xmin[0];

 		cout<<ymax<<" "<<xmax+8*hele[k][0]->GetBinWidth(1)<<" "<<xmin<<endl;

 		//hele[k][0]->GetXaxis()->SetRangeUser(0,xmax+8*hele[k][0]->GetBinWidth(1));
 		//heghltUS[k][0]->GetXaxis()->SetRangeUser(0,xmax+8*hele[k][0]->GetBinWidth(1));
 
 		TH1D* hratio[number_hist-1];

 		for (int i=0; i<number_hist; i++) {
            if(i==3) continue;
 			hratio[i]=(TH1D*)heghltUS[k][i]->Clone(Form("ratio_plot_%i",i));
 			if(hratio[i]->GetNbinsX()!=heghltUS[k][i]->GetNbinsX()) cout<<"Ratio plot: with different number of bins\n";
 			if(hratio[i]->GetBinWidth(1)!=heghltUS[k][i]->GetBinWidth(1)) cout<<"Ratio plot_path: with different bin width\n";
 			hratio[i]->Divide(hele[k][i]);
 			hratio[i]->SetLineColor(1+i);
            if(i>=4) hratio[i]->SetLineColor(2+i);
 			hratio[i]->SetLineWidth(2);
 			hratio[i]->SetLineStyle(1);	

 		}

		l1[k]->SetBorderSize(1);
        l1[k]->SetFillColor(0);
        l2[k]->SetBorderSize(1);
        l2[k]->SetFillColor(0); 

 		TRatioPlot *rp=new TRatioPlot((TH1D*)heghltUS[k][0]->Clone(),(TH1D*)hele[k][0]->Clone());
  		rp->SetH1DrawOpt("hist");
 		rp->SetH2DrawOpt("hist");

 		rp->Draw();
 		rp->GetUpperRefYaxis()->SetRangeUser(0,ymax*1.4);
 		rp->GetLowerRefYaxis()->SetTitle("reco/HLT");
        //rp->GetLowerRefXaxis()->SetRangeUser(0,(xmax+8*hele[k][0]->GetBinWidth(1)));	
        rp->GetLowerRefYaxis()->SetRangeUser(0.5,1.5);	

		//if (name.Contains("hdetPhi")) rp->GetLowerRefXaxis()->SetRangeUser(-5,8);

 		rp->GetUpperPad()->cd();
     
     	for (int i=1; i<number_hist; i++) {
            if(i==3) continue;
 			heghltUS[k][i]->Draw("hist same");
 			hele[k][i]->Draw("hist same");
 		}

        l1[k]->Draw();
        l2[k]->Draw();

        rp->GetLowerPad()->cd();

        for (int i=0;i<number_hist;i++) 
        {
//            hratio[i]->GetYaxis()->SetRangeUser(-5,5);
            if(i==3) continue;
            hratio[i]->Draw("P,same");
        }

        //rp->GetLowerPad()->SetEditable(0);	

        c1[k]->Update();

//    	TString plot_path="Splitfiles/plots/eps/"+figname;
    	TString plot_path="Splitfiles/plots/png/"+figname;

    	//if (!IsPathExist(plot_path)){

			int status=mkdir(plot_path,0777); 
			if (status==0) cout<<"folder create:"<<plot_path<<"/\n";	
			else cout<<"folder already exists\n";
//			c1[k]->Print(plot_path+"/"+name+".eps");		
			c1[k]->Print(plot_path+"/"+name+".png");		
		//}

        
	}
    //cout<<p1k<<" "<<p1i<<endl;
    //cout<<p2k<<" "<<p2i<<endl;
    /*
//    if(hele[p1k][p1i]->GetMaximum()>heghltUS[p2k][p2i]->GetMaximum()){
//        hele[p1k][p1i]->Draw("hist");}
//    else heghltUS[p2k][p2i]->Draw("hist");
    heghltUS[p2k][p2i]->Draw("hist");

    for(int k=0;k<8;k++){
        for(int i=0;i<4;i++){
            if(k!=p2k && i!=p2i) heghltUS[k][i]->DrawNormalized("hist same");
            hele[k][i]->DrawNormalized("hist same");
        }
        name = hele[k][1]->GetName();
        l1[k]->Draw();
        l2[k]->Draw();
		c1[k]->Draw();
		c1[k]->Print("./"+figname+name+".pdf");
    }*/
        hele.clear();
        heghltUS.clear();
    //    maxele.clear();
    //    maxeghltUS.clear();
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
int draw_et(){
	Style();

	vector<TString> vec_region_of_mZ_eta; 
    vec_region_of_mZ_eta.push_back("50_120_");
    vec_region_of_mZ_eta.push_back("120_200_");

    vector<TString> vec_flag={"eta","et"};

    for (int j=0;j<2;j++){

    	for (int k=1;k<vec_flag.size();k++){
    	
    		int imax=6;
    		/*if(vec_flag[k]=="et") imax=6;
    		for(int i=0;i<imax;i++) {draw(i,vec_region_of_mZ_eta[j],vec_flag[k]);};*/
            draw(0,vec_region_of_mZ_eta[j],vec_flag[k]); 
            draw(1,vec_region_of_mZ_eta[j],vec_flag[k]); 
            draw(2,vec_region_of_mZ_eta[j],vec_flag[k]); 
            draw(3,vec_region_of_mZ_eta[j],vec_flag[k]); 
            draw(4,vec_region_of_mZ_eta[j],vec_flag[k]); 
            draw(5,vec_region_of_mZ_eta[j],vec_flag[k]); 
 		}   	
	}


	return 1;

}
