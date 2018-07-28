using namespace RooFit;
void higgs(){
ifstream file("Hgg.txt");
TString buffer;
std::strstream ss;
Double_t data;
int k=1,i=0;
TH1D* h1 = new TH1D("h1","Higgs mass",100,100,200);
while(k>0){
getline(file,buffer);
ss<<buffer;
ss>>data;
h1->Fill(data);
i++;
}
cout<<"i = "<<i<<endl;
h1->Draw("P");
}
