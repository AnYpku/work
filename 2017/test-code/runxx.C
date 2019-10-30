#include "com.C"
#include <iostream>
#include <fstream>
using namespace std;

void runxx() {
//TString dir ="/eos/uscms/store/user/qliphy/andy/2017/cutlep/";
TString dir = "./";
ifstream infile("file");
string buffer; 
TString infilename;

int k=1;

while (k>0){
getline (infile, buffer) ;
infilename = buffer;
if(infilename.Contains("end")==1) {k=-2; continue;}
TString inname="cutla-out"+infilename+".root";

cout<<inname<<endl;

TFile *file1 =new TFile(dir+inname);
TTree *tree1 = (TTree*) file1->Get("demo");
com m1(tree1);
m1.Loop(infilename,"massVlep");

//cout<<ratio<<endl;
}
}

int main(){
	runxx();
	return 1;
}

