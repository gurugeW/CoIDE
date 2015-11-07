

#include "stm32f0xx.h"
#include <math.h>
#include <stm32f0xx_gpio.h>

#define SW_USER_PIN  0

int main(void)
{
 volatile unsigned int i = 0;

 RCC -> AHBENR |= (1 << 19) ; // enable clock for port c
 RCC -> AHBENR |= (1 << 17);  // Enable clock for port A

 GPIOC -> MODER |= (1 << 16); // enable port c pin 8 as digital output
 GPIOC -> MODER |= (1 << 18);
 //RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
 int x = 5;

    while(1)
    {
 printf("%i \n", x);
if(GPIOA->IDR & (1 << SW_USER_PIN)) { //  check port A pin 0 press or not
     //GPIOC ->ODR |= ( 1 << 8); // turn on GPIOC pin 8 on
     GPIOC->BSRR = (1 << 9);
     GPIOC->BRR = (1 << 8);
     for(i = 0; i < 100000; i++);// delay

    // GPIOC ->ODR &= ~( 1 << 8); // turn on GPIOC pin 8 on
     GPIOC->BRR = (1 << 9);
     GPIOC->BSRR = (1 << 8);
     for(i = 0; i < 100000; i++);// delay

    }
x++;
  GPIOC->BRR = (1 << 8);
  GPIOC->BRR = (1 << 9);
}
}
