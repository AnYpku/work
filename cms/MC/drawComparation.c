void drawComparation(){

// Load shared library
// gSystem->Load("/store/home/andy/MC/MG5/MG5_aMC_v2_3_3/ExRootAnalysis/libExRootAnalysis.so");
 gSystem->Load("/usr/local/Cellar/madgraph5_amcatnlo/2.6.0/ExRootAnalysis/libExRootAnalysis.so");
// gSystem->Load("/home/qliphy/Desktop/common/root/lib/root/libPhysics.so");
// Create chain of root trees


 float inix= 0.0;
 float finx= 2000.0;
 float nbin= 50.0;

 
TString IFile1 =   "./pp2lnew/pp2l-nlo-mg.root";
TChain chain("LHEF");
chain.Add(IFile1); 
// Create object of class ExRootTreeReader
 ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
 Long64_t numberOfEntries = treeReader->GetEntries();
// Get pointers to branches used in this analysis
 TClonesArray *branchEvent = treeReader->UseBranch("Event");
 TClonesArray *branchParticle = treeReader->UseBranch("Particle");
//  TClonesArray *branchJet = treeReader->UseBranch("Jet");
 TH1F *h1= new TH1F("1_Mjj","test histogram",nbin,inix,finx);
 h1->Sumw2();
 TLorentzVector J1, J2, JJ;
for(int i=0; i<=numberOfEntries-1; i++)
{
////*****************************************************************
    J1.SetPtEtaPhiE(0.,0.,0.,0.);
    J2.SetPtEtaPhiE(0.,0.,0.,0.);
    treeReader->ReadEntry(i);
    TRootLHEFEvent *event=(TRootLHEFEvent*) branchEvent->At(0);
    int np=event->Nparticles;
    for(int j=2; j<np; j++) {
     TRootLHEFParticle *particle1=(TRootLHEFParticle*) branchParticle->At(j);
      if((abs(particle1->PID)<6 || (particle1->PID)==21) ) {
          if(J1.E()>0){
          J2.SetPtEtaPhiE(particle1->PT,particle1->Eta,particle1->Phi,particle1->E);
             }
          else{  
          J1.SetPtEtaPhiE(particle1->PT,particle1->Eta,particle1->Phi,particle1->E);
             }
        }
     }
    JJ=J1+J2;
    h1->Fill(JJ.M(), 4.594/float(numberOfEntries)); 
////*****************************************************************
}
TFile *f2=new TFile("./pp2lnew/pp2l-nlo-vf.root");

TH1F *h2=(TH1F *) H_12_LO->Clone();
TH1F *h3=(TH1F *) H_12_NLO->Clone();


      TCanvas *c1= new TCanvas("c1","test graph",750,800);

      gStyle->SetOptStat(0);
      c1->Range(0,-0.5,1,1);
      c1->SetFillColor(0);
      c1->SetBorderMode(0);
      c1->SetBorderSize(2);
//      c1->SetGridx();
//      c1->SetGridy();
//      c1->SetTickx(1);
//      c1->SetTicky(1);
      c1->SetLeftMargin(0.14);
      c1->SetRightMargin(0.05);
      c1->SetTopMargin(0.07);
      c1->SetBottomMargin(0.3);
      c1->SetFrameBorderMode(0);


      gStyle->SetPadBorderMode(0);
      gStyle->SetOptStat(0);
      gStyle->SetPadGridX(1);
      gStyle->SetPadGridY(1);
      gStyle->SetPadTickX(1);
      gStyle->SetPadTickY(1);
      gStyle->SetPadTopMargin(0.07);
      gStyle->SetPadBottomMargin(0.3);
      gStyle->SetPadRightMargin(0.05);
      gStyle->SetPadLeftMargin(0.14);
      gStyle->SetPadTickX(1);
      gStyle->SetPadTickY(1);
      gStyle->SetAxisColor(1, "XYZ");
      gStyle->SetStripDecimals(kTRUE);
      gStyle->SetTickLength(0.03, "XYZ");
      gStyle->SetNdivisions(510, "XYZ");

      TPad *top_pad = new TPad("top_pad", "top_pad",0,0.3, 1.0, 1.0);
      top_pad->Draw();
      top_pad->cd();  
      top_pad->SetBottomMargin(0.1);
      top_pad->SetLogy();

//      c1->Divide(1,2,0,0);
//      c1->cd(1);
      h1->SetTitle("VBF Z(#rightarrow e^{+}e^{-})+2Jets at 13TeV LHC");
//      h1->GetXaxis()->SetTitle("M_{jj} [GeV] ");
      h1->GetYaxis()->SetTitle("#sigma (fb) ");
      h1->GetXaxis()->CenterTitle();
      h1->GetYaxis()->CenterTitle();
      h1->SetStats(kFALSE);
      h1->SetLineColor(kBlack);
      h1->SetLineWidth(3);
      h1->SetMarkerStyle(20);
      h1->GetXaxis()->SetTitleOffset(0.6);
      h1->GetYaxis()->SetTitleOffset(0.8);
      h1->SetMinimum(0.001);

      h3->SetLineColor(kRed);
      h3->SetLineWidth(3);
      h3->SetMarkerStyle(20);

      h2->SetLineColor(kBlue);
      h2->SetLineWidth(3);
      h2->SetMarkerStyle(20);
      
      h2->Scale(h1->GetMaximum()/h2->GetMaximum());
      h3->Scale(h1->GetMaximum()/h3->GetMaximum());
      h1->Draw("Hist");
      h2->Draw("same");
      h3->Draw("same");
     
      TLegend *l1 = new TLegend(0.75,0.75,0.9,0.9);
      l1->SetBorderSize(1);
      l1->SetFillColor(0);
      l1->AddEntry(h1,"MG");
      l1->AddEntry(h2,"VBFNLO LO");
      l1->AddEntry(h3,"VBFNLO NLO");
      l1->Draw();

//      c1->cd(2);
      TPad *bottom_pad = new TPad("bottom_pad","",0,0,1,0.3);
      bottom_pad->Draw();
      bottom_pad->cd();
      bottom_pad->SetTopMargin(0);
     
      TH1F * h4 = (TH1F *) h3 -> Clone();
      h4->Divide(h2);
      h4->Draw("Hist");
   
      h4->SetTitle("");
      h4->GetXaxis()->SetTitle("M_{jj} [GeV] ");
      h4->GetYaxis()->SetTitle("K factor ");
      h4->GetXaxis()->CenterTitle();
      h4->GetYaxis()->CenterTitle();
      h4->SetLineColor(kBlack);
      h4->GetXaxis()->SetTitleOffset(0.9);
      h4->GetYaxis()->SetTitleOffset(0.22);
      h4->GetXaxis()->SetTitleSize(0.15);
      h4->GetYaxis()->SetTitleSize(0.15);
      h4->GetXaxis()->SetLabelSize(0.12);
      h4->GetYaxis()->SetLabelSize(0.1);
      h4->SetMaximum(1.35);
      h4->SetMinimum(0.);

}

