void draw(TString name){
  gStyle->SetOptFit();
  TString file = name+".txt";
  TGraph* gr = new TGraph("./"+file,"%lg %lg");
  TF1 *pol2 = new TF1("pol2","pol2",-240,240);
  gr->SetLineColor(kRed);
  gr->SetMarkerStyle(24);
  gr->SetMarkerColor(kBlue);
  gr->SetMarkerSize(1.0);
  pol2->SetLineColor(2);
  pol2->SetLineWidth(2);
  pol2->SetLineStyle(2);
  gr->Fit("pol2");
  TCanvas*c1 =new TCanvas("c1",name,700,600);
  c1->SetGrid();
  gr->Draw("AP");
  gr->GetXaxis()->CenterTitle();
  gr->GetXaxis()->SetTitle(name);
  gr->GetXaxis()->SetTitleSize(0.06);
  gr->GetXaxis()->SetTitleOffset(0.6);
  gr->GetXaxis()->SetTitleFont(30); 
  gr->GetXaxis()->SetLabelFont(22); 

  gr->GetYaxis()->CenterTitle();
  gr->GetYaxis()->SetTitle("cross section /pb");
  gr->GetYaxis()->SetTitleSize(0.06);
  gr->GetYaxis()->SetTitleOffset(0.8);
  gr->GetYaxis()->SetTitleFont(30); 
  gr->GetYaxis()->SetLabelFont(22); 
  gr->SetTitle(name);
      
  c1->Print("./"+name+".eps");
}

int acdraw(){
  TString name[5]={"cwww","cw","cb","cpwww","cpw"};
  for(Int_t i=0;i<5;i++){draw(name[i]); }

  return 0;
}
