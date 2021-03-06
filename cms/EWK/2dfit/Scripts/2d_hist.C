#include "TH2.h"
#include "TFile.h"
#include "TTree.h"
#include <string>

using namespace std;

TH2D*th2[9];
void run(std::string filename);
void run(std::string filename){

	std::string file = filename+".root";
	TFile* f1 = TFile::Open(file.c_str());

	TTree* t = (TTree*)f1->Get("demo");

	Double_t Mjj;
	Double_t detajj;
    Double_t theWeight,lumiWeight,scalef,pweight[703];
	Double_t actualWeight[9];

	t->SetBranchAddress("Mjj", &Mjj);
	t->SetBranchAddress("deltaetajj", &detajj);
	t->SetBranchAddress("pweight", pweight);
	t->SetBranchAddress("scalef", &scalef);
	t->SetBranchAddress("theWeight", &theWeight);
	t->SetBranchAddress("lumiWeight", &lumiWeight);

	Double_t mjj_bins[4]={500, 750, 1000, 2000};
	Double_t detajj_bins[4]={2.5, 4.5, 6, 6.5};
    char th2name[9];
    for(Int_t i=0;i<9;i++){
       sprintf(th2name,"th2_%d",i);
	   th2[i] = new TH2D(th2name,th2name,3, mjj_bins, 3, detajj_bins);
	   th2[i]->Sumw2();}
    Int_t p;
	for(Int_t j=0; j<t->GetEntries();j++)
	{
		t->GetEntry(j);
        p=0;
        for(Int_t i=0;i<9;i++){
//            if(i==0) {actualWeight[i]=scalef*theWeight*lumiWeight*pweight[i];}
//            if(i==3) {actualWeight[i]=scalef*theWeight*lumiWeight*pweight[i];}
//            if(i==6) {actualWeight[i]=scalef*theWeight*lumiWeight*pweight[i];}
//            if(i==1 || i==4 || i==7)
//                {actualWeight[i]=scalef*theWeight*lumiWeight*pweight[i];}
//            if(i==2 || i==5 || i==8)
//              actualWeight[i]=scalef*theWeight*lumiWeight*pweight[i];
              actualWeight[p]=scalef*lumiWeight*pweight[i];

		if(Mjj<2000 && detajj<6.5) th2[p]->Fill(Mjj, detajj, actualWeight[i]);
		if(Mjj>=2000 && detajj<6.5) th2[p]->Fill(1999, detajj, actualWeight[i]);
		if(Mjj<2000 && detajj>=6.5) th2[p]->Fill(Mjj, 6.1, actualWeight[i]);
		if(Mjj>=2000 && detajj>=6.5) th2[p]->Fill(1999, 6.1, actualWeight[i]);
        p++;
     	}
         cout<<"entry "<<j<<endl;
         cout<<"scalef = "<<scalef<<endl;
         cout<<"lumiWeight = "<<lumiWeight<<endl;
         for(Int_t k=0;k<9;k++){
             cout<<"pweight ["<<k<<"] = "<<pweight[k]<<endl;
          }
         for(Int_t k=0;k<9;k++){
            cout<<"actualWeight ["<<k<<"] = "<<actualWeight[k]<<endl;
          }
         cout<<"######################################"<<endl;
    }
}

int main(){
    cout<<"test"<<endl;
	TFile* f5=new TFile("th2-histo.root","RECREATE");
	run("outZA-cut1");
    for(Int_t i=0;i<9;i++){
	   th2[i]->Write();}
	f5->Close();
	
}
