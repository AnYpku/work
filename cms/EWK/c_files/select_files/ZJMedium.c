{
 TString b ="zj7mediuma0426";
 TFile *f = new TFile("../rootfiles/ZJ_loose.root");
 TTree *t1 =(TTree*)f->Get("demo");
 //the needed variables in the root file
 Double_t ptlep1,ptlep2,etalep1,etalep2,massVlep;
 Double_t scalef;
 Int_t nlooseeles,nloosemus;
 Double_t photon_drla[6],photon_pt[6],photon_drla2[6],photon_sieie[6],photon_chiso[6];
 double photon_hoe[6];
 double photon_nhiso[6];
 double photon_phoiso[6];
 double photon_eta[6];
 int photon_isprompt[6];
 t1->SetBranchAddress("photon_isprompt",photon_isprompt); t1->SetBranchAddress("photon_hoe",photon_hoe);
 t1->SetBranchAddress("photon_nhiso",photon_nhiso);
 t1->SetBranchAddress("photon_phoiso",photon_phoiso);
 t1->SetBranchAddress("photon_pt",photon_pt);
 t1->SetBranchAddress("photon_eta",photon_eta);
 t1->SetBranchAddress("scalef",&scalef);
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
 t1->SetBranchAddress("photon_pt",photon_pt);
 
 Int_t bin=50;
 Double_t xlow= 0.;
 Double_t xhigh= 0.018;

 gStyle->SetOptStat(0);
 gStyle->SetPadGridX(1);
 gStyle->SetPadGridY(1);
 gStyle->SetPadTickX(1);
 gStyle->SetPadTickY(1);
 gStyle->SetAxisColor(1, "XYZ");
 gStyle->SetStripDecimals(kTRUE);
 gStyle->SetTickLength(0.03, "XYZ");

    TH1D *h11=new TH1D("h11","chiso<0.441",bin,0,xhigh);//Zjets && leding_photon && medium_cut && photon_chiso<1.416
    TH1D *h12=new TH1D("h12","10>chiso>4",bin,0,xhigh);////Zjets && leding_photon && medium_cut && photon_chiso>2
    TH1D *h13=new TH1D("h13","4>chiso>2",bin,0,xhigh);//Zjets && leding_photon && medium_cut && photon_chiso>4
    TH1D *h14=new TH1D("h14","chiso>4",bin,0,xhigh);//Zjets && leding_photon && medium_cut && photon_chiso>4
    TH1D *h15=new TH1D("h15","chiso>2",bin,0,xhigh);//Zjets && leding_photon && medium_cut && photon_chiso>4

    TH1D *h21=new TH1D("h21","chiso<1.295",bin,0,xhigh);////Zjets && leding_photon && loose_cut && photon_chiso<2.839
    TH1D *h22=new TH1D("h22","chiso>0.1",bin,0,xhigh);//Zjets && leding_photon && loose_cut && photon_chiso>4
    TH1D *h23=new TH1D("h23","chiso>6",bin,0,xhigh);//Zjets && leding_photon && loose_cut && photon_chiso>6
    
    TH2D *hh11 = new TH2D("hh11","chiso and sieie with chiso<0.441",500,0,xhigh,500,-1,0.5);//Zjets && leding_photon && medium_cut && photon_chiso<1.416
    TH2D *hh12 = new TH2D("hh12","chiso and sieie with 0.1<chiso<10",500,0,xhigh,500,0,10);//Zjets && leding_photon && medium_cut && photon_chiso>2
    TH2D *hh13 = new TH2D("hh13","chiso and sieie with 2<chiso<4", 500,0,xhigh,500,1,4);//Zjets && leding_photon && medium_cut && photon_chiso>4

    TH2D *hh21 = new TH2D("hh21","chiso and sieie with chiso<1.295",500,0,0.07,500,0,150);//Zjets && leding_photon && loose_cut && photon_chiso<2.839
    TH2D *hh22 = new TH2D("hh22","chiso and sieie with chiso>0.1",500,0,0.07,500,0,150);    //Zjets && leding_photon && loose_cut && photon_chiso>4
    TH2D *hh23 = new TH2D("hh23","chiso and sieie with chiso>6",500,0,0.07,500,0,150);    //Zjets && leding_photon && loose_cut && photon_chiso>6
 bool Zjets[6],Leading_photon[6],medium_cut[6],loose_cut[6];
 Int_t nentries = t1->GetEntriesFast();
 cout<<"nentries = "<<nentries<<endl;
// nentries=100;
 vector<double> vector_pt;
// vector<double> vector_sieie;
 vector<double>::iterator biggest_pt;
 double sieie,chiso;
 int position=0,size;
// vector_pt.push_back(-100);
 for(Int_t i=0;i<nentries;i++){
    t1->GetEntry(i);
    for(Int_t j=0;j<6;j++){
         Zjets[j] = ptlep1 > 20. && ptlep2 > 20.&& abs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep >70. && massVlep < 110;
         Leading_photon[j]=photon_isprompt[j] != 1  &&  photon_drla[j]>0.7 && photon_drla2[j]>0.7&& photon_pt[j]<400.&&photon_pt[j]>25;
         medium_cut[j]= photon_hoe[j]<0.0396  && photon_nhiso[j]<2.725 + 0.0148*photon_pt[j] + 0.000017*photon_pt[j]*photon_pt[j] && photon_phoiso[j]<2.571 + 0.0047*photon_pt[j]&&abs(photon_eta[j])<1.4442;
         if(Zjets[j]&&Leading_photon[j]&&medium_cut[j]){
            vector_pt.push_back(photon_pt[j]);
        }
         else {vector_pt.push_back(0);}
      }//fill the vector_pt
   size=vector_pt.size();
   biggest_pt = max_element(begin(vector_pt),end(vector_pt));
   if(*biggest_pt==0){
       vector_pt.clear();
       continue;}
   position = distance( begin(vector_pt), biggest_pt);
   sieie = photon_sieie[position];
   chiso = photon_chiso[position];
//   cout<<"i = "<<i<<"  "<<"size = "<<size<<endl;
//   cout<<"the max pt " <<*biggest_pt<<endl<<"position "<<position<<endl<<"sieie "<<sieie<<endl;
//   cout<<"photon_sieie"<<photon_sieie[position]<<endl;
//   cout<<endl;
   if(photon_chiso[position]<0.441) 
     {
     h11->Fill(photon_sieie[position],scalef);
     //h11->Fill(photon_sieie[position]);
     hh11->Fill(photon_sieie[position],photon_chiso[position]);
     } 
   if(photon_chiso[position]<10 &&photon_chiso[position]>4)   
     {
     h12->Fill(photon_sieie[position],scalef);
     //h12->Fill(photon_sieie[position]);
     hh12->Fill(photon_sieie[position],photon_chiso[position]);
     }  
   if(photon_chiso[position]<4 && photon_chiso[position]>2)   
      {
      h13->Fill(photon_sieie[position],scalef);
      //h13->Fill(photon_sieie[position]);
      hh13->Fill(photon_sieie[position],photon_chiso[position]);
      }
   if(photon_chiso[position]>4 )   
      {
      h14->Fill(photon_sieie[position],scalef);
      //h14->Fill(photon_sieie[position]);
      }
   if(photon_chiso[position]>2 )   
      {
      h15->Fill(photon_sieie[position],scalef);
      //h15->Fill(photon_sieie[position]);
      }
   vector_pt.clear();
//   vector_sieie.clear();
   }  
TCanvas *c1=new TCanvas("c1","Zjets and leading photon",900,600);   
 c1->SetGrid();
// c1->SetLogy();
 h11->SetLineColor(kBlue);
 h11->SetTitle("Zjetscuts and Leading photon and medium ID ");
 h11->GetXaxis()->SetTitle("photon_sieie");
 h11->GetYaxis()->SetTitle("count");
 h11->SetLineStyle(1);
 h11->SetLineWidth(3);
 Double_t s1=1/h11->Integral();
 cout<<"s1 = "<<s1<<endl;
// h11->Scale(s1);
 h11->DrawNormalized("HIST");
 h12->SetLineStyle(2);
 h12->SetLineColor(kRed);
 h12->SetLineWidth(3);
 Double_t s2=1/h12->Integral();
 cout<<"s2 = "<<s2<<endl;
// h12->Scale(s2);
 h13->SetLineStyle(3);
 h13->SetLineColor(kGreen);
 h14->SetFillColor(55);
 h14->SetFillStyle(3002);
 h13->SetLineWidth(3);
 Double_t s3=1/h13->Integral();
 cout<<"s3 = "<<s3<<endl;
// h13->Scale(s3);
 h14->SetLineStyle(3);
 //h14->SetLineColor(kPurple);
 h14->SetLineWidth(3);
 h14->SetFillColor(51);
 h14->SetFillStyle(3002);
 Double_t s4=1/h14->Integral();
 cout<<"s4 = "<<s4<<endl;

 h15->SetLineStyle(3);
 h15->SetLineColor(6);
 h15->SetLineWidth(3);
 Double_t s5=1/h15->Integral();
 cout<<"s5 = "<<s5<<endl;

 h12->DrawNormalized("HIST,SAME");
 h13->DrawNormalized("HIST,SAME");
 h14->DrawNormalized("HIST,SAME");
 h15->DrawNormalized("HIST,SAME");
 TLegend *l1 = new TLegend(0.2,0.7,0.4,0.9);
 l1->AddEntry(h11,"photon_chiso<0.441"); 
 l1->AddEntry(h12,"4<photon_chiso<10");
 l1->AddEntry(h13,"2<photon_chiso<4");
 l1->AddEntry(h14,"photon_chiso>4");
 l1->AddEntry(h15,"photon_chiso>2");
 l1->Draw(); 
 c1->Print("./"+b+"_sieie.eps");


TCanvas *c2=new TCanvas("c2","two dimension distribution",900,600);
 c2->SetLogz();
 hh11->SetTitle("ZJetscut&&Leading photon&&mediumID&&photon_chiso[0]<0.441; photon_sieie; photon_chiso");
 //h3->Draw("COLTEXTZ");
 Double_t cc1=hh11->GetCorrelationFactor();
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
 hh11->Draw("COLZ");
 pt1->Draw();
 c2->Print("./"+b+"_hh11.eps");
TCanvas *c3=new TCanvas("c3","two dimension distribution",900,600);
 c3->SetLogz();
 hh12->SetTitle("Zjets&&Leading photon&&MediumID&&0.1<photon_chiso[0]<10; photon_sieie; photon_chiso");
 //h33->Draw("COLTEXTZ");
 Double_t cc2=hh12->GetCorrelationFactor();
 cout<< "cc2 = "<<cc2<<endl;
 TPaveText *pt2 = new TPaveText(0.60, 0.10, 0.90, 0.20, "BRNDC");
 pt2->SetFillColor(19);
 pt2->SetBorderSize(1);
 pt2->SetTextAlign(12);
 pt2->SetTextSize(0.04);
 char cor2[20];
 sprintf(cor2,"%f",cc2);
 TString par2=cor2;
 TString Par2 = "#rho = " + par2;
 TText *text2 = pt2->AddText(Par2);
 hh12->Draw("COLZ");
 pt2->Draw();
 c3->Print("./"+b+"_hh12.eps");
TCanvas *c4=new TCanvas("c4","two dimension distribution",900,600);
 c4->SetLogz();
 hh13->SetTitle("Zjets&&Leading photon&&MediumID&&2<photon_chiso[0]<4; photon_sieie; photon_chiso");
 //h33->Draw("COLTEXTZ");
 Double_t cc3=hh13->GetCorrelationFactor();
 cout<< "cc3 = "<<cc3<<endl;
 TPaveText *pt3 = new TPaveText(0.60, 0.10, 0.90, 0.20, "BRNDC");
 pt3->SetFillColor(19);
 pt3->SetBorderSize(1);
 pt3->SetTextAlign(12);
 pt3->SetTextSize(0.04);
 char cor3[20];
 sprintf(cor3,"%f",cc3);
 TString par3=cor3;
 TString Par3 = "#rho = " + par3;
 TText *text3 = pt3->AddText(Par3);
 hh13->Draw("COLZ");
 pt3->Draw();
 c4->Print("./"+b+"_hh13.eps");
}
