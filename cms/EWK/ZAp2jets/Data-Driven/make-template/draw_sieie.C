Double_t lowpt[9]= {25,30,35,40,45,50,60,80,100};
Double_t highpt[9]={30,35,40,45,50,60,80,120,400};
void draw(TCanvas *c,TH1D *h1,TH1D *h2,TH1D *h3,Double_t ptlow,Double_t pthigh){
    c=new TCanvas("c","Zjets and leading photon",900,600);
    c->SetGrid();
   // c->SetLogy();
    h1->SetLineColor(51);
    h1->SetTitle(Form("Barrel Region  %0.f < photon PT <% 0.f",ptlow,pthigh));
    h1->GetXaxis()->SetTitle("#sigma_{i#eta i#eta}");
    h1->GetYaxis()->SetTitle("count");
    h1->SetLineStyle(1);
    h1->SetLineWidth(3);
    h1->SetFillColor(51);
    h1->SetFillStyle(3002);
   double s1=1/h1->Integral();
         cout<<Form(" %0.f<photon_pt<%0.f ",ptlow,pthigh);
         cout<<"s1 = "<<s1<<endl;
         h2->SetLineColor(2);
   // h1->Scale(s1);
    h2->SetLineStyle(2);
    h2->SetLineWidth(3);
    double s2=1/h2->Integral();
    cout<<Form(" %0.f<photon_pt<%0.f ",ptlow,pthigh);
             cout<<"  s2 = "<<s2<<endl;
       // h2[i]->Draw("HIST,SAME");
       // h2->Scale(s2);
   //   }
    h3->SetLineStyle(3);
    Int_t ci=ci = TColor::GetColor("#3399ff");
    h3->SetLineColor(ci);
    h3->SetFillColor(ci);
    h3->SetFillStyle(3008);
    h3->SetLineWidth(3);
    double s3=1/h3->Integral();
         cout<<Form(" %0.f<photon_pt<%0.f ",ptlow,pthigh);
         cout<<"s3 = "<<s3<<endl;
   // h3->Scale(s3);
   // h1->DrawNormalized("HIST");
   // h2->DrawNormalized("HIST,SAME");
   // h3->DrawNormalized("HIST,SAME");
    h1->Draw("HIST");
    h2->Draw("HIST,SAME");
    h3->Draw("HIST,SAME");
    TLegend *l1 = new TLegend(0.5,0.6,0.9,0.9);
    l1->AddEntry(h1,"data template" );
    l1->AddEntry(h2,"true template" );
    l1->AddEntry(h3,"fake template");
    l1->Draw();
    c->Print(Form("./eps/photon_sieiept%0.f_%0.f.eps",ptlow,pthigh));
    delete c;
    delete h1;
    delete h2;
    delete h3;
}
int draw_sieie(){
    TFile* fdata = new TFile("/Users/andy/work/cms/EWK/ZAp2jets/Data-Driven/make-template/root/Data_template-cutLEP-outDMuon.root");
    TFile* ftrue = new TFile("/Users/andy/work/cms/EWK/ZAp2jets/Data-Driven/make-template/root/True_template-cutLEP-outZA.root");
    TFile* ffake = new TFile("/Users/andy/work/cms/EWK/ZAp2jets/Data-Driven/make-template/root/Fake_template-cutLEP-outDMuon.root");
    TH1D* t1[9];
    TH1D* t2[9];
    TH1D* t3[9];
    TCanvas*c1[9];
    for(Int_t i=0;i<9;i++){
      t1[i]=(TH1D*)fdata->Get(Form("h3_pt%0.f-%0.f",lowpt[i],highpt[i]));
      t2[i]=(TH1D*)ftrue->Get(Form("h1_pt%0.f-%0.f",lowpt[i],highpt[i]));
      t3[i]=(TH1D*)ffake->Get(Form("h2_pt%0.f-%0.f",lowpt[i],highpt[i]));
    }
   for(Int_t i=0;i<9;i++){
     c1[i]=new TCanvas(Form("pt%0.f-%0.f",lowpt[i],highpt[i]),"mediumID selection",900,600);
     draw(c1[i],t1[i],t2[i],t3[i],lowpt[i],highpt[i]);
     cout<<"######################################finish######################################"<<endl;
   }
  return 0;

}    
