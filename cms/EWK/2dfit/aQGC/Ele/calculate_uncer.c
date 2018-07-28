const char *name[6]={"Za 100~250","Za 250~350","Za 350~400","Za 400~600","Za 600~infi"};
void open(Int_t i);
Int_t p=5;//the amount of bin
Int_t histo_number=6;//the histo_number equals the amount of pdf except the central value
Double_t central_value[5],nlo_value[6][5];//[the amount of pdf][the amout of bin]
ofstream f1("./uncertainty-ele.txt");
ofstream f2("./uncertaintymm-ele.txt");
vector<Double_t> vector_nlo,vector_center;
vector<Double_t>:: iterator biggest_nlo;
vector<Double_t>:: iterator smallest_nlo;
Double_t biggest[5],smallest[5];
void open(Int_t i){
    ifstream file(Form("./content_th%daQGC",i-1));
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
     
 
int calculate_uncer(){
    gStyle->SetOptStat(0);
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
   cout<<j <<" bin "<<"; biggest = "<<biggest[j]<<"; smallest = "<<*smallest_nlo<<"; 2*central value = "<<2*central_value[j]<<endl;
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
         uncertainty[j]=sqrt(average)/mean;
         }
      }
    uncertainty_other[j]=(biggest[j]-smallest[j])/(2*central_value[j]);
//  cout<<"bin "<<j+1<<"; mean = "<<mean<<endl;
//  cout<<"bin "<<j+1<<"; sum = "<<sum<<endl;
//    cout<<"bin "<<j+1<<"; uncertainty["<<j<<"] = "<<uncertainty[j]<<endl;
    cout<<"bin "<<j+1<<"; uncertainty_other["<<j<<"] = "<<uncertainty_other[j]<<"; uncertainty["<<j<<"] = "<<uncertainty[j]<<endl;
    f1<<"bin "<<j+1<<"; uncertainty["<<j<<"] = "<<uncertainty[j]<<endl;
    f2<<uncertainty_other[j]<<endl;
  }
Double_t ZGmass_bins[6]={150, 250, 350, 400,600,800};
TH1D* h1 =new TH1D("h1","uncertainty",5,ZGmass_bins);
TH1D* h2 =new TH1D("h2","",5,ZGmass_bins);
TCanvas* can = new TCanvas("can","uncertainty",900,600);
can->SetGrid();
TLegend* l1 = new TLegend(0.65,0.8,0.75,0.9);
for(Int_t i=0;i<p;i++){
    h2->SetBinContent(i+1,uncertainty[i]);
    h1->SetBinContent(i+1,uncertainty_other[i]);
    h1->GetXaxis()->SetBinLabel(i+1,name[i]);
  }
    h1->SetTitle("uncertainty;;uncertainty");
    h1->GetYaxis()->CenterTitle();
    h1->GetYaxis()->SetRangeUser(0.1,0.4);
    h1->GetYaxis()->SetTitleFont(22);
    h1->GetYaxis()->SetLabelFont(32);
    h1->GetYaxis()->SetLabelSize(0.05);
    h1->GetYaxis()->SetTitleSize(0.06);
    h1->GetYaxis()->SetTitleOffset(0.85);
    h1->GetXaxis()->SetTitle("Z+#gamma mass/GeV/c^{2}");
    h1->GetXaxis()->CenterTitle();
    h1->GetXaxis()->SetTitleFont(22);
    h1->GetXaxis()->SetTitleOffset(0.8);
    h1->GetXaxis()->SetTitleSize(0.05);
    h1->GetXaxis()->SetLabelSize(0.05);
    h1->GetXaxis()->SetLabelFont(32);
    h1->SetMarkerStyle(29);
    h1->SetMarkerColor(kRed);
    h1->SetMarkerSize(1.5);
    h2->SetMarkerStyle(22);
    h2->SetMarkerSize(1.5);
    l1->AddEntry(h1," ");
    l1->AddEntry(h2," ");
    h1->Draw("P");
    h2->Draw("P same");
//l1->Draw();

return 0;
}

