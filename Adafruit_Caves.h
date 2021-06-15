#pragma once
#include "Adafruit_GFX.h"

class Adafruit_Caves : public Adafruit_GFX
{
private:
    uint16_t _W;
    uint16_t _H;
    uint16_t* _GRAM = nullptr;

public:
    Adafruit_Caves(uint16_t W, uint16_t H);
    ~Adafruit_Caves();

    uint8_t begin();
    void end();

    uint16_t* getCaves();
    uint16_t getCavesWidth();
    uint16_t getCavesHeigh();

    void drawPixel(int16_t x, int16_t y, uint16_t color);
};

