void calculate(Double_t lowpt,Double_t highpt,Double_t lowchiso,Double_t highchiso);
void run_calculate(Int_t a);
TString rootfiles="data_sieiecut";
TString b="sieiecut";
ofstream file(b+"_closure_True.txt");
ofstream file1(b+"_closure_Fake.txt");
ofstream file2(b+"_Fakefraction.txt");
ofstream file3(b+"_total.txt");
void calculate(Double_t lowpt,Double_t highpt,Double_t lowchiso,Double_t highchiso){
    ifstream f1,f2,f3,f4,f5;

    f1.open(Form(b+"truenumber_pt%0.f-%0.f.txt",lowpt,highpt));
    if(!f1.is_open()){cout<<"can not open the file";}
    
    Double_t selectTrue_number,TrueNumber,fitTrue_number,fitTrue_error,ptlow,pthigh,selectFake_number,FakeNumber,fitFake_number,fitFake_error,chisolow,chisohigh,selectData_number,fit_fakerate,fit_fakerateErr;
    f1>>ptlow>>pthigh>>selectTrue_number>>TrueNumber;
    cout<<"pt range"<<ptlow<<" ~ "<<pthigh<<"  "<<"chiso range"<<lowchiso<<" ~ "<<highchiso<<endl;
    cout<<"selectTrue_number"<<selectTrue_number<<endl;
    
    f2.open(Form("TrueNumber_pt%0.f-%0.f_chiso%0.f-%0.f.txt",lowpt,highpt,lowchiso,highchiso));
    if(!f2.is_open()){cout<<"can not open the file";}
    f2>>fitTrue_number>>fitTrue_error;
    cout<<"fitTrue_number "<<fitTrue_number<<" "<<"fitTrue_error"<<fitTrue_error<<endl;
    Double_t closureTrue_test = TMath::Abs((TrueNumber - fitTrue_number)/fitTrue_error);
    file<<Form("%0.f  <pt<%0.f ",lowpt,highpt)<<"\t"<<Form("%0.f<chiso range<%0.f ",lowchiso,highchiso)<<"\t"<<TrueNumber<<"\t"<<fitTrue_number<<"\t"<<fitTrue_error<<"\t"<<closureTrue_test<<endl;
    cout<<"the value of closure is "<<closureTrue_test<<endl;
    
    f3.open(Form(b+"mfakenumber_pt%0.f-%0.f_chiso%0.f-%0.f.txt",lowpt,highpt,lowchiso,highchiso));
    if(!f3.is_open()){cout<<"can not open the file";}
    f3>>ptlow>>pthigh>>chisolow>>chisohigh>>FakeNumber>>selectFake_number;
    cout<<"selectFake_number"<<selectFake_number;
    cout<<" FakeNumber"<<FakeNumber<<endl;

    f4.open(Form("FakeNumber_pt%0.f-%0.f_chiso%0.f-%0.f.txt",lowpt,highpt,lowchiso,highchiso));
    if(!f4.is_open()){cout<<"can not open the file";}
    f4>>fitFake_number>>fitFake_error>>fit_fakerate>>fit_fakerateErr;
    
    Double_t closureFake_test = TMath::Abs((FakeNumber - fitFake_number)/fitFake_error);
    file1<<Form("%0.f <pt<%0.f ",lowpt,highpt)<<"\t"<<Form("%0.f<chiso range<%0.f ",lowchiso,highchiso)<<"\t"<<FakeNumber<<"\t"<<fitFake_number<<"\t"<<fitFake_error<<"\t"<<closureFake_test<<endl;
    f5.open(Form(b+"datanumber_pt%0.f-%0.f.txt",lowpt,highpt));
    if(!f5.is_open()){cout<<"can not open the file";}
    f5>>ptlow>>pthigh>>selectData_number;
    Double_t fake_fraction=FakeNumber/selectData_number;
    file2<<Form("%0.f <pt<%0.f ",lowpt,highpt)<<"\t"<<Form("%0.f<chiso range<%0.f ",lowchiso,highchiso)<<"\t"<<selectData_number<<"\t"<<FakeNumber<<"\t"<<fake_fraction<<"\t"<<fit_fakerate<<"\t"<<fit_fakerateErr<<"\t"<<TMath::Abs((fake_fraction - fit_fakerate)/fit_fakerateErr)<<endl;
    file3<<Form("%0.f <pt<%0.f ",lowpt,highpt)<<"\t"<<Form("%0.f<chiso range<%0.f ",lowchiso,highchiso)<<"\t"<<selectData_number<<"\t"<<FakeNumber<<"\t"<<TrueNumber<<"\t"<<fitFake_number<<"\t"<<fitTrue_number<<"\t"<<closureFake_test<<"\t"<<closureTrue_test<<endl;
 }  
 void run_calculate(Int_t a,Int_t b){
     Double_t lowchiso[10]={2,3,4,5,6,4,4,6,8,5};
     Double_t highchiso[10]={4,5,6,7,8,9,10,10,10,12};
     Double_t lowpt[7] ={25,30,35,40,50,65,100};
     Double_t highpt[7]={30,35,40,50,65,100,400};
     calculate(lowpt[a],highpt[a],lowchiso[b],highchiso[b]);
 }

int main(){
    file<<"pt range"<<"\t"<<"chiso range"<<"\t"<<"TrueNumber"<<"\t"<<"fitTrue_number"<<"\t"<<"fitTrue_error"<<"\t"<<"closureTrue_test"<<endl;
    file<<"#######################################################################################"<<endl;    
    file1<<"pt range"<<"\t"<<"chiso range"<<"\t"<<"FakeNumber"<<"\t"<<"fitFake_number"<<"\t"<<"fitFake_Err"<<"\t"<<"closure"<<endl;
    file1<<"#######################################################################################"<<endl;    
    file2<<"pt range"<<"\t"<<"chiso range"<<"\t"<<"DataNumber"<<"\t"<<"FakeNumber"<<"\t"<<"fake_fraction"<<"\t"<<"fit_fakerate"<<"\t"<<"fit_fakerateErr"<<"\t"<<"closure"<<endl;
    file2<<"#######################################################################################"<<endl;    
    file3<<"pt range"<<"\t"<<"chiso range"<<"\t"<<"DataNumber"<<"\t"<<"FakeNumber"<<"\t"<<"TrueNumber"<<"\t"<<"fitFake_number"<<"\t"<<"fitTrue_number"<<"\t"<<"closureFake_test"<<"\t"<<"closureTrue_test"<<endl;
  file3<<"#######################################################################################"<<endl;    
  for(Int_t i=0;i<7;i++){
      for(Int_t j=0;j<10;j++){
         run_calculate(i,j);
       }
  file<<"#######################################################################################"<<endl;    
  file1<<"#######################################################################################"<<endl;    
  file2<<"#######################################################################################"<<endl;    
  file3<<"#######################################################################################"<<endl;    
   }
  return 0; 
}


