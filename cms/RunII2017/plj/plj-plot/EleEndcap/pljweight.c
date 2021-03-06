Double_t fakerate[10];
Double_t lowpt[10]= {20,25,30,35,40,45,50,60,80,120};
Double_t highpt[10]={25,30,35,40,45,50,60,80,120,400};
Double_t bin_data[10],bin_plj[10];
Double_t weight[10];
TFile* f1 = new TFile("./plj-hist/cutla-outDEle_pljnew_he.root");
TFile* f2 = new TFile("./plj-hist/cutla-outDEle_he.root");
//TFile* f1 = new TFile("./plj-hist/cutla-outDEle_plj_he.root");
//TFile* f2 = new TFile("./plj-hist/cutla-outDEle_he.root");
 
TH1F* h1 = (TH1F*)f1->Get("h_cutla-outDEle_pljnew");
TH1F* h2 = (TH1F*)f2->Get("h_cutla-outDEle");
void draw(){

/* TCanvas* c1 = new TCanvas("c1","plj vs data",900,700);
// for(Int_t j=1;j<=9;j++){ h1->GetXaxis()->SetBinLabel(j,name[j-1]);}
 h1->SetLineColor(kRed);
 h1->SetLineWidth(3);
 h1->SetLineStyle(5);

 h2->SetLineWidth(3);
 h2->SetLineColor(kGreen);
 h2->SetLineStyle(5);
 TLegend *leg = new TLegend(0.7, 0.8, 0.88, 0.88, NULL, "brNDC");
 leg->SetFillColor(10);
 leg->AddEntry(h1, "plj", "L");
 leg->AddEntry(h2, "data", "L");
 h1->Draw();
 h2->Draw("Same");
 leg->Draw();
 c1->Print("./plj_vs_data.eps");
 delete c1;*/
 for(Int_t i=0;i<10;i++){
    bin_data[i]=h2->GetBinContent(i+1);
    bin_plj[i] =h1->GetBinContent(i+1);
  }
}
void open(Int_t i){
    
    ifstream f1;
    f1.open(Form("./eleEndcap-ff/fakerate_pt%0.f_%0.f.txt",lowpt[i],highpt[i]));
//    f1.open(Form("./eleBarrel-ff/fakerate_pt%0.f_%0.f.txt",lowpt[i],highpt[i]));
    if(!f1.is_open()) cout<<"can not open the file: "<<Form("fakerate_pt%0.f_%0.f.txt",lowpt[i],highpt[i])<<endl;
   // if(f1.is_open()) cout<<"open the file: "<<Form("fakerate_pt%0.f_%0.f.txt",lowpt[i],highpt[i])<<endl;
    f1>>fakerate[i];cout<<"fakerate = "<<fakerate[i]<<endl;
}
int pljweight(){
gStyle->SetOptStat(0);
for(Int_t i=0;i<10;i++){
   open(i);
 }
draw();
ofstream file("./ele-endcap-pljweight/pljweight.txt");
//ofstream file("./ele-barrel-pljweight/pljweight.txt");
const char *name[10]={"20~25","25~30","30~35","35~40","40~45","45~50","50~60","60~80","80~120","120~400"};
for(Int_t i=0;i<10;i++){
   weight[i]=bin_data[i]*fakerate[i]/bin_plj[i];
//   weight[i]=bin_data[i]*fakerate[i]/bin_plj[i];
   cout<<"bin "<<name[i]<<" ;"<<"data : "<<bin_data[i]<<"; plj : "<<bin_plj[i]<<"; fakerate : "<<fakerate[i]<<"; weight : "<<weight[i]<<endl;
   file<<name[i]<<"\t"<<weight[i]<<endl;
  }
return 0;
}

