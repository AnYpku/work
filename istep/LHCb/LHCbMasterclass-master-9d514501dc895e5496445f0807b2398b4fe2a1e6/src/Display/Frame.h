/*
 * Frame.h
 *
 *  Created on: 2 Aug 2013
 *      Author: Ana Trisovic
 */

#ifndef FRAME_H_
#define FRAME_H_

#include <TTree.h>
#include <TEveManager.h>
#include <TEveLine.h>
#include <TGTextEntry.h>
#include <TApplication.h>
#include <TCanvas.h>
#include <TEveBrowser.h>
#include <TEveViewer.h>
#include <TEveGeoNode.h>
#include <TEveManager.h>
#include <TEveLine.h>
#include <TGButton.h>
#include <TGDoubleSlider.h>
#include <TGeoManager.h>
#include <TEveGValuators.h>
#include <TGLClip.h>
#include <TGLUtil.h>
#include <TGLViewer.h>
#include <TPointsArray3D.h>
#include <TSystem.h>
#include <TRandom.h>
#include <map>
#include "LbMclassTrack.h"
#include <TEveLine.h>
#include <TGListBox.h>
#include <TH1F.h>
#include <TGComboBox.h>
#include <TGIcon.h>
#include <TImage.h>
#include <math.h>
#include "launcher.h"

class Frame {
	public:
		Frame();
		Frame(const int lang, const char* user, Int_t h, launcher *lstart);
		virtual ~Frame();
		void makeGui();	

		//event managment 
		/***
		** init - initial reading
		** readTracks - reads event using counter 
		**/
		void init();
		void Next();
		void Back();
		void Clear();
		void readTracks();

		//view options
		void Zoom();
		void DefaultCam();

		void GeometrySwitch();
		void HideGeometry();
		void ShowGeometry();
		void ShowTransparency();
		void TransparencySwitch();
		
		 //start
		 void disableAll();
		 void enableAll();
		
		void OnClicked(TObject *obj);
		void SaveParticle();
		void DeleteParticle();
		void Reset();
		void Calculate();
		void Continue();
		void Draw();
		void Help();
		void Exit();
		void SaveHist();
		void Validate(Int_t h);
		//void readSpecialTracks();
		//static bool compare_2(TEveLine i, TEveLine j);
		
		//static bool compare_3(int a, int b){return a<b;}
		void Hint();
		void YZ();
		void YX();
		void ZX();
		void rotate(double hor, double ver);


		void EN();
		void RO();
		void IT();
		void DE();
		void FR();

	private:
		int counter; //currnet number of event
		Int_t nb; //total number of events
		Bool_t eventsDone[50]; //checks if that event is solved
		//TEveElementList* list;
		TEveLine* linexx;
		TEveGeoTopNode* tn; //LHCb geometry
		int checked; //show hide geometry
		TRandom r;
		int pom;
		const char *user1;
		int lang1;
		TString fileName; // root file name - tracks and particles 
		TString histName;
		TObjArray *array;
		const double PI;  
		std::map <float, LbMclassTrack> particles;
		LbMclassTrack selected; //current selected particle 
		int particleCount;
		
		launcher *l_start;
		//std::map <TEveLine, LbMclassTrack> particles;

		TGComboBox *fComboBox1325; //file chooser
		//LbMclassTrack* particles;
		TGTextButton *fTextButton758; ///save histogram
		TGTextEntry *fTextEntry1305;
		TGTextEntry *fTextEntry1306;
		TGTextEntry *fTextEntry1307;
		TGTextEntry *fTextEntry1308;
		TGTextEntry *fTextEntry1309;
		TGTextEntry *fTextEntry1311;
		TGTextEntry *fTextEntry1312;
		TGTextEntry *fTextEntry799;
		TGTextButton *fTextButton1353; //validate button
		 TGTextButton *fTextButton1606;
		 TGTextButton *fTextButton1442;
		 TGTextButton *fTextButton753a; //add on histogram
		 TGTextButton *fTextButton759; //help button
		 TGTextButton *fTextButton834; //exit button
		 
		 TGIcon *leg; //icon legend particles - colors 
		 TGGroupFrame *fGroupFrame748; //group box for legend

		 //enable / disable start
		TGPictureButton *fPictureButton710;
		TGPictureButton *fPictureButton711; 
		TGPictureButton *fPictureButton1723;
		TGCheckButton *fCheckButton712;
		TGCheckButton *fCheckButton713;
		TGPictureButton *fPictureButton716;
		TGPictureButton *fPictureButton715;
		TGPictureButton *fPictureButton861;
		TGPictureButton *fPictureButton862;
		TGPictureButton *fPictureButton863;

		//group box
		 TGGroupFrame *fGroupFrame735;
		 TGGroupFrame *fGroupFrame717;
		 TGGroupFrame *fGroupFrame860;
		 TGGroupFrame *fGroupFrame714;
		 TGGroupFrame *fGroupFrame709;
		 TGGroupFrame *fGroupFrame1395;
		 TGGroupFrame *fGroupFrame1558;
		 TGGroupFrame *fGroupFrame558;

		 //resize
		 UInt_t mainFrameWidth;
		 UInt_t mainFrameHeight;
		 TGMainFrame *fMainFrame1460;

		 //labele
		TGLabel *fLabel842;
		TGLabel *fLabel726; 
		TGLabel *fLabel743; 
		TGLabel *fLabel733;

		TGLabel *fLabel1351;
		//my particles
		TGListBox *fListBox1321;
		LbMclassTrack myParticle1;
		LbMclassTrack myParticle2;
		TGTextButton *fTextButton753; //delete
		TGTextButton *fTextButton1338;
		int flag;
		float res; //new mass
		int tabNum;
		int zoomBool; //zoom dialog should be shown just ones
		TH1F* a;
		int his;
		Double_t center[3];
		//calculate
		TGTextEntry *fTextEntry1337;
		TGTextButton *fTextButton1335;
		TGTextButton *fTextButton1319;
	  TCanvas* fHistCanvas;
	  
	  TString e1;
	  TString e2;
	  TString h1;
	  TString e3;
	  TString e4;
	  TString h2;
	  TString h3_a;
	  TString h3_b;

	  // Flag to know whether transparency was already checked
	  int checked_trans;
	  // Vector with initial transparency values per volume
	   std::vector< std::pair< TGeoVolume*, UInt_t > > fVolumeTrans;
	  
	public:
		TTree *tree;
		TString event;
	
};

#endif /* FRAME_H_ */
