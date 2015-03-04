
/*****************************************************************************
*
* Atmel Corporation
*
* File              : main.c
* Compiler          : IAR EWAAVR 2.28a/3.10c
* Revision          : $Revision: 2516 $
* Date              : $Date: 2007-09-27 10:41:15 +0200 (to, 27 sep 2007) $
* Updated by        : $Author: mlarsson $
*
* Support mail      : avr@atmel.com
*
* Supported devices : All devices with a TWI module can be used.
*                     The example is written for the ATmega16
*
* AppNote           : AVR311 - TWI Slave Implementation
*
* Description       : Example of how to use the driver for TWI slave
*                     communication.
*
****************************************************************************/
/*! \page MISRA
 *
 * General disabling of MISRA rules:
 * * (MISRA C rule 1) compiler is configured to allow extensions
 * * (MISRA C rule 111) bit fields shall only be defined to be of type unsigned int or signed int
 * * (MISRA C rule 37) bitwise operations shall not be performed on signed integer types
 * As it does not work well with 8bit architecture and/or IAR

 * Other disabled MISRA rules
 * * (MISRA C rule 109) use of union - overlapping storage shall not be used
 * * (MISRA C rule 61) every non-empty case clause in a switch statement shall be terminated with a break statement
*/


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "include/TWI_slave.h"

// Sample TWI transmission commands
#define TWI_CMD_MASTER_WRITE 0x10
#define TWI_CMD_MASTER_READ  0x20

// The AVR can be waken up by a TWI address match from all sleep modes,
// But it only wakes up from other TWI interrupts when in idle mode.
// If POWER_MANAGEMENT_ENABLED is defined the device will enter power-down
// mode when waiting for a new command and enter idle mode when waiting
// for TWI receives and transmits to finish.
#define POWER_MANAGEMENT_ENABLED

// Compiler-independent macros (was previously IAR intrinsics)

#define SEI()     sei()
#define SLEEP()   sleep_cpu()
#define NOP()     __asm__ __volatile__ ("nop" ::)


// When there has been an error, this function is run and takes care of it
//unsigned char TWI_Act_On_Failure_In_Last_Transmission ( unsigned char TWIerrorMsg );




//end of atmel include code
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/I2C.h"
#include "include/Command.h"
#include <avr/interrupt.h>


//globale variable





void initCom(void)
{
//configuration fréquance I2C pas utile en slave
    TWBR = 0x02; //Set SCL Frequency to 400Khz
    TWSR &= !(1<<TWPS1) & !(1<<TWPS0); //SetPrescaler (for SCL frequency)

    // Initialise TWI module for slave operation. Include address and/or enable General Call.
    unsigned char TWI_slaveAddress = TWI_ADRESS;

  // Initialise TWI module for slave operation. Include address and/or enable General Call.
  TWI_Slave_Initialise( (unsigned char)((TWI_slaveAddress<<TWI_ADR_BITS) | (TRUE<<TWI_GEN_BIT) ));

    TWI_Start_Transceiver();
}

unsigned char getDataCom(unsigned char *pdata,unsigned char *pcmd,unsigned char msglength)
{
unsigned char* ptemp = malloc(msglength);

if (msglength>TWI_BUFFER_SIZE)
    return OVERRUN;
else
    TWI_Get_Data_From_Transceiver(ptemp,msglength);
    pcmd = ptemp[0];
    pdata = memcpy(pdata,&ptemp[1],msglength-1);
    free(ptemp);

return 0;

    //ajouter ici le traitement d'erreur
}

/*TWI_Start_Transceiver( );

  for(;;)
  {
    if ( ! TWI_Transceiver_Busy() )
    {
      if ( TWI_statusReg.RxDataInBuf )
      {
        TWI_Get_Data_From_Transceiver(&temp, 1);
        PORTB = temp;
      }
      temp = PORTB + 1;
      TWI_Start_Transceiver_With_Data(&temp, 1);
    }
    __no_operation();   // Do something else while waiting
*/

/*void PingCom()
{
if ( ! TWI_Transceiver_Busy() )
{
    TWI_Start_Transceiver_With_Data()

}

void output()
{
    Fif
}*/
