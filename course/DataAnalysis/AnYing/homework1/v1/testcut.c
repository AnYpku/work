void testcut(){

Float_t ppac[5][4];
Float_t PPAC[5][4];

TFile *f =new TFile("/home/data/students2018/AnYing/tree.root");
TTree *t=(TTree *)f->Get("mytree");

Double_t entries = t->GetEntries();
cout<<"Entries = "<<entries<<endl;

TFile *nf=new TFile("treecut.root","RECREATE");
TTree *tnf=new TTree("tt","tt");

tnf->Branch("ppac",&ppac,"ppac[5][4]/F");

TBranch *b_PPAC;

t->SetBranchAddress("PPAC",PPAC,&b_PPAC);

Int_t AB=0,AC=0,BC=0;
     for(Int_t i=0;i<entries;i++)
     {
       t->GetEntry(i);
       if((TMath::Abs(PPAC[0][0])<=120)&&(TMath::Abs(PPAC[0][1])<=75))
           num1a=1;
           num[0]=num1a;
       if((TMath::Abs(PPAC[1][0])<=120)&&(TMath::Abs(PPAC[1][1])<=75))
           num1b=1;
           num[1]=num1b;
       if((TMath::Abs(PPAC[2][0])<=120)&&(TMath::Abs(PPAC[2][1])<=75))
           num2a=1;
           num[2]=num2a;
       if((TMath::Abs(PPAC[3][0])<=120)&&(TMath::Abs(PPAC[3][1])<=75))
           num2b=1;
           num[3]=num2b;
       if((TMath::Abs(PPAC[4][0])<=50 )&&(TMath::Abs(PPAC[4][1])<=50))
           num3=1;
           num[4]=num3;
       num[5]=num1a+num1b+num2a+num2b+num3;
       if(num1a+num1b+num2a+num2b==0) continue;
       if(num1a+num1b+num3==0) continue;
       if(num2a+num2b+num3==0) continue;

          




		  for(Int_t j=0;j<5;j++)
		     {
		       for(Int_t i=0;i<4;i++)
		       {
          	         ppac[j][i]=PPAC[j][i];
		       }
		     }
		  AB=AB+1;
		  tnf->Fill();
  		}
  	     else
  	        { 
  		  if(PPAC[4][0]>-900&&PPAC[4][1]>-900)
  		    {
		       for(Int_t j=0;j<5;j++)
		       { 
		          for(Int_t i=0;i<4;i++)
		           {
          	            ppac[j][i]=PPAC[j][i];
		           }
		       }  
		  AC=AC+1;
		  tnf->Fill();
  		    }
  	        }
  	 }
       else
          {
  	     if((PPAC[2][0]>-900&&PPAC[2][1]>-900)&&(PPAC[3][0]>-900&&PPAC[3][1]>-900)&&(PPAC[4][0]>-900&&PPAC[4][1]>-900))
  		    {

                       for(Int_t j=0;j<5;j++)
		      {  
		         for(Int_t i=0;i<4;i++)
		          {
          	           ppac[j][i]=PPAC[j][i];
		          }
		      }
		  BC=BC+1;
		  tnf->Fill();
  		    }
  	  }
//     cout<<"PPAC1a ( "<<ppac[0][0]<<" , "<<ppac[0][1]<<" )"<<endl;
//     cout<<"PPAC1b ( "<<ppac[1][0]<<" , "<<ppac[1][1]<<" )"<<endl;
//     cout<<"PPAC2a ( "<<ppac[2][0]<<" , "<<ppac[2][1]<<" )"<<endl;
//     cout<<"PPAC2b ( "<<ppac[3][0]<<" , "<<ppac[3][1]<<" )"<<endl;
//     cout<<"PPAC3  ( "<<ppac[4][0]<<" , "<<ppac[4][1]<<" )"<<endl;
  
       }
cout<<"AB +ABC = "<<AB<<endl<<"AC = "<<AC<<endl<<"BC = "<<BC<<endl<<"AB+ABC+AC+BC = "<<AB+AC+BC<<endl;
tnf->Write();
nf->Close();

}

