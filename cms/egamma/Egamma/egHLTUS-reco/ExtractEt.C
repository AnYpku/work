Double_t etbins[7]={0,20,30,50,100,200,400};
Double_t etabins[7]={0,0.5,1.0,1.4442,1.566,2.0,2.5};
//TString n1 = "50_120_barrel_";
//TString n1 = "120_200_barrel_";
//TString n1 = "50_120_endcap_";
//TString n1 = "120_200_";
TString n1 = "50_120_";
TFile*file[6];
void run(int i,int j){
//    TString split = Form("%0.f<et<%0.f and %.2f<eta<%.2f",etbins[i],etbins[i+1],barreletabins[j],barreletabins[j+1]);
//    TString figname = n1 + Form("et_%0.f_%0.f_eta_%.2f_%.2f",etbins[i],etbins[i+1],barreletabins[j],barreletabins[j+1]);
//    TFile* f1 = new TFile("./Splitfiles/"+n1+Form("et_%0.f_%0.f-eta_%.2f_%.2f.root",etbins[i],etbins[i+1],barreletabins[j],barreletabins[j+1]));
    TString split = Form("%0.f<et<%0.f and %.2f<eta<%.2f",etbins[i],etbins[i+1],etabins[j],etabins[j+1]);
    TString figname = n1 + Form("et_%0.f_%0.f_eta_%.2f_%.2f",etbins[i],etbins[i+1],etabins[j],etabins[j+1]);
    TFile* f1 = new TFile("./Splitfiles/splits/"+n1+Form("et_%0.f_%0.f-eta_%.2f_%.2f.root",etbins[i],etbins[i+1],etabins[j],etabins[j+1]));
    cout<<f1->GetName()<<endl;
   TH1D*het[2][6];
   TH1D*heta[2][6];
   TH1D*hnrgy[2][6];
   TH1D*hphi[2][6];
   TH1D*hdeta[2][6];
   TH1D*hdphi[2][6];
   TH1D*hsieie[2][6];
   TH1D*hmhits[2][6];
   file[i]->cd();
   TString name;
   het[0][j] = (TH1D*)f1->Get("hclusEt_ele");  
     name = het[0][j]->GetName();
     het[0][j]->SetTitle(split);het[0][j]->Write(name+Form("_%i",j));
   het[1][j] = (TH1D*)f1->Get("het_eghltUS");     
     name = het[1][j]->GetName();
     het[1][j]->SetTitle(split);het[1][j]->Write(name+Form("_%i",j));
   heta[0][j] = (TH1D*)f1->Get("hdetEta_ele"); 
      name = heta[0][j]->GetName();
      heta[0][j]->SetTitle(split);heta[0][j]->Write(name+Form("_%i",j));
   heta[1][j] = (TH1D*)f1->Get("heta_eghltUS");  
       name = heta[1][j]->GetName();
       heta[1][j]->SetTitle(split);heta[1][j]->Write(name+Form("_%i",j));
   hnrgy[0][j] = (TH1D*)f1->Get("hclusNrgy_ele");  
       name = hnrgy[0][j]->GetName();
       hnrgy[0][j]->SetTitle(split);hnrgy[0][j]->Write(name+Form("_%i",j));
   hnrgy[1][j] = (TH1D*)f1->Get("hnrgy_eghltUS");    
       name = hnrgy[1][j]->GetName();
       hnrgy[1][j]->SetTitle(split);hnrgy[1][j]->Write(name+Form("_%i",j));
   hphi[0][j] = (TH1D*)f1->Get("hdetPhi_ele");     
       name = hphi[0][j]->GetName();
       hphi[0][j]->SetTitle(split);hphi[0][j]->Write(name+Form("_%i",j));
   hphi[1][j] = (TH1D*)f1->Get("hphi_eghltUS");      
       name = hphi[1][j]->GetName();
       hphi[1][j]->SetTitle(split);hphi[1][j]->Write(name+Form("_%i",j));
   hdeta[0][j] = (TH1D*)f1->Get("hdEtaInSeed_ele");
       name = hdeta[0][j]->GetName();
       hdeta[0][j]->SetTitle(split);hdeta[0][j]->Write(name+Form("_%i",j));
   hdeta[1][j] = (TH1D*)f1->Get("hetain_eghltUS");   
       name = hdeta[1][j]->GetName();
       hdeta[1][j]->SetTitle(split);hdeta[1][j]->Write(name+Form("_%i",j));
   hdphi[0][j] = (TH1D*)f1->Get("hPhiIn_ele");     
       name = hdphi[0][j]->GetName();
       hdphi[0][j]->SetTitle(split);hdphi[0][j]->Write(name+Form("_%i",j));
   hdphi[1][j] = (TH1D*)f1->Get("hphiin_eghltUS");   
       name = hdphi[1][j]->GetName();
       hdphi[1][j]->SetTitle(split);hdphi[1][j]->Write(name+Form("_%i",j));
   hsieie[0][j] = (TH1D*)f1->Get("hsieie_ele");    
       name = hsieie[0][j]->GetName();
       hsieie[0][j]->SetTitle(split);hsieie[0][j]->Write(name+Form("_%i",j));
   hsieie[1][j] = (TH1D*)f1->Get("hsieie_eghltUS");  
       name = hsieie[1][j]->GetName();
       hsieie[1][j]->SetTitle(split);hsieie[1][j]->Write(name+Form("_%i",j));
   hmhits[0][j] = (TH1D*)f1->Get("hMHits_ele");    
       name = hmhits[0][j]->GetName();
       hmhits[0][j]->SetTitle(split);hmhits[0][j]->Write(name+Form("_%i",j));
   hmhits[1][j] = (TH1D*)f1->Get("hMHits_eghltUS");  
       name = hmhits[1][j]->GetName();
       hmhits[1][j]->SetTitle(split);hmhits[1][j]->Write(name+Form("_%i",j));
}
int ExtractEt(){
    //Style();
    for(int i=0;i<6;i++){
    file[i] = new TFile(n1+Form("et_%0.f_%0.f.root",etbins[i],etbins[i+1]),"recreate");
        for(int j=0;j<6;j++){
            run(i,j);
        }
    }

    return 1;

}

