#include "ArduinoCoreEmu.h"

#include"Adafruit_OpencvDrawable.h"
#include "Print.h"
#include "Adafruit_GFX.h"
#include "EglBasic.h"
#include "Adafruit_Caves.h"


Adafruit_OpencvDrawable tft(320, 240);
EglBasic egl;
Adafruit_Caves window1(100, 100);



void ArduinoCoreEmu::setup()
{
	window1.begin();
}

void ArduinoCoreEmu::loop()
{
	//color:BGR565
	static int tc = 0;
	tc++;
	tft.setTextColor(0xffe0, 0x0000);
	tft.setTextSize(5);
	tft.setCursor(0, 0);
	tft.print(tc);
	tft.setCursor(0, 100);
	tft.print("        ");
	tft.setCursor(0, 100);

	imshow("ARDUINO ILI9341LCD", tft.getPic());
	egl.delay(80);


}
