/* 
 * File:   system_IO_camera.h
 * Author: Stefan Trenkwalder
 *
 * Created on 27 August 2015, 16:26
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

#ifndef SYSTEM_IO_CAMERA_H
#define	SYSTEM_IO_CAMERA_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "definitions.h"

#define SYS_MAX_RED     0b00011111;
#define SYS_MAX_GREEN   0b00111111;
#define SYS_MAX_BLUE    0b00011111;

    typedef struct sys_rgb_pixel_s{
        uint8 red;
        uint8 green;
        uint8 blue;
    }sys_rgb, sys_rgb_pixel;

    typedef void (*pCameraPreProcessor)(sys_rgb_pixel **frame, uint16 width, uint16 height);

    void Sys_Init_Camera(void);
    void Sys_Start_Camera(void);

    void Sys_Set_Preprocessing(pCameraPreProcessor func);

    sys_rgb_pixel **getFinishedFrame();
    bool isNewFrameAvailable();

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_IO_CAMERA_H */

