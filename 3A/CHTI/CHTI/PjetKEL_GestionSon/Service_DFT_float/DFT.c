#include "CosSin_Fract_1_15.h"
#include "Signal_4_12.h"
#include <stdio.h>
#include <math.h>


#define M 64

long long int DFT(short k, short * x){
	long long int Re=0.0;
	long long int Im=0.0;
	for (int n=0;n<M;n++){
		int i = (k*n)%M;
		Re+=(x[n]*(TabCos[i]));
		Im+=x[n]*(-TabSin[i]);
		
	
	}
	return Re*Re + Im*Im;

}

//int Tab1[M];
long long int Tab1[M];
float Tab[M];
void Afficher(){
	long long int r;
	for (short e = 0; e<M; e++){
		Tab1[e] = DFT(e, (short *)LeSignal);// >> 32;
		//Tab[e]=r/pow(2,27);
		
	}
	//return Tab;

}
