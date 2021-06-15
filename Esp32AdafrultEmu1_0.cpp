
#include "ArduinoCoreEmu.h"


ArduinoCoreEmu arduino;
int main()
{
	arduino.setup();

	while (true)
	{
		arduino.loop();
	}
	return 0;
}
