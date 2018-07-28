/// \file
/// \ingroup tutorial_roofit
/// \notebook -js
///  'LIKELIHOOD AND MINIMIZATION' RooFit tutorial macro #605
///
///  Working with the profile likelihood estimator
///
/// \macro_image
/// \macro_output
/// \macro_code
/// \author 07/2008 - Wouter Verkerke 


#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooAddPdf.h"
#include "RooMinimizer.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "RooPlot.h"
using namespace RooFit ;


void rf605_profilell()
{
    
    Double_t hgg_bins=30;// 100,110,160
    Double_t hgg_low=110;
    Double_t hgg_up =160;
    int dof = 6 ;
    
    Double_t para[20];
    para[3] = 3.0498e+04 ;  //Nbkg: expo      N3
    para[5] = 2.7100e+02 ;  //Nsig: Gaussian  N1
    para[1] = 8.6137e+00 ;  //expo: a1
    para[2] = 2.0198e+00 ;           //expo:    a2
    para[7] = 1.2450e+02 ;  //mean_GS:  Gaussian
    para[11]= 1.4961e+00 ;  //sigma_GS
    para[4] = 1.3539e+02 ;  //mean_GS:  Gaussian
    para[6]= 0.5e+00 ;  //sigma_GS
    para[10]=0.3;//Nf

   // C r e a t e   m o d e l   a n d   d a t a s e t 
   // -----------------------------------------------
    TFile *f1 = new TFile("Hgg.root");
    TTree *t1 = (TTree *)f1->Get("tree");
    RooRealVar hgg("hgg", "", hgg_low, hgg_up);
    RooDataSet* data =new RooDataSet("data", "data", t1,hgg);
   // Model (intentional strong correlations)
   RooRealVar mean("mean","mean of g1 and g2",130,140) ;
   RooRealVar sigma_g1("sigma_g1","width of g1",0.5,5) ;
   RooGaussian gauss1_pdf("g1","g1",hgg,mean,sigma_g1) ;

RooRealVar a1("a1", "",para[1],-500,600);
RooRealVar a2("a2", "",para[2],-500,500);
RooGenericPdf expo("expo", "exponential PDF","exp(-(a1*hgg/100)+a2*(hgg/100)^2)",RooArgSet(hgg,a1,a2));
RooRealVar N3("Nbkg", "", para[3], 20000,  40000);
RooRealVar N1("Nsig",  "", 100,400);
RooAddPdf sum("sum","signalPDF + exp PDF",RooArgList(gauss1_pdf, expo),RooArgList(N1,N3));
   
   // C o n s t r u c t   p l a i n   l i k e l i h o o d
   // ---------------------------------------------------
   // Construct unbinned likelihood
   RooAbsReal* nll = sum.createNLL(*data,NumCPU(4));

   // Minimize likelihood w.r.t all parameters before making plots
   RooMinimizer(*nll).migrad() ;

   // Plot likelihood scan frac 
   RooPlot* frame1 = mean.frame(Bins(30),Range(130,140),Title("LL and profileLL in mean_gauss")) ;
   nll->plotOn(frame1,ShiftToZero()) ;

   // Plot likelihood scan in sigma_g2
   RooPlot* frame2 = N1.frame(Bins(30),Range(10,150),Title("LL and profileLL in Nsig")) ;
   nll->plotOn(frame2,ShiftToZero()) ;



   // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   f r a c
   // -----------------------------------------------------------------------

   // The profile likelihood estimator on nll for frac will minimize nll w.r.t
   // all floating parameters except frac for each evaluation

   RooAbsReal* pll_mean = nll->createProfile(mean) ;

   // Plot the profile likelihood in frac
   pll_mean->plotOn(frame1,LineColor(kRed)) ;

   // Adjust frame maximum for visual clarity
   frame1->SetMinimum(0) ;
   frame1->SetMaximum(3) ;



   // C o n s t r u c t   p r o f i l e   l i k e l i h o o d   i n   s i g m a _ g 2 
   // -------------------------------------------------------------------------------

   // The profile likelihood estimator on nll for sigma_g2 will minimize nll
   // w.r.t all floating parameters except sigma_g2 for each evaluation
   RooAbsReal* pll_N1 = nll->createProfile(N1) ;

   // Plot the profile likelihood in sigma_g2
   pll_N1->plotOn(frame2,LineColor(kRed)) ;

   // Adjust frame maximum for visual clarity
   frame2->SetMinimum(0) ;
   frame2->SetMaximum(3) ;



   // Make canvas and draw RooPlots
   TCanvas *c = new TCanvas("rf605_profilell","rf605_profilell",800, 400);
   c->Divide(2);
   c->cd(1) ; gPad->SetLeftMargin(0.15) ; frame1->GetYaxis()->SetTitleOffset(1.4) ; 
   frame1->GetXaxis()->SetTitle("M_{#gamma#gamma}/GeV/c^{2}");frame1->Draw();
   c->cd(2) ; gPad->SetLeftMargin(0.15) ; frame2->GetYaxis()->SetTitleOffset(1.4) ; 
   frame2->GetXaxis()->SetTitle("Number of signal");
   frame2->Draw() ;

   delete pll_mean ;
   delete pll_N1 ;
   delete nll ;
}

