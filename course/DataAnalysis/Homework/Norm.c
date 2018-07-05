#define Norm_cxx
#include "Norm.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Norm::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L Norm.C
//      Root > Norm t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
//   t1->Draw("normf:normb>>(450,0,4500,450,0,4500)","normf>=200&&normf<=4000&&normb>=200&&normb<=4000","colz")
//   t1->Draw("normf:normf-normb>>(2000,-2000,2000,2000,0,4000)","normf>100&&normb>0","colz")
 
  /*TFile *file = new TFile("../hw2_1/tele0300.root");
	TTree *t = (TTree*)file->Get("tree");
        TTree  *fChain;
	fChain = t;*/
	const int N=5;
	/*Int_t f,b;
	t->SetBranchAddress("f",&f);
	t->SetBranchAddress("b",&b);*/
	Double_t A[32],B[32],C[32],D[32];
	Double_t count;
	
	//tree->Draw("b[14]:f[14]");
	for(Int_t i=0;i<32;i++)
	{
	for(Int_t j=0;j<N;j++)
	{ 
	  TString istr; ostringstream ostr;  ostr<<i; istr = ostr.str();
	  TString jstr;  ostr.str(""); ostr<<j;    jstr = ostr.str();
	  TString Astr;  ostr.str(""); ostr<<A[i]; Astr = ostr.str();
	  TString Bstr;  ostr.str(""); ostr<<B[i]; Bstr = ostr.str();
	  if(j==0)
	    {count=tree->Draw("f[15]:b["+istr+"]>>(400,0,4000,400,0,4000)","b["+istr+"]>100&&f[15]>100&&b["+istr+"]<3840&&f[15]<3840&&f[15]-0.5*b["+istr+"]>=0&&f[15]-1.6*b["+istr+"]<=0","colz");
	      //count=tree->Draw("f[15]:b["+istr+"]>>(400,0,4000,400,0,4000)","b["+istr+"]>100&&f[15]>100&&b["+istr+"]<3840&&f[15]<3840","colz");
	    }
	  else
	    {//tree->Draw("f[15]:b[i]>>(400,0,4000,400,0,4000)","f[15]-A[i]*b[i]+B[i]+200/j>=0&&f[15]-A[i]*b[i]+B[i]-200/j<=0");
	      count=tree->Draw("f[15]:b["+istr+"]>>(400,0,4000,400,0,4000)","b["+istr+"]>100&&f[15]>100&&b["+istr+"]<3840&&f[15]<3840&&f[15]-"+Astr+"*b["+istr+"]-"+Bstr+"-800/2**"+jstr+"<=0&&f[15]-"+Astr+"*b["+istr+"]-"+Bstr+"+800/2**"+jstr+">=0","colz");
	     //count=tree->Draw("f[15]:b["+istr+"]>>(400,0,4000,400,0,4000)","b["+istr+"]>0&&f[15]>0&&b["+istr+"]<3840&&f[15]<3840&&f[15]-"+Astr+"*b["+istr+"]-"+Bstr+"-200/"+jstr+"<=0");
	    }
	  
	  if(count<=50)  { A[i]=1;  B[i]=0; continue;}
	TF1 *fitfunc = new TF1("fitfunc","pol1",200,3840);
	tree->Fit("fitfunc","");
	
	A[i] = fitfunc->GetParameter(1);
	B[i] = fitfunc->GetParameter(0);
	cout<<A[i]<<"   "<<B[i]<<" "<<count<<endl;
	
	}
	}
        //cout<<A[15];

      	for(Int_t i=0;i<32;i++)
	{
	for(Int_t j=0;j<N;j++)
	{  ostr.str(""); ostr<<i; istr = ostr.str();   ostr.str(""); ostr<<j; jstr = ostr.str();
	  TString Cstr;   ostr.str(""); ostr<<C[i]; Cstr = ostr.str();
	  TString Dstr;   ostr.str(""); ostr<<D[i]; Dstr = ostr.str();
	  if(j==0)
	  {count=tree->Draw("b[15]:f["+istr+"]>>(400,0,4000,400,0,4000)","f["+istr+"]>100&&b[15]>100&&f["+istr+"]<3840&&b[15]<3840&&b[15]-0.5*f["+istr+"]>=0&&b[15]-1.6*f["+istr+"]<=0");}
	  else
	    {//tree->Draw("b[15]:f[i]>>(400,0,4000,400,0,4000)","b[15]-C[i]*f[i]+D[i]+200/j>=0&&b[15]-C[i]*f[i]+D[i]-200/j<=0");
	  count=tree->Draw("b[15]:f["+istr+"]>>(400,0,4000,400,0,4000)","f["+istr+"]>100&&b[15]>100&&f["+istr+"]<3840&&b[15]<3840&&b[15]-"+Cstr+"*f["+istr+"]-"+Dstr+"-800/2**"+jstr+"<=0&&b[15]-"+Cstr+"*f["+istr+"]-"+Dstr+"+800/2**"+jstr+">=0");}
	  
	if(count<=50)  { C[i]=1;  D[i]=0; continue;}
	TF1 *fitfunc1 = new TF1("fitfunc1","pol1",200,3840);
	tree->Fit("fitfunc1","");
	
	C[i] = fitfunc1->GetParameter(1);
	D[i] = fitfunc1->GetParameter(0);
	//cout<<C[i]<<"  "<<D[i]<<endl;
	cout<<C[i]<<"   "<<D[i]<<" "<<count<<endl;
	
	}
	}
	
	newf=new TFile("./normalization.root","RECREATE");
        newt=new TTree("t1","t1");
        Int_t normf[32],normb[32];
        newt->Branch("normf",normf,"normf[32]/I");
        newt->Branch("normb",normb,"normb[32]/I");
        Long64_t nentries = fChain->GetEntriesFast();
	ofstream fnorm,bnorm;

        Long64_t nbytes = 0, nb = 0;

        for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
    
        for(int i=0;i<32;i++){
	  if(A[i]<0.5||A[i]>1.6) {A[i]=1;B[i]=0;}
	  if(C[i]<0.5||C[i]>1.6) {C[i]=1;D[i]=0;}
          normb[i]=int(b[i]*A[i]+B[i]);
          normf[i]=int(f[i]*C[i]*A[15]+A[15]*D[i]+B[15]);
        }
        newt->Fill();
        }
        newt->Write();
        newf->Close();

	fnorm.open("./fnorm.txt");
	for(int i=0;i<32;i++)  fnorm<<i<<": "<<C[i]*A[15]<<"   "<<A[15]*D[i]+B[15]<<endl;
	fnorm.close();
	
	bnorm.open("./bnorm.txt");
	for(int i=0;i<32;i++)  bnorm<<i<<": "<<A[i]<<"   "<<B[i]<<endl;
	bnorm.close();
}


