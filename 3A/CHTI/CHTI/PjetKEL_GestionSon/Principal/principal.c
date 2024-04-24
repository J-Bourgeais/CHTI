

#include "DriverJeuLaser.h"
#include "ServiceJeuLaser.h"
#include "DFT.h"

extern void GestionSon_callback(void);
extern int PeriodeSonMicroSec;
int compteur=0;

//extern (unsigned int)* SortieSon;

	
int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

/* Apr�s ex�cution : le coeur CPU est clock� � 72MHz ainsi que tous les timers */
CLOCK_Configure();

/* Configuration du son (voir ServiceJeuLaser.h) 
 Ins�rez votre code d'initialisation des parties mat�rielles g�rant le son ....*/	

ServJeuLASER_Son_Init(PeriodeSonMicroSec, 0, &(GestionSon_callback));
//PWM_Set_Value_TIM3_Ch3(*SortieSon);
	
Afficher();
	
	


//============================================================================	
	
	
while	(1)
	{
	}
}


