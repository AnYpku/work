#include "TH2.h"
#include "TFile.h"
#include "TTree.h"
#include <string>
#include <iostream>
#include "TCanvas.h"
#include <vector>

using namespace std;

TH2D* hist_2d_mc(TString filename){

    TString file = "./optimal_"+filename+".root";
	TFile* f1 = TFile::Open(file);

	TTree* t = (TTree*)f1->Get("outtree");

	Double_t Mjj;
	Double_t ZGmass;
	Double_t detajj;
	Double_t scalef;
	Double_t pileupWeight;

	t->SetBranchAddress("Mjj", &Mjj);
    Double_t photonet;
	t->SetBranchAddress("photonet", &photonet);
//	t->SetBranchAddress("ZGmass", &ZGmass);
	t->SetBranchAddress("detajj", &detajj);
	t->SetBranchAddress("scalef", &scalef);
	t->SetBranchAddress("pileupWeight", &pileupWeight);
//	Double_t mjj_bins[4]={500, 750, 1000, 2000};
	Double_t mjj_bins[4]={500, 800, 1200, 2000};
    Double_t pt_bins[5]={20,50,80,120,400};
//	Double_t mlla_bins[5]={90, 130, 170, 210, 240};
//	Double_t detajj_bins[4]={2.5, 4.5,  6, 6.5};
	Double_t detajj_bins[4]={2.5, 4., 5, 6.5};
    Double_t actualWeight;
//	TH2D* th2 = new TH2D("th2","th2",4, mjj_bins, 4, mlla_bins);
	TH2D* th2 = new TH2D("th2","th2" ,3, mjj_bins,3, detajj_bins);
	th2->Sumw2();
    if(filename.Contains("plj")) actualWeight=1;
    actualWeight=scalef*pileupWeight;
	for(Int_t i=0; i<t->GetEntries();i++)
	{
		t->GetEntry(i);
        th2->Fill(Mjj,detajj, actualWeight);
	}

	return th2;
}
TH2D* hist_2d(std::string filename){

	std::string file = "./optimal_"+filename+".root";
	TFile* f1 = TFile::Open(file.c_str());

	TTree* t = (TTree*)f1->Get("outtree");

	Double_t Mjj;
	Double_t ZGmass;
	Double_t detajj;
	Double_t scalef;
    Double_t pileupWeight;
    Double_t actualWeight;
    Double_t photonet;
	t->SetBranchAddress("photonet", &photonet);
	t->SetBranchAddress("Mjj", &Mjj);
//	t->SetBranchAddress("ZGmass", &ZGmass);
	t->SetBranchAddress("detajj", &detajj);
    t->SetBranchAddress("scalef", &scalef);
	t->SetBranchAddress("pileupWeight", &pileupWeight);
    actualWeight=1;
//	Double_t mjj_bins[4]={500, 750, 1000, 2000};
	Double_t mjj_bins[4]={500, 800, 1200, 2000};
    Double_t pt_bins[5]={20,50,80,120,400};
//	Double_t mlla_bins[5]={90, 130, 170, 210, 250};
	Double_t detajj_bins[4]={2.5, 4.5, 6, 6.5};
//	TH2D* th2 = new TH2D("th2","th2",4, mjj_bins, 4, mlla_bins);
	TH2D* th2 = new TH2D("th2","th2", 3, mjj_bins,3, detajj_bins);
	th2->Sumw2();
	for(Int_t i=0; i<t->GetEntries();i++)
	{
		t->GetEntry(i);
        th2->Fill(Mjj,detajj,actualWeight);
	}

	return th2;
}

int main(){
	TFile* f1=new TFile("2d_ST.root","RECREATE");
	TFile* f2=new TFile("2d_VV.root","RECREATE");
	TFile* f3=new TFile("2d_TTA.root","RECREATE");
	TFile* f4=new TFile("2d_WA.root","RECREATE");
	TFile* f5=new TFile("2d_ZA.root","RECREATE");
	TFile* f6=new TFile("2d_ZA_EWK.root","RECREATE");
	TFile* f7=new TFile("2d_plj.root","RECREATE");
	TFile* f8=new TFile("2d_Muon.root","RECREATE");

    vector<TString> histoname;
    histoname.push_back("ST");
    histoname.push_back("VV");
    histoname.push_back("TTA");
    histoname.push_back("WA");
    histoname.push_back("ZA");
    histoname.push_back("ZA_sig");
    histoname.push_back("plj");
    histoname.push_back("Muon");

	TH2D* h1= hist_2d_mc("ST");
	TH2D* h2= hist_2d_mc("VV");
	TH2D* h3= hist_2d_mc("TTA");
	TH2D* h4= hist_2d_mc("WA");
	TH2D* h5= hist_2d_mc("ZA");
	TH2D* h6= hist_2d_mc("ZA-EWK");
	TH2D* h7= hist_2d_mc("DMuon_plj_weightb");
	TH2D* h8= hist_2d("Muon");
	
	f1->cd();
	h1->Write();
	f1->Close();
	f2->cd();
	h2->Write();
	f2->Close();
	f3->cd();
	h3->Write();
	f3->Close();
	f4->cd();
	h4->Write();
	f4->Close();
	f5->cd();
	h5->Write();
	f5->Close();
	f6->cd();
	h6->Write();
	f6->Close();
	f7->cd();
	h7->Write();
	f7->Close();
	f8->cd();
	h8->Write();
	f8->Close();
    vector<TH2D*> histo2d;
    histo2d.push_back(h1);
    histo2d.push_back(h2);
    histo2d.push_back(h3);
    histo2d.push_back(h4);
    histo2d.push_back(h5);
    histo2d.push_back(h6);
    histo2d.push_back(h7);
    histo2d.push_back(h8);

    TCanvas* c[9];
    for(Int_t i=0;i<histo2d.size();i++){
        c[i] = new TCanvas(Form("c%d",i+1),Form("photonet vs deltaeatjj %d histo",i+1),900,600);
        histo2d[i]->Draw("COLZTEXTE");
       // histo2d[i]->SetMarkerSize(1.8);
        c[i]->SaveAs("./"+histoname[i]+".eps");
    }

}
