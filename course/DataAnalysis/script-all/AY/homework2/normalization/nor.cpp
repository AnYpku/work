#include <TF1.h>
#include <TH2D.h>
#include <TGraph.h>
#include <TString.h>
#include <TStyle.h>
#include <TMath.h>
#include <TCut.h>
#include <TCutG.h>
#include <TTree.h>
#include <TTreeFormula.h>
#include <TFile.h>

#include <iostream>

using namespace std;

TString outfile1 = "front0300.root";
TString outfile2 = "back0300.root";
TH2D *f[32],*b[32]; //hf为正面归一
TGraph *gf[32],*gb[32];
TF1 *line;
Double_t kf,bf,kb,bbb; //bbb != bb

void createHist(TTree *tree);

void createHist(TTree *tree){
 for(Int_t i=0;i<32;i++){
  char f[32];
  char b[32];
  sprintf(f,"f%d",i);
  sprintf(b,"b%d",i);
  f[i]=new TH2D(f,f,4000,0,4000,4000,0,4000);
  b[i]=new TH2D(b,b,4000,0,4000,4000,0,4000); 
 }
  line=new TF1("line","pol1",0,4000);
}
int main(){
   TFile *file = new TFile("/home/data/data/RIBLL_DATA/tele0300.root"); //打开root
   if(!file->IsOpen()){
   cout<<"cannot open input file:"<<" tele0300.root"<<endl;
   return 1;}
   TTree *tree = (TTree*)file->Get("tree");
   if(tree == 0){
   cout<<"cannot find input tree!"<<endl;
   return 1;}   

   createHist(ipt);
  
   TCutG * Bcut = (TCutG*)gROOT->FindObject("Bcut");
   TCutG * Fcut = (TCutG*)gROOT->FindObject("Fcut");


    //正面归一
    ofstream out("fcaliPara.txt"); //front
    for(Int_t i=0;i<32;i++){
      //ipt->Project(TString::Format("hf%d",i),"be:fe");
      //TCut cut1 = Form("fe[%d]>=200 && fe[%d]<=3840",i,i);
      //TCut cut2 = "be>=200";
     cout<<"front strips normalization: "<<i+1<<endl;
     cout<<"####################################"<<endl;
     Fcut->SetName("Fcut");
     Fcut->SetVarX("fe");
     Fcut->SetVarY("be");
    // TCut cut = Form("ff==%d",i);
     
    tree->Draw(Form("be:fe>>f[%d](4000,0,4000,4000,0,4000)",i),Form("Fcut && bb==15 && ff == %d",i),"colz");
    gf[i] = new TGraph(tree->GetSelectedRows(),tree->GetV2(),tree->GetV1());
    gf[i]->Draw("A*");
    Long64_t npoints = gf[i]->GetN();
      
    cout<<"first cut points="<<npoints<<endl;
    if(npoints<6){
       cout<<"less counts!can not fit!"<<endl;
      kf=1.0;
      bf=0.0;   
      out<<kf<<"\t"<<bf<<"\t"<<endl;
      continue;}
     gf[i]->Fit("line","ROB");
     bf=line->GetParameter(0);
     kf=line->GetParameter(1);
     
        if(kf>=0.8||kf<=0.6){
      cout<<"weak correlation!can not fit!"<<endl;
      kf=1.0;
      bf=0.0;
      out<<kf<<"\t"<<bf<<"\t"<<endl;
      continue;}

     out<<kf<<"\t"<<bf<<"\t"<<endl;

    // delete cut;
    }
    out.close();
     TFile *opf= new TFile(outfile1,"RECREATE");
     for(Int_t i=0;i<32;i++){
      if(gf[i]!=0) gf[i]->Write();
      if(f[i]!=0) f[i]->Write();}
     opf->Close();
     for(Int_t i=0;i<32;i++){
       delete gf[i];
       delete hf[i];}
     cout<<"front normalization is over"<<endl;


//背面归一
   
   ofstream outs("bcaliPara.txt"); //back
   
   for(Int_t i=0;i<32;i++){
    // ipt->Project(TString::Format("hb%d",i),"fe:be");
     // TCut cut1 = Form("be[%d]>=200 && be[%d]<=3840",i,i);
     //TCut cut2 = "fe[15]>=200";
     cout<<"back strips normalization: "<<i+1<<endl;
     cout<<"####################################"<<endl;

     Bcut->SetName("Bcut");
     Bcut->SetVarX("be");
     Bcut->SetVarY("fe");
    // TCut cut = Form("bb==%d",i);
     
    ipt->Draw(TString::Format("fe:be>>hb[%d](4000,0,4000,4000,0,4000)",i),TString::Format("ff==15 &&Bcut && bb == %d",i),"colz");
      gb[i] = new TGraph(ipt->GetSelectedRows(),ipt->GetV2(),ipt->GetV1());
      gb[i]->Draw("A*");
      Long64_t  npoints = gb[i]->GetN();
      
        cout<<"first cut points="<<npoints<<endl;
	if(npoints<6){
	 cout<<"less counts!can not fit!"<<endl;
	kb=1.0;
	bbb=0.0;   
	outs<<kb<<"\t"<<bbb<<"\t"<<endl;
	continue;}

      gb[i]->Fit("line","ROB");
      bbb=line->GetParameter(0);
      kb=line->GetParameter(1);

      if(kb>=2.0||kb<=1.2){
      cout<<"weak correlation!can not fit!"<<endl;
      kb=1.0;
      bbb=0.0;
      outs<<kb<<"\t"<<bbb<<"\t"<<endl;      
      continue;}

     // delete cut;
      
      outs<<kb<<"\t"<<bbb<<"\t"<<endl;
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


    

