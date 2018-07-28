#include "TH1F.h"
#include "TMath.h"
#include <vector> 

TList* list_files(const char *dirname) {
    TSystemDirectory dir(dirname, dirname);
    TList *files = dir.GetListOfFiles();
    TList *out_files = new TList();
    if (files) {
        TSystemFile *file;
        TString fname;
        TIter next(files);
        while ((file=(TSystemFile*)next())) {
            fname = file->GetName();
            if (!file->IsDirectory() && fname.EndsWith(".root") && fname != "output.root") {
                cout << fname.Data() << endl;
                out_files->AddLast(file);
            }
        }
    }
    return out_files;
}


void root_combine(){
    
    TFile *f = new TFile("output.root","RECREATE");

    vector< TH1F* > sample; 

    TList* files = list_files(".");
    TIter next(files);
    while ((file=(TSystemFile*)next())) {
        cout << "Processing: " << file->GetName() << endl;
		TFile *infile=new TFile(file->GetName());
		TH1F *hnew = (TH1F*)hist->Clone("hnew");
		sample.push_back(hnew);
    }

    TH1F *hns=new TH1F("hns","Number of samples",30,0,31);
    TH1F *master = (TH1F*)sample.at(0)->Clone("master");

    for(Int_t j=0;j<sample.size();j++){


		master->SetTitle("");
		master->SetXTitle("Mass K-#pi [MeV/c^{2}]");

		cout << "Number of events in sample: " << j << " " << sample[j]->GetEntries() << endl;
		hns->Fill(sample[j]->GetEntries());
		
		master->Add(sample[j]);
		master->Draw("e");

		Float_t max=master->GetMaximum();
		N=master->GetEntries();

		cout << max << endl;

		TPaveText *pt = new TPaveText(.1,.7,.4,.9,"NDC");
	//	pt->SetFillColor(18);
		pt->SetTextFont(62); //20 times new roman
		pt->SetTextColor(2);
		pt->AddText("Number of canidates");
		pt->AddText(TString::Itoa(N,10));
		pt->Draw();

		c1->Update();
		c1->Print("plot.gif+100");
		
		c1->WaitPrimitive();	
	
    }

    hns->Draw();
    c1->Print("EventsPerSample.gif");

}
