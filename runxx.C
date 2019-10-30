#include "rm.C"
#include <fstream>
void runxx() {
  TFile*file = new TFile("/home/pku/anying/cms/file_in_cms/files_weighted/outZA-EWK.root");
  TTree*tree=(TTree*)file->Get("demo");
  cout<<"OK"<<endl;

  rm m1(tree);
  cout<<"OK"<<endl;
  m1.Loop();

}

int main(){
	runxx();
	return 1;
}

