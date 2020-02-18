#include <xc.h>
#include "ADC.h"

unsigned int configuracionADC(unsigned char FOSC, unsigned char channel){
    //ADC
    INTCONbits.PEIE=1; //
    PIE1bits.ADIE = 1;
    PIR1bits.ADIF=0; // Clear Bandera ADC
    ADCON1bits.ADFM=0; // Pines significativos en ADRESH
    ADCON1bits.VCFG1=0; // Referencia a Tierra
    ADCON1bits.VCFG0=0; // Referencia a Tierra
    ADCON0bits.ADON=1;
    
    switch (FOSC){
        case 0:
            ADCON0bits.ADCS1=0;//
            ADCON0bits.ADCS0=0;// Fosc/2
            break;
        case 1:
            ADCON0bits.ADCS1=0;//
            ADCON0bits.ADCS0=1;// Fosc/8
            break;
        case 2:
            ADCON0bits.ADCS1=1;//
            ADCON0bits.ADCS0=0;// Fosc/32
            break;
        case 3:
            ADCON0bits.ADCS1=1;//
            ADCON0bits.ADCS0=1;// Frc
            break;
    }
    switch (channel){
        case 0:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            ANSELbits.ANS0=1; // RA0 como pin analógico
            break;
        case 1:
            ADCON0bits.CHS0 = 1;
            ADCON0bits.CHS1 = 0;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            ANSELbits.ANS1=1; // RA1 como pin analógico
            break;
        case 2:
            ADCON0bits.CHS0 = 0;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            ANSELbits.ANS2=1; // RA2 como pin analógico
            break;
        case 3:
            ADCON0bits.CHS0 = 1;
            ADCON0bits.CHS1 = 1;
            ADCON0bits.CHS2 = 0;
            ADCON0bits.CHS3 = 0;
            ANSELbits.ANS3=1; // RA3 como pin analógico
            break;
    }
    ADCON0bits.GO_DONE=1;
    INTCONbits.GIE = 1;
}



