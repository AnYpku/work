#include "RooAddPdf.h"
#include "RooChi2Var.h"
#include "RooDataHist.h"
#include "RooExtendPdf.h"
#include "RooFitResult.h"
#include "RooHistPdf.h"
#include "RooPlot.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TFitResultPtr.h"
#include "TH1.h"
#include "TH2.h"
#include "TLegend.h"
#include "TLorentzVector.h"
#include "TMatrixDSym.h"
#include "TNtupleD.h"
#include "TStyle.h"
#include "TTree.h"
#include <TLatex.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
    TFile* input1   = new TFile("outWAJJ.root");
    TTree* Outtree1 = (TTree*)input1->Get("demo");

    int nentries1 = (int)Outtree1->GetEntries();

    Double_t Mjj;
    Double_t Mjj_new;
    Double_t Mjj_JEC_up;
    Double_t Mjj_JEC_down;
    Double_t Mjj_JER_down;
    Double_t Mjj_JER_up;
    Double_t photonet;
    Double_t scalef;
    Double_t deltaeta;
    Double_t deltaeta_new;
    Double_t deltaeta_JEC_up;
    Double_t deltaeta_JEC_down;
    Double_t deltaeta_JER_up;
    Double_t deltaeta_JER_down;
    Double_t Dphiwajj;
    Double_t Dphiwajj_new;
    Double_t Dphiwajj_JEC_up;
    Double_t Dphiwajj_JEC_down;
    Double_t Dphiwajj_JER_up;
    Double_t Dphiwajj_JER_down;
    Double_t zepp;
    Double_t zepp_new;
    Double_t zepp_JEC_up;
    Double_t zepp_JEC_down;
    Double_t zepp_JER_up;
    Double_t zepp_JER_down;
    Double_t photonsceta;
    Double_t ptlep1;
    Double_t etalep1;
    Double_t jet1pt;
    Double_t jet1pt_new;
    Double_t jet1pt_JEC_up;
    Double_t jet1pt_JEC_down;
    Double_t jet1pt_JER_up;
    Double_t jet1pt_JER_down;
    Double_t jet1eta;
    Double_t jet1eta_new;
    Double_t jet1eta_JEC_up;
    Double_t jet1eta_JEC_down;
    Double_t jet1eta_JER_up;
    Double_t jet1eta_JER_down;
    Double_t jet2pt;
    Double_t jet2pt_new;
    Double_t jet2pt_JEC_up;
    Double_t jet2pt_JEC_down;
    Double_t jet2pt_JER_up;
    Double_t jet2pt_JER_down;
    Double_t jet2eta;
    Double_t jet2eta_new;
    Double_t jet2eta_JEC_up;
    Double_t jet2eta_JEC_down;
    Double_t jet2eta_JER_up;
    Double_t jet2eta_JER_down;
    Double_t drj1a;
    Double_t drj1a_new;
    Double_t drj1a_JEC_up;
    Double_t drj1a_JEC_down;
    Double_t drj1a_JER_up;
    Double_t drj1a_JER_down;
    Double_t drj2a;
    Double_t drj2a_new;
    Double_t drj2a_JEC_up;
    Double_t drj2a_JEC_down;
    Double_t drj2a_JER_up;
    Double_t drj2a_JER_down;
    Double_t drj1l;
    Double_t drj1l_new;
    Double_t drj1l_JEC_up;
    Double_t drj1l_JEC_down;
    Double_t drj1l_JER_up;
    Double_t drj1l_JER_down;
    Double_t drj2l;
    Double_t drj2l_new;
    Double_t drj2l_JEC_up;
    Double_t drj2l_JEC_down;
    Double_t drj2l_JER_up;
    Double_t drj2l_JER_down;
    Double_t j1metPhi;
    Double_t j1metPhi_new;
    Double_t j1metPhi_JEC_up;
    Double_t j1metPhi_JEC_down;
    Double_t j1metPhi_JER_up;
    Double_t j1metPhi_JER_down;
    Double_t j2metPhi;
    Double_t j2metPhi_new;
    Double_t j2metPhi_JEC_up;
    Double_t j2metPhi_JEC_down;
    Double_t j2metPhi_JER_up;
    Double_t j2metPhi_JER_down;
    Double_t Mla;
    Double_t ptVlepJEC;
    Double_t yVlepJEC;
    Double_t phiVlepJEC;
    Double_t massVlepJEC;
    Double_t mtVlepJEC;
    Double_t mtVlepJECnew;
    Double_t ptVlepJEC_new;
    Double_t yVlepJEC_new;
    Double_t phiVlepJEC_new;
    Double_t massVlepJEC_new;
    Double_t mtVlepJEC_new;
    Double_t mtVlepJECnew_new;
    Double_t ptVlepJEC_JEC_up;
    Double_t yVlepJEC_JEC_up;
    Double_t phiVlepJEC_JEC_up;
    Double_t massVlepJEC_JEC_up;
    Double_t mtVlepJEC_JEC_up;
    Double_t mtVlepJECnew_JEC_up;
    Double_t ptVlepJEC_JEC_down;
    Double_t yVlepJEC_JEC_down;
    Double_t phiVlepJEC_JEC_down;
    Double_t massVlepJEC_JEC_down;
    Double_t mtVlepJEC_JEC_down;
    Double_t mtVlepJECnew_JEC_down;
    Double_t ptVlepJEC_JER_up;
    Double_t yVlepJEC_JER_up;
    Double_t phiVlepJEC_JER_up;
    Double_t massVlepJEC_JER_up;
    Double_t mtVlepJEC_JER_up;
    Double_t mtVlepJECnew_JER_up;
    Double_t ptVlepJEC_JER_down;
    Double_t yVlepJEC_JER_down;
    Double_t phiVlepJEC_JER_down;
    Double_t massVlepJEC_JER_down;
    Double_t mtVlepJEC_JER_down;
    Double_t mtVlepJECnew_JER_down;
    Bool_t   photonhaspixelseed;
    Double_t jet1icsv;
    Double_t jet1icsv_new;
    Double_t jet1icsv_JEC_up;
    Double_t jet1icsv_JEC_down;
    Double_t jet1icsv_JER_up;
    Double_t jet1icsv_JER_down;
    Double_t jet2icsv;
    Double_t jet2icsv_new;
    Double_t jet2icsv_JEC_up;
    Double_t jet2icsv_JEC_down;
    Double_t jet2icsv_JER_up;
    Double_t jet2icsv_JER_down;
    Double_t photoneta;
    Double_t photonphi;
    Int_t    lep;
    Int_t    nlooseeles;
    Int_t    nloosemus;
    Int_t    HLT_Mu2;
    Int_t    HLT_Ele2;
    Double_t MET_et;
    Double_t MET_et_new;
    Double_t MET_et_JEC_up;
    Double_t MET_et_JEC_down;
    Double_t MET_et_JER_up;
    Double_t MET_et_JER_down;
    Double_t drla;

    Outtree1->SetBranchAddress("photoneta", &photoneta);
    Outtree1->SetBranchAddress("photonphi", &photonphi);
    Outtree1->SetBranchAddress("lep", &lep);
    Outtree1->SetBranchAddress("nlooseeles", &nlooseeles);
    Outtree1->SetBranchAddress("nloosemus", &nloosemus);
    Outtree1->SetBranchAddress("HLT_Mu2", &HLT_Mu2);
    Outtree1->SetBranchAddress("HLT_Ele2", &HLT_Ele2);
    Outtree1->SetBranchAddress("MET_et", &MET_et);
    Outtree1->SetBranchAddress("MET_et_new", &MET_et_new);
    Outtree1->SetBranchAddress("MET_et_JEC_up", &MET_et_JEC_up);
    Outtree1->SetBranchAddress("MET_et_JEC_down", &MET_et_JEC_down);
    Outtree1->SetBranchAddress("MET_et_JER_up", &MET_et_JER_up);
    Outtree1->SetBranchAddress("MET_et_JER_down", &MET_et_JER_down);
    Outtree1->SetBranchAddress("drla", &drla);

    Outtree1->SetBranchAddress("ptlep1", &ptlep1);
    Outtree1->SetBranchAddress("etalep1", &etalep1);
    Outtree1->SetBranchAddress("jet1pt", &jet1pt);
    Outtree1->SetBranchAddress("jet1pt_new", &jet1pt_new);
    Outtree1->SetBranchAddress("jet1pt_JEC_up", &jet1pt_JEC_up);
    Outtree1->SetBranchAddress("jet1pt_JEC_down", &jet1pt_JEC_down);
    Outtree1->SetBranchAddress("jet1pt_JER_up", &jet1pt_JER_up);
    Outtree1->SetBranchAddress("jet1pt_JER_down", &jet1pt_JER_down);
    Outtree1->SetBranchAddress("jet1eta", &jet1eta);
    Outtree1->SetBranchAddress("jet1eta_new", &jet1eta_new);
    Outtree1->SetBranchAddress("jet1eta_JEC_up", &jet1eta_JEC_up);
    Outtree1->SetBranchAddress("jet1eta_JEC_down", &jet1eta_JEC_down);
    Outtree1->SetBranchAddress("jet1eta_JER_up", &jet1eta_JER_up);
    Outtree1->SetBranchAddress("jet1eta_JER_down", &jet1eta_JER_down);
    Outtree1->SetBranchAddress("jet2pt", &jet2pt);
    Outtree1->SetBranchAddress("jet2pt_new", &jet2pt_new);
    Outtree1->SetBranchAddress("jet2pt_JEC_up", &jet2pt_JEC_up);
    Outtree1->SetBranchAddress("jet2pt_JEC_down", &jet2pt_JEC_down);
    Outtree1->SetBranchAddress("jet2pt_JER_up", &jet2pt_JER_up);
    Outtree1->SetBranchAddress("jet2pt_JER_down", &jet2pt_JER_down);
    Outtree1->SetBranchAddress("jet2eta", &jet2eta);
    Outtree1->SetBranchAddress("jet2eta_new", &jet2eta_new);
    Outtree1->SetBranchAddress("jet2eta_JEC_up", &jet2eta_JEC_up);
    Outtree1->SetBranchAddress("jet2eta_JEC_down", &jet2eta_JEC_down);
    Outtree1->SetBranchAddress("jet2eta_JER_up", &jet2eta_JER_up);
    Outtree1->SetBranchAddress("jet2eta_JER_down", &jet2eta_JER_down);
    Outtree1->SetBranchAddress("drj1a", &drj1a);
    Outtree1->SetBranchAddress("drj1a_new", &drj1a_new);
    Outtree1->SetBranchAddress("drj1a_JEC_up", &drj1a_JEC_up);
    Outtree1->SetBranchAddress("drj1a_JEC_down", &drj1a_JEC_down);
    Outtree1->SetBranchAddress("drj1a_JER_up", &drj1a_JER_up);
    Outtree1->SetBranchAddress("drj1a_JER_down", &drj1a_JER_down);
    Outtree1->SetBranchAddress("drj2a", &drj2a);
    Outtree1->SetBranchAddress("drj2a_new", &drj2a_new);
    Outtree1->SetBranchAddress("drj2a_JEC_up", &drj2a_JEC_up);
    Outtree1->SetBranchAddress("drj2a_JEC_down", &drj2a_JEC_down);
    Outtree1->SetBranchAddress("drj2a_JER_up", &drj2a_JER_up);
    Outtree1->SetBranchAddress("drj2a_JER_down", &drj2a_JER_down);
    Outtree1->SetBranchAddress("drj1l", &drj1l);
    Outtree1->SetBranchAddress("drj1l_new", &drj1l_new);
    Outtree1->SetBranchAddress("drj1l_JEC_up", &drj1l_JEC_up);
    Outtree1->SetBranchAddress("drj1l_JEC_down", &drj1l_JEC_down);
    Outtree1->SetBranchAddress("drj1l_JER_up", &drj1l_JER_up);
    Outtree1->SetBranchAddress("drj1l_JER_down", &drj1l_JER_down);
    Outtree1->SetBranchAddress("drj2l", &drj2l);
    Outtree1->SetBranchAddress("drj2l_new", &drj2l_new);
    Outtree1->SetBranchAddress("drj2l_JEC_up", &drj2l_JEC_up);
    Outtree1->SetBranchAddress("drj2l_JEC_down", &drj2l_JEC_down);
    Outtree1->SetBranchAddress("drj2l_JER_up", &drj2l_JER_up);
    Outtree1->SetBranchAddress("drj2l_JER_down", &drj2l_JER_down);
    Outtree1->SetBranchAddress("j1metPhi", &j1metPhi);
    Outtree1->SetBranchAddress("j1metPhi_new", &j1metPhi_new);
    Outtree1->SetBranchAddress("j1metPhi_JEC_up", &j1metPhi_JEC_up);
    Outtree1->SetBranchAddress("j1metPhi_JEC_down", &j1metPhi_JEC_down);
    Outtree1->SetBranchAddress("j1metPhi_JER_up", &j1metPhi_JER_up);
    Outtree1->SetBranchAddress("j1metPhi_JER_down", &j1metPhi_JER_down);
    Outtree1->SetBranchAddress("j2metPhi", &j2metPhi);
    Outtree1->SetBranchAddress("j2metPhi_new", &j2metPhi_new);
    Outtree1->SetBranchAddress("j2metPhi_JEC_up", &j2metPhi_JEC_up);
    Outtree1->SetBranchAddress("j2metPhi_JEC_down", &j2metPhi_JEC_down);
    Outtree1->SetBranchAddress("j2metPhi_JER_up", &j2metPhi_JER_up);
    Outtree1->SetBranchAddress("j2metPhi_JER_down", &j2metPhi_JER_down);
    Outtree1->SetBranchAddress("Mla", &Mla);
    Outtree1->SetBranchAddress("photonsceta", &photonsceta);
    Outtree1->SetBranchAddress("Dphiwajj", &Dphiwajj);
    Outtree1->SetBranchAddress("Dphiwajj_new", &Dphiwajj_new);
    Outtree1->SetBranchAddress("Dphiwajj_JEC_up", &Dphiwajj_JEC_up);
    Outtree1->SetBranchAddress("Dphiwajj_JEC_down", &Dphiwajj_JEC_down);
    Outtree1->SetBranchAddress("Dphiwajj_JER_up", &Dphiwajj_JER_up);
    Outtree1->SetBranchAddress("Dphiwajj_JER_down", &Dphiwajj_JER_down);
    Outtree1->SetBranchAddress("zepp", &zepp);
    Outtree1->SetBranchAddress("zepp_new", &zepp_new);
    Outtree1->SetBranchAddress("zepp_JEC_up", &zepp_JEC_up);
    Outtree1->SetBranchAddress("zepp_JEC_down", &zepp_JEC_down);
    Outtree1->SetBranchAddress("zepp_JER_up", &zepp_JER_up);
    Outtree1->SetBranchAddress("zepp_JER_down", &zepp_JER_down);
    Outtree1->SetBranchAddress("Mjj", &Mjj);
    Outtree1->SetBranchAddress("Mjj_new", &Mjj_new);
    Outtree1->SetBranchAddress("Mjj_JEC_up", &Mjj_JEC_up);
    Outtree1->SetBranchAddress("Mjj_JEC_down", &Mjj_JEC_down);
    Outtree1->SetBranchAddress("Mjj_JER_up", &Mjj_JER_up);
    Outtree1->SetBranchAddress("Mjj_JER_down", &Mjj_JER_down);
    Outtree1->SetBranchAddress("photonet", &photonet);
    Outtree1->SetBranchAddress("deltaeta", &deltaeta);
    Outtree1->SetBranchAddress("deltaeta_new", &deltaeta_new);
    Outtree1->SetBranchAddress("deltaeta_JEC_up", &deltaeta_JEC_up);
    Outtree1->SetBranchAddress("deltaeta_JEC_down", &deltaeta_JEC_down);
    Outtree1->SetBranchAddress("deltaeta_JER_up", &deltaeta_JER_up);
    Outtree1->SetBranchAddress("deltaeta_JER_down", &deltaeta_JER_down);
    Outtree1->SetBranchAddress("scalef", &scalef);
    Outtree1->SetBranchAddress("ptVlepJEC", &ptVlepJEC);
    Outtree1->SetBranchAddress("yVlepJEC", &yVlepJEC);
    Outtree1->SetBranchAddress("phiVlepJEC", &phiVlepJEC);
    Outtree1->SetBranchAddress("massVlepJEC", &massVlepJEC);
    //Outtree1->SetBranchAddress("mtVlepJEC", &mtVlepJEC);
    Outtree1->SetBranchAddress("mtVlepJECnew", &mtVlepJECnew);
    Outtree1->SetBranchAddress("ptVlepJEC_new", &ptVlepJEC_new);
    Outtree1->SetBranchAddress("yVlepJEC_new", &yVlepJEC_new);
    Outtree1->SetBranchAddress("phiVlepJEC_new", &phiVlepJEC_new);
    Outtree1->SetBranchAddress("massVlepJEC_new", &massVlepJEC_new);
    //Outtree1->SetBranchAddress("mtVlepJEC_new", &mtVlepJEC_new);
    Outtree1->SetBranchAddress("mtVlepJECnew_new", &mtVlepJECnew_new);
    Outtree1->SetBranchAddress("ptVlepJEC_JEC_up", &ptVlepJEC_JEC_up);
    Outtree1->SetBranchAddress("yVlepJEC_JEC_up", &yVlepJEC_JEC_up);
    Outtree1->SetBranchAddress("phiVlepJEC_JEC_up", &phiVlepJEC_JEC_up);
    Outtree1->SetBranchAddress("massVlepJEC_JEC_up", &massVlepJEC_JEC_up);
    //Outtree1->SetBranchAddress("mtVlepJEC_JEC_up", &mtVlepJEC_JEC_up);
    Outtree1->SetBranchAddress("mtVlepJECnew_JEC_up", &mtVlepJECnew_JEC_up);
    Outtree1->SetBranchAddress("ptVlepJEC_JEC_down", &ptVlepJEC_JEC_down);
    Outtree1->SetBranchAddress("yVlepJEC_JEC_down", &yVlepJEC_JEC_down);
    Outtree1->SetBranchAddress("phiVlepJEC_JEC_down", &phiVlepJEC_JEC_down);
    Outtree1->SetBranchAddress("massVlepJEC_JEC_down", &massVlepJEC_JEC_down);
    //Outtree1->SetBranchAddress("mtVlepJEC_JEC_down", &mtVlepJEC_JEC_down);
    Outtree1->SetBranchAddress("mtVlepJECnew_JEC_down", &mtVlepJECnew_JEC_down);
    Outtree1->SetBranchAddress("ptVlepJEC_JER_up", &ptVlepJEC_JER_up);
    Outtree1->SetBranchAddress("yVlepJEC_JER_up", &yVlepJEC_JER_up);
    Outtree1->SetBranchAddress("phiVlepJEC_JER_up", &phiVlepJEC_JER_up);
    Outtree1->SetBranchAddress("massVlepJEC_JER_up", &massVlepJEC_JER_up);
    //Outtree1->SetBranchAddress("mtVlepJEC_JER_up", &mtVlepJEC_JER_up);
    Outtree1->SetBranchAddress("mtVlepJECnew_JER_up", &mtVlepJECnew_JER_up);
    Outtree1->SetBranchAddress("ptVlepJEC_JER_down", &ptVlepJEC_JER_down);
    Outtree1->SetBranchAddress("yVlepJEC_JER_down", &yVlepJEC_JER_down);
    Outtree1->SetBranchAddress("phiVlepJEC_JER_down", &phiVlepJEC_JER_down);
    Outtree1->SetBranchAddress("massVlepJEC_JER_down", &massVlepJEC_JER_down);
    //Outtree1->SetBranchAddress("mtVlepJEC_JER_down", &mtVlepJEC_JER_down);
    Outtree1->SetBranchAddress("mtVlepJECnew_JER_down", &mtVlepJECnew_JER_down);
    Outtree1->SetBranchAddress("photonhaspixelseed", &photonhaspixelseed);
    Outtree1->SetBranchAddress("jet1icsv", &jet1icsv);
    Outtree1->SetBranchAddress("jet1icsv_new", &jet1icsv_new);
    Outtree1->SetBranchAddress("jet1icsv_JEC_up", &jet1icsv_JEC_up);
    Outtree1->SetBranchAddress("jet1icsv_JEC_down", &jet1icsv_JEC_down);
    Outtree1->SetBranchAddress("jet1icsv_JER_up", &jet1icsv_JER_up);
    Outtree1->SetBranchAddress("jet1icsv_JER_down", &jet1icsv_JER_down);
    Outtree1->SetBranchAddress("jet2icsv", &jet2icsv);
    Outtree1->SetBranchAddress("jet2icsv_new", &jet2icsv_new);
    Outtree1->SetBranchAddress("jet2icsv_JEC_up", &jet2icsv_JEC_up);
    Outtree1->SetBranchAddress("jet2icsv_JEC_down", &jet2icsv_JEC_down);
    Outtree1->SetBranchAddress("jet2icsv_JER_up", &jet2icsv_JER_up);
    Outtree1->SetBranchAddress("jet2icsv_JER_down", &jet2icsv_JER_down);
    TLorentzVector p4, v4;
    Double_t       WGmass;
    Double_t       binx[6] = {150, 400, 600, 800, 1000, 1500};
    //Double_t       binx[5] = {500, 800, 1200, 1700, 2000};
    //Double_t       biny[4] = {30, 80, 130, 200};
    /*
    TH2F* histo1 = new TH2F("histo1", "histo1", 4, binx, 3, biny);
    TH2F* histo2 = new TH2F("histo2", "histo2", 4, binx, 3, biny);
    TH2F* histo3 = new TH2F("histo3", "histo3", 4, binx, 3, biny);
    TH2F* histo4 = new TH2F("histo4", "histo4", 4, binx, 3, biny);
    TH2F* histo5 = new TH2F("histo5", "histo5", 4, binx, 3, biny);
    TH2F* histo6 = new TH2F("histo6", "histo6", 4, binx, 3, biny);
    */
    TH1F* histo1 = new TH1F("histo1", "histo1", 5, binx);
    TH1F* histo2 = new TH1F("histo2", "histo2", 5, binx);
    TH1F* histo3 = new TH1F("histo3", "histo3", 5, binx);
    TH1F* histo4 = new TH1F("histo4", "histo4", 5, binx);
    TH1F* histo5 = new TH1F("histo5", "histo5", 5, binx);
    TH1F* histo6 = new TH1F("histo6", "histo6", 5, binx);
    histo1->Sumw2();
    histo2->Sumw2();
    histo3->Sumw2();
    histo4->Sumw2();
    histo5->Sumw2();
    histo6->Sumw2();
    double count          = 0;
    double count_new      = 0;
    double count_JEC_up   = 0;
    double count_JEC_down = 0;
    double count_JER_up   = 0;
    double count_JER_down = 0;

    for (int j = 0; j < nentries1; j++) {
        Outtree1->GetEntry(j);
        /*
        if (Mjj > 1900)
            Mjj = 1900;
        if (Mla > 190)
            Mla = 190;
*/

        p4.SetPtEtaPhiM(photonet, photoneta, photonphi, 0);
        v4.SetPtEtaPhiM(ptVlepJEC, yVlepJEC, phiVlepJEC, massVlepJEC);
        WGmass = (p4 + v4).M();
        if (WGmass > 1500)
            WGmass = 1250;

        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && photonet > 100 && jet1pt > 40 && jet2pt > 30 && fabs(jet1eta) < 4.7 && fabs(jet2eta) < 4.7 && drj1a > 0.5 && drj2a > 0.5 && drj1l > 0.5 && drj2l > 0.5 && jet1icsv < 0.8484 && jet2icsv < 0.8484 && Mla > 30 && deltaeta > 2.5 && Mjj > 500 && mtVlepJECnew > 30 && MET_et > 30 && j1metPhi > 0.4 && j2metPhi > 0.4 && WGmass > 100;

        // electron
        bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && photonet > 100 && jet1pt > 40 && jet2pt > 30 && fabs(jet1eta) < 4.7 && fabs(jet2eta) < 4.7 && drj1a > 0.5 && drj2a > 0.5 && drj1l > 0.5 && drj2l > 0.5 && jet1icsv < 0.8484 && jet2icsv < 0.8484 && fabs(Mla - 91) > 10 && Mla > 30 && deltaeta > 2.5 && Mjj > 500 && MET_et > 30 && j1metPhi > 0.4 && j2metPhi > 0.4 && mtVlepJECnew > 30 && WGmass > 100;

        // barre : fabs(photonsceta) < 1.4442 ; endcap : fabs(photonsceta)>1.566 && fabs(photonsceta)<2.5

        // --------------------------------------------------------------------
        // control region
        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && mtVlepJECnew > 30 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && MET_et > 30 && photonet > 25 && jet1pt > 40 && jet2pt > 30 && fabs(jet1eta) < 4.7 && fabs(jet2eta) < 4.7 && drj1a > 0.5 && drj2a > 0.5 && drj1l > 0.5 && drj2l > 0.5 && j1metPhi > 0.4 && j2metPhi > 0.4 && jet1icsv < 0.8484 && jet2icsv < 0.8484 && Mjj > 200 && Mjj < 400;

        // electron
        //bool ipass = fabs(photonsceta) < 1.4442 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && mtVlepJECnew > 30 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && MET_et > 30 && photonet > 25 && jet1pt > 40 && jet2pt > 30 && fabs(jet1eta) < 4.7 && fabs(jet2eta) < 4.7 && drj1a > 0.5 && drj2a > 0.5 && drj1l > 0.5 && drj2l > 0.5 && j1metPhi > 0.4 && j2metPhi > 0.4 && jet1icsv < 0.8484 && jet2icsv < 0.8484 && fabs(Mla - 91) > 10 && Mjj > 200 && Mjj < 400;

        double lumi = 35.857;

        if (ipass) {
            count += scalef * lumi;
            histo1->Fill(WGmass, lumi * scalef);
        }
    }

    for (int j = 0; j < nentries1; j++) {
        Outtree1->GetEntry(j);
        /*
        if (Mjj > 1900)
            Mjj = 1900;
        if (Mla > 190)
            Mla = 190;
*/
        p4.SetPtEtaPhiM(photonet, photoneta, photonphi, 0);
        v4.SetPtEtaPhiM(ptVlepJEC_new, yVlepJEC_new, phiVlepJEC_new, massVlepJEC_new);
        WGmass = (p4 + v4).M();
        if (WGmass > 1500)
            WGmass = 1250;

        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && photonet > 100 && jet1pt_new > 40 && jet2pt_new > 30 && fabs(jet1eta_new) < 4.7 && fabs(jet2eta_new) < 4.7 && drj1a_new > 0.5 && drj2a_new > 0.5 && drj1l_new > 0.5 && drj2l_new > 0.5 && jet1icsv_new < 0.8484 && jet2icsv_new < 0.8484 && Mla > 30 && deltaeta_new > 2.5 && Mjj_new > 500 && mtVlepJECnew_new > 30 && MET_et_new > 30 && j1metPhi_new > 0.4 && j2metPhi_new > 0.4 && WGmass > 100;
        // electron
        bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && photonet > 100 && jet1pt_new > 40 && jet2pt_new > 30 && fabs(jet1eta_new) < 4.7 && fabs(jet2eta_new) < 4.7 && drj1a_new > 0.5 && drj2a_new > 0.5 && drj1l_new > 0.5 && drj2l_new > 0.5 && jet1icsv_new < 0.8484 && jet2icsv_new < 0.8484 && fabs(Mla - 91) > 10 && Mla > 30 && deltaeta_new > 2.5 && Mjj_new > 500 && mtVlepJECnew_new > 30 && MET_et_new > 30 && j1metPhi_new > 0.4 && j2metPhi_new > 0.4 && WGmass > 100;
        // barre : fabs(photonsceta) < 1.4442 ; endcap : fabs(photonsceta)>1.566 && fabs(photonsceta)<2.5

        // --------------------------------------------------------------------
        // control region
        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && mtVlepJECnew_new > 30 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && MET_et_new > 30 && photonet > 25 && jet1pt_new > 40 && jet2pt_new > 30 && fabs(jet1eta_new) < 4.7 && fabs(jet2eta_new) < 4.7 && drj1a_new > 0.5 && drj2a_new > 0.5 && drj1l_new > 0.5 && drj2l_new > 0.5 && j1metPhi_new > 0.4 && j2metPhi_new > 0.4 && jet1icsv_new < 0.8484 && jet2icsv_new < 0.8484 && Mjj_new > 200 && Mjj_new < 400;

        // electron
        //bool ipass = fabs(photonsceta) < 1.4442 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && mtVlepJECnew_new > 30 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && MET_et_new > 30 && photonet > 25 && jet1pt_new > 40 && jet2pt_new > 30 && fabs(jet1eta_new) < 4.7 && fabs(jet2eta_new) < 4.7 && drj1a_new > 0.5 && drj2a_new > 0.5 && drj1l_new > 0.5 && drj2l_new > 0.5 && j1metPhi_new > 0.4 && j2metPhi_new > 0.4 && jet1icsv_new < 0.8484 && jet2icsv_new < 0.8484 && fabs(Mla - 91) > 10 && Mjj_new > 200 && Mjj_new < 400;

        double lumi = 35.857;
        if (ipass) {
            count_new += scalef * lumi;
            histo2->Fill(WGmass, lumi * scalef);
        }
    }

    for (int j = 0; j < nentries1; j++) {
        Outtree1->GetEntry(j);
        /*
        if (Mjj > 1900)
            Mjj = 1900;
        if (Mla > 190)
            Mla = 190;
*/

        p4.SetPtEtaPhiM(photonet, photoneta, photonphi, 0);
        v4.SetPtEtaPhiM(ptVlepJEC_JEC_up, yVlepJEC_JEC_up, phiVlepJEC_JEC_up, massVlepJEC_JEC_up);
        WGmass = (p4 + v4).M();
        if (WGmass > 1500)
            WGmass = 1250;

        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && photonet > 100 && jet1pt_JEC_up > 40 && jet2pt_JEC_up > 30 && fabs(jet1eta_JEC_up) < 4.7 && fabs(jet2eta_JEC_up) < 4.7 && drj1a_JEC_up > 0.5 && drj2a_JEC_up > 0.5 && drj1l_JEC_up > 0.5 && drj2l_JEC_up > 0.5 && jet1icsv_JEC_up < 0.8484 && jet2icsv_JEC_up < 0.8484 && Mla > 30 && deltaeta_JEC_up > 2.5 && Mjj_JEC_up > 500 && mtVlepJECnew_JEC_up > 30 && MET_et_JEC_up > 30 && j1metPhi_JEC_up > 0.4 && j2metPhi_JEC_up > 0.4 && WGmass > 100;
        // electron
        bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && photonet > 100 && jet1pt_JEC_up > 40 && jet2pt_JEC_up > 30 && fabs(jet1eta_JEC_up) < 4.7 && fabs(jet2eta_JEC_up) < 4.7 && drj1a_JEC_up > 0.5 && drj2a_JEC_up > 0.5 && drj1l_JEC_up > 0.5 && drj2l_JEC_up > 0.5 && jet1icsv_JEC_up < 0.8484 && jet2icsv_JEC_up < 0.8484 && fabs(Mla - 91) > 10 && Mla > 30 && deltaeta_JEC_up > 2.5 && Mjj_JEC_up > 500 && mtVlepJECnew_JEC_up > 30 && MET_et_JEC_up > 30 && j1metPhi_JEC_up > 0.4 && j2metPhi_JEC_up > 0.4 && WGmass > 100;

        // barre : fabs(photonsceta) < 1.4442 ; endcap : fabs(photonsceta)>1.566 && fabs(photonsceta)<2.5

        // --------------------------------------------------------------------
        // control region
        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && mtVlepJECnew_JEC_up > 30 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && MET_et_JEC_up > 30 && photonet > 25 && jet1pt_JEC_up > 40 && jet2pt_JEC_up > 30 && fabs(jet1eta_JEC_up) < 4.7 && fabs(jet2eta_JEC_up) < 4.7 && drj1a_JEC_up > 0.5 && drj2a_JEC_up > 0.5 && drj1l_JEC_up > 0.5 && drj2l_JEC_up > 0.5 && j1metPhi_JEC_up > 0.4 && j2metPhi_JEC_up > 0.4 && jet1icsv_JEC_up < 0.8484 && jet2icsv_JEC_up < 0.8484 && Mjj_JEC_up > 200 && Mjj_JEC_up < 400;

        // electron
        //bool ipass = fabs(photonsceta) < 1.4442 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && mtVlepJECnew_JEC_up > 30 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && MET_et_JEC_up > 30 && photonet > 25 && jet1pt_JEC_up > 40 && jet2pt_JEC_up > 30 && fabs(jet1eta_JEC_up) < 4.7 && fabs(jet2eta_JEC_up) < 4.7 && drj1a_JEC_up > 0.5 && drj2a_JEC_up > 0.5 && drj1l_JEC_up > 0.5 && drj2l_JEC_up > 0.5 && j1metPhi_JEC_up > 0.4 && j2metPhi_JEC_up > 0.4 && jet1icsv_JEC_up < 0.8484 && jet2icsv_JEC_up < 0.8484 && fabs(Mla - 91) > 10 && Mjj_JEC_up > 200 && Mjj_JEC_up < 400;

        double lumi = 35.857;

        if (ipass) {
            count_JEC_up += scalef * lumi;
            histo3->Fill(WGmass, lumi * scalef);
        }
    }

    for (int j = 0; j < nentries1; j++) {
        Outtree1->GetEntry(j);
        /*
        if (Mjj > 1900)
            Mjj = 1900;
        if (Mla > 190)
            Mla = 190;
*/
        p4.SetPtEtaPhiM(photonet, photoneta, photonphi, 0);
        v4.SetPtEtaPhiM(ptVlepJEC_JEC_down, yVlepJEC_JEC_down, phiVlepJEC_JEC_down, massVlepJEC_JEC_down);
        WGmass = (p4 + v4).M();
        if (WGmass > 1500)
            WGmass = 1250;

        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && photonet > 100 && jet1pt_JEC_down > 40 && jet2pt_JEC_down > 30 && fabs(jet1eta_JEC_down) < 4.7 && fabs(jet2eta_JEC_down) < 4.7 && drj1a_JEC_down > 0.5 && drj2a_JEC_down > 0.5 && drj1l_JEC_down > 0.5 && drj2l_JEC_down > 0.5 && jet1icsv_JEC_down < 0.8484 && jet2icsv_JEC_down < 0.8484 && Mla > 30 && deltaeta_JEC_down > 2.5 && Mjj_JEC_down > 500 && mtVlepJECnew_JEC_down > 30 && j1metPhi_JEC_down > 0.4 && j2metPhi_JEC_down > 0.4 && MET_et_JEC_down > 30 && WGmass > 100;
        // electron
        bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && photonet > 100 && jet1pt_JEC_down > 40 && jet2pt_JEC_down > 30 && fabs(jet1eta_JEC_down) < 4.7 && fabs(jet2eta_JEC_down) < 4.7 && drj1a_JEC_down > 0.5 && drj2a_JEC_down > 0.5 && drj1l_JEC_down > 0.5 && drj2l_JEC_down > 0.5 && jet1icsv_JEC_down < 0.8484 && jet2icsv_JEC_down < 0.8484 && fabs(Mla - 91) > 10 && Mla > 30 && deltaeta_JEC_down > 2.5 && Mjj_JEC_down > 500 && mtVlepJECnew_JEC_down > 30 && j1metPhi_JEC_down > 0.4 && j2metPhi_JEC_down > 0.4 && MET_et_JEC_down > 30 && WGmass > 100;

        // barre : fabs(photonsceta) < 1.4442 ; endcap : fabs(photonsceta)>1.566 && fabs(photonsceta)<2.5

        // --------------------------------------------------------------------
        // control region
        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && mtVlepJECnew_JEC_down > 30 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && MET_et_JEC_down > 30 && photonet > 25 && jet1pt_JEC_down > 40 && jet2pt_JEC_down > 30 && fabs(jet1eta_JEC_down) < 4.7 && fabs(jet2eta_JEC_down) < 4.7 && drj1a_JEC_down > 0.5 && drj2a_JEC_down > 0.5 && drj1l_JEC_down > 0.5 && drj2l_JEC_down > 0.5 && j1metPhi_JEC_down > 0.4 && j2metPhi_JEC_down > 0.4 && jet1icsv_JEC_down < 0.8484 && jet2icsv_JEC_down < 0.8484 && Mjj_JEC_down > 200 && Mjj_JEC_down < 400;

        // electron
        //bool ipass = fabs(photonsceta) < 1.4442 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && mtVlepJECnew_JEC_down > 30 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && MET_et_JEC_down > 30 && photonet > 25 && jet1pt_JEC_down > 40 && jet2pt_JEC_down > 30 && fabs(jet1eta_JEC_down) < 4.7 && fabs(jet2eta_JEC_down) < 4.7 && drj1a_JEC_down > 0.5 && drj2a_JEC_down > 0.5 && drj1l_JEC_down > 0.5 && drj2l_JEC_down > 0.5 && j1metPhi_JEC_down > 0.4 && j2metPhi_JEC_down > 0.4 && jet1icsv_JEC_down < 0.8484 && jet2icsv_JEC_down < 0.8484 && fabs(Mla - 91) > 10 && Mjj_JEC_down > 200 && Mjj_JEC_down < 400;

        double lumi = 35.857;

        if (ipass) {
            count_JEC_down += scalef * lumi;
            histo4->Fill(WGmass, lumi * scalef);
        }
    }
    for (int j = 0; j < nentries1; j++) {
        Outtree1->GetEntry(j);
        /*
        if (Mjj > 1900)
            Mjj = 1900;
        if (Mla > 190)
            Mla = 190;
*/

        p4.SetPtEtaPhiM(photonet, photoneta, photonphi, 0);
        v4.SetPtEtaPhiM(ptVlepJEC_JER_up, yVlepJEC_JER_up, phiVlepJEC_JER_up, massVlepJEC_JER_up);
        WGmass = (p4 + v4).M();
        if (WGmass > 1500)
            WGmass = 1250;

        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && photonet > 100 && jet1pt_JER_up > 40 && jet2pt_JER_up > 30 && fabs(jet1eta_JER_up) < 4.7 && fabs(jet2eta_JER_up) < 4.7 && drj1a_JER_up > 0.5 && drj2a_JER_up > 0.5 && drj1l_JER_up > 0.5 && drj2l_JER_up > 0.5 && jet1icsv_JER_up < 0.8484 && jet2icsv_JER_up < 0.8484 && Mla > 30 && deltaeta_JER_up > 2.5 && Mjj_JER_up > 500 && MET_et_JER_up > 30 && j1metPhi_JER_up > 0.4 && j2metPhi_JER_up > 0.4 && mtVlepJECnew_JER_up > 30 && WGmass > 100;
        // electron
        bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && photonet > 100 && jet1pt_JER_up > 40 && jet2pt_JER_up > 30 && fabs(jet1eta_JER_up) < 4.7 && fabs(jet2eta_JER_up) < 4.7 && drj1a_JER_up > 0.5 && drj2a_JER_up > 0.5 && drj1l_JER_up > 0.5 && drj2l_JER_up > 0.5 && jet1icsv_JER_up < 0.8484 && jet2icsv_JER_up < 0.8484 && fabs(Mla - 91) > 10 && Mla > 30 && deltaeta_JER_up > 2.5 && Mjj_JER_up > 500 && mtVlepJECnew_JER_up > 30 && MET_et_JER_up > 30 && j1metPhi_JER_up > 0.4 && j2metPhi_JER_up > 0.4 && WGmass > 100;

        // barre : fabs(photonsceta) < 1.4442 ; endcap : fabs(photonsceta)>1.566 && fabs(photonsceta)<2.5

        // --------------------------------------------------------------------
        // control region
        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && mtVlepJECnew_JER_up > 30 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && MET_et_JER_up > 30 && photonet > 25 && jet1pt_JER_up > 40 && jet2pt_JER_up > 30 && fabs(jet1eta_JER_up) < 4.7 && fabs(jet2eta_JER_up) < 4.7 && drj1a_JER_up > 0.5 && drj2a_JER_up > 0.5 && drj1l_JER_up > 0.5 && drj2l_JER_up > 0.5 && j1metPhi_JER_up > 0.4 && j2metPhi_JER_up > 0.4 && jet1icsv_JER_up < 0.8484 && jet2icsv_JER_up < 0.8484 && Mjj_JER_up > 200 && Mjj_JER_up < 400;

        // electron
        //bool ipass = fabs(photonsceta) < 1.4442 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && mtVlepJECnew_JER_up > 30 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && MET_et_JER_up > 30 && photonet > 25 && jet1pt_JER_up > 40 && jet2pt_JER_up > 30 && fabs(jet1eta_JER_up) < 4.7 && fabs(jet2eta_JER_up) < 4.7 && drj1a_JER_up > 0.5 && drj2a_JER_up > 0.5 && drj1l_JER_up > 0.5 && drj2l_JER_up > 0.5 && j1metPhi_JER_up > 0.4 && j2metPhi_JER_up > 0.4 && jet1icsv_JER_up < 0.8484 && jet2icsv_JER_up < 0.8484 && fabs(Mla - 91) > 10 && Mjj_JER_up > 200 && Mjj_JER_up < 400;

        double lumi = 35.857;

        if (ipass) {
            count_JER_up += scalef * lumi;
            histo5->Fill(WGmass, lumi * scalef);
        }
    }
    for (int j = 0; j < nentries1; j++) {
        Outtree1->GetEntry(j);
        /*
        if (Mjj > 1900)
            Mjj = 1900;
        if (Mla > 190)
            Mla = 190;
*/
        p4.SetPtEtaPhiM(photonet, photoneta, photonphi, 0);
        v4.SetPtEtaPhiM(ptVlepJEC_JER_down, yVlepJEC_JER_down, phiVlepJEC_JER_down, massVlepJEC_JER_down);
        WGmass = (p4 + v4).M();
        if (WGmass > 1500)
            WGmass = 1250;

        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && photonet > 100 && jet1pt_JER_down > 40 && jet2pt_JER_down > 30 && fabs(jet1eta_JER_down) < 4.7 && fabs(jet2eta_JER_down) < 4.7 && drj2a_JER_down > 0.5 && drj1a_JER_down > 0.5 && drj1l_JER_down > 0.5 && drj2l_JER_down > 0.5 && jet1icsv_JER_down < 0.8484 && jet2icsv_JER_down < 0.8484 && Mla > 30 && deltaeta_JER_down > 2.5 && Mjj_JER_down > 500 && MET_et_JER_down > 30 && j1metPhi_JER_down > 0.4 && j2metPhi_JER_down > 0.4 && mtVlepJECnew_JER_down > 30 && WGmass > 100;

        // electron
        bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && photonet > 100 && jet1pt_JER_down > 40 && jet2pt_JER_down > 30 && fabs(jet1eta_JER_down) < 4.7 && fabs(jet2eta_JER_down) < 4.7 && drj2a_JER_down > 0.5 && drj1a_JER_down > 0.5 && drj1l_JER_down > 0.5 && drj2l_JER_down > 0.5 && jet1icsv_JER_down < 0.8484 && jet2icsv_JER_down < 0.8484 && fabs(Mla - 91) > 10 && Mla > 30 && deltaeta_JER_down > 2.5 && Mjj_JER_down > 500 && j1metPhi_JER_down > 0.4 && j2metPhi_JER_down > 0.4 && MET_et_JER_down > 30 && mtVlepJECnew_JER_down > 30 && WGmass > 100;

        // barre : fabs(photonsceta) < 1.4442 ; endcap : fabs(photonsceta)>1.566 && fabs(photonsceta)<2.5 photonet > 25 photonet > 100

        // --------------------------------------------------------------------
        // control region
        // muon
        //bool ipass = fabs(photonsceta) > 1.566 && fabs(photonsceta) < 2.5 && !photonhaspixelseed && lep == 13 && nlooseeles < 1 && nloosemus < 2 && HLT_Mu2 == 1 && mtVlepJECnew_JER_down > 30 && ptlep1 > 30 && fabs(etalep1) < 2.4 && drla > 0.5 && MET_et_JER_down > 30 && photonet > 25 && jet1pt_JER_down > 40 && jet2pt_JER_down > 30 && fabs(jet1eta_JER_down) < 4.7 && fabs(jet2eta_JER_down) < 4.7 && drj2a_JER_down > 0.5 && drj1a_JER_down > 0.5 && drj1l_JER_down > 0.5 && drj2l_JER_down > 0.5 && j1metPhi_JER_down > 0.4 && j2metPhi_JER_down > 0.4 && jet1icsv_JER_down < 0.8484 && jet2icsv_JER_down < 0.8484 && Mjj_JER_down > 200 && Mjj_JER_down < 400;

        // electron
        //bool ipass = fabs(photonsceta) < 1.4442 && !photonhaspixelseed && lep == 11 && nlooseeles < 2 && nloosemus < 1 && HLT_Ele2 == 1 && mtVlepJECnew_JER_down > 30 && ptlep1 > 30 && fabs(etalep1) < 2.5 && drla > 0.5 && MET_et_JER_down > 30 && photonet > 25 && jet1pt_JER_down > 40 && jet2pt_JER_down > 30 && fabs(jet1eta_JER_down) < 4.7 && fabs(jet2eta_JER_down) < 4.7 && drj2a_JER_down > 0.5 && drj1a_JER_down > 0.5 && drj1l_JER_down > 0.5 && drj2l_JER_down > 0.5 && j1metPhi_JER_down > 0.4 && j2metPhi_JER_down > 0.4 && jet1icsv_JER_down < 0.8484 && jet2icsv_JER_down < 0.8484 && fabs(Mla - 91) > 10 && Mjj_JER_down > 200 && Mjj_JER_down < 400;

        double lumi = 35.857;

        if (ipass) {
            count_JER_down += scalef * lumi;
            histo6->Fill(WGmass, lumi * scalef);
        }
    }

    //cout << "old:" << histo1->Integral() << "\t new:" << histo2->Integral() << "\t jec_up:" << histo3->Integral() << "\t jec_down:" << histo4->Integral() << "\t jer_up:" << histo5->Integral() << "\t jer_down:" << histo6->Integral() << endl;
    cout << "count:" << count << "\t count_new:" << count_new << "\t count_JEC_up:" << count_JEC_up << "\t count_JEC_down:" << count_JEC_down << "\t count_JER_up:" << count_JER_up << "\t count_JER_down:" << count_JER_down << endl;
    /*
    TH2F tmp;
    TH2F tmp2;
    //tmp.Sumw2();
    //tmp2.Sumw2();
    tmp  = (*histo3);
    tmp2 = (*histo3);
    for (int bin = 0; bin <= histo3->GetNcells(); ++bin) {
        tmp.SetBinContent(bin, abs(histo3->GetBinContent(bin) - histo4->GetBinContent(bin)) / 2.);
        //tmp.SetBinError(bin, (histo3->GetBinError(bin) + histo4->GetBinError(bin)) / 2.);
    }

    tmp.Divide(histo2);
    tmp.SetName("jec_unc");
    for (int bin = 0; bin <= histo4->GetNcells(); ++bin) {
        tmp2.SetBinContent(bin, max(abs(histo3->GetBinContent(bin) - histo2->GetBinContent(bin)), abs(histo4->GetBinContent(bin) - histo2->GetBinContent(bin))));
        //tmp2.SetBinError(bin, (histo3->GetBinError(bin) + histo4->GetBinError(bin)) / 2.);
    }
    tmp2.Divide(histo2);
    tmp2.SetName("jec_unc_max");

    TH2F tmp3;
    TH2F tmp4;

    tmp3 = (*histo5);
    tmp4 = (*histo5);
    //tmp3.Sumw2();
    //tmp4.Sumw2();

    for (int bin = 0; bin <= histo5->GetNcells(); ++bin) {
        tmp3.SetBinContent(bin, abs(histo5->GetBinContent(bin) - histo6->GetBinContent(bin)) / 2.);
        //tmp3.SetBinError(bin, (histo5->GetBinError(bin) + histo6->GetBinError(bin)) / 2.);
    }

    tmp3.Divide(histo2);
    tmp3.SetName("jer_unc");

    for (int bin = 0; bin <= histo6->GetNcells(); ++bin) {
        tmp4.SetBinContent(bin, max(abs(histo5->GetBinContent(bin) - histo2->GetBinContent(bin)), abs(histo6->GetBinContent(bin) - histo2->GetBinContent(bin))));
        //tmp4.SetBinError(bin, (histo5->GetBinError(bin) + histo6->GetBinError(bin)) / 2.);
    }
    tmp4.Divide(histo2);
    tmp4.SetName("jer_unc_max");

    //gStyle->SetPaintTextFormat("3.2f");
    gStyle->SetOptStat(0);
    TCanvas* c1 = new TCanvas("c1", "c1", 1200, 900);
    c1->Divide(2, 2);
    c1->cd(1);
    tmp.GetXaxis()->SetTitle("M_{jj}");
    tmp.GetYaxis()->SetTitle("M_{l#gamma}");
    tmp.Draw("text colz");
    c1->cd(2);
    tmp2.GetXaxis()->SetTitle("M_{jj}");
    tmp2.GetYaxis()->SetTitle("M_{l#gamma}");
    tmp2.Draw("text colz");
    c1->cd(3);
    tmp3.GetXaxis()->SetTitle("M_{jj}");
    tmp3.GetYaxis()->SetTitle("M_{l#gamma}");
    tmp3.Draw("text colz");
    c1->cd(4);
    tmp4.GetXaxis()->SetTitle("M_{jj}");
    tmp4.GetYaxis()->SetTitle("M_{l#gamma}");
    tmp4.Draw("text colz");
    c1->Print("jerc_met.pdf");

    TFile* fout = TFile::Open("jerc_met.root", "RECREATE");
    histo1->Write();
    histo2->Write();
    histo3->Write();
    histo4->Write();
    histo5->Write();
    histo6->Write();
    tmp.Write();
    tmp2.Write();
    tmp3.Write();
    tmp4.Write();
    c1->Write();
    fout->Write();
    return 0;
    */
    TH1F tmp;
    TH1F tmp2;
    //tmp.Sumw2();
    //tmp2.Sumw2();
    tmp  = (*histo3);
    tmp2 = (*histo3);
    for (int bin = 1; bin < 6; ++bin) {
        tmp.SetBinContent(bin, abs(histo3->GetBinContent(bin) - histo4->GetBinContent(bin)) / 2.);
        //tmp.SetBinError(bin, (histo3->GetBinError(bin) + histo4->GetBinError(bin)) / 2.);
    }

    tmp.Divide(histo2);
    tmp.SetName("jec_unc");
    for (int bin = 1; bin < 6; ++bin) {
        tmp2.SetBinContent(bin, max(abs(histo3->GetBinContent(bin) - histo2->GetBinContent(bin)), abs(histo4->GetBinContent(bin) - histo2->GetBinContent(bin))));
        //tmp2.SetBinError(bin, (histo3->GetBinError(bin) + histo4->GetBinError(bin)) / 2.);
    }
    tmp2.Divide(histo2);
    tmp2.SetName("jec_unc_max");

    TH1F tmp3;
    TH1F tmp4;

    tmp3 = (*histo5);
    tmp4 = (*histo5);
    //tmp3.Sumw2();
    //tmp4.Sumw2();

    for (int bin = 1; bin < 6; ++bin) {
        tmp3.SetBinContent(bin, abs(histo5->GetBinContent(bin) - histo6->GetBinContent(bin)) / 2.);
        //tmp3.SetBinError(bin, (histo5->GetBinError(bin) + histo6->GetBinError(bin)) / 2.);
    }

    tmp3.Divide(histo2);
    tmp3.SetName("jer_unc");

    for (int bin = 1; bin < 6; ++bin) {
        tmp4.SetBinContent(bin, max(abs(histo5->GetBinContent(bin) - histo2->GetBinContent(bin)), abs(histo6->GetBinContent(bin) - histo2->GetBinContent(bin))));
        //tmp4.SetBinError(bin, (histo5->GetBinError(bin) + histo6->GetBinError(bin)) / 2.);
    }
    tmp4.Divide(histo2);
    tmp4.SetName("jer_unc_max");

    //gStyle->SetPaintTextFormat("3.2f");
    gStyle->SetOptStat(0);
    TCanvas* c1 = new TCanvas("c1", "c1", 1200, 900);
    c1->Divide(2, 2);
    c1->cd(1);
    tmp.GetXaxis()->SetTitle("WGmass");
    //tmp.GetYaxis()->SetTitle("M_{l#gamma}");
    tmp.Draw();
    c1->cd(2);
    tmp2.GetXaxis()->SetTitle("WGmass");
    //tmp2.GetYaxis()->SetTitle("M_{l#gamma}");
    tmp2.Draw();
    c1->cd(3);
    tmp3.GetXaxis()->SetTitle("WGmass");
    //tmp3.GetYaxis()->SetTitle("M_{l#gamma}");
    tmp3.Draw();
    c1->cd(4);
    tmp4.GetXaxis()->SetTitle("WGmass");
    //tmp4.GetYaxis()->SetTitle("M_{l#gamma}");
    tmp4.Draw();
    c1->Print("jerc_met.pdf");

    TFile* fout = TFile::Open("jerc_met.root", "RECREATE");
    histo1->Write();
    histo2->Write();
    histo3->Write();
    histo4->Write();
    histo5->Write();
    histo6->Write();
    tmp.Write();
    tmp2.Write();
    tmp3.Write();
    tmp4.Write();
    c1->Write();
    fout->Write();
    return 0;
}  //main
//g++ -o calc `root-config --cflags --glibs` unc.cc
