#include "CosSin_float.h"
#include "Signal_float.h"
#include <stdio.h>


#define M 64

float DFT(int k, float * x){
	float Re=0.0;
	float Im=0.0;
	for (int n=0;n<M;n++){
		int i = (k*n)%M;
		Re+=x[n]*(TabCos[i]);
		Im+=x[n]*(-TabSin[i]);
		
	
	}
	return Re*Re + Im*Im;

}

float Tab[M];
void Afficher(){
	float r;
	for (int e = 0; e<M; e++){
		r = DFT(e, LeSignal);
		Tab[e]=r;
	}
	//return Tab;

}
