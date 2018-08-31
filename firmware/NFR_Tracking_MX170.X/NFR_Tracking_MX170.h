/* 
 * File:   ProbeCardSlavePollInit.h
 * Author: bernabe
 *
 * Created on July 31, 2017, 9:43 AM
 */
//#include <proc/p32mx170f256d.h>
#ifndef NFR_TRACKING_MX170_H
#define	NFR_TRACKING_MX170_H

#ifdef	__cplusplus
extern "C" {
#endif

// Configuration Bit settings
// SYSCLK = 48 MHz (8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 48 MHz
// Primary Osc w/PLL (XT+,HS+,EC+PLL)
// WDT OFF
// Other options are don't care
//
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

#define SYS_FREQ 			(48000000)
#define BAUD                (2000000)//(460800)(2000000)
    
#define GLED            PORTAbits.RA10
    
#define U1TX            PORTCbits.RC7   //pin10 fubrino
#define U1RX            PORTCbits.RC6   //pin9 fubrino
    
#define MOSI1           PORTBbits.RB13  //pin0 fubrino    
#define SCLK1           PORTBbits.RB14  //pin3 fubrino
#define CS1             PORTBbits.RB15  //pin4 fubrino
#define MISO1           PORTAbits.RA1   //pin6 fubrino

typedef union {
    struct {
        unsigned char BYTE              :8;
    };
    struct {
        unsigned SAMPLE                 :1;
        unsigned IMU                    :1;
        unsigned DUMP                   :1;
        unsigned STAT                   :1;
        unsigned                        :4;
    };
} command_register1;
command_register1 cmd_reg1;    

char urx1_flag;
    
#ifdef	__cplusplus
}
#endif

#endif	/* NFR_TRACKING_MX170_H */

