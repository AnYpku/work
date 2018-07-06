#include "dssd.h"
//#include "/Users/songyx/work/useful.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){
/*
	int runnum;
	if(argc!=2) {
		cout<<"USAGE : "<<argv[0]<<" #[runnum]";
		return -1;
	}
	runnum=atoi(argv[1]);//run number;
	*/
	// filename for input/output file
	TString DataPath, OutPath, infile, outfile;
	DataPath = "/home/data/data/RIBLL_DATA/script/alphasource/"; 
        OutPath="./";
	//infile.Form("%srunmust200%2d.root",DataPath.Data(),runnum);//input file
	infile.Form("%sdata.root",DataPath.Data());//input file
	outfile.Form("dssd.root");//output file
        
	//open input file and get the pointer of the tree.
	TFile *ipf=new TFile(infile);
	if(!ipf->IsOpen()) {
	  cout<<"cannot open input file:"<<infile<<endl;
	  return 1;
	}
	TTree *ipt=(TTree*)ipf->Get("tree");
	if(ipt==0){
	  cout<<"cannot find input tree!"<<endl;
	  return 1;
	}
	//set open output file and create new tree.
	//TFile *opf=new TFile(outfile,"RECREATE");
	//TTree *opt=new TTree("tree","tree");

	dssd *pc=new dssd(ipt);//pass input tree 	
    //pc->Loop();

  pc->createHisto(ipt);
  ipt->SetBranchStatus("*",0);
  ipt->SetBranchStatus("adc",1);
  pc->project(ipt);
  pc->fitpeak();
  pc->record();

  pc->Loop();

	//opt->Write();//write to the output file
  //  opf->Close();//close the output file
	return 1;
}

