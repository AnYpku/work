#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TCanvas.h"
#include "TAxis.h"


void drawCompare_Cuts( Int_t hist1D = 1,  Int_t hist1Dlog = 0,  Int_t hist2D = 0,  Int_t hist2Dlog = 0, Int_t hist3D = 0)
{
  TString fileDataName = "/store/home/andy/GEM/root files/TestGEMCSCSegmentHistograms_EGun_99_200GeV_750evts.root";
//  TString fileMCName = "./histroot/hist_p2gamma_inc_010000.root";
  TFile *fdata = TFile::Open(fileDataName);
//  TFile *fmc   = TFile::Open(fileMCName);
  
  TString figsDir = "./"; 
    cout<<"root file is: "<<fileDataName.Data()<<endl;
//    cout<<"root file is: "<<fileMCName.Data()<<endl;

  if(hist1D) {
     const int maxTH1DHistNum = 5;
     TString histTH1DName[maxTH1DHistNum] = {"NumGEMRH","NumCSCRH","NumGEMCSCRH","NumGEMCSCSeg"};


//"ReducedChi2_csc","ReducedChi2_gemcsc","NumGEMRH","NumCSCRH","NumGEMCSCRH","NumGEMCSCSeg","SuperS_LPx","SuperS_LPy","SuperS_LPx","SuperS_LPy","SuperS_LPEx","SuperS_LPEy","SuperS_LDx","SuperS_LDy","SuperS_LDEx","SuperS_LDEy","CSCSegm_LPx","CSCSegm_LPy","CSCSegm_LPEx","CSCSegm_LPEy","CSCSegm_LDx","CSCSegm_LDy","CSCSegm_LDEx","CSCSegm_LDEy","SSegm_LDx_expected","SSegm_LDy_expected","SuperS_LDEx_expected","SuperS_LDEy_expected","xGEMCSCRes","xGEMRes","xCSCRes","xGEMRes_even","xCSCRes_even","xGEMRes_odd","xCSCRes_odd","xGEMCSCRes_cscl1","xGEMCSCRes_cscl2","xGEMCSCRes_cscl3","xGEMCSCRes_cscl4","xGEMCSCRes_cscl5","xGEMCSCRes_cscl6","xGEMCSCRes_geml1","xGEMCSCRes_geml2","xGEMCSCPool","xGEMPool","xCSCPool","xGEMPool_even","xGEMPool_odd","xCSCPool_even","xCSCPool_odd","xGEMCSCPool_cscl1","xGEMCSCPool_cscl2","xGEMCSCPool_cscl3","xGEMCSCPool_cscl4","xGEMCSCPool_cscl5","xGEMCSCPool_cscl6","xGEMCSCPool_geml1","xGEMCSCPool_geml2","xGEMPool_newE","yGEMPool_newE","xGEMPool_odd_newE_mp","xGEMPool_odd_newE_mm","xGEMPool_newE_mm","xGEMPool_newE_mp","GEMCSC_SSegm_xe_l1","GEMCSC_SSegm_ye_l1","GEMCSC_SSegm_ze_l1","GEMCSC_SSegm_xe_l2","GEMCSC_SSegm_ye_l2","GEMCSC_SSegm_ze_l2","GEMCSC_SSegm_sigmaxe_l1","GEMCSC_SSegm_sigmaye_l1","GEMCSC_SSegm_sigmaxe_l2","GEMCSC_SSegm_sigmaye_l2","DR_gemRHgemcscS_min_afterCut","Dphi_gemRHgemcscS_min_afterCut_l1","Dphi_gemRHgemcscS_min_afterCut_l2","Dphi_gemRHcscS_min_afterCut","Dtheta_gemRHcscS_min_afterCut","DR_gemRHcscS_min_afterCut","Dphi_gemRHcscS_min_afterCut_l1","Dphi_gemRHcscS_min_afterCut_l2","Dphi_gemRHcscS_min_afterCut_odd","Dphi_gemRHcscS_min_afterCut_odd_r1","Dphi_gemRHcscS_min_afterCut_odd_r2","Dphi_gemRHcscS_min_afterCut_odd_r3","Dphi_gemRHcscS_min_afterCut_odd_r4","Dphi_gemRHcscS_min_afterCut_odd_r5","Dphi_gemRHcscS_min_afterCut_odd_r6","Dphi_gemRHcscS_min_afterCut_odd_r7","Dphi_gemRHcscS_min_afterCut_odd_r8","Dphi_gemRHcscS_min_afterCut_even","Dphi_gemSHSS_min_afterCut","Dtheta_gemSHSS_min_afterCut","xGEMRes_simhit","yGEMRes_simhit","xGEMPool_newE_simhit","yGEMPool_newE_simhit","xGEMRes_shrh","yGEMRes_shrh","xGEMPool_shrh","yGEMPool_shrh"}; // add any TH1D histogram name

     for(int i=0; i<maxTH1DHistNum; i++)
        {
        cout<<"histogram is: "<<histTH1DName[i].Data()<<endl;

        TString NameData01      = histTH1DName[i].Data();
        TString treeName01      = histTH1DName[i].Data();
        TString titleCan01      = histTH1DName[i].Data();
        TString figNameData01   = figsDir + NameData01 + ".gif";
        TH1D* histNameData01    = (TH1D*)fdata->Get(treeName01);
//        TH1D* histNameMC01      = (TH1D*)fmc->Get(treeName01);
        TCanvas* canvName01 = new TCanvas(titleCan01, titleCan01, 900, 600);
//        canvName01->Divide(2,1);
//        canvName01->cd(1);
        histNameData01->SetMinimum(0.0);
        histNameData01->GetYaxis()->SetTitleOffset(1.2);
        histNameData01->Draw();
//        canvName01->cd(2);
//        histNameMC01->SetMinimum(0.0);
//        histNameMC01->GetYaxis()->SetTitleOffset(1.2);
//        histNameMC01->Draw();
        canvName01->SaveAs(figNameData01);
        }
 }

  if(hist1Dlog) {
     const int maxTH1DLogHistNum = 8;
     TString histTH1DLogName[maxTH1DLogHistNum] = {"NU_Unused_Energy_pi0", "NU_Unused_Energy_1_pi0", "NU_Unused_Energy_eta", "NU_Unused_Energy_1_eta", "t_pi0", "t_eta", "Acci_t_pi0", "Acci_t_eta"}; // add any TH1D histogram name

     for(int i=0; i<maxTH1DLogHistNum; i++)
        {
        cout<<"histogram is: "<<histTH1DName[i].Data()<<endl;
        TString NameData01      = histTH1DLogName[i].Data();
        TString treeName01      = histTH1DLogName[i].Data();
        TString titleCan01      = histTH1DLogName[i].Data();
        TString figNameData01   = figsDir + NameData01 + "_log.ps";
        TString figNameData02   = figsDir + NameData01 + "_log.pdf";
        TH1D* histNameData01    = (TH1D*)fdata->Get(treeName01);
        TH1D* histNameMC01      = (TH1D*)fmc->Get(treeName01);
        TCanvas* canvName01 = new TCanvas("canvName01", titleCan01, 960, 320);
        canvName01->Divide(2,1);
        canvName01->cd(1);
        gPad->SetLogy();
        histNameData01->SetMinimum(0.1);
        histNameData01->GetYaxis()->SetTitleOffset(1.2);
        histNameData01->Draw();
        canvName01->cd(2);
        gPad->SetLogy();
        histNameMC01->SetMinimum(0.1);
        histNameMC01->GetYaxis()->SetTitleOffset(1.2);
        histNameMC01->Draw();
        canvName01->SaveAs(figNameData01);
        canvName01->SaveAs(figNameData02);
        }
  }

  if(hist2D) {
     const int maxTH2DHistNum = 8;
     TString histTH2DName[maxTH2DHistNum] = {"SIMGEMCSCSegm_theta_cscSsh_vs_ndof_odd","SIMGEMCSCSegm_theta_cscSsh_vs_ndof_even","CSCSegm_LPEy_vs_ndof","CSCSegm_LDEy_vs_ndof","SSegm_LPEy_vs_ndof","SSegm_LDEy_vs_ndof","SimTrack_etaVScharge","SimTrack_etaVStype"}; // add any TH2D histogram name

     for(int i=0; i<maxTH2DHistNum; i++)
        {
       cout<<"histogram is: "<<histTH2DName[i].Data()<<endl;

        TString NameData01      = histTH2DName[i].Data();
        TString treeName01      = histTH2DName[i].Data();
        TString titleCan01      = histTH2DName[i].Data();
        TString figNameData01   = figsDir + NameData01 + ".gif";
//        TString figNameData02   = figsDir + NameData01 + "_log.pdf";
        TH2D* histNameData21    = (TH2D*)fdata->Get(treeName01);
//        TH2D* histNameMC21      = (TH2D*)fmc->Get(treeName01);
        TCanvas* canvName01 = new TCanvas(titleCan01, titleCan01, 900, 600);
//        canvName01->Divide(2,1);
//        canvName01->cd(1);
        //  histNameData01->SetStats(0);
        histNameData21->Draw("COLZ1");
//        canvName01->cd(2);
        //  histNameMC01->SetStats(0);
//        histNameMC21->Draw("COLZ1");
        canvName01->SaveAs(figNameData01);
//        canvName01->SaveAs(figNameData02);
        }
  }

  if(hist2Dlog) {
     const int maxTH2DLogHistNum = 31;
     TString histTH2DLogName[maxTH2DLogHistNum] = {"z_vs_r_vertex", "Phi_Proton_vs_BE_cut6", "Acci_Phi_Proton_vs_BE_cut6", "Phi_Proton_vs_IM2g_cutBE", "Acci_Phi_Proton_vs_IM2g_cutBE", "ME_vs_Phi_Proton_cut6", "Acci_ME_vs_Phi_Proton_cut6", "Phi_Proton_vs_t_2", "Phi_Proton_vs_t_5_2", "Phi_Proton_vs_t_15_2", "Acci_Phi_Proton_vs_t_2", "Acci_Phi_Proton_vs_t_5_2", "Acci_Phi_Proton_vs_t_15_2", "Phi_Proton_vs_t_5", "Phi_Proton_vs_t_5_5", "Phi_Proton_vs_t_15_5", "Acci_Phi_Proton_vs_t_5", "Acci_Phi_Proton_vs_t_5_5", "Acci_Phi_Proton_vs_t_15_5", "Phi_Proton_vs_t_1", "Phi_Proton_vs_t_5_1", "Phi_Proton_vs_t_15_1", "Acci_Phi_Proton_vs_t_1", "Acci_Phi_Proton_vs_t_5_1", "Acci_Phi_Proton_vs_t_15_1", "Phi_Proton_vs_t_4", "Phi_Proton_vs_t_5_4", "Phi_Proton_vs_t_15_4", "Acci_Phi_Proton_vs_t_4", "Acci_Phi_Proton_vs_t_5_4", "Acci_Phi_Proton_vs_t_15_4"}; // add any TH2D histogram name

     for(int i=0; i<maxTH2DLogHistNum; i++)
        {
       cout<<"histogram is: "<<histTH2DLogName[i].Data()<<endl;

        TString NameData01      = histTH2DLogName[i].Data();
        TString treeName01      = histTH2DLogName[i].Data();
        TString titleCan01      = histTH2DLogName[i].Data();
        TString figNameData01   = figsDir + NameData01 + "_log.ps";
        TString figNameData02   = figsDir + NameData01 + "_log.pdf";
        TH2D* histNameData21    = (TH2D*)fdata->Get(treeName01);
        TH2D* histNameMC21      = (TH2D*)fmc->Get(treeName01);
        TCanvas* canvName01 = new TCanvas("canvName01", titleCan01, 900, 6000);
        canvName01->Divide(2,1);
        canvName01->cd(1);
        //  histNameData01->SetStats(0);
        gPad->SetLogz();
        histNameData21->Draw("COLZ1");
        canvName01->cd(2);
        //  histNameMC01->SetStats(0);
        gPad->SetLogz();
        histNameMC21->Draw("COLZ1");
        canvName01->SaveAs(figNameData01);
        canvName01->SaveAs(figNameData02);
        }
  }

  if(hist3D) {
     const int maxTH3DHistNum = 0;
     TString histTH3DName[maxTH3DHistNum] = {""}; // add any TH3D histogram name

     for(int i=0; i<maxTH3DHistNum; i++)
        {
       cout<<"histogram is: "<<histTH3DName[i].Data()<<endl;

        TString NameData01      = histTH2DName[i].Data();
        TString treeName01      = histTH2DName[i].Data();
        TString titleCan01      = histTH2DName[i].Data();
        TString figNameData01   = figsDir + NameData01 + ".ps";
        TH3D* histNameData31    = (TH2D*)fdata->Get(treeName01);
        TH3D* histNameMC31      = (TH2D*)fmc->Get(treeName01);
        TCanvas* canvNameData01 = new TCanvas("canvName01", titleCan01, 960, 320);
        canvName01->Divide(2,1);
        canvName01->cd(1);
        //  histNameData01->SetStats(0);
        histNameData31->Draw("COLZ1");
        canvName01->cd(2);
        //  histNameMC01->SetStats(0);
        histNameMC31->Draw("COLZ1");
        canvName01->SaveAs(figNameData01);
        }
  }

}
