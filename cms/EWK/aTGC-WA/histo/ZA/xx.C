#define xx_cxx
#include "L1_weight.C"
#include "xx.h"
#include <vector>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

using namespace std;
void xx::Loop()
{
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   char name[373];
   for(Int_t i=0;i<373;i++){
	   sprintf(name,"h1_%d",i);
	   h1[i] = new TH1D(name,name,100,60,200);
   }
   Long64_t nbytes = 0, nb = 0;
   int cutl0=0,cutp0=0,cutr0=0,position;
   vector<double> vector_pweight;
   vector<double>::iterator biggest_pweight;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   if(!(photonet>60)) continue;      
   cout<<"jentry = "<<jentry<<endl;
   for(Int_t i=0;i<373;i++){
          h1[i]->Fill(photonet,pweight[i+104]);
          vector_pweight.push_back(pweight[i+104]);
         // cout<<"pweight["<<i+104<<"] = "<<pweight[i+104]<<endl;
     }
   biggest_pweight = max_element(begin(vector_pweight),end(vector_pweight));
   position = distance( begin(vector_pweight), biggest_pweight);
   cout<<"the biggest pweight = "<<*biggest_pweight<<"; position = "<<position+104<<endl;
          cout<<"pweight[475] = "<<pweight[475]<<endl;
          cout<<"pweight[476] = "<<pweight[476]<<endl;
          cout<<"pweight[849] = "<<pweight[849]<<endl;
          cout<<"pweight[0] = "<<pweight[0]<<endl;
   vector_pweight.clear();
   }
   /*TCanvas* c1[372];
   for(Int_t i=0;i<373;i++){
       if(i<372)  c1[i]= new TCanvas(Form("c1_%0.d",i),Form("c1_%0.d",i),900,600);  
           h1[i]->SetLineColor(kBlue);
           h1[i]->SetMarkerSize(2);
           h1[i]->SetMarkerStyle(22);
           if(i==372)  
           { h1[372]->SetMarkerStyle(22);h1[372]->SetMarkerColor(kRed);h1[372]->SetMarkerSize(2);}
       c1[i]->cd();
       h1[372]->Draw("P");
       if(i!=372) h1[i]->Draw("same P");
       c1[i]->SetFrameFillColor(41);
       c1[i]->Print(Form("h_%0.d.pdf",i+1));
       delete c1[i];
  }*/
}
