#include "stm32f10x.h"
#include "MyTimer.h"
#include "MyGPIO.h"

MyGPIO_Struct_typedef A5;

void ToggleLed(){
	GPIOA->ODR ^= (0x1 << A5.GPIO_Pin);
}

int main (void) {
	MyTimer_Struct_TypeDef Temp;
		
		Temp.Timer = TIM2;
		Temp.PSC = 5600;
		Temp.ARR = 2000;
		
		MyTimer_Base_Init(&Temp);
		
		MyTimer_Base_Start(Temp);
	
	A5.GPIO = GPIOA;
	A5.GPIO_Pin = 0;
	A5.GPIO_Conf = AltOut_Ppull;
	
	MyGPIO_Init(&A5);
	MyTimer_ActiveIT(Temp.Timer, 0, &ToggleLed);
	
	MyTimerSetPWMCycle(Temp.Timer, 1, 30);
	MyTimer_PMW(Temp.Timer, 1);
	
	do{
			
	}while(1);
}