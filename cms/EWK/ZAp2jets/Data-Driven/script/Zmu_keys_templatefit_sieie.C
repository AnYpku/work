// Photon fake rate: Template method 
// 
// daneng.yang.pku@gmail.com
//

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooGaussModel.h"
#include "RooAddModel.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooPolynomial.h"
#include "RooKeysPdf.h"
#include "RooNDKeysPdf.h"
#include "RooProdPdf.h"
#include "TCanvas.h"
#include "TLorentzVector.h"
#include "TAxis.h"
#include "TH1.h"
#include "TTree.h"
#include "TFile.h"
#include "TLegend.h"
#include "RooPlot.h"

using namespace RooFit ;

void mu_keys_templatefit(float lowpt,float highpt){

    // ZA sample
    TFile* f1 = TFile::Open("../../../VAJets_11_21/Ztest/Outroot/outZA.root");
    // DY sample
    TFile* f2 = TFile::Open("../../../VAJets_11_21/Ztest/Outroot/outZJets.root");
    // Data sample
    TFile* f3 = TFile::Open("../../../VAJets_11_21/Wtest/VAJets_11_21/outSMOCT.root");
    // True and Fake Sample
    TFile* f4 = TFile::Open("../../../VAJets_11_21/Ztest/Outroot/outDMOCT.root");
    //WA sample
    TFile* f5 = TFile::Open("../../../VAJets_11_21/Wtest/VAJets_11_21/outWA.root");

    TFile fdata(Form("mu_hist_%0.f_%0.f.root",lowpt,highpt), "RECREATE");


    TTree* t1 = (TTree*) f1->Get("demo");
    TTree* t2 = (TTree*) f2->Get("demo");
    TTree* t3 = (TTree*) f3->Get("demo");
    TTree* t4 = (TTree*) f4->Get("demo");
    TTree* t5 = (TTree*) f5->Get("demo");

        //ZA
		t1->SetBranchStatus("photon_pev",1);
		t1->SetBranchStatus("photon_hoe",1);
		t1->SetBranchStatus("photon_chiso",1);
		t1->SetBranchStatus("photon_nhiso",1);
		t1->SetBranchStatus("photon_phoiso",1);
		t1->SetBranchStatus("photon_sieie",1);
		t1->SetBranchStatus("photon_pt",1);
		t1->SetBranchStatus("photon_eta",1);
		t1->SetBranchStatus("photon_phi",1);
		t1->SetBranchStatus("photon_e",1);
        t1->SetBranchStatus("photon_isprompt",1);
        t1->SetBranchStatus("photon_drla",1);
        t1->SetBranchStatus("photon_drla2",1);
        t1->SetBranchStatus("massVlep",1);
        t1->SetBranchStatus("yVlep",1);
        t1->SetBranchStatus("phiVlep",1);
        t1->SetBranchStatus("ptVlep",1);
        t1->SetBranchStatus("triggerWeight",1);
        t1->SetBranchStatus("lumiWeight",1);
        t1->SetBranchStatus("pileupWeight",1);
        t1->SetBranchStatus("theWeight",1);
        t1->SetBranchStatus("scalef",1);

    
    
        //DY
		t2->SetBranchStatus("photon_pev",1);
		t2->SetBranchStatus("photon_hoe",1);
		t2->SetBranchStatus("photon_chiso",1);
		t2->SetBranchStatus("photon_nhiso",1);
		t2->SetBranchStatus("photon_phoiso",1);
		t2->SetBranchStatus("photon_sieie",1);
		t2->SetBranchStatus("photon_pt",1);
		t2->SetBranchStatus("photon_eta",1);
		t2->SetBranchStatus("photon_phi",1);
		t2->SetBranchStatus("photon_e",1);
        t2->SetBranchStatus("photon_isprompt",1);
        t2->SetBranchStatus("photon_drla",1);
        t2->SetBranchStatus("photon_drla2",1);
        t2->SetBranchStatus("massVlep",1);
    t2->SetBranchStatus("yVlep",1);
    t2->SetBranchStatus("ptVlep",1);
    t2->SetBranchStatus("phiVlep",1);
    t2->SetBranchStatus("triggerWeight",1);
    t2->SetBranchStatus("lumiWeight",1);
    t2->SetBranchStatus("pileupWeight",1);
    t2->SetBranchStatus("theWeight",1);
    t2->SetBranchStatus("scalef",1);





    //SMDATA
    t3->SetBranchStatus("photon_pev",1);
    t3->SetBranchStatus("photon_hoe",1);
    t3->SetBranchStatus("photon_chiso",1);
    t3->SetBranchStatus("photon_nhiso",1);
    t3->SetBranchStatus("photon_phoiso",1);
    t3->SetBranchStatus("photon_sieie",1);
    t3->SetBranchStatus("photon_pt",1);
    t3->SetBranchStatus("photon_eta",1);
    t3->SetBranchStatus("photon_phi",1);
    t3->SetBranchStatus("photon_e",1);
    t3->SetBranchStatus("photon_isprompt",1);
    t3->SetBranchStatus("photon_drla",1);
    
    //MC WA
    t5->SetBranchStatus("photon_pev",1);
    t5->SetBranchStatus("photon_hoe",1);
    t5->SetBranchStatus("photon_chiso",1);
    t5->SetBranchStatus("photon_nhiso",1);
    t5->SetBranchStatus("photon_phoiso",1);
    t5->SetBranchStatus("photon_sieie",1);
    t5->SetBranchStatus("photon_pt",1);
    t5->SetBranchStatus("photon_eta",1);
    t5->SetBranchStatus("photon_phi",1);
    t5->SetBranchStatus("photon_e",1);
    t5->SetBranchStatus("photon_isprompt",1);
    t5->SetBranchStatus("photon_drla",1);
    t5->SetBranchStatus("triggerWeight",1);
    t5->SetBranchStatus("lumiWeight",1);
    t5->SetBranchStatus("pileupWeight",1);
    t5->SetBranchStatus("theWeight",1);
    t5->SetBranchStatus("scalef",1);




    //DMDATA
    t4->SetBranchStatus("photon_pev",1);
    t4->SetBranchStatus("photon_hoe",1);
    t4->SetBranchStatus("photon_chiso",1);
    t4->SetBranchStatus("photon_nhiso",1);
    t4->SetBranchStatus("photon_phoiso",1);
    t4->SetBranchStatus("photon_sieie",1);
    t4->SetBranchStatus("photon_pt",1);
    t4->SetBranchStatus("photon_eta",1);
    t4->SetBranchStatus("photon_phi",1);
    t4->SetBranchStatus("photon_e",1);
    t4->SetBranchStatus("photon_isprompt",1);
    t4->SetBranchStatus("photon_drla",1);
    t4->SetBranchStatus("photon_drla2",1);
    t4->SetBranchStatus("massVlep",1);
    t4->SetBranchStatus("yVlep",1);
    t4->SetBranchStatus("ptVlep",1);
    t4->SetBranchStatus("phiVlep",1);








    // ZA sample
    Double_t photon_eta_za[50],photon_pt_za[50],photon_phi_za[50],;
    Char_t   photon_pev_za[50];
    Double_t photon_hoe_za[50],photon_chiso_za[50],photon_nhiso_za[50],photon_phoiso_za[50],photon_sieie_za[50],photon_drla_za[50];
    Double_t photon_drla2_za[50] =0;
    Double_t massVlep_za,yVlep_za,phiVlep_za,ptVlep_za,mlla_za;
    Int_t    photon_isprompt_za[50];
    Double_t pileupWeight_za,lumiWeight_za,triggerWeight_za,theWeight_za,scalef_za;
    
    // DY sample
    Double_t photon_eta_dy[50],photon_pt_dy[50],photon_phi_dy[50],photon_e_dy[50];
    Char_t   photon_pev_dy[50];
    Double_t photon_hoe_dy[50],photon_chiso_dy[50],photon_nhiso_dy[50],photon_phoiso_dy[50],photon_sieie_dy[50],photon_drla_dy[50],photon_drla2_dy[50],massVlep_dy,yVlep_dy,phiVlep_dy,ptVlep_dy,mlla_dy;
    Int_t    photon_isprompt_dy[50];
    Double_t pileupWeight_dy,lumiWeight_dy,triggerWeight_dy,theWeight_dy,scalef_dy;


   // Data sample
    Double_t photon_eta[50],photon_pt[50],photon_phi[50],photon_e[50];
    Char_t   photon_pev[50];
    Double_t photon_hoe[50],photon_chiso[50],photon_nhiso[50],photon_phoiso[50],photon_sieie[50],photon_drla[50],massVlep;
    Int_t    photon_isprompt[50];
    
    // WA sample
    Double_t photon_eta_wa[50],photon_pt_wa[50],photon_phi_wa[50],photon_e_wa[50];
    Char_t   photon_pev_wa[50];
    Double_t photon_hoe_wa[50],photon_chiso_wa[50],photon_nhiso_wa[50],photon_phoiso_wa[50],photon_sieie_wa[50],photon_drla_wa[50],massVlep_wa;
    Int_t    photon_isprompt_wa[50];
    Double_t pileupWeight_wa,lumiWeight_wa,triggerWeight_wa,theWeight_wa,scalef_wa;

    
    // True and Fake sample
    Double_t photon_eta_tf[50],photon_pt_tf[50],photon_phi_tf[50],photon_e_tf[50];
    Char_t   photon_pev_tf[50];
    Double_t photon_hoe_tf[50],photon_chiso_tf[50],photon_nhiso_tf[50],photon_phoiso_tf[50],photon_sieie_tf[50],photon_drla_tf[50],photon_drla2_tf[50],massVlep_tf,yVlep_tf,phiVlep_tf,ptVlep_tf,mlla_tf;
    Int_t    photon_isprompt_tf[50];

    t1->SetBranchAddress("photon_eta",photon_eta_za);
    t1->SetBranchAddress("photon_pt",photon_pt_za);
    t1->SetBranchAddress("photon_phi",photon_phi_za);
    t1->SetBranchAddress("photon_pev",photon_pev_za);
    t1->SetBranchAddress("photon_hoe",photon_hoe_za);
    t1->SetBranchAddress("photon_chiso",photon_chiso_za);
    t1->SetBranchAddress("photon_nhiso",photon_nhiso_za);
    t1->SetBranchAddress("photon_phoiso",photon_phoiso_za);
    t1->SetBranchAddress("photon_sieie",photon_sieie_za);
    t1->SetBranchAddress("photon_isprompt",photon_isprompt_za);
    t1->SetBranchAddress("photon_drla",photon_drla_za);
    t1->SetBranchAddress("photon_drla2",photon_drla2_za);
    t1->SetBranchAddress("massVlep",&massVlep_za);
    t1->SetBranchAddress("yVlep",&yVlep_za);
    t1->SetBranchAddress("phiVlep",&phiVlep_za);
    t1->SetBranchAddress("ptVlep",&ptVlep_za);
    t1->SetBranchAddress("pileupWeight",&pileupWeight_za);
    t1->SetBranchAddress("lumiWeight",&lumiWeight_za);
    t1->SetBranchAddress("triggerWeight",&triggerWeight_za);
    t1->SetBranchAddress("theWeight",&theWeight_za);
    t1->SetBranchAddress("scalef",&scalef_za);

    
    t2->SetBranchAddress("photon_eta",photon_eta_dy);
    t2->SetBranchAddress("photon_pt",photon_pt_dy);
    t2->SetBranchAddress("photon_phi",photon_phi_dy);
    t2->SetBranchAddress("photon_e",photon_e_dy);
    t2->SetBranchAddress("photon_pev",photon_pev_dy);
    t2->SetBranchAddress("photon_hoe",photon_hoe_dy);
    t2->SetBranchAddress("photon_chiso",photon_chiso_dy);
    t2->SetBranchAddress("photon_nhiso",photon_nhiso_dy);
    t2->SetBranchAddress("photon_phoiso",photon_phoiso_dy);
    t2->SetBranchAddress("photon_sieie",photon_sieie_dy);
    t2->SetBranchAddress("photon_isprompt",photon_isprompt_dy);
    t2->SetBranchAddress("photon_drla",photon_drla_dy);
    t2->SetBranchAddress("photon_drla2",photon_drla2_dy);
    t2->SetBranchAddress("massVlep",&massVlep_dy);
    t2->SetBranchAddress("yVlep",&yVlep_dy);
    t2->SetBranchAddress("phiVlep",&phiVlep_dy);
    t2->SetBranchAddress("ptVlep",&ptVlep_dy);
    t2->SetBranchAddress("pileupWeight",&pileupWeight_dy);
    t2->SetBranchAddress("lumiWeight",&lumiWeight_dy);
    t2->SetBranchAddress("triggerWeight",&triggerWeight_dy);
    t2->SetBranchAddress("theWeight",&theWeight_dy);
    t2->SetBranchAddress("scalef",&scalef_dy);





   t3->SetBranchAddress("photon_eta",photon_eta);
   t3->SetBranchAddress("photon_pt",photon_pt);
   t3->SetBranchAddress("photon_e",photon_e);
   t3->SetBranchAddress("photon_phi",photon_phi);
   t3->SetBranchAddress("photon_pev",photon_pev);
   t3->SetBranchAddress("photon_hoe",photon_hoe);
   t3->SetBranchAddress("photon_chiso",photon_chiso);
   t3->SetBranchAddress("photon_nhiso",photon_nhiso);
   t3->SetBranchAddress("photon_phoiso",photon_phoiso);
   t3->SetBranchAddress("photon_sieie",photon_sieie);
   t3->SetBranchAddress("photon_isprompt",photon_isprompt);
    t3->SetBranchAddress("photon_drla",photon_drla);
    
    t5->SetBranchAddress("photon_eta",photon_eta_wa);
    t5->SetBranchAddress("photon_pt",photon_pt_wa);
    t5->SetBranchAddress("photon_e",photon_e_wa);
    t5->SetBranchAddress("photon_phi",photon_phi_wa);
    t5->SetBranchAddress("photon_pev",photon_pev_wa);
    t5->SetBranchAddress("photon_hoe",photon_hoe_wa);
    t5->SetBranchAddress("photon_chiso",photon_chiso_wa);
    t5->SetBranchAddress("photon_nhiso",photon_nhiso_wa);
    t5->SetBranchAddress("photon_phoiso",photon_phoiso_wa);
    t5->SetBranchAddress("photon_sieie",photon_sieie_wa);
    t5->SetBranchAddress("photon_isprompt",photon_isprompt_wa);
    t5->SetBranchAddress("photon_drla",photon_drla_wa);
    t5->SetBranchAddress("pileupWeight",&pileupWeight_wa);
    t5->SetBranchAddress("lumiWeight",&lumiWeight_wa);
    t5->SetBranchAddress("triggerWeight",&triggerWeight_wa);
    t5->SetBranchAddress("theWeight",&theWeight_wa);
    t5->SetBranchAddress("scalef",&scalef_wa);


    
    t4->SetBranchAddress("photon_eta",photon_eta_tf);
    t4->SetBranchAddress("photon_pt",photon_pt_tf);
    t4->SetBranchAddress("photon_phi",photon_phi_tf);
    t4->SetBranchAddress("photon_e",photon_e_tf);
    t4->SetBranchAddress("photon_pev",photon_pev_tf);
    t4->SetBranchAddress("photon_hoe",photon_hoe_tf);
    t4->SetBranchAddress("photon_chiso",photon_chiso_tf);
    t4->SetBranchAddress("photon_nhiso",photon_nhiso_tf);
    t4->SetBranchAddress("photon_phoiso",photon_phoiso_tf);
    t4->SetBranchAddress("photon_sieie",photon_sieie_tf);
    t4->SetBranchAddress("photon_isprompt",photon_isprompt_tf);
    t4->SetBranchAddress("photon_drla",photon_drla_tf);
    t4->SetBranchAddress("photon_drla2",photon_drla2_tf);
    t4->SetBranchAddress("massVlep",&massVlep_tf);
    t4->SetBranchAddress("yVlep",&yVlep_tf);
    t4->SetBranchAddress("phiVlep",&phiVlep_tf);
    t4->SetBranchAddress("ptVlep",&ptVlep_tf);



    

//>>>>>>>>>>>>>>>>>MC ZA TruetoFake>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    std::cout<<"Begin temp_za"<<std::endl;


    Double_t Sieie_za,weight_za; // pointer to the leading photon
    Long64_t nentries_za = t1->GetEntries();
    std::cout<<"nentries = "<<nentries_za<<std::endl;
    TFile* newfile0 = new TFile(Form("newtree0_%0.f_%0.f.root",lowpt,highpt),"recreate");
    TTree* temp_mcza = new TTree("temp_mcza","temp_mcza");
    temp_mcza->Branch("sieie",&Sieie_za);

    TH1F* h_mc_za = new TH1F("hmc_za","hmc_za",10,0.005,0.02);
    Int_t numevents_za = 0;

     for(int i=0;i<nentries_za;i++)
  //   for(int i=0;i<100;i++)
    {
                t1->GetEntry(i);
				Int_t iPhoton12_za = 0;
				Int_t pass1 = 1;
				Int_t disc1 = 0;
        if(i%1000000==0) std::cout << "Entry num " << i << std::endl;

        for(Int_t iPhoton=0;iPhoton<6;iPhoton++){
                if(photon_pev_za[iPhoton]==1 &&
                   photon_isprompt_za[iPhoton]>0 &&
                   photon_hoe_za[iPhoton]<0.05 &&
                   photon_chiso_za[iPhoton] <0.76 &&
                   photon_nhiso_za[iPhoton]<(0.97 + 0.014*photon_pt_za[iPhoton] + 0.000019*photon_pt_za[iPhoton]*photon_pt_za[iPhoton]) &&
                   photon_phoiso_za[iPhoton]<(0.08 + 0.0053*photon_pt_za[iPhoton]) &&
                   TMath::Abs(photon_eta_za[iPhoton])<1.4442 &&
                   photon_pt_za[iPhoton]>lowpt && photon_pt_za[iPhoton]<highpt){
						if(iPhoton12_za==0 && iPhoton==0)
						  {
                                disc1++;
								pass1++;
						  }
						if(iPhoton12_za==0 && pass1==0 && iPhoton>0)
						  {
								iPhoton12_za = iPhoton;
								disc1++;
						  }
						if(pass1>0 && photon_pt_za[iPhoton]>photon_pt_za[iPhoton12_za])
						  {
								iPhoton12_za = iPhoton;
								disc1++;
							}
						if(iPhoton12_za>0 && pass1==0 && photon_pt_za[iPhoton]>photon_pt_za[iPhoton12_za])
						  {
								iPhoton12_za = iPhoton;
								disc1++;
							}
					}
				}
        weight_za = pileupWeight_za*lumiWeight_za*triggerWeight_za*scalef_za*0.553;
      //  std::cout<<weight_za<<std::endl;


            if(disc1>0 &&
               photon_drla_za[iPhoton12_za]>1 && photon_drla_za[iPhoton12_za]<10 &&
               photon_drla2_za[iPhoton12_za]>1 && photon_drla2_za[iPhoton12_za]<10 &&
               massVlep_za>80 && massVlep_za<100 ){
            Sieie_za = photon_sieie_za[iPhoton12_za];
                            h_mc_za->Fill(Sieie_za,weight_za);
                temp_mcza->Fill();
                temp_mcza->SetWeight(-1*weight_za);
        }
    }
    temp_mcza->Write();

    std::cout<<"numevents_za = "<<h_mc_za->GetSumOfWeights()<<std::endl;
    std::cout<<"temp_za OK"<<std::endl;
    
   
//>>>>>>>>>>>>>>>>>>>>>>>>ZA Data for Fake>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    std::cout<<"Begin temp_fkp"<<std::endl;
    
    
    Float_t  Sieie_fkp; // pointer to the leading photon
    Long64_t nentries_fkp = t4->GetEntries();
    TFile* newfile1 = new TFile(Form("newtree1_%0.f_%0.f.root",lowpt,highpt),"recreate");
    TTree* temp_fkp = new TTree("temp_fkp","temp_fkp");
    temp_fkp->Branch("sieie",&Sieie_fkp);
    std::cout<<"nentries = "<<nentries_fkp<<std::endl;
    TH1F* hfkp = new TH1F("hfkp","hfkp",10,0.005,0.02);
    
    
      for(int i=0;i<nentries_fkp;i++)
   // for(int i=0;i<1000;i++)
    {
        t4->GetEntry(i);
        Int_t iPhoton12_tf = 0;
        Int_t pass2 = 1;
        Int_t disc2 = 0;
        if(i%1000000==0) std::cout << "Entry num " << i << std::endl;
        for(Int_t iPhoton=0;iPhoton<6;iPhoton++){
                if(photon_pev_tf[iPhoton]==1 &&
                   photon_hoe_tf[iPhoton]<0.05 && photon_chiso_tf[iPhoton] <0.76 &&
                   photon_nhiso_tf[iPhoton]<(0.97 + 0.014*photon_pt_tf[iPhoton] + 0.000019*photon_pt_tf[iPhoton]*photon_pt_tf[iPhoton]) &&
                   photon_phoiso_tf[iPhoton]<(0.08 + 0.0053*photon_pt_tf[iPhoton]) &&
                   TMath::Abs(photon_eta_tf[iPhoton])<1.4442 &&
                   photon_pt_tf[iPhoton]>lowpt && photon_pt_tf[iPhoton]<highpt){
                if(iPhoton12_tf==0 && iPhoton==0)
                {
                    disc2++;
                    pass2++;
                }
                if(iPhoton12_tf==0 && pass2==0 && iPhoton>0)
                {
                    iPhoton12_tf = iPhoton;
                    disc2++;
                }
                if(pass2>0 && photon_pt_tf[iPhoton]>photon_pt_tf[iPhoton12_tf])
                {
                    iPhoton12_tf = iPhoton;
                    disc2++;
                }
                if(iPhoton12_tf>0 && pass2==0 && photon_pt_tf[iPhoton]>photon_pt_tf[iPhoton12_tf])
                {
                    iPhoton12_tf = iPhoton;
                    disc2++;
                }
            }
        }
        if(disc2>0 &&
           photon_drla_tf[iPhoton12_tf]>1 && photon_drla2_tf[iPhoton12_tf]>1 &&
           photon_drla_tf[iPhoton12_tf]<10 && photon_drla2_tf[iPhoton12_tf]<10 &&
           massVlep_tf>80 && massVlep_tf<100 ){
            Sieie_fkp = photon_sieie_tf[iPhoton12_tf];
            hfkp->Fill(Sieie_fkp);
            temp_fkp->Fill();
        }
    }
    temp_fkp->Write();
    std::cout<<"numevents_fkp = "<<hfkp->GetSumOfWeights()<<std::endl;
    std::cout<<"temp_fkp OK"<<std::endl;
   
    //>>>>>>>>>>>>>>>>>DY FaketoTrue>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
     std::cout<<"Begin temp_dy"<<std::endl;

    Double_t Sieie_dy,weight_dy; // pointer to the leading photon
    Long64_t nentries_dy = t2->GetEntries();
    std::cout<<"nentries = "<<nentries_dy<<std::endl;
    TFile* newfile2 = new TFile(Form("newtree2_%0.f_%0.f.root",lowpt,highpt),"recreate");
    TTree* temp_mcdy = new TTree("temp_mcdy","temp_mcdy");
    temp_mcdy->Branch("sieie",&Sieie_dy);
    TH1F* h_mc_dy = new TH1F("hmc_dy","hmc_dy",10,0.005,0.02);
    Int_t numevents_dy = 0;
    
    
    //for(int i=0;i<nentries_dy;i++)
          for(int i=0;i<10;i++)
    {
        t2->GetEntry(i);
        Int_t iPhoton12_dy = 0;
        Int_t pass3 = 1;
        Int_t disc3 = 0;
        if(i%1000000==0) std::cout << "Entry num " << i << std::endl;
        for(Int_t iPhoton=0;iPhoton<6;iPhoton++){
                if(photon_pev_dy[iPhoton]==1 &&
                   photon_hoe_dy[iPhoton]<0.05 &&
                   photon_chiso_dy[iPhoton]<0.76 &&
                   photon_nhiso_dy[iPhoton]<(0.97 + 0.014*photon_pt_dy[iPhoton] + 0.000019*photon_pt_dy[iPhoton]*photon_pt_dy[iPhoton]) &&
                   photon_phoiso_dy[iPhoton]<(0.08 + 0.0053*photon_pt_dy[iPhoton]) &&
                   TMath::Abs(photon_eta_dy[iPhoton])<1.4442 &&
                   photon_isprompt_dy[iPhoton]==0 &&
                   //   photon_pt_dy[iPhoton]>lowpt && photon_pt_dy[iPhoton]<highpt){
                      photon_pt_dy[iPhoton]>10){
                if(iPhoton12_dy==0 && iPhoton==0)
                {
                    disc3++;
                    pass3++;
                }
                if(iPhoton12_dy==0 && pass3==0 && iPhoton>0)
                {
                    iPhoton12_dy = iPhoton;
                    disc3++;
                }
                if(pass3>0 && photon_pt_dy[iPhoton]>photon_pt_dy[iPhoton12_dy])
                {
                    iPhoton12_dy = iPhoton;
                    disc3++;
                }
                if(iPhoton12_dy>0 && pass3==0 && photon_pt_dy[iPhoton]>photon_pt_dy[iPhoton12_dy])
                {
                    iPhoton12_dy = iPhoton;
                    disc3++;
                }
            }
        }

        TLorentzVector leptonV,PhotonS;
        leptonV.SetPtEtaPhiE(ptVlep_dy,yVlep_dy,phiVlep_dy,massVlep_dy);
        PhotonS.SetPtEtaPhiE(photon_pt_dy[iPhoton12_dy],photon_eta_dy[iPhoton12_dy],photon_phi_dy[iPhoton12_dy],photon_e_dy[iPhoton12_dy]);
        mlla_dy= (leptonV+PhotonS).M();

        if(disc3>0 &&
           photon_drla_dy[iPhoton12_dy]>0.4 && photon_drla2_dy[iPhoton12_dy]>0.4 &&
           TMath::Min(photon_drla_dy[iPhoton12_dy],photon_drla2_dy[iPhoton12_dy])<1 &&
           massVlep_dy<80 &&
           mlla_dy>81 && mlla_dy<101){
            Sieie_dy = photon_sieie_dy[iPhoton12_dy];
            weight_dy = pileupWeight_dy*lumiWeight_dy*triggerWeight_dy*scalef_dy*0.553;
            h_mc_dy->Fill(Sieie_dy,weight_dy);
            temp_mcdy->Fill();
            temp_mcdy->SetWeight(-1*weight_dy);
           // numevents_dy++;
        }
    }
    temp_mcdy->Write();
    std::cout<<"numevents_dy = "<<h_mc_dy->GetSumOfWeights()<<std::endl;
    std::cout<<"temp_dy OK"<<std::endl;
    

//>>>>>>>>>>>>>>>ZA Data for True>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    std::cout<<"<<<<<<<<<<<<<<<<<Begin temp_true<<<<<<<<<<<<<<<<"<<std::endl;
    Float_t Sieie_true; // pointer to the leading photon
    Long64_t nentries_true = t4->GetEntries();
    std::cout<<"nentries = "<<nentries_true<<std::endl;
    TFile* newfile3 = new TFile(Form("newtree3_%0.f_%0.f.root",lowpt,highpt),"recreate");
    TTree* temp_true = new TTree("temp_true","temp_true");
    temp_true->Branch("sieie",&Sieie_true);
    TH1F* htrue = new TH1F("htrue","htrue",10,0.005,0.02);
    TH1F* htrue_sieie = new TH1F("htrue_sieie","htrue_sieie",10,0.005,0.02);
    
    Int_t numevents_true = 0;
    Int_t numevents_sieie = 0;
     for(int i=0;i<nentries_true;i++)
   //  for(int i=0;i<1000;i++)
    {
                t4->GetEntry(i);
				Int_t iPhoton12_true = 0;
				Int_t pass4 = 0;
				Int_t disc4 = 0;
			    Sieie_true = -1;
        if(i%1000000==0) std::cout << "Entry num " << i << std::endl;

				for(Int_t iPhoton=0;iPhoton<6;iPhoton++){
              if(photon_pev_tf[iPhoton]==1 &&
                 photon_hoe_tf[iPhoton]<0.05 &&
                 photon_chiso_tf[iPhoton]<0.76 &&
                 photon_nhiso_tf[iPhoton]<(0.97 + 0.014*photon_pt_tf[iPhoton] + 0.000019*photon_pt_tf[iPhoton]*photon_pt_tf[iPhoton]) &&
                 photon_phoiso_tf[iPhoton]<(0.08 + 0.0053*photon_pt_tf[iPhoton]) &&
                 TMath::Abs(photon_eta_tf[iPhoton])<1.4442 &&
                // photon_pt_tf[iPhoton]>lowpt && photon_pt_tf[iPhoton]<highpt){
                  photon_pt_tf[iPhoton]>10){
						if(iPhoton12_true==0 && iPhoton==0)
						  {
                                disc4++;
								pass4++;
						  }
						if(iPhoton12_true==0 && pass4==0 && iPhoton>0)
						  {
								iPhoton12_true = iPhoton;
								disc4++;
						  }
						if(pass4>0 && photon_pt_tf[iPhoton]>photon_pt_tf[iPhoton12_true])
						  {
								iPhoton12_true = iPhoton;
								disc4++;
							}
						if(iPhoton12_true>0 && pass4==0 && photon_pt_tf[iPhoton]>photon_pt_tf[iPhoton12_true])
						  {
								iPhoton12_true = iPhoton;
								disc4++;
							}
					}
				}
        
        TLorentzVector leptonV,PhotonS;
        leptonV.SetPtEtaPhiE(ptVlep_tf,yVlep_tf,phiVlep_tf,massVlep_tf);
        PhotonS.SetPtEtaPhiE(photon_pt_tf[iPhoton12_true],photon_eta_tf[iPhoton12_true],photon_phi_tf[iPhoton12_true],photon_e_tf[iPhoton12_true]);
        mlla_tf= (leptonV+PhotonS).M();
        
            if(disc4>0 &&
               photon_drla_tf[iPhoton12_true]>0.4 && photon_drla2_tf[iPhoton12_true]>0.4 &&
               TMath::Min(photon_drla_tf[iPhoton12_true],photon_drla2_tf[iPhoton12_true])<1 &&
               massVlep_tf<80 &&
               mlla_tf>81 && mlla_tf<101){
					Sieie_true = photon_sieie_tf[iPhoton12_true];
                    htrue->Fill(Sieie_true);
                temp_true->Fill();

                if(Sieie_true<0.0102){
                    htrue_sieie->Fill(Sieie_true);
                }
				}
        
    }
    temp_true->Write();
    std::cout<<"numevents_true = "<<htrue->GetSumOfWeights()<<std::endl;
    std::cout<<"numevents_sieie = "<<htrue_sieie->GetSumOfWeights()<<std::endl;
    std::cout<<"temp_true OK"<<std::endl;

//>>>>>>>>>>>>>>>>>>ZA Data>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    std::cout<<"Begin temp_data"<<std::endl;
    Float_t Sieie_data; // pointer to the leading photon
    Long64_t nentries_data = t4->GetEntries();
    std::cout<<"nentries = "<<nentries_data<<std::endl;
    TFile* newfile4 = new TFile(Form("newtree4_%0.f_%0.f.root",lowpt,highpt),"recreate");
    TTree* temp_data = new TTree("temp_data","temp_data");
    temp_data->Branch("sieie",&Sieie_data);
    TH1F* hdata = new TH1F("hdata","hdata",10,0.005,0.02);

    Int_t numevents_data = 0;
    
    for(int i=0;i<nentries_data;i++)
  //      for(int i=0;i<1000000;i++)
    {
                t4->GetEntry(i);
				Int_t iPhoton12_data = 0;
				Int_t disc5 = 0;
				Int_t pass5 = 0;
        if(i%1000000==0) std::cout << "Entry num " << i << std::endl;

				for(Int_t iPhoton=0;iPhoton<6;iPhoton++){
                    if(photon_pev_tf[iPhoton]==1 &&
                       photon_hoe_tf[iPhoton]<0.05 &&
                       photon_chiso_tf[iPhoton]<0.76 &&
                       photon_nhiso_tf[iPhoton]<(0.97 + 0.014*photon_pt_tf[iPhoton] + 0.000019*photon_pt_tf[iPhoton]*photon_pt_tf[iPhoton]) &&
                       photon_phoiso_tf[iPhoton]<(0.08 + 0.0053*photon_pt_tf[iPhoton]) &&
                       TMath::Abs(photon_eta_tf[iPhoton])<1.4442 &&
                       photon_pt_tf[iPhoton]>lowpt && photon_pt_tf[iPhoton]<highpt){
						if(iPhoton12_data==0 && iPhoton==0)
						  {
                                disc5++;
								pass5++;
						  }
						if(iPhoton12_data==0 && pass5==0 && iPhoton>0)
						  {
								iPhoton12_data = iPhoton;
								disc5++;
						  }
						if(pass5>0 && photon_pt_tf[iPhoton]>photon_pt_tf[iPhoton12_data])
						  {
								iPhoton12_data = iPhoton;
								disc5++;
							}
						if(iPhoton12_data>0 && pass5==0 && photon_pt_tf[iPhoton]>photon_pt_tf[iPhoton12_data])
						  {
								iPhoton12_data = iPhoton;
								disc5++;
							}
					}
				}

      //  if(disc5>0 ){
        if(disc5>0 && photon_drla_tf[iPhoton12_data]>0.4 && photon_drla2_tf[iPhoton12_data]>0.4){
					Sieie_data = photon_sieie_tf[iPhoton12_data];
                  hdata->Fill(Sieie_data);
                        temp_data->Fill();
				}
    }
    temp_data->Write();
    std::cout<<"numevents_data = "<<hdata->GetSumOfWeights()<<std::endl;
    std::cout<<"temp_data OK"<<std::endl;
    
    //>>>>>>>>>>>>>>>>>>WA MC>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    std::cout<<"Begin temp_wa"<<std::endl;
    Float_t Sieie_wa; // pointer to the leading photon
    Long64_t nentries_wa = t1->GetEntries();
    std::cout<<"nentries = "<<nentries_wa<<std::endl;
    TFile* newfile5 = new TFile(Form("newtree5_%0.f_%0.f.root",lowpt,highpt), "RECREATE");
    TTree* temp_mcwa = new TTree("temp_mcwa","temp_mcwa");
    temp_mcwa->Branch("sieie",&Sieie_wa);
    
    TH1F* h_mc_wa = new TH1F("hmc_wa","hmc_wa",10,0.005,0.02);
    
    Int_t numevents_wa = 0;
    
    for(int i=0;i<nentries_wa;i++)
  //             for(int i=0;i<1000;i++)
    {
        t1->GetEntry(i);
        Int_t iPhoton12_wa = 0;
        Int_t disc5 = 0;
        Int_t pass5 = 0;
        if(i%1000000==0) std::cout << "Entry num " << i << std::endl;
        
        for(Int_t iPhoton=0;iPhoton<6;iPhoton++){
            if(photon_pev_za[iPhoton]==1 &&
               photon_hoe_za[iPhoton]<0.05 &&
               photon_chiso_za[iPhoton]<0.76 &&
               photon_nhiso_za[iPhoton]<(0.97 + 0.014*photon_pt_za[iPhoton] + 0.000019*photon_pt_za[iPhoton]*photon_pt_za[iPhoton]) &&
               photon_phoiso_za[iPhoton]<(0.08 + 0.0053*photon_pt_za[iPhoton]) &&
               TMath::Abs(photon_eta_za[iPhoton])<1.4442 &&
               photon_pt_za[iPhoton]>lowpt && photon_pt_za[iPhoton]<highpt){
                if(iPhoton12_wa==0 && iPhoton==0)
                {
                    disc5++;
                    pass5++;
                }
                if(iPhoton12_wa==0 && pass5==0 && iPhoton>0)
                {
                    iPhoton12_wa = iPhoton;
                    disc5++;
                }
                if(pass5>0 && photon_pt_za[iPhoton]>photon_pt_za[iPhoton12_wa])
                {
                    iPhoton12_wa = iPhoton;
                    disc5++;
                }
                if(iPhoton12_wa>0 && pass5==0 && photon_pt_za[iPhoton]>photon_pt_za[iPhoton12_wa])
                {
                    iPhoton12_wa = iPhoton;
                    disc5++;
                }
            }
        }
       
      //  if(disc5>0 && photon_drla_za[iPhoton12_wa]>0.4){
        if(disc5>0 && photon_drla_za[iPhoton12_data]>0.4 && photon_drla2_za[iPhoton12_data]>0.4){

            Double_t weight_wa = pileupWeight_za*lumiWeight_za*triggerWeight_za*scalef_za*0.553;
            Sieie_wa = photon_sieie_za[iPhoton12_wa];
            h_mc_wa->Fill(Sieie_wa,weight_wa);
            temp_mcwa->Fill();
            temp_mcwa->SetWeight();
        }
    }
    temp_mcwa->Write();
    std::cout<<"numevents_wa = "<<h_mc_wa->GetSumOfWeights()<<std::endl;
    std::cout<<"temp_wa OK"<<std::endl;
    
   // TFile fdata("mu_hist.root", "RECREATE");
    fdata.cd();
    h_mc_za->Write();
    h_mc_dy->Write();
    h_mc_wa->Write();
    htrue->Write();
    htrue_sieie->Write();
    hfkp->Write();
    hdata->Write();
  //  fdata.Close();
}



void RootFit(float lowpt,float highpt){
    TFile* f1 = TFile::Open(Form("mu_hist_%0.f_%0.f.root",lowpt,highpt));
    TH1F* h_mc_za = (TH1F *)f1->Get("hmc_za");
    TH1F* h_mc_dy = (TH1F *)f1->Get("hmc_dy");
    TH1F* h_mc_wa = (TH1F *)f1->Get("hmc_wa");
    TH1F* htrue = (TH1F *)f1->Get("htrue");
    TH1F* htrue_sieie = (TH1F *)f1->Get("htrue_sieie");
    TH1F* hfkp = (TH1F *)f1->Get("hfkp");
    TH1F* hdata = (TH1F *)f1->Get("hdata");

    
    //minus FaketoTrue and TruetoFake
    hfkp->Add(h_mc_za,-1);
    htrue->Add(h_mc_dy,-1);
    Double_t nFake = hfkp->Integral();
    Double_t nTrue = htrue->Integral();

    Double_t nBins = hfkp->GetNbinsX();
    Double_t nMax = hdata->GetSumOfWeights();
    Double_t nTrueStart = h_mc_wa->GetSumOfWeights();
    Double_t nFakeStart = nMax - nTrueStart;
    std::cout<<"nMax = "<<nMax<<" nTrueStart = "<<nTrueStart<<" nFakeStart = "<<nFakeStart<<std::endl;
    
    Double_t eff = htrue_sieie->GetSumOfWeights()/htrue->GetSumOfWeights();
     stds::cout<<"eff"<<htrue_sieie->GetSumOfWeights()<<" "<<htrue->GetSumOfWeights()<<" "<<std::endl;

    hfkp->Scale(nFakeStart/nFake);
    htrue->Scale(nTrueStart/nTrue);
    
    TObjArray *mc = new TObjArray(2);        // MC histograms are put in this array
    mc->Add(hfkp);
    mc->Add(htrue);
    TFractionFitter* fit = new TFractionFitter(hdata, mc); // initialise
  //  fit->Constrain(1,nTrueStart-100,nTrueStart+100);               // constrain fraction 1 to be between 0 and 1
   // fit->Constrain(2,nFakeStart-100,nFakeStart+100);               // constrain fraction 1 to be between 0 and 1
    fit->Constrain(1,0,1);
    fit->Constrain(2,0,1);
    fit->SetRangeX(1,nBins);                    // use only the first 15 bins in the fit
    Int_t status = fit->Fit();               // perform the fit
    std::cout << "fit status: " << status << std::endl;
    if (status == 0) {                       // check on fit status
        TH1F* result = (TH1F*) fit->GetPlot();
        TCanvas *c1 = new TCanvas("c1","c1",600,600);
        gPad->SetLogy();
        hdata->SetMarkerColor(1);
        hdata->SetLineColor(1);
        hdata->SetMarkerStyle(20);
        result->SetLineColor(kRed);
        hdata->Draw("Ep");
        result->Draw("same");
        mcp0 = (TH1F*)fit->GetMCPrediction(0);
		mcp0->SetLineColor(kBlue);
        mcp0->SetLineStyle(9);
		mcp1 = (TH1F*)fit->GetMCPrediction(1);
		mcp1->SetLineColor(kGreen);
        mcp1->SetLineStyle(9);
        
        mcp0->Draw("sameE");
		mcp1->Draw("sameE");
        
        c1->Print(Form("root_fit_%0.f_%0.fEB.png",lowpt,highpt));
        gPad->SetLogy(0);
        c1->Print(Form("notlog_root_fit_%0.f_%0.fEB.png",lowpt,highpt));

        Double_t chi2 = fit->GetChisquare()/8;
        std::cout<<"chi2"<<chi2<<std::endl;
        Double_t fakeError, trueError, dataError, dataActualError,fakeActualError;
        
       // stds::cout<<"eff"<<htrue_sieie->GetSumOfWeights()<<" "<<htrue->GetSumOfWeights()<<" "<<std::endl;
        Double_t trueValue = mcp1->IntegralAndError(1,5,trueError);
        
        Double_t dataValue = result->IntegralAndError(1,nBins,dataError);
        Double_t dataActualValue  = hdata->IntegralAndError(1,5,dataError);
        Double_t fakeValue = dataActualValue-trueValue;
        Double_t fakeActualValue = mcp0->IntegralAndError(1,5,fakeActualError);

        fakeError = sqrt(dataError * dataError + trueError * trueError);
        Double_t rate = fakeValue/hdata->Integral(1,5);
        Double_t rateError = fakeError/dataActualValue+fakeValue*dataActualError/(dataActualValue*dataActualValue);
        Double_t p0, p1, errP0, errP1;
        fit->GetResult( 0, p0, errP0);
		printf(" Parameter %d: true, estim. %.3f +/- %.3f\n", 0, p0, errP0);
        fit->GetResult( 1, p1, errP1);
		printf(" Parameter %d: true , estim. %.3f +/- %.3f\n", 1, p1, errP1);
        
        ofstream myfile(TString("root_rate_")+Form("photon_pt%0.f_%0.f.txt",lowpt,highpt),ios::out);
        
        myfile <<"Fake Yields"<<fakeValue<<"+-"<<fakeActualValue<<"  "<<"  "<<fakeError<<fakeActualError<<endl;
        myfile <<"Ture yields"<<trueValue<<"+-"<<trueError<<endl;
        myfile <<"Data yields"<<dataActualValue<<"+-"<<dataActualValue<<endl;
        myfile <<"Fake Rate"<<rate<<"+-"<<rateError<<endl;
        
        
        myfile.close();
        
    }
}
    void RooFit(float lowpt,float highpt){
    
    TFile* f1 = TFile::Open(Form("mu_hist_%0.f_%0.f.root",lowpt,highpt));
    TH1F* h_mc_za = (TH1F *)f1->Get("hmc_za");
    TH1F* h_mc_dy = (TH1F *)f1->Get("hmc_dy");
    TH1F* h_mc_wa = (TH1F *)f1->Get("hmc_wa");
    TH1F* htrue = (TH1F *)f1->Get("htrue");
    TH1F* htrue_sieie = (TH1F *)f1->Get("htrue_sieie");
    TH1F* hfkp = (TH1F *)f1->Get("hfkp");
    TH1F* hdata = (TH1F *)f1->Get("hdata");
 
    TFile *f0 = new TFile(Form("newtree0_%0.f_%0.f.root",lowpt,highpt));
    TTree *temp_mcza = (TTree*)f0->Get("temp_mcza");
    TFile *f1 = new TFile(Form("newtree1_%0.f_%0.f.root",lowpt,highpt));
    TTree *temp_fkp = (TTree*)f1->Get("temp_fkp");
    TFile *f2 = new TFile(Form("newtree2_%0.f_%0.f.root",lowpt,highpt));
    TTree *temp_mcdy = (TTree*)f2->Get("temp_mcdy");
    TFile *f3 = new TFile(Form("newtree3_%0.f_%0.f.root",lowpt,highpt));
    TTree *temp_true = (TTree*)f3->Get("temp_true");
    TFile *f4 = new TFile(Form("newtree4_%0.f_%0.f.root",lowpt,highpt));
    TTree *temp_data = (TTree*)f4->Get("temp_data");
    TFile *f5 = new TFile(Form("newtree5_%0.f_%0.f.root",lowpt,highpt));
    TTree *temp_mcwa = (TTree*)f5->Get("temp_mcwa");
//>>>>>>>>>>>>>>>>>>>Fit>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    
       double varMin=0;
       double varMax=0;
       int nBins=0;
    
       //minus FaketoTrue and TruetoFake
       hfkp->Add(h_mc_za,-1);
       htrue->Add(h_mc_dy,-1);
    
       nBins = hfkp->GetNbinsX();
       varMin = hfkp->GetBinLowEdge(1);
       varMax = hfkp->GetBinLowEdge(nBins)+hfkp->GetBinWidth(nBins);
    
        Double_t nMax = hdata->GetSumOfWeights();
     Double_t nTrueStart = h_mc_wa->GetSumOfWeights();
    //Double_t nTrueStart = 717.401;
        Double_t nFakeStart = nMax - nTrueStart;
        std::cout<<"nMax = "<<nMax<<" nTrueStart = "<<nTrueStart<<" nFakeStart = "<<nFakeStart<<std::endl;
    
        RooRealVar sieie("sieie","sieie",0.005, 0.02);
        RooArgList argList;
        argList.add(sieie);
        RooArgSet argSet;
        argSet.add(sieie);
    

        RooDataHist dataHist("hist", "data set converted to hist", argList, hdata);
        RooDataSet* dataTree = new RooDataSet("dataTree","dataTree",temp_data,sieie);

    
//    RooDataSet* trueDataTree = new RooDataSet("trueDataTree","trueDataTree",temp_true,sieie);
//  //  trueDataPdf.fitTo(*trueDataTree,NumCPU(2));
//    RooDataSet* trueMCTree = new RooDataSet("trueMCTree","trueMCTree",temp_mcdy,sieie);
//    RooKeysPdf trueDataPdf("trueDataPdf","trueDataPdf",sieie,*trueDataTree,RooKeysPdf::MirrorBoth);
//    RooKeysPdf trueMCPdf("trueMCPdf","trueMCPdf",sieie,*trueMCTree,RooKeysPdf::MirrorBoth);
//    RooRealVar plus("plus","plus",1,0.9999999999,1.00000000001);
//    RooAddPdf  truePdf("truePdf","truePdf",RooArgList(trueDataPdf,trueMCPdf),RooArgList(plus,plus));

   
     RooDataHist trueDataHist("trueDataHist","true RooDataHist", argList, htrue);
     RooHistPdf trueHistPdf("trueHistPdf","trueHistPdf", argSet, trueDataHist);
  
//    RooDataSet* fakeDataTree = new RooDataSet("fakeDataTree","fakeDataTree",temp_fkp,sieie);
//    RooDataSet* fakeMCTree = new RooDataSet("fakeMCTree","fakeMCTree",temp_mcza,sieie);
//    RooKeysPdf fakeDataPdf("fakeDataPdf","fakeDataPdf",sieie,*fakeDataTree,RooKeysPdf::MirrorBoth);
//    RooKeysPdf fakeMCPdf("fakeMCPdf","fakeMCPdf",sieie,*fakeMCTree,RooKeysPdf::MirrorBoth);
//    RooAddPdf  fakePdf("fakePdf","fakePdf",RooArgList(fakeDataPdf,fakeMCPdf),RooArgList(plus,plus));
    
      RooDataHist fakeDataHist("fakeDataHist", "fake RooDataHist", argList, hfkp);
      RooHistPdf fakeHistPdf("fakeHistPdf","fakeHistPdf", argSet, fakeDataHist);

   //    RooRealVar rooNTrue("nTrue","n True",nTrueStart,0,nMax);//0.2*nMax,*nMax);//1931.46
     //  RooRealVar rooNFake("nFake","n Fake",nFakeStart,0*nMax,nMax);//0.5*nMax,1*nMax);//7622.54
    
        RooRealVar rooNTrue("nTrue","n True",500,0,1000);//0.2*nMax,*nMax);//1931.46
       RooRealVar rooNFake("nFake","n Fake",300,0*nMax,600);//0.5*nMax,1*nMax);//7622.54
    
       RooAddPdf fullPdf("fitModel","fit model",RooArgList(trueHistPdf,fakeHistPdf),RooArgList(rooNTrue,rooNFake));
        std::cout<<"fullPdf.getNorm()="<<fullPdf.getNorm()<<std::endl;
        std::cout<<"dataHist.sumEntries()="<<dataHist.sumEntries()<<std::endl;
    
        //fit
        fullPdf.fitTo(dataHist,SumW2Error(kFALSE),Extended(kTRUE));
   // fullPdf.fitTo(*dataTree,NumCPU(2));
        //calc chi squared
        RooChi2Var chi2("chi2","chi2",fullPdf,dataHist);
        Double_t chi2ToNDF = chi2.getVal()/(nBins-2);
    
//>>>>>>>>>>>>>>>>>>>Get Value>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
    //get nFake values from fit
    Double_t nFakeFromFitVal = rooNFake.getVal();
    Double_t nFakeFromFitErr = rooNFake.getError();
    
    Double_t nTrueFromFitVal = rooNTrue.getVal();
    Double_t nTrueFromFitErr = rooNTrue.getError();
    
    // add eff for true and fake
   // Double_t eff = eff=hTruePassed->GetBinContent(1)/hTrueTot->GetBinContent(1);
    Double_t eff = htrue_sieie->GetSumOfWeights()/htrue->GetSumOfWeights();
    //std::cout<<htrue_sieie->GetSumOfWeights()<<" "<<htrue->GetSumOfWeights()<<" "<<"eff = "<<eff<<std::endl;
   // Double_t eff = 45./46.;
    Double_t nTrueYieldsVal = nTrueFromFitVal * eff;
  //  std::cout<<"nTrueFromFitVal = "<<nTrueFromFitVal<<" "<<eff<<std::endl;
    Double_t nTrueYieldsErr = nTrueFromFitErr * eff;
    
    Double_t nDataFullSelErr=0;
    Double_t nFakeYieldsVal = hdata->IntegralAndError(1,nBins,nDataFullSelErr) - nTrueYieldsVal;
    Double_t nFakeYieldsErr = sqrt(nDataFullSelErr * nDataFullSelErr + nTrueYieldsErr * nTrueYieldsErr);
  //  std::cout<<"nDataFullSelErr = "<<nDataFullSelErr<<std::endl;
    
    double FakeRateVal = nFakeYieldsVal/nMax;
    double FakeRateErr = nFakeYieldsErr/nMax+nFakeYieldsVal*nDataFullSelErr/(nMax*nMax);
    std::cout<<"FakeRateErr = "<<FakeRateErr<<std::endl;

    
    //OutPut file
    RooArgSet *params = (RooArgSet*)fullPdf.getParameters(*dataTree) ;
    params->Print("v") ;
    params->writeToFile(TString("parms_")+Form("photon_pt%0.f_%0.f.txt",lowpt,highpt)) ;
    
    ofstream myfile(TString("rate_")+Form("photon_pt%0.f_%0.f.txt",lowpt,highpt),ios::out);
    
    myfile <<"Fake fit"<<nFakeFromFitVal<<"+-"<<nFakeFromFitErr<<endl;
    myfile <<"True fit"<<nTrueFromFitVal<<"+-"<<nTrueFromFitErr<<endl;
    myfile <<"chi2/ndf="<<chi2ToNDF<<endl;
    myfile <<"Fake Yields"<<nFakeYieldsVal<<"+-"<<nFakeYieldsErr<<endl;
    myfile <<"Ture yields"<<nTrueYieldsVal<<"+-"<<nTrueYieldsErr<<endl;
    myfile <<"Data yields"<<nMax<<"+-"<<nDataFullSelErr<<endl;
    myfile <<"Fake Rate"<<FakeRateVal<<"+-"<<FakeRateErr<<endl;

    
    myfile.close();
    

//>>>>>>>>>>>>>>>>>>>Plots>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
       //plot
       RooPlot* xframe = sieie.frame(Title(Form("Barrel region, %0.f GeV < photon PT < %0.f GeV ",lowpt,highpt)),Bins(10));
       dataTree.plotOn(xframe);
       fullPdf.plotOn(xframe,Name("sum"),LineColor(kRed));
       fullPdf.plotOn(xframe,Components("trueHistPdf"), Name("true"),LineColor(kGreen),LineStyle(9));
       fullPdf.plotOn(xframe, Components("fakeHistPdf"),Name("fake"),LineColor(kBlue),LineStyle(9));
       fullPdf.paramOn(xframe);
    
       TCanvas *c1 = new TCanvas("c1","c1",600,600);
       xframe->GetXaxis()->SetTitle("#sigma_{i#etai#eta}") ;
       xframe->GetYaxis()->SetTitleOffset(1.4) ;
       xframe->Draw();
       gPad->SetLogy(0);
    
       hdata->SetLineColor(kRed);
     //  hdata->SetLineStyle(2);
       hdata->SetLineWidth(3);
    
       hfkp->SetLineColor(kBlue);
       hfkp->SetLineStyle(5);
       hfkp->SetLineWidth(3);
    
       htrue->SetLineColor(kGreen+2);
       htrue->SetLineStyle(kDashed);
       htrue->SetLineWidth(3);
    
    TLegend *leg = new TLegend(0.55,0.6659582,0.88,0.850488,NULL,"brNDC");
    leg->SetFillColor(10);
    leg->AddEntry(hdata,"WA Data","L");
    leg->AddEntry(htrue,"Ture photons","L");
    leg->AddEntry(hfkp,"Fake photons","L");
    leg->Draw("same");
    c1->Print(Form("notlog_tempfit_%0.f_%0.fEB.png",lowpt,highpt));

    
    gPad->SetLogy();
    c1->Print(Form("tempfit_%0.f_%0.fEB.png",lowpt,highpt));

    std::cout<<"chi2/ndf="<<chi2ToNDF<<std::endl;


    
    f1->Close();

}
