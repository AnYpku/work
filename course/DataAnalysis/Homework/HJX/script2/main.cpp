#include "ppac.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv){
	
	// Prepare the file names
	int runnum;
	if(argc!=2) {
		cout << "USAGE : " << argv[0] << " #[runnum]";
		return -1;
	}
	runnum = atoi(argv[1]);		// convet char to int

	char ipfn[124];		// input file name
	char opfn[124];		// output file name
	//sprintf(ipfn,"/home/data/students2018/HanJiaxing/runmust20%03d.root",runnum);
	sprintf(ipfn,"../runmust20%03d.root",runnum);
	sprintf(opfn,"./ppac20%03d.root",runnum);

	//TString DataPath, OutPath, ipfn, opfn;
	//DataPath = "$HOME/data/MUST2@BigRIPS/"; 
	//DataPath = "./";
	//OutPath = "./";
	//ipfn.Form("%srunmust200%2d.root",DataPath.Data(),runnum);
	//opfn.Form("run%04d.root",runnum);


	// Open input file and get the pointer of the tree.
	TFile *ipf = new TFile(ipfn);
	if(!ipf->IsOpen()) {
		cout << "cannot open input file: " << ipfn << endl;
		return 1;
	}
	TTree *ipt = (TTree*)ipf->Get("t1");
	if(ipt==0){
	  cout<<"cannot find input tree!"<<endl;
	  return 1;
	}

	// Open output file and create new tree.
	TFile *opf = new TFile(opfn,"RECREATE");
	if(!opf->IsOpen()) {
		cout << "cannot creat output file!" << endl;
		return 1;
	}
	TTree *opt = new TTree("tree","tree");
	if(opt==0){
	  cout<<"cannot creat output tree!"<<endl;
	  return 1;
	}
	
	// Analysis
	ppac *pc=new ppac(ipt);	// pass input tree
	pc->BranchOpt(opt);			// branches for output
  pc->Loop(opt);
	opt->Write();						// write to the output file
  opf->Close();						// close the output file

	return 1;
}
