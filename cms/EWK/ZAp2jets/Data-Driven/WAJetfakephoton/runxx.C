#include "MakeTemplate.C"
#include <iostream>
#include <fstream>
using namespace std;

void runxx() {
TString dir="/data/pku/home/anying/cms/file_in_cms/files_weighted/";
ifstream infile("file");
string buffer;
TString name;
TString sss;

int k=2;

   while(k>0){
      getline (infile, buffer) ;
      name = buffer;
      if(name.Contains("out")){ 
         TString filename= name+".root";
         cout<<name<<endl;
         sss=filename;
         TFile *file1 =new TFile(dir+filename);
         TTree *tree1 = (TTree*) file1->Get("demo");
         MakeTemplate m1(tree1);
         cout<<filename<<endl;
         m1.Loop(name);
         m1.endJob(name);
        }
      if(name.Contains("end")){
         k=-2;continue;
       }
    }
 }
int main(){
    runxx();
    return 1;
  }
