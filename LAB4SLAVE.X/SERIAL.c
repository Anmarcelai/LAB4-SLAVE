#include <xc.h>
#include "SERIAL.h"
#define _XTAL_FREQ 4000000
void configSerial(int baudrate){
    
    TRISC = 0x80;
    
    PIE1bits.RCIE = 1;
    
    TXSTA=0b00100110;
    
    RCSTA=0b10010000;
    
    BAUDCTLbits.BRG16 = 1;
    
    if(baudrate == 9600){
        SPBRG = 103;
    } else if (baudrate == 10417){
        SPBRG = 95;
    } else if (baudrate == 19200){
        SPBRG = 51;
    } else if (baudrate == 57600){
        SPBRG = 16;
    }
}

void enviarSerial(char data){
    while (TXSTAbits.TRMT == 0){
       __delay_us(1);
    }
    TXREG=data;
   
}


