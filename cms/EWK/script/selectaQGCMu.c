void selectaQGCMu(){
//    TChain *t1=new TChain("demo");
//    chain->Add("/afs/cern.ch/work/y/yian/Ntuple/CMSSW_8_0_26_patch2/src/analysis_code/step1_add_weight/outps_*.root");
    TFile *f1 = new TFile("/afs/cern.ch/work/y/yian/Ntuple/CMSSW_8_0_26_patch2/src/analysis_code/step1_add_weight/outZA.root");
    TTree *t1 = (TTree*)f1->Get("demo");
    double ptlep1,ptlep2,etalep1,etalep2,massVlep;
    double jet1pt,jet2pt,jet1eta,jet2eta;
    double photonet,photoneta;
    double pweight[703],Mjj,deltaetajj,zepp;
    double scalef,theWeight,lumiWeight;
    int nlooseeles,nloosemus,HLT_Ele2,HLT_Mu2,lep;
    t1->SetBranchAddress("scalef",&scalef);
    t1->SetBranchAddress("theWeight",&theWeight);
    t1->SetBranchAddress("lumiWeight",&lumiWeight);
    t1->SetBranchAddress("nloosemus",&nloosemus);
    t1->SetBranchAddress("nlooseeles",&nlooseeles);
    t1->SetBranchAddress("HLT_Ele2",&HLT_Ele2);
    t1->SetBranchAddress("HLT_Mu2",&HLT_Mu2);
    t1->SetBranchAddress("lep",&lep);
    t1->SetBranchAddress("pweight",pweight);
    t1->SetBranchAddress("Mjj",&Mjj);
    t1->SetBranchAddress("deltaetajj",&deltaetajj);
    t1->SetBranchAddress("zepp",&zepp);
    t1->SetBranchAddress("photonet",&photonet);
    t1->SetBranchAddress("photoneta",&photoneta);
    t1->SetBranchAddress("jet1pt",&jet1pt);
    t1->SetBranchAddress("jet2pt",&jet2pt);
    t1->SetBranchAddress("jet1eta",&jet1eta);
    t1->SetBranchAddress("jet2eta",&jet2eta);
    t1->SetBranchAddress("ptlep1",&ptlep1);
    t1->SetBranchAddress("ptlep2",&ptlep2);
    t1->SetBranchAddress("etalep1",&etalep1);
    t1->SetBranchAddress("etalep2",&etalep2);
    t1->SetBranchAddress("massVlep",&massVlep);

	TFile *newfile = new TFile("outZA-cut-aQGC-mu.root", "recreate");
	//in the new.root files, all events satisfy your cuts 
	TTree *newtree = t1->CloneTree(0);
	int nentries = t1->GetEntriesFast();
//    nentries=10000;
    int cut0=0,cut1=0,cut2=0,cut3=0,cut4=0;
    bool LEP,JET,PHOTON,SignalRegion;
    vector<double> vector_pt;
    vector<double>::iterator biggest_pt;
    int position=0,size,m=0;
    double actualWeight[9];
//    nentries=10000;
    for (int i = 0; i < nentries; i++) {
      t1->GetEntry(i);
      cut0++;//total events, cut0=t1->GetEntries()
      LEP = lep==13 && HLT_Mu2>0&& ptlep1 > 20. && ptlep2 > 20.&& fabs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles==0 && nloosemus <3  && massVlep >70. && massVlep < 110; 
//      LEP = lep==11 && HLT_Ele2>0 && ptlep1 > 25. && ptlep2 > 25.&& fabs(etalep1) < 2.5 &&abs(etalep2) < 2.5 && nlooseeles < 3 && nloosemus == 0  && massVlep >70. && massVlep < 110; 
      SignalRegion= Mjj>500 && deltaetajj>2.5;// && zepp<1.8;
//      SignalRegion= deltaetajj>2.5 && zepp<1.8;
      PHOTON= photonet>80 && (fabs(photoneta)<2.5&&fabs(photoneta)>1.566) || fabs(photoneta)<1.4442;//fabs(photoneta)<2.5&&fabs(photoneta)>1.566;
      JET=jet1pt> 30 && jet2pt > 30 && fabs(jet1eta)< 4.7 && fabs(jet2eta)<4.7 && Mjj > 150;
      if(!(LEP&&PHOTON&&JET&&SignalRegion))
           continue;
     cut1++;//how many events passing the selection 
//     if(SignalRegion==false)
//        continue;//if the entry can not pass this selection, remove this event and clear the vector
//     cut2++;//after passing the selection of photons,how many events pass the SignalRegion selection
     newtree->Fill(); //fill the brach when this entry pass the both selection
  }
	newtree->Write(); //fill this tree into KEY from OBJ
	newfile->Close();
	//print some information 
    std::cout << "The total events are      : " << cut0 << std::endl;
    std::cout << "The qualified events      : " << cut1 << std::endl;
//    std::cout << "The SignalRegion selection: " << cut2 << std::endl;
}
