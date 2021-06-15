#pragma once
#include "Arduino.h"
#include"Adafruit_GFX.h"
//using namespace cv;

class Adafruit_OpencvDrawable :
    public Adafruit_GFX
{
public :
    virtual void drawPixel(int16_t x, int16_t y, uint16_t color);
    Adafruit_OpencvDrawable(int16_t w,int16_t h);
    uint16_t getPixel(int16_t x, int16_t y);
    cv::Mat getPic();

private:
    int16_t _W, _H;
    cv::Mat *img;
    long v_map(long x, long in_min, long in_max, long out_min, long out_max);
    cv::Vec3b RGB565ToRGB888(uint16_t rgb565);
    uint16_t RGB888ToRGB565(cv::Vec3b rgb888);

};

