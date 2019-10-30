#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TAxis.h"
using namespace RooFit ;


void test_roofit()
{
   RooRealVar x("x","x",-10,10) ;
   RooRealVar mean("mean","mean of gaussian",1,-10,10) ;
   RooRealVar sigma("sigma","width of gaussian",1,0.1,10) ;
   RooGaussian gauss("gauss","gaussian PDF",x,mean,sigma) ;  

   RooPlot* xframe = x.frame(Title("Gaussian function")) ;
   TLegend* l1 = new TLegend(0.6,0.8,0.8,0.9);
   gauss.plotOn(xframe);
   l1->AddEntry(xframe,"#sigma = 1");
   sigma.setVal(3) ;
   l1->AddEntry(xframe,"#sigma = 3");
   gauss.plotOn(xframe,LineColor(kRed)) ;
  

   RooDataSet* data = gauss.generate(x,10000) ;  
  
   RooPlot* xframe2 = x.frame(Title("fit data with Gaussian function")) ;
   data->plotOn(xframe2) ;
   gauss.plotOn(xframe2) ;
  
   gauss.fitTo(*data) ;

//   mean.Print() ;
//   sigma.Print() ;
   TCanvas* c1 = new TCanvas("c1","gauss function",800,600) ;
   c1->cd();  xframe->GetYaxis()->SetTitleOffset(1.6) ; xframe->Draw(); l1->Draw();
   TCanvas* c2 = new TCanvas("c2","fit data with gauss function",800,600) ;
   c2->cd() ; xframe2->GetYaxis()->SetTitleOffset(1.6) ; xframe2->Draw() ;
}
