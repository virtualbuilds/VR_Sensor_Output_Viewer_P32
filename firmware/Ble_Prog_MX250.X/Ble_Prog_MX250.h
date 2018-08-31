/* 
 * File:   ProbeCardSlavePollInit.h
 * Author: bernabe
 *
 * Created on July 31, 2017, 9:43 AM
 */
//#include <proc/p32mx250f128d.h>
#ifndef BLE_PROG_MX250_H
#define	BLE_PROG_MX250_H

#ifdef	__cplusplus
extern "C" {
#endif

// Configuration Bit settings
// SYSCLK = 48 MHz (8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 48 MHz
// Primary Osc w/PLL (XT+,HS+,EC+PLL)
// WDT OFF
// INTERNAL CLOCK

#pragma config FPLLMUL = MUL_24, FPLLIDIV = DIV_2, FPLLODIV = DIV_2, FWDTEN = OFF
#pragma config POSCMOD = OFF, FNOSC = FRCPLL, FPBDIV = DIV_1
#pragma config OSCIOFNC = OFF            // CLKO Output Signal Active on the OSCO Pin (Enabled)

#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disabled)
#pragma config IESO = OFF               // Internal/External Switch Over (Disabled)
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

//// DEVCFG3 //EXTERNAL CLOCK 
//// USERID = No Setting
//#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
//#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
//
//// DEVCFG2
//#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
//#pragma config FPLLMUL = MUL_24         // PLL Multiplier (24x Multiplier)
//#pragma config FPLLODIV = DIV_2         // System PLL Output Clock Divider (PLL Divide by 2)
//
//// DEVCFG1
//#pragma config FNOSC = FRCPLL           // Oscillator Selection Bits (Fast RC Osc with PLL)
//#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disabled)
//#pragma config IESO = OFF               // Internal/External Switch Over (Disabled)
//#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
//#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
//#pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/1)
//#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
//#pragma config WDTPS = PS8192        // Watchdog Timer Postscaler (1:1048576)
//#pragma config WINDIS = OFF             // Watchdog Timer Window Enable (Watchdog Timer is in Non-Window Mode)
//#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))
//#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window Size is 25%)
//
//// DEVCFG0
//#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Disabled)
//#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
//#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
//#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
//#pragma config CP = OFF                 // Code Protect (Protection Disabled)

#define SYS_FREQ 			(48000000L)
#define BAUD                (460800)
    
#define GLED            PORTAbits.RA10
    
#define U1TX            PORTBbits.RB4   //pin10 fubrino
#define U1RX            PORTAbits.RA4   //pin9 fubrino
    
#define MOSI1           PORTBbits.RB13  //pin0 fubrino    
#define SCLK1           PORTBbits.RB14  //pin3 fubrino
#define CS1             PORTBbits.RB15  //pin4 fubrino
#define MISO1           PORTAbits.RA1   //pin6 fubrino
//#define CS1     PORTAbits.RA8
//    
//#define MOSI2           PORTBbits.RB13  //pin0 fubrino    
//#define SCLK2           PORTBbits.RB15  //pin4 fubrino
//#define CS2             PORTBbits.RB14  //pin3 fubrino
//#define MISO2           PORTAbits.RA2   //pin6 fubrino
    
#define nRF_RESET       PORTAbits.RA0   //pin5 fubrino
#define nRF_PROG        PORTAbits.RA7   //pin2 fubrino

char urx1_flag;
//char SCLK_EN;
//char i;
//char dump;
//unsigned int spidata1;
//unsigned int spidata2;
    
#ifdef	__cplusplus
}
#endif

#endif	/* BLE_PROG_MX250_H */

