#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED
#define TAKEJETONPWM \
while (jetonPwm);\
jetonPwm = 1;
//uint8_t jetonPwm; //jeton pwm est remis à 0 lors d'un nouveau cycle pwm permet de bloquer une execution
void pwm_init();
uint8_t set_color(uint8_t R,uint8_t G,uint8_t B,uint8_t Alpha);

#endif // PWM_H_INCLUDED
