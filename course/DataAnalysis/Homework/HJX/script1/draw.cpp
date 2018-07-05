{
	// F8PPACRawData
  t1->Draw("Ta>>hTa(4200,0,4200)");	//PPAC 1 Layer A Anode Time

  t1->Draw("Txl>>hTxl(4200,0,4200)");	//PPAC 1 Layer A X-Left Time
  t1->Draw("Txl-Txr>>hTxlTxr(5000,-5000,5000)");
  t1->Draw("Txl-Txr>>hcTxlTxr(5000,-5000,5000)",cxl&&cxr);
  t1->Draw("Txl+Txr>>hTsumx(5000,0,10000)");
  t1->Draw("Txl+Txr>>hTsumx(5000,0,10000)",cxl&&cxr);
  t1->Draw("Ttxl+Ttxr>>hTtsumx(5000,0,10000)",cxl&&cxr&&ca);
  t1->Draw("Ttxl+Ttxr>>hTtsumx(5000,0,10000)",cxl&&cxr&&ca&&cMultiHit);
  hTtsumx->SetLineColor(kGreen);
	hTtsumx->Draw();
	hTsumx->Draw("same");
  t1->Draw("Txl:Txr>>h2TxlTxr(1000,0,2500,1000,0,2500)",cxl&&cxr,"colz");
  t1->Draw("Ttxl:Ttxr>>h2TtxlTtxr(1000,0,2500,1000,0,2500)",cxl&&cxr&&ca,"colz");
  t1->Draw("Ttxl:Ttxr>>h2TtxlTtxr(1000,0,2500,1000,0,2500)",cxl&&cxr&&ca&&cmhx,"colz");

  t1->Draw("Tyd>>hTyd(4200,0,4200)");	//PPAC 1 Layer A Y-Down Time
  t1->Draw("Tyd-Tyu>>hTydTyu(5000,-5000,5000)");
  t1->Draw("Tyd-Tyu>>hcTydTyu(5000,-5000,5000)",cyd&&cyu);
  t1->Draw("Tyd+Tyu>>hTsumy(5000,0,10000)");
  t1->Draw("Tyd+Tyu>>hTsumy(5000,0,10000)",cyd&&cyu);
  t1->Draw("Ttyd+Ttyu>>hTtsumy(5000,0,10000)",cyd&&cyu&&ca);
  t1->Draw("Ttyd+Ttyu>>hTtsumy(5000,0,10000)",cyd&&cyu&&ca&&cmhy);
  hTtsumy->SetLineColor(kGreen);
	hTtsumy->Draw();
	hTsumy->Draw("same");
  t1->Draw("Tyd:Tyu>>h2TydTyu(1000,0,2500,1000,0,2500)",cyd&&cyu,"colz");
  t1->Draw("Ttyd:Ttyu>>h2TtydTtyu(1000,0,2500,1000,0,2500)",cyd&&cyu&&ca,"colz");
  t1->Draw("Ttyd:Ttyu>>h2TtydTtyu(1000,0,2500,1000,0,2500)",cyd&&cyu&&ca&&cmhy,"colz");

  t1->Draw("Ttxl-Ttxr:Ttyd-Ttyu>>h2txy(500,-1000,1000,500,-1000,1000)",cxl&&cxr&&ca&&cmhx&&cmhy,"colz");
 
	// PPACF8
	t1->Draw("1AX");
	t1->Draw("1AX",c1AX);
	t1->Draw("1AY");
	t1->Draw("1AY",c1AY);
	t1->Draw("1AZx");
	t1->Draw("1AZy");
	t1->Draw("1AA");
	t1->Draw("1AA",c1AA);
	t1->Draw("1AY:1AX",c1A,"colz");


 t1->Draw("ice:tof711>>h1(500,200,280,500,0,8000)",cf11pt&&cf7pt&&"ice>100","colz");//9.1
 t1->Draw("ice-20*(tof711-255):tof711>>(500,200,280,500,0,8000)",cf11pt&&cf7pt&&"ice>100","colz");//9.2
 t1->Draw("f9ppacx:tof711>>(400,230,280,500,-100,-130)",cf11pt&&cf7pt,"colz");//10.
 t1->Draw("f9ppacx:tof711-f9ppacx*0.06>>(400,230,280,500,-100,-130)",cf11pt&&cf7pt,"colz");//11

 t1->Draw("ice:tof711>>(500,200,280,500,0,8000)",cf11pt&&cf7pt&&"ice>100","colz");//12
 t1->Draw("ice:tof711-f9ppacx*0.06>>(500,200,360,500,0,8000)",cf11pt&&cf7pt&&"ice>100","colz")//13


 t1->Draw("f7pt:f7pq>>(300,-1.5,1.5,200,-50,150)",cf7pt&&cf7pq,"colz");//14.  

 t1->Draw("ic1>>hic1(400,0,18000)");//15.
 t1->Draw("ic1:ic2>>hic12(400,0,12000,400,0,12000)","","colz");//16.
 t1->Draw("ic1:ic2>>hic12a(400,0,500,400,0,500)","","colz");//17.
 t1->Draw("ic1-ic2>>(500,-5000,5000)",cic1&&cic2,"colz") ;//18.
 t1->Draw("ic1-ic2:ic3-ic4>>(500,-10000,10000,500,-10000,10000)",cic,"colz");//19.
}
