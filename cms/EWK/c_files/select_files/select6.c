void select6(){
    TFile *f1 = new TFile("outZJets_FX.root");
//    TDirectory *d1 = (TDirectory*)f1->Get("treeDumper");
    TTree *t1 = (TTree*) f1->Get("demo");
//    TTree *t1 = (TTree*) d1->Get("ZPKUCandidates");
	double photon_hoe[6];
	double photon_nhiso[6];
	double photon_phoiso[6];
	double photon_pt[6];
	double photon_eta[6];
    double photon_drla[6],photon_drla2[6],photon_sieie[6],photon_chiso[6];
    int photon_isprompt[6];
    int nlooseeles,nloosemus;
    double ptlep1,ptlep2,etalep1,etalep2,massVlep;
    t1->SetBranchAddress("nloosemus",&nloosemus);
    t1->SetBranchAddress("nlooseeles",&nlooseeles);
    t1->SetBranchAddress("ptlep1",&ptlep1);
    t1->SetBranchAddress("ptlep2",&ptlep2);
    t1->SetBranchAddress("etalep1",&etalep1);
    t1->SetBranchAddress("etalep2",&etalep2);
    t1->SetBranchAddress("massVlep",&massVlep);
    t1->SetBranchAddress("photon_isprompt",photon_isprompt);
    t1->SetBranchAddress("photon_drla",photon_drla);
    t1->SetBranchAddress("photon_drla2",photon_drla2);
    t1->SetBranchAddress("photon_sieie",photon_sieie);
    t1->SetBranchAddress("photon_chiso",photon_chiso);
    t1->SetBranchAddress("photon_hoe",photon_hoe);
    t1->SetBranchAddress("photon_nhiso",photon_nhiso);
    t1->SetBranchAddress("photon_phoiso",photon_phoiso);
    t1->SetBranchAddress("photon_pt",photon_pt);
    t1->SetBranchAddress("photon_eta",photon_eta);

	TFile *newfile = new TFile("ZJetsm.root", "recreate");
	//in the new.root files, all events satisfy your cuts 
	TTree *newtree = t1->CloneTree(0);
	int nentries = t1->GetEntriesFast();
//    nentries=10000;
    int cut0=0,cut1[6]={0},cut2[6]={0},cut3[6]={0},cut4[6]={0};
    int p,m=0;
    Double_t a[6],c[6];
    bool Zjets[6],Leading_photon[6],medium_cut[6],loose_cut[6];
    for (int i = 0; i < nentries; i++) {
      p=0;
      t1->GetEntry(i);
      cut0++;
      for(Int_t j=0; j<6;j++){
         Zjets[j] = ptlep1 > 20. && ptlep2 > 20.&& abs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep >70. && massVlep < 110; 
         Leading_photon[j]=photon_isprompt[j] != 1  &&  photon_drla[j]>0.3 && photon_drla2[j]>0.3;
         medium_cut[j]= photon_hoe[j]<0.0396  && photon_nhiso[j]<2.725 + 0.0148*photon_pt[j] + 0.000017*photon_pt[j]*photon_pt[j] && photon_phoiso[j]<2.571 + 0.0047*photon_pt[j]&&abs(photon_eta[j])<1.4442;
         //no sieie cut and photon_chiso cut.
         loose_cut[j]= photon_hoe[j]<0.0597  && photon_nhiso[j]<10.910 + 0.0148*photon_pt[j] + 0.000017*photon_pt[j]*photon_pt[j] && photon_phoiso[j]<3.63 + 0.0047*photon_pt[j]&&abs(photon_eta[j])<1.4442;
         //no sieie cut and photon_chiso cut.
         if (!(Zjets[j]==true))
             continue;
         cut1[j]++;
         if (!(Leading_photon[j]==true))
             continue;
         cut2[j]++;
         if (!(loose_cut[j]==true))
              continue;
         cut3[j]++;
          if (!(medium_cut[j]==true))
      	      continue;
          cut4[j]++;
          p++;//in the entry i, the number of photons passing the three selections
          m++;//the total number of photons passing the three selection
        }
//          std::cout << "p =  "<<p<<std::endl;
          if(p==0)//Only fill the tree when the number of photons passing the three selections does not equal 0
          continue;
          newtree->Fill(); //fill the brach one entry
          cout<<"i = "<<i<<endl;
	}
	newtree->Write(); //fill this tree into KEY from OBJ
	newfile->Close();
	//print some information 
    std::cout << "The total events are     : " << cut0 << std::endl;
    std::cout << "Zjets cut       	   : " << cut1[5] << std::endl;
    std::cout << "Leading photon cut       : " << cut2[5] << std::endl;
    std::cout << "loose  ID cut  	   : " << cut3[5] << std::endl;
    std::cout << "medium ID cut  	   : " << cut4[5] << std::endl;
    std::cout << "sum cut4  	           : " <<cut4[0]+cut4[1]+cut4[2]+cut4[3]+cut4[4]+ cut4[5] << std::endl;
    std::cout << "the total number of qulified photons  =  "<<m<<std::endl;
}
