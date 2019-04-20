Double_t binMC[8][7];
Double_t binData[8],scalefactor[8];
TH1D* histoMC(TString name, Int_t j){
TFile* file = new TFile("./histos_"+name+".root");
TH1D* h1 = (TH1D*)file->Get("photonet_mu");
for(Int_t i=0;i<8;i++){
   //if(name.Contains("plj")==0) 
    binMC[i][j]=h1->GetBinContent(i+1)*41.52;
    if(name.Contains("plj")==1) binMC[i][j]=h1->GetBinContent(i+1); 
    cout<<"name "<<name<<" ; bin "<<i<<" ; BinContent "<<binMC[i][j]<<endl;
  }
return h1;
}
TH1D* histoData(TString name){
TFile* file = new TFile("./histos_"+name+".root");
TH1D* h1 = (TH1D*)file->Get("photonet_mu");
for(Int_t i=0;i<8;i++){
   binData[i]=h1->GetBinContent(i+1);
    cout<<"name "<<name<<" ; bin "<<i<<" ; BinContent "<<binData[i]<<endl;
  }
return h1;
}

void scale(){
    Int_t num[7]={0,1,2,3,4,5,6};
    TH1D*h0=histoMC("ST",num[0]);
    TH1D*h1=histoMC("TTA",num[1]);
    TH1D*h2=histoMC("VV",num[2]);
    TH1D*h3=histoMC("WA",num[3]);
    TH1D*h4=histoMC("DMuon_plj_weightb",num[4]);
    TH1D*h5=histoMC("ZA-EWK",num[5]);
    TH1D*h6=histoMC("ZA",num[6]);
    TH1D* hData=histoData("Muon");
    double sum[8]={0};
    for(Int_t i=0;i<8;i++){
        for(Int_t j=0 ; j<6;j++){
            sum[i] = binMC[i][j] + sum[i]; 
        }//sum except ZA
    }
    for(Int_t i=0;i<8;i++){
        scalefactor[i] = (binData[i] - sum[i])/binMC[i][6]; 
        cout<<" scalefactor "<< scalefactor[i]<<endl;
    }
}
