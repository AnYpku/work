#include "fit.C"
void run_fit(Int_t a){
    float lowchiso[10]={2,3,4,5,6,4,4,6,8,5};
    float highchiso[10]={4,5,6,7,8,9,10,10,10,12};
//	fit(25,30,lowchiso[a],highchiso[a]);
//	fit(30,35,lowchiso[a],highchiso[a]);
//	fit(35,40,lowchiso[a],highchiso[a]);
//	fit(40,45,lowchiso[a],highchiso[a]);
//	fit(45,50,lowchiso[a],highchiso[a]);
//	fit(50,60,lowchiso[a],highchiso[a]);
//	fit(60,80,lowchiso[a],highchiso[a]);
//	fit(80,120,lowchiso[a],highchiso[a]);
//	fit(120,400,lowchiso[a],highchiso[a]);
	fit(25,400,lowchiso[a],highchiso[a]);
}

int main(){
    for(Int_t i=0;i<10;i++){
	run_fit(i);}
	return 0;
}
