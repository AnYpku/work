//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Apr  5 21:23:46 2018 by ROOT version 6.12/06
// from TTree tree/Pku Ribll
// found on file: ../data.root
//////////////////////////////////////////////////////////

#ifndef cali_h
#define cali_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class cali {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           ahit;
   Int_t           amod[308];   //[ahit]
   Int_t           ach[308];   //[ahit]
   Int_t           aval[308];   //[ahit]
   Int_t           adc[13][32];
   Int_t           acnt[13];
   Int_t           ghit;
   Int_t           gmod[10];   //[ghit]
   Int_t           gch[10];   //[ghit]
   Int_t           gval[10];   //[ghit]
   Int_t           gdc[2][128][20];
   Int_t           gmulti[2][128];
   Int_t           gcnt[2];
   Int_t           shit;
   Int_t           smod[12];   //[shit]
   Int_t           sch[12];   //[shit]
   ULong64_t       sval[12];   //[shit]
   ULong64_t       sdc[32];
   Long64_t        nevt;
 
   // List of branches
   TBranch        *b_ahit;   //!
   TBranch        *b_amod;   //!
   TBranch        *b_ach;   //!
   TBranch        *b_aval;   //!
   TBranch        *b_adc;   //!
   TBranch        *b_acnt;   //!
   TBranch        *b_ghit;   //!
   TBranch        *b_gmod;   //!
   TBranch        *b_gch;   //!
   TBranch        *b_gval;   //!
   TBranch        *b_gdc;   //!
   TBranch        *b_gmulti;   //!
   TBranch        *b_gcnt;   //!
   TBranch        *b_shit;   //!
   TBranch        *b_smod;   //!
   TBranch        *b_sch;   //!
   TBranch        *b_sval;   //!
   TBranch        *b_sdc;   //!
   TBranch        *b_nevt;   //!
  
   cali(TTree *tree=0);
   virtual ~cali();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef cali_cxx
cali::cali(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../data.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../data.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

cali::~cali()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t cali::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t cali::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void cali::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ahit", &ahit, &b_ahit);
   fChain->SetBranchAddress("amod", amod, &b_amod);
   fChain->SetBranchAddress("ach", ach, &b_ach);
   fChain->SetBranchAddress("aval", aval, &b_aval);
   fChain->SetBranchAddress("adc", adc, &b_adc);
   fChain->SetBranchAddress("acnt", acnt, &b_acnt);
   fChain->SetBranchAddress("ghit", &ghit, &b_ghit);
   fChain->SetBranchAddress("gmod", gmod, &b_gmod);
   fChain->SetBranchAddress("gch", gch, &b_gch);
   fChain->SetBranchAddress("gval", gval, &b_gval);
   fChain->SetBranchAddress("gdc", gdc, &b_gdc);
   fChain->SetBranchAddress("gmulti", gmulti, &b_gmulti);
   fChain->SetBranchAddress("gcnt", gcnt, &b_gcnt);
   fChain->SetBranchAddress("shit", &shit, &b_shit);
   fChain->SetBranchAddress("smod", smod, &b_smod);
   fChain->SetBranchAddress("sch", sch, &b_sch);
   fChain->SetBranchAddress("sval", sval, &b_sval);
   fChain->SetBranchAddress("sdc", sdc, &b_sdc);
   fChain->SetBranchAddress("nevt", &nevt, &b_nevt);
 
   Notify();
}

Bool_t cali::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void cali::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t cali::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef cali_cxx
