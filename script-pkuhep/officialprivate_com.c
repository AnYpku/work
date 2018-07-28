
Int_t bin=100;
Double_t low = 0;
Double_t high= 100 ;
Double_t scalef;
Double_t lumiWeight;
Double_t pileupWeight;

Double_t photonet;
Double_t photoneta;
Double_t jet1eta,jet2eta;
Double_t jet1pt,jet2pt;
Double_t ptlep1,etalep1;
Double_t ptlep2,etalep2;
Double_t npT,ptVlep,Mjj;
Int_t nVtx;
TH1D *h1[14];
TH1D *h2[14];

void draw(TString title,TH1D* h3[14]);
void open(std::string filename, TH1D* h[14]);
TString name[14] = {"photonet","photoneta","etalep1","etalep2","ptlep1","ptlep2","jet1pt","jet2pt","jet1eta","jet2eta","ptVlep","npT","nVtx","Mjj"};

void open(std::string filename, TH1D* h[14]){
  string file = filename + ".root";
  TFile *f1=new TFile(file.c_str());
  TTree* t=(TTree *)f1->Get("demo");
  Long64_t en=t->GetEntries();
  t->SetBranchAddress("scalef",&scalef);
  t->SetBranchAddress("lumiWeight",&lumiWeight);
  t->SetBranchAddress("pileupWeight",&pileupWeight);
      t->SetBranchAddress(name[0],&photonet);
      t->SetBranchAddress(name[1],&photoneta);
      t->SetBranchAddress(name[2],&etalep1);
      t->SetBranchAddress(name[3],&etalep2);
      t->SetBranchAddress(name[4],&ptlep1);
      t->SetBranchAddress(name[5],&ptlep2);
      t->SetBranchAddress(name[6],&jet1pt);
      t->SetBranchAddress(name[7],&jet2pt);
      t->SetBranchAddress(name[8],&jet1eta);
      t->SetBranchAddress(name[9],&jet2eta);
      t->SetBranchAddress(name[10],&ptVlep);
      t->SetBranchAddress(name[11],&npT);
      t->SetBranchAddress(name[12],&nVtx);
      t->SetBranchAddress(name[13],&Mjj);

  Double_t a[14];
  Double_t actualWeight;
  for (Long64_t i = 0; i < en; i++) {
    /* code */
    t->GetEntry(i);
    actualWeight=scalef*lumiWeight*pileupWeight;
    a[0]=photonet;a[1]=photoneta;a[2]=etalep1;a[3]=etalep2;a[4]=ptlep1;a[5]=ptlep2;a[6]=jet1pt;
    a[7]=jet2pt ; a[8]=jet1eta  ;a[9]=jet2eta;a[10]=ptVlep;a[11]=npT;  a[12]=nVtx; a[13]=Mjj;
    for(Int_t i=0;i<12;i++){
       h[i]->Fill(a[i],actualWeight);}
  }
}
void draw(TString title,TH1D* h3[14]){
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


      TCanvas *c1= new TCanvas(title,title,750,500);


      TPad *top_pad=new TPad("top_pad", "top_pad",0,0.2, 1.0, 1.0);
      top_pad->Draw();
      top_pad->cd();
      top_pad->SetBottomMargin(0.1);
      //top_pad->SetLogy();

   for(Int_t i=0;i<14;i++){
      h1[i]->SetLineColor(kRed);
      h1[i]->SetLineWidth(3);
      h1[i]->SetMarkerStyle(20);
      h1[i]->Draw("HIST");

      h2[i]->SetLineColor(kBlue);
      h2[i]->SetLineWidth(4);
      h2[i]->SetLineStyle(5);
      h2[i]->SetMarkerStyle(20);
      h2[i]->Draw("HIST same");
   }

      TLegend *l1 = new TLegend(0.65,0.65,0.78,0.82);
      l1->SetBorderSize(1);
      l1->SetFillColor(0);

      c1->cd();
      TPad *bottom_pad=new TPad("bottom_pad", "bottom_pad", 0, 0., 1.0, 0.2);
      bottom_pad->Draw();
      bottom_pad->cd();
      bottom_pad->SetTopMargin(0);

   for(Int_t i=0;i<14;i++){
      h3[i]->Draw("HIST");
      h3[i]->SetTitle("");
      h3[i]->GetXaxis()->SetTitle( title +" [GeV] ");
      h3[i]->GetYaxis()->SetTitle("K factor ");
      h3[i]->GetXaxis()->CenterTitle();
      h3[i]->GetYaxis()->CenterTitle();
      h3[i]->SetLineColor(kBlack);
      h3[i]->GetXaxis()->SetTitleOffset(0.9);
      h3[i]->GetYaxis()->SetTitleOffset(0.22);
      h3[i]->GetXaxis()->SetTitleSize(0.15);
      h3[i]->GetYaxis()->SetTitleSize(0.15);
      h3[i]->GetXaxis()->SetLabelSize(0.12);
      h3[i]->GetYaxis()->SetLabelSize(0.1);
      h3[i]->SetMaximum(1.35);
      h3[i]->SetMinimum(0.7);
      l1->AddEntry(h1[i],"Offical");
      l1->AddEntry(h2[i],"private");
      l1->AddEntry(h3[i],"private/Offical");
   }
      l1->Draw();
      c1->Draw();
      c1->Print(title +".eps");
      c1->Print(title +".pdf");
}

int main(){
for(int i=0;i<14;i++){
     h1[i]=new TH1D(Form("h1_%d",i),name[i],bin,low,high);
     h2[i]=new TH1D(Form("h2_%d",i),name[i],bin,low,high);
   }
      open("outofficial",h1);
      open("outprivate",h2);
      
      TH1D *h3[14];
      for(Int_t i=0;i<14;i++){
      h3[i]= (TH1D *)h2[i]->Clone();
      h3[i]->Divide(h1[i]);
      }
     
      for(Int_t i=0;i<14;i++){
         draw(name[i],h3);
      }

      return 0;
}




