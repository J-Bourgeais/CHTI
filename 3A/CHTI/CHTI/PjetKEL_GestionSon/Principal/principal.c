

#include "DriverJeuLaser.h"
#include "ServiceJeuLaser.h"
#include "DFT.h"
#include "Signal_4_12.h"
#include <stdint.h>


#define THRESHOLD 0x00030000

extern void GestionSon_callback(void);
extern void GestionSon_Start(void);
extern int PeriodeSonMicroSec;
int compteur=0;

short dma_buf[64];
int dft[64];
int Players[6];
int Scores[6]={0};
int previousShot[6]={0};

void Callback(void){
	ServJeuLASER_StartDMA();
		Players[0]=DFT(16, dma_buf)>>32;
		Players[1]=DFT(17, dma_buf)>>32;
		Players[2]=DFT(18, dma_buf)>>32;
		Players[3]=DFT(19, dma_buf)>>32;
		Players[4]=DFT(23, dma_buf)>>32;
		Players[5]=DFT(24, dma_buf)>>32;
	
		for(int i=0; i<6; i++){
			if (Players[i]>THRESHOLD){
				if (previousShot[i]!=1){
					GestionSon_Start();
					Scores[i]++;
				}
				previousShot[i]=1;
			} else {
				previousShot[i]=0;
			}
		}
	
		/*for (int i=0; i<64; i++){
			int value=(DFT(i, dma_buf)>>32);
			dft[i]=value;
		}*/
}

	

	
int main(void)
	{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

/* Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers */
CLOCK_Configure();

/* Configuration du son (voir ServiceJeuLaser.h) 
 Insérez votre code d'initialisation des parties matérielles gérant le son ....*/	
	
	ServJeuLASER_ADC_DMA(dma_buf);
	
	
	
	//SysTick_Config(5);
	ServJeuLASER_Systick_IT_Init(5000, 1, Callback);

	

ServJeuLASER_Son_Init(PeriodeSonMicroSec, 0, &(GestionSon_callback));
//PWM_Set_Value_TIM3_Ch3(*SortieSon);

	//ServJeuLASER_ADC_DMA(LeSignal);
	//ServJeuLASER_StartDMA();
	
Afficher();
	
	


//============================================================================	
	
	
while	(1)
	{
	}
}


