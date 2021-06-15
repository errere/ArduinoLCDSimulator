#include "Adafruit_Caves.h"
Adafruit_Caves::Adafruit_Caves(uint16_t W, uint16_t H) : Adafruit_GFX(W, H)
{
    _W = W;
    _H = H;
}

Adafruit_Caves::~Adafruit_Caves()
{
}

uint8_t Adafruit_Caves::begin()
{
    if (_GRAM == nullptr)
    {
        _GRAM = (uint16_t*)malloc(_W * _H * sizeof(uint16_t));
    }
    if (_GRAM != nullptr)
    {
        return 1;
        memset(_GRAM, 0x00, (_W * _H * sizeof(uint16_t)));
    }

    return 0;
}
void Adafruit_Caves::end()
{
    if (_GRAM != nullptr)
    {
        free(_GRAM);
        _GRAM = nullptr;
    }
}
uint16_t* Adafruit_Caves::getCaves()
{
    return _GRAM;
}

uint16_t Adafruit_Caves::getCavesWidth()
{
    return _W;
}

uint16_t Adafruit_Caves::getCavesHeigh()
{
    return _H;
}

void Adafruit_Caves::drawPixel(int16_t x, int16_t y, uint16_t color)
{
    if (x >= _W || y >= _H)return ;
    uint8_t temp1, temp2;
    if (x < _W && y < _W)
    {
        *(_GRAM + (y * _W) + x) = color;//(color << 8) | (color >> 8)
    }
}