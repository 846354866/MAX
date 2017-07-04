DFRobot_MAX myMax;

myMax.begin();                                       //直接初始化整个MAX，不出现单总线方面的任何东西。
myMax.advance(左侧电机速度值,右侧电机速度值);    //MAX前进（速度范围0~255）
myMax.retreat(左侧电机速度值,右侧电机速度值);          //MAX后退（速度范围0~255）
myMax.swerve(左侧前进或者后退，左侧速度，右侧前进或者后退，右侧速度)   //自定义电机转向和速度
myMax.stopMotor();                                                            //两个电机停止
myMax.servoControl(端口号SP,角度值);     //端口号SP1~SP3，SP1=D18，SP2=D14，SP3=D11角度0~180度
myMax.playSound(音乐编号);                                  //播放音效，编号1~16号
val=myMax.micValue();                                                  //读取模拟声音量   
val=myMax.distanceValue();                                           //读取超声波距离，单位cm
val=myMax.lightValue(L或R);                                         //读取光线传感器的值，左侧或者右侧。
val=myMax.lineValue(2或者1或者0);                            //读取巡线传感器的值，左（2）中（1）右（0）
myMax.lineLED(HIGH或者LOW);                        //设置巡线传感器的灯亮或者灭 
val=myMax.buttonValue();                                            //读取板载按钮的值
RGBLED(序号，红色值，绿色值，蓝色值);  //板载的4个RGB灯显示 序号从1~4，颜色值0~255
static int8_t myFace[129]{                                            //自定义表情板点阵显示
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //0
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //1
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //2
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //3
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //4
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //5
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //6
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //7
};
myMax.showFace(1~22，颜色宏);                                    //设置表情板显示的固定表情，从1~22号
myMax.customFace(myFace,颜色宏); 


* @n [Get the module here]
* @n This example Set the volume size and play music snippet.
* @n [Connection and Diagram]
*
* Copyright	[DFRobot](http://www.dfrobot.com), 2016
* Copyright	GNU Lesser General Public License
*
* @author [yangyang]
* version  V1.0
* date  2017-6-29
