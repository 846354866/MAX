/*!
 * @file rgbLed.ino
 * @brief DFRobot's led show
 * @n [Get the module here](等上架后添加商品购买链接)
 * @n [Connection and Diagram](等上架后添加wiki链接)
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [yangyang](971326313@qq.com)
 * @version  V1.0
 * @date  2017-6-29
 */
#include <DFRobot_MAX.h>

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