void target(){
TFile *f=new TFile("/home/data/students2018/AnYing/treecut.root");
TTree *t=(TTree*)f->Get("tt");

const int ZZ=0;
Int_t count;
count = t->GetEntries();
//count = 1000;

cout<<"count = "<<count<<endl;
 
Float_t x[5],zx[5],y[5],zy[5];
Float_t a,b,c,d,X,Y;
Float_t PPAC[5][4];
 
TFile *target=new TFile("target.root","RECREATE");
TTree *tree=new TTree("t","t");
tree->Branch("X",&X,"X/F");
tree->Branch("Y",&Y,"Y/F");

TBranch *b_ppac;
t->SetBranchAddress("ppac",PPAC,&b_ppac);
 
TF1 *fun;
TF1 *ff;
TGraph *g;
TGraph *gg;

g=new TGraph(5);	
gg=new TGraph(5);	

fun=new TF1("fun","[0]*x+[1]",-200,200);
fun->SetParameters(0,1);

ff=new TF1("ff","[0]*x+[1]",-200,200);
ff->SetParameters(1,1);
Int_t m=0;
for(Int_t j=0;j<count;j++)
    {
      t->GetEntry(j);
      for(Int_t i=0;i<5;i++)
           {
              x[i] =PPAC[i][0];
              zx[i]=PPAC[i][2];
      	      y[i] =PPAC[i][1];
              zy[i]=PPAC[i][3];
	      g->SetPoint(i,zx[i],x[i]);
	      gg->SetPoint(i,zy[i],y[i]);
           }  
      g->SetMarkerStyle(20);
//      g->Draw("AP");
      g->Fit("fun"); 

      gg->SetMarkerStyle(22);
//      gg->Draw("AP");
      gg->Fit("ff"); 

      a=fun->GetParameter(0);
      b=fun->GetParameter(1);
      X=a*ZZ+b;

      c=ff->GetParameter(0);
      d=ff->GetParameter(1);
      Y=c*ZZ+d;
      tree->Fill();
      cout<<"j = "<<j<<" "<<"a = "<<a<<endl;
//      cout<<"j = "<<j<<" "<<"c = "<<c<<endl;
//      cout<<"j = "<<j<<" "<<"X = "<<X<<endl;
//      cout<<"j = "<<j<<" "<<"Y = "<<Y<<endl;
    }
tree->Write();
target->Close();
}

