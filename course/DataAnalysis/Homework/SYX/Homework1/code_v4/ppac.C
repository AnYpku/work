#define ppac_cxx
#include "ppac.h"
//#include "/Users/songyx/work/useful.h"
#include "/home/data/students2018/SongYunxuan/useful.h"
void ppac::Loop()
{

   auto f2=new TFile("target.root","RECREATE");
   auto t2=new TTree("Tree","Tree");
   t2->Branch("PPAC",&PPAC,"PPAC[5][5]/F");
   t2->Branch("OK",&OK,"OK[6]/F");
   Int_t cut_1=1;//cut button
   if (fChain == 0) return;
   Int_t x_down=-150;
   Int_t x_up  =150;
   Int_t y_down=-150;
   Int_t y_up  =150;
 /////////////////5 PPAC face/////////
   auto h1a  =new TH2D("h1a","",100,x_down,x_up,100,y_down,y_up);
   auto h1b  =new TH2D("h1b","",100,x_down,x_up,100,y_down,y_up);
   auto h2a  =new TH2D("h2a","",100,x_down,x_up,100,y_down,y_up);
   auto h2b  =new TH2D("h2b","",100,x_down,x_up,100,y_down,y_up);
   auto h3   =new TH2D("h3"," ",100,x_down,x_up,100,y_down,y_up);
   auto htar =new TH2D("h"  ,"",100,-60,60,100,-60,60);//200


   TF1 *fzx =new TF1("fzx","[0]*x+[1]",-2000,2000);
   fzx->SetParameters(0,1);

   TF1 *fzy=new TF1("fzy","[0]*x+[1]",-2000,2000);
   fzy->SetParameters(1,1);

   Long64_t nentries = fChain->GetEntriesFast();
  Float_t a,b,c,d;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
        
        if(cut_1==1){
        Int_t ok1a=0;Int_t ok1b=0;Int_t ok2a=0;Int_t ok2b=0;Int_t ok3=0;
        if((TMath::Abs(PPACF8[0][0])<=120)&&(TMath::Abs(PPACF8[0][1])<=75))ok1a=1;OK[0]=ok1a;
        if((TMath::Abs(PPACF8[1][0])<=120)&&(TMath::Abs(PPACF8[1][1])<=75))ok1b=1;OK[1]=ok1b;
        if((TMath::Abs(PPACF8[2][0])<=120)&&(TMath::Abs(PPACF8[2][1])<=75))ok2a=1;OK[2]=ok2a;
        if((TMath::Abs(PPACF8[3][0])<=120)&&(TMath::Abs(PPACF8[3][1])<=75))ok2b=1;OK[3]=ok2b;
        if((TMath::Abs(PPACF8[4][0])<=50 )&&(TMath::Abs(PPACF8[4][1])<=50))ok3=1; OK[4]=ok3;
        OK[5]=ok1a+ok1b+ok2a+ok2b+ok3;
        if(ok1a+ok1b+ok2a+ok2b==0)continue;//1 2 bad
        if(ok1a+ok1b+ok3==0)continue;      //1 3 bad 
        if(ok2a+ok2b+ok3==0)continue;      //2 3 bad
        if(OK[5]<=1)continue;              //2 Good or more
        }
        TGraph *gzx =new TGraph(OK[5]);  
        TGraph *gzy =new TGraph(OK[5]);
        //aaa=aaa+1;
        for(Int_t j=0;j<5;j++){
          for(Int_t k=0;k<5;k++){
          PPAC[j][k]=PPACF8[j][k];//j-> 
          }
          if(OK[j]==1){
	        gzx->SetPoint(j,PPACF8[j][2],PPACF8[j][0]);//j->event i 第几块板
          gzy->SetPoint(j,PPACF8[j][3],PPACF8[j][1]);//
          }
        }
      	gzx->SetMarkerStyle(20);
      	gzx->Fit(fzx); 

      	gzy->SetMarkerStyle(22);
      	gzy->Fit(fzy); 
    

        a=fzx->GetParameter(0);
        b=fzx->GetParameter(1);
        X=a*ZZ+b;

        c=fzy->GetParameter(0);
        d=fzy->GetParameter(1);
        Y=c*ZZ+d;
        Y=Y*(TMath::Sqrt(2));//旋转45度

      	htar->Fill(X,Y);
      	if((TMath::Abs(X)<20)&&(TMath::Abs(Y)<12.5))num=num+1;
      	delete gzx;
      	delete gzy;

        h1a->Fill(PPAC[0][0],PPAC[0][1]);
        h1b->Fill(PPAC[1][0],PPAC[1][1]);
        h2a->Fill(PPAC[2][0],PPAC[2][1]);
        h2b->Fill(PPAC[3][0],PPAC[3][1]);
        h3->Fill(PPAC[4][0],PPAC[4][1]);
        t2->Fill();
      }
    TCanvas *c1=new TCanvas();
    c1->Divide(3,2);
    c1->cd(1);h1a->Draw("colz");txt(0.15,0.8,Form("PPAC1a)"));drawpave(-120,-75,120,75,1);
    c1->cd(2);h1b->Draw("colz");txt(0.15,0.8,Form("PPAC1b)"));drawpave(-120,-75,120,75,1);
    c1->cd(3);h2a->Draw("colz");txt(0.15,0.8,Form("PPAC2a)"));drawpave(-120,-75,120,75,1);
    c1->cd(4);h2b->Draw("colz");txt(0.15,0.8,Form("PPAC2b)"));drawpave(-120,-75,120,75,1);
    c1->cd(5);h3->Draw("colz");txt(0.15,0.8,Form("PPAC3)"));drawpave(-50,-50,50,50,1);
    c1->Write();  
    
    TCanvas *c2 =new TCanvas("c2","c2",0,0,900,900);
    htar->Draw("colz");
    gPad->SetLogz(1);
    //txt(0.15,0.8,Form("4 Good  with selection"));//2      3     4      5
    drawpave(-20,-12.5,20,12.5,1);            //my 0.852 0.808 0.565  0.154
    c2->Write();                             //new 0.714 0.670 0.444  0.116  
    num=num/341933;
    cout<<num<<endl;
    t2->Write();
    f2->Write();
    f2->Close();
      delete fzx;
      delete fzy;

}
