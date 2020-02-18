/* 
 * File:   ADC.h
 * Author: Andrea Marcela Ixquiac Madrigales 17285
 *
 * Created on February 4, 2020, 8:05 AM
 */

#ifndef ADC_H
#define	ADC_H

unsigned char adc = 0;
unsigned char disp1 = 15;
unsigned char disp2 = 1;
int ncompleto =0;
unsigned int configuracionADC(unsigned char FOSC, unsigned char channel);
void readADC(void);

#endif	/* ADC_H */
//ACA FUNCIONA