/* 
 * File:   system_IO.h
 * Author: Stefan Trenkwalder
 *
 * Created on 28 July 2015, 11:21
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
 * 3. If this or parts of this source code or binary code in any form is used for a commercial product or service in any form, this product or service must provide a clear notice/message readable for any user or customer that this product or service uses OpenSwarm.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef SYSTEM_IO_HDI_H
#define	SYSTEM_IO_HDI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../../../os/definitions.h"

#define STEPS_PER_SECOND 10000
#define STEPS_PER_MILISECOND 10
    
typedef struct sys_periodical_IOHandler_s {
    pFunction function;
    
    struct sys_periodical_IOHandler_s *next;
} sys_periodical_IOHandler, sys_pIOHandler;

inline void Sys_Init_IOTimer_HDI();
inline void Sys_Start_IOTimer_HDI();
inline void Sys_IOTimer_code_HDI();

extern sys_periodical_IOHandler *sys_iohandlers;


inline void Sys_Stop_IOTimer_HDI(void);
inline void Sys_Continue_IOTimer_HDI(void);
inline void Sys_Reset_IOTimer_HDI(void);
inline void Sys_Disable_IOTimerInterrupt_HDI(void);
inline void Sys_Enable_IOTimerInterrupt_HDI(void);
inline void Sys_Force_IOTimerInterrupt_HDI(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_IO_HDI_H */
