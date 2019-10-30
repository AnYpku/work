#include "TH2.h"
#include "TFile.h"
#include "TTree.h"
#include <string>
#define num 9

using namespace std;

TH2D*th2[num];
void run(std::string filename);
void run(std::string filename){

	std::string file = filename+".root";
	TFile* f1 = TFile::Open(file.c_str());

	//TTree* t = (TTree*)f1->Get("demo");
	TTree* t = (TTree*)f1->Get("ZPKUCandidates");

	Double_t Mjj,Mva;
	Double_t detajj;
    Double_t drj1a,drj2a,drj1l,drj2l,drla,drla2;
    Double_t theWeight,lumiWeight,scalef,pweight[703];
	Double_t actualWeight[num];
    Bool_t flag,LEPmu,LEPele,PHOTONb,PHOTONe,JET;

	t->SetBranchAddress("Mjj", &Mjj);
	t->SetBranchAddress("deltaetajj", &detajj);
	t->SetBranchAddress("pweight", pweight);
	t->SetBranchAddress("scalef", &scalef);
	t->SetBranchAddress("theWeight", &theWeight);
	t->SetBranchAddress("lumiWeight", &lumiWeight);
	t->SetBranchAddress("Mva", &Mva);
	t->SetBranchAddress("drla", &drla);
	t->SetBranchAddress("drla2", &drla2);
	t->SetBranchAddress("drj1a", &drj1a);
	t->SetBranchAddress("drj2a", &drj2a);
	t->SetBranchAddress("drj1l", &drj1l);
	t->SetBranchAddress("drj2l", &drj2l);
    double ptlep1,ptlep2,etalep1,etalep2,massVlep;
    double jet1pt,jet2pt,jet1eta,jet2eta;
    double photonet,photoneta;
    double zepp;
    double npT,pileupWeight;
    int nlooseeles,nloosemus,HLT_Ele2,lep,HLT_Mu2;
    t->SetBranchAddress("pileupWeight",&pileupWeight);
    t->SetBranchAddress("nloosemus",&nloosemus);
    t->SetBranchAddress("nlooseeles",&nlooseeles);
    t->SetBranchAddress("npT",&npT);
    t->SetBranchAddress("HLT_Ele2",&HLT_Ele2);
    t->SetBranchAddress("HLT_Mu2",&HLT_Mu2);
    t->SetBranchAddress("lep",&lep);
    t->SetBranchAddress("zepp",&zepp);
    t->SetBranchAddress("photonet",&photonet);
    t->SetBranchAddress("photoneta",&photoneta);
    t->SetBranchAddress("jet1pt",&jet1pt);
    t->SetBranchAddress("jet2pt",&jet2pt);
    t->SetBranchAddress("jet1eta",&jet1eta);
    t->SetBranchAddress("jet2eta",&jet2eta);
    t->SetBranchAddress("ptlep1",&ptlep1);
    t->SetBranchAddress("ptlep2",&ptlep2);
    t->SetBranchAddress("etalep1",&etalep1);
    t->SetBranchAddress("etalep2",&etalep2);
    t->SetBranchAddress("massVlep",&massVlep);

	Double_t mjj_bins[2]={150, 400};
	Double_t detajj_bins[2]={0.,6.5};
    char th2name[num];
    for(Int_t i=0;i<num;i++){
       sprintf(th2name,"th2_%d",i);
	   th2[i] = new TH2D(th2name,th2name,1, mjj_bins, 1, detajj_bins);
	   th2[i]->Sumw2();}
    Int_t p;
	for(Int_t j=0; j<t->GetEntries();j++)
	{
        p=0;
		t->GetEntry(j);
        flag = Mjj>150 && Mjj<400 && Mva<100 && drla >0.7&&drla2>0.7 && drj1a>0.5&&drj2a>0.5 && drj1l>0.5&&drj2l>0.5; 
        LEPmu = lep==13 && HLT_Mu2>0&& ptlep1 > 20. && ptlep2 > 20.&& fabs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles==0 && nloosemus <3  && massVlep >70. && massVlep < 110;
        LEPele = lep==11 && HLT_Ele2>0 && ptlep1 > 25. && ptlep2 > 25.&& fabs(etalep1) < 2.5 &&abs(etalep2) < 2.5 && nlooseeles < 3 && nloosemus == 0  && massVlep >70. && massVlep < 110;
        PHOTONb= photonet>20 &&(/*(fabs(photoneta)<2.5&&fabs(photoneta)>1.566) ||*/ fabs(photoneta)<1.4442);
        PHOTONe= photonet>20 &&((fabs(photoneta)<2.5&&fabs(photoneta)>1.566) /*|| fabs(photoneta)<1.4442*/);
        JET=jet1pt> 30 && jet2pt > 30 && fabs(jet1eta)< 4.7 && fabs(jet2eta)<4.7;
        //if((LEPmu&&PHOTONb&&JET&&flag)==false) continue;
        //if((LEPmu&&PHOTONe&&JET&&flag)==false) continue;
        //if((LEPele&&PHOTONb&&JET&&flag)==false) continue;
        if((LEPele&&PHOTONe&&JET&&flag)==false) continue;
        for(Int_t i=104;i<113;i++){
           if(p==0)
               { actualWeight[p]=scalef*lumiWeight*pweight[i];
                // if(i==109 || i==111) continue;
               }
           else
               { actualWeight[p]=2*scalef*lumiWeight*pweight[i];
              //   if(i==109 || i==111) continue;
               }


		if(Mjj<400 && detajj<6.5) th2[p]->Fill(Mjj, detajj, actualWeight[p]);
		if(Mjj>=400 && detajj<6.5) th2[p]->Fill(399, detajj, actualWeight[p]);
		if(Mjj<400 && detajj>=6.5) th2[p]->Fill(Mjj, 6.1, actualWeight[p]);
		if(Mjj>=400 && detajj>=6.5) th2[p]->Fill(399, 6.1, actualWeight[p]);
        p++;
     	}
         cout<<"p = "<<p<<endl;
         cout<<"entry "<<j<<endl;
         cout<<"scalef = "<<scalef<<endl;
         cout<<"lumiWeight = "<<lumiWeight<<endl;
         for(Int_t k=104;k<113;k++){
             cout<<"pweight ["<<k<<"] = "<<pweight[k]<<endl;
          }
         for(Int_t k=0;k<num;k++){
            cout<<"actualWeight ["<<k<<"] = "<<actualWeight[k]<<endl;
          }
         cout<<"######################################"<<endl;
    }
//  return 0;
}

int d_hist(){
	run("outZA-mu-ele");
	TFile* f5=new TFile("th2-histo.root","RECREATE");
    for(Int_t i=0;i<num;i++){
	   th2[i]->Write();}
	f5->Close();
    return 0;
	
}
