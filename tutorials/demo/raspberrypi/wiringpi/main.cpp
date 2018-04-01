/**
 *  @filename   :   main.cpp
 *  @brief      :   7.5inch e-paper display (B) demo
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     August 18 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdlib.h>
#include <stdio.h>
#include "epd7in5b.h"
#include "epd7in5bpaint.h"
#include "imagedata.h"

int main(void)
{
    Epd epd;
    if (epd.Init() != 0) {
        printf("e-Paper init failed\n");
        return -1;
    }

    unsigned char* frame_buffer = (unsigned char*)malloc(epd.width / 2 * epd.height);

    Paint paint(frame_buffer, epd.width, epd.height);
    paint.Clear(EPDPAINT_WHITE);

    /* Draw something to the frame_buffer */
    /* For simplicity, the arguments are explicit numerical coordinates */
    paint.SetRotate(ROTATE_90);
    paint.DrawRectangle(20, 80, 180, 280, EPDPAINT_RED);
    paint.DrawLine(20, 80, 180, 280, EPDPAINT_RED);
    paint.DrawLine(180, 80, 20, 280, EPDPAINT_RED);
    paint.DrawFilledRectangle(200, 80, 360, 280, EPDPAINT_BLACK);
    paint.DrawCircle(300, 160, 60, EPDPAINT_WHITE);
    paint.DrawFilledCircle(90, 210, 30, EPDPAINT_BLACK);

    /* Write strings to the buffer */
    paint.DrawFilledRectangle(0, 6, 384, 30, EPDPAINT_RED);
    paint.DrawStringAt(100, 10, "Hello world!", &Font24, EPDPAINT_WHITE);
    paint.DrawStringAt(100, 40, "e-Paper Demo", &Font24, EPDPAINT_BLACK);

    /* Display the frame buffer */
    epd.DisplayFrame(frame_buffer);

    /* Display the image buffer */
    epd.DisplayFrame(IMAGE_DATA);
    return 0;
}

