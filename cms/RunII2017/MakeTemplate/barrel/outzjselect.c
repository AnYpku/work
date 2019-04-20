{
    TFile *f1 = new TFile("./outZJets_FX.root");
    TTree *t1 = (TTree*) f1->Get("demo");
    Int_t photon_isprompt[6];
    t1->SetBranchAddress("photon_isprompt",photon_isprompt);

	TFile *newfile1 = new TFile("outZJets_fakephoton.root", "recreate");
	//in the new.root files, all events satisfy your cuts 
	TTree *newtree1 = t1->CloneTree(0);
	int nentries = t1->GetEntriesFast();
//    nentries=10000;
    cout<<"nentries = "<<nentries<<endl;
	int cut0=0,cut2=0,cut3=0,cut4=0;
        Int_t m=1; 
	for (int i = 0; i < nentries; i++) {
          t1->GetEntry(i);
          cut0++;
          Int_t cut1=0;
//        if(i==1000*m)
//        cout<<"i = "<<i<<endl;
          for(Int_t j=0;j<6;j++){
		if (photon_isprompt[j]==1){
		        cut1++;
                continue;
                }
            }
          if (cut1!=0)
          cout<<"i = "<<i<<"  "<<"the real photon in one event "<<cut1<<endl; 
                if (cut1!=0) 
                  continue;
		cut2++;  
	  newtree1->Fill(); //fill the brach one entry
	}
	newtree1->Write(); //fill this tree into KEY from OBJ
	newfile1->Close();
	
	//print some information
	std::cout << "The total events are : " << cut0 << std::endl;
        std::cout << "the selected events   : " << cut2 << std::endl;
   }
