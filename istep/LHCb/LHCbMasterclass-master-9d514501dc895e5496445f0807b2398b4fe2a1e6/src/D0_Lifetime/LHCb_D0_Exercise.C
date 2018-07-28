/* (C) Copyright 2013  CERN

   This software is distributed under the terms of the GNU General Public
   License version 3 (GPL Version 3), copied verbatim in the file "COPYING".

   In applying this license, CERN does not waive the privileges and immunities
   granted to it by virtue of its status as an Intergovernmental Organization
   or submit itself to any jurisdiction.
 */
#pragma warning(disable: 4244 4800 )
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

#include <TGFileDialog.h>
#include <TRootHelpDialog.h>

#include "TImage.h"

#include <TGClient.h>
#include <TGFrame.h>
#include <TGLayout.h>
#include <TGSplitter.h>

#include <TGLOverlayButton.h>

#include <TText.h>
#include <TPaveText.h>
#include <TLatex.h>
#include <TVirtualFitter.h>

#include <TG3DLine.h>
#include <TAxis3D.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TF1.h>
#include <TEveGValuators.h>
#include <TGDoubleSlider.h>

#include <TApplication.h>
#include <TEveManager.h>
#include <TEveEventManager.h>
#include <TEveWindowManager.h>
#include <TEveVSD.h>
#include <TEveVSDStructs.h>

#include <TCanvas.h>

#include <TEveTrack.h>
#include <TEveTrackPropagator.h>
#include <TEveGeoShape.h>

#include <TEveSelection.h>

#include <TGLEmbeddedViewer.h>
#include <TCanvas.h>
#include <TParticlePDG.h>

#include <TH1D.h>

#include <TGTextEntry.h>

#include <TGLabel.h>
#include <TGComboBox.h>

#include <TGTab.h>
#include <TGButton.h>
#include <TTimer.h>

#include <TFile.h>
#include <TKey.h>
#include <TSystem.h>
#include <TPRegexp.h>

#include <TGNumberEntry.h>
#include <TGLWidget.h>

#include <TSystemDirectory.h>

#include <TGraphErrors.h>

#include <TEveManager.h>

#include <TEveViewer.h>
#include <TGLViewer.h>

#include <TEveScene.h>

#include <TEveProjectionManager.h>
#include <TEveProjectionAxes.h>
#include <TEveProjectionAxesGL.h>

#include <TEveBrowser.h>
#include <TEveWindow.h>

#include <TAxis3D.h>

#include <limits>

#include "LHCb_D0_Exercise.h"

#ifndef DATA_DIR
#define DATA_DIR "share/LHCbMasterclass"
#endif
#include "launcher.h"

using namespace std;

Double_t FitResults::max( const FitResults::FitPoint& point )
{
  return point.upp;
}

Double_t FitResults::min( const FitResults::FitPoint& point )
{
  return point.low;
}


namespace
{
  const char *gMasterClassOutputData[] = {"MasterClass Output Data", "*.masterclass", 0, 0}; //for loading results
}

namespace
{
  const char *gMasterClassOutputPicture[] = {"MasterClass Histograms", "*.png", 0, 0}; //for loading results
}

TH1D* gKMinvHist = 0;
TH1D* gXMinvHist = 0;
TH1D* gLMinvHist = 0;
TH1D* gALMinvHist = 0;
TH1D* gAllMinvHist = 0;

TCanvas* pad1 = 0;
TCanvas* pad2 = 0;

TGCheckButton* gCheckVertex = 0;
TGCheckButton* gCheckClusters = 0;
TGCheckButton* gCheckITSClusters = 0;
TGCheckButton* gCheckTPCClusters = 0;
TGCheckButton* gCheckTRDClusters = 0;
TGCheckButton* gCheckTOFClusters = 0;
TGCheckButton* gCheckESDTracks = 0;
TGCheckButton* gCheckV0s = 0;
TGCheckButton* gCheckCascades = 0;

TGLabel* gEventNumber = 0;

TEveLine* pointingLine[10] = {0};
TEveLine* pointingLine1[10] = {0};
TEveLine* pointingLine2[10] = {0};
TEveLine* guideX[12] = {0};
TEveLine* guideY[14] = {0};
TEveLine* guideZ[14] = {0};

Int_t globalChoice = 0;
Int_t globalMode = 0;
Int_t globalDataset = 0;
Int_t gLoads = 0;

Int_t nV0Tracks = 0;
Int_t nCascadeTracks = 0;

Double_t pxPos[10] = {0};
Double_t pyPos[10] = {0};
Double_t pzPos[10] = {0};
Double_t massPos[10] = {0};

Double_t pxNeg[10] = {0};
Double_t pyNeg[10] = {0};
Double_t pzNeg[10] = {0};
Double_t massNeg[10] = {0};

Double_t pxPosCas[10] = {0};
Double_t pyPosCas[10] = {0};
Double_t pzPosCas[10] = {0};
Double_t massPosCas[10] = {0};

Double_t pxNegCas[10] = {0};
Double_t pyNegCas[10] = {0};
Double_t pzNegCas[10] = {0};
Double_t massNegCas[10] = {0};

Double_t pxBacCas[10] = {0};
Double_t pyBacCas[10] = {0};
Double_t pzBacCas[10] = {0};
Double_t massBacCas[10] = {0};
Double_t chargeBacCas[10] = {0};

Double_t pxPosFound = 0;
Double_t pyPosFound = 0;
Double_t pzPosFound = 0;
Double_t massPosFound = 0;

Double_t pxNegFound = 0;
Double_t pyNegFound = 0;
Double_t pzNegFound = 0;
Double_t massNegFound = 0;

Int_t chargeNegFound = -1;
Int_t chargePosFound = 1;

Bool_t foundNeg = kFALSE;
Bool_t foundPos = kFALSE;
Bool_t teacher = kFALSE;

Double_t pcaX[10] = {0};
Double_t pcaY[10] = {0};
Double_t pcaZ[10] = {0};

Double_t pcaXCas[10] = {0};
Double_t pcaYCas[10] = {0};
Double_t pcaZCas[10] = {0};

Double_t pcaXBacCas[10] = {0};
Double_t pcaYBacCas[10] = {0};
Double_t pcaZBacCas[10] = {0};

Int_t detector = 0;
Int_t geometry = 0;

Int_t AC = 0;

TString globalName1 = "";
TString globalName2 = "";

// Mass of particles in MeV
Double_t gMassElecton = 0.000510998910;
Double_t gMassMuon = 0.105658367;
Double_t gMassPion = 0.13957018;
Double_t gMassKaon = 0.493677;
Double_t gMassProton = 0.938272013;

Bool_t change = kTRUE;
TString pathSaveD0="";

//--------------------------------------------------------------
//additional classes
//--------------------------------------------------------------


//---------------------------------------------------------------------------

TVSDReader::TVSDReader(const char* file_name) :
  d0File(0),d0Tree(0),D0_MM(0),D0_PT(0),D0_TAU(0),D0_MINIP(0),
    fittedMass(0),fittedTime(0),
    fFile(0), fDirectory(0), fEvDirKeys(0), fVSD(0),

    fMaxEv(-1), fCurEv(-1), fMaxR(400), fRAnim(0), fAnalysis1(0), fAnalysis2(0),

    fVertexLoaded(kTRUE), fITSClustersLoaded(kFALSE), fTPCClustersLoaded(kFALSE), fTRDClustersLoaded(kFALSE),
    fTOFClustersLoaded(kFALSE), fClustersLoaded(kTRUE), fEsdTracksLoaded(kTRUE),
    fV0sLoaded(kFALSE), fCascadesLoaded(kFALSE), fGuidesLoaded(kFALSE),
    fGeometrySet(kTRUE), fInDemoMode(kFALSE),

    fTrackList(0), fTrackListV0Neg(0), fTrackListV0Pos(0), fTrackListV0Mother(0),
    fTrackListCascade(0), fTrackListCascadeNeg(0), fTrackListCascadePos(0),
    fTrackListCascadeBachelor(0), fTrackListCascadeMother(0),
    fTrackListPointingV0(0),
    fPsVertex(0), fITSClusters(0), fTPCClusters(0), fTRDClusters(0), fTOFClusters(0),
    fPsV0(0), fPsCascade(0), fTimer(0),
    obutton1(0), obutton2(0), obutton3(0), overlayButton(0),
    fAnalysis1TE(0), fAnalysis2TE(0), fMinvHisto(0),
    fD0PTHisto_Sig(0),fD0TAUHisto_Sig(0),fD0IPHisto_Sig(0),
    fD0PTHisto_Bkg(0),fD0TAUHisto_Bkg(0),fD0IPHisto_Bkg(0),
    fPad(0), fD0PTCut(0) ,fD0TAUCut(0), fD0IPCut(0), fFitRangeGaus(0), fFitRangePoly(0),
    fResultButton1(0), fResultButton2(0), fResultButton3(0), fResultButton4(0),
    fResultButton5(0), fResultButton6(0), fResultButton7(0), fResultButton8(0),
    fResultPicture1(0), fResultPicture2(0), fResultPicture3(0), fResultPicture4(0),
    fResultPicture5(0), fResultPicture6(0), fResultPicture7(0), fResultPicture8(0),
    fFitGaus(0), fFitExpo(0), fFitPolynomial(0), fSaveDir(0), fLoadDir(0), fTeacherName(0), 
  fTrendPad(0), fFitPad(0), fSigCacheForFit(0), fBkgCacheForFit(0), fVarToTrend(0),
  fPTRangeMin( 2.5f ), fPTRangeMax( 20.0f ), 
  fTAURangeMin(0.15f) , fTAURangeMax(10.15f), 
  fIPRangeMin(-4.0f), fIPRangeMax(1.5f), 
  fTrendPadNum( 0 )
  
    
  {
    LoadD0Ntuple(file_name);
    SetD0NtupleBranches();
    //fD0FitResultTrend_FitResults.clear();
    //fD0FitResultTrend.clear();
   
    fTrendPadMap.clear() ;
    fD0Trend_FitResults.clear();

    fVSD = new TEveVSD;


  }

  void TVSDReader::ToStudent(){

    fInDemoMode = kFALSE;

    globalChoice = 2;
    globalMode = 2;

    delete fVSD;

    fVertexLoaded = kFALSE;
    fITSClustersLoaded = kFALSE;
    fTPCClustersLoaded = kFALSE;
    fTRDClustersLoaded = kFALSE;
    fTOFClustersLoaded = kFALSE;
    fClustersLoaded = kFALSE;
    fEsdTracksLoaded = kTRUE;
    fV0sLoaded = kFALSE;
    fCascadesLoaded = kFALSE;
    fGuidesLoaded = kFALSE;
    fGeometrySet = kTRUE;


    fVSD = new TEveVSD;

    AutomaticMenu();

    //      GotoEvent(0);

    gEve->FullRedraw3D();

  }

  void TVSDReader::Exit(){
	 gEve->GetBrowser()->GetMainFrame()->UnmapWindow();
	/*  this->Delete();
	  gEve->GetBrowser()->GetMainFrame()->DeleteWindow();*/
  }

  void TVSDReader::SaveCanvas() {

    TString nametosave = pathSaveD0+filetosave + ".root"; 
    fPad->SaveAs(nametosave);
    nametosave = pathSaveD0+filetosave + ".eps";
    fPad->SaveAs(nametosave);
    nametosave = pathSaveD0+filetosave + ".pdf";
    fPad->SaveAs(nametosave);
    nametosave = pathSaveD0+filetosave + ".png";
    fPad->SaveAs(nametosave);

  }

  void TVSDReader::SetFileName() {
    filetosave = fName1->GetText(); 
  }

void TVSDReader::LHCbInfo()
{
  /* 
     Pop-up and LHCb dialog box with web-links
   */
  TRootHelpDialog* info = new TRootHelpDialog(gClient->GetRoot(), "LHCb Experiment", 360, 150);

  info->SetText(i6);
  
  info->DontCallClose();
  info->Popup();
}

  void TVSDReader::Instructions(){
	TRootHelpDialog* instructions = new TRootHelpDialog(gClient->GetRoot(), "INSTRUCTIONS", 700, 600);

	if(lang1==4){
const char* ins="Benvenuto nell'esercizio di LHCb per le masterclass: la misura della vita media della\n" 
	"particella D0\n"
"L'obiettivo di questo esercizio e' la misura della vita media della particella D0, una \n"
"particella costituita da un quark charm e un anti-quark up. Per fare questa misura, prima \n"
"imparerai come separare gli eventi di segnale - che contengono una particella D0 - da quelli \n"
"di fondo. Alla fine, confronterai i tuoi risultati con il valore trovato dal Particle Data Group \n" 
"(http://pdgLive.lbl.gov). \n"
"Istruzioni passo passo: \n"
"1. Fai il grafico della distribuzione della massa del D0. La massa del D0 e' una variabile \n"
"fondamentale che permette di separare gli eventi di segnale - la struttura a forma di picco nel\n" 
"centro della distribuzione - dal fondo - che ha invece una distribuzione piatta. \n"
"2. Osserva i risultati del fit e usali per determinare l'intervallo contenente gli eventi di \n"
"segnale. La funzione matematica usata nel fit del segnale e' una Gaussiana, la cui larghezza \n"
"- indicata dalla lettera greca sigma - dipende da quanto gli eventi di segnale sono lontani dal \n"
"valore medio (o valore piu' probabile). Piu' in dettaglio, un intervallo largo +/-1 sigma \n"
"attorno al valore medio contiene il 68% degli eventi di segnale, mentre un intervallo largo \n"
"+/- 3 sigma contiene il 99.7% degli eventi di segnale. Usa il cursore per fissare l'intervallo \n"
"del segnale a +/- 3 sigma attorno al valor medio.  \n"
"3. Fai il grafico delle distribuzioni delle variabili. Vedrai apparire altri tre grafici. In \n"
"ciascuno i punti blu rappresentano le distribuzioni della variabile negli eventi di segnale, \n"
"mentre i punti rossi rappresentano la distribuzione del fondo. Lungo l'asse Y il grafico e' in \n"
"scala logaritmica e ciascun punto rappresenta la frazione di segnale in quello specifico bin. \n"
"Quali intevalli contengono soprattutto segnale? Quali contengono soprattutto fondo? \n"
"4. Fai il fit della distribuzione della vita media. Salva il risultato del fit e confrontalo con il \n"
"valore PDG. Sono in accordo? \n"
"5. Ripeti il punto 4 ma ora riduci il valore superiore dell'intervallo della variabile log(IP) da\n" 
"1.5 a -2 a passi di 0.2. Alla fine noti un andamento particolare? \n"
"6. Discuti i tuoi risultati con un tutor. Il valore della vita media del D0 ottenuto con un taglio\n"
"di -1.5 sulla variabile log(IP) e' in accordo migliore o peggiore con il valore PDG rispetto\n"
"alla vita media misurata con un taglio di 1.5?\n";
instructions->SetText(ins);
	}
	else if(lang1==3){
const char* ins="Herzlich Willkommen bei den LHCb-Masterclasses Uebungen zur Messung\n" 
"der D0 meson Lebenszeit. \n"
"\nZiel dieser Uebung ist die Messung der D0-Lebenszeit. Das D0-Meson ist\n" 
"ein aus einem Charm- und einem Up-Quark zusammen gesetztes Teilchen. \n" 
"Dafuer wirst du zunaechst lernen Signal von Untergrund zu unterschieden. \n"
"Am Schluss wirst du deine Ergebnisse mit denen er Particle Data Group \n"
" (http://pdgLive.lbl.gov) vergleichen. \n"
"Schritt-fuer-Schritt-Anleitung: \n"
"\n1. Plotte die D0-Massenverteilung. Die Masse des D0 ist eine fundamentale \n"
"Groesse, die sehr gut zur Unterscheidung von Signal (der Peak in der Mitte) \n"
"und flachem Untergrund geeignet ist. \n"
"\n2. Schau dir das Fit-Ergebnis an und nutze es um das Signal-Interval zu \n"
"bestimmen. Die Funktion die an das Signal gefittet wurde ist eine Gauss-\n"
"Funktion, deren Breite (durch den griechischen Buchstaben sigma \n"
"beschrieben) eine Aussage darueber trifft, wie sehr das Signal sich von \n"
"seinem Mittelwert erstreckt. Ein Intervall von +/-1 sigma um den Mittelwert \n"
"enthaelt 68% der Signal-Ereignisse, waehrend +/-3 sigma schon 99.7% des \n"
"Signals enthalten. Benutze den Schieberegler um das Signal-Intervall auf ein \n"
"+/-3 sigma Intervall um den Mittelwert zu setzen. \n"
"\n3. Plotte die Variablen-Verteilungen. Du wirst drei neue Plots sehen. In \n"
"jedem dieser Plots repraesentieren die blauen Punkte die Signal-Verteilung\n" 
"in dieser Variablen, waehrend die roten Punkte die Untergrund-Verteilung \n"
"darstellen. Der Plot hat eine logarithmische y-Achse und jeder Punkt \n"
"repraesentiert den Anteil des Signals/Backgrounds im entsprechenden Bin. \n" 
"Welches Intervall enthaelt am meisten Signal, welches am meisten \n"
"Untergrund? \n"
"\n4. Fitte die Lebenszeit-Verteilung und speicher das Ergebnis des Fits. \n"
"Vergleiche deinen Wert fuer die D0-Lebenszeit mit dem der PDG. Ist dein \n"
"Ergebnis kompatibel? \n"
"\n5. Wiederhole Schritt 4: Aendere die obere D0 log(IP)-Variablen Grenze \n"
"von 1.5 zu -2 in 0.2 Schritten. Erkennst du ein Muster? \n"
"\n6. Sprich mit einem der Betreuer ueber dein Ergebnis. Stimmt die D0-\n"
"Lebenszeit besser mit dem PDG-Wert ueberein wenn du die log(IP)- \n"
"Variable auf -1.5 oder 1.5 schneidest? \n";
instructions->SetText(ins);
	}
	else if(lang1==2)
	{
const char* ins="Bienvenue dans l'exercice de masterclass LHCb sur la mesure du temps de vie \n"
"du meson D0. \n"
"\n Le but de cet exercice est de mesurer le temps de vie du meson D0. Le meson D0 \n"
"est une particule constituee d'un quark charme et d'un anti-quark haut. Afin de \n"
"realiser cette mesure, vous apprendrez a separer le signal correspondant au D0 \n"
"des bruit de fond. Puis vous pourrez comparer votre resultat avec celui du \n"
"Particle Data Group (PDG http://pdgLive.lbl.gov). \n"
"Instructions pas-a-pas\n"
"\n 1. Tracer la distribution de masse du D0. La masse du D0 est une quantite\n" 
"fondamentale qui permet dans l'exercice de separer le signal (le pic au milieu de \n"
"la distribution) du bruit de fond (qui lui est plat). \n"
"\n 2. Utiliser les resultats de l'ajustement pour determiner le domaine en masse du \n"
"signal. Le distribution en masse est ajuster par une fonction gaussienne. Son \n"
"ecart-type est designe par la lettre grecque sigma et determine jusqu'a quelle \n"
"valeur de masse le signal s'etend autour de sa moyenne. Ainsi, dans un intervalle\n" 
"de +/-1 sigma autour des la moyenne, on trouvera 68% des evenements de \n"
"signal, et 99.7% dans un intervalle de +/-3 sigma autour de la moyenne. Utilisez \n"
"le curseur pour selectionner le domaine de masse du signal a +/- 3 sigma autour \n"
"de la valeur moyenne. 	\n"
"\n 3. Tracer les distributions de variables. Trois nouveaux graphiques vont \n"
"apparaitre. Dans chacun les points bleu representent la distribution des \n"
"evenements de signal, tandis que les points rouge representent la distribution des \n"
"evenements de bruit de fond. Les graphiques sont traces sur une echelle \n"
"logarithmique sur l'ordonnee, et chaque points representent la fraction \n"
"d'evenements de signal ou de bruit de fond dans cet intervalle. Quelles domaines \n"
"des differentes variables contiennent le plus de signal? Lesquelles contiennent le \n"
"plus de bruit de fond? \n"
"\n 4. Ajuster la distribution du temps de vie. Enregistrez les resultats de \n"
"l'ajustement et comparez les avec les valeur du PDG. Sont elles comparables? \n"
"\n 5. Repetez l'etape 4 mais en variant la limite superieure du domaine de la \n"
"variable D0 log(IP) de 1.5 a -2 par pas de 0.2. Observez vous une tendance \n"
"particuliere? \n"
"\n 6. Discuter de vos resultats avec le demonstrateur. Le temps de vie du D0 est il \n"
"en meilleur accord avec le PDG avec une coupure sur le log(IP) a -1.5 ou a 1.5? \n";
instructions->SetText(ins);
	}
	else if (lang1==5)
	{
	const char* ins="Bine ati venit la exercitiul de masurare a timpului de viata a mezonului \n"
"D0 propus in cadrul programului LHCb masterclass. \n"
"\nScopul acestui exercitiu este de a masura timpul de viata al mezonului \n"
"D0, o particula elementara formata dintr-un cuarc charm si un \n"
"anticuarc up. Pentru aceasta va trebui mai intai sa invatati cum sa \n"
"separati adevaratii mezoni D0 de fond. Apoi veti compara rezultatele \n"
"voastre, cu cele publicate de Particle Data Group \n"
" (http://pdgLive.lbl.gov). \n"
"\nInstructiuni pas cu pas: \n"
"\n1. Reprezentati 	grafic distributia de masa a mezonului D0. Masa \n"
"mezonului D0 este o variabila fundamentala ce permite extragerea \n"
"semnalului (structura cu varf din mijloc) din distributia plata de fond. \n"
"\n2. Retineti rezultatele fit-ului si folositi-le pentru a determina regiunea \n"
"de semnal. Functia cu care este fitat semnalul este o functie Gauss a \n"
"carei largime, notata cu litera greceasca sigma, indica domeniul de \n"
"variatie a semnalului fata de valoarea medie (sau cea mai 	probabila). \n"
"De exemplu un interval de +/- 1 sigma in jurul valorii medii contine \n"
"67% din evenimentele de semnal, in timp ce +/- 3 sigma contine 99.7% \n"
"din semnal. Mutati cursoarele (la cele doua capete ale barii de selectie) \n"
"pentru a stabili un interval de semnal la +/- 3 sigma in jurul valorii medii. \n"
"\n3. Reprezentati grafic distributiile variabilelor. Vor aparea alte trei \n"
"reprezentari, iar in fiecare dintre acestea punctele albastre reprezinta \n"
"distributia semnalului in timp ce punctele rosii reprezinta distributia \n"
"fondului. Reprezentarea are scara logaritmica pe axa Y si fiecare punct \n"
"reprezinta fractiunea din semnalul total in acel interval (bin). \n"
"In care din regiunile fiecarei variabile apare cel mai mult semnal? Care \n"
"regiune contine cel mai mult fond? \n"
"\n4. Fitati distributia timpului de viata. Salvati rezultatele si comparati-le \n"
"cu valorile din PDG. Sunt in acord cu acestea? \n"
"\n5. Repetati pasul 4, dar acum variind valoarea superioara a intervalului \n"
"variabilei D0 log(IP) de la 1.5 la 2 in pasi de 0.2. Observati vreun tipar? \n"
"\n6. Discutati cu un indrumator rezultatele voastre. Timpul de viata al lui \n"
"D0 obtinut cu conditia asupra variabilei log(IP) de -1.5 este mai \n"
"apropiat sau nu de valorile PDG decat timpul de viata al D0 obtinut cu \n"
"conditia de 1.5 asupra aceleiasi variabile? \n";
	instructions->SetText(ins);
	}
	
	else{
		const char* ins="Welcome to the LHCb masterclass exercise on measuring the lifetime of the D0 meson. \n"
"The goal of this exercise is to measure the lifetime of the D0 meson, a fundamental\n"
"particle made of a charm quark and an up anti-quark. In order to do so, you will\n"
"first learn how to separate signal D0 mesons from backgrounds. Finally, you will\n"
"compare your results to the values found by the Particle Data Group (http://pdgLive.lbl.gov).\n"
"Step-by-step instructions :\n"
	"1. Plot the D0 mass distribution. The mass of the D0 is a fundamendal variable\n"
		"which separates signal (the peaking structure in the middle) from the flat\n"
		"background.\n"
	"2. Read the results of the fit and use them to determine the signal range. The\n"
		"function being fitted to the signal is a Gaussian, whose width, indicated by\n"
		"the greek letter sigma, is related to how far the signal extends from the mean\n"
		"(or most probable) value. In particular, an interval of +-1 sigma around the mean\n"
		"value contains 68% of the signal, while +-3 sigma contains 99.7% of the signal.\n"
		"Use the slider to set the signal range to be +-3 sigma around the mean value.\n"
	"3. Plot the variable distributions. You will see three further plots appearing, and\n"
		"in each one the blue points represent the distribution of the signal in that variable\n"
		"while the red points represent the distribution of the background. The plot is logarithmic\n"
		"in the Y axis, and each point represents the fraction of the total signal in that bin.\n"
		"Which regions of each variable contain mostly signal? Which contain mostly background?\n"
	"4. Fit the lifetime distribution. Save the results\n"
		"of your fit and compare them to the PDG value. Do they agree?\n"
	"5. Repeat step 4 but now varying the upper D0 log(IP) variable range\n"
		"from 1.5 to -2 in steps of 0.2. Do you notice a pattern?\n"
	"6. Talk to a demonstrator about your results. Does the D0 lifetime with an log(IP) cut of\n"
		"-1.5 agree better or worse with the PDG than the lifetime with an log(IP) cut of 1.5?\n";
		instructions->SetText(ins);
	}
        instructions->DontCallClose();
	instructions->Popup();

  }


void TVSDReader::DeleteHistograms()
{
  if ( fSigCacheForFit ) { delete fSigCacheForFit;fSigCacheForFit=0;}
  if ( fBkgCacheForFit ) { delete fBkgCacheForFit;fBkgCacheForFit=0;}
  if ( fMinvHisto )      { delete fMinvHisto;fMinvHisto = 0;}
  if ( fD0PTHisto_Sig )  { delete fD0PTHisto_Sig;fD0PTHisto_Sig=0;}
  if ( fD0TAUHisto_Sig ) { delete fD0TAUHisto_Sig;fD0TAUHisto_Sig=0;}
  if ( fD0IPHisto_Sig )  { delete fD0IPHisto_Sig;fD0IPHisto_Sig=0;}
  if ( fD0PTHisto_Bkg )  { delete fD0PTHisto_Bkg;fD0PTHisto_Bkg=0;}
  if ( fD0TAUHisto_Bkg ) { delete fD0TAUHisto_Bkg;fD0TAUHisto_Bkg=0;}
  if ( fD0IPHisto_Bkg )  { delete fD0IPHisto_Bkg;fD0IPHisto_Bkg=0;}
}


  void TVSDReader::ResetExercise(){
    for (int i=1;i<5;i++){ 
      fPad->GetPad(i)->Clear();
    }
    
    fPad->Update();

    if ( fTrendPad ){
      for (int i=1;i<5;i++){ 
        fTrendPad->GetPad(i)->Clear();
      }
      fTrendPad->Update();
    }
    
    if ( fFitPad )
    {
      for (int i=1;i<5;i++){ 
        fFitPad->GetPad(i)->Clear();
      }
      
      fFitPad->Update();
    }
   
    DeleteHistograms();

    fD0PTCut->SetValues(fPTRangeMin,fPTRangeMax);
    fD0TAUCut->SetValues(fTAURangeMin,fTAURangeMax);
    fD0IPCut->SetValues(fIPRangeMin,fIPRangeMax);
    fFitRangeGaus->SetValues(1815.,1915.);
    fFitRangePoly->SetValues(1815.,1915.);
    //fFitCut->SetNumber(0.0);
    fFitErr->SetNumber(0.0);
    fFitResult->SetNumber(0.0);
    fittedTime = false;
    fittedMass = false;
    
    
    fD0Trend_FitResults.clear() ;
    
    fTrendPadMap.clear() ;
    fTrendPadNum = 1;
  }

//-----------------

  void TVSDReader::LoadD0Ntuple(const char* file_name) {
    d0File = new TFile(file_name);
    if (d0File->IsZombie())
      throw MissingDataFile(file_name);
    d0Tree = (TTree*) d0File->Get("DecayTree");
  }

  void TVSDReader::SetD0NtupleBranches() {
    d0Tree->SetBranchStatus("D0_MM",1);
    d0Tree->SetBranchAddress("D0_MM",&D0_MM);
    d0Tree->SetBranchStatus("D0_PT",1);
    d0Tree->SetBranchAddress("D0_PT",&D0_PT);
    d0Tree->SetBranchStatus("D0_TAU",1);
    d0Tree->SetBranchAddress("D0_TAU",&D0_TAU);
    d0Tree->SetBranchStatus("D0_MINIP",1);
    d0Tree->SetBranchAddress("D0_MINIP",&D0_MINIP);
  }

  void TVSDReader::PlotFitResultsVsVar() {
   
    // Create the trend pad if it doesn't exist if it does navigate to it 
    TrendPad();
  
    int choice = fVarToTrend->GetSelected();

    FitResults::Trend* trendtype = 0 ;

    switch (choice) {
    case 1 : 
      trendtype = new FitResults::Trend( FitResults::min, "D^{0} PT (GeV)", 2.0, 6.0 );
      break;
    case 2 : 
      trendtype = new FitResults::Trend( FitResults::max, "log_{10}( D^{0} IP [mm] )",-4.0, 2.0 );
      break;
    case 3:
      trendtype = new FitResults::Trend( FitResults::max, "D^{0} PT (GeV)", 2.0, 20.0 );
      break;
    case 4:
      trendtype = new FitResults::Trend( FitResults::min, "log_{10}( D^{0} IP [mm] )",-4.0, 2.0 );
      break;
    default:
      return;
    }
 
    if (fD0Trend_FitResults[choice].empty()){
      TRootHelpDialog* instructions = new TRootHelpDialog(gClient->GetRoot(), "Plot", 350, 65);
      instructions->SetText(i2);
      instructions->DontCallClose();
      instructions->Popup();
      return;
    }
    
    // if it already exists clear the graph else create a new one.

    if ( fD0FitResultTrendPlot.find( choice ) != fD0FitResultTrendPlot.end() ){
      delete fD0FitResultTrendPlot[choice];
    }

    fD0FitResultTrendPlot[choice] = new TGraphErrors(fD0Trend_FitResults[choice].size());

    int npoint = 0;
    
    // consitency check
    CheckTrend( choice );
    
    std::map< int , std::vector< FitResults::FitPoint > >::iterator ichoice;
  
    ichoice = fD0Trend_FitResults.find(choice);
    
    if ( ichoice !=  fD0Trend_FitResults.end() ){
      
      std::vector< FitResults::FitPoint >::const_iterator ir;
  
      for ( ir = ichoice->second.begin(); ir != ichoice->second.end(); ++ir ){
        
        fD0FitResultTrendPlot[choice]->SetPoint( npoint , (*trendtype)( *ir ), ir->val );
        fD0FitResultTrendPlot[choice]->SetPointError( npoint , 0., ir->err );
        
        ++npoint;
      }
    }
    
    // check for min / max trend 
    
    if ( fTrendPadMap.find( choice ) == fTrendPadMap.end() ){
      if ( fTrendPadNum > 4 ) {
        fTrendPadNum = 1;
      }
      
      fTrendPadMap[choice] = fTrendPadNum;
      fTrendPadNum++;
    }
    
    fTrendPad->cd( fTrendPadMap[choice] );
    fTrendPad->GetPad( fTrendPadMap[choice]  )->SetLogy(0);
    
    
    fD0FitResultTrendPlot[choice]->Draw("AEP");
    fD0FitResultTrendPlot[choice]->GetXaxis()->SetLimits( trendtype->min, trendtype->max );
    fD0FitResultTrendPlot[choice]->GetXaxis()->SetTitle( trendtype->title );
    fD0FitResultTrendPlot[choice]->GetYaxis()->SetTitle("Fitted D^{0} lifetime (ps)");
    
    fD0FitResultTrendPlot[choice]->SetMaximum( 0.55 );
    fD0FitResultTrendPlot[choice]->SetMinimum( 0.35 );
    
    fTrendPad->Update();
    
    delete trendtype;
    
  }

Bool_t TVSDReader::CheckTrend( int choice ) //  const Bool_t def ) 
{
  std::map< int , std::vector< FitResults::FitPoint > >::iterator ichoice;
  
  ichoice = fD0Trend_FitResults.find(choice);
  
  if ( ichoice ==  fD0Trend_FitResults.end() ){
    return false;
  }
  
  
  Double_t lastupp = ichoice->second.begin()->upp;
  Double_t lastlow = ichoice->second.begin()->low;
  
  bool uppconst = true;
  bool lowconst = true;
  
  std::vector< FitResults::FitPoint >::const_iterator ir;
  
  for ( ir = ichoice->second.begin(); ir != ichoice->second.end(); ++ir ){
    
    uppconst &= ( std::abs( lastupp - ir->upp ) < 2.0*std::numeric_limits<double>::epsilon() );
    lowconst &= ( std::abs( lastlow - ir->low ) < 2.0*std::numeric_limits<double>::epsilon() );
    
    lastlow = ir->low;
    lastupp = ir->upp;
  }
  
  if ( uppconst || lowconst ) return true;
  
  TRootHelpDialog* instructions = new TRootHelpDialog(gClient->GetRoot(), "Plot", 350, 65);
  instructions->SetText(i4);
  instructions->DontCallClose();
  instructions->Popup();
  
  return false;
}


void TVSDReader::SaveFitResult() {
  if (!fittedTime) {
    TRootHelpDialog* instructions = new TRootHelpDialog(gClient->GetRoot(), "Plot", 350, 65);
    instructions->SetText(i3);
    instructions->DontCallClose();
    instructions->Popup();
    return;
  }

  int choice = fVarToTrend->GetSelected();

  Double_t min, max;
  
  switch ( choice ){
  case 1:
    min = fD0PTCut->GetMin();
    max = fD0PTCut->GetMax();
    break;
  case 2: 
    min = fD0IPCut->GetMin();
    max = fD0IPCut->GetMax();
    break;
  case 3:
    min = fD0PTCut->GetMin();
    max = fD0PTCut->GetMax();
    break;
  case 4:
    min = fD0IPCut->GetMin();
    max = fD0IPCut->GetMax();
  }
  
  fD0Trend_FitResults[choice].push_back( FitResults::FitPoint( min, max , fFitResult->GetNumber(),fFitErr->GetNumber() ) );
}

void TVSDReader::PlotD0Mass() {
  
  // Create the pad for the mass if it doesn't exist if it does, navigate to it. 
  VarPad() ;
  // Clear the variable plots when plotting the mass
  for (int i=1;i<5;i++){ 
    fPad->GetPad(i)->Clear(); 
  }
  
  fPad->Update();

  fPad->cd(1) ;

  int maxEvent = d0Tree->GetEntries();
  if (!fMinvHisto) {
    fMinvHisto = new TH1D("D0Mass","D0Mass",200,1815.0,1915.0);
    fMinvHisto->SetLineColor(1);
    fMinvHisto->GetXaxis()->SetTitle("D^{0} Invariant Mass (MeV/c^{2})");
    fMinvHisto->GetYaxis()->SetTitle("D^{0} Candidates/(0.5 MeV)");
    fMinvHisto->SetFillColor(0);
    fMinvHisto->Sumw2();
  } else fMinvHisto->Reset();
  for(Int_t nEvents = 0; nEvents < maxEvent; nEvents++){
    d0Tree->GetEntry(nEvents);
    if (D0_PT  < fD0PTCut->GetMin()*1000.     || D0_PT  > fD0PTCut->GetMax()*1000.)  continue;
    if (D0_TAU < fD0TAUCut->GetMin()/1000.    || D0_TAU > fD0TAUCut->GetMax()/1000.) continue;
    if (log10(D0_MINIP) < fD0IPCut->GetMin() || log10(D0_MINIP) > fD0IPCut->GetMax()) continue;
    fMinvHisto->Fill(D0_MM);
  }
  fMinvHisto->GetYaxis()->SetRangeUser(0,1000);
  fMinvHisto->Draw();
  fPad->Update();
}

void TVSDReader::PlotVarDists() {
  // navigate to fPad
  VarPad();

  int maxEvent = d0Tree->GetEntries();

  Double_t MinRange[2] = {fFitRangePoly->GetMin(),fFitRangeGaus->GetMin()};
  Double_t MaxRange[2] = {fFitRangeGaus->GetMax(),fFitRangePoly->GetMax()};

  if (!fittedMass) {
    TRootHelpDialog* instructions = new TRootHelpDialog(gClient->GetRoot(), "Plot", 350, 120); 
    instructions->SetText(i5);
    instructions->DontCallClose();
    instructions->Popup();
    return;
  }

  if (MinRange[0] == MinRange[1] || MaxRange[0] == MaxRange[1]) {
    TRootHelpDialog* instructions = new TRootHelpDialog(gClient->GetRoot(), "Plot", 350, 120);
    instructions->SetText(i1);
    instructions->DontCallClose();
    instructions->Popup();
    return;
  }
  
  if ( fSigCacheForFit ) delete fSigCacheForFit;
  if ( fBkgCacheForFit ) delete fBkgCacheForFit;
  
  fSigCacheForFit = new TH1D("D0TAU Sig For Fit","D0TAU Sig For Fit",100,fD0TAUCut->GetMin(),fD0TAUCut->GetMax());
  fSigCacheForFit->SetLineColor(2);
  fSigCacheForFit->SetMarkerColor(2);
  fSigCacheForFit->SetMarkerStyle(24);
  fSigCacheForFit->GetXaxis()->SetTitle("D^{0} decay time (ps)");
  fSigCacheForFit->GetYaxis()->SetTitle("D^{0} Candidate Fraction");
  fSigCacheForFit->SetFillColor(0);
  fSigCacheForFit->Sumw2();
  
  fBkgCacheForFit = new TH1D("D0TAU Bkg For Fit","D0TAU Bkg For Fit",100,fD0TAUCut->GetMin(),fD0TAUCut->GetMax());
  fBkgCacheForFit->SetLineColor(2);
  fBkgCacheForFit->SetMarkerColor(2);
  fBkgCacheForFit->SetMarkerStyle(24);
  fBkgCacheForFit->GetXaxis()->SetTitle("D^{0} decay time (ps)");
  fBkgCacheForFit->GetYaxis()->SetTitle("D^{0} Candidate Fraction");
  fBkgCacheForFit->SetFillColor(0);
  fBkgCacheForFit->Sumw2();

  double backscalingfactor = Background_Integral(MinRange[1],MaxRange[0]);
  backscalingfactor /= (Background_Integral(MinRange[0],MinRange[1])+Background_Integral(MaxRange[0],MaxRange[1]));

  if (!fD0PTHisto_Sig) {
    fD0PTHisto_Sig = new TH1D("D0PT Sig","D0PT Sig",175,fPTRangeMin,fPTRangeMax); //fD0PTCut->GetMin(),fD0PTCut->GetMax());
    fD0PTHisto_Sig->SetLineColor(4);
    fD0PTHisto_Sig->SetMarkerColor(4);
    fD0PTHisto_Sig->SetMarkerStyle(26);
    fD0PTHisto_Sig->GetXaxis()->SetTitle("D^{0} P_{T} (GeV/c^{2})");
    fD0PTHisto_Sig->GetYaxis()->SetTitle("D^{0} Candidate Fraction");
    fD0PTHisto_Sig->SetFillColor(0);
    fD0PTHisto_Sig->Sumw2();
  } else {
    fD0PTHisto_Sig->Reset();
    //  fD0PTHisto_Sig->GetXaxis()->SetRangeUser(fD0PTCut->GetMin(),fD0PTCut->GetMax());
  }

  if (!fD0TAUHisto_Sig) {
    fD0TAUHisto_Sig = new TH1D("D0TAU Sig","D0TAU Sig",1000,fTAURangeMin,fTAURangeMax); 
    //fD0TAUCut->GetMin(),fD0TAUCut->GetMax());
    fD0TAUHisto_Sig->SetLineColor(4);
    fD0TAUHisto_Sig->SetMarkerColor(4);
    fD0TAUHisto_Sig->SetMarkerStyle(26);
    fD0TAUHisto_Sig->GetXaxis()->SetTitle("D^{0} decay time (ps)");
    fD0TAUHisto_Sig->GetYaxis()->SetTitle("D^{0} Candidate Fraction");
    fD0TAUHisto_Sig->SetFillColor(0);
    fD0TAUHisto_Sig->Sumw2();
  } else {
    fD0TAUHisto_Sig->Reset();
    //  fD0TAUHisto_Sig->GetXaxis()->SetRangeUser(fD0TAUCut->GetMin(),fD0TAUCut->GetMax());
  }

  if (!fD0IPHisto_Sig) {
    fD0IPHisto_Sig = new TH1D("D0IP Sig","D0IP Sig",110,fIPRangeMin,fIPRangeMax); 
    //fD0IPCut->GetMin(),fD0IPCut->GetMax());
    fD0IPHisto_Sig->SetLineColor(4);
    fD0IPHisto_Sig->SetMarkerColor(4);
    fD0IPHisto_Sig->SetMarkerStyle(26);
    fD0IPHisto_Sig->GetXaxis()->SetTitle("log_{10}(D^{0} IP)");
    fD0IPHisto_Sig->GetYaxis()->SetTitle("D^{0} Candidate Fraction");
    fD0IPHisto_Sig->SetFillColor(0);
    fD0IPHisto_Sig->Sumw2();
  } else {
    fD0IPHisto_Sig->Reset();
    //    fD0IPHisto_Sig->GetXaxis()->SetRangeUser(fD0IPCut->GetMin(),fD0IPCut->GetMax());
  }

  if (!fD0PTHisto_Bkg) {
    fD0PTHisto_Bkg = new TH1D("D0PT Bkg","D0PT Bkg",175,fPTRangeMin,fPTRangeMax); 
    //fD0PTCut->GetMin(),fD0PTCut->GetMax());
    fD0PTHisto_Bkg->SetLineColor(2);
    fD0PTHisto_Bkg->SetMarkerColor(2);
    fD0PTHisto_Bkg->SetMarkerStyle(24);
    fD0PTHisto_Bkg->GetXaxis()->SetTitle("D^{0} P_{T} (GeV/c^{2})");
    fD0PTHisto_Bkg->GetYaxis()->SetTitle("D^{0} Candidate Fraction");
    fD0PTHisto_Bkg->SetFillColor(0);
    fD0PTHisto_Bkg->Sumw2();
  } else {
    fD0PTHisto_Bkg->Reset();
    //  fD0PTHisto_Bkg->GetXaxis()->SetRangeUser(fD0PTCut->GetMin(),fD0PTCut->GetMax());
  }

  if (!fD0TAUHisto_Bkg) {
    fD0TAUHisto_Bkg = new TH1D("D0TAU Bkg","D0TAU Bkg",1000,fTAURangeMin,fTAURangeMax); 
                               // fD0TAUCut->GetMin(),fD0TAUCut->GetMax());
    fD0TAUHisto_Bkg->SetLineColor(2);
    fD0TAUHisto_Bkg->SetMarkerColor(2);
    fD0TAUHisto_Bkg->SetMarkerStyle(24);
    fD0TAUHisto_Bkg->GetXaxis()->SetTitle("D^{0} decay time (ps)");
    fD0TAUHisto_Bkg->GetYaxis()->SetTitle("D^{0} Candidate Fraction");
    fD0TAUHisto_Bkg->SetFillColor(0);
    fD0TAUHisto_Bkg->Sumw2();
  } else {
    fD0TAUHisto_Bkg->Reset();
    //  fD0TAUHisto_Bkg->GetXaxis()->SetRangeUser(fD0TAUCut->GetMin(),fD0TAUCut->GetMax());
  }

  if (!fD0IPHisto_Bkg) {
    fD0IPHisto_Bkg = new TH1D("D0IP Bkg","D0IP Bkg",110,fIPRangeMin,fIPRangeMax); 
    //fD0IPCut->GetMin(),fD0IPCut->GetMax());
    fD0IPHisto_Bkg->SetLineColor(2);
    fD0IPHisto_Bkg->SetMarkerColor(2);
    fD0IPHisto_Bkg->SetMarkerStyle(24);
    fD0IPHisto_Bkg->GetXaxis()->SetTitle("log_{10}(D^{0} IP)");
    fD0IPHisto_Bkg->GetYaxis()->SetTitle("D^{0} Candidate Fraction");
    fD0IPHisto_Bkg->SetFillColor(0);
    fD0IPHisto_Bkg->Sumw2();
  } else {
    fD0IPHisto_Bkg->Reset();
    //  fD0IPHisto_Bkg->GetXaxis()->SetRangeUser(fD0IPCut->GetMin(),fD0IPCut->GetMax());
  }

  for(Int_t nEvents = 0; nEvents < maxEvent; nEvents++){
    d0Tree->GetEntry(nEvents);
    if (D0_PT  < fD0PTCut->GetMin()*1000.     || D0_PT  > fD0PTCut->GetMax()*1000.)  continue;
    if (D0_TAU < fD0TAUCut->GetMin()/1000.    || D0_TAU > fD0TAUCut->GetMax()/1000.) continue;
    if (log10(D0_MINIP) < fD0IPCut->GetMin() || log10(D0_MINIP) > fD0IPCut->GetMax()) continue;

    if (D0_MM < MinRange[1] || D0_MM > MaxRange[0]) {
      fD0PTHisto_Bkg->Fill(D0_PT/1000.);
      fD0TAUHisto_Bkg->Fill(D0_TAU*1000.);
      fBkgCacheForFit->Fill(D0_TAU*1000.);
      fD0IPHisto_Bkg->Fill(log10(D0_MINIP));
    } else {
      fD0PTHisto_Sig->Fill(D0_PT/1000.);
      fD0TAUHisto_Sig->Fill(D0_TAU*1000.);
      fSigCacheForFit->Fill(D0_TAU*1000.);
      fD0IPHisto_Sig->Fill(log10(D0_MINIP));
    }
  }

  fD0PTHisto_Sig->Add(fD0PTHisto_Bkg,-1.*backscalingfactor);
  fD0TAUHisto_Sig->Add(fD0TAUHisto_Bkg,-1.*backscalingfactor);
  fD0IPHisto_Sig->Add(fD0IPHisto_Bkg,-1.*backscalingfactor);
  
  fSigCacheForFit->Add(fBkgCacheForFit,-1.*backscalingfactor);

  fPad->cd(2);
  fPad->GetPad(2)->SetLogy();
  fD0PTHisto_Bkg->DrawNormalized();
  fD0PTHisto_Sig->DrawNormalized("SAME");
  TLegend* leg=new TLegend(0.575,0.725,0.875,0.875);
  leg->SetFillStyle(0);
  leg->SetMargin(0.25f);
  leg->SetTextSize(0.05f);
  leg->SetFillColor(0);
  leg->AddEntry(fD0PTHisto_Bkg,"Background", "p");
  leg->AddEntry(fD0PTHisto_Sig,"Signal", "p");
  leg->Draw("same");
  fPad->Update();

  fPad->cd(3);
  fPad->GetPad(3)->SetLogy();
  fD0TAUHisto_Bkg->DrawNormalized();
  fD0TAUHisto_Sig->DrawNormalized("SAME");
  TLegend* leg2=new TLegend(0.575,0.725,0.875,0.875);
  leg2->SetFillStyle(0);
  leg2->SetMargin(0.25f);
  leg2->SetTextSize(0.05f);
  leg2->SetFillColor(0);
  leg2->AddEntry(fD0TAUHisto_Bkg,"Background", "p");
  leg2->AddEntry(fD0TAUHisto_Sig,"Signal", "p");
  leg2->Draw("same");
  fPad->Update();

  fPad->cd(4);
  fPad->GetPad(4)->SetLogy();
  fD0IPHisto_Sig->DrawNormalized();
  fD0IPHisto_Bkg->DrawNormalized("SAME");
  TLegend* leg3=new TLegend(0.175,0.725,0.375,0.875);
  leg3->SetFillStyle(0);
  leg3->SetMargin(0.25f);
  leg3->SetTextSize(0.05f);
  leg3->SetFillColor(0);
  leg3->AddEntry(fD0IPHisto_Bkg,"Background", "p");
  leg3->AddEntry(fD0IPHisto_Sig,"Signal", "p");
  leg3->Draw("same");

  fPad->Update();

  fittedTime = false;

}

void TVSDReader::FitDecayTime() {

  if (!fD0TAUHisto_Sig) {
    TRootHelpDialog* instructions = new TRootHelpDialog(gClient->GetRoot(), "Plot", 350, 65);
    instructions->SetText("You must plot the variable distributions\nbefore attempting to fit the signal lifetime.");
    instructions->DontCallClose();
    instructions->Popup();
    return;
  }

  /* pad creation and navigation */
  FitPad() ;
  
  if (!fFitExpo) fFitExpo = new TF1("fitExpo","expo(0)",fD0TAUCut->GetMin(),fD0TAUCut->GetMax());
  else {
    delete fFitExpo;
    fFitExpo = new TF1("fitExpo","expo(0)",fD0TAUCut->GetMin(),fD0TAUCut->GetMax());
  }

  /*fFitExpo->SetParameter(0,5.);
    fFitExpo->SetParLimits(0,0.0,TMath::Power(10.,9));
    fFitExpo->SetParameter(1,-2.);
    fFitExpo->SetParLimits(1,-10.0,0.0);*/

  fFitExpo->SetLineColor(kGreen+1);
  fFitExpo->SetLineWidth(2);
  
  fSigCacheForFit->Draw("same");
  fSigCacheForFit->Fit(fFitExpo,"rmeh");
  
  fFitPad->GetPad(1)->SetLogy();
  
  TLatex *labels2 = new TLatex(0,0,"Fit Parameters");
  labels2->SetTextSize(0.04f);
  labels2->SetTextColor(kBlack);
  labels2->SetNDC(kTRUE);
  Double_t LabelX = 0.35;
  Double_t LabelY = 0.8;
  //Double_t LabelYstep = 0.05;

  labels2->DrawLatex(LabelX, LabelY,Form("D^{0} lifetime %.4f #pm %.4f (ps)",
                                         -1./fFitExpo->GetParameter(1),
                                         fFitExpo->GetParError(1)/(fFitExpo->GetParameter(1)*fFitExpo->GetParameter(1))));

  fittedTime = true;

  //fFitCut->SetNumber(fD0IPCut->GetMax());
  fFitResult->SetNumber(-1./fFitExpo->GetParameter(1));
  fFitErr->SetNumber(fFitExpo->GetParError(1)/(fFitExpo->GetParameter(1)*fFitExpo->GetParameter(1)));

  fFitPad->Update();
}

void TVSDReader::FitInvariantMass()
{

  if (!fMinvHisto) {
    TRootHelpDialog* instructions = new TRootHelpDialog(gClient->GetRoot(), "Plot", 350, 65);
    instructions->SetText("You must plot the invariant mass\ndistribution before attempting to fit it.");
    instructions->DontCallClose();
    instructions->Popup();
    return;
  }

  fPad->cd(1);
  Double_t MinRange = TMath::Min(fFitRangePoly->GetMin(),fFitRangeGaus->GetMin());
  Double_t MaxRange = TMath::Max(fFitRangePoly->GetMax(),fFitRangeGaus->GetMax());

  if (!fFitGaus) fFitGaus = new TF1("fitGaus","[0]*TMath::Gaus(x,[1],[2])+[3]*x+[4]",MinRange,MaxRange);
  else fFitGaus->SetRange(MinRange,MaxRange);

  fFitGaus->SetParameter(0,80.);
  fFitGaus->SetParameter(1,0.5*(fFitRangeGaus->GetMin()+fFitRangeGaus->GetMax()));
  fFitGaus->SetParameter(2,1.);
  fFitGaus->SetParLimits(0,0.,TMath::Power(10.,9));
  fFitGaus->SetParLimits(1,fFitRangeGaus->GetMin(),fFitRangeGaus->GetMax());
  fFitGaus->SetParLimits(2,0.,(fFitRangeGaus->GetMax()-fFitRangeGaus->GetMin())/2.);

  fFitGaus->SetLineColor(kBlue+1);
  fFitGaus->SetLineWidth(2);
  fMinvHisto->Fit(fFitGaus,"rmeh");

  TLatex *labels2 = new TLatex(0,0,"Fit Parameters");
  labels2->SetTextSize(0.04f);
  labels2->SetTextColor(kBlack);
  labels2->SetNDC(kTRUE);
  Double_t LabelX = 0.15;
  Double_t LabelY = 0.825;
  Double_t LabelYstep = 0.05;

  Double_t BinWidth= fMinvHisto->GetBinWidth(1);
  Float_t GausMin= fFitRangeGaus->GetMin();
 // printf(">>>>>>>>>>>>>>>>>> %f", GausMin);
  Float_t GausMax=fFitRangeGaus->GetMax();
 // printf(">>>>>>>>>>>>>>>>>> %f", GausMax);
  Double_t pom= (Int_t)(fFitGaus->Integral(GausMin,GausMax)/BinWidth);
  //(Int_t)Background_Integral(MinRange,MaxRange); //Integral(10,20); //GausMin,GausMax);
  Int_t Total_Fit = (Int_t)(pom);
  Int_t Bck_Fit = (Int_t)(Background_Integral(GausMin,GausMax)/BinWidth);
  
  labels2->DrawLatex(LabelX, LabelY,Form("Total: %d",Total_Fit));
  labels2->DrawLatex(LabelX, LabelY-LabelYstep,Form("Background: %d",Bck_Fit));
  labels2->DrawLatex(LabelX, LabelY-2.*LabelYstep,Form("Signal: %d",Total_Fit-Bck_Fit));
  labels2->DrawLatex(LabelX, LabelY-3.*LabelYstep,Form("Mean: %.1f#pm%.1f",fFitGaus->GetParameter(1),
                                                       fFitGaus->GetParError(1)));
  labels2->DrawLatex(LabelX, LabelY-4.*LabelYstep,Form("#sigma: %.1f#pm%.1f",fFitGaus->GetParameter(2),
                                                       fFitGaus->GetParError(2)));

  if(!fFitPolynomial) fFitPolynomial = new TF1("fitPoly","[0]*x+[1]",MinRange,MaxRange);
  else fFitPolynomial->SetRange(MinRange,MaxRange);
  fFitPolynomial->SetParameter(0,fFitGaus->GetParameter(3));
  fFitPolynomial->SetParameter(1,fFitGaus->GetParameter(4));
  fFitPolynomial->SetLineColor(kRed+1);
  fFitPolynomial->SetLineWidth(2);
  fFitPolynomial->Draw("SAME");

  fittedMass = true;

  fPad->Update();
}

Double_t TVSDReader::Background_Integral(Double_t xmin, Double_t xmax) {
  return  ((xmax-xmin)*fFitGaus->GetParameter(4)+fFitGaus->GetParameter(3)*(xmax*xmax-xmin*xmin)/2.);
}


void TVSDReader::ClearTrend() 
{
  int choice = fVarToTrend->GetSelected();
  // Delete existing trend plot
  
  std::map< int, std::vector< FitResults::FitPoint > >::iterator it;
  
  it = fD0Trend_FitResults.find( choice );
  
  if ( it != fD0Trend_FitResults.end() ){ it->second.clear(); }

  if ( fTrendPadMap.find(choice) != fTrendPadMap.end() ){
    fTrendPad->GetPad(fTrendPadMap[choice])->Clear();
    fTrendPad->Update();
  }
}


void TVSDReader::AutomaticMenu()
{
  TGTextButton* b=0;
  TGTextButton* bisc=0;
  TGTextButton* bi=0;
  TGTextButton* bii=0;
  TGGroupFrame* gf=0;
  TGVerticalFrame* vf=0;
  TGHorizontalFrame* hf=0;
  TEveBrowser* browser = gEve->GetBrowser();

 // if(browser->GetMainFrame()->IsVisible())
 
	  browser->GetMainFrame()->SetWindowName(Form("LHCb Masterclass : D0 lifetime analysis"));

  browser->GetMainFrame()->MapWindow();

  if(browser->GetTabRight()->GetTabTab(3))
    browser->GetTabRight()->RemoveTab(3);

  if(browser->GetTabRight()->GetTabTab(2))
    browser->GetTabRight()->RemoveTab(2);

  if(browser->GetTabLeft()->GetTabTab(1))
    browser->GetTabLeft()->RemoveTab(1);

  if(browser->GetTabLeft()->GetTabTab(0))
    browser->GetTabLeft()->RemoveTab(0);

  if(browser->GetTabBottom()->GetTabTab(0))
    browser->GetTabBottom()->RemoveTab(0);
  
  if(browser->GetTabRight()->GetTabTab(0))
    browser->GetTabRight()->RemoveTab(0);

	if(browser->GetTabRight()->GetTabTab(0))
    browser->GetTabRight()->RemoveTab(0);
	
  browser->StartEmbedding(TRootBrowser::kLeft);

  frmMain = new TGMainFrame(gClient->GetRoot(), 1000, 600);
  
  frmMain->SetWindowName("XX GUI");
  
  //frmMain->SetCleanup(kDeepCleanup);

  TString icondir(TString::Format("%s/icons/", gSystem->Getenv("ROOTSYS")) );
 
  ULong_t buttonRedColor,buttonBlueColor;
  //left tab
  TGTab *left = gEve->GetBrowser()->GetTabLeft();
   TGFrame *parent = (TGFrame *)left->GetParent();
   parent->Resize(parent->GetDefaultWidth()*0.8, parent->GetDefaultHeight());
     if (gEve->GetDefaultGLViewer()) {
        gEve->GetDefaultGLViewer()->RefreshPadEditor();
   }
  gf = new TGGroupFrame(frmMain, var_ranges);
    
  vf = new TGVerticalFrame(gf, 200, 20, kFixedWidth);
  {

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 5, 5, 5, 5));

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {

      fD0PTCut = new TEveGDoubleValuator(hf,"D0 PT :", 40, 0);
      fD0PTCut->SetNELength(5);
      fD0PTCut->SetLabelWidth(70);
      fD0PTCut->Build();
      fD0PTCut->GetSlider()->SetWidth(190);
      fD0PTCut->SetLimits(fPTRangeMin, fPTRangeMax, TGNumberFormat::kNESRealOne);
      fD0PTCut->SetValues(fPTRangeMin, fPTRangeMax, TGNumberFormat::kNESRealOne);

      hf->AddFrame(fD0PTCut, new TGLayoutHints(kLHintsExpandX));

    }

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 5, 5, 5, 5));

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {

      fD0TAUCut = new TEveGDoubleValuator(hf,"D0 TAU :", 40, 0);
      fD0TAUCut->SetNELength(5);
      fD0TAUCut->SetLabelWidth(70);
      fD0TAUCut->Build();
      fD0TAUCut->GetSlider()->SetWidth(190);
      fD0TAUCut->SetLimits(fTAURangeMin, fTAURangeMax, TGNumberFormat::kNESRealTwo);
      fD0TAUCut->SetValues(fTAURangeMin, fTAURangeMax, TGNumberFormat::kNESRealTwo);

      hf->AddFrame(fD0TAUCut, new TGLayoutHints(kLHintsExpandX));

    }

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 5, 5, 5, 5));

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {

      fD0IPCut = new TEveGDoubleValuator(hf,"D0 IP :", 40, 0);
      fD0IPCut->SetNELength(5);
      fD0IPCut->SetLabelWidth(70);
      fD0IPCut->Build();
      fD0IPCut->GetSlider()->SetWidth(190);
      fD0IPCut->SetLimits(fIPRangeMin, fIPRangeMax, TGNumberFormat::kNESRealOne);
      fD0IPCut->SetValues(fIPRangeMin, fIPRangeMax, TGNumberFormat::kNESRealOne);

      hf->AddFrame(fD0IPCut, new TGLayoutHints(kLHintsExpandX));

    }

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 5, 5, 5, 5));

  }

  gf->AddFrame(vf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));

  frmMain->AddFrame(gf);

  gf = new TGGroupFrame(frmMain, an_tools);

  vf = new TGVerticalFrame(gf, 200, 20, kFixedWidth);
  {

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {

      b = new TGTextButton(hf, plt_mass);
      b->Connect("Clicked()", "TVSDReader", this, "PlotD0Mass()");

      hf->AddFrame(b, new TGLayoutHints(kLHintsExpandX));

    }
    
    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 0,0,5,0));
    
    /* added TB   */
    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {
      b = new TGTextButton(hf, fit_mass_dis);
      b->Connect("Clicked()", "TVSDReader", this, "FitInvariantMass()");
      hf->AddFrame(b, new TGLayoutHints(kLHintsExpandX));
    }

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));
    //

   

  }

  gf->AddFrame(vf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));

  frmMain->AddFrame(gf);

  gf = new TGGroupFrame(frmMain, bg_sub);

  vf = new TGVerticalFrame(gf, 200, 20, kFixedWidth);
  {

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 5, 5, 5, 5));

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {

      fFitRangePoly = new TEveGDoubleValuator(hf,"Bkg range:", 40, 0);
      fFitRangePoly->SetNELength(6);
      fFitRangePoly->SetLabelWidth(60);
      fFitRangePoly->Build();
      fFitRangePoly->GetSlider()->SetWidth(190);
      fFitRangePoly->SetLimits(1815, 1915, TGNumberFormat::kNESRealOne);
      fFitRangePoly->SetValues(1815, 1915, TGNumberFormat::kNESRealOne);

      //hf->AddFrame(fFitRangePoly, new TGLayoutHints(kLHintsExpandX));

    }

    //vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 5, 5, 5, 5));

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {

      fFitRangeGaus = new TEveGDoubleValuator(hf,"Sig range:", 40, 0);
      fFitRangeGaus->SetNELength(6);
      fFitRangeGaus->SetLabelWidth(60);
      fFitRangeGaus->Build();
      fFitRangeGaus->GetSlider()->SetWidth(190);
      fFitRangeGaus->SetLimits(1815, 1915, TGNumberFormat::kNESRealOne);
      fFitRangeGaus->SetValues(1815, 1915, TGNumberFormat::kNESRealOne);

      hf->AddFrame(fFitRangeGaus, new TGLayoutHints(kLHintsExpandX));

    }

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 5, 5, 5, 5));

    /*
    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {
      b = new TGTextButton(hf, "Fit mass distribution");
      b->Connect("Clicked()", "TVSDReader", this, "FitInvariantMass()");
      hf->AddFrame(b, new TGLayoutHints(kLHintsExpandX));
    }

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 5, 5, 5, 5));
    */

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {
      b = new TGTextButton(hf, plt_distr);
      b->Connect("Clicked()", "TVSDReader", this, "PlotVarDists()");
      hf->AddFrame(b, new TGLayoutHints(kLHintsExpandX));
    } 
    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 0, 0, 5, 0));
  }

  gf->AddFrame(vf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY ) );

  frmMain->AddFrame(gf);

  gf = new TGGroupFrame(frmMain,t_fit);

  vf = new TGVerticalFrame(gf, 200, 20, kFixedWidth);
  {

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY ));

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {
      b = new TGTextButton(hf, fit_sign);
      b->Connect("Clicked()", "TVSDReader", this, "FitDecayTime()");
      hf->AddFrame(b, new TGLayoutHints(kLHintsExpandX));
    }

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY ));

  }

  gf->AddFrame(vf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 0, 0, 5, 0));

   vf = new TGVerticalFrame(gf, 200, 20, kFixedWidth);
  {

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {

      TGHorizontalFrame*  hframe = new TGHorizontalFrame(hf, 50, 20, kFixedWidth);
      /*{

        TGLabel* val1 = new TGLabel(hframe, "IP Cut");
    	  val1->SetTextJustify(kTextCenterX);
    	  hframe->AddFrame(val1, new TGLayoutHints(kLHintsExpandX, 1, 1, 1, 1));        }

      hf->AddFrame(hframe, new TGLayoutHints(kLHintsExpandX));

      hframe = new TGHorizontalFrame(hf, 50, 20, kFixedWidth);*/
      {

        TGLabel* val2 = new TGLabel(hframe, "Fit Result");
    	  val2->SetTextJustify(kTextCenterX);
    	  hframe->AddFrame(val2, new TGLayoutHints(kLHintsExpandX, 1, 1, 1, 1));

      }

      hf->AddFrame(hframe, new TGLayoutHints(kLHintsExpandX));

      hframe = new TGHorizontalFrame(hf, 50, 20, kFixedWidth);
      {

        TGLabel* val3 = new TGLabel(hframe, "Fit Error");
    	  val3->SetTextJustify(kTextCenterX);
    	  hframe->AddFrame(val3, new TGLayoutHints(kLHintsExpandX, 1, 1, 1, 1));

      }

      hf->AddFrame(hframe, new TGLayoutHints(kLHintsExpandX));
    }

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));

  }

  gf->AddFrame(vf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));

  vf = new TGVerticalFrame(gf, 200, 20, kFixedWidth);
  {

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {

      TGHorizontalFrame*  hframe = new TGHorizontalFrame(hf, 50, 20, kFixedWidth);
      /*{

        fFitCut = new TGNumberEntryField(hframe,0,0,TGNumberFormat::kNESRealTwo);
        hframe->AddFrame(fFitCut, new TGLayoutHints(kLHintsExpandX));        }

      hf->AddFrame(hframe, new TGLayoutHints(kLHintsExpandX));*/

      hframe = new TGHorizontalFrame(hf, 50, 20, kFixedWidth);
      {

        fFitResult = new TGNumberEntryField(hframe,1,0,TGNumberFormat::kNESRealFour);
        hframe->AddFrame(fFitResult, new TGLayoutHints(kLHintsExpandX));

      }

      hf->AddFrame(hframe, new TGLayoutHints(kLHintsExpandX));

      hframe = new TGHorizontalFrame(hf, 50, 20, kFixedWidth);
      {
        fFitErr = new TGNumberEntryField(hframe,2,0,TGNumberFormat::kNESRealFour);
        hframe->AddFrame(fFitErr, new TGLayoutHints(kLHintsExpandX));
      }
      hf->AddFrame(hframe, new TGLayoutHints(kLHintsExpandX));
    }
    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));
  }

  gf->AddFrame(vf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));
  
  frmMain->AddFrame(gf);

  
  gf = new TGGroupFrame(frmMain, save_res);

  
 
  vf = new TGVerticalFrame(gf, 200, 20, kFixedWidth);
  {
    
    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    
    // {
    //  b = new TGTextButton(hf, "Plot D0 lifetime trend vs.");
    //  b->Connect("Clicked()", "TVSDReader", this, "PlotFitResultsVsVar()");
    //  hf->AddFrame(b, new TGLayoutHints(kLHintsExpandX));
    //}

    fVarToTrend = new TGComboBox(hf);
    
    //fVarToTrend->AddEntry("Trend vs. min PT", 1);
    fVarToTrend->AddEntry("Trend vs. max IP", 2);
    //fVarToTrend->AddEntry("Trend vs. max PT", 3);
    //fVarToTrend->AddEntry("Trend vs. min IP", 4);

    fVarToTrend->Resize(200,20); // 50, 20 
    fVarToTrend->Select(2,kFALSE);
    //fVarToTrend->Connect("Selected(Int_t)", "TVSDReader", this, "ClearTrend()");

    hf->AddFrame(fVarToTrend);//, new TGLayoutHints(kLHintsExpandX));
  
    //vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));    

    //hf = new TGHorizontalFrame(vf, 150, 20, kFixedWidth); 

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));  

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY, 5, 5, 5, 5));

    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {
      b = new TGTextButton(hf, sv_res_fit);
      b->Connect("Clicked()", "TVSDReader", this, "SaveFitResult()");
      hf->AddFrame(b, new TGLayoutHints(kLHintsExpandX));
    }

    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));
    
    
    hf = new TGHorizontalFrame(vf, 200, 20, kFixedWidth);
    {
      b = new TGTextButton(hf, pl_trend);
      b->Connect("Clicked()", "TVSDReader", this, "PlotFitResultsVsVar()");
      hf->AddFrame(b, new TGLayoutHints(kLHintsExpandX));
    
      b = new TGTextButton(hf, cl_trend);
      b->Connect("Clicked()", "TVSDReader", this, "ClearTrend()");
      hf->AddFrame(b, new TGLayoutHints(kLHintsExpandX));
    }
    
    vf->AddFrame(hf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));
  }

  gf->AddFrame(vf, new TGLayoutHints(kLHintsExpandX | kLHintsCenterY));

  vf = new TGVerticalFrame(gf);
  {
    hf = new TGHorizontalFrame(vf);
    {
      const TGPicture *logo = gClient->GetPicture("share/LHCbMasterclass/lhcb-logo.png");
      if (!logo) // the local picture is not available, use the installed one
        logo = gClient->GetPicture(DATA_DIR "/lhcb-logo.png");
      TGPictureButton* b1 = new TGPictureButton(hf, logo);
      b1->Connect("Clicked()", "TVSDReader", this, "LHCbInfo()");
      hf->AddFrame(b1, new TGLayoutHints(kLHintsExpandX, 5, 5, 5, 5));
    }
    vf->AddFrame(hf);
  }
  gf->AddFrame(vf);

  frmMain->AddFrame(gf);

  frmMain->MapSubwindows();
  frmMain->Resize();
  frmMain->MapWindow();

  browser->StopEmbedding(tools);
  
  browser->StartEmbedding(TRootBrowser::kBottom);

  frmMain = new TGMainFrame(gClient->GetRoot(), 1000, 600, kHorizontalFrame);
  frmMain->SetWindowName("XX GUI");
  frmMain->SetCleanup(kDeepCleanup);

  //   hf = new TGHorizontalFrame(frmMain);

  const TGFont *font = gClient->GetFont("-*-helvetica-bold-r-normal-*-20-*-*-*-*-*-*-*");
  FontStruct_t buttonFont = font->GetFontStruct();

  gClient->GetColorByName("red", buttonRedColor);
  gClient->GetColorByName("blue", buttonBlueColor);

  bisc = new TGTextButton(frmMain, sv_canv);
  bisc->SetTextColor(buttonBlueColor);
  bisc->SetFont(buttonFont);
  bisc->Connect("Clicked()", "TVSDReader", this, "SaveCanvas()");

  frmMain->AddFrame(bisc, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY , 1,1,1,1)); 

  fName1 = new TGTextEntry(frmMain,f_name);
  fName1->Connect("TextChanged(char*)", "TVSDReader", this, "SetFileName()");

  frmMain->AddFrame(fName1, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY, 1,1,1,1));

  bisc = new TGTextButton(frmMain,"");
  frmMain->AddFrame(bisc, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY , 1,1,1,1));

  frmMain->MapSubwindows();
  frmMain->Resize();
  frmMain->MapWindow();

  frmMain = new TGMainFrame(gClient->GetRoot(), 1000, 600, kHorizontalFrame);
  frmMain->SetWindowName("XX GUI");
  frmMain->SetCleanup(kDeepCleanup);

  bi = new TGTextButton(frmMain,read_inst);
  bi->SetTextColor(buttonBlueColor);
  bi->SetFont(buttonFont);
  bi->Connect("Clicked()", "TVSDReader", this, "Instructions()");

  frmMain->AddFrame(bi, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY , 1, 1, 1, 1));

  bii = new TGTextButton(frmMain,reset_exe);
  bii->SetTextColor(buttonBlueColor);
  bii->SetFont(buttonFont);
  bii->Connect("Clicked()", "TVSDReader", this, "ResetExercise()");
   
  frmMain->AddFrame(bii, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY , 1, 1, 1, 1));

  b = new TGTextButton(frmMain,s_exit);
  b->SetTextColor(buttonRedColor);
  b->SetFont(buttonFont);
  b->Connect("Clicked()", "TVSDReader", this, "CloseWin()");

  frmMain->AddFrame(b, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY , 1, 1, 1, 1));

  frmMain->MapSubwindows();
  frmMain->Resize();
  frmMain->MapWindow();

  browser->StopEmbedding(" ");
  
  // Open the tab for the variables
  VarPad();

}

/* TB test */

void TVSDReader::CloseWin()
{
	 gEve->GetBrowser()->GetMainFrame()->UnmapWindow();
	//gEve->GetBrowser()->CloseWindow();
}

bool TVSDReader::OpenTab( TList* tabs, const char* str )
{
  TIter next(tabs);
  
  TGFrameElement* frame;
  TGTabElement* tab;
  
  while ((frame = (TGFrameElement*) next())) {
    
    TString tname = ((TGTabElement *)(frame->fFrame))->GetString();
    
    if ( 0 == tname.CompareTo( str ) ) return true;
  }
  
  return false;
}


void TVSDReader::VarPad() 
{
  TEveBrowser* browser = gEve->GetBrowser();
 
  if ( !fPad )
  {
    browser->StartEmbedding(TRootBrowser::kRight);
    
    fPad = new TCanvas("fPad","");
    fPad->Divide(2, 2);
    
    browser->StopEmbedding("Invariant Mass Distribution");
  }
  else 
  {
    if ( !OpenTab( browser->GetTabRight()->GetList(), "Invariant Mass Distribution" ) )
    {
      // void pointer 
      fPad = 0;
      VarPad();
    }
  } 
  
  browser->GetTabRight()->SetTab("Invariant Mass Distribution");
  fPad->cd(1);
}




void TVSDReader::TrendPad()
{
  TEveBrowser* browser = gEve->GetBrowser();
 
  // create new tab and canvas
  if ( !fTrendPad )
  {    
    browser->StartEmbedding(TRootBrowser::kRight);
    
    fTrendPad = new TCanvas("fTrendPad","");
    fTrendPad->Divide(2, 2);
    fTrendPad->cd(1);
    
    browser->StopEmbedding("Lifetime trend");
 
    fTrendPadNum = 1;
    fTrendPadMap.clear();
  }
  else 
  {
    if ( !OpenTab( browser->GetTabRight()->GetList(), "Lifetime trend" ) )
    {
      // void pointer 
      fTrendPad = 0;
      TrendPad();
    }
  } 

  browser->GetTabRight()->SetTab( "Lifetime trend" );
  fTrendPad->cd(1);
}

void TVSDReader::FitPad()
{
  TEveBrowser* browser = gEve->GetBrowser();
  
  if ( !fFitPad )
  {
    browser->StartEmbedding(TRootBrowser::kRight);
    
    fFitPad = new TCanvas("fFitPad","");
    fFitPad->Divide(2, 2);
    fFitPad->cd(1);
    
    browser->StopEmbedding("Lifetime fit");    
  }
  else 
  {
    if ( !OpenTab( browser->GetTabRight()->GetList(), "Lifetime fit" ) )
    {
      // void pointer 
      fFitPad = 0;
      FitPad();
    }
  } 
  
  browser->GetTabRight()->SetTab( "Lifetime fit" );
  fFitPad->cd(1);
}
void TVSDReader::setLang1(Int_t lang){lang1=lang;}
	void TVSDReader::FR(){
   var_ranges="Intrevalles des variables";
   an_tools="Outils d'analyses";
   tools="Outils";
   bg_sub="Soustraction du bruit de fond";
   t_fit="Ajustement du temps";
   save_res="Sauvegarde des resultats";
   plt_mass="Tracer la masse du D0";
   plt_distr="Tracer les distributions";
   //fit_sign="Ajuster le temps de desintegration du signal";
   f_name="Nom du fichier";
   s_exit="Quitter";
   fit_mass_dis="Ajuster la distribution de masse";
   reset_exe="Redemarrer l'exercice";
   read_inst="Lire les instructions";
   sv_canv="Enregistrer le canevas";
   //cl_trend="Effacer la tendance";
   //pl_trend="Tracer la tendance";
   //sv_res_fit="Enregistrer les resultats et ajuster";
   fit_sign="Ajust. le tps de desint. du sig.";
    cl_trend="Effacer";
    pl_trend="Trac. la tend.";
    sv_res_fit="Enregistrer et ajuster";

   i1="Le domaine de masse pour le signal doit etre different du domaine de masse total.\n" 
	   "Le domaine de masse pour le bruit de fond doit toujours contenir au moins une region en\n" 
	   "dehors du domaine de masse du signal afin d'avoir des evenements de pur bruit de fond 'a soustraire.\n";
   i2="Vous devez sauvez au moins un des resultats de l'ajustement du temps de vie avant d'afficher la tendance.";
   i3="Vous devez ajuster la distribution du temps de vie avant d'essayer d'enregistrer les resultats de l'ajustement.";
   i4="ATTENTION: les coupures maximales et minimales changent en meme temps";
   i5="La distribution en masse doit etre ajustee avant d'afficher les distributions des variables.\n"
"L'ajustement de la distribution en masse permet d'evaluer le nombre d'evenement de bruit de fond sous\n "
"le signal. Cela permet de savoir combien d'evenements de bruit de fond il \n"
"faut soustraire de la region du signal pour obtenir la distribution du signal.\n";
   i6="Pour plus de details sur l'experience LHCb, vous pouvez vous rendre sur le site:\n"
  "http://lhcb-public.web.cern.ch/lhcb-public/ et http://lhcb.web.cern.ch/lhcb/ \n";
	
	}
	void TVSDReader::DE(){
	   var_ranges="Variablen-Intervall";
   an_tools="Analyse-Werkzeuge";
   tools="Werkzeuge";
   bg_sub="Untergrund-Subtraktion";
   t_fit="Lebenszeit-Fit";
   save_res="Ergebnisse speichern";
   plt_mass="D0-Masse plotten";
   plt_distr="Verteilungen plotten";
   fit_sign=" Signal Zerfallszeit fitten ";
   f_name="Dateiname";
   s_exit="Beenden";
   fit_mass_dis="Massen-Verteilung fitten";
   reset_exe="Aufgaben zuruecksetzen";
   read_inst="Anleitungen lesen";
   sv_canv="Plot speichern";
   cl_trend="Trend entfernen";
   pl_trend="Trend zeichnen";
   sv_res_fit=" Fit-Ergebnis speichern";

	   i1="Du kannst das Signal-Interval nicht gleich dem gesamten Massen-Intervall setzen.\n" 
		   "Das Untergrund-Intervall muss immer einen Bereich enthalten, der nicht im Signal-Interval liegt.\n" 
		   "Nur so bekommst du einige reine Untergrund-Ereignisse die du subtrahieren kannst.\n";
   i2="Du musst mindestens ein Fit-Ergebnis speichern\n befor du einen Trend plotten einzeichnen kannst.";
   i3="Du musst die Lebenszeit zunaechst fitten bevor \n du die Ergebnisse speichern kannst.";
   i4="WARNUNG: Der Maximum-  und Minimum-Schnitt sind beide veraenderlich.";
   i5="Du musst die Massen-Verteilung zunaechst fitten bevor du die Variablen-Verteilungen plottest.\n"
"Der Massen-Fit erlaubt dir die Anzahl der Untergrund-Ereignisse unter dem Signal-Peak zu bestimmen.\n"
"Jetzt weisst du wieviele Untergrund-Ereignisse du im Signal-Intervall abziehen musst, um die Signal-Verteilung zu erhalten.\n";
   i6="Fuer mehr Informationen ueber das LHCb-Experiment,\n besuche die LHCb Webseiten:\n"
  "http://lhcb-public.web.cern.ch/lhcb-public/ und http://lhcb.web.cern.ch/lhcb/";

	
	}
	void TVSDReader::EN(){
	   var_ranges="Variable ranges";
   an_tools="Analysis tools";
   tools="Tools";
   bg_sub="Background subtraction";
   t_fit="Time fit";
   save_res="Save results";
   plt_mass="Plot D0 mass";
   plt_distr="Plot distributions";
   fit_sign="Fit signal decay time";
   f_name="Filename";
   s_exit="Exit";
   fit_mass_dis="Fit mass distribution";
   reset_exe="Reset Exercise";
   read_inst="Read Instructions";
   sv_canv="Save Canvas";
   cl_trend="Clear Trend";
   pl_trend="Plot trend";
   sv_res_fit="Save result and fit";
   i1="You cannot set the signal range to be the same as the total mass range.\n"
"The background range must always contain\nat least some area which is not\n"
"in the signal range, so that you have\nsome pure background events to subtract.\n";
   i2="You must save at least one result of the\nlifetime fit before making the trend plot.";
   i3="You must fit the lifetime distribution before\nattempting to save the results of this fit.";
   i4="WARNING: Max and min cut are both varying";
   i5="You must fit the mass distribution\nbefore plotting the variable distributions.\n"
"The fit to the mass distribution allows\nyou to measure the number of background\n"
"events under the signal peak. This\nin turn means that you know how many background\n"
"events to subtract from the signal region\nto get the signal variable distributions.\n";
   i6="For more details on the LHCb experiment, \n"
"please visit the LHCb pages at: \n"
   "http://lhcb-public.web.cern.ch/lhcb-public/ \n and \n http://lhcb.web.cern.ch/lhcb/";
	}
	void TVSDReader::IT(){
   var_ranges="Intervalli delle variabili";
   an_tools="Strumenti di analisi";
   tools="Strumenti";
   bg_sub="Sottrazione del fondo";
   t_fit="Fit vita media";
   save_res="Salva risultati";
   plt_mass="Grafico massa D0";


   f_name="Nome del file";
   s_exit="Esci";
   fit_mass_dis="Fit distribuzione massa";
   reset_exe="Azzera esercizio";
   read_inst="Istruzioni";
   sv_canv="Salva finestra";

   sv_res_fit="Salva risultati fit";

   cl_trend="Azzera grafico";
   pl_trend="Grafico";
   plt_distr="Grafici distribuzioni";
   fit_sign="Fit tempo decadimento";


   i1="Non e' possibile che l'intervallo del segnale sia uguale a tutto l'intervallo di massa. L'intervallo del fondo deve sempre comprendere una parte al di fuori dell'intervallo del segnale, in modo da avere degli eventi di solo fondo da sottrarre.";
	i2="E' necessario salvare almeno un risultato del fit di vita media prima di fare il plot dell'andamento.";
	i3="E' necessario fare il fit della distribuzione della vita media prima di salvare il risultato.";
	i4="ATTENZIONE: Variano sia il valore minimo che il valore massimo";
	i5="E' necessario fare il fit della distribuzione di massa prima di fare i grafici delle distribuzioni delle variabili. Il fit della distribuzione di massa permette di misurare il numero di eventi di fondo presenti sotto il picco del segnale;  permette quindi di sapere quanti eventi di fondo bisogna sottrarre dalla regione di segnale per avere le distribuzioni delle variabili dei soli eventi di segnale.";
	i6="Potete trovare maggiori dettagli sull'esperimento LHCb alla pagina: http://lhcb-public.web.cern.ch/lhcb-public/ and http://lhcb.web.cern.ch/lhcb/";
	}
	void TVSDReader::RO(){
	
	   var_ranges="Domenii variabile";
   an_tools="Instrumente analiza";
   tools="Instrumente";
   bg_sub="Eliminare fond";
   t_fit="Fit timp de viata";
   save_res="Salvare rezultate";
   plt_mass="Afiseaza masa D0";
   plt_distr="Afiseaza distributii";
   fit_sign="Fit timp viata semnal";
   f_name="Nume fisier";
   s_exit="Iesire";
   fit_mass_dis="Fit distributie masa";
   reset_exe="Resetare exercitiu";
   read_inst="Citeste instructiuni";
   sv_canv="Salveaza grafice";
   cl_trend="Reset tendinta";
   pl_trend="Afiseaza tendinta";
   sv_res_fit="Salvare rezultat si fit";
   i1="Nu puteti stabili un domeniu de semnal\n egal cu intregul spectru de masa. \n"
"Domeniul evenimentelor de fond trebuie\n sa cuprinda si cel putin o zona care \n"
"nu face parte din domeniul de semnal, \nastfel incat sa existe evenimente exclusiv \n"
"de fond ce pot fi extrase din zona\n de semnal. \n";
   i2="Trebuie sa salvati cel putin un rezultat al fit-ului \n timpului de viata, inainte de a face afisa tendinta masuratorii.";
   i3="Trebuie sa fitati distributia timpului de viata inainte \n de a incerca sa salvati rezultatele acestui fit.";
   i4="ATENTIE: Si maximul si minimul domeniului de selectie pot fi variate.";
   i5="Trebuie sa fitati distributia de masa inainte\n de reprezentarea grafica a distributiilor \n"
"variabilelor. Fit-ul distributiei de masa va\n permite sa masurati numarul de evenimente \n"
"de fond aflate sub varful (peak-ul) de semnal.\n Aceasta inseamna ca veti stii cate \n"
"evenimente de semnal sa extrageti din \n regiunea de semnal pentru a obtine \n"
"distributiile variabilelor pentru semnal. \n";
   i6="Pentru mai multe detalii despre experimentul LHCb, \n"
	  "va rugam sa vizitati pagina web la adresa: http://lhcb-public.web.cern.ch/lhcb-public/ and http://lhcb.web.cern.ch/lhcb/ ";
	}


TVSDReader::~TVSDReader()
{
  // Destructor.
	
  delete fVSD;
  delete fEvDirKeys;
  
  fFile->Close();
  delete fFile;
}

TVSDReader* gVSDReader = 0;


// Forward declaration.
//void make_gui(Int_t mode);

//______________________________________________________________________________
//void LHCb_D0_Exercise(Int_t choice = 2, Int_t mode = 2, Int_t dataset = 1, TString name1 = "", TString name2 = "")

void LHCb_D0_Exercise(Int_t lang, TString pathSave2, Int_t choice, Int_t mode, Int_t dataset, TString name1, TString name2)
{
  std::string vsd_file_name;

  {
    // check if we have a local data file
    std::ifstream ifs("share/LHCbMasterclass/MasterclassData_2012.root");
    if (!ifs.fail())
      // we do
      vsd_file_name = "share/LHCbMasterclass/MasterclassData_2012.root";
    else
      // we don't
      vsd_file_name = DATA_DIR "/MasterclassData_2012.root";
  }

  globalName1 = name1;
  globalName2 = name2;

  globalChoice = choice;
  globalMode = mode;
  globalDataset = dataset;
  pathSaveD0= pathSave2;

  // Main function, initializes the application.
  //
  // 1. Load the auto-generated library holding ESD classes and ESD dictionaries.
  // 2. Open ESD data-files.
  // 3. Load cartoon geometry.
  // 4. Spawn simple GUI.
  // 5. Load first event.

  TFile::SetCacheFileDir(".");
  TEveVSD::DisableTObjectStreamersForVSDStruct();

  gVSDReader = new TVSDReader(vsd_file_name.c_str());
  gVSDReader->setLang1(lang);
	switch (lang)
	{
	case 2:
		gVSDReader->FR();
		break;
	case 3:
		gVSDReader->DE();
		break;
	case 4:
		gVSDReader->IT();
		break;
	case 5:
		gVSDReader->RO();
		break;
	default:
		gVSDReader->EN();
		break;
	}
  TEveManager::Create(kTRUE,"FV");
  // Final stuff
  //=============

  gEve->GetViewers()->SwitchColorSet();
  gEve->GetDefaultGLViewer()->SetStyle(TGLRnrCtx::kOutline);
  //   make_gui(mode);

  TEveBrowser* browser = gEve->GetBrowser();

  browser->CloseTab(0);

  Int_t lhcbFont = 42;
  // line thickness
  Double_t lhcbWidth = 1.5;

  gStyle->SetFrameBorderMode(0);
  gStyle->SetStatColor(0);
  gStyle->SetPalette(1);
  gStyle->SetTitleColor(1);
  gStyle->SetFillColor(1);
  gStyle->SetLegendBorderSize(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetPadColor(0);
  gStyle->SetCanvasColor(0);

  // use large fonts
  gStyle->SetTextFont(lhcbFont);
  gStyle->SetTextSize(0.08f);
  gStyle->SetLabelFont(lhcbFont,"x");
  gStyle->SetLabelFont(lhcbFont,"y");
  gStyle->SetLabelFont(lhcbFont,"z");
  gStyle->SetLabelSize(0.0425f,"x");
  gStyle->SetLabelSize(0.0425f,"y");
  gStyle->SetLabelSize(0.0425f,"z");
  gStyle->SetTitleFont(lhcbFont);
  gStyle->SetTitleFont(lhcbFont,"x");
  gStyle->SetTitleFont(lhcbFont,"y");
  gStyle->SetTitleFont(lhcbFont,"z");
  gStyle->SetTitleSize(0.0425f,"x");
  gStyle->SetTitleSize(0.0425f,"y");
  gStyle->SetTitleSize(0.0425f,"z");
  gStyle->SetTitleOffset(1.2f,"x");
  gStyle->SetTitleOffset(1.5f,"y");
  gStyle->SetTitleOffset(1.2f,"z");

  gStyle->SetLabelOffset(0.015f);

  // look of the statistics box:
  gStyle->SetStatBorderSize(1);
  gStyle->SetStatFont(lhcbFont);
  gStyle->SetStatFontSize(0.05f);
  gStyle->SetStatX(0.9f);
  gStyle->SetStatY(0.4f);
  gStyle->SetStatW(0.25f);
  gStyle->SetStatH(0.15f);
  // put tick marks on top and RHS of plots
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPadBottomMargin(0.15f);
  gStyle->SetPadLeftMargin(0.12f);

  // histogram divisions: only 5 in x to avoid label overlaps
  gStyle->SetNdivisions(505,"x");
  gStyle->SetNdivisions(505,"y");
  gStyle->SetHatchesSpacing(1.);
  gStyle->SetHatchesLineWidth(5.0f);

  // use bold lines and markers
  gStyle->SetLineWidth(lhcbWidth);
  gStyle->SetFrameLineWidth(lhcbWidth);
  gStyle->SetHistLineWidth(lhcbWidth);
  gStyle->SetFuncWidth(lhcbWidth);
  gStyle->SetGridWidth(lhcbWidth);
  gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
  gStyle->SetMarkerStyle(24);
  gStyle->SetMarkerSize(0.5);

  gStyle->SetLineWidth(2);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  gStyle->SetCanvasColor(0);
  gStyle->SetPalette(1);

  gVSDReader->ToStudent();
  gEve->GetWindowManager()->HideAllEveDecorations();
  gEve->Redraw3D(kTRUE); // Reset camera after the first event has been shown.
  browser->GetMainFrame()->MoveResize(5, 30, gClient->GetDisplayWidth()-350, gClient->GetDisplayHeight()-200);

}

