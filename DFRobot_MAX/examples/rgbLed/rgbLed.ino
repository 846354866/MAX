/*!
 * @file rgbLed.ino
 * @brief DFRobot's led show
 * @n [Get the module here](���ϼܺ������Ʒ��������)
 * @n [Connection and Diagram](���ϼܺ����wiki����)
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [yangyang](971326313@qq.com)
 * @version  V1.0
 * @date  2016-12-07
 */
#include <DFRobot_MAX.h>

//#define SINGLE_BUS_PIN 	2

//SoftwareSinglebus  mySingleBus(SINGLE_BUS_PIN);
//DFRobot_MAX myMax(&mySingleBus);
DFRobot_MAX myMax;

void setup() {
	myMax.begin();
}

void loop() {
   myMax.rgbLed(0, 255, 0, 0); //rgbLed(0~4, r, g, b)  \ r,g,b-0~255
   myMax.rgbLed(1, 0, 255, 0); 
   myMax.rgbLed(2, 0, 0, 255); 
   myMax.rgbLed(3, 255, 255, 0); 
}