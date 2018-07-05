 TString b ="0502h3";
 TString str="Zjets && Leading photon && MediumID ";
 TH1D *h21;
 TH1D *h22;
 TH1D *h23;
 TH1D *h24;
 TH1D *h25;
 TH1D *h2;
 TH1D *h3;
 TH1D *h4;
 TH1D *h5;
void tree(TTree*t1);
void histo();
void select(TTree*t1);
void draw(TCanvas*c1);
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
 void tree(TTree*t1) {
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
  }

 void histo(){
 Int_t bin=50;
 Double_t xlow= 0.;
 Double_t xhigh= 0.018;

 h21=new TH1D("h21","chiso<1.295",bin,0,xhigh);////Zjets && leding_photon && loose_cut && photon_chiso<2.839
 h22=new TH1D("h22","chiso>0.1",bin,0,xhigh);//Zjets && leding_photon && loose_cut && photon_chiso>4
 h23=new TH1D("h23","chiso>6",bin,0,xhigh);//Zjets && leding_photon && loose_cut && photon_chiso>6
 h24=new TH1D("h24","chiso>4",bin,0,xhigh);//Zjets && leding_photon && medium_cut && photon_chiso>4
 h25=new TH1D("h25","chiso>2",bin,0,xhigh);//Zjets && leding_photon && medium_cut && photon_chiso>4
  }

 void draw(TCanvas*c1){
 gStyle->SetOptStat(0);
 gStyle->SetPadGridX(1);
 gStyle->SetPadGridY(1);
 gStyle->SetPadTickX(1);
 gStyle->SetPadTickY(1);
 gStyle->SetAxisColor(1, "XYZ");
 gStyle->SetStripDecimals(kTRUE);
 gStyle->SetTickLength(0.03, "XYZ");

 c1=new TCanvas("c1","",900,600);   
 //c1->SetGrid();
 TPad *top_pad=new TPad("top_pad", "top_pad",0,0.2, 1.0, 1.0);
 top_pad->Draw();
 top_pad->cd();
 top_pad->SetBottomMargin(0.1);
// c1->SetLogy();
 h21->SetLineColor(51);
 h21->SetTitle(str);
 h21->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
 h21->GetYaxis()->SetTitle("count");
 h21->SetLineStyle(1);
 h21->SetLineWidth(3);
 h21->SetFillColor(51);
 h21->SetFillStyle(3002);
 h22->SetLineStyle(2);
 h22->SetLineColor(kRed);
 h22->SetLineWidth(3);
 h23->SetLineStyle(4);
 h23->SetLineColor(kGreen);
 h23->SetLineWidth(3);
 h24->SetLineStyle(2);
 h24->SetLineColor(kBlue);
 h24->SetLineWidth(3);

 h25->SetLineStyle(4);
 h25->SetLineColor(kBlack);
 h25->SetLineWidth(3);

 h21->DrawNormalized("HIST");
 h22->DrawNormalized("HIST,SAME");
 h23->DrawNormalized("HIST,SAME");
 h24->DrawNormalized("HIST,SAME");
 h25->DrawNormalized("HIST,SAME");
 TLegend *l1 = new TLegend(0.6,0.6,1.0,0.9);
 l1->AddEntry(h21,"photon_chiso<0.441"); 
 l1->AddEntry(h22,"4<photon_chiso<10");
 l1->AddEntry(h23,"2<photon_chiso<4");
 l1->AddEntry(h24,"photon_chiso>4");
 l1->AddEntry(h25,"photon_chiso>2");
 l1->Draw(); 


 c1->cd();
 TPad *bottom_pad=new TPad("bottom_pad", "bottom_pad", 0, 0., 1.0, 0.2);
 bottom_pad->Draw();
 bottom_pad->cd();
 bottom_pad->SetTopMargin(0);

 h2->SetTitle("");
 h2->SetLineColor(kRed);
 h3->SetLineColor(kGreen);
 h4->SetLineColor(kBlue);
 h5->SetLineColor(kBlack);
 h2->GetXaxis()->SetTitleOffset(0.9);
 h2->GetYaxis()->SetTitleOffset(0.22);
 h2->GetXaxis()->SetTitleSize(0.1);
 h2->GetYaxis()->SetTitleSize(0.1);
 h2->GetXaxis()->SetLabelSize(0.1);
 h2->GetYaxis()->SetLabelSize(0.1);
 h3->GetYaxis()->SetLabelSize(0.1);
 h4->GetYaxis()->SetLabelSize(0.1);
 h5->GetYaxis()->SetLabelSize(0.1);
 h2->SetMaximum(1.5);
 h2->SetMinimum(0.5);
 h3->SetMaximum(1.5);
 h3->SetMinimum(0.5);
 h4->SetMaximum(1.5);
 h4->SetMinimum(0.5);
 h5->SetMaximum(1.5);
 h5->SetMinimum(0.5);
// h2->Draw("P");
 h3->Draw("same");
// h4->Draw("P,SAME");
// h5->Draw("same");
 TLine *line = new TLine(0,1,0.018,1);
 line->SetLineColor(6);
 line->SetLineWidth(3);
 line->Draw();

 c1->Print("./"+b+"_sieie.eps");
 }
 void select(TTree*t1){
 bool Zjets[6],Leading_photon[6],medium_cut[6],loose_cut[6];
 Int_t nentries = t1->GetEntriesFast();
 cout<<"nentries = "<<nentries<<endl;
// nentries=100;
 vector<double> vector_pt;
 vector<double>::iterator biggest_pt;
 double sieie,chiso;
 int position=0,size;
 for(Int_t i=0;i<nentries;i++){
    t1->GetEntry(i);
    for(Int_t j=0;j<6;j++){
         Zjets[j] = ptlep1 > 20. && ptlep2 > 20.&& abs(etalep1) < 2.4 &&abs(etalep2) < 2.4 && nlooseeles == 0 && nloosemus < 3 && massVlep >70. && massVlep < 110;
         Leading_photon[j]=photon_isprompt[j] != 1  &&  photon_drla[j]>0.7 && photon_drla2[j]>0.7 && photon_pt[j]<400.&&photon_pt[j]>25;
         medium_cut[j]= photon_hoe[j]<0.0396  && photon_nhiso[j]<2.725 + 0.0148*photon_pt[j] + 0.000017*photon_pt[j]*photon_pt[j] && photon_phoiso[j]<2.571 + 0.0047*photon_pt[j]&&abs(photon_eta[j])<1.4442;
         loose_cut[j]= photon_hoe[j]<0.0597  && photon_nhiso[j]<(10.910 + 0.0148*photon_pt[j] + 0.000017*photon_pt[j]*photon_pt[j])*1 && photon_phoiso[j]<(3.63 + 0.0047*photon_pt[j])*1 &&abs(photon_eta[j])<1.4442;
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
   if(photon_chiso[position]<0.441) 
     {
     h21->Fill(photon_sieie[position],scalef);
     } 
   if(photon_chiso[position]<10 &&photon_chiso[position]>4)   
     {
     h22->Fill(photon_sieie[position],scalef);
     }  
   if(photon_chiso[position]<4 && photon_chiso[position]>2)   
      {
      h23->Fill(photon_sieie[position],scalef);
      }
   if(photon_chiso[position]>4 )   
      {
      h24->Fill(photon_sieie[position],scalef);
      }
   if(photon_chiso[position]>2 )   
      {
      h25->Fill(photon_sieie[position],scalef);
      }
   vector_pt.clear();
   }  
 Double_t s1=1/h21->Integral();
 cout<<"s1 = "<<s1<<endl;
 h21->Scale(s1);
 Double_t s2=1/h22->Integral();
 cout<<"s2 = "<<s2<<endl;
 h22->Scale(s2);
 Double_t s3=1/h23->Integral();
 cout<<"s3 = "<<s3<<endl;
 h23->Scale(s3);
 Double_t s4=1/h24->Integral();
 cout<<"s4 = "<<s4<<endl;
 h24->Scale(s4);
 Double_t s5=1/h25->Integral();
 cout<<"s5 = "<<s5<<endl;
 h25->Scale(s5);

 h2 = (TH1D *)h22->Clone();
 h2->Divide(h21);
 h3 =(TH1D *)h23->Clone();
 h3->Divide(h21);
 h4 = (TH1D *)h24->Clone();
 h4->Divide(h21);
 h5 = (TH1D *)h25->Clone();
 h5->Divide(h21);
 }
int main(){

 TFile *f = new TFile("../rootfiles/isprompno1/ZJ_loose.root");
 TTree *t =(TTree*)f->Get("demo");
 tree(t);
 histo();
 select(t);
 TCanvas *c1= new TCanvas("c1","test graph",750,500);
 draw(c1);





}
//TCanvas *c2=new TCanvas("c2","two dimension distribution",900,600);
// c2->SetLogz();
// hh11->SetTitle("ZJetscut&&Leading photon&&LooseID&&photon_chiso[0]<1.295; photon_sieie; photon_chiso");
// //h3->Draw("COLTEXTZ");
// Double_t cc1=hh21->GetCorrelationFactor();
// cout<< "cc1 = "<<cc1<<endl;
// TPaveText *pt1 = new TPaveText(0.60, 0.30, 0.90, 0.40, "BRNDC");
// pt1->SetFillColor(19);
// pt1->SetBorderSize(1);
// pt1->SetTextAlign(12);
// pt1->SetTextSize(0.04);
// char cor1[20];
// sprintf(cor1,"%f",cc1);
// TString par1=cor1;
// TString Par1 = "#rho = " + par1;
// TText *text1 = pt1->AddText(Par1);
// hh21->Draw("COLZ");
// pt1->Draw();
// c2->Print("./"+b+"_hh21.eps");
//TCanvas *c3=new TCanvas("c3","two dimension distribution",900,600);
// c3->SetLogz();
// hh22->SetTitle("Zjets&&Leading photon&&LooseID&&0.1<photon_chiso[0]<10; photon_sieie; photon_chiso");
// //h33->Draw("COLTEXTZ");
// Double_t cc2=hh22->GetCorrelationFactor();
// cout<< "cc2 = "<<cc2<<endl;
// TPaveText *pt2 = new TPaveText(0.60, 0.10, 0.90, 0.20, "BRNDC");
// pt2->SetFillColor(19);
// pt2->SetBorderSize(1);
// pt2->SetTextAlign(12);
// pt2->SetTextSize(0.04);
// char cor2[20];
// sprintf(cor2,"%f",cc2);
// TString par2=cor2;
// TString Par2 = "#rho = " + par2;
// TText *text2 = pt2->AddText(Par2);
// hh22->Draw("COLZ");
// pt2->Draw();
// c3->Print("./"+b+"_hh22.eps");
//TCanvas *c4=new TCanvas("c4","two dimension distribution",900,600);
// c4->SetLogz();
// hh23->SetTitle("Zjets&&Leading photon&&LooseID&&2<photon_chiso[0]<4; photon_sieie; photon_chiso");
// //h33->Draw("COLTEXTZ");
// Double_t cc3=hh23->GetCorrelationFactor();
// cout<< "cc3 = "<<cc3<<endl;
// TPaveText *pt3 = new TPaveText(0.60, 0.10, 0.90, 0.20, "BRNDC");
// pt3->SetFillColor(19);
// pt3->SetBorderSize(1);
// pt3->SetTextAlign(12);
// pt3->SetTextSize(0.04);
// char cor3[20];
// sprintf(cor3,"%f",cc3);
// TString par3=cor3;
// TString Par3 = "#rho = " + par3;
// TText *text3 = pt3->AddText(Par3);
// hh23->Draw("COLZ");
// pt3->Draw();
// c4->Print("./"+b+"_hh23.eps");
