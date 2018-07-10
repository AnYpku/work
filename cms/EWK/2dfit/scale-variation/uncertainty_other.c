void open(Int_t i);
Int_t p=9;//the amount of bin
Int_t histo_number=8;//the histo_number equals the amount of pdf except the central value
Double_t central_value[9],nlo_value[8][9];//[the amount of pdf][the amout of bin]
ofstream f1("./uncertainty-other.txt");
vector<Double_t> vector_nlo,vector_center;
vector<Double_t>:: iterator biggest_nlo;
vector<Double_t>:: iterator smallest_nlo;
Double_t biggest[9],smallest[9];
void open(Int_t i){
    ifstream file(Form("./scale-txt/content-hist_%d",i));
    if(!file.is_open()){cout<<"can not open the "<<i<<" file"<<endl;   }
    for(Int_t j=0;j<p;j++){
       if(i==1){
         file>>central_value[j];
         cout<<"histo "<<i<<"; bin"<<j+1<<"; central_value = "<<central_value[j]<<endl;  }
       if(i>1){
          file>>nlo_value[i-2][j];
          cout<<"hist "<<i<<"; bin"<<j<<"; nlo_value = "<<nlo_value[i-2][j]<<endl;
          //nlo_value[i][j]代表第几个histo的第几个bin的值
         }
      }

 }
     
 
int uncertainty_other(){
for(Int_t i=1;i<=histo_number+1;i++){
   open(i);
   //对于第j个bin，把每个histo的bincontent输出
   cout<<"*****************************"<<endl;
  }
for(Int_t j=0;j<p;j++){
   for(Int_t i=0;i<histo_number;i++){
        vector_nlo.push_back(nlo_value[i][j]);
       }
   biggest_nlo = max_element(begin(vector_nlo),end(vector_nlo));
   smallest_nlo = min_element(begin(vector_nlo),end(vector_nlo));
   biggest[j]=*biggest_nlo;
   smallest[j]=*smallest_nlo;
   cout<<j <<" bin "<<"; biggest = "<<biggest[j]<<"; smallest = "<<*smallest_nlo<<";central value = "<<central_value[j]<<endl;
   vector_nlo.clear();
   cout<<"*****************************"<<endl;
  }
Double_t single,sum,average,uncertainty[p],mean=0,uncertainty_other[p];
for(Int_t j=0;j<p;j++){
  sum=0;
  mean=0;
  for(Int_t i=0;i<histo_number;i++){
      single = pow(nlo_value[i][j]-central_value[j],2);
      sum = sum+single;
      mean = (mean + nlo_value[i][j]);
      if(i==histo_number-1){
         mean = (mean + central_value[j])/(histo_number+1);
         average = sum/histo_number;
         uncertainty[j]=sqrt(sum/8)/mean;
         }
      }
    uncertainty_other[j]=(biggest[j]-smallest[j])/(2*central_value[j]);
//  cout<<"bin "<<j+1<<"; mean = "<<mean<<endl;
//  cout<<"bin "<<j+1<<"; sum = "<<sum<<endl;
//    cout<<"bin "<<j+1<<"; uncertainty["<<j<<"] = "<<uncertainty[j]<<endl;
    cout<<"bin "<<j+1<<"; uncertainty_other["<<j<<"] = "<<uncertainty_other[j]<<endl;
    f1<<"bin "<<j+1<<"; uncertainty["<<j<<"] = "<<uncertainty[j]<<endl;
  }



return 0;
}

