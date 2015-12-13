/* 
 * File:   system_IO_i2c.h
 * Author: Stefan Trenkwalder
 *
 * Created on 10 August 2015, 15:53
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


#ifndef SYSTEM_IO_I2C_HDI_H
#define	SYSTEM_IO_I2C_HDI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../../../os/definitions.h"

inline void Sys_I2C_Send_Start_HDI();
inline void Sys_I2C_Send_Restart_HDI(void);
inline void Sys_I2C_Send_Stop_HDI(void);
inline void Sys_I2C_Send_ACK_HDI(void);
inline void Sys_I2C_Send_NACK_HDI(void);
inline void Sys_I2C_Start_Reading_HDI(void);
inline char Sys_I2C_ReadByte_HDI(void);
inline void Sys_I2C_WriteByte_HDI(uint8 byte);

inline void Sys_Init_I2C_HDI(void);
inline void Sys_Start_I2C_HDI(void);
inline void Sys_Pause_I2C_HDI(void);
inline void Sys_Contine_I2C_HDI(void);
inline void Sys_Stop_I2C_HDI(void);

void Sys_I2C_SentBytes(uint8 address, uint8 *bytes, uint16 length);
void Sys_I2C_Read(uint8 address, uint8 *intern_address, uint16 length, pByteFunction bytehandler);



#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_IO_I2C_H */

