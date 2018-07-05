{
    TFile *f1 = new TFile("official_ZA.root");
//    TFile *f1 = new TFile("/afs/cern.ch/work/y/yian/public/private_ZA.root");
    TDirectory *d1 = (TDirectory*)f1->Get("treeDumper");
    TTree *t1 = (TTree*) d1->Get("ZPKUCandidates");
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

	TFile *newfile1 = new TFile("realphoton80x_medium.root", "recreate");
	//in the new.root files, all events satisfy your cuts 
	TTree *newtree1 = t1->CloneTree(0);
	int nentries = t1->GetEntriesFast();
//    nentries=10000;
    cout<<"nentries = "<<nentries<<endl;
    TH1D *h11=new TH1D("h11","chiso<0.441",200,0,0.026);//Zjets && leding_photon && medium_cut && photon_chiso<1.416
    TH1D *h12=new TH1D("h12","chiso>2",200,0,0.026);////Zjets && leding_photon && medium_cut && photon_chiso>2
    TH1D *h13=new TH1D("h13","chiso>4",200,0,0.026);//Zjets && leding_photon && medium_cut && photon_chiso>4
    TH1D *h21=new TH1D("h21","chiso<2.839",200,0,0.026);////Zjets && leding_photon && loose_cut && photon_chiso<2.839
    TH1D *h22=new TH1D("h22","chiso>4",200,0,0.026);//Zjets && leding_photon && loose_cut && photon_chiso>4
    TH1D *h23=new TH1D("h23","chiso>6",200,0,0.026);//Zjets && leding_photon && loose_cut && photon_chiso>6
    
    TH2D *hh11 = new TH2D("hh11","chiso and sieie with chiso<0.441",500,0,0.07,500,0,150);//Zjets && leding_photon && medium_cut && photon_chiso<1.416
    TH2D *hh12 = new TH2D("hh12","chiso and sieie with chiso>2",500,0,0.07,500,0,150);//Zjets && leding_photon && medium_cut && photon_chiso>2
    TH2D *hh13 = new TH2D("hh13","chiso and sieie with chiso>4",500,0,0.07,500,0,150);//Zjets && leding_photon && medium_cut && photon_chiso>4

    TH2D *hh21 = new TH2D("hh21","chiso and sieie with chiso<1.295",500,0,0.07,500,0,150);//Zjets && leding_photon && loose_cut && photon_chiso<2.839
    TH2D *hh22 = new TH2D("hh22","chiso and sieie with chiso>4",500,0,0.07,500,0,150);    //Zjets && leding_photon && loose_cut && photon_chiso>4
    TH2D *hh23 = new TH2D("hh23","chiso and sieie with chiso>6",500,0,0.07,500,0,150);    //Zjets && leding_photon && loose_cut && photon_chiso>6
	int cut0=0,cut1=0,cut2=0,cut3=0,cut4=0;
        Double_t a;
        Double_t c;
	for (int i = 0; i < nentries; i++) {
      t1->GetEntry(i);
    bool Zjets = ptlep1 > 20. && ptlep2 > 20.&& abs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep >70. && massVlep < 110; 
    bool Leading_photon=photon_isprompt[0] != 1  &&  photon_drla[0]>0.3 && photon_drla2[0]>0.3;
    bool medium_cut= photon_hoe[0]<0.0396  && photon_nhiso[0]<2.725 + 0.0148*photon_pt[0] + 0.000017*photon_pt[0]*photon_pt[0] && photon_phoiso[0]<2.571 + 0.0047*photon_pt[0]&&photon_eta[0]<1.4442&&photon_sieie[0]<0.018;
    // no sieie cut and photon_chiso cut.
    bool loose_cut= photon_hoe[0]<0.0597  && photon_nhiso[0]<10.910 + 0.0148*photon_pt[0] + 0.000017*photon_pt[0]*photon_pt[0] && photon_phoiso[0]<3.630 + 0.0047*photon_pt[0];
       a = photon_sieie[0];
       c = photon_chiso[0];
    // no sieie cut and photon_chiso cut.
	  cut0++; //total events before any cuts;

		if (!(Zjets==true))
	       continue;
		cut1++;

        if (!(Leading_photon==true))
	       continue;
		cut2++;

         if (!(loose_cut==true)){
            continue;
            if(photon_chiso[0]<1.295) {h21->Fill(a);hh21->Fill(a,c);}
            if(photon_chiso[0]>4)     {h22->Fill(a);hh22->Fill(a,c);}
            if(photon_chiso[0]>6)     {h23->Fill(a);hh23->Fill(a,c);}
           }
         cut3++;

	  if (!(medium_cut==true)){
	          continue;
          if(photon_chiso[0]<0.441) {h11->Fill(a);hh11->Fill(a,c);}
          if(photon_chiso[0]>2)     {h12->Fill(a);hh12->Fill(a,c);}
          if(photon_chiso[0]>4)     {h13->Fill(a);hh13->Fill(a,c);}
          } 
        cut4++;
	newtree1->Fill(); //fill the brach one entry
	}
	newtree1->Write(); //fill this tree into KEY from OBJ
	newfile1->Close();
	
	//print some information
	std::cout << "The total events are : " << cut0 << std::endl;
	std::cout << "Zjets cut       	   : " << cut1 << std::endl;
    std::cout << "Leading photon cut   : " << cut2 << std::endl;
    std::cout << "loose  ID cut  	   : " << cut3 << std::endl;
    std::cout << "medium ID cut  	   : " << cut4 << std::endl;
}
