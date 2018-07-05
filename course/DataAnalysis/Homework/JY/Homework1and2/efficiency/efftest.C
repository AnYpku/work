#include <iostream>
#include "TFile.h"
#include "TTree.h"

using namespace std;

void efftest() {
	
	TFile *f = new TFile("/home/data/students2018/JinYu/Homework1_v2/v1_interpreter/run87PPACF8.root","read");
	TTree *t1 = (TTree*)f->Get("t1");
	
	//Hw1生成的root文件中，PPACFlag[5][3]表示5个PPAC的x、y、阳极板是否有效
	Bool_t PPACFlag[5][3];
	TBranch *pFlag = t1->GetBranch("PPACFlag");
	pFlag->SetAddress(PPACFlag);
	
	//定义Effum变量，记录PPAC1A的x极板与其他极板同时探测到有效信号的事件数(分子)
	Int_t EffNum[5][3] = {{0}};
	Int_t Num[5][3] = {{0}}; //每个极板探测到有效信号的事件数(分母)
	Float_t eff[5][3];
	TString ppac[5] = {"1A","1B","2A","2B","3"};

	Long64_t nentries = t1->GetEntries();
	for(Long64_t jentry=0;jentry<nentries;jentry++) {
		pFlag->GetEntry(jentry);

		Bool_t p1ax = PPACFlag[0][0];

		for(Int_t i=0;i<5;i++) {
			for(Int_t j=0;j<3;j++) {
				if(PPACFlag[i][j]&&p1ax) EffNum[i][j]++;
				if(PPACFlag[i][j]) Num[i][j]++;
			}
		}
	}

	for(Int_t i=0;i<5;i++) {

		for(Int_t j=0;j<3;j++) eff[i][j] = EffNum[i][j]*1.0 / Num[i][j];

		cout << "PPAC" << ppac[i] << ":" << endl;
		cout << "x: " << EffNum[i][0] << "/" << Num[i][0] << "=" << eff[i][0] << endl;
		cout << "y: " << EffNum[i][1] << "/" << Num[i][1] << "=" << eff[i][1] << endl;
		cout << "a: " << EffNum[i][2] << "/" << Num[i][2] << "=" << eff[i][2] << endl;
		cout << endl;
	}
}
