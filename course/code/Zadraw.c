{
 TString b ="photon_sieie0";
 TFile *f = new TFile("official_ZA.root");
 f->cd("treeDumper");
 TTree *tr =(TTree*)f->Get("ZPKUCandidates");
 Double_t ptlep1,ptlep2,etalep1,etalep2,massVlep;
 Int_t nlooseeles,nloosemus;
 Double_t photon_drla[6],photon_drla2[6],photon_sieie[6],photon_chiso[6];
 Int_t photon_isprompt[6];


 ZPKUCandidates->SetBranchAddress("nloosemus",&nloosemus);
 ZPKUCandidates->SetBranchAddress("nlooseeles",&nlooseeles);
 ZPKUCandidates->SetBranchAddress("ptlep1",&ptlep1);
 ZPKUCandidates->SetBranchAddress("ptlep2",&ptlep2);
 ZPKUCandidates->SetBranchAddress("etalep1",&etalep1);
 ZPKUCandidates->SetBranchAddress("etalep2",&etalep2);
 ZPKUCandidates->SetBranchAddress("massVlep",&massVlep);
 ZPKUCandidates->SetBranchAddress("photon_isprompt",photon_isprompt);
 ZPKUCandidates->SetBranchAddress("photon_drla",photon_drla);
 ZPKUCandidates->SetBranchAddress("photon_drla2",photon_drla2);
 ZPKUCandidates->SetBranchAddress("photon_sieie",photon_sieie);
 ZPKUCandidates->SetBranchAddress("photon_chiso",photon_chiso);
 
 Double_t a,c;
 Int_t nentries = ZPKUCandidates->GetEntriesFast();
 cout<<"nentries = "<<nentries<<endl;
// nentries=10000;
 Int_t bin=200;
 Double_t xlow= 0.;
 Double_t xhigh= 0.036;

 gStyle->SetOptStat(0);
 gStyle->SetPadGridX(1);
 gStyle->SetPadGridY(1);
 gStyle->SetPadTickX(1);
 gStyle->SetPadTickY(1);
 gStyle->SetAxisColor(1, "XYZ");
 gStyle->SetStripDecimals(kTRUE);
 gStyle->SetTickLength(0.03, "XYZ");

 TH1D *h1 = new TH1D("h1","",bin,xlow,xhigh);
 TH1D *h2 = new TH1D("h2","",bin,xlow,xhigh);
 TH2D *h3 = new TH2D("h3","",500,0,0.07,500,-0.2,0.7);
 TH2D *h33 = new TH2D("h33","",500,0.,0.06,500,0,150);
// bool Zjets = ptlep1 > 20. && ptlep2 > 20.&& abs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep >70. && massVlep < 110 
// bool Leading_photon=photon_isprompt[0] != 1  &&  photon_drla[0]>0.3 && photon_drla2[0]>0.3;
 for(Int_t i=0;i<nentries;i++){
      ZPKUCandidates->GetEntry(i);
      a=photon_sieie[0];
      c=photon_chiso[0];
        if(ptlep1 > 20. && ptlep2 > 20. &&abs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep >70. && massVlep < 110  && photon_isprompt[0] != 1  &&  photon_drla[0]>0.3 &&photon_drla2[0]>0.3 )
         { 
           if( photon_chiso[0] <0.441 )
               {
               h1->Fill(a);
               h3->Fill(a,c);
               }
           if (photon_chiso[0] >1.2 ) 
                {
                h2->Fill(a);
                h33->Fill(a,c);
                }
          }
      }  
TCanvas *c1=new TCanvas("c1","Zjets and leading photon",900,600);   
 c1->SetGrid();
 c1->SetLogy();
 h1->SetLineColor(kBlue);
 h1->SetTitle("Zjetscuts and Leading photon");
 h1->GetXaxis()->SetTitle("photon_sieie[0]");
 h1->GetYaxis()->SetTitle("count");
 h1->SetLineStyle(1);
 h1->SetLineWidth(3);
 Double_t s1=1/h1->Integral();
 cout<<"s1 = "<<s1<<endl;
 h1->Scale(s1);
 h1->Draw();
 h2->SetLineStyle(2);
 h2->SetLineColor(kRed);
 h2->SetLineWidth(3);
 Double_t s2=1/h2->Integral();
 cout<<"s2 = "<<s2<<endl;
 h2->Scale(s2);
 h2->Draw("same");
 TLegend *l1 = new TLegend(0.7,0.7,0.9,0.9);
 l1->AddEntry(h1,"photon_chiso[0]<0.441"); 
 l1->AddEntry(h2,"photon_chiso[0]>1.2");
 l1->Draw(); 
 c1->Print("./"+b+"_ZLscale.eps");


TCanvas *c2=new TCanvas("c2","two dimension distribution",900,600);
 c2->SetLogz();
 h3->SetTitle("ZJetscut&&Leading photon&&photon_chiso[0]<0.441; photon_sieie[0]; photon_chiso[0]");
 //h3->Draw("COLTEXTZ");
 Double_t cc1=h3->GetCorrelationFactor();
 cout<< "cc1 = "<<cc1<<endl;
 TPaveText *pt1 = new TPaveText(0.60, 0.30, 0.90, 0.40, "BRNDC");
 pt1->SetFillColor(19);
 pt1->SetBorderSize(1);
 pt1->SetTextAlign(12);
 pt1->SetTextSize(0.04);
 char cor1[20];
 sprintf(cor1,"%f",cc1);
 TString par1=cor1;
 TString Par1 = "#rho = " + par1;
 TText *text1 = pt1->AddText(Par1);
 h3->Draw("COLZ");
 pt1->Draw();
 c2->Print("./sieieVSchiso_ZLsc.eps");
TCanvas *c5=new TCanvas("c5","two dimension distribution",900,600);
 c5->SetLogz();
 h33->SetTitle("Zjets&&Leading photon&&photon_chiso[0]>1.2; photon_sieie[0]; photon_chiso[0]");
 //h33->Draw("COLTEXTZ");
 Double_t cc2=h33->GetCorrelationFactor();
 cout<< "cc2 = "<<cc2<<endl;
 TPaveText *pt2 = new TPaveText(0.60, 0.30, 0.90, 0.40, "BRNDC");
 pt2->SetFillColor(19);
 pt2->SetBorderSize(1);
 pt2->SetTextAlign(12);
 pt2->SetTextSize(0.04);
 char cor2[20];
 sprintf(cor2,"%f",cc2);
 TString par2=cor2;
 TString Par2 = "#rho = " + par2;
 TText *text2 = pt2->AddText(Par2);
 h33->Draw("COLZ");
 pt2->Draw();
 c5->Print("./sieieVSchiso_ZLsc.eps");
}
