//root -l
//root[0].L calibration.cpp
//root[1]main()
//root[2].q
//input file: data.root
//output file: cali.txt  cali.root
 #include <iostream>
 using namespace std;

 TH1F *h[32];
 TGraph *gr[32];
 TSpectrum *sp[32];
 TF1 *fit; //double gaus fitting
 TF1 *line; // linear fitting for energy calibration
 Double_t par[32][18];  //save fitting parameters which are from three peaks
 Double_t xbin[3]; //peak value
 Double_t lpar[32][2]; //save intercept,slope
 Double_t lpare[32][2];// save errors of intercept and slope
// create 32 histograms for adc[4][*]
 void createHisto(){
   for(int i=0;i<32;i++){
     char hname[16];
     sprintf(hname,"h%d",i);
     h[i]=new TH1F(hname,hname,500,500,1000);
   }
   fit=new TF1("fit","gaus(0)+gaus(3)",0,4000);
   line=new TF1("ln","pol1",0,4000);
 }
// read adc[4][*] to histogram
 void project(TTree * tree){
   for(int i=0;i<32;i++){
     tree->Project(TString::Format("h%d",i),TString::Format("adc[4][%d]",i));
   }
 }
// fit histogram and find xbins 
 void fitpeak(){
   for(int i=0;i<32;i++){
     sp[i]=new TSpectrum(6,1); //consider there are 6 peaks, and set resoluion=1
     Int_t nfound = sp[i]->Search(h[i],2,"",0.05); //0.05:peaks with amplitude less than threshold*higst_peak are discareded
     if(nfound!=3) {
       cout<<"Ch No. "<<i<<" found "<<nfound<<" peaks!"<<endl;
       continue;
     }
    Double_t *xpeaks = sp[i]->GetPositionX();
    Int_t npeaks=0;
    for(int p=0;p<nfound;p++){
      Float_t xp = xpeaks[p];
      Int_t bbin = h[i]->GetXaxis()->FindBin(xp); //定位xp处的bin值
      Float_t yp = h[i]->GetBinContent(bbin);   //定位xp出bin的计数

      fit->SetParameters(yp/5.,xp-5,2,yp,xp,2);
      fit->SetParLimits(1,xp-20,xp+20);
      fit->SetParLimits(4,xp-20,xp+20);

      h[i]->Fit(fit,"q+","",xp-20,xp+20);
      fit->GetParameters(&par[i][6*p]);
      Double_t tmppar[6];
      Int_t fcnt=0;
      while(1){
        memcpy(tmppar,&par[i][6*p],sizeof(Double_t)*6);
        h[i]->Fit(fit,"q+","",tmppar[1]-20,tmppar[4]+TMath::Abs(tmppar[5]*2));//再次fit,以寻求最佳的参数值
        gStyle->SetOptFit(1111);
	fit->GetParameters(&par[i][6*p]);
	if(TMath::Abs(tmppar[1]-par[i][6*p+1])<0.01&&TMath::Abs(tmppar[4]-par[i][6*p+4])<0.01) break;
	fcnt++;
	if(fcnt>20) break;
      }
      npeaks++;
      xbin[p]=par[i][6*p+4];
    }
    
    const Double_t ener[4]={5.156,5.486,5.805};
    
    gr[i]=new TGraph(npeaks,xbin,ener);
    gr[i]->Fit(line);
    gr[i]->Draw("AP");
    gr[i]->SetMarkerStyle(20);
    gr[i]->SetMarkerSize(1.0); 
    gr[i]->SetMarkerColor(kGreen);
    gStyle->SetOptFit(1111);
    line->GetParameters(&lpar[i][0]);
    memcpy(&lpare[i][0],line->GetParErrors(),sizeof(Double_t)*2);

    cout<<"Finish fitting ch : "<<i<<endl;
  }
 }
// save information of energy calibrtion
 void record(){
   ofstream out("cali.txt");
   for(int i=0;i<32;i++){
     out<<lpar[i][0]<<"\t"<<lpar[i][1]<<"\t"<<lpare[i][0]<<"\t"<<lpare[i][1]<<endl;
   }
   out.close();
   TFile *file=new TFile("cali.root","RECREATE");
   for(int i=0;i<32;i++){
     if(h[i]!=0) h[i]->Write();
     if(gr[i]!=0) gr[i]->Write();
   }
   file->Close();
 }
// main function
 int main(){
   TFile *ipf = new TFile("./data.root");
   TTree *ipt = (TTree*)ipf->Get("tree");
   createHisto();
   project(ipt);
   fitpeak();
   record();
 }
