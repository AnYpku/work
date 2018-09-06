TString bb="0509data_all";
void style();
void histo();
void select(TTree *tree,TH1D *h1,TH1D *h2[10],TH1D *h3,Double_t lowpt,Double_t highpt);
void draw(TCanvas *c,TH1D *h1,TH1D *h2[10],TH1D *h3,Double_t lowpt,Double_t highpt);
void creatfiles(Double_t lowpt,Double_t highpt);
 //the needed variables in the root file
 Double_t ptlep1,ptlep2,etalep1,etalep2,massVlep;
 Double_t scalef;
 Int_t nlooseeles,nloosemus;
 Double_t photon_drla[6],photon_pt[6],photon_drla2[6],photon_sieie[6],photon_chiso[6];
 double photon_hoe[6];
 double photon_nhiso[6];
 double photon_phoiso[6];
 double photon_eta[6];
 int photon_isprompt[6];
 bool Zjets[6],Leading_photon[6],medium_cut[6],loose_cut[6];
 vector<double> vector_pt;
 vector<double>::iterator biggest_pt;
 Int_t position=0,size,m=0;
 Double_t m1,m2[10],m3;
 Int_t nentries;

 Double_t lowchiso[10],highchiso[10];
 TH1D* h11;
 TH1D* h21;
 TH1D* h31;
 TH1D* h12[10];
 TH1D* h22[10];
 TH1D* h32;
 TH1D* h13;
 TH1D* h23;
 TH1D* h33;
// TCanvas *c1;
// TFile *f1;
// TFile *f2;
// TTree *t1;
// TTree *t2;

void style(){
 gStyle->SetOptStat(0);
 gStyle->SetPadGridX(1);
 gStyle->SetPadGridY(1);
 gStyle->SetPadTickX(1);
 gStyle->SetPadTickY(1);
 gStyle->SetAxisColor(1, "XYZ");
 gStyle->SetStripDecimals(kTRUE);
 gStyle->SetTickLength(0.03, "XYZ");
 }
void histo(){
 Int_t bin=20;
 Double_t xlow= 0.;
 Double_t xhigh= 0.02;
  h11=new TH1D("h11","chiso<0.441",bin,0,xhigh);//Zjets && leding_photon && medium_cut && photon_chiso<1.416
  h13=new TH1D("h13","",bin,0,xhigh);////Zjets && leding_photon && medium_cut && photon_chiso>2
  h21=new TH1D("h21","chiso<0.441",bin,0,xhigh);//Zjets && leding_photon && medium_cut && photon_chiso<1.416
  h23=new TH1D("h23","",bin,0,xhigh);////Zjets && leding_photon && medium_cut && photon_chiso>2
  for(Int_t i=0;i<10;i++){
      h12[i]=new TH1D(Form("h12_chiso%0.f-%0.f",lowchiso[i],highchiso[i]),Form("%0.f>chiso>%0.f",highchiso[i],lowchiso[i]),bin,0,xhigh);////Zjets && leding_photon && medium_cut && photon_chiso>2
      h22[i]=new TH1D(Form("h22%0.f-%0.f",lowchiso[i],highchiso[i]),Form("%0.f>chiso>%0.f",highchiso[i],lowchiso[i]),bin,0,xhigh);////Zjets && leding_photon && medium_cut && photon_chiso>2
  }  
  h31=new TH1D("h31","10>chiso>4",bin,0,xhigh);////Zjets && leding_photon && medium_cut && photon_chiso>2
  h32=new TH1D("h32","",bin,0,xhigh);////Zjets && leding_photon && medium_cut && photon_chiso>2
  h33=new TH1D("h33","",bin,0,xhigh);////Zjets && leding_photon && medium_cut && photon_chiso>2
}

void select(TTree *tree,TH1D *h1,TH1D *h2[10],TH1D *h3,Double_t lowpt,Double_t highpt){
 tree->SetBranchAddress("photon_hoe",photon_hoe);
 tree->SetBranchAddress("photon_nhiso",photon_nhiso);
 tree->SetBranchAddress("photon_phoiso",photon_phoiso);
 tree->SetBranchAddress("photon_pt",photon_pt);
 tree->SetBranchAddress("photon_eta",photon_eta);
 tree->SetBranchAddress("scalef",&scalef);
 tree->SetBranchAddress("nloosemus",&nloosemus);
 tree->SetBranchAddress("nlooseeles",&nlooseeles);
 tree->SetBranchAddress("ptlep1",&ptlep1);
 tree->SetBranchAddress("ptlep2",&ptlep2);
 tree->SetBranchAddress("etalep1",&etalep1);
 tree->SetBranchAddress("etalep2",&etalep2);
 tree->SetBranchAddress("massVlep",&massVlep);
 tree->SetBranchAddress("photon_isprompt",photon_isprompt);
 tree->SetBranchAddress("photon_drla",photon_drla);
 tree->SetBranchAddress("photon_drla2",photon_drla2);
 tree->SetBranchAddress("photon_sieie",photon_sieie);
 tree->SetBranchAddress("photon_chiso",photon_chiso);
 tree->SetBranchAddress("photon_pt",photon_pt);
 nentries = tree->GetEntries();
// cout<<"nentries = "<<nentries<<endl;
// nentries=10000;
 m1=0;m3=0;
 for(Int_t i=0;i<10;i++){m2[i]=0;}
 for(Int_t i=0;i<nentries;i++){
    tree->GetEntry(i);
    for(Int_t j=0;j<6;j++){
         Zjets[j] = ptlep1 > 20. && ptlep2 > 20.&& abs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep >70. && massVlep < 110;
         Leading_photon[j]= photon_drla[j]>0.7 && photon_drla2[j]>0.7&&photon_pt[j]<highpt &&photon_pt[j]>lowpt;
         medium_cut[j]= photon_hoe[j]<0.0396  && photon_nhiso[j]<2.725 + 0.0148*photon_pt[j] + 0.000017*photon_pt[j]*photon_pt[j] && photon_phoiso[j]<2.571 + 0.0047*photon_pt[j]&&abs(photon_eta[j])<1.4442;
         if(Zjets[j]&&Leading_photon[j]&&medium_cut[j]){
            vector_pt.push_back(photon_pt[j]);}
         else {vector_pt.push_back(0);}
      }//fill the vector_pt
   size=vector_pt.size();
   biggest_pt = max_element(begin(vector_pt),end(vector_pt));
   if(*biggest_pt==0){
       vector_pt.clear();
       continue;}
//   cout<<"the biggest pt"<<*biggest_pt<<endl;
   position = distance( begin(vector_pt), biggest_pt);
   if(photon_chiso[position]<0.441) 
     {h1->Fill(photon_sieie[position],scalef);m1 += scalef;}//datamc
   for(Int_t j=0;j<10;j++){
//        lowchiso[j] =2+j;
//        highchiso[j]=4+j;
//      if(highchiso[j]>10&&highchiso[j]<13) {highchiso[j]=10;}
//      if(highchiso[j]==13)                 {highchiso[j]=12;}
//      if(lowchiso[j]==7||lowchiso[j]==8)      {lowchiso[j]=4;}
//      if(lowchiso[j]==9)                   {lowchiso[j]=6;}
//      if(lowchiso[j]==10)                  {lowchiso[j]=8;}
//      if(lowchiso[j]==11)                  {lowchiso[j]=5;}
      if(photon_chiso[position]>lowchiso[j]&&photon_chiso[position]<highchiso[j]) 
         { 
            h2[j]->Fill(photon_sieie[position],scalef);m2[j] +=scalef;
         }
      }//fake
   if(photon_isprompt[position]==1&&photon_chiso[position]<0.441) 
     {h3->Fill(photon_sieie[position],scalef);m3 +=scalef;}//real
   vector_pt.clear();
//   cout<<"i "<<i<<" size "<<size<<endl;
   }  
// cout<<"the number of gamma in mix = m1 = "<<m1<<endl;
// cout<<"the number of fake gamma in ZJ = m2 = "<<m2<<endl;
// cout<<"the number of real gamma in Za = m3 = "<<m3<<endl;
// cout<<"nentries = "<<nentries<<endl;
}

void draw(TCanvas *c,TH1D *h1,TH1D *h2[10],TH1D *h3,Double_t lowpt,Double_t highpt){
 c=new TCanvas("c","Zjets and leading photon",900,600);   
 c->SetGrid();
// c->SetLogy();
 h1->SetLineColor(51);
 h1->SetTitle(Form("Barrel Region  %0.f < photon PT <% 0.f",lowpt,highpt));
 h1->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
 h1->GetYaxis()->SetTitle("count");
 h1->SetLineStyle(1);
 h1->SetLineWidth(3);
 h1->SetFillColor(51);
 h1->SetFillStyle(3002);
 Double_t s1=1/h1->Integral();
 cout<<"s1 = "<<s1<<endl;
// h1->Scale(s1);
 Double_t s2[10];
 for(Int_t i=0;i<10;i++){
     h2[i]->SetLineStyle(2);
     h2[i]->SetLineColor(i);
     h2[i]->SetLineWidth(3);
     s2[i]=1/h2[i]->Integral();
     cout<<Form(" %0.f<photon_chiso<%0.f ",lowchiso[i],highchiso[i]);
     cout<<"  s2 = "<<s2[i]<<endl;
    // h2[i]->Draw("HIST,SAME");
    // h2->Scale(s2);
   }
 h3->SetLineStyle(3);
 Int_t ci=ci = TColor::GetColor("#3399ff");
 h3->SetLineColor(ci);
 h3->SetFillColor(ci);
 h3->SetFillStyle(3008);
 h3->SetLineWidth(3);
 Double_t s3=1/h3->Integral();
 cout<<"s3 = "<<s3<<endl;
// h3->Scale(s3);
// h1->DrawNormalized("HIST");
// h2->DrawNormalized("HIST,SAME");
// h3->DrawNormalized("HIST,SAME");
 h1->Draw("HIST");
 h2[6]->Draw("HIST,SAME");
 h3->Draw("HIST,SAME");
 TLegend *l1 = new TLegend(0.5,0.6,0.9,0.9);
 l1->AddEntry(h1,"photon_chiso<0.441 datamc #gamma" );
 for(Int_t i=0;i<10;i++){
      l1->AddEntry(h2[i],Form("%0.f<photon_chiso<%0.f  Fake #gamma",lowchiso[i],highchiso[i]) );
    } 
 l1->AddEntry(h3,"photon_chiso<0.441 Real #gamma"); 
 l1->Draw(); 
// c->Print("./"+b+"_sieie.eps");
 c->Print("./"+bb+Form("_sieiept%0.f_%0.f.eps",lowpt,highpt));
 delete c;
}
void creatfiles(Double_t lowpt,Double_t highpt){
for(Int_t j=0;j<10;j++){
     lowchiso[j] =2+j;
     highchiso[j]=4+j;
     if(highchiso[j]>10&&highchiso[j]<13) {highchiso[j]=10;}
     if(highchiso[j]==13)                 {highchiso[j]=12;}
     if(lowchiso[j]==7||lowchiso[j]==8)      {lowchiso[j]=4;}
     if(lowchiso[j]==9)                   {lowchiso[j]=6;}
     if(lowchiso[j]==10)                  {lowchiso[j]=8;}
     if(lowchiso[j]==11)                  {lowchiso[j]=5;}
   }
style();
histo();
TString b = Form("pt%0.f-%0.f",lowpt,highpt);
ofstream myfile("info_"+b+".txt");
TFile *f1 = new TFile("../rootfiles/data_all.root");     
TFile *ff1[10];
TTree *t1 =(TTree*)f1->Get("demo");
cout<<"file data_all.root"<<endl;
cout<<"pt range "<<lowpt<<" ~ "<<highpt<<endl;
select(t1,h11,h12,h13,lowpt,highpt);
cout<<"the number  m1 is in datamc"<<m1<<endl;
//myfile<<"pt range "<<lowpt<<" ~ "<<highpt<<endl;
//myfile<<"============================total photon========================="<<endl;
//myfile<<"for the mix root file "+b+".root,with photon_chiso<0.441, the number of selected total photon = "<<m1<<endl;
//myfile<<"============================fake photon========================="<<endl;
for(Int_t i=0;i<10;i++){
     ff1[i]= new TFile(Form(bb+"photonandfake_pt%0.f-%0.f_chiso%0.f-%0.f.root",lowpt,highpt,lowchiso[i],highchiso[i]),"recreate");
     h12[i]->Write();
     h11->Write();
     cout<<"the number  m2 is fake photon with ";cout<<Form(" %0.f<photon_chiso<%0.f",lowchiso[i],highchiso[i]);cout<<" = "<<m2[i]<<endl;
//   myfile<<"for the mix root file "+b+".root,with"+Form("%0.f<photon_chiso<%0.f",lowchiso[i],highchiso[i])+"the number of selected fake photon = "<<m2[i]<<endl;
//   myfile<<"============================next chiso sideban========================="<<endl;
  } 
//cout<<"succeed to fill histo h11 and h12"<<endl;
cout<<"#####################################"<<endl;
//myfile<<"####################################################################################################"<<endl;
for(Int_t i=0;i<10;i++){
ff1[i]->Close();}

TFile *f2 = new TFile("../rootfiles/outofficial_ZA.root");     
//TFile *ff2= new TFile(Form(b+"_photonreal_pt%0.f_%0.f.root",lowpt,highpt),"recreate");
TTree *t2 =(TTree*)f2->Get("demo");
cout<<"file za sample"<<endl;
cout<<"pt range "<<lowpt<<" ~ "<<highpt<<endl;
select(t2,h21,h22,h23,lowpt,highpt);
cout<<"the number m3 is real photon"<<m3<<endl;
//myfile<<"============================real photon========================="<<endl;
//myfile<<"for the ZA sample outofficial.root,with photon_chiso<0.441 and photon_isprompt=1"<<endl<<"the number of selected real photon = "<<m3<<endl;
myfile<<m3<<endl;
//cout<<"succeed to fill histo h23"<<endl;
cout<<"#####################################"<<endl;
//myfile<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
//h23->Write();
//ff2->Close();

//TFile *f3 = new TFile("../rootfiles/outZJets_FX.root");     
//TFile *ff3= new TFile(Form("photonfakept%0.f_%0.f.root",lowpt,highpt),"recreate");
//TTree *t3 =(TTree*)f1->Get("demo");
//cout<<"pt range "<<lowpt<<" ~ "<<highpt<<endl;
//select(t3,h31,h32,h33,lowpt,highpt);
//cout<<"the number  m2 is fake photon "<<endl;
TCanvas *c1=new TCanvas("c1","mediumID selection",900,600);   
draw(c1,h11,h12,h23,lowpt,highpt);
cout<<"######################################################################"<<endl;
delete c1;
delete h11;
for(Int_t i=0;i<10;i++){
   delete h12[i];
   delete h22[i];
  } 
delete h13;
delete h21;
delete h23;
delete h31;
delete h32;
delete h33;
}
int main(){
//lowchiso[10]={2,3,4,5,6,4,4,6,8,5};
//highchis[10]={4,5,6,7,8,9,10,10,10,12}
creatfiles(25,30);
creatfiles(30,35);
creatfiles(35,40);
creatfiles(40,45);
creatfiles(45,50);
creatfiles(50,60);
creatfiles(60,80);
creatfiles(80,120);
creatfiles(120,400);
creatfiles(25,400);
return 0;
}
