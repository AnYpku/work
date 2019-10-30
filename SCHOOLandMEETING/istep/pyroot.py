import ROOT
from ROOT import gStyle, TCanvas, TGraphErrors
canvas_8_1=ROOT.TCanvas("canvas_8_1" ,"Data Python" ,200 ,10 ,700 ,500)
f1 = ROOT.TF1("f2","[0]*sin([1]*x)/x",0.,10.)
f1.SetParameter(0,1);
f1.SetParameter(1,1);
f1.Draw();
canvas_8_1.Draw();
canvas_8_1.Print("test.pdf");
