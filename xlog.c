/**
 * This file belongs to the 'xlab' game engine.
 * Copyright 2009 xfacter
 * Copyright 2016 wickles
 * This work is licensed under the LGPLv3
 * subject to all terms as reproduced in the included LICENSE file.
 */

#include <stdarg.h>
#include <stdio.h>
#include <psptypes.h>
#include <psprtc.h>

#include "xlog.h"

#define X_BUFFER_SIZE (1024)

FILE* xlog_file = 0;
char buffer[X_BUFFER_SIZE];

void xLogPrint(char* text)
{
    xlog_file = fopen("./xlog.txt", "a");
    if (!xlog_file) return;
    ScePspDateTime time_struct;
    sceRtcGetCurrentClockLocalTime(&time_struct);
    fprintf(xlog_file, "[%02u:%02u:%02u:%06u] %s\r\n", time_struct.hour, time_struct.minute, time_struct.second, (unsigned int)time_struct.microsecond, text);
    fclose(xlog_file);
    xlog_file = 0;
}

void xLogPrintf(char* text, ... )
{
#ifdef X_DEBUG
    va_list ap;
    va_start(ap, text);
	vsnprintf(buffer, X_BUFFER_SIZE, text, ap);
    va_end(ap);
    xLogPrint(buffer);
#endif
}
