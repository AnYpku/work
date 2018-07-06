void TriggerCalculation(int tGATCONF,int tTrig[16]);

void plot()
{
  TFile *f = new TFile("/home/data/students2018/AnYing/homework1/v2/test0410.root");
  TTree *tr1;
  int GATCONF,tTrig[16];
  float FPPosition[12][4];
  f->GetObject("tr1",tr1);
  tr1->SetBranchAddress("GATCONF",&GATCONF);
  tr1->SetBranchAddress("FPPosition",FPPosition);
  TH2F *hBeam = new TH2F("hBeam","Beam trigger",100,-100,100,100,-100,100);
  TH2F *hMUST = new TH2F("hMUST","MUST1 and MUST4 trigger",100,-100,100,100,-100,100);
  for(int i=0;i<tr1->GetEntries();i++)
    {
      tr1->GetEntry(i);
      TriggerCalculation(GATCONF,tTrig);
      if(tTrig[11]==1) // Beam trigger
	{
	  hBeam->Fill(FPPosition[8][0],FPPosition[8][1]);
	}
      if(tTrig[0]==1||tTrig[3]==1) // MUST 1 and 3  trigger
	{
	  hMUST->Fill(FPPosition[8][0],FPPosition[8][1]);
	}
    }
  TFile *fout = new TFile("out.root","recreate");
  hBeam->Write();
  hMUST->Write();
  fout->Close();
}
/////////////////////////////////////////////////////////////////////////                                                                           
/////////////////////////////////////////////////////////////////////////                                                                           
/////////////////////////////////////////////////////////////////////////                                                                           
void TriggerCalculation(int tGATCONF,int tTrig[16])
{
  int icoin = tGATCONF;
  int ibit[16],imask;
  //cout<<" icoin= "<<icoin<<endl;;                                                                                                                 

  for(int i = 0;i<16;i++)
    {
      tTrig[i]=-1000000;
      ibit[i]=0;
      imask = pow(2,i);
      ibit[i] = (icoin&imask)/imask;
      //cout<<"  i= "<<i<<" imask= "<<imask;                                                                                                    
      //cout<<" ibit[i]= "<<ibit[i]<<endl;                                                                                                      
      if(ibit[i]!=0)
	{
	  tTrig[i]=1;
	}
      else
	{
	  tTrig[i]=0;
	}
    }
}
