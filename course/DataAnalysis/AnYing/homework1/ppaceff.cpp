{
 t1->SetAlias("p1ax","PPACF8[0][0]");
 t1->SetAlias("p1ay","PPACF8[0][1]");
 t1->SetAlias("p1aa","PPACF8[0][4]");

 TCut cp1ax="abs(p1ax)<125";
 TCut cp1ay="abs(p1ay)<75";
 TCut cp1aa="p1aa>0";
 
 // t1->Draw("p1aa",cp1aa);//1
 // t1->Draw("p1ax",cp1aa&&cp1ax);//2
  
 t1->SetAlias("p1bx","PPACF8[1][0]");
 t1->SetAlias("p1by","PPACF8[1][1]");
 t1->SetAlias("p1ba","PPACF8[1][4]");

 TCut cp1bx="abs(p1bx)<125";
 TCut cp1by="abs(p1by)<75";
 TCut cp1ba="p1ba>0";

 // t1->Draw("p2by",cp2by);//3
 // t1->Draw("p1ax",cp2by&&cp1ax);//4

 t1->SetAlias("p2ax","PPACF8[2][0]");
 t1->SetAlias("p2ay","PPACF8[2][1]");
 t1->SetAlias("p2aa","PPACF8[2][4]");
 
 TCut cp2ax="abs(p2ax)<125";
 TCut cp2ay="abs(p2ay)<75";
 TCut cp2aa="p2aa>0";

 t1->SetAlias("p2bx","PPACF8[3][0]");
 t1->SetAlias("p2by","PPACF8[3][1]");
 t1->SetAlias("p2ba","PPACF8[3][4]");

 TCut cp2bx="abs(p2bx)<125";
 TCut cp2by="abs(p2by)<75";
 TCut cp2ba="p2ba>0";

 t1->SetAlias("p3x","PPACF8[4][0]");
 t1->SetAlias("p3y","PPACF8[4][1]");
 t1->SetAlias("p3a","PPACF8[4][4]");

 TCut cp3x="abs(p3x)<50";
 TCut cp3y="abs(p3x)<50";
 TCut cp3a="p3a>0";

 // t1->Draw("p3y",cp3y);//5
 // t1->Draw("p1ax",cp3y&&cp1ax);//6




}
