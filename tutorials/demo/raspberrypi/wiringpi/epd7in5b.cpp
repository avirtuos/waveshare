/**
 *  @filename   :   epd7in5b.cpp
 *  @brief      :   Implements for e-paper library
 *  @author     :   Yehui from Waveshare
 *
 *  Copyright (C) Waveshare     August 10 2017
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
#include "epd7in5b.h"
#include "epdif.h"

Epd::~Epd() {
};

Epd::Epd() {
    reset_pin = RST_PIN;
    dc_pin = DC_PIN;
    cs_pin = CS_PIN;
    busy_pin = BUSY_PIN;
    width = EPD_WIDTH;
    height = EPD_HEIGHT;
};

int Epd::Init(void) {
    if (IfInit() != 0) {
        return -1;
    }
    Reset();
    SendCommand(POWER_SETTING); 
    SendData(0x37);
    SendData(0x00);
    SendCommand(PANEL_SETTING);
    SendData(0xCF);
    SendData(0x08);
    SendCommand(BOOSTER_SOFT_START);
    SendData(0xC7);     
    SendData(0xCC);
    SendData(0x28);
    SendCommand(PLL_CONTROL);
    SendData(0x3C);        
    SendCommand(TEMPERATURE_CALIBRATION);
    SendData(0x00);
    SendCommand(VCOM_AND_DATA_INTERVAL_SETTING);
    SendData(0x77);
    SendCommand(TCON_SETTING);
    SendData(0x22);
    SendCommand(TCON_RESOLUTION);
    SendData(0x02);     //source 640
    SendData(0x80);
    SendData(0x01);     //gate 384
    SendData(0x80);
    SendCommand(VCM_DC_SETTING);
    SendData(0x1E);      //decide by LUT file
    SendCommand(0xE5);           //FLASH MODE            
    SendData(0x03);  
    SendCommand(POWER_ON);
    WaitUntilIdle();
    return 0;
}

void Epd::SendCommand(unsigned char command) {
    DigitalWrite(dc_pin, LOW);
    SpiTransfer(command);
}

void Epd::SendData(unsigned char data) {
    DigitalWrite(dc_pin, HIGH);
    SpiTransfer(data);
}

void Epd::WaitUntilIdle(void) {
    while(DigitalRead(busy_pin) == 0) {      //0: busy, 1: idle
        DelayMs(100);
    }      
}

void Epd::Reset(void) {
    DigitalWrite(reset_pin, LOW);                //module reset    
    DelayMs(200);
    DigitalWrite(reset_pin, HIGH);
    DelayMs(200);    
}

void Epd::DisplayFrame(const unsigned char* frame_buffer) {
    SendCommand(DATA_START_TRANSMISSION_1);
    for(int i = 0; i < this->width / 2 * this->height; i++) {   
        SendData(frame_buffer[i]);
    }
    SendCommand(DISPLAY_REFRESH);
    DelayMs(100);
    WaitUntilIdle();
}

void Epd::Sleep(void) {
    SendCommand(POWER_OFF);
    WaitUntilIdle();
    SendCommand(DEEP_SLEEP);
    SendData(0xa5);
}

/* END OF FILE */


