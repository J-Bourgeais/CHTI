

#include "DriverJeuLaser.h"
#include "ServiceJeuLaser.h"
#include "DFT.h"
#include "Signal_4_12.h"
#include <stdint.h>

extern void GestionSon_callback(void);
extern int PeriodeSonMicroSec;
int compteur=0;

short dma_buf[64];
int dft[64];
void Callback(void){
	ServJeuLASER_StartDMA();
		for (int i=0; i<64; i++){
			int value=(DFT(i, dma_buf)>>32);
			dft[i]=value;
		}
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


