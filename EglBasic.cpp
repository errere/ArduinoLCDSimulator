#include "EglBasic.h"

void EglBasic::delay(uint32_t ms)
{
	cv::waitKey(ms);
}
int32_t EglBasic::map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}