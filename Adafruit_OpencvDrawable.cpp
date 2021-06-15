#include "Adafruit_OpencvDrawable.h"

void Adafruit_OpencvDrawable::drawPixel(int16_t x, int16_t y, uint16_t color)
{
	if (x >= _W || y >= _H)return ;
	this->img->at<cv::Vec3b>(y, x) = RGB565ToRGB888(color);
	/*uint16_t tmp = color >> 11;
	tmp &= 0b11111;
	std::cout << (int)tmp << " ";
	this->img->at<Vec3b>(y, x)[0] = v_map(tmp, 0, 0b11111, 0, 0xff);
	tmp = color >> 5;
	tmp &= 0b111111;
	std::cout << (int)tmp << " ";
	this->img->at<Vec3b>(y, x)[1] = v_map(tmp, 0, 0b111111, 0, 0xff);
	tmp = color;
	tmp &= 0b11111;
	std::cout << (int)tmp << std::endl;
	this->img->at<Vec3b>(y, x)[2] = v_map(tmp, 0, 0b11111, 0, 0xff);*/
}

Adafruit_OpencvDrawable::Adafruit_OpencvDrawable(int16_t w, int16_t h) :Adafruit_GFX(w, h)
{
	_W = w;
	_H = h;
	img = new cv::Mat(h, w, CV_8UC3, cv::Scalar(0, 0, 0));
}

uint16_t Adafruit_OpencvDrawable::getPixel(int16_t x, int16_t y)
{
	if (x >= _W || y >= _H)return 0;
	cv::Vec3b res = cv::Vec3b(0,0,0);
	res = this->img->at<cv::Vec3b>(y, x);
	return RGB888ToRGB565(res);
}

cv::Mat Adafruit_OpencvDrawable::getPic()
{
    return *img;
}


long Adafruit_OpencvDrawable::v_map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

cv::Vec3b Adafruit_OpencvDrawable::RGB565ToRGB888(uint16_t rgb565)
{
	cv::Vec3b res(0, 0, 0);
	uint16_t tmp = rgb565 >> 11;
	tmp &= 0b11111;
	//std::cout << (int)tmp<<" ";
	res[0] = v_map(tmp, 0, 0b11111, 0, 0xff);
	tmp = rgb565 >> 5;
	tmp &= 0b111111;
	//std::cout << (int)tmp << " ";
	res[1] = v_map(tmp, 0, 0b111111, 0, 0xff);
	tmp = rgb565;
	tmp &= 0b11111;
	//std::cout << (int)tmp<<std::endl;
	res[2] = v_map(tmp, 0, 0b11111, 0, 0xff);
	return res;
}

uint16_t Adafruit_OpencvDrawable::RGB888ToRGB565(cv::Vec3b rgb888)
{
	return (((rgb888[0] >> 3) & 0x1F) << 11)  //b
		| (((rgb888[1] >> 2) & 0x3F) << 5) //g
		| ((rgb888[1] >> 3) & 0x1F);       //r
}
