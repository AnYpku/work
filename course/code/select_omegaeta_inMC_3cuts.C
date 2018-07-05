{
	TChain fit4c("fit4c");//fit4c should be "your tree name"
	fit4c.Add("/scratchfs/bes/anying/664/omegaeta/analysis/rootfiles/root/omegaeta_data12.root");
	//for Array variables/branches
/*	double Lamb[2]; //define variable to each branch that you want to use; the variable type should be same
	double Lambp[2];
	fit4c->SetBranchAddress("Lamb", Lamb); // Lamb is the variable/branch in the tree fit4c
	fit4c->SetBranchAddress("Lambp", Lambp);
	//			 |       |
	//			 |    this is the one you defined in line 6
	//			 |
	//			 |
	//		   this is the one in the 
	//		tree "fit4c", in your root file "filename.root"
*/
	//for common variables/branches
	double chi2;
	double mpi0,meta,m3pi[4];
	fit4c->SetBranchAddress("chi2", &chi2);
    fit4c->SetBranchAddress("mpi0", &mpi0);
    fit4c->SetBranchAddress("meta", &meta);
	fit4c->SetBranchAddress("m3pi",&m3pi);

	TFile *newfile = new TFile("omegaeta_data12_threecuts.root", "recreate");
	//in the new.root files, all events satisfy your cuts 
	TTree *newtree = fit4c->CloneTree(0);
	int nentries = fit4c->GetEntriesFast();

	int cut0 = 0;
	int cut1 = 0;
	int cut2 = 0;
	int cut3 = 0;
	int cut4 = 0;
	int cut5 = 0;
	int cut6 = 0;
	int cut7 = 0;
	for (int i = 0; i < nentries; i++) {
		fit4c->GetEntry(i); //first you should get the entry: fit4c->GetEntry(i);
		cut0++; //total events before any cuts;

		if (!(chi2 < 50))
			continue;
		cut1++;

                if (!(mpi0>0.129967358&&mpi0<0.150004325))
	       		continue;
		cut2++;

	        if (!(meta>0.42&&meta<0.65))
		    continue;
        	cut3++;
        
  
                if (!(m3pi[0]>0.7&&m3pi[0]<0.87))
                continue;
                cut4++;
              
               
		newtree->Fill(); //fill the brach one entry
	}
	newtree->Write(); //fill this tree into KEY from OBJ
//	newfile->Write(); //fill all trees into KEY from OBJ
	newfile->Close();

	//print some information
	std::cout << "The total events are		: " << cut0 << std::endl;
        std::cout << "chi2<50				: " << cut1 << std::endl;
	std::cout << "0.129967358<mpi0<0.150004325       	: " << cut2 << std::endl;
        std::cout << "0.42<meta<0.65		: " << cut3 << std::endl;
        std::cout << "0.7000<m3pi<0.87   	: " << cut4 << std::endl;
}
