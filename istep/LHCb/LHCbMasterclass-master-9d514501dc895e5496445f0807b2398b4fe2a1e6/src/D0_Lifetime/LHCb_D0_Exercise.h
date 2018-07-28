#ifndef LHCB_D0_EXERCISE_HH
#define LHCB_D0_EXERCISE_HH 1
/* (C) Copyright 2013  CERN

   This software is distributed under the terms of the GNU General Public
   License version 3 (GPL Version 3), copied verbatim in the file "COPYING".

   In applying this license, CERN does not waive the privileges and immunities
   granted to it by virtue of its status as an Intergovernmental Organization
   or submit itself to any jurisdiction.
 */
#pragma warning(disable: 4244 4800 )
#include <TObject.h>
#include <TString.h>
#include <map>
#include <iostream>
#include <exception>
#include "launcher.h"
class TFile;
class TTree;
class TDirectory;
class TObjArray;
class TEveVSD;
class TEveTrackList;
class TEvePointSet;
class TTimer;
class TGLOverlayButton;
class TGTextEntry;
class TH1D;
class TGraphErrors;
class TEveGDoubleValuator;
class TCanvas;
class TGPictureButton;
class TF1;
class TGComboBox;
class TGNumberEntryField;
class TGTextEntry;
class TGMainFrame;

class MissingDataFile: public std::exception {
public:
  MissingDataFile(const std::string &filename): m_filename(filename) {}
  virtual ~MissingDataFile() throw() {}
  virtual const char* what() const throw() {
    return ("Cannot open file " + m_filename).c_str();
  }
private:
  std::string m_filename;
};



namespace FitResults {
  
  class FitPoint 
  {
  public:
    
    FitPoint( const Double_t vlow, 
              const Double_t vupp, 
              const Double_t vval, 
              const Double_t verr ) :  
      low( vlow ), upp( vupp ), val( vval ), err( verr ){};
    
    
    FitPoint() : 
      low( 0. ), upp( 0. ), val( 0. ), err( 0. ){} ;
    
    
    ~FitPoint(){} ;
    
    Double_t low;
    Double_t upp;
    Double_t val;
    Double_t err;
  };  

  class Trend {
    
  public:
    Trend( Double_t (*vfunc)(const FitResults::FitPoint&), 
           const TString vtitle, 
           const Double_t vmin, 
           const Double_t vmax ) : 
      func( vfunc ), title( vtitle ), min( vmin ), max( vmax ) {} ;
    
    Double_t operator()( const FitResults::FitPoint& point ) 
    {
      return func( point );
    }
    
    const TString  title;
    const Double_t min;
    const Double_t max;
    
  private:
    
        
    Double_t (*func)(const FitResults::FitPoint&) ;
    
  };


  Double_t max( const FitResults::FitPoint& point );
  
  Double_t min( const FitResults::FitPoint& point );
  
};






class TVSDReader: public TObject
{
public:
  // ----------------------------------------------------------
  // File / Event Data
  // ----------------------------------------------------------

  TFile      *d0File;
  TTree      *d0Tree;

  Double_t    D0_MM,D0_PT,D0_TAU,D0_MINIP;
  bool     fittedMass,fittedTime;
   Int_t lang1;
  TFile      *fFile;
  TDirectory *fDirectory;

  TObjArray  *fEvDirKeys;

  TEveVSD    *fVSD;

  Int_t       fMaxEv, fCurEv, fMaxR, fRAnim, fAnalysis1, fAnalysis2;

  Bool_t      fVertexLoaded, fITSClustersLoaded, fTPCClustersLoaded, fTRDClustersLoaded,
    fTOFClustersLoaded,  fClustersLoaded, fEsdTracksLoaded, fV0sLoaded, fCascadesLoaded,
    fGuidesLoaded, fGeometrySet, fInDemoMode;

  // ----------------------------------------------------------
  // Event visualization structures
  // ----------------------------------------------------------

  TEveTrackList *fTrackList;
  TEveTrackList *fTrackListV0Neg;
  TEveTrackList *fTrackListV0Pos;
  TEveTrackList *fTrackListV0Mother;
  TEveTrackList *fTrackListCascade;
  TEveTrackList *fTrackListCascadeNeg;
  TEveTrackList *fTrackListCascadePos;
  TEveTrackList *fTrackListCascadeBachelor;
  TEveTrackList *fTrackListCascadeMother;
  TEveTrackList *fTrackListPointingV0;

  TEvePointSet  *fPsVertex;
  TEvePointSet  *fITSClusters;
  TEvePointSet  *fTPCClusters;
  TEvePointSet  *fTRDClusters;
  TEvePointSet  *fTOFClusters;
  TEvePointSet  *fPsV0;
  TEvePointSet  *fPsCascade;

  TTimer        *fTimer;

  TGLOverlayButton*	obutton1;
  TGLOverlayButton*	obutton2;
  TGLOverlayButton*	obutton3;
  TGLOverlayButton*	overlayButton;

  TGTextEntry*		fAnalysis1TE;
  TGTextEntry*		fAnalysis2TE;

  TH1D*			fMinvHisto;
  TH1D*			fD0PTHisto_Sig;
  TH1D*			fD0TAUHisto_Sig;
  TH1D*			fD0IPHisto_Sig;
  TH1D*			fD0PTHisto_Bkg;
  TH1D*			fD0TAUHisto_Bkg;
  TH1D*			fD0IPHisto_Bkg;

  std::map<int, TGraphErrors*>		fD0FitResultTrendPlot;
  std::map<int, UInt_t> fTrendPadMap;

  TH1D* fSigCacheForFit;
  TH1D* fBkgCacheForFit;

  std::map< int, std::vector< FitResults::FitPoint > > fD0Trend_FitResults;
  

  TCanvas*		fPad;
  TCanvas*    fTrendPad;
  TCanvas*    fFitPad  ;
  
  
  TEveGDoubleValuator*  fD0PTCut;
  TEveGDoubleValuator*  fD0TAUCut;
  TEveGDoubleValuator*  fD0IPCut;
  TEveGDoubleValuator*	fFitRangeGaus;
  TEveGDoubleValuator*	fFitRangePoly;
  TGPictureButton*	fResultButton1;
  TGPictureButton*	fResultButton2;
  TGPictureButton*	fResultButton3;
  TGPictureButton*	fResultButton4;
  TGPictureButton*	fResultButton5;
  TGPictureButton*	fResultButton6;
  TGPictureButton*	fResultButton7;
  TGPictureButton*	fResultButton8;
  TString		fResultPicture1;
  TString		fResultPicture2;
  TString		fResultPicture3;
  TString		fResultPicture4;
  TString		fResultPicture5;
  TString		fResultPicture6;
  TString		fResultPicture7;
  TString		fResultPicture8;
  TF1*			fFitGaus;
  TF1*                  fFitExpo;
  TF1*			fFitPolynomial;
  TGComboBox*           fSaveDir;
  TGComboBox*           fLoadDir;
  TGTextEntry*          fTeacherName;
  TGNumberEntryField* 	fFitCut;
  TGNumberEntryField* 	fFitResult;
  TGNumberEntryField* 	fFitErr;
  TGTextEntry* fName1;
  TString filetosave;
  TGComboBox* fVarToTrend;


  TGMainFrame* frmMain;


public:
  TVSDReader(const char* file_name);

  virtual ~TVSDReader();

  void ToStudent();

  void Exit();

  void SaveCanvas(); 

  void SetFileName(); 

  void Instructions();

  void ResetExercise();
 
//-----------------

  void LoadD0Ntuple(const char* file_name);

  void SetD0NtupleBranches();

  void PlotFitResultsVsVar();

  void SaveFitResult();

  void PlotD0Mass();

  void PlotVarDists();

  void FitDecayTime();

  void FitInvariantMass();

  Double_t Background_Integral(Double_t xmin, Double_t xmax);

  void AutomaticMenu();

  void TrendPad() ;

  void FitPad() ;
  
  void VarPad() ;
  void CloseWin();
  void LHCbInfo();
  void IT();
  void RO();
  void EN();
  void FR();
  void setLang1(Int_t lang);
  void DE();
  bool OpenTab( TList* tabs, const char* str );

  void ClearTrend();

  Bool_t CheckTrend( const int choice );

  void DeleteHistograms();
  
  
private:

  const double fPTRangeMin;
  const double fPTRangeMax;
  const double fTAURangeMin; 
  const double fTAURangeMax;
  const double fIPRangeMin; 
  const double fIPRangeMax;
 
  UInt_t fTrendPadNum;
  
  //needed for language translation
  TString var_ranges;
  TString an_tools;
  TString tools;
  TString bg_sub;
  TString t_fit;
  TString save_res;
  TString plt_mass;
  TString plt_distr;
  TString fit_sign;
  TString f_name;
  TString s_exit;
  TString reset_exe;
  TString read_inst;
  TString sv_canv;
  TString cl_trend;
  TString pl_trend;
  TString sv_res_fit;
  TString fit_mass_dis;
  //error, warning and info messages
  TString i1;
  TString i2;
  TString i3;
  TString i4;
  TString i5;
  TString i6;

  ClassDef(TVSDReader, 0);
};
//main constructor
void LHCb_D0_Exercise(Int_t lang, TString pathSave2, Int_t choice = 2, Int_t mode = 2, Int_t dataset = 1, TString name1 = "", TString name2 = "");

#endif // LHCB_D0_EXERCISE_HH
