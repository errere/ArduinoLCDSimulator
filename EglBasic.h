#pragma once

#include "Arduino.h"
class EglBasic
{
public:
	void delay(uint32_t ms);
	int32_t map(int32_t, int32_t, int32_t, int32_t, int32_t);
};

