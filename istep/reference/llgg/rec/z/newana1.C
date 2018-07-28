//code for running
//step 1: .L newana1.C
//step 2:(CB function + pol2) newana1("rec") or newana1("gen")
//step 2:(gaus + pol2) newana1("rec","gaus") or newana1("gen","gaus")

using namespace RooFit ;

void txt(Double_t x0=0.3, Double_t y0=0.3,Char_t txts[100]="",Int_t iColor=2,Double_t fSize=0.05,Bool_t IsNDC=kTRUE);
void SetPKUStyle();

void newana1(TString process="gen",TString fit="CB",Double_t mlow=75,Double_t mhigh=105,Bool_t idebug=kFALSE){

//void newana1(TString process="gen",Double_t mlow=120,Double_t mhigh=130,Bool_t idebug=kTRUE){
  SetPKUStyle();
  TH1F *h = new TH1F("h",";invariant mass of Z [GeV];Counts",1400,0,140);
  
  RooRealVar x("x","x",mlow,mhigh) ;
  
  RooDataSet data("data","",x);
  if(process=="rec")
  TFile *f = new TFile("llgg_rec_new.root");
  else if(process=="gen") TFile *f = new TFile("llgg_gen_new.root");
  TTree *t=new TTree("t","t");
  f->GetObject("tree",t);
  Double_t Z;
  t->SetBranchAddress("mll",&Z);
  Long64_t nentries = t->GetEntries();
  Long64_t ntotal=0;
  for (Long64_t i=0; i<nentries;i++) {
  t->GetEntry(i);
  if(Z>=mlow&&Z<=mhigh){
  x=Z;
  data.add(x);
  ntotal++;}
  h->Fill(Z);
  //cout<<H[3]<<endl;
  }
  f->Close();

  TCanvas *c1 = new TCanvas("c1","",800,600);
  if(idebug) {
  h->Draw();
  return;
    } 

  // Construct signal
  RooRealVar mean("mean","mean",90,75,105) ;
  RooRealVar sigma("sigma","sigma",0.01,0.01,10) ;
  if(fit=="CB"){
  RooRealVar a1("a1","a1",1,0,1000);
  RooRealVar n1("n1","n1",1,0,1000);
  RooCBShape sign("sign","sign",x,mean,sigma,a1,n1) ;}
  else if(fit=="gaus") RooGaussian sign("sign","sign",x,mean,sigma) ;
/*    if(process=="gen") {
    RooRealVar mean1("mean1","mean1",90,80,105) ;
    RooRealVar sigma1("sigma1","sigma1",0.01,0.01,10) ;
    RooGaussian sign1("sign1","sign1",x,mean1,sigma1) ;}
*/
        
    RooRealVar mean1("mean1","mean1",90,75,106) ;
    RooRealVar sigma1("sigma1","sigma1",0.01,0.01,10) ;
    if(fit=="CB"){
        RooRealVar a2("a1","a1",1,0,1000);
        RooRealVar n2("n1","n1",1,0,1000);
        RooCBShape sign1("sign1","sign1",x,mean1,sigma1,a2,n2) ;}
        
        
    //background
  if(process=="rec"){
  RooRealVar a2("a2","a2",0.1,0,10) ;
  RooRealVar a3("a3","a3",-0.1,-10,10) ;
  RooPolynomial fbkg("fbkg","fbkg",x,RooArgList(a2,a3));

  // Construct model = f*gx + (1-f)px
  RooRealVar nsig("nsig","nsig",0.5*ntotal,0,ntotal) ;
      
  RooRealVar nbkg("nbkg","nbkg",0.5*ntotal,0,ntotal) ;
  RooAddPdf model("model","model",RooArgList(sign,fbkg),RooArgList(nsig,nbkg)) ;}
  else if(process=="gen") 
  {RooRealVar nsig("nsig","nsig",0.5*ntotal,0,ntotal) ;
  RooRealVar nsig1("nsig1","nsig1",0.5*ntotal,0,ntotal) ;
      RooAddPdf model("model","model",RooArgList(sign,sign1),RooArgList(nsig,nsig1));}

  RooFitResult* r =  model.fitTo(data,Save(),Minos(kTRUE),NumCPU(100));

  ////draw the fitted results
  if(process=="rec")
  RooPlot* xframe = x.frame(Bins(50),Title("llgg_rec;invariant mass of Z [GeV];Counts/0.2GeV")) ;
  else if(process=="gen") RooPlot* xframe = x.frame(Bins(50),Title("llgg_gen;invariant mass of Z [GeV];Counts/0.2GeV")) ;
  RooPlot *data_1= data.plotOn(xframe);
  RooPlot *sig_1= model.plotOn(xframe,Components("sign"),LineWidth(3),LineStyle(3),LineColor(kRed));
  //if(process=="rec")
      RooPlot *bkg_1=model.plotOn(xframe,Components("sign1"),LineWidth(3),LineStyle(2),LineColor(kBlue));
  //if(process=="rec")
      RooPlot *model_1=model.plotOn(xframe,LineColor(kGreen));

  //caculate chi2
  Int_t nParsToFit = (r->floatParsFinal()).getSize();
  Double_t chi2 = xframe->chiSquare(nParsToFit);//reduced chi-squared = chi2/ndof
 
  gPad->SetLeftMargin(0.16) ; 
  xframe->GetYaxis()->SetTitleOffset(1.1)  ; 
  xframe->Draw() ;
  Double_t d1 = 0.85;
  Double_t dd = 0.07;
  txt(0.2,d1,Form("#chi^{2}/ndof=%f",chi2)); d1-=dd;
  txt(0.2,d1,Form("Mean=%.3f#pm%.3f",mean.getVal(),mean.getError()));    d1-=dd;
  txt(0.2,d1,Form("Sigma=%.3f#pm%.3f",sigma.getVal(),sigma.getError()));    d1-=dd;
  txt(0.2,d1,Form("Nsig=%.1f#pm%.1f",nsig.getVal(),nsig.getError()));    d1-=dd;
  txt(0.2,d1,Form("Nsig1=%.1f#pm%.1f",nsig1.getVal(),nsig1.getError()));    d1-=dd;

  if(process=="rec") {txt(0.2,d1,Form("Nbkg=%.1f#pm%.1f",nbkg.getVal(),nbkg.getError()));}

  //Draw the legend.
  TLegend *leg=new TLegend(0.8,0.65,0.95,.9);
  //RooHist *h_data=data_1->getHist("h_data");
  if(process=="rec") RooCurve *c_model=model_1->getCurve("model_Norm[x]");
  RooCurve *c_sig=sig_1->getCurve("model_Norm[x]_Comp[sign]");
  if(process=="rec") RooCurve *c_bkg=bkg_1->getCurve("model_Norm[x]_Comp[fbkg]");
  leg->SetBorderSize(1);
  leg->AddEntry(h_data,"data","LPE");
  if(process=="rec") leg->AddEntry(c_model,"model","L");
  if(fit=="CB") leg->AddEntry(c_sig,"signal(CB)","L");
  if(fit=="gaus") leg->AddEntry(c_sig,"signal(gaus)","L");
  if(process=="rec") leg->AddEntry(c_bkg,"bkg(pol2)","L");
  leg->Draw();
}


// Set the general style options
void SetPKUStyle(){
  // No Canvas Border
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasBorderSize(0);
  // White BG
  //  gStyle->SetCanvasColor(10);
  gStyle->SetCanvasColor(10);
  // Format for axes
  gStyle->SetLabelFont(22,"xyz");
  gStyle->SetLabelSize(0.06,"xyz");
  gStyle->SetLabelOffset(0.01,"xyz");
  gStyle->SetNdivisions(510,"xyz");
  gStyle->SetTitleFont(22,"xyz");
  gStyle->SetTitleColor(1,"xyz");
  gStyle->SetTitleSize(0.06,"xyz");
  gStyle->SetTitleOffset(0.91);
  gStyle->SetTitleYOffset(1.1);
  // No pad borders
  gStyle->SetPadBorderMode(0);
  gStyle->SetPadBorderSize(0);
  // White BG
  gStyle->SetPadColor(10);
  // Margins for labels etc.
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadTopMargin(0.06);
  // No error bars in x direction
  gStyle->SetErrorX(0);
  // Format legend 
  gStyle->SetLegendBorderSize(0);
  gStyle->SetLegendFont(22);
  gStyle->SetFillStyle(0);
}

void txt(Double_t x0, Double_t y0,Char_t txts[],Int_t iColor,Double_t fSize,Bool_t IsNDC)
{
  TLatex *ltx = new TLatex();
  ltx->SetNDC(IsNDC);
  if(!(x0>=0 && x0<=1 && y0>=0 && y0<=1) ) ltx->SetNDC(kFALSE);
  ltx->SetTextColor(iColor);
  ltx -> SetTextFont(22);
  ltx->SetTextSize(fSize);
  ltx->DrawLatex(x0,y0,txts);
}
