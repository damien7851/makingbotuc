#ifndef I2C
#define I2C

#define TYPE_PATTE_MATERIEL 0x00
#define TWI_ADRESS 0x01
#define OVERRUN 0xFF
void initCom(void);
void DoCommand();
void PingCom();
void output();
/*typedef enum
{
    BUSY,
    READ,
    WRITE,
    ERROR
}status;*/
#endif
