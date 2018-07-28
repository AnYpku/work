#include "th1.h"
#include "TFile.h"
#include "TTree.h"
#include <string>

using namespace std;
const char *name[6]={"Za 100~250","Za 250~350","Za 350~400","Za 400~600","Za 600~infi"};
Int_t bins=5;
Double_t lumi=35.866;
Double_t ZA_scale=0.98;
void run(std::string filename, Int_t num,TH1D* th1[num]);
void draw(Int_t num,TH1D* h[num]);
void run(std::string filename, Int_t num,TH1D* th1[num]){
	std::string file = filename+".root";
	TFile* f1 = TFile::Open(file.c_str());

	TTree* t = (TTree*)f1->Get("demo");

	Double_t Mjj;
	Double_t detajj;
    Double_t theWeight,lumiWeight,scalef,pweight[703];
    Double_t ptlep1,ptlep2,etalep1,etalep2,philep1,philep2;
    Double_t photonet,photoneta,photonphi;
	Double_t actualWeight[num];
    Double_t ZGmass;

	t->SetBranchAddress("Mjj", &Mjj);
	t->SetBranchAddress("deltaetajj", &detajj);
	t->SetBranchAddress("pweight", pweight);
	t->SetBranchAddress("scalef", &scalef);
	t->SetBranchAddress("theWeight", &theWeight);
	t->SetBranchAddress("lumiWeight", &lumiWeight);

    t->SetBranchAddress("ptlep1",&ptlep1);
    t->SetBranchAddress("ptlep2",&ptlep2);
    t->SetBranchAddress("etalep1",&etalep1);
    t->SetBranchAddress("etalep2",&etalep2);
    t->SetBranchAddress("philep1",&philep1);
    t->SetBranchAddress("philep2",&philep2);

    t->SetBranchAddress("photonet",&photonet);
    t->SetBranchAddress("photoneta",&photoneta);
    t->SetBranchAddress("photonphi",&photonphi);

    TLorentzVector vmup;// = new TLorentzVector(); 
    TLorentzVector vmum;// = new TLorentzVector();
    TLorentzVector va  ;// = new TLorentzVector();
    TLorentzVector vz  ;// = new TLorentzVector();
    TLorentzVector v   ;// = new TLorentzVector();

	Double_t ZGmass_bins[6]={150, 250, 350, 400,600,800};
    char th1name[num];
    char th1title[num];
    int j;
    for(Int_t i=0;i<num;i++){
       if(i<5) j=i+1;
       if(i==5)j=7;
       if(i==6)j=9;
       sprintf(th1name,"scale_variation_%d",j);
       sprintf(th1title,"th1_%d",i);
	   th1[i] = new TH1D(th1title,th1name,5,ZGmass_bins);
	   th1[i]->Sumw2();}
    Int_t p;
	for(Int_t j=0; j<t->GetEntries();j++)
	{
        p=0;
		t->GetEntry(j);
        va.SetPtEtaPhiM(photonet, photoneta, photonphi, 0);  //enter the corresponding value of each particle
        vmup.SetPtEtaPhiM(ptlep1, etalep1, philep1, 0.1);
        vmum.SetPtEtaPhiM(ptlep2, etalep2, philep2, 0.1);
        vz = vmup+vmum;
        v  = vz+va;
        ZGmass = v.M();   //the invariant mass of Z+gamma
        for(Int_t i=104;i<113;i++){
          if(p==0)  
              { actualWeight[p]=scalef*lumiWeight*pweight[i];
                if(i==109 || i==111) continue;}
          else 
              { actualWeight[p]=2*scalef*lumiWeight*pweight[i];
                if(i==109 || i==111) continue;}

		if(ZGmass>600) th1[p]->Fill(650, actualWeight[p]);
        else           th1[p]->Fill(ZGmass, actualWeight[p]);
        p++;
     	}
         cout<<"p = "<<p<<endl;
         cout<<"ZGmass = "<<ZGmass<<endl;
         cout<<"entry "<<j<<endl;
         cout<<"scalef = "<<scalef<<endl;
         cout<<"lumiWeight = "<<lumiWeight<<endl;
         for(Int_t k=104;k<113;k++){
              if(k==109 || k==111) continue;
             cout<<"pweight ["<<k<<"] = "<<pweight[k]<<endl;
          }
         for(Int_t k=0;k<num;k++){
            cout<<"actualWeight ["<<k<<"] = "<<actualWeight[k]<<endl;
          }
         cout<<"######################################"<<endl;
    }
//  return 0;
}

void draw(Int_t num,TH1D* h[num]){
    TCanvas* cc[7];
    TLegend *ll[7];
    Int_t m=1,p=0;
    for(Int_t i=0;i<9;i++){
        if(i==5 || i==7) continue;
        ll[p] = new TLegend(0.55,0.36,0.8,0.86);
        cc[p] = new TCanvas(Form("cc_%d",p),Form("Z and #gamma mass %d",i+1),900,600);
        h[p]->SetLineWidth(3);
        h[p]->SetLineColor(i+1);
        for(Int_t j=1;j<=5;j++){ h[p]->GetXaxis()->SetBinLabel(j,name[j-1]);}
        h[p]->Scale(lumi*ZA_scale);
        h[p]->Draw("HIST");
//        h[i]->DrawNormalized("HIST");
        if(p==0) ll[p]->AddEntry(h[p],Form("%d central scale variation",i+1),"LP");
        else     ll[p]->AddEntry(h[p],Form("%d scale variation",i+1),"LP");
        ll[p]->SetFillColor(kWhite);
        ll[p]->SetLineColor(kWhite);
        ll[p]->SetTextFont(32);
        ll[p]->SetTextSize(0.045);
        ll[p]->Draw();
        cc[p]->Print(Form("tmp-hist2d_%d.eps",i+1));
        cout<<"*******************************"<<endl;
        p++;
      }
     TCanvas* c1 = new TCanvas("c1","Z and #gamma mass",900,600);
     c1->SetFrameFillColor(41);
     c1->SetGrid();
     TLegend *l2 = new TLegend(0.55,0.36,0.8,0.86);
     h[0]->SetTitle("Z and #gamma mass");
     h[0]->SetLineWidth(3);
     h[0]->GetYaxis()->SetRangeUser(0,16);
     h[0]->GetXaxis()->SetTitle("Z+#gamma mass/GeV/c^{2}");
     h[0]->GetXaxis()->CenterTitle();
     h[0]->GetXaxis()->SetTitleFont(22);
     h[0]->GetXaxis()->SetTitleOffset(0.8);
     h[0]->GetXaxis()->SetTitleSize(0.05);
     h[0]->GetXaxis()->SetLabelSize(0.05);
     h[0]->GetXaxis()->SetLabelFont(32);
     h[0]->SetLineColor(kBlack);
     h[0]->Draw("HIST");
     l2->AddEntry(h[0]," central scale variation","LP");
     for(Int_t i=1;i<9;i++){
 //         h[i]->SetFillColor(kMagenta);
 //         h[i]->SetMarkerColor(kMagenta);
         if(i==5 || i==7) continue;
          h[m]->SetLineColor(i+1);
          h[m]->SetLineWidth(2);
          h[m]->SetLineStyle(2);
//          h[m]->Scale(scale_factor[m]);
          //h[i]->Draw("HIST,SAME");
          h[m]->Draw("HIST,SAME");
          l2->AddEntry(h[m],Form("%d scale variations",i+1),"LP");
         // delete h[i];
         // delete cc[i];
          m++;
       }
       l2->SetFillColor(41);
       l2->SetLineColor(41);
       l2->SetTextFont(32);
       l2->SetTextSize(0.045);
       l2->Draw();
       c1->Print("hist-2d.eps");
       c1->Print("hist-2d.pdf");


}


int aQGC_hist1d(){
	gStyle->SetPadBorderMode(0);
    gStyle->SetOptStat(0);
	gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetAxisColor(1, "XYZ");
    gStyle->SetStripDecimals(kTRUE);
    gStyle->SetTickLength(0.03, "XYZ");
    gStyle->SetNdivisions(510, "XYZ");
    Int_t num=7;
    TH1D*th1[num];
	run("outZA-cut-aQGC-mu",num,th1);
	TFile* f5=new TFile("1d-histo.root","RECREATE");
    for(Int_t i=0;i<num;i++){
       th1[i]->SetLineWidth(2);
//       th1[i]->Draw("HIST"); 
	   th1[i]->Write();}
	f5->Close();
    for(Int_t j=0;j<num;j++){
        cout<<"th1["<<j+1<<"]"<<endl;
        ofstream file(Form("content_th%daQGC",j));
        for(Int_t i=0;i<bins;i++){
              cout<<"bin "<<i+1<<" ;BinContent = "<<th1[j]->GetBinContent(i+1)<<endl;
              file<<th1[j]->GetBinContent(i+1)<<endl;
            } 
        }
    draw(num,th1);
    return 0;
	
}
