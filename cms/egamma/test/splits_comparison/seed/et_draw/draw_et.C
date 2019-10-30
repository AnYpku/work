Double_t etabins[7]={0,0.5,1.0,1.4442,1.566,2.0,2.5};
void draw(TString name,TString region){
    TFile* file = new TFile(name+"eta.root"); 
    TH1D* het_ele[6];
    TH1D* het_eghlt[6];
    vector<double> ymax;
    vector<int> fColors;
    fColors.push_back(kGreen+1);
    fColors.push_back(kBlue);
    fColors.push_back(kRed);
    for(int i=0;i<6;i++){
        if(i==3) continue;
        het_ele[i]=(TH1D*)file->Get(Form("hclusEt_ele_%i",i));
        het_eghlt[i]=(TH1D*)file->Get(Form("het_eghlt_%i",i));
    }
    TLegend* l1 = new TLegend(0.6,0.6,0.95,0.9);
    TLegend* l2 = new TLegend(0.6,0.3,0.95,0.6);
    l1->SetTextSize(0.065);
    l2->SetTextSize(0.065);
    if(region.Contains("barrel")){
        TCanvas* c1 = new TCanvas("c1","E_{T} comparison in the barrel",900,900);
        for(int i=0;i<6;i++){
            if(i==3) continue;
            if(i<3){
                if(het_ele[i]->Integral()==0) het_ele[i]->Scale(1.);
                else het_ele[i]->Scale(1./het_ele[i]->Integral());
                if(het_eghlt[i]->Integral()==0) het_eghlt[i]->Scale(1.);
                else het_eghlt[i]->Scale(1./het_eghlt[i]->Integral());

                ymax.push_back(het_ele[i]->GetMaximum());
                ymax.push_back(het_eghlt[i]->GetMaximum());
                het_ele[i]->SetTitle("E_{T} comparison in the barrel;E_{T};Normalized");
                het_ele[i]->SetLineColor(fColors[i]);
                het_ele[i]->SetLineWidth(3);
                het_ele[i]->SetLineStyle(2);
                het_ele[i]->GetYaxis()->SetTitleSize(0.07);
                het_ele[i]->GetYaxis()->SetTitleOffset(0.47);

                het_eghlt[i]->SetLineColor(fColors[i]);
                het_eghlt[i]->SetLineWidth(3);
                het_eghlt[i]->SetLineStyle(1);
                het_eghlt[i]->GetYaxis()->SetTitleSize(0.07);
                het_eghlt[i]->GetYaxis()->SetTitleOffset(0.47);
                l1->AddEntry(het_ele[i],Form("reco %0.2f<eta<%0.2f",etabins[i],etabins[i+1]));
                l2->AddEntry(het_eghlt[i],Form("HLT %0.2f<eta<%0.2f",etabins[i],etabins[i+1]));

            }
        }
        sort(ymax.begin(), ymax.end(), greater<double>());
        double Ymax = ymax[0];
        TPad *top_pad=new TPad("top_pad", "top_pad",0,0.35, 1.0, 1.0);
        top_pad->Draw();
        top_pad->cd();
        top_pad->SetBottomMargin(0.0);
        for(int i=0;i<3;i++){
            het_ele[i]->GetYaxis()->SetRangeUser(0,Ymax+0.15);
            het_eghlt[i]->GetYaxis()->SetRangeUser(0,Ymax);
            het_ele[i]->Draw("EP same");
            het_eghlt[i]->Draw("EP same");
        }
        l1->Draw();
        l2->Draw();
        c1->cd();
        TH1D*h3[3];
        TPad *bottom_pad=new TPad("bottom_pad", "bottom_pad", 0, 0.1, 1.0, 0.35);
        bottom_pad->Draw();
        bottom_pad->cd();
        bottom_pad->SetTopMargin(0.0);
        double xmin,xmax;
        xmin=het_ele[0]->GetXaxis()->GetXmin();
        xmax=het_ele[0]->GetXaxis()->GetXmax();
        TLine* line = new TLine(xmin,1.,xmax,1);
        line->SetLineColor(kRed);
//        bottom_pad->SetBottomMargin(0.1);
        for(int i=0;i<3;i++){
           h3[i]=(TH1D*)het_ele[i]->Clone();
           h3[i]->Divide(het_eghlt[i]);
           h3[i]->GetYaxis()->SetRangeUser(0.5,1.5);
           h3[i]->SetLineStyle(1);
           h3[i]->Draw("EP SAME");
           h3[i]->SetTitle("");
           h3[i]->GetYaxis()->SetTitle("Reco/HLT");
           h3[i]->GetXaxis()->SetTitle("E_{T}");
           h3[i]->GetXaxis()->SetTitleOffset(0.9);
           h3[i]->GetYaxis()->SetTitleOffset(0.22);
           h3[i]->GetXaxis()->SetTitleSize(0.15);
           h3[i]->GetYaxis()->SetTitleSize(0.15);
           h3[i]->GetXaxis()->SetLabelSize(0.12);
           h3[i]->GetYaxis()->SetLabelSize(0.1);
           h3[i]->SetLineWidth(2);
         }
        line->SetLineWidth(1);
        line->Draw();
        c1->Draw();
        c1->SaveAs(name+"_EtComp_"+region+".eps");
    }
    if(region.Contains("endcap")){
        TCanvas* c1 = new TCanvas("c1","E_{T} comparison in the endcap",900,900);
        for(int i=0;i<6;i++){
            if(i==3) continue;
            if(i>3){
                if(het_ele[i]->Integral()==0) het_ele[i]->Scale(1.);
                else het_ele[i]->Scale(1./het_ele[i]->Integral());
                if(het_eghlt[i]->Integral()==0) het_eghlt[i]->Scale(1.);
                else het_eghlt[i]->Scale(1./het_eghlt[i]->Integral());

                ymax.push_back(het_ele[i]->GetMaximum());
                ymax.push_back(het_eghlt[i]->GetMaximum());
                het_ele[i]->SetTitle("E_{T} comparison in the endcap;E_{T};Normalized");
                het_ele[i]->SetLineColor(fColors[i-3]);
                het_ele[i]->SetLineWidth(3);
                het_ele[i]->SetLineStyle(2);
                het_ele[i]->GetYaxis()->SetTitleSize(0.07);
                het_ele[i]->GetYaxis()->SetTitleOffset(0.47);

                het_eghlt[i]->SetLineColor(fColors[i-3]);
                het_eghlt[i]->SetLineWidth(3);
                het_eghlt[i]->SetLineStyle(1);
                het_eghlt[i]->GetYaxis()->SetTitleSize(0.07);
                het_eghlt[i]->GetYaxis()->SetTitleOffset(0.47);
                l1->AddEntry(het_ele[i],Form("reco %0.2f<eta<%0.2f",etabins[i],etabins[i+1]));
                l2->AddEntry(het_eghlt[i],Form("HLT %0.2f<eta<%0.2f",etabins[i],etabins[i+1]));

            }
        }
        sort(ymax.begin(), ymax.end(), greater<double>());
        double Ymax = ymax[0];
        TPad *top_pad=new TPad("top_pad", "top_pad",0,0.35, 1.0, 1.0);
        top_pad->Draw();
        top_pad->cd();
        top_pad->SetBottomMargin(0.0);
        for(int i=4;i<6;i++){
            het_ele[i]->GetYaxis()->SetRangeUser(0,Ymax+0.15);
            het_eghlt[i]->GetYaxis()->SetRangeUser(0,Ymax);
            het_ele[i]->Draw("EP same");
            het_eghlt[i]->Draw("EP same");
        }
        l1->Draw();
        l2->Draw();
        c1->cd();
        TH1D*h3[2];
        TPad *bottom_pad=new TPad("bottom_pad", "bottom_pad", 0, 0.1, 1.0, 0.35);
        bottom_pad->Draw();
        bottom_pad->cd();
        bottom_pad->SetTopMargin(0.0);
        double xmin,xmax;
        xmin=het_ele[0]->GetXaxis()->GetXmin();
        xmax=het_ele[0]->GetXaxis()->GetXmax();
        TLine* line = new TLine(xmin,1.,xmax,1);
        line->SetLineColor(kRed);
//        bottom_pad->SetBottomMargin(0.1);
        for(int i=0;i<2;i++){
           h3[i]=(TH1D*)het_ele[i+4]->Clone();
           h3[i]->Divide(het_eghlt[i+4]);
           h3[i]->GetYaxis()->SetRangeUser(0.5,1.5);
           h3[i]->SetLineStyle(1);
           h3[i]->Draw("EP SAME");
           h3[i]->SetTitle("");
           h3[i]->GetYaxis()->SetTitle("Reco/HLT");
           h3[i]->GetXaxis()->SetTitle("E_{T}");
           h3[i]->GetXaxis()->SetTitleOffset(0.9);
           h3[i]->GetYaxis()->SetTitleOffset(0.22);
           h3[i]->GetXaxis()->SetTitleSize(0.15);
           h3[i]->GetYaxis()->SetTitleSize(0.15);
           h3[i]->GetXaxis()->SetLabelSize(0.12);
           h3[i]->GetYaxis()->SetLabelSize(0.1);
           h3[i]->SetLineWidth(2);
         }
        line->SetLineWidth(1);
        line->Draw();
        c1->Draw();
        c1->SaveAs(name+"_EtComp_"+region+".eps");
    }


}
int draw_et(){
    gStyle->SetOptStat(0);
    gStyle->SetPadGridX(1);
    gStyle->SetPadGridY(1);
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetPadTopMargin(0.07);
    gStyle->SetPadBottomMargin(0.3);
    gStyle->SetPadRightMargin(0.05);
    gStyle->SetPadLeftMargin(0.14);
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetAxisColor(1, "XYZ");
    gStyle->SetStripDecimals(kTRUE);
    gStyle->SetTickLength(0.3, "XYZ");
    gStyle->SetNdivisions(510, "XYZ");
    TString name1 = "50_120";
    TString name2 = "120_200";
    draw(name1,"barrel");
    draw(name1,"endcap");
    draw(name2,"barrel");
    draw(name2,"endcap");

return 1;
}
