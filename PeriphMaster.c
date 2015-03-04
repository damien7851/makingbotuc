/*
 * PeriphMaster.c
 *
 * Created: 08/10/2014 18:35:19
 *  Author: Jonathan
 */


#include <avr/io.h>
#include <stdint.h>
#include "include/Init.h"
#include "include/PeriphMaster.h"
#include <avr/interrupt.h>
#include "include/pwm.h"
#include "include/isr.h"
#include <util/delay.h>
#include "include/I2C.h"



uint8_t btn = 0;







int main()
{
    cli();
     init();
     pwm_init();
     isr_init();
     initCom();
    sei();

   while(1)
   {

        set_color(255,0,0,255); //a priori 25ms d'execution
        _delay_ms(10);
        set_color(0,0,255,255); //a priori 25ms d'execution
        _delay_ms(10);
        set_color(255,255,255,0); //a priori 25ms d'execution
        _delay_ms(10);


   }
}
