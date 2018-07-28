#include "TH2.h"
#include "TFile.h"
#include "TTree.h"
#include <string>

using namespace std;

TH2D*th2[9];
//TH2D* hist_2d_mc(std::string filename){
void run(std::string filename){

	std::string file = filename+".root";
	TFile* f1 = TFile::Open(file.c_str());

	TTree* t = (TTree*)f1->Get("demo");

//	Double_t ZGmass;
	Double_t Mjj;
	Double_t detajj;
    Double_t theWeight,lumiWeight,scalef,pweight[703];
	Double_t actualWeight[9];

//	t->SetBranchAddress("ZGmass", &ZGmass);
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
	for(Int_t j=0; j<t->GetEntries();j++)
	{
		t->GetEntry(j);
        for(Int_t i=0;i<9;i++){
           actualWeight[i]=theWeight*lumiWeight*pweight[i];

		   if(Mjj<2000 && detajj<6.5) th2[i]->Fill(Mjj, detajj, actualWeight[i]);
		   if(Mjj>=2000 && detajj<6.5) th2[i]->Fill(1999, detajj, actualWeight[i]);
		   if(Mjj<2000 && detajj>=6.5) th2[i]->Fill(Mjj, 6.1, actualWeight[i]);
		   if(Mjj>=2000 && detajj>=6.5) th2[i]->Fill(1999, 6.1, actualWeight[i]);
     	}
                cout<<"entry "<<j<<endl;
                cout<<"scalef = "<<scalef<<endl;
                cout<<"theWeight = "<<theWeight<<endl;
                cout<<"lumiWeight = "<<lumiWeight<<endl;
                for(Int_t k=0;k<9;k++){
                    cout<<"pweight ["<<k<<"] = "<<pweight[k]<<endl;
                 }
                for(Int_t k=0;k<9;k++){
                   cout<<"actualWeight ["<<k<<"] = "<<actualWeight[k]<<endl;
                 }
                cout<<"######################################"<<endl;
    }
//	return th2[0];
//	return th2[1];
//	return th2[2];
//	return th2[3];
//	return th2[4];
//	return th2[5];
//	return th2[6];
//	return th2[7];
//	return th2[8];
}
//TH2D* hist_2d(std::string filename){
//
//	std::string file = "../root_file_zepp18/optimal_"+filename+".root";
//	TFile* f1 = TFile::Open(file.c_str());
//
//	TTree* t = (TTree*)f1->Get("outtree");
//
//	Double_t Mjj;
//	Double_t ZGmass;
//	Double_t detajj;
//	Double_t actualWeight;
//
//	t->SetBranchAddress("Mjj", &Mjj);
//	t->SetBranchAddress("ZGmass", &ZGmass);
//	t->SetBranchAddress("detajj", &detajj);
//	t->SetBranchAddress("actualWeight", &actualWeight);
//
//	Double_t mjj_bins[4]={500, 750, 1000,2000};
////	Double_t mlla_bins[5]={90, 130, 170, 210, 250};
//	Double_t detajj_bins[4]={2.5, 4.5, 6, 6.5};
////	TH2D* th2 = new TH2D("th2","th2",4, mjj_bins, 4, mlla_bins);
//	TH2D* th2 = new TH2D("th2","th2",3, mjj_bins, 3, detajj_bins);
//	th2->Sumw2();
//	for(Int_t i=0; i<t->GetEntries();i++)
//	{
//		t->GetEntry(i);
//		if(Mjj<2000 && detajj<6.5) th2->Fill(Mjj, detajj);
//		if(Mjj>=2000 && detajj<6.5) th2->Fill(1999, detajj);
//		if(Mjj<2000 && detajj>=6.5) th2->Fill(Mjj, 6.1);
//		if(Mjj>=2000 && detajj>=6.5) th2->Fill(1999, 6.1);
//	}
//
//	return th2;
//}

int main(){
//	TFile* f1=new TFile("2d_ST.root","RECREATE");
//	TFile* f2=new TFile("2d_VV.root","RECREATE");
//	TFile* f3=new TFile("2d_TTA.root","RECREATE");
//	TFile* f4=new TFile("2d_WA.root","RECREATE");
	TFile* f5=new TFile("th2-histo.root","RECREATE");
//	TFile* f6=new TFile("2d_ZA_EWK.root","RECREATE");
//	TFile* f7=new TFile("2d_plj.root","RECREATE");
//	TFile* f8=new TFile("2d_DEle.root","RECREATE");

//	TH2D* h1= hist_2d_mc("outZA-cut1");
//	TH2D* h2= hist_2d_mc("VV");
//	TH2D* h3= hist_2d_mc("TTA");
//	TH2D* h4= hist_2d_mc("WA");
	run("outZA-cut1");
//	f5->cd();
    for(Int_t i=0;i<9;i++){
	   th2[i]->Write();}
	f5->Close();
//    for(Int_t i=0;i<9;i++){
//      delete th2[i];}
//	TH2D* h6= hist_2d_mc("outZA-EWK");
//	TH2D* h7= hist_2d_mc("outphotonlikejet_ele_mediumlikephoton");
//	TH2D* h8= hist_2d("outDEle");
	
//	f1->cd();
//	h1->Write();
//	f1->Close();
//	f2->cd();
//	h2->Write();
//	f2->Close();
//	f3->cd();
//	h3->Write();
//	f3->Close();
//	f4->cd();
//	h4->Write();
//	f4->Close();
//	f6->cd();
//	h6->Write();
//	f6->Close();
//	f7->cd();
//	h7->Write();
//	f7->Close();
//	f8->cd();
//	h8->Write();
//	f8->Close();
}
