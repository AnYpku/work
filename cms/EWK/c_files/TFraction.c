ofstream myfile("result_TFraction.txt");
void fit(float lowpt, float highpt, float lowchiso, float highchiso){
  
  TFile* fdata = TFile::Open(Form("data-output/rootfiles/data_photonandfake_pt%0.f-%0.f_chiso%0.f-%0.f.root",lowpt,highpt,lowchiso,highchiso));
  TFile* ffake = TFile::Open(Form("data-output/rootfiles/data_fake_pt%0.f-%0.f_chiso%0.f-%0.f.root",lowpt,highpt,lowchiso,highchiso));
  TFile* ftrue = TFile::Open(Form("data-output/rootfiles/data_photonreal_pt%0.f_%0.f.root",lowpt,highpt));

  TH1F* hdata_ = (TH1F*)fdata->Get(Form("h11_pt%0.f-%0.f",lowpt,highpt));
  TH1F* hfake_ = (TH1F*)fdata->Get(Form("h12_pt%0.f-%0.f_chiso%0.f-%0.f",lowpt,highpt,lowchiso,highchiso));
  TH1F* htrue_ = (TH1F*)ftrue->Get(Form("h23_pt%0.f-%0.f",lowpt,highpt));

  Int_t nBins = 9;
  Double_t bins[10];
     for (Int_t i=0;i<10;i++){
          bins[i] = 0.0022 + 0.001*i;
         }
  TH1* hdata = hdata_->Rebin(nBins, "hdata", bins);
  TH1* htrue = htrue_->Rebin(nBins, "htrue", bins);
  TH1* hfake = hfake_->Rebin(nBins, "hfake_data", bins);

  TObjArray* mc= new TObjArray(2);        // MC histograms are put in this array
  mc->Add(hfake);
  mc->Add(htrue);
  TFractionFitter* fit = new TFractionFitter(hdata,mc,"V"); // initialise
  fit->Constrain(1,0.0,1.0);               // constrain fraction 1 to be between 0 and 1
  fit->SetRangeX(1,9);                    // use only the first 15 bins in the fit
  Int_t status = fit->Fit();               // perform the fit
  std::cout << "fit status: " << status <<"  pt range "<<lowpt<<"GeV ~ "<<highpt<<"GeV chiso range"<<lowchiso<<" ~ "<<highchiso<< std::endl;
  if (status == 0) {                       // check on fit status
     TCanvas* c1 = new TCanvas(Form("c1-pt%0.f-%0.f_chiso%0.f-%0.f",lowpt,highpt,lowchiso,highchiso),"fit result",900,600);
     c1->SetGrid();
     TH1F* result = (TH1F*) fit->GetPlot();
     hdata->SetTitle(Form("Barrel region %0.f < pt < %0.f ",lowpt,highpt));                                                      
     hdata->SetMarkerStyle(20);
     hdata->SetMarkerSize(1.1);
     
     hdata->Draw("Ep");
     result->SetLineColor(kRed);
     result->Draw("same");
     Double_t chi2=fit->GetChisquare();
     Double_t value,error;
     fit->GetResult(0,value,error);
    char c[20],c2[20],c3[20];
    sprintf(c,"%f",chi2);
    sprintf(c2,"%f",value);
    sprintf(c3,"%f",error);
    TString s="chi2 = ";
    TString s2="value = ";
    TString s3="error = ";
    TString chisquare=s + c;
    TString v=s2 + c2;
    TString e=s3 + c3;

    TLatex *textchi2 = new TLatex(0.6, 0.5, chisquare);
	textchi2->SetNDC();
	textchi2->SetTextSize(0.05);
	textchi2->SetLineWidth(1);
	textchi2->Draw();
    TLatex *textvalue = new TLatex(0.6, 0.4, v);
	textvalue->SetNDC();
	textvalue->SetTextSize(0.05);
	textvalue->SetLineWidth(1);
	textvalue->Draw();
    TLatex *texterror = new TLatex(0.6, 0.3, e);
	texterror->SetNDC();
	texterror->SetTextSize(0.05);
	texterror->SetLineWidth(1);
	texterror->Draw();
    TString chiso =Form("%0.f<chiso<%0.f",lowchiso,highchiso);
    TLatex *textchiso = new TLatex(0.6, 0.6, chiso);
	textchiso->SetNDC();
	textchiso->SetTextSize(0.08);
	textchiso->SetLineWidth(1);
	textchiso->Draw();
     c1->SaveAs(Form("fakefraction_pt%0.f-%0.f_chiso%0.f-%0.f.eps",lowpt,highpt,lowchiso,highchiso));
    myfile<<Form("%0.f<Pt<%0.f   %0.f<chiso<%0.f",lowpt,highpt,lowchiso,highchiso)<<"\t"<<chi2<<"\t"<<value<<"\t"<<error<<endl;
   }
}
void run_fit(Int_t a,Int_t b){

    float lowchiso[10]={2,3,4,5,6,4,4,6,8,5};
    float highchiso[10]={4,5,6,7,8,9,10,10,10,12};
    Double_t lowpt[7] ={25,30,35,40,50,65,100};
    Double_t highpt[7]={30,35,40,50,65,100,400};
	fit(lowpt[a],highpt[a],lowchiso[b],highchiso[b]);
}

int main(){
    myfile<<"pt range"<<"\t"<<"chiso range"<<"chi2"<<"\t"<<"value"<<"\t"<<"error"<<endl;
for(Int_t j=0;j<7;j++){    
    for(Int_t i=0;i<10;i++){
	run_fit(j,i);
    }
    myfile<<"############################################"<<endl;
}
	return 0;
}
