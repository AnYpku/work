#include "hltGenTree.C"
//#include "hlt.C"
#include <iostream>
#include <fstream>
using namespace std;

void runxx(int a) {
    TString dir ="/Users/andy/work/cms/egamma/Egamma/rootfiles/";
    ifstream infile("file");
    string buffer; 
    TString name;

    int k=1;

    while (k>0){
        getline (infile, buffer) ;
        name = buffer;
        if(name.Contains("0")==0) {k=-2; continue;}
        TString inname="zToEE_M_" +name+"_102X_TrigNtup.root";
//        TString outname=name+"_endcap_";
//        TString outname=name+"_barrel_";
        TString outname=name+"_";

        cout<<inname<<endl;
        cout<<outname<<endl;

        TFile *file1 =new TFile(dir+inname);
        TTree *tree1 = (TTree*) file1->Get("hltGenTree");
        hltGenTree m1(tree1);
        cout<<outname<<endl;
        m1.Loop(outname,a);
        m1.endJob(inname,a);

    }
}

int main(){
    for(int j=0;j<6;j++){
           runxx(j);
    }
//runxx(3,4);
	return 1;
}

