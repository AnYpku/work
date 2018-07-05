#include "/home/data/students2018/SongYunxuan/.useful.h"
//#include "/Users/songyx/work/useful.h"
void choose(){

  auto f1=new TFile("/home/data/MUST2@BigRIPS/runmust20092.root");
  auto t1=(TTree*)f1->Get("t1");
  auto number = t1->GetEntries();

  cout<<"number of entries = "<<number<<endl;
  
  Int_t cut_1=1;//cut the event which only one ppac has one signal(include zero signal)
  
  auto f2=new TFile("choose.root","RECREATE");
  auto t2=new TTree("tree","tree");

  //TBranch        *b_PPACF8;   //!
  Float_t         PPACF8[5][5];
  Float_t         PPAC[5][5];
  Float_t         OK[6];

  t1->SetBranchAddress("PPACF8", PPACF8);//, &b_PPACF8);

  t2->Branch("PPAC",&PPAC,"PPAC[5][5]/F");
  t2->Branch("OK",&OK,"OK[6]/F");

  Int_t x_down=-150;
  Int_t x_up  =150;
  Int_t y_down=-150;
  Int_t y_up  =150;

  auto *h1a=new TH2D("h1a","",100,x_down,x_up,100,y_down,y_up);
  auto *h1b=new TH2D("h1b","",100,x_down,x_up,100,y_down,y_up);
  auto *h2a=new TH2D("h2a","",100,x_down,x_up,100,y_down,y_up);
  auto *h2b=new TH2D("h2b","",100,x_down,x_up,100,y_down,y_up);
  auto *h3 =new TH2D("h3"," ",100,x_down,x_up,100,y_down,y_up);
  Int_t aaa=0;
  for(auto i=0;i<number;i++){
      t1->GetEntry(i);
      if(cut_1==1){
        Int_t ok1a=0;Int_t ok1b=0;Int_t ok2a=0;Int_t ok2b=0;Int_t ok3=0;
        if((TMath::Abs(PPACF8[0][0])<=500)&&(TMath::Abs(PPACF8[0][1])<=500))ok1a=1;OK[0]=ok1a;
        if((TMath::Abs(PPACF8[1][0])<=500)&&(TMath::Abs(PPACF8[1][1])<=500))ok1b=1;OK[1]=ok1b;
        if((TMath::Abs(PPACF8[2][0])<=500)&&(TMath::Abs(PPACF8[2][1])<=500))ok2a=1;OK[2]=ok2a;
        if((TMath::Abs(PPACF8[3][0])<=500)&&(TMath::Abs(PPACF8[3][1])<=500))ok2b=1;OK[3]=ok2b;
        if((TMath::Abs(PPACF8[4][0])<=500)&&(TMath::Abs(PPACF8[4][1])<=500))ok3=1; OK[4]=ok3;
        OK[5]=ok1a+ok1b+ok2a+ok2b+ok3;
        if(ok1a+ok1b+ok2a+ok2b==0)continue;//1 2 bad
        if(ok1a+ok1b+ok3==0)continue;      //1 3 bad 
        if(ok2a+ok2b+ok3==0)continue;      //2 3 bad
        if(ok1a+ok1b+ok2a+ok2b+ok3<=3)continue;
        }
        aaa=aaa+1;
        for(Int_t j=0;j<5;j++){
          for(Int_t k=0;k<5;k++){
          PPAC[j][k]=PPACF8[j][k];
          }
        }
        h1a->Fill(PPAC[0][0],PPAC[0][1]);
        h1b->Fill(PPAC[1][0],PPAC[1][1]);
        h2a->Fill(PPAC[2][0],PPAC[2][1]);
        h2b->Fill(PPAC[3][0],PPAC[3][1]);
         h3->Fill(PPAC[4][0],PPAC[4][1]);
        t2->Fill();
    }
    std::cout<<aaa<<std::endl;

    TCanvas *c1=new TCanvas();
    c1->Divide(3,2);
    c1->cd(1);h1a->Draw("colz");txt(0.15,0.8,Form("PPAC1a)"));drawpave(-120,-75,120,75,1);
    c1->cd(2);h1b->Draw("colz");txt(0.15,0.8,Form("PPAC1b)"));drawpave(-120,-75,120,75,1);
    c1->cd(3);h2a->Draw("colz");txt(0.15,0.8,Form("PPAC2a)"));drawpave(-120,-75,120,75,1);
    c1->cd(4);h2b->Draw("colz");txt(0.15,0.8,Form("PPAC2b)"));drawpave(-120,-75,120,75,1);
    c1->cd(5);h3->Draw("colz");txt(0.15,0.8,Form("PPAC3)"));drawpave(-50,-50,50,50,1);
    c1->Write();  
    t2->Write();
  //f2->Close();
}

