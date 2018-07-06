#include "/Users/songyx/work/useful.h"
void ana(){
auto *f=new TFile("./choose.root");
auto *t=(TTree*)f->Get("tree");

const int ZZ=0;
Int_t count;
count = t->GetEntries();
//count=1000;
cout<<"count = "<<count<<endl;
 
Float_t x[5][count],zx[5][count],y[5][count],zy[5][count];
Float_t a[count],b[count],c[count],d[count],X,Y;
Float_t PPAC[5][5];
Float_t OK[6];

auto *target=new TFile("bsw.root","RECREATE");
auto *tree=new TTree("t","t");
tree->Branch("X",&X,"X/F");
tree->Branch("Y",&Y,"Y/F");

TBranch *b_ppac;
TBranch *b_ok;
t->SetBranchAddress("PPAC",PPAC,&b_ppac);
t->SetBranchAddress("OK",OK,&b_ok);



TF1 *fzx =new TF1("fzx","[0]*x+[1]",-200,200);
fzx->SetParameters(0,1);

TF1 *fzy=new TF1("fzy","[0]*x+[1]",-200,200);
fzy->SetParameters(1,1);

TH2D *h=new TH2D("h","",200,-600,600,200,-600,600);//200
Float_t num=0;
for(Int_t j=0;j<count;j++)
    {
      t->GetEntry(j);
      TGraph *gzx =new TGraph(OK[5]);  
      TGraph *gzy=new TGraph(OK[5]);
      for(Int_t i=0;i<5;i++)
        {
            x[i][j] =PPAC[i][0];
            zx[i][j]=PPAC[i][2];
	          y[i][j] =PPAC[i][1];
	          zy[i][j]=PPAC[i][3];
            if(OK[i]==1){
	          gzx->SetPoint(i,(zx[i][j]+zy[i][j])/2,x[i][j]);//
            gzy->SetPoint(i,(zx[i][j]+zy[i][j])/2,y[i][j]);//
          }
        } 
      gzx->SetMarkerStyle(20);
      gzx->Fit(fzx); 

      gzy->SetMarkerStyle(22);
      gzy->Fit(fzy); 
    
      //TF1 *fzx = gzx->GetFunction("pol2");
      a[j]=fzx->GetParameter(0);
      b[j]=fzx->GetParameter(1);
      X=a[j]*ZZ+b[j];

      //TF1 *fzy = gzy->GetFunction("pol2");
      c[j]=fzy->GetParameter(0);
      d[j]=fzy->GetParameter(1);
      Y=c[j]*ZZ+d[j];
      h->Fill(X,Y);
      if((TMath::Abs(X)<20)&&(TMath::Abs(Y)<12.5))num=num+1;
      tree->Fill();
      delete gzx;
      delete gzy;
    }
      delete fzx;
      delete fzy;
      num=num/341933; //341933
/*
    TCanvas *c1 =new TCanvas("c1","c1",0,0,900,700);
    c1->Divide(2);
    c1->cd(1);fzx->Draw("APE");txt(0.15,0.8,Form("ZX"));
    c1->cd(2);fzy->Draw("APE");txt(0.15,0.8,Form("ZY"));
    c1->Write();  
*/
    TCanvas *c2 =new TCanvas("c2","c2",0,0,900,900);
    h->Draw("colz");
    txt(0.15,0.8,Form("4 Good  with selection(0.444)"));//2      3     4      5
    drawpave(-20,-12.5,20,12.5,1);            //my 0.852 0.808 0.565  0.154
    c2->Write();                             //new 0.714 0.670 0.444  0.116  
                     
    cout<<num<<endl;
    tree->Write();
//target->Close();
}

