/**
 *  @filename   :   epd7in5bpaint.h
 *  @brief      :   Header file for epd7in5bpaint.cpp
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

#ifndef EPD7IN5BPAINT_H
#define EPD7IN5BPAINT_H

// Display orientation
#define ROTATE_0            0
#define ROTATE_90           1
#define ROTATE_180          2
#define ROTATE_270          3

// Color definition
#define EPDPAINT_BLACK      0x0
#define EPDPAINT_RED        0x4
#define EPDPAINT_WHITE      0x3

#include "fonts.h"

class Paint {
public:
    Paint(unsigned char* image, int width, int height);
    ~Paint();
    void Clear(int color);
    int  GetWidth(void);
    void SetWidth(int width);
    int  GetHeight(void);
    void SetHeight(int height);
    int  GetRotate(void);
    void SetRotate(int rotate);
    unsigned char* GetImage(void);
    void DrawAbsolutePixel(int x, int y, int color);
    void DrawPixel(int x, int y, int color);
    void DrawCharAt(int x, int y, char ascii_char, sFONT* font, int color);
    void DrawStringAt(int x, int y, const char* text, sFONT* font, int color);
    void DrawLine(int x0, int y0, int x1, int y1, int color);
    void DrawHorizontalLine(int x, int y, int width, int color);
    void DrawVerticalLine(int x, int y, int height, int color);
    void DrawRectangle(int x0, int y0, int x1, int y1, int color);
    void DrawFilledRectangle(int x0, int y0, int x1, int y1, int color);
    void DrawCircle(int x, int y, int radius, int color);
    void DrawFilledCircle(int x, int y, int radius, int color);

private:
    unsigned char* image;
    int width;
    int height;
    int rotate;
};

#endif

/* END OF FILE */

