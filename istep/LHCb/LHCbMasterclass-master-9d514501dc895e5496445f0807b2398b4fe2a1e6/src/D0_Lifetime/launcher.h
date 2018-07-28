#pragma once
#include "TString.h"
#include <TGTextEntry.h>
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#include <TGButton.h>

class launcher 
{
	public:
		int lang;
		int start;
		char* user;
		Int_t h;
		TString pathSave1;
		TGMainFrame *fMainFrame990;
		TGTextEntry *fTextEntry754;
		TGTextEntry *fTextEntry752;
		TGTextEntry *fTextEntry753;
		TGComboBox *fComboBox759;
		TGPictureButton *fPictureButton779;
		TGPictureButton *fPictureButton785;
		TGTextButton *fTextButton758;
		TGGroupFrame *fGroupFrame781;
		TGGroupFrame *fGroupFrame745;
		TGGroupFrame *fGroupFrame751;

		TGTextButton *fTextButton782;
		TGTextButton *fTextButton783;

		TGLabel *fLabel755;
		TGLabel *fLabel756;
		TGLabel *fLabel757;

		TGTextButton *fTextButton869;
		TGTextEntry *fTextEntry1141;

	public:
		launcher();
		//languages 
		void EN();
		void IT();
		void DE();
		void FR();
		void RO();

		//navigation
		void disableAll();
		void enable1();
	    void enable2();
		void enableII();

		//start
		void start1();
		void start2();
		void initialCheck();
		void save();
		void gui();

		//output dir for saving histograms
		void setOutputDir();
		void ChangeFocus(); //changes focus by pressing TAB
		//additional 
		void Exit();
		void about();
		~launcher(void);
};
