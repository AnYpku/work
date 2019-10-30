Double_t etbins[6]={0,20,40,60,100,200};
Double_t etabins[7]={0,0.5,1.0,1.4442,1.566,2.0,2.5};

TString n1 = "50_120_";
//TString n1 = "120_200_";
//TString n1 = "50_120_barrel_";
//TString n1 = "120_200_barrel_";
//TString n1 = "50_120_endcap_";
//TString n1 = "120_200_endcap_";
TFile*file[6];
void run(int j,int i){
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
   file[j]->cd();
   TString name;
   het[0][i] = (TH1D*)f1->Get("hadem_ele");  
     name = het[0][i]->GetName();
     het[0][i]->SetTitle(split);het[0][i]->Write(name+Form("_%i",i));
   het[1][i] = (TH1D*)f1->Get("hadem_eghltUS");     
     name = het[1][i]->GetName();
     het[1][i]->SetTitle(split);het[1][i]->Write(name+Form("_%i",i));
   heta[0][i] = (TH1D*)f1->Get("hdetEta_ele"); 
      name = heta[0][i]->GetName();
      heta[0][i]->SetTitle(split);heta[0][i]->Write(name+Form("_%i",i));
   heta[1][i] = (TH1D*)f1->Get("heta_eghltUS");  
       name = heta[1][i]->GetName();
       heta[1][i]->SetTitle(split);heta[1][i]->Write(name+Form("_%i",i));
   hnrgy[0][i] = (TH1D*)f1->Get("hclusNrgy_ele");  
       name = hnrgy[0][i]->GetName();
       hnrgy[0][i]->SetTitle(split);hnrgy[0][i]->Write(name+Form("_%i",i));
   hnrgy[1][i] = (TH1D*)f1->Get("hnrgy_eghltUS");    
       name = hnrgy[1][i]->GetName();
       hnrgy[1][i]->SetTitle(split);hnrgy[1][i]->Write(name+Form("_%i",i));
   hphi[0][i] = (TH1D*)f1->Get("hdetPhi_ele");     
       name = hphi[0][i]->GetName();
       hphi[0][i]->SetTitle(split);hphi[0][i]->Write(name+Form("_%i",i));
   hphi[1][i] = (TH1D*)f1->Get("hphi_eghltUS");      
       name = hphi[1][i]->GetName();
       hphi[1][i]->SetTitle(split);hphi[1][i]->Write(name+Form("_%i",i));
   hdeta[0][i] = (TH1D*)f1->Get("hdEtaInSeed_ele");
       name = hdeta[0][i]->GetName();
       hdeta[0][i]->SetTitle(split);hdeta[0][i]->Write(name+Form("_%i",i));
   hdeta[1][i] = (TH1D*)f1->Get("hetain_eghltUS");   
       name = hdeta[1][i]->GetName();
       hdeta[1][i]->SetTitle(split);hdeta[1][i]->Write(name+Form("_%i",i));
   hdphi[0][i] = (TH1D*)f1->Get("hPhiIn_ele");     
       name = hdphi[0][i]->GetName();
       hdphi[0][i]->SetTitle(split);hdphi[0][i]->Write(name+Form("_%i",i));
   hdphi[1][i] = (TH1D*)f1->Get("hphiin_eghltUS");   
       name = hdphi[1][i]->GetName();
       hdphi[1][i]->SetTitle(split);hdphi[1][i]->Write(name+Form("_%i",i));
   hsieie[0][i] = (TH1D*)f1->Get("hsieie_ele");    ;
       name = hsieie[0][i]->GetName();
       hsieie[0][i]->SetTitle(split);hsieie[0][i]->Write(name+Form("_%i",i));
   hsieie[1][i] = (TH1D*)f1->Get("hsieie_eghltUS");  ;
       name = hsieie[1][i]->GetName();
       hsieie[1][i]->SetTitle(split);hsieie[1][i]->Write(name+Form("_%i",i));
   hmhits[0][i] = (TH1D*)f1->Get("hMHits_ele");    ;
       name = hmhits[0][i]->GetName();
       hmhits[0][i]->SetTitle(split);hmhits[0][i]->Write(name+Form("_%i",i));
   hmhits[1][i] = (TH1D*)f1->Get("hMHits_eghltUS");  ;
       name = hmhits[1][i]->GetName();
       hmhits[1][i]->SetTitle(split);hmhits[1][i]->Write(name+Form("_%i",i));
}
int ExtractEta(){
    //Style();
    for(int j=0;j<6;j++){
//    file[j] = new TFile(n1+Form("eta_%.2f_%.2f.root",barreletabins[j],barreletabins[j+1]),"recreate");
    file[j] = new TFile("./Splitfiles/"+n1+Form("eta_%.2f_%.2f.root",etabins[j],etabins[j+1]),"recreate");
        for(int i=0;i<5;i++){
            run(j,i);
        }
    }

    return 1;

}

