#include "TH2.h"
#include "TFile.h"
#include "TTree.h"
#include <string>

using namespace std;

TH2D*th2[51];
void run(std::string filename);
void run(std::string filename){

	std::string file = filename+".root";
	TFile* f1 = TFile::Open(file.c_str());

	TTree* t = (TTree*)f1->Get("ZPKUCandidates");

	Double_t Mjj;
	Double_t detajj;
    Double_t theWeight,lumiWeight,scalef,pweight[703];
	Double_t actualWeight[51];

	t->SetBranchAddress("Mjj", &Mjj);
	t->SetBranchAddress("deltaetajj", &detajj);
	t->SetBranchAddress("pweight", pweight);
	t->SetBranchAddress("scalef", &scalef);
	t->SetBranchAddress("theWeight", &theWeight);
	t->SetBranchAddress("lumiWeight", &lumiWeight);

//	Double_t mjj_bins[4]={500, 750, 1000, 2000};
	Double_t mjj_bins[4]={500, 800, 1200, 2000};
	Double_t detajj_bins[4]={2.5, 4.5, 6, 6.5};
//    Double_t mjj_bins[4]={500, 800,1200, 2000};
    char th2name[51];
    for(Int_t i=0;i<51;i++){
       sprintf(th2name,"th2_%d",i);
	   th2[i] = new TH2D(th2name,th2name,3, mjj_bins, 3, detajj_bins);
	   th2[i]->Sumw2();}
    Int_t p;
	for(Int_t j=0; j<t->GetEntries();j++)
	{
        p=0;
		t->GetEntry(j);
        for(Int_t i=384;i<=434;i++){
              actualWeight[p]=scalef*lumiWeight*pweight[i];

		if(Mjj<2000 && detajj<6.5) th2[p]->Fill(Mjj, detajj, actualWeight[p]);
		if(Mjj>=2000 && detajj<6.5) th2[p]->Fill(1999, detajj, actualWeight[p]);
		if(Mjj<2000 && detajj>=6.5) th2[p]->Fill(Mjj, 6.1, actualWeight[p]);
		if(Mjj>=2000 && detajj>=6.5) th2[p]->Fill(1999, 6.1, actualWeight[p]);
        p++;
     	}
         cout<<" p = "<<p<<endl;
         cout<<"entry "<<j<<endl;
         cout<<"scalef = "<<scalef<<endl;
         cout<<"lumiWeight = "<<lumiWeight<<endl;
         for(Int_t k=384;k<=434;k++){
             cout<<"pweight ["<<k<<"] = "<<pweight[k]<<endl;
          }
         for(Int_t k=0;k<p;k++){
            cout<<"actualWeight ["<<k<<"] = "<<actualWeight[k]<<endl;
          }
         cout<<"######################################"<<endl;
    }
//  return 0;
}

int d_hist(){
    cout<<"test"<<endl;
	run("outZA-mu-ele");
	TFile* f5=new TFile("th2-histo.root","RECREATE");
    for(Int_t i=0;i<51;i++){
	   th2[i]->Write();}
	f5->Close();
    return 0;
	
}
