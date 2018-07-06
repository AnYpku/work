#include <TF1.h>
#include <TH2D.h>
#include <TGraph.h>
#include <TString.h>
#include <TStyle.h>
#include <TMath.h>
#include <TCut.h>
#include <TTree.h>
#include <TTreeFormula.h>

#include <iostream>

using namespace std;

TString infile = "/home/data/data/RIBLL_DATA/tele0300.root";
TString outfile1 = "front0300.root";
TString outfile2 = "back0300.root";
TH2D *hf[32],*hb[32]; //hf为正面归一
TGraph *gf[32],*gb[32];
TF1 *line;
Double_t kf,bf,kb,bb; 


void getHisto(TTree *tree);

int main(){
   TFile *ipf = new TFile(infile,"read"); //打开root
   if(!ipf->IsOpen()){
   cout<<"cannot open input file:"<<infile<<endl;
   return 1;}
   TTree *ipt = (TTree*)ipf->Get("tree");
   if(ipt == 0){
   cout<<"cannot find input tree!"<<endl;
   return 1;}
   


   getHisto(ipt);
  
   //正面归一
   ofstream out("fcaliPara.txt"); //front
   
   for(Int_t i=0;i<32;i++){
     ipt->Project(TString::Format("hf%d",i),TString::Format("b[15]:f[%d]",i));
     TCut c1 = Form("f[%d]>=200 && f[%d]<=3840",i,i);
     TCut c2 = "b[15]>=200";
     cout<<"front strips normalization: "<<i+1<<endl;
     cout<<"####################################"<<endl;
     //第一次cut
       // ipt->Draw("b[15]:f[0]>>hf[0](4000,0,4000,4000,0,4000)",c1 && c2,"colz");
      ipt->Draw(TString::Format("b[15]:f[%d]>>hf[%d](4000,0,4000,4000,0,4000)",i,i),c1 && c2,"colz");
      gf[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gf[i]->Draw("A*");
      Long64_t npoints = gf[i]->GetN();
      
        cout<<"first cut points="<<npoints<<endl;
        if(npoints<=50){
        cout<<"less counts!can not fit!"<<endl;
        kf=1.0;
        bf=0.0;   
        out<<kf<<"\t"<<bf<<"\t"<<endl;
        continue;}

     //第二次cut       
      TCut c3 = Form("b[15]-1.0*f[%d]<=0",i);
      TCut c4 = Form("b[15]-1.0/2*f[%d]>=0",i);
      // ipt->Draw("b[15]:f[0]>>hf[0](4000,0,4000,4000,0,4000)",c1 && c2 && c3 && c4,"colz");
      ipt->Draw(TString::Format("b[15]:f[%d]>>hf[%d](4000,0,4000,4000,0,4000)",i,i),c1 && c2 && c3 && c4,"colz");
      
      gf[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gf[i]->Draw("A*");
      npoints = gf[i]->GetN();
      cout<<"second cut points="<<npoints<<endl;
      if(npoints<=20){ 
      cout<<"less counts!can not fit!"<<endl;
      kf=1.0;
      bf=0.0;
      out<<kf<<"\t"<<bf<<"\t"<<endl;
      continue;}
      gf[i]->Fit("line","ROB");
      bf=line->GetParameter(0);
      kf=line->GetParameter(1);
     cout<<"kf="<<kf<<endl;
     cout<<"bf="<<bf<<endl;
    
     

      //第三次cut 
     c3 = Form("b[15]-%g*f[%d]-%g-200<=0",kf,i,bf);
     c4 = Form("b[15]-%g*f[%d]-%g+200>=0",kf,i,bf);
      // ipt->Draw("b[15]:f[0]>>hf[0](4000,0,4000,4000,0,4000)",c1 && c2 && c3 && c4,"colz");
      ipt->Draw(TString::Format("b[15]:f[%d]>>hf[%d](4000,0,4000,4000,0,4000)",i,i),c1 && c2 && c3 && c4,"colz");
      
      if(kf>=0.8||kf<=0.6){
      cout<<"weak correlation!can not fit!"<<endl;
      kf=1.0;
      bf=0.0;
      out<<kf<<"\t"<<bf<<"\t"<<endl;
      continue;}
      gf[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gf[i]->Draw("A*");
      npoints = gf[i]->GetN();
      cout<<"third cut points="<<npoints<<endl;
      gf[i]->Fit("line","ROB");
      bf=line->GetParameter(0);
      kf=line->GetParameter(1);
     
     cout<<"kf="<<kf<<endl;
     cout<<"bf="<<bf<<endl;
     
     //第四次cut 
     c3 = Form("b[15]-%g*f[%d]-%g-100<=0",kf,i,bf);
     c4 = Form("b[15]-%g*f[%d]-%g+100>=0",kf,i,bf);      
     // ipt->Draw("b[15]:f[0]>>hf[0](4000,0,4000,4000,0,4000)",c1 && c2 && c3 && c4,"colz");
     ipt->Draw(TString::Format("b[15]:f[%d]>>hf[%d](4000,0,4000,4000,0,4000)",i,i),c1 && c2 && c3 && c4,"colz");
      
     
      if(kf>=0.8||kf<=0.4){
      cout<<"weak correlation!can not fit!"<<endl;
      kf=1.0;
      bf=0.0;
      out<<kf<<"\t"<<bf<<"\t"<<endl;      
      continue;}
      gf[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gf[i]->Draw("A*");
      npoints = gf[i]->GetN();
      cout<<"fourth cut pointss="<<npoints<<endl;
      
      gf[i]->Fit("line","ROB");
      bf=line->GetParameter(0);
      kf=line->GetParameter(1);
    
     cout<<"kf="<<kf<<endl;
     cout<<"bf="<<bf<<endl;

     //第五次cut 
     c3 = Form("b[15]-%g*f[%d]-%g-50<=0",kf,i,bf);
     c4 = Form("b[15]-%g*f[%d]-%g+50>=0",kf,i,bf);
     // ipt->Draw("b[15]:f[0]>>hf[0](4000,0,4000,4000,0,4000)",c1 && c2 && c3 && c4,"colz");
     ipt->Draw(TString::Format("b[15]:f[%d]>>hf[%d](4000,0,4000,4000,0,4000)",i,i),c1 && c2 && c3 && c4,"colz");
     
      gf[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gf[i]->Draw("A*");

      npoints = gf[i]->GetN();
      cout<<"fifth cut points="<<npoints<<endl;
      if(npoints<6){
      cout<<"less counts!can not fit!"<<endl;
      kf=1.0;
      bf=0.0;
      out<<kf<<"\t"<<bf<<"\t"<<endl;
      continue;}
      
      gf[i]->Fit("line","ROB");
      bf=line->GetParameter(0);
      kf=line->GetParameter(1);
     
     cout<<"kf="<<kf<<endl;
     cout<<"bf="<<bf<<endl;
     
     
    
     
      out<<kf<<"\t"<<bf<<"\t"<<endl;
     }
     out.close();
     TFile *opf= new TFile(outfile1,"RECREATE");
     for(Int_t i=0;i<32;i++){
      if(gf[i]!=0) gf[i]->Write();
      if(hf[i]!=0) hf[i]->Write();}
     opf->Close();
     for(Int_t i=0;i<32;i++){
       delete gf[i];
       delete hf[i];}
     cout<<"front normalization is over"<<endl;


//背面归一
   ofstream outs("bcaliPara.txt"); //back
   
   for(Int_t i=0;i<32;i++){
     ipt->Project(TString::Format("hb%d",i),TString::Format("f[15]:b[%d]",i));
     TCut c1 = Form("b[%d]>=200 && b[%d]<=3840",i,i);
     TCut c2 = "f[15]>=200";
     cout<<"back strips normalization: "<<i+1<<endl;
     cout<<"####################################"<<endl;
     //第一次cut
       // ipt->Draw("b[15]:f[0]>>hf[0](4000,0,4000,4000,0,4000)",c1 && c2,"colz");
      ipt->Draw(TString::Format("f[15]:b[%d]>>hb[%d](4000,0,4000,4000,0,4000)",i,i),c1 && c2,"colz");
      gb[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gb[i]->Draw("A*");
      Long64_t  npoints = gb[i]->GetN();
      
        cout<<"first cut points="<<npoints<<endl;
        if(npoints<=50){
        cout<<"less counts!can not fit!"<<endl;
        kb=1.0;
        bb=0.0;   
        outs<<kb<<"\t"<<bb<<"\t"<<endl;
        continue;}

     //第二次cut       
      TCut c3 = Form("f[15]-2.0*b[%d]<=0",i);
      TCut c4 = Form("f[15]-1.0*b[%d]>=0",i);
      // ipt->Draw("b[15]:f[0]>>hf[0](4000,0,4000,4000,0,4000)",c1 && c2 && c3 && c4,"colz");
      ipt->Draw(TString::Format("f[15]:b[%d]>>hb[%d](4000,0,4000,4000,0,4000)",i,i),c1 && c2 && c3 && c4,"colz");
      
      gb[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gb[i]->Draw("A*");
      npoints = gb[i]->GetN();
      cout<<"second cut points="<<npoints<<endl;
      if(npoints<=20){ 
      cout<<"less counts!can not fit!"<<endl;
      kb=1.0;
      bb=0.0;
      outs<<kb<<"\t"<<bb<<"\t"<<endl;
      continue;}
      gb[i]->Fit("line","ROB");
      bb=line->GetParameter(0);
      kb=line->GetParameter(1);
     cout<<"kb="<<kb<<endl;
     cout<<"bb="<<bb<<endl;
    
     

      //第三次cut 
     c3 = Form("f[15]-%g*b[%d]-%g-200<=0",kb,i,bb);
     c4 = Form("f[15]-%g*b[%d]-%g+200>=0",kb,i,bb);
      // ipt->Draw("b[15]:f[0]>>hf[0](4000,0,4000,4000,0,4000)",c1 && c2 && c3 && c4,"colz");
      ipt->Draw(TString::Format("f[15]:b[%d]>>hb[%d](4000,0,4000,4000,0,4000)",i,i),c1 && c2 && c3 && c4,"colz");
      
      if(kb>=2.0||kb<=1.2){
      cout<<"weak correlation!can not fit!"<<endl;
      kb=1.0;
      bb=0.0;
      outs<<kb<<"\t"<<bb<<"\t"<<endl;
      continue;}
      gb[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gb[i]->Draw("A*");
      npoints = gb[i]->GetN();
      cout<<"third cut points="<<npoints<<endl;
      gb[i]->Fit("line","ROB");
      bb=line->GetParameter(0);
      kb=line->GetParameter(1);
     
     cout<<"kb="<<kb<<endl;
     cout<<"bb="<<bb<<endl;
     
     //第四次cut 
     c3 = Form("f[15]-%g*b[%d]-%g-100<=0",kb,i,bb);
     c4 = Form("f[15]-%g*b[%d]-%g+100>=0",kb,i,bb);      
     // ipt->Draw("b[15]:f[0]>>hf[0](4000,0,4000,4000,0,4000)",c1 && c2 && c3 && c4,"colz");
     ipt->Draw(TString::Format("f[15]:b[%d]>>hb[%d](4000,0,4000,4000,0,4000)",i,i),c1 && c2 && c3 && c4,"colz");
      
     
      if(kb>=2.0||kb<=1.2){
      cout<<"weak correlation!can not fit!"<<endl;
      kb=1.0;
      bb=0.0;
      outs<<kb<<"\t"<<bb<<"\t"<<endl;      
      continue;}
      gb[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gb[i]->Draw("A*");
      npoints = gb[i]->GetN();
      cout<<"fourth cut pointss="<<npoints<<endl;
      
      gb[i]->Fit("line","ROB");
      bb=line->GetParameter(0);
      kb=line->GetParameter(1);
    
     cout<<"kb="<<kb<<endl;
     cout<<"bb="<<bb<<endl;

     //第五次cut 
     c3 = Form("f[15]-%g*b[%d]-%g-50<=0",kb,i,bb);
     c4 = Form("f[15]-%g*b[%d]-%g+50>=0",kb,i,bb);
     // ipt->Draw("b[15]:f[0]>>hf[0](4000,0,4000,4000,0,4000)",c1 && c2 && c3 && c4,"colz");
     ipt->Draw(TString::Format("f[15]:b[%d]>>hb[%d](4000,0,4000,4000,0,4000)",i,i),c1 && c2 && c3 && c4,"colz");
     
      gb[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gb[i]->Draw("A*");

      npoints = gb[i]->GetN();
      cout<<"fifth cut points="<<npoints<<endl;
      if(npoints<6){
      cout<<"less counts!can not fit!"<<endl;
      kb=1.0;
      bb=0.0;
      outs<<kb<<"\t"<<bb<<"\t"<<endl;
      continue;}
      
      gb[i]->Fit("line","ROB");
      bb=line->GetParameter(0);
      kb=line->GetParameter(1);
     
     cout<<"kb="<<kb<<endl;
     cout<<"bb="<<bb<<endl;
     
     
    
     
      outs<<kb<<"\t"<<bb<<"\t"<<endl;
     }
     outs.close();
     TFile *opfs= new TFile(outfile2,"RECREATE");
     for(Int_t i=0;i<32;i++){
      if(gb[i]!=0) gb[i]->Write();
      if(hb[i]!=0) hb[i]->Write();}
     opfs->Close();
     for(Int_t i=0;i<32;i++){
       delete gb[i];
       delete hb[i];}
     cout<<"back normalization is over"<<endl;

     return 0;
}



void getHisto(TTree *tree){
 for(Int_t i=0;i<32;i++){
  char hfname[32];
  char hbname[32];
  sprintf(hfname,"hf%d",i);
  sprintf(hbname,"hb%d",i);
  hf[i]=new TH2D(hfname,hfname,4000,0,4000,4000,0,4000);
  hb[i]=new TH2D(hbname,hbname,4000,0,4000,4000,0,4000); 
 }
  line=new TF1("line","pol1",0,4000);
}
