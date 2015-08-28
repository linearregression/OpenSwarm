/*
 * File:   main.c
 * Author: Stefan trenkwalder
 *
 * Created on 07 July 2014, 14:15
 *
 * LICENCE: adapted FreeBSD Licence
 * Copyright (c) 2015, Stefan Trenkwalder
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * 3. If this or parts of this source code or binary code in any form used for an commercial product or service in any form, this product or service must provide a clear notice/message readable for any user or customer that this product or service uses OpenSwarm.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC30F__)
        #include <p30Fxxxx.h>
    #endif
#endif

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include "definitions.h"

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/


/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void task1();
void task2();

int16_t main(void)
{

    /* Configure the oscillator for the device */
    Sys_Init_Kernel();

    Sys_Start_Process_HDI(task1);
    Sys_Start_Process_HDI(task2);

    Sys_Start_Kernel();

    /* Initialize IO ports and peripherals */
    InitApp();

    sys_event_data * data = Sys_Wait_For_Event(SYS_EVENT_TERMINATION);
    Sys_Clear_EventData(&data);
    
    int i = 0;
    while(1){//DO Nothing (do yonly things for testing)
        i++;
        i %= 100;
    }
}


void task1(){
    unsigned char x=0,y=0,z=0;
    while(1){
        x--;
        z++;
        y=x*z;
    }
}


void task2(){
    unsigned char a=0,b=0,c=0;
    bool ohno = false;
    while(1){

        a--;
        c++;
        b = a*a;
        c=b*a;

        if(ohno){
            Sys_Send_Event(SYS_EVENT_TERMINATION, 0, 0);
        }
    }
}