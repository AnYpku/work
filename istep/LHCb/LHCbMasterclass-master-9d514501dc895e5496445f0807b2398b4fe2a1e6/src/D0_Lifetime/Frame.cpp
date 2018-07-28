/*
 * Frame.cpp
 *
 *  Created on: 2 Aug 2013
 *      Author: Ana Trisovic <ana.trisovic@cern.ch>
 */
 
#pragma warning(disable: 4244 4800 )
#include "Frame.h"

#include <TGLViewer.h>
#include <TEveBrowser.h>
#include <TSystem.h>
#include <iostream>

#include <TEveManager.h>
#include <TEveViewer.h>
#include <TEveEventManager.h>
#include <TEveLine.h>

#include <TRandom.h>
#include <TSystem.h>
#include <TFile.h>
#include <TStyle.h>
#include <TTree.h>
#include <TPointsArray3D.h>

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
#include <TGLabel.h>
#include <TFile.h>
#include <TKey.h>
#include <TPointsArray3D.h>
#include <TSystem.h>
#include <TEveTrack.h>
#include <TPaveText.h>
#include <TGButtonGroup.h>
#include <TH1F.h>

#include "LbMclassTrack.h"
#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGFontDialog
#include "TGFontDialog.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#include <TImage.h>
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGMsgBox
#include "TGMsgBox.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif
#ifndef ROOT_TGObject
#include "TGObject.h"
#endif
//
#include "Riostream.h"
#include "TRandom.h"
#include "TEveSceneInfo.h"
#include <map>
#include <TEveScene.h>
#include <TEveGeoShape.h>
#include <TEveProjectionManager.h>
#include <TEveProjectionAxes.h>
#include <math.h>

#include "launcher.h"

//POPup menu for saving histogram
TString pathSave;
/*TGTextButton *fTextButton947;
TGTextEntry *fTextEntry994;
TGMainFrame *fMainFrame1599;*/


Frame::Frame(const int lang, const char* user, TString pathSave2, Int_t h, launcher *lstart): fHistCanvas( 0 ), PI(3.141592653589793238462) {
    TEveManager::Create();
	user1=Form("%s",user);
	makeGui();
	init();

	//camera settings
	pathSave=pathSave2;
    TGLViewer *v = gEve->GetDefaultGLViewer();

    v->ColorSet().Background().SetColor(kWhite); //background color
	ShowGeometry();
	ShowTransparency();
	
	l_start=lstart;
	//CAMERA SETTINGS
	DefaultCam();

	disableAll();
	lang1=lang;
	switch (lang)
	{
	case 2:
		FR();
		break;
	case 3:
		DE();
		break;
	case 4:
		IT();
		break;
	case 5:
		RO();
		break;
	default:
		break;
	}
	Validate(h);
}

void Frame:: init(){
	counter=0;
	checked=0;
	particleCount=0;
	flag=0; //delete particles
	tabNum=1;
	his=0;
	zoomBool=kTRUE;
	popUpOkNum=1;
	checked_trans = 0;
	for (int i=0; i<50; i++){eventsDone[i]=kFALSE;}
	//a=new TH1F(Form("hist %d",tabNum),Form("My histogram %d",tabNum), 50, 1815, 1930);
	a=new TH1F("hist","My histogram", 50, 1815, 1915); //

	e1="You cannot have more than two particles.";
	e2="You have already added this particle.";
	h1="You have successfully saved your histogram.";
	h2="When you want to rotate the view, press CTRL or CTRL + SHIFT to be more precise.";
	e3="Mass is not in range. Please, try again.";
	e4="You have already added new mass in histogram.";
	h3_a="Congratulations!";
	h3_b="You have successfully completed MasterClassDisplay exercise.";
}
void Frame::Reset(){
	//my particles reset
	flag=0;
	particleCount=0;
	fListBox1321->RemoveEntries(0,1);
	fTextEntry1305->SetText("");
	fTextEntry1306->SetText("");
	fTextEntry1307->SetText("");
	fTextEntry1308->SetText("");
	fTextEntry1309->SetText("");
	fTextEntry1311->SetText("");
	fTextEntry1312->SetText("");
	fTextEntry799->SetText("");
	fTextButton1319->SetEnabled(kFALSE);
	fTextButton1335->SetEnabled(kFALSE);
	fTextButton753->SetEnabled(kFALSE);
	fTextButton753a->SetEnabled(kFALSE);
	fTextEntry1337->SetText("");

	TGPicture *fRightIconPicture = (TGPicture *)gClient->GetPicture("Icons/leg1.png");
	gClient->FreePicture(fRightIconPicture);
	fRightIconPicture = (TGPicture *)gClient->GetPicture("Icons/leg1.png");
	leg->SetPicture(fRightIconPicture);

}
void Frame::Next() {
	counter++;
	if (counter<nb) 
	{
		particles.clear();
		Clear();
		readTracks(); 
		Reset();
	    fLabel1351->SetText(Form("%d",counter+1));
	}
	else new TGMsgBox(gClient->GetRoot(), 0,  h3_a, h3_b,0);
}
void Frame::Back() {
	counter--;
	
	if (counter>=0) 
	{
		particles.clear();
		Clear();
		readTracks();
	}
	else counter=0;
	Reset();
	fLabel1351->SetText(Form("%d",counter+1));
}
void Frame::disableAll(){
	fPictureButton710->SetEnabled(kFALSE);
	fPictureButton711->SetEnabled(kFALSE);
	fPictureButton1723->SetEnabled(kFALSE);
	fCheckButton712->SetEnabled(kFALSE);
	fCheckButton713->SetEnabled(kFALSE);
	fPictureButton716->SetEnabled(kFALSE);
	fPictureButton715->SetEnabled(kFALSE);
	fPictureButton861->SetEnabled(kFALSE);
	fPictureButton862->SetEnabled(kFALSE);
	fPictureButton863->SetEnabled(kFALSE);
}
void Frame::enableAll(){
	fPictureButton710->SetEnabled(kTRUE);
	fPictureButton711->SetEnabled(kTRUE);
	fPictureButton1723->SetEnabled(kTRUE);
	fCheckButton712->SetEnabled(kTRUE);
	fCheckButton713->SetEnabled(kTRUE);
	fPictureButton716->SetEnabled(kTRUE);
	fPictureButton715->SetEnabled(kTRUE);
	fPictureButton861->SetEnabled(kTRUE);
	fPictureButton862->SetEnabled(kTRUE);
	fPictureButton863->SetEnabled(kTRUE);
}
void Frame::makeGui() {
	TEveBrowser* browser = gEve->GetBrowser();
	mainFrameWidth=gClient->GetDisplayWidth()*0.9;
	mainFrameHeight= gClient->GetDisplayHeight()*0.9;
	browser->StartEmbedding(TRootBrowser::kLeft);
	browser->GetMainFrame()->MoveResize(5, 30, mainFrameWidth, mainFrameHeight);
	browser->SetMWMHints(kMWMDecorBorder|kMWMDecorTitle,kMWMFuncResize|kMWMFuncMove, 0);
	browser->SetTabTitle("Event Control", 0);
	 //tab 
   TGTab *left = gEve->GetBrowser()->GetTabLeft();
   TGFrame *parent = (TGFrame *)left->GetParent();
   parent->Resize(parent->GetDefaultWidth()*1.2, parent->GetDefaultHeight());

   gEve->GetDefaultGLViewer()->RefreshPadEditor();
   
    //Hide tabs
   if(browser->GetTabLeft()->GetTabTab(0))
    browser->GetTabLeft()->RemoveTab(0);

	if(browser->GetTabLeft()->GetTabTab(0))
    browser->GetTabLeft()->RemoveTab(0);

	if(browser->GetTabBottom()->GetTabTab(0))
	browser->GetTabBottom()->RemoveTab(0);

	//made using TGuiBuilder
	// main frame
   fMainFrame1460 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   fMainFrame1460->SetLayoutBroken(kTRUE);

   // composite frame
   TGCompositeFrame *fMainFrame1181 = new TGCompositeFrame(fMainFrame1460,490,933,kVerticalFrame);
   fMainFrame1181->SetLayoutBroken(kTRUE);

   // composite framesto
   TGCompositeFrame *fCompositeFrame1182 = new TGCompositeFrame(fMainFrame1181,296,816,kVerticalFrame);
   fCompositeFrame1182->SetLayoutBroken(kTRUE);

   // canvas widget
   TGCanvas *fCanvas1183 = new TGCanvas(fCompositeFrame1182,280,1150,kDoubleBorder);

   // canvas viewport
   TGViewPort *fViewPort1184 = fCanvas1183->GetViewPort();

   // composite frame
   TGCompositeFrame *fCompositeFrame1193 = new TGCompositeFrame(fViewPort1184,260,1010,kHorizontalFrame | kOwnBackground);
   fCompositeFrame1193->SetLayoutManager(new TGTileLayout(fCompositeFrame1193,8));

   // composite frame
   TGCompositeFrame *fCompositeFrame708 = new TGCompositeFrame(fCompositeFrame1193,240,1010,kVerticalFrame);
   fCompositeFrame708->SetLayoutBroken(kTRUE);



    // "Event manager" group frame
   fGroupFrame714 = new TGGroupFrame(fCompositeFrame708,"Event manager");
   fGroupFrame714->SetLayoutBroken(kTRUE);
   fPictureButton716 = new TGPictureButton(fGroupFrame714,gClient->GetPicture("Icons/GoBack.png"));

   fPictureButton716->Connect("Clicked()", "Frame", this, "Back()");
   fGroupFrame714->AddFrame(fPictureButton716, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fPictureButton716->MoveResize(8,48,96,40); 
   fLabel842 = new TGLabel(fGroupFrame714,"Event number:");
   fLabel842->SetTextJustify(36);
   fLabel842->SetMargins(0,0,0,0);
   fLabel842->SetWrapLength(-1);
   fGroupFrame714->AddFrame(fLabel842, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel842->MoveResize(8,24,112,18);

   TGFont *ufont;         // will reflect user font changes
   ufont = gClient->GetFont("-*-System-bold-r-*-*-12-*-*-*-*-*-*-*");

   TGGC   *uGC;           // will reflect user GC changes
   // graphics context changes
   GCValues_t vall1351;
   vall1351.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",vall1351.fForeground);
   gClient->GetColorByName("#c0c0c0",vall1351.fBackground);
   vall1351.fFillStyle = kFillSolid;
   vall1351.fFont = ufont->GetFontHandle();
   vall1351.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&vall1351, kTRUE);
   fLabel1351 = new TGLabel(fGroupFrame714,"1",uGC->GetGC(),ufont->GetFontStruct());
   fLabel1351->SetTextJustify(36);
   fLabel1351->SetMargins(0,0,0,0);
   fLabel1351->SetWrapLength(-1);
   fGroupFrame714->AddFrame(fLabel1351, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1351->MoveResize(128,24,64,18);
   fPictureButton715 = new TGPictureButton(fGroupFrame714,gClient->GetPicture("Icons/GoForward.png"));
   fPictureButton715->Connect("Pressed()", "Frame", this, "Next()");
   fGroupFrame714->AddFrame(fPictureButton715, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fPictureButton715->MoveResize(120,48,96,40);

   fGroupFrame714->SetLayoutManager(new TGVerticalLayout(fGroupFrame714));
   fGroupFrame714->Resize(224,104);
   fCompositeFrame708->AddFrame(fGroupFrame714, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fGroupFrame714->MoveResize(8,0,224,104); //MoveResize(8,8,224,104); //MoveResize(8,96,224,104); //MoveResize(8,224,224,104);


      // "View" group frame
   fGroupFrame709 = new TGGroupFrame(fCompositeFrame708,"View");
   fGroupFrame709->SetLayoutBroken(kTRUE);
   fPictureButton710 = new TGPictureButton(fGroupFrame709,gClient->GetPicture("Icons/Zoom.png"));
   fPictureButton710->Connect("Clicked()", "Frame", this, "Zoom()");
   fGroupFrame709->AddFrame(fPictureButton710, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fPictureButton710->MoveResize(8,24,96,40);
   fPictureButton711 = new TGPictureButton(fGroupFrame709,gClient->GetPicture("Icons/fullscreen.png"));
   fPictureButton711->Connect("Clicked()", "Frame", this, " DefaultCam()");
   fGroupFrame709->AddFrame(fPictureButton711, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fPictureButton711->MoveResize(120,24,96,40); //->
   fPictureButton1723 = new TGPictureButton(fGroupFrame709,gClient->GetPicture("Icons/hint.png"));
   fPictureButton1723->Connect("Clicked()", "Frame", this, "Hint()");
   fGroupFrame709->AddFrame(fPictureButton1723, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fPictureButton1723->MoveResize(168,96,48,40); //MoveResize(152,24,64,40); //MoveResize(152,72,64,40); //

   fCheckButton712 = new TGCheckButton(fGroupFrame709,"Hide Geometry");
   fCheckButton712->Connect("Clicked()", "Frame", this, "GeometrySwitch()"); 
   fCheckButton712->SetTextJustify(36);
   fCheckButton712->SetMargins(0,0,0,0);
   fCheckButton712->SetWrapLength(-1);
   fGroupFrame709->AddFrame(fCheckButton712, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fCheckButton712->MoveResize(16,72,144,19);

   fCheckButton713 = new TGCheckButton(fGroupFrame709,"Transparency");
   fCheckButton713->Connect("Clicked()", "Frame", this, "TransparencySwitch()"); 
   fCheckButton713->SetTextJustify(36);
   fCheckButton713->SetMargins(0,0,0,0);
   fCheckButton713->SetWrapLength(-1);
   fGroupFrame709->AddFrame(fCheckButton713, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fCheckButton713->MoveResize(16,88,144,19);

   fTextButton759 = new TGTextButton(fGroupFrame709,"Help");
   fTextButton759->Connect("Clicked()", "Frame", this, "Help()");
   fTextButton759->SetTextJustify(36);
   fTextButton759->SetMargins(0,0,0,0);
   fTextButton759->SetWrapLength(-1);
   fTextButton759->Resize(144,24);
   fGroupFrame709->AddFrame(fTextButton759, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton759->MoveResize(16,112,144,24); //MoveResize(8,56,104,24);

   fGroupFrame709->SetLayoutManager(new TGVerticalLayout(fGroupFrame709));
   fGroupFrame709->Resize(224,152); //Resize(224,131);
   fCompositeFrame708->AddFrame(fGroupFrame709, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fGroupFrame709->MoveResize(8,104,224,152); //MoveResize(8,200,224,131); //MoveResize(8,96,224,131);

   
     // "Zoom" group frame
   fGroupFrame860 = new TGGroupFrame(fCompositeFrame708,"Zoom");
   fGroupFrame860->SetLayoutBroken(kTRUE);
   fPictureButton861 = new TGPictureButton(fGroupFrame860,gClient->GetPicture("Icons/a.png"));
   fPictureButton861->Connect("Pressed()", "Frame", this, "YZ()");
   fGroupFrame860->AddFrame(fPictureButton861, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fPictureButton861->MoveResize(8,24,64,40);
   fPictureButton862 = new TGPictureButton(fGroupFrame860,gClient->GetPicture("Icons/b.png"));
   fPictureButton862->Connect("Pressed()", "Frame", this, "YX()");
   fGroupFrame860->AddFrame(fPictureButton862, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fPictureButton862->MoveResize(80,24,64,40);
   fPictureButton863 = new TGPictureButton(fGroupFrame860,gClient->GetPicture("Icons/c.png"));
   fPictureButton863->Connect("Pressed()", "Frame", this, "ZX()");
   fGroupFrame860->AddFrame(fPictureButton863, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fPictureButton863->MoveResize(152,24,64,40); //MoveResize(152,24,64,40);

   fGroupFrame860->SetLayoutManager(new TGVerticalLayout(fGroupFrame860));
   fGroupFrame860->Resize(224,104); //Resize(224,80);
   fCompositeFrame708->AddFrame(fGroupFrame860, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fGroupFrame860->MoveResize(8,256,224,80);

   // "Particle Info" group frame
   fGroupFrame717 = new TGGroupFrame(fCompositeFrame708,"Particle Info");
   fGroupFrame717->SetLayoutBroken(kTRUE);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry718;
   valEntry718.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry718.fForeground);
   gClient->GetColorByName("#e0e0e0",valEntry718.fBackground);
   valEntry718.fFillStyle = kFillSolid;
   valEntry718.fFont = ufont->GetFontHandle();
   valEntry718.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry718, kTRUE);

    fTextEntry1305 = new TGTextEntry(fGroupFrame717, new TGTextBuffer(15),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kDoubleBorder | kOwnBackground);
   fTextEntry1305->SetMaxLength(4096);
   fTextEntry1305->SetAlignment(kTextLeft);
   fTextEntry1305->SetText("");
   fTextEntry1305->Resize(80,fTextEntry1305->GetDefaultHeight());
   fGroupFrame717->AddFrame(fTextEntry1305, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1305->MoveResize(72,48,80,22);
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

      // graphics context changes
   GCValues_t valEntry719;
   valEntry719.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry719.fForeground);
   gClient->GetColorByName("#e0e0e0",valEntry719.fBackground);
   valEntry719.fFillStyle = kFillSolid;
   valEntry719.fFont = ufont->GetFontHandle();
   valEntry719.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry719, kTRUE);

   fTextEntry1306 = new TGTextEntry(fGroupFrame717, new TGTextBuffer(15),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kDoubleBorder | kOwnBackground);
   fTextEntry1306->SetMaxLength(4096);
   fTextEntry1306->SetAlignment(kTextLeft);
   fTextEntry1306->SetText("");
   fTextEntry1306->Resize(80,fTextEntry1306->GetDefaultHeight());
   fGroupFrame717->AddFrame(fTextEntry1306, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1306->MoveResize(72,96,80,22);
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

     // graphics context changes
   GCValues_t valEntry720;
   valEntry720.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry720.fForeground);
   gClient->GetColorByName("#e0e0e0",valEntry720.fBackground);
   valEntry720.fFillStyle = kFillSolid;
   valEntry720.fFont = ufont->GetFontHandle();
   valEntry720.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry720, kTRUE);
  
   fTextEntry1307 = new TGTextEntry(fGroupFrame717, new TGTextBuffer(15),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kDoubleBorder | kOwnBackground);
   fTextEntry1307->SetMaxLength(4096);
   fTextEntry1307->SetAlignment(kTextLeft);
   fTextEntry1307->SetText("");
   fTextEntry1307->Resize(80,fTextEntry1307->GetDefaultHeight());
   fGroupFrame717->AddFrame(fTextEntry1307, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1307->MoveResize(72,120,80,22);
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

      // graphics context changes
   GCValues_t valEntry721;
   valEntry721.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry721.fForeground);
   gClient->GetColorByName("#e0e0e0",valEntry721.fBackground);
   valEntry721.fFillStyle = kFillSolid;
   valEntry721.fFont = ufont->GetFontHandle();
   valEntry721.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry721, kTRUE);

   fTextEntry1308 = new TGTextEntry(fGroupFrame717, new TGTextBuffer(15),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kDoubleBorder | kOwnBackground);
   fTextEntry1308->SetMaxLength(4096);
   fTextEntry1308->SetAlignment(kTextLeft);
   fTextEntry1308->SetText("");
   fTextEntry1308->Resize(80,fTextEntry1308->GetDefaultHeight());
   fGroupFrame717->AddFrame(fTextEntry1308, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1308->MoveResize(72,144,80,22);
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");


   // graphics context changes
   GCValues_t valEntry722;
   valEntry722.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry722.fForeground);
   gClient->GetColorByName("#e0e0e0",valEntry722.fBackground);
   valEntry722.fFillStyle = kFillSolid;
   valEntry722.fFont = ufont->GetFontHandle();
   valEntry722.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry722, kTRUE);
   fTextEntry1309 = new TGTextEntry(fGroupFrame717, new TGTextBuffer(15),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kDoubleBorder | kOwnBackground);
   fTextEntry1309->SetMaxLength(4096);
   fTextEntry1309->SetAlignment(kTextLeft);
   fTextEntry1309->SetText("");
   fTextEntry1309->Resize(80,fTextEntry1309->GetDefaultHeight());
   fGroupFrame717->AddFrame(fTextEntry1309, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1309->MoveResize(72,192,80,22);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

      // graphics context changes
   GCValues_t valEntry723;
   valEntry723.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry723.fForeground);
   gClient->GetColorByName("#e0e0e0",valEntry723.fBackground);
   valEntry723.fFillStyle = kFillSolid;
   valEntry723.fFont = ufont->GetFontHandle();
   valEntry723.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry723, kTRUE);

   fTextEntry1311 = new TGTextEntry(fGroupFrame717, new TGTextBuffer(15),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kDoubleBorder | kOwnBackground);
   fTextEntry1311->SetMaxLength(4096);
   fTextEntry1311->SetAlignment(kTextLeft);
   fTextEntry1311->SetText("");
   fTextEntry1311->Resize(80,fTextEntry1311->GetDefaultHeight());
   fGroupFrame717->AddFrame(fTextEntry1311, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1311->MoveResize(72,24,80,22);
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

      // graphics context changes
   GCValues_t valEntry724;
   valEntry724.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry724.fForeground);
   gClient->GetColorByName("#e0e0e0",valEntry724.fBackground);
   valEntry724.fFillStyle = kFillSolid;
   valEntry724.fFont = ufont->GetFontHandle();
   valEntry724.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry724, kTRUE);

   fTextEntry1312 = new TGTextEntry(fGroupFrame717, new TGTextBuffer(15),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kDoubleBorder | kOwnBackground);
   fTextEntry1312->SetMaxLength(4096);
   fTextEntry1312->SetAlignment(kTextLeft);
   fTextEntry1312->SetText("");
   fTextEntry1312->Resize(80,fTextEntry1312->GetDefaultHeight());
   fGroupFrame717->AddFrame(fTextEntry1312, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1312->MoveResize(72,72,80,22);
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry725;
   valEntry725.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry725.fForeground);
   gClient->GetColorByName("#e0e0e0",valEntry725.fBackground);
   valEntry725.fFillStyle = kFillSolid;
   valEntry725.fFont = ufont->GetFontHandle();
   valEntry725.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry725, kTRUE);
 
   fTextEntry799 = new TGTextEntry(fGroupFrame717, new TGTextBuffer(15),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kDoubleBorder | kOwnBackground);
   fTextEntry799->SetMaxLength(4096);
   fTextEntry799->SetAlignment(kTextLeft);
   fTextEntry799->SetText("");
   fTextEntry799->Resize(80,fTextEntry799->GetDefaultHeight());
   fGroupFrame717->AddFrame(fTextEntry799, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry799->MoveResize(72,168,80,22);
   
   fLabel726 = new TGLabel(fGroupFrame717,"Mass");
   fLabel726->SetTextJustify(36);
   fLabel726->SetMargins(0,0,0,0);
   fLabel726->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel726, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel726->MoveResize(8,48,48,18);
   TGLabel *fLabel727 = new TGLabel(fGroupFrame717,"E");
   fLabel727->SetTextJustify(36);
   fLabel727->SetMargins(0,0,0,0);
   fLabel727->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel727, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel727->MoveResize(8,72,48,18);
   TGLabel *fLabel728 = new TGLabel(fGroupFrame717,"chi2");
   fLabel728->SetTextJustify(36);
   fLabel728->SetMargins(0,0,0,0);
   fLabel728->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel728, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel728->MoveResize(8,120,48,18);
   TGLabel *fLabel729 = new TGLabel(fGroupFrame717,"pz");
   fLabel729->SetTextJustify(36);
   fLabel729->SetMargins(0,0,0,0);
   fLabel729->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel729, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel729->MoveResize(8,192,48,18);
   TGLabel *fLabel730 = new TGLabel(fGroupFrame717,"py");
   fLabel730->SetTextJustify(36);
   fLabel730->SetMargins(0,0,0,0);
   fLabel730->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel730, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel730->MoveResize(8,168,48,18);
   TGLabel *fLabel731 = new TGLabel(fGroupFrame717,"px");
   fLabel731->SetTextJustify(36);
   fLabel731->SetMargins(0,0,0,0);
   fLabel731->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel731, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel731->MoveResize(8,144,48,18);
   TGLabel *fLabel732 = new TGLabel(fGroupFrame717,"q");
   fLabel732->SetTextJustify(36);
   fLabel732->SetMargins(0,0,0,0);
   fLabel732->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel732, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel732->MoveResize(8,96,48,18);
   fLabel733 = new TGLabel(fGroupFrame717,"Name");
   fLabel733->SetTextJustify(36);
   fLabel733->SetMargins(0,0,0,0);
   fLabel733->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel733, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel733->MoveResize(8,24,48,18);

    fTextButton1319 = new TGTextButton(fGroupFrame717,"Save Particle");
   fTextButton1319->SetEnabled(kFALSE);
   fTextButton1319->Connect("Clicked()", "Frame", this, "SaveParticle()");
   fTextButton1319->SetTextJustify(36);
   fTextButton1319->SetMargins(0,0,0,0);
   fTextButton1319->SetWrapLength(-1);
   fTextButton1319->Resize(208,24);
   fGroupFrame717->AddFrame(fTextButton1319, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1319->MoveResize(8,224,208,24);


   TGLabel *fLabel926 = new TGLabel(fGroupFrame717,"MeV/c2");  

   fLabel926->SetTextJustify(36);
   fLabel926->SetMargins(0,0,0,0);
   fLabel926->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel926, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel926->MoveResize(160,48,47,18);
   TGLabel *fLabel983 = new TGLabel(fGroupFrame717,"MeV");
   fLabel983->SetTextJustify(36);
   fLabel983->SetMargins(0,0,0,0);
   fLabel983->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel983, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel983->MoveResize(160,72,40,18);
   TGLabel *fLabel989 = new TGLabel(fGroupFrame717,"MeV/c");
   fLabel989->SetTextJustify(36);
   fLabel989->SetMargins(0,0,0,0);
   fLabel989->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel989, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel989->MoveResize(160,144,48,18);
   TGLabel *fLabel1023 = new TGLabel(fGroupFrame717,"MeV/c");
   fLabel1023->SetTextJustify(36);
   fLabel1023->SetMargins(0,0,0,0);
   fLabel1023->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel1023, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1023->MoveResize(160,168,48,18);
   TGLabel *fLabel1035 = new TGLabel(fGroupFrame717,"MeV/c");
   fLabel1035->SetTextJustify(36);
   fLabel1035->SetMargins(0,0,0,0);
   fLabel1035->SetWrapLength(-1);
   fGroupFrame717->AddFrame(fLabel1035, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel1035->MoveResize(160,192,48,18);
   
   fGroupFrame717->SetLayoutManager(new TGVerticalLayout(fGroupFrame717));
   fGroupFrame717->Resize(224,264);
   fCompositeFrame708->AddFrame(fGroupFrame717, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fGroupFrame717->MoveResize(8,336,224,264); //(8,408,224,264); //MoveResize(8,328,224,264);

    // "My Particles" group frame
   fGroupFrame735 = new TGGroupFrame(fCompositeFrame708,"My Particles");
   fGroupFrame735->SetLayoutBroken(kTRUE);

    // list box
   fListBox1321 = new TGListBox(fGroupFrame735);

   fListBox1321->Resize(208,36);
   fGroupFrame735->AddFrame(fListBox1321, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fListBox1321->MoveResize(8,24,208,36);

   fLabel743 = new TGLabel(fGroupFrame735,"Mass");
   fLabel743->SetTextJustify(36);
   fLabel743->SetMargins(0,0,0,0);
   fLabel743->SetWrapLength(-1);
   fGroupFrame735->AddFrame(fLabel743, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fLabel743->MoveResize(8,96,48,18);

   fTextButton1335 = new TGTextButton(fGroupFrame735,"Calculate");
   fTextButton1335->Connect("Clicked()", "Frame", this, "Calculate()");
   fTextButton1335->SetEnabled(kFALSE);
   fTextButton1335->SetTextJustify(36);
   fTextButton1335->SetMargins(0,0,0,0);
   fTextButton1335->SetWrapLength(-1);
   fTextButton1335->Resize(104,24);
   fGroupFrame735->AddFrame(fTextButton1335, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1335->MoveResize(8,64,104,24);

   fTextButton753 = new TGTextButton(fGroupFrame735,"Delete");
   fTextButton753->Connect("Pressed()", "Frame", this, "DeleteParticle()");
   fTextButton753->SetEnabled(kFALSE);
   fTextButton753->SetTextJustify(36);
   fTextButton753->SetMargins(0,0,0,0);
   fTextButton753->SetWrapLength(-1);
   fTextButton753->Resize(96,24);
   fGroupFrame735->AddFrame(fTextButton753, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton753->MoveResize(120,64,96,24);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valEntry746;
   valEntry746.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valEntry746.fForeground);
   gClient->GetColorByName("#e0e0e0",valEntry746.fBackground);
   valEntry746.fFillStyle = kFillSolid;
   valEntry746.fFont = ufont->GetFontHandle();
   valEntry746.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valEntry746, kTRUE);
   
 fTextEntry1337 = new TGTextEntry(fGroupFrame735, new TGTextBuffer(15),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kDoubleBorder | kOwnBackground);
   fTextEntry1337->SetMaxLength(4096);
   fTextEntry1337->SetAlignment(kTextLeft);
   fTextEntry1337->SetText("");
   fTextEntry1337->Resize(160,fTextEntry1337->GetDefaultHeight());
   fGroupFrame735->AddFrame(fTextEntry1337, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextEntry1337->MoveResize(56,96,160,22);

   fGroupFrame735->SetLayoutManager(new TGVerticalLayout(fGroupFrame735));
   fGroupFrame735->Resize(224,136);
   fCompositeFrame708->AddFrame(fGroupFrame735, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fGroupFrame735->MoveResize(8,600,224,136); //(8,672,224,136); //MoveResize(8,592,224,136);
 
   // "Histogram" group frame
   fGroupFrame1395 = new TGGroupFrame(fCompositeFrame708,"Histogram");
   fGroupFrame1395->SetLayoutBroken(kTRUE);
   fTextButton1442 = new TGTextButton(fGroupFrame1395,"Draw");
   fTextButton1442->Connect("Clicked()", "Frame", this, "Draw()");
   fTextButton1442->SetTextJustify(36);
   fTextButton1442->SetMargins(0,0,0,0);
   fTextButton1442->SetWrapLength(-1);
   fTextButton1442->Resize(96,24);
   fTextButton1442->SetState(kButtonDisabled);
   fGroupFrame1395->AddFrame(fTextButton1442, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton1442->MoveResize(120,24,96,24);
   fTextButton753a = new TGTextButton(fGroupFrame1395,"Add");
   fTextButton753a->Connect("Pressed()", "Frame", this, "Continue()");
   fTextButton753a->SetTextJustify(36);
   fTextButton753a->SetMargins(0,0,0,0);
   fTextButton753a->SetWrapLength(-1);
   fTextButton753a->Resize(104,24);
   fTextButton753a->SetState(kButtonDisabled);
   fGroupFrame1395->AddFrame(fTextButton753a, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton753a->MoveResize(8,24,104,24);
   fTextButton758 = new TGTextButton(fGroupFrame1395,"Save Histogram");
   fTextButton758->Connect("Clicked()", "Frame", this, "SaveHist()");
   fTextButton758->SetTextJustify(36);
   fTextButton758->SetMargins(0,0,0,0);
   fTextButton758->SetWrapLength(-1);
   fTextButton758->Resize(208,24);
   fTextButton758->SetState(kButtonDisabled);
   fGroupFrame1395->AddFrame(fTextButton758, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton758->MoveResize(8,56,208,24);

   
   fTextButton834 = new TGTextButton(fGroupFrame1395,"Move on to D0 Exercise");
   fTextButton834->Connect("Clicked()", "Frame", this, "Exit()");
   fTextButton834->SetTextJustify(36);
   fTextButton834->SetMargins(0,0,0,0);
   fTextButton834->SetWrapLength(-1);
   fTextButton834->Resize(208,24);
   fGroupFrame1395->AddFrame(fTextButton834, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fTextButton834->MoveResize(8,88,208,24);

   fGroupFrame1395->SetLayoutManager(new TGVerticalLayout(fGroupFrame1395));
   fGroupFrame1395->Resize(224,128);
   fCompositeFrame708->AddFrame(fGroupFrame1395, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fGroupFrame1395->MoveResize(8,736,224,128); //MoveResize(8,808,224,96); //MoveResize(8,728,224,96);
   
       // "Legend" group frame
   fGroupFrame748 = new TGGroupFrame(fCompositeFrame708 ,"Legend");
   fGroupFrame748->SetLayoutBroken(kTRUE);

   leg = new TGIcon(fGroupFrame748,"Icons/leg1.png");
  // printf("%s",gSystem->GetPathInfo("Icons/leg1.png"));
   fGroupFrame748->AddFrame(leg, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   leg-> MoveResize(40,20,141,100);
  
   fGroupFrame748->SetLayoutManager(new TGVerticalLayout(fGroupFrame748));
   fGroupFrame748->Resize(224,140);
   fCompositeFrame708->AddFrame(fGroupFrame748, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fGroupFrame748->MoveResize(8,864,224,128); //(8,904,224,134); //MoveResize(8,824,224,140);
   
   fCompositeFrame1193->AddFrame(fCompositeFrame708, new TGLayoutHints(kLHintsNormal));
   fViewPort1184->AddFrame(fCompositeFrame1193);
   fCompositeFrame1193->SetLayoutManager(new TGTileLayout(fCompositeFrame1193,8));
   fCompositeFrame1193->MapSubwindows();
   fCanvas1183->SetContainer(fCompositeFrame1193);
   fCanvas1183->MapSubwindows();
   fCanvas1183->SetVsbPosition(0);
   fCompositeFrame1182->AddFrame(fCanvas1183, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fCanvas1183->MoveResize(0,0,280,mainFrameHeight-100);

   fMainFrame1181->AddFrame(fCompositeFrame1182, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fCompositeFrame1182->MoveResize(0,8,490,1050); //MoveResize(0,0,296,816);

   fMainFrame1460->AddFrame(fMainFrame1181, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame1181->MoveResize(0,0,490,1050);  //MoveResize(0,0,490,933);

   fMainFrame1460->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fMainFrame1460->MapSubwindows();

   fMainFrame1460->Resize(fMainFrame1460->GetDefaultSize());
   fMainFrame1460->MapWindow();
   fMainFrame1460->Resize(490,1055); //Resize(1024,1130); //Resize(602,846);

	browser->SetTabTitle("Event Control", 0);
	browser->StopEmbedding();
	
}
void Frame:: Exit()
{
	gEve->GetBrowser()->GetMainFrame()->UnmapWindow();
	l_start->enableII();
}
void Frame::SaveHist(){
	
	TString histName1="MassHistogram_";
	histName1.Append(histName);
	
	TFile *saveH=new TFile(pathSave+histName1,"RECREATE");
	if(a->Write())
	{
		new TGMsgBox(gClient->GetRoot(), 0,  "Info", h1,0);
	}
	else{
		new TGMsgBox(gClient->GetRoot(), 0,  "Error", "Access denied.",0);
	}
	saveH->Close();
}

void Frame:: DeleteParticle(){
	if(particleCount>0){
		Int_t id = fListBox1321->GetSelected();
		if (id>=0){
		if(id==0)flag=1;
		fListBox1321->RemoveEntry(id);
		particleCount--;
		fTextEntry1337->SetText("");
		fTextButton1335->SetEnabled(kFALSE);}
	}
}
void Frame :: SaveParticle()
{
		if(particleCount>1) //if there is already two particles selected
		{
			new TGMsgBox(gClient->GetRoot(), 0,  "Error", e1,0);
		}
		else if (particleCount==0 || flag==1) //if this is a first selected particle
		{
			fListBox1321->AddEntry("My particle: "+selected.particleId->GetString(),particleCount);
			myParticle1=selected;
			particleCount++;
			if(flag==1)fTextButton1335->SetEnabled();
			flag=0;
		}
		else if (selected.particleId == myParticle1.particleId && selected.px == myParticle1.px && selected.py==myParticle1.py) {
			new TGMsgBox(gClient->GetRoot(), 0,  "Error", e2,0);
		}
		else {
			fListBox1321->AddEntry("My particle: "+selected.particleId->GetString(),particleCount);
			myParticle2=selected;
			fTextButton1335->SetEnabled(kTRUE);
			particleCount++;
		}
		fListBox1321->MoveResize(8,24,208,36);
		fTextButton753->SetEnabled();
		
}
void Frame::Clear() {
	//deletes all tracks on screen
	gEve->GetViewers()->DeleteAnnotations();
	gEve->GetCurrentEvent()->DestroyElements();
}
void Frame:: OnClicked(TObject *obj)
{
   // Handle click events in GL viewer
   if (obj && obj->InheritsFrom("TEveElement")) { //std::cout <<"akakak";}
     TEveLine *el = dynamic_cast<TEveLine*>(obj);
	 TEveVector s = el->GetLineStart();
	 TEveVector e = el->GetLineEnd();
	int y1=static_cast<int>(s.fY); 
	int y2=static_cast<int>(e.fY); 
	int x1=static_cast<int>(s.fX); 
	int x2=static_cast<int>(e.fX);
	
	long long longIndex=(31*y1+31*31*x1+11*31*31*y2+11*31*31*x2); // sqrt(pow((x2-x1),2)+pow((y2-y1),2)+yN;
	int index = longIndex % 10000000;
	//std::cout << x1 << " "<< x2 <<" "<<y1 <<" "<<y2<<" "<< index<<endl;
	// float index=s.fX + s.fY + e.fX;
	 selected=particles[index];
	 //particles[p*(p + hash(pointsArray->GetX(p-1)) + hash(pointsArray->GetY(p-1)))] = *t
	  fTextEntry1305->SetText(Form("%.2lf",selected.mass));
	  fTextEntry1306->SetText(Form("%.2lf",selected.q));
	  fTextEntry1307->SetText(Form("%.2lf",selected.chi2));
	  fTextEntry1308->SetText(Form("%.2lf",selected.px));
	  fTextEntry1309->SetText(Form("%.2lf",selected.pz));
	  fTextEntry1311->SetText(selected.particleId->GetString());
	  fTextEntry1312->SetText(Form("%.2lf",selected.E));
	  fTextEntry799->SetText(Form("%.2lf",selected.py));
	  fTextButton1319->SetEnabled();
   }

}
void Frame::readTracks() {
	//random colors
	//TRandom r;	
	Int_t ncolors = gStyle->GetNumberOfColors();

	array = new TObjArray();
	//array->Clear();
	tree->SetBranchAddress("event", &array);
	//array->Delete();
	//tree->GetUserInfo()->Clear();
	//printf("%d", counter);
	tree->GetEntry(counter);
	
	int size =  array->GetEntries(); //Last();  //getting the SIZE of array
	//printf("Size of the array: %d\n", size);
	TEveElementList *list = new TEveElementList("Tracks", "Tracks");

	for (int a=0; a<size; a++)
	{
		LbMclassTrack *t = (LbMclassTrack *)array->At(a);
		TPointsArray3D *pointsArray = t->track;

		//t->printTrack();

		linexx= new TEveLine();

		linexx->SetPickable(kTRUE);

		TObjString *particleName=t->particleId;
		int partColor=0;
		if(particleName->IsEqual(new TObjString("pi+")))partColor=6;
		else if(particleName->IsEqual(new TObjString("pi-")))partColor=2;
		else if(particleName->IsEqual(new TObjString("K-")))partColor=kGreen+2;
		else if(particleName->IsEqual(new TObjString("K+")))partColor=4;
		else if(particleName->IsEqual(new TObjString("D0"))) partColor=1;
		else  partColor=ncolors*r.Rndm();
		linexx->SetLineColor(partColor);
		//linexx->SetLineWidth(4);
		//if(a==2) {center[0] = t->pvx; center[1]=t->pvy;  center[2]= t->pvz; } 
		if(a==2) {center[0] = pointsArray->GetX(0); center[1]=pointsArray->GetY(0); center[2]= pointsArray->GetZ(0);}
		if(particleName->IsEqual(new TObjString("D0"))){}
		else {
		for (int i=0; i< pointsArray->GetN(); i++)
		{
		  linexx->SetNextPoint(pointsArray->GetX(i), pointsArray->GetY(i), pointsArray->GetZ(i));
		}}
		//MAP
		float p=pointsArray->GetN();
		int y1=static_cast<int>(pointsArray->GetY(0)); 
		int y2=static_cast<int>(pointsArray->GetY(p-1)); 
		int x1=static_cast<int>(pointsArray->GetX(0)); 
		int x2=static_cast<int>(pointsArray->GetX(p-1));
		long long longIndex=(31*y1+31*31*x1+11*31*31*y2+11*31*31*x2); // sqrt(pow((x2-x1),2)+pow((y2-y1),2)+yN;
		int index = longIndex% 10000000;
		particles[index] = *t;		//std::cout << x1 << " "<< x2 <<" "<<y1 <<" "<<y2<< " "<< index<<endl;
		list->AddElement(linexx);
	}
	//delete array;
	gEve->AddElement(list);
	gEve->DoRedraw3D();
	gEve->GetDefaultGLViewer()->Connect("Clicked(TObject*)", "Frame", this, "OnClicked(TObject*)");

}
void Frame:: Validate(Int_t h){
	
	if (!(h>=1)) h=1;
	fileName = Form("share/LHCbMasterclass/mclasseventv2_D0_%d",h);
	histName = Form("%d_%s.root",h, user1);
	//fTextButton1353 -> SetEnabled(kFALSE);
	//fComboBox1325 ->SetEnabled(kFALSE);
	enableAll();
	TFile *file = TFile::Open(fileName.Append(".root"));
	tree = (TTree *)file->Get("MCEvent");
	nb = tree->GetEntries(); // nb == total number of events
	//printf("Number of events: %d\n", nb);
	readTracks();
	DefaultCam();

}
void Frame:: Hint(){
	TEveElementList *list = new TEveElementList("Tracks", "Tracks");

//legend picture changes 
	TGPicture *fRightIconPicture = (TGPicture *)gClient->GetPicture("Icons/leg2.png");
	gClient->FreePicture(fRightIconPicture);
	fRightIconPicture = (TGPicture *)gClient->GetPicture("Icons/leg2.png");
	leg->SetPicture(fRightIconPicture);

	//particles
	for (int a=0; a<3; a++)
	{
		LbMclassTrack *t = (LbMclassTrack *)array->At(a);
		TPointsArray3D *pointsArray = t->track;

		//t->printTrack();

		linexx= new TEveLine();

		linexx->SetPickable(kTRUE);

		TObjString *particleName=t->particleId;
		int partColor=0;
		if(particleName->IsEqual(new TObjString("pi+")))partColor=6;
		else if(particleName->IsEqual(new TObjString("pi-")))partColor=2;
		else if(particleName->IsEqual(new TObjString("K-")))partColor=kGreen+2;
		else if(particleName->IsEqual(new TObjString("K+")))partColor=4;
		else if(particleName->IsEqual(new TObjString("D0")))partColor=1;

		linexx->SetLineColor(partColor);
		linexx->SetLineWidth(4);
		for (int i=0; i< pointsArray->GetN(); i++)
		{
		  linexx->SetNextPoint(pointsArray->GetX(i), pointsArray->GetY(i), pointsArray->GetZ(i));
		}
		list->AddElement(linexx);
	}
	//delete array;
	gEve->AddElement(list);
	gEve->DoRedraw3D();
	gEve->GetDefaultGLViewer()->Connect("Clicked(TObject*)", "Frame", this, "OnClicked(TObject*)");

}
void Frame:: Zoom(){ 
	if(zoomBool) {new TGMsgBox(gClient->GetRoot(), 0,  "Hint", h2,0); zoomBool=kFALSE;}
		gEve->GetDefaultGLViewer()->ResetCameras();
		//center[3] = {0,0,0};
		TGLViewer *v = gEve->GetDefaultGLViewer();
		//v->CurrentCamera().Configure(0.0003, 0, center, 1.57, -1.57);
		//v->CurrentCamera().Reset();//0.005

		Double_t pom [8][3];
		pom[0][0]=center[0]-5;		pom[0][1]=-3;					pom[0][2]=center[2]-5;
		pom[1][0]=center[0]+5;		pom[1][1]=-3;					pom[1][2]=center[2]-5;
		pom[2][0]=center[0]+5;		pom[2][1]=center[1]+3;			pom[2][2]=center[2]-5;
		pom[3][0]=center[0]-5;		pom[3][1]=center[1]+3;			pom[3][2]=center[2]-5;
		pom[4][0]=center[0]-5;		pom[4][1]=-3;					pom[4][2]=center[2]+5;
		pom[5][0]=center[0]+5;		pom[5][1]=-3;					pom[5][2]=center[2]+5;
		pom[6][0]=center[0]+5;		pom[6][1]=center[1]+3;			pom[6][2]=center[2]+5;
		pom[7][0]=center[0]-5;		pom[7][1]=center[1]+3;			pom[7][2]=center[2]+5;
		v->CurrentCamera().Setup(TGLBoundingBox(pom));
		gEve->GetEventScene();
		v->CurrentCamera().Configure(10, 0, center, 1.57, -1.57);
		v->DoDraw();

}
void Frame:: YZ(){rotate(0,0);}
void Frame:: YX(){rotate(0, -PI/2);}
void Frame:: ZX(){rotate(PI/2, -PI/2);}
void Frame:: rotate(double hor, double ver){
	gEve->GetDefaultGLViewer()->ResetCameras();
	TGLViewer *v = gEve->GetDefaultGLViewer();
	Double_t pom [8][3];
	pom[0][0]=center[0]-1515;		pom[0][1]=-1513;					pom[0][2]=center[2]-1515;
	pom[1][0]=center[0]+1515;		pom[1][1]=-1513;					pom[1][2]=center[2]-1515;
	pom[2][0]=center[0]+1515;		pom[2][1]=center[1]+1513;			pom[2][2]=center[2]-1515;
	pom[3][0]=center[0]-1515;		pom[3][1]=center[1]+1513;			pom[3][2]=center[2]-1515;
	pom[4][0]=center[0]-1515;		pom[4][1]=-1513;					pom[4][2]=center[2]+1515;
	pom[5][0]=center[0]+1515;		pom[5][1]=-1513;					pom[5][2]=center[2]+1515;
	pom[6][0]=center[0]+1515;		pom[6][1]=center[1]+1513;			pom[6][2]=center[2]+1515;
	pom[7][0]=center[0]-1515;		pom[7][1]=center[1]+1513;			pom[7][2]=center[2]+1515;

	v->CurrentCamera().Setup(TGLBoundingBox(pom));
	v->CurrentCamera().Configure(10, 0, center, 0, 0);
	//v->SetGuideState(TGLUtil::kAxesEdge, kTRUE, kFALSE, 0);
    //v->RefreshPadEditor(v);
	v->CurrentCamera().RotateRad(hor, ver);
	v->DoDraw();
}
void Frame:: DefaultCam(){ 
	gEve->GetDefaultGLViewer()->ResetCameras();
	//gEve->GetDefaultGLViewer()->RequestDraw();
	TGLViewer *v = gEve->GetDefaultGLViewer();
	v->CurrentCamera().RotateRad(-1.2, 0.5);
	v->DoDraw();
}
void Frame :: GeometrySwitch(){
	if(checked == 1){
			checked=-1; 
			HideGeometry();
		}
	else if (checked == -1){
			checked=1; 
			ShowGeometry();
		}
}
void Frame:: HideGeometry(){
	
		TEveViewer *v = (TEveViewer*) gEve->GetViewers()->FindChild("Viewer 1");
	    TEveSceneInfo *si = (TEveSceneInfo*) v->FindChild("SI - Geometry scene");
		si->SetRnrState(kFALSE);
		gEve->DoRedraw3D();

}
void Frame:: ShowGeometry(){
	if (checked==0) 
	{
		gGeoManager = gEve->GetGeometry("share/LHCbMasterclass/lhcbfull.root");
		gGeoManager->DefaultColors();
		TEveGeoTopNode* tn = new TEveGeoTopNode(gGeoManager, gGeoManager->GetTopNode());

		// Hiding Ecal Modules as they are many of them, slowing down rendering
		TGeoVolume *ecalModulesFiberPb = gGeoManager->FindVolumeFast("EcalModulesFiberPb");
		if (ecalModulesFiberPb != 0) 
		{ 
			ecalModulesFiberPb->SetVisibility(kFALSE);
			std::cerr << "Hiding volume EcalModulesFiberPb" << std::endl;
		} 
		else 
		{
			std::cerr << "Failed locating EcalModulesFiberPb" << std::endl;
		}
		tn->SetVisLevel(4);
		gEve->AddGlobalElement(tn);
		checked=1;
	}
	else 
	{
		TEveViewer *v = (TEveViewer*) gEve->GetViewers()->FindChild("Viewer 1");
		TEveSceneInfo *si = (TEveSceneInfo*) v->FindChild("SI - Geometry scene");
		si->SetRnrState(kTRUE);
		gEve->DoRedraw3D();
	}

}

void Frame::ShowTransparency()
{
  std::cout << "ShowTransparency:" << checked_trans << std::endl;
  if ( checked_trans == 0 ){
    std::cout << "ShowTransparency - Initial Setup" << std::endl;
    TGeoVolume* top = gGeoManager->GetTopVolume();
    TGeoIterator next( top );
    TGeoNode *node = 0;
    bool debug = false;
    while ( (node=(TGeoNode*)next()) )
      {
	TGeoVolume *volume = node->GetVolume();
	if ( volume ) {
	  fVolumeTrans.push_back( std::make_pair( volume , volume->GetTransparency() ) );
	}
      }
    checked_trans = -1;
    return ;
  }

  std::vector< std::pair< TGeoVolume*, UInt_t > >::iterator it;

  for ( it = fVolumeTrans.begin(); it != fVolumeTrans.end(); ++it ){
    if ( checked_trans == 1 ) {
      it->first->SetVisibility();
      it->first->SetTransparency( 80 );
    }
    else {
      //->first->SetVisibility();                                                                                                                                               
      it->first->SetTransparency( it->second );
    }
  }
  gEve->FullRedraw3D(false); //VERY SLOW

  return ;
}

void Frame::TransparencySwitch()
{
  std::cout << "TransparencySwitch " << checked_trans << std::endl;
  if ( 1 == checked_trans ){
    checked_trans  = -1;
  }
  else {
    checked_trans  = 1;
  }
  ShowTransparency();
  return;
}

void Frame :: Calculate(){
	Double_t a=(myParticle1.E + myParticle2.E)*(myParticle1.E + myParticle2.E);
    Double_t b=(myParticle1.px + myParticle2.px)*(myParticle1.px + myParticle2.px);
	Double_t c=(myParticle1.py + myParticle2.py)*(myParticle1.py + myParticle2.py);
	Double_t d=(myParticle1.pz + myParticle2.pz)*(myParticle1.pz + myParticle2.pz);
	res=sqrt(a-b-c-d);

	fTextEntry1337->SetText(Form("%.2lf",res));

	 fTextButton753a->SetEnabled();
}

void Frame :: Draw(){
	//fTextButton1606->SetEnabled();
	fTextButton1442 ->SetEnabled();
	fTextButton758->SetEnabled(); //save histogram enabled
  TString tabname = "My histogram";

  TIter next( gEve->GetBrowser()->GetTabRight()->GetList() );
  
  TGFrameElement* frame;
  TGTabElement* tab;
  
  bool tabopen = false;
  
  while ((frame = (TGFrameElement*) next())) {
    
    TString tname = ((TGTabElement *)(frame->fFrame))->GetString();
    
    if ( 0 == tname.CompareTo( tabname  ) ) tabopen = true; 
  }

  if ( !tabopen ) { 
		if ( fHistCanvas ) fHistCanvas = 0;

		gEve->GetBrowser()->StartEmbedding(1);
	
		fHistCanvas = new TCanvas("HistCanvas","");
		fHistCanvas->cd() ;
    
		tabNum++;
		a->Draw();
		gEve->GetBrowser()->StopEmbedding( tabname );
		//  his=1;
	}
	else
	{
		fHistCanvas->SetEditable(kTRUE);
		gEve->GetBrowser()->GetTabRight()->SetTab( tabname );
    
		fHistCanvas->cd() ;
        a->Draw();
    
		fHistCanvas->Update();
	}
  fHistCanvas->SetEditable(kFALSE);
}
void Frame :: Continue(){
	if (eventsDone[counter]==kTRUE){ new TGMsgBox(gClient->GetRoot(), 0,  "Error", e4,0);
	}
	else if ( res >= 1814 && res <= 1915){
			a->Fill(res);
			eventsDone[counter]=kTRUE;
			fTextButton1442->SetEnabled();
			}
	else new TGMsgBox(gClient->GetRoot(), 0,  "Error", e3,0);
}
Frame::~Frame() {
	// TODO Auto-generated destructor stub
}


void Frame :: Help(){
  TString tabname = "Help";
  
  TIter next( gEve->GetBrowser()->GetTabRight()->GetList() );
  
  TGFrameElement* frame;
  TGTabElement* tab;
  
  bool tabopen1 = false;
  
  while ((frame = (TGFrameElement*) next())) {
    
    TString tname = ((TGTabElement *)(frame->fFrame))->GetString();
    
    if ( 0 == tname.CompareTo( tabname  ) ) tabopen1 = true; 
  }

//printf(">>>>>>>>>>>>>>>>> %s",  gSystem->WorkingDirectory());
  
  if ( !tabopen1 ) { 
		gEve->GetBrowser()->StartEmbedding(1);
		TGMainFrame *fMainFrame734 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   fMainFrame734->SetLayoutBroken(kTRUE);
   TGIcon *fIcon560 = new TGIcon(fMainFrame734,Form("Icons/help%d.png", lang1));
   fMainFrame734->AddFrame(fIcon560, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Float_t a=1647.0/909.0; //printf("%fl", a); //fIcon560->GetWidth()/fIcon560->GetHeight() ; //
   
   Float_t newHeight=mainFrameHeight*0.8;
   fIcon560->MoveResize(0,0,a*newHeight,newHeight);
   fMainFrame734->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fMainFrame734->MapSubwindows();

   fMainFrame734->Resize(fMainFrame734->GetDefaultSize());
   fMainFrame734->MapWindow();
   fMainFrame734->Resize(1096,772);
		/*
		
		TImage *helpImg = TImage ::Open("Icons/help.png");
		helpImg->SetConstRatio(kFALSE);
		helpImg->Draw();
		helpImg->SetEditable(kFALSE);
		helpImg->SetPaletteEnabled(kFALSE);*/
		gEve->GetBrowser()->StopEmbedding( tabname );
	}

}


void Frame :: EN()
{
	//buttons
	//fTextButton1353 ->SetText("Validate");          //1
	fTextButton759 ->SetText("Help");               //2
	fTextButton834 ->SetText("Move on to D0 Exercise");               //3
	fTextButton1319 ->SetText("Save Particle");     //4
	fTextButton1335 ->SetText("Calculate");         //5 
	fTextButton753 ->SetText("Delete");             //6
	fTextButton753a ->SetText("Add");               //7
	fTextButton1442->SetText ("Draw");              //8
	fTextButton758 ->SetText("Save Histogram");     //9 

	//labels
	fLabel726->SetText("Mass");                     //10
	fLabel743->SetText("Mass");                     //10 
	fLabel733->SetText("Name");                     //11
	fLabel842->SetText ("Event number:");           //12

	//group box
	fGroupFrame735->SetTitle("My Particles");       //13
	fGroupFrame717->SetTitle ("Particle Info");     //14
	fGroupFrame735->SetTitle ("My Particles");      //15
	fGroupFrame860->SetTitle("Zoom");               //16
	fGroupFrame714->SetTitle("Event manager");      //17
	fGroupFrame709->SetTitle("View");               //18
	fGroupFrame748->SetTitle("Legend");             //19
	fGroupFrame1395->SetTitle("Histogram");         //20
	//fGroupFrame1558->SetTitle("Start");             //21
	//fGroupFrame558->SetTitle("Languages");          //22

	fCheckButton712->SetText("Hide Geometry");      //23
	fCheckButton713->SetText("Transparency");       //24
}

void Frame :: IT()
{
	//buttons
	//fTextButton1353 ->SetText("Convalida");
	fTextButton759 ->SetText("Aiuto");
	fTextButton834 ->SetText("Esci");
	fTextButton1319 ->SetText("Salva la Particella");
	fTextButton1335 ->SetText("Calcola");
	fTextButton753 ->SetText("Cancella");
	fTextButton753a ->SetText("Aggiungi");
	fTextButton1442->SetText ("Disegna");
	fTextButton758 ->SetText("Salva l'Istogramma");

	//labels
	fLabel726->SetText("Massa");
	fLabel743->SetText("Massa");
	fLabel733->SetText("Nome");
	fLabel842->SetText ("Numero di evento:");

	//group box
	fGroupFrame735->SetTitle("Le mie particelle");
	fGroupFrame717->SetTitle ("Informazioni sulla particella");
	fGroupFrame735->SetTitle ("Le mie particelle");
	fGroupFrame860->SetTitle("Zoom");
	fGroupFrame714->SetTitle("Gestore degli eventi");
	fGroupFrame709->SetTitle("Visualizza");
	fGroupFrame748->SetTitle("Legenda");
	fGroupFrame1395->SetTitle("Istogramma");
	//fGroupFrame1558->SetTitle("Inizia");
	//fGroupFrame558->SetTitle("Lingua");

	fCheckButton712->SetText("Nascondi la geometria");
	fCheckButton713->SetText("Trasparenza");

	e1="Non e' possibile selezionare piu' di due particelle per volta.";
	e2="Questa particella e' gia' stata selezionata.";
	e3="La massa calcolata non e' nell'intervallo ammesso. Riprova di nuovo.";
	e4="Hai gia' aggiunto questo valore di massa nell'istogramma";
	h2="Premi CTRL o CTRL+SHIFT per ruotare la figura in modo piu' preciso.";
	h3_a="Congratulazioni";
	h3_b="Hai compleato con successo l'esercizio MasterClassDisplay";
	h1="Istogramma salvato con successo";
}

void Frame :: DE()
{
	//buttons
	//fTextButton1353 ->SetText("Validieren");          //1
	fTextButton759 ->SetText("Hilfe");               //2
	fTextButton834 ->SetText("Schliessen");               //3
	fTextButton1319 ->SetText("Teilchen speichern");     //4
	fTextButton1335 ->SetText("Berechnen");         //5 
	fTextButton753 ->SetText("Loeschen");             //6
	fTextButton753a ->SetText("Hinzufuegen");               //7
	fTextButton1442->SetText ("Zeichnen");              //8
	fTextButton758 ->SetText("Histogramm speichern");     //9 

	//labels
	fLabel726->SetText("Masse");                     //10
	fLabel743->SetText("Masse");                     //10 
	fLabel733->SetText("Name");                     //11
	fLabel842->SetText ("Ereignis-Nr.:");           //12

	//group box
	fGroupFrame735->SetTitle("Meine Teilchen");       //13
	fGroupFrame717->SetTitle ("Teilchen-Information");     //14
	fGroupFrame735->SetTitle ("Meine Teilchen");      //15
	fGroupFrame860->SetTitle("Zoom");               //16
	fGroupFrame714->SetTitle("Ereignis-Verwaltung");      //17
	fGroupFrame709->SetTitle("Ansicht");               //18
	fGroupFrame748->SetTitle("Legende");             //19
	fGroupFrame1395->SetTitle("Histogramm");         //20
	//fGroupFrame1558->SetTitle("Start");             //21
	//fGroupFrame558->SetTitle("Sprachen");          //22

	fCheckButton712->SetText("Geometrie verbergen");      //23
	fCheckButton713->SetText("Transparenz");       //24

	e1="Du kannst nicht mehr als zwei Teilchen auswaehlen.";
	e2="Dieses Teilchen ist bereits ausgewaehlt.";
	h1="Das Histogram wurde erfolgreich gespeichert.";
	h2="Wenn du die Ansicht rotieren willst, druecke STRG oder STRG + SHIFT um praeziser zu arbeiten.";
	e3="Die Masse liegt nicht im korrekten Interval. Versuche es erneut.";
	e4="Du hast bereits ein Massen-Histogram hinzugefuegt.";
	h3_a="Herzlichen Glueckwunsch!"; 
	h3_b="Du hast die MasterclassDisplay-Aufgabe erfolgreich geloest.";
	
}
void Frame :: FR()
{
		//buttons
	//fTextButton1353 ->SetText("Valider");          //1
	fTextButton759 ->SetText("Aide");               //2
	fTextButton834 ->SetText("Quitter");               //3
	fTextButton1319 ->SetText("Sauver une particule");     //4
	fTextButton1335 ->SetText("Calculer");         //5 
	fTextButton753 ->SetText("Effacer");             //6
	fTextButton753a ->SetText("Ajouter");               //7
	fTextButton1442->SetText ("Dessiner");              //8
	fTextButton758 ->SetText("Sauver l'histogramme");     //9 

	//labels
	fLabel726->SetText("Masse");                     //10
	fLabel743->SetText("Masse");                     //10 
	fLabel733->SetText("Nom");                     //11
	fLabel842->SetText ("Num. d'evenement:");           //12

	//group box
	fGroupFrame735->SetTitle("Mes particules");       //13
	fGroupFrame717->SetTitle ("Information sur les particules");     //14
	fGroupFrame735->SetTitle ("Mes particules");      //15
	fGroupFrame860->SetTitle("Zoom");               //16
	fGroupFrame714->SetTitle("Gestionnaire d'evenement");      //17
	fGroupFrame709->SetTitle("Voir");               //18
	fGroupFrame748->SetTitle("Legende");             //19
	fGroupFrame1395->SetTitle("Histogramme");         //20
	//fGroupFrame1558->SetTitle("Commencer");             //21
	//fGroupFrame558->SetTitle("Langages");          //22

	fCheckButton712->SetText("Masquer la geometrie");      //23
	fCheckButton713->SetText("Transparence");       //24

	e1="Vous ne pouvez pas avoir plus de deux particules.";
	e2="Vous avez deja ajoute cette particule.";
	h1="Vous avez enregistrez votre histogramme avec succes.";
	h2="Pour effectuez un rotation de la vue, utilisez CTRL ou CTRL+SHIFT pour etre plus precis.";
	e3="Le masse n'est pas dans le domaine. Essayez a nouveau.";
	e4="Vous avez deja ajoute une nouvelle masse a l'histogramme.";
	h3_a="Felicitations!";
	h3_b="Vous avez realise votre exercice avec succes.";
	

}
void Frame :: RO()
{
		//buttons
	//fTextButton1353 ->SetText("Valideaza");          //1 
	fTextButton759 ->SetText("Ajutor");               //2
	fTextButton834 ->SetText("Iesire");               //3 
	fTextButton1319 ->SetText("Salveaza particula");     //4  
	fTextButton1335 ->SetText("Calculeaza");         //5  
	fTextButton753 ->SetText("Sterge");             //6 
	fTextButton753a ->SetText("Adauga");               //7 
	fTextButton1442->SetText ("Deseneaza");              //8 
	fTextButton758 ->SetText("Salveaza histograma");     //9 

	//labels
	fLabel726->SetText("Masa");                     //10
	fLabel743->SetText("Masa");                     //10 
	fLabel733->SetText("Nume");                     //11
	fLabel842->SetText ("Indice eveniment:");           //12

	//group box
	fGroupFrame735->SetTitle("Particulele mele");       //13
	fGroupFrame717->SetTitle ("Informatii particula");     //14  
	fGroupFrame735->SetTitle ("Particulele mele");      //15
	fGroupFrame860->SetTitle("Mareste");               //16 
	fGroupFrame714->SetTitle("Manager evenimente");      //17
	fGroupFrame709->SetTitle("Vizualizeaza");               //18 
	fGroupFrame748->SetTitle("Legenda");             //19 
	fGroupFrame1395->SetTitle("Histograma");         //20
	//fGroupFrame1558->SetTitle("Start");             //21
//	fGroupFrame558->SetTitle("Limba");          //22

	fCheckButton712->SetText("Ascunde geometria");      //23
	fCheckButton713->SetText("Transparenta");       //24 


	e1="Nu puteti avea mai mult de doua particule.";
	e2="Ati adaugat deja aceasta particula la lista.";

	h1="Ati salvat cu succes histograma dvs.";
	h2="Cand rotiti imaginea apasati tasta CTRL sau tastele CTRL si SHIFT pentru a avea o precizie mai buna.";
	e3="Masa nu este in interval. Va rugam incercati din nou.";
	e4="Noua masuratoare de masa este deja adaugata la histograma.";

	h3_a="Felicitari!"; 
	h3_b="Ati completat cu succes exercitiul MasterClassDisplay.";

}
