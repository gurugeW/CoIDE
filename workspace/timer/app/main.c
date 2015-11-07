

//=============================================================================
// STM32VLDISCOVERY tutorial
// Lesson 3. Blinking with timer.
// Copyright : Radoslaw Kwiecien
// http://en.radzio.dxp.pl
// e-mail : radek(at)dxp.pl
//=============================================================================
#include "stm32f0xx.h"
#include "antilib_gpio.h"
//=============================================================================
// Defines
//=============================================================================
//#define LED_BLUE_GPIO GPIOC
#define LED_BLUE_PIN  8
//=============================================================================
// main function
//=============================================================================
int main(void)
{
 RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;  // enable clock for timer 3
 RCC->AHBENR  |= RCC_AHBENR_GPIOCEN;  // enable clock for port C
 RCC->AHBENR  |= RCC_AHBENR_GPIOAEN;  //                  port A

 GPIOC ->MODER |= (1<<16);     // enable PC pin 8 output
 GPIOC ->MODER |= (1<<18);     //               9 output

TIM3->PSC  = 7999;      // Set prescaler to 24 000 (PSC + 1)
TIM3->ARR = 1000;       // Auto reload value 1000
TIM3->CR1 = TIM_CR1_CEN;// Enable timer

while (1) {
if(TIM3->SR & TIM_SR_UIF) // if UIF flag is set
  {
  TIM3->SR &= ~TIM_SR_UIF; // clear UIF flag
  GPIOC->ODR ^= (1 << LED_BLUE_PIN); // toggle LED state
  }
}
}
//=============================================================================
// End of file

















/*
#include "stm32f0xx.h"

#define PORTA_PIN0  0


int main(void)
{

	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;  // enable clock for timer 3
    RCC->AHBENR  |= RCC_AHBENR_GPIOCEN;  // enable clock for port C
    RCC->AHBENR  |= RCC_AHBENR_GPIOAEN;  //                  port A

    GPIOC ->MODER |= (1<<16);     // enable PC pin 8 output
    GPIOC ->MODER |= (1<<18);     //               9 output
   // GPIOA ->MODER |= (0<< 0);     //        port A pin 0

    while(1)
    {
    if(GPIOA ->IDR & (1 << PORTA_PIN0))
     {
    GPIOC ->BSRR |= (1 << 8);
    GPIOC ->BSRR |= (1 << 9);
     }
    GPIOC ->BRR |= (1 << 8);
    GPIOC ->BRR |= (1 << 9);
    }
}
*/
