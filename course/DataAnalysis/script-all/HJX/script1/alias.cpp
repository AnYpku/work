{ 
	// F8PPACRawData
  t1->SetAlias("Txl","F8PPACRawData[0][0]");	//PPAC 1 Layer A X-Left	Time
  t1->SetAlias("Txr","F8PPACRawData[0][1]");	//PPAC 1 Layer A X-Right Time
  t1->SetAlias("Tyd","F8PPACRawData[0][2]");	//PPAC 1 Layer A Y-Left Time
  t1->SetAlias("Tyu","F8PPACRawData[0][3]");	//PPAC 1 Layer A Y-Right Time
  t1->SetAlias("Ta","F8PPACRawData[0][4]");		//PPAC 1 Layer A Anode Time
  t1->SetAlias("Qxl","F8PPACRawData[0][5]");	//PPAC 1 Layer A X-Left	Q
  t1->SetAlias("Qxr","F8PPACRawData[0][6]");	//PPAC 1 Layer A X-Right Q
  t1->SetAlias("Qyd","F8PPACRawData[0][7]");	//PPAC 1 Layer A Y-Left Q
  t1->SetAlias("Qyu","F8PPACRawData[0][8]");	//PPAC 1 Layer A Y-Right Q
  t1->SetAlias("Qa","F8PPACRawData[0][9]");		//PPAC 1 Layer A Anode Q

  t1->SetAlias("Ttxl","Txl-Ta");
  t1->SetAlias("Ttxr","Txr-Ta");
  t1->SetAlias("Ttyd","Tyd-Ta");
  t1->SetAlias("Ttyu","Tyu-Ta");
  t1->SetAlias("sum","Txl+Txr");

  TCut cxl="Txl>0&&Txl<4000";
  TCut cxr="Txr>0&&Txr<4000";
  TCut cyu="Tyu>0&&Tyu<4000";
  TCut cyd="Tyd>0&&Tyd<4000";
  TCut ca="Ta>0&&Ta<4000";
  TCut cf8ppac=cxl&&cxr&&cyu&&cyd&&ca;
	
	TCut cmhx="abs(Ttxl+Ttxr-1171.8)<24";
	TCut cmhy="abs(Ttyd+Ttyu-662)<27.1";
	
	// PPACF8
	t1->SetAlias("1AX","PPACF8[0][0]");		//PPAC 1 Layer A X mm
	t1->SetAlias("1AY","PPACF8[0][1]");		//PPAC 1 Layer A Y mm
	t1->SetAlias("1AZx","PPACF8[0][2]");	//PPAC 1 Layer A Z for X direction mm
	t1->SetAlias("1AZy","PPACF8[0][3]");	//PPAC 1 Layer A Z for Y direction mm
	t1->SetAlias("1AA","PPACF8[0][4]");		//PPAC 1 Layer A Anode time ns

	TCut c1AX="1AX>-999";
	TCut c1AY="1AY>-999";
	TCut c1AA="1AA>-999";
	TCut c1A=c1AX&&c1AY&&c1AA;

	// F3Plastic
  t1->SetAlias("f3pt1","F3PlaRawData[0]");//time
  t1->SetAlias("f3pt2","F3PlaRawData[1]");
  t1->SetAlias("f3pq1","F3PlaRawData[2]");//charge
  t1->SetAlias("f3pq2","F3PlaRawData[3]");

  t1->SetAlias("f3pt","f3pt1-f3pt2");
  t1->SetAlias("f3pq","TMath::Log(f3pq1/f3pq2)");
  
  t1->SetAlias("f3t","0.5*(f3pt1+f3pt2)");
  t1->SetAlias("f3q","sqrt(f3pq1*f3pq2)");

  TCut cf3pt="f3pt1>0&&f3pt1<4000&&f3pt2>0&&f3pt2<4000";
  TCut cf3pq="f3pq1>20&&f3pq1<4000&&f3pq2>20&&f3pq2<4000";

	
	// F7Plastic
  t1->SetAlias("f7pt1","F7PlaRawData[0]");//time
  t1->SetAlias("f7pt2","F7PlaRawData[1]");
  t1->SetAlias("f7pq1","F7PlaRawData[2]");//charge
  t1->SetAlias("f7pq2","F7PlaRawData[3]");

  t1->SetAlias("f7pt","f7pt1-f7pt2");
  t1->SetAlias("f7pq","TMath::Log(f7pq1/f7pq2)");

  t1->SetAlias("f7t","0.5*(f7pt1+f7pt2)");
  t1->SetAlias("f7q","sqrt(f7pq1*f7pq2)");

  TCut cf7pt="f7pt1>0&&f7pt1<4000&&f7pt2>0&&f7pt2<4000";
  TCut cf7pq="f7pq1>20&&f7pq1<4000&&f7pq2>20&&f7pq2<4000";

	
	// F11Plastic
  t1->SetAlias("f11pt1","F11PlaRawData[0]");//time
  t1->SetAlias("f11pt2","F11PlaRawData[1]");
  t1->SetAlias("f11pq1","F11PlaRawData[2]");//charge
  t1->SetAlias("f11pq2","F11PlaRawData[3]");

  t1->SetAlias("f11pt","f11pt1-f11pt2");
  t1->SetAlias("f11pq","TMath::Log(f11pq1/f11pq2)");

  t1->SetAlias("f11t","0.5*(f11pt1+f11pt2)");
  t1->SetAlias("f11q","sqrt(f11pq1*f11pq2)");

  TCut cf11pt="f11pt1>0&&f11pt1<4000&&f11pt2>0&&f11pt2<4000";
  TCut cf11pq="f11pq1>20&&f11pq1<4000&&f11pq2>20&&f11pq2<4000";
	
	
	// Ion Chamber   
  t1->SetAlias("ic0","F11ICRawData[0]");
  t1->SetAlias("ic1","F11ICRawData[1]");
  t1->SetAlias("ic2","F11ICRawData[2]");
  t1->SetAlias("ic3","F11ICRawData[3]");
  t1->SetAlias("ic4","F11ICRawData[4]");
  t1->SetAlias("ic5","F11ICRawData[5]");
  t1->SetAlias("ice","TMath::Power(ic1*ic2*ic3*ic4*ic5,0.2)");

  TCut cic1="ic1>200&&ic1<16000";
  TCut cic2="ic2>150&&ic2<16000";
  TCut cic3="ic3>170&&ic3<16000";
  TCut cic4="ic4>200&&ic4<16000";
  TCut cic5="ic5>140&&ic5<16000";
  TCut cic = cic1 && cic2 && cic3 && cic4 && cic5;

	
	//TOF
  t1->SetAlias("tof37","TOF[1]");
  t1->SetAlias("f5ppacx","FPPosition[5][0]");
  t1->SetAlias("f5ppacy","FPPosition[5][1]");

  t1->SetAlias("f7ppacx","FPPosition[7][0]");
  t1->SetAlias("f7ppacy","FPPosition[7][1]");
  
  t1->SetAlias("tof37","TOF[1]");
  t1->SetAlias("tof711","TOF[2]");
  t1->SetAlias("f9ppacx","FPPosition[9][0]");
  t1->SetAlias("f9ppacy","FPPosition[9][1]");
}
