#ifndef PATTE
#define PATTE

//#define PWM0 	0x10
#define LEDB 	0x20
#define LEDR 	0x40
#define LEDG 	0x80
#define R 0
#define G 1
#define B 2
//#define GENOU 	3
#define TIME_GAIN 268

#define ADC_HANCHEX 	0x42 //ADC2
#define ADC_HANCHEZ 	0x43 //ADC3
#define ADC_GENOU 		0x46 //ADC6
#define ADC_HANCHEY		0x47 //ADC7

#define MAX_CURRENT		500 //max => 900

void ConvertToPwm(unsigned short intensite, unsigned int color, unsigned int timems);
void waitposition();
void GenerationOfPwm(unsigned short numpwm);
void StartAdcConversion(unsigned short numpwm);
unsigned int GetCurrent(unsigned short numpwm);

void Stop();
void Unstop();

#endif
