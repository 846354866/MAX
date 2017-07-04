/*!
 * @file playDemo.ino
 * @brief DFRobot's Led Control
 * @n [Get the module here](等上架后添加商品购买链接)
 * @n [Connection and Diagram](等上架后添加wiki链接)
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
   myMax.lineLED(HIGH);
   delay(1000);
   myMax.lineLED(LOW);
   delay(1000);
} 