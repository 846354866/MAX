/*!
 * @file buttonValue.ino
 * @brief DFRobot's read button value
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
	Serial.begin(115200);
	myMax.begin();
}

void loop() {
	int16_t data = myMax.buttonValue();
  
	Serial.println(data);
	
	delay(100); 
} 