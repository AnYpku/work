#include <iostream>
#include "TFile.h"
#include "TTree.h"

using namespace std;

void efficiency() {
	
	TFile *f = new TFile("/home/data/students2018/JinYu/Homework1_v2/v1_interpreter/run87PPACF8.root","read");
	TTree *t1 = (TTree*)f->Get("t1");
	
	//Hw1生成的root文件中，PPACFlag[5][3]表示5个PPAC的x、y、阳极板是否有效
	//后面判断条件中的PPACFlag[4][2]即PPAC3的阳极板，所有效率均以它作参考
	Bool_t PPACFlag[5][3];
	TBranch *pFlag = t1->GetBranch("PPACFlag");
	pFlag->SetAddress(PPACFlag);
	
	//定义Effum变量，记录5个PPAC的x、y极板以及xy极板和PPAC3阳极板
	//同时探测到有效信号的事件数(分子)
	Int_t EffNum[5][3] = {{0}};
	Int_t p3Anode = 0; //PPAC3的阳极板探测到有效信号的事件数(分母)
	Float_t eff[5][3];
	TString ppac[5] = {"1A","1B","2A","2B","3"};

	Long64_t nentries = t1->GetEntries();
	for(Long64_t jentry=0;jentry<nentries;jentry++) {
		pFlag->GetEntry(jentry);

		Bool_t p3a = PPACFlag[4][2]; //修改Flag可以选择其他极板作分母
		if(p3a) p3Anode++;

		for(Int_t i=0;i<5;i++) {
			if(PPACFlag[i][0]&&p3a) EffNum[i][0]++;
			if(PPACFlag[i][1]&&p3a) EffNum[i][1]++;
			if(PPACFlag[i][0]&&PPACFlag[i][1]&&p3a) EffNum[i][2]++;
		}
	}

	for(Int_t i=0;i<5;i++) {

		for(Int_t j=0;j<3;j++) eff[i][j] = EffNum[i][j]*1.0 / p3Anode;

		cout << "PPAC" << ppac[i] << ":" << endl;
		cout << "x:  " << EffNum[i][0] << "/" << p3Anode << "=" << eff[i][0] << endl;
		cout << "y:  " << EffNum[i][1] << "/" << p3Anode << "=" << eff[i][1] << endl;
		cout << "xy: " << EffNum[i][2] << "/" << p3Anode << "=" << eff[i][2] << endl;
		cout << endl;
	}
}
