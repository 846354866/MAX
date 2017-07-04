/*!
 * @file lightsensordread.ino
 * @brief DFRobot's get the Brightness numerical 
 * @n [Get the module here](等上架后添加商品购买链接)
 * @n This example Set the volume size and play music snippet.
 * @n [Connection and Diagram](等上架后添加wiki链接)
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2016
 * @copyright	GNU Lesser General Public License
 *
 * @author [yangyang](971326313@qq.com)
 * @version  V1.0
 * @date  2016-09-22
 */
#include <DFRobot_MAX.h>

#define VALUE_R	0
#define VALUE_L	1
//#define DISCOVERY_SINGLE_BUS_PIN 2

//SoftwareSinglebus  mySingleBus(DISCOVERY_SINGLE_BUS_PIN);
//DFRobot_MAX myMax(&mySingleBus);
DFRobot_MAX myMax;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myMax.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t data_l = myMax.lightValue(VALUE_L);//get the left numerical
  delay(100); 
  int16_t data_r = myMax.lightValue(VALUE_R);//get the right numerical
  
  Serial.print("Left :");
  Serial.println(data_l);
  
  Serial.print("Right:");
  Serial.println(data_r);
  
  delay(100); 
}

