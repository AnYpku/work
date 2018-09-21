#include "xx.C"
#include <iostream>
#include <fstream>
using namespace std;

void runxx() {
TString dir="/eos/user/y/yian/fnal/";
ifstream infile("file_root");
string buffer;
TString infilename;

int k=1;

while (k>0){
getline (infile, buffer) ;
infilename = buffer;
if(infilename.Contains(".root")==0) {k=-2; continue;}
TString outname="cutLEP-"+infilename;

cout<<outname<<endl;

TFile *file1 =new TFile(dir+infilename);
TTree *tree1 = (TTree*) file1->Get("demo");
xx m1(tree1,outname);
cout<<outname<<endl;
m1.Loop();
m1.endJob();

}
}

int main(){
    runxx();
    return 1;
  }
