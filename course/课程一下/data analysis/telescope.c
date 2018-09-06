void test()
{
TRandom r;
double BeamEnergymax[15]={30.,60.,90.,90.,120.,180.,210.,240.,270.,270.,300.,330.,330.,360.,390.};
double BeamEnergymin[15]={1.,2.,3.,3.,4.,6.,7.,8.,9.,9.,10.,11.,11.,12.,13.};
double Energy[15],Range[15],dE1[15],dE2[15],E[15];
double a0[15],a1[15],a2[15],a3[15],a4[15],a5[15],a6[15],a7[15];
Double_t Energy_t[15],Range_t[15];
TF1 *fun[15];
TH2D *dE12[15];
TH2D *dE2E[15];
TGraph *Re[15];
TFile *f[15];
TTree *tree[15];
for(int i=0;i<15;i++)
{
 f[i] = new TFile(Form("./rootfiles/%d.root",i));

 tree[i]=(TTree*)f[i]->Get("tree");

 Long64_t count=tree[0]->GetEntries();//get the entries,count=entries=40

 tree[i]->SetBranchAddress("range",&Range_t[i]);
 tree[i]->SetBranchAddress("energy",&Energy_t[i]);
 Re[i] = new TGraph(count);
//Re[i]->SetMarkerStyle(3);
//Re[i]->SetMarkerSize(2.0);

	for(int j=0;j<count;j++)
       {
        tree[i]->GetEntry(j);
        Re[i]->SetPoint(j,Energy_t[i],Range_t[i]);
       }

 fun[i]= new TF1(Form("fun_%d",i),"[0]*pow(x,[1])+[2]*pow(x,[3])+[4]*pow(x,[5])+[6]*pow(x,[7])",0,100);

 fun[i]->SetParameter(0,1);
 fun[i]->SetParameter(1,2);
 fun[i]->SetParameter(2,1);
 fun[i]->SetParameter(3,1);
 fun[i]->SetParameter(4,1);
 fun[i]->SetParameter(5,0.5);
 fun[i]->SetParameter(6,1);
 fun[i]->SetParameter(7,0);

 Re[i]->Fit(fun[i]);

   a0[i]=fun[i]->GetParameter(0);
   a1[i]=fun[i]->GetParameter(1);
   a2[i]=fun[i]->GetParameter(2);
   a3[i]=fun[i]->GetParameter(3);
   a4[i]=fun[i]->GetParameter(4);
   a5[i]=fun[i]->GetParameter(5);
   a6[i]=fun[i]->GetParameter(6);
   a7[i]=fun[i]->GetParameter(7);


   dE12[i] = new TH2D(Form("dE12_%d",i),"dE_{1}-dE_{2}",100,0,200,100,0,100);

   dE2E[i] = new TH2D(Form("dE2E_%d",i),"dE_{2}-E",100,0,360,100,0,200);

        for(int k=0;k<15000;k++)
        {
	     // r.SetSeed(1);
            Energy[i]=r.Uniform(BeamEnergymin[i],BeamEnergymax[i]);
	        Range[i]=a0[i]*pow(Energy[i],a1[i])+a2[i]*pow(Energy[i],a3[i])+a4[i]*pow(Energy[i],a5[i])+a6[i]*pow(Energy[i],a7[i]);
         // cout<<"Range"<<Range<<endl;
	        if(Range[i]<100)
	          {dE1[i]=Energy;
		       dE2[i]=E[i]=0;}

	        if(Range[i]>100.0&&Range[i]<=600.0)
	          {dE1[i]=Energy[i]-fun[i]->GetX(Range[i]-100);
		       dE2[i]=Energy[i]-dE1[i];}

	        if(Range[i]>600&&Range[i]<3100)
	          {dE1[i]=Energy[i]-fun[i]->GetX(Range[i]-100);
		       dE2[i]=Energy[i]-fun[i]->GetX(Range[i]-600)-dE1[i];
		       E[i]=Energy[i]-dE1[i]-dE2[i];}

	        if(Range[i]>3100)
	          {dE1[i]=Energy[i]-fun[i]->GetX(Range[i]-100);
		       dE2[i]=Energy[i]-fun[i]->GetX(Range[i]-600)-dE1[i];
		       E[i]=Energy[i]-fun[i]->GetX(Range[i]-3100)-dE1[i]-dE2[i];}

	        if(Range[i]<0) {Range[i]=0;}

	        dE12[i]->Fill(dE2[i],dE1[i]);
	        dE2E[i]->Fill(E[i],dE2[i]);
	     }

}

TCanvas *can1 = new TCanvas("can1","dE1-dE2",0,0,900,700);
can1->SetGridx();
can1->SetGridy();
//c1->Write();
for(int m=0;m<15;m++)
   {  /*if(m=0)
        {dE12[0]->Draw();
         dE12[0]->GetXaxis()->SetTitle("dE_{2}/MeV");
         dE12[0]->GetYaxis()->SetTitle("dE_{1}/MeV");}
      else*/
	    dE12[m]->Draw("SAME");
   }
can1->SaveAs("./dE1-dE2_test.pdf");

TCanvas *can2 = new TCanvas("can2","dE2-E",0,0,900,700);
can2->SetGridx();
can2->SetGridy();
for(int n=0;n<15;n++)
   { /*if(n=0)
       {dE2E[0]->Draw();
	   dE2E[0]->GetXaxis()->SetTitle("E/MeV");
       dE2E[0]->GetYaxis()->SetTitle("dE_{2}/MeV");}
	 else*/
	   dE2E[n]->Draw("SAME");
   }
//c2->Write();
can2->SaveAs("./dE2-E_test.pdf");


delete can1;
delete can2;
}
