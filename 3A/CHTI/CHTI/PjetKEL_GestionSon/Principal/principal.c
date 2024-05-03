

#include "DriverJeuLaser.h"
#include "ServiceJeuLaser.h"
#include "DFT.h"
#include "Signal_4_12.h"
#include <stdint.h>

extern void GestionSon_callback(void);
extern int PeriodeSonMicroSec;
int compteur=0;


short * dma_buf;
int dft[64];
void Callback(void){
		for (int i=0; i<64; i++){
			int value=DFT(i, dma_buf);
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
	
	SysTick_Config(5);
	SysTick(1, Callback);
	ServJeuLASER_Systick_IT_Init(5, 1, void(Callback*(void));

	
	ServJeuLASER_ADC_DMA(dma_buf);
	ServJeuLASER_StartDMA();
	
	

ServJeuLASER_Son_Init(PeriodeSonMicroSec, 0, &(GestionSon_callback));
//PWM_Set_Value_TIM3_Ch3(*SortieSon);

	ServJeuLASER_ADC_DMA(LeSignal);
	ServJeuLASER_StartDMA();
	
Afficher();
	
	


//============================================================================	
	
	
while	(1)
	{
	}
}


