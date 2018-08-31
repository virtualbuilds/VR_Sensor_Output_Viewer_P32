
/* 
 * File:   ProbeCardSlavePoll.c
 * Author: bernabe
 *
 * Created on Sept 1, 2017, 11:36 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h> //interrupt
#include <plib.h>
#include "Ble_Prog_MX250.h"
#include <proc/p32mx250f128d.h>

unsigned char urx1;
unsigned char spi1;
int i;
int j;
int k;

unsigned char addr0;
unsigned char addr1;
unsigned char data0;
unsigned int readData;
unsigned int writeData;


void init_sys(void);
void configure_spi(void);
void configure_uart(void);
char uart_getc(void);
void uart_putc(unsigned char);
void uart_puts(char*);
unsigned char spi_transfer(unsigned char);
unsigned char spi_transfer2(char);
void ascii_print(unsigned char hex);

int main(int argc, char** argv) {
    init_sys();
    uart_puts("NFR Tracking: \n\r");
    uart_puts(">");
    GLED = 0;
    writeData = 0;
    readData = 0;
    while(1) {
//        switch (urx1) {
//            case '0' :
//                break;
//            case '1' :
//                spi_transfer(urx1);
//                break;
//            default : 
//                break;
//        }
        urx1 = uart_getc();
        switch (urx1) {
            case 'a' :
                CS1 = 0;
                spi_transfer(0x06); //WREN
//                spi_transfer(0xff); //WREN
//                spi_transfer(0x55); //WREN
//                spi_transfer(0x33); //WREN
                CS1 = 1;
                break;
            case 'b' :
                CS1 = 0;
                spi_transfer(0x04); //WRDIS
                CS1 = 1;
                break;
            case 'c' :
                CS1 = 0;
                spi_transfer(0x05); //RDSR
                 
                CS1 = 1;
                ascii_print(spi1);
                break;
            case 'd' :
                CS1 = 0;
                spi_transfer(0x01); //WRSR
                spi1 = spi_transfer(0x00);//read  
                CS1 = 1;
                ascii_print(spi1);     
                break;
            case 'e' :
                //nRF_PROG = 1; 
                CS1 = 0;
                    spi_transfer(0x03); //READ
                    spi_transfer(readData >> 8); //next address
                    spi_transfer(readData & 0xFF);
                    //spi1 = spi_transfer(0x00);
//                    CS1 = 1;
                for (readData = 0; readData < 256; readData++) {
//                    CS1 = 0;
//                    spi_transfer(0x06); //WREN
//                    CS1 = 1;
//                    ascii_print(spi1 >> 8);
//                    ascii_print(spi1 & 0xFF);
                    CS1 = 0;
//                    spi_transfer(0x03); //READ
//                    spi_transfer(readData >> 8); //next address
//                    spi_transfer(readData & 0xFF);
                    spi1 = spi_transfer(0x00);
                    //CS1 = 1;
                    ascii_print(spi1 >> 8);
                    ascii_print(spi1 & 0xFF);
                }
                CS1 = 1;
//                for (readData = 0; readData < 32768; readData++) {
//                addr0 = uart_getc();
//                addr1 = uart_getc();
//                    CS1 = 0;
//                    spi_transfer(0x03); //READ
////                    spi_transfer(readData >> 8); //next address
////                    spi_transfer(readData & 0xFF);
//                    spi_transfer(addr0); //next address
//                    spi_transfer(addr1);
//                    spi1 = spi_transfer(0x00);
//                    CS1 = 1;
//                    ascii_print(spi1 >> 8);
//                    ascii_print(spi1 & 0xFF);
//                    //for(i=0; i<222; i++){};
////                }
//                break;
            case 'f' :
                data0 = uart_getc();
                
                //for(i=0; i < 128; i++) {
                    CS1 = 0;
                    spi_transfer(0x06); //WREN
                    CS1 = 1;
                    CS1 = 0;
                    spi_transfer(0x02); //PROGRAM
                    spi_transfer(writeData >> 8); //next address
                    spi_transfer(writeData & 0xFF);
                    //for(j=0; j < 256; j++) {
//                        data0 = uart_getc();
                        spi_transfer(data0);
                    //}
                    CS1 = 1;
                    //writeData+= 256;
                    //for(k=0; k<48000; k++){};
                //}
//                CS1 = 1;
                writeData++;
                break;
            case 'g' :
                CS1 = 0;
                spi_transfer(0x52); //ERASE PAGE
                spi_transfer(uart_getc());
                CS1 = 1;
                break;
            case 'h' :
                CS1 = 0;
                spi_transfer(0x62); //ERASE ALL
                CS1 = 1;
                break;
            case 'i' :
                CS1 = 0;
                spi_transfer(0x89); //RDFPCR
                spi1 = spi_transfer(0x00);//read  
                CS1 = 1;
                ascii_print(spi1);     
                break;
            case 'j' :
                CS1 = 0;
                spi_transfer(0x84); //RDISIP
                CS1 = 1;
                break;
            case 'k' :
                CS1 = 0;
                spi_transfer(0x85); //RDISMB
                CS1 = 1;
                break;
            case 'l' :
                CS1 = 0;
                spi_transfer(0x86); //ENDEBUG
                CS1 = 1;
                break;
            case 'm' :
                nRF_RESET = 1;  
                break;
            case 'n' :
                nRF_RESET = 0; 
                break;
            case 'o' :
                nRF_PROG = 1; 
                break;
            case 'p' :
                nRF_PROG = 0;
                break;  
            case 'q' :
                nRF_RESET = 0;
                for(i=0; i<222; i++){};
                nRF_RESET = 1;
                for(i=0; i<22222; i++){};
                nRF_PROG = 1;
                for(i=0; i<222222; i++){};for(i=0; i<222222; i++){};
                CS1 = 0;
                spi_transfer(0x06); //WREN
                CS1 = 1;
                for(i=0; i<222; i++){};
                CS1 = 0;
                spi_transfer(0x62); //ERASE ALL
                CS1 = 1;
                for(i=0; i<222222; i++){};for(i=0; i<222222; i++){};for(i=0; i<222222; i++){};for(i=0; i<222222; i++){};
                CS1 = 0;
                spi_transfer(0x06); //WREN
                CS1 = 1;
                for(i=0; i<222; i++){};
                CS1 = 0;
                spi_transfer(0x02); //PROGRAM
                spi_transfer(0x00); //next address
                spi_transfer(0x00);
                //for(i=0; i < 256; i++) {
                    spi_transfer(0x45);
                //}
                CS1 = 1;
                //nRF_PROG = 0;
                for(i=0; i<2222; i++){};
                CS1 = 0;
                spi_transfer(0x03); //READ
                spi_transfer(0x00); //next address
                spi_transfer(0x00);
                spi1 = spi_transfer(0x00);
                CS1 = 1;
                ascii_print(spi1 >> 4);
                ascii_print(spi1 & 0xF);  
                //nRF_PROG = 0;
                break;
            case 'r' :
                uart_puts("-"); 
                break;
            case 's' :
                CS1 = 0;
                spi_transfer(0x01); //READ
                spi1 = spi_transfer(0x00);
                CS1 = 1;
                ascii_print(spi1 >> 4);
                ascii_print(spi1 & 0xF);
                break;
            case 't' :
                CS1 = 0;
                spi_transfer(0x80); //READ
                spi1 = spi_transfer(0x00);
                CS1 = 1;
                ascii_print(spi1 >> 4);
                ascii_print(spi1 & 0xF);
                break;
            case 'u' :
                CS1 = 0;
                spi_transfer(0x89); //READ
                spi1 = spi_transfer(0x00);
                CS1 = 1;
                ascii_print(spi1 >> 4);
                ascii_print(spi1 & 0xF);
                break;
            case 'v' :
                addr0 = uart_getc();
                addr1 = uart_getc();
                CS1 = 0;
                spi_transfer(0x03); //READ
                spi_transfer(addr0); //next address
                spi_transfer(addr1);
                spi1 = spi_transfer(0x00);
                CS1 = 1;
                ascii_print(spi1 >> 8);
                ascii_print(spi1 & 0xFF);
                break;
            case 'w' :
                writeData = 0;
                readData = 0;
                break;
            default : 
                break;
        }
//        spi_transfer(urx1);
//        for(i=0; i<222222; i++){}
        GLED ^= 1;  
    }
    return (EXIT_SUCCESS);
}

//void __ISR(_UART_1_VECTOR, IPL3AUTO) U1Interrupt(void) {   
//    if(U1STAbits.OERR | U1STAbits.FERR){      //Check for UART RX overrun error and reset RX if flagged
//		U1STACLR = 0x00000006;
//	}
//    urx1 = uart_getc();
//    uart_putc(urx1);
//    //uart_putc(spi_transfer(urx1));
//	IFS1CLR = 0x00000380;
//}

void init_sys(void) {
    //OSCCONbits.COSC = 3;  //= Primary Oscillator (POSC) with PLL module (XTPLL, HSPLL or ECPLL)
    TRISA = 0x0016; //RA4=U1RX, RA1=MISO1
    TRISB = 0x0000; //all output
    TRISC = 0x0000; //all output
    ANSELA = 0; ODCA = 0;//All pins to digital
    ANSELB = 0; ODCB = 0;
    ANSELC = 0; ODCC = 0;
    __builtin_disable_interrupts();
    configure_spi();
    configure_uart();
    nRF_RESET = 1; 
    nRF_PROG = 0; 
//    INTCONSET = _INTCON_MVEC_MASK;
//    __builtin_enable_interrupts();
}

void configure_uart(void){
    U1BRG = (SYS_FREQ/BAUD/4) - 1;     //PBCLK/BAUD/4 - 1

    U1MODEbits.BRGH = 1;
    U1MODEbits.PDSEL = 0b00;  // no parity
    U1MODEbits.STSEL =  0; // 1 stopbit
    U1MODEbits.UEN = 0b00;
    U1MODEbits.IREN = 0;
    U1MODEbits.SIDL = 0;
    U1MODEbits.RTSMD = 0;
    U1MODEbits.WAKE = 1;
    U1MODEbits.LPBACK = 0;
    U1MODEbits.RXINV = 0;
	U1MODEbits.ON = 1;
 
    U1STAbits.UTXINV = 0;
    U1STAbits.UTXEN = 1;
    U1STAbits.URXEN = 1;
    
    RPB4Rbits.RPB4R = 1; //U1TX
    U1RXRbits.U1RXR = 2; //RPA4
    
    IFS1CLR = 0x00000380;
//	IPC8bits.U1IP = 3; // U1 interrupt priority 3
//    IEC1SET = 0x00000180; // U1RXIE & U1EIE enable
    
    int i;
    for(i=0;i<40000000;i++){};
}

void configure_spi(void){
    RPB15Rbits.RPB15R = 3; //CS1
    RPB13Rbits.RPB13R = 3; //MOSI1
    SDI1Rbits.SDI1R = 0;   //MISO1 = RA1
    SpiChnOpen(1, SPICON_ON | SPICON_SSEN | SPICON_MSTEN, 8);
    SPI1CONbits.CKE = 1;
    SPI1CONbits.CKP = 0;
    CS1 = 0;
}

unsigned char spi_transfer(unsigned char sdata) {
    //CS1 = 0;
    SPI1BUF = sdata;
    while(!SPI1STATbits.SPIRBF); 
    //CS1 = 1;
    return SPI1BUF;
}

unsigned char spi_transfer2(char sdata) {
    //CS1 = 0;
    SPI2BUF = sdata;
    while(!SPI2STATbits.SPIRBF); 
    //CS1 = 1;
    return SPI2BUF;
}

void ascii_print(unsigned char hex) {
    switch(hex) {
        case 0x0 : uart_putc('0'); break;
        case 0x1 : uart_putc('1'); break;
        case 0x2 : uart_putc('2'); break;
        case 0x3 : uart_putc('3'); break;
        case 0x4 : uart_putc('4'); break;
        case 0x5 : uart_putc('5'); break;
        case 0x6 : uart_putc('6'); break;
        case 0x7 : uart_putc('7'); break;
        case 0x8 : uart_putc('8'); break;
        case 0x9 : uart_putc('9'); break;
        case 0xA : uart_putc('A'); break;
        case 0xB : uart_putc('B'); break;
        case 0xC : uart_putc('C'); break;
        case 0xD : uart_putc('D'); break;
        case 0xE : uart_putc('E'); break;
        case 0xF : uart_putc('F'); break;
    }
}

void uart_puts(char *str) {
    int i = 0;
    while(str[i]!='\0') {
        uart_putc(str[i]);
        i++;
    }
}

char uart_getc(void) {
    if(U1STAbits.OERR | U1STAbits.FERR){      //Check for UART RX overrun error and reset RX if flagged
		U1STACLR = 0x00000006;
	}
    while(!U1STAbits.URXDA);             // Wait for information to be received
    return U1RXREG;                      // Return received character
}

void uart_putc(unsigned char tx_byte) {
    while(U1STAbits.UTXBF);    // wait while UTXBF == 1.
    U1TXREG = tx_byte;    // Copy byte2send to the UxTXREG register
}