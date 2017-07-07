/*!
 * @file DFRobot_MAX.cpp
 * @brief DFRobot's Emoticons
 * @n This example implementation of I2C communication LCD
 *
 * @copyright	[DFRobot](http://www.dfrobot.com), 2017
 * @copyright	GNU Lesser General Public License
 * @author [YangYang](Yang.Yang@dfrobot.com)
 * @version  V1.0
 * @date  2017-1-3
 */

#include <DFRobot_MAX.h>


DFRobot_MAX::DFRobot_MAX()
{
}

DFRobot_MAX::~DFRobot_MAX()
{
}

void DFRobot_MAX::begin()
{
	pinMode(SPEED_R, OUTPUT);
	pinMode(SPEED_L, OUTPUT);
	pinMode(DIRECTION_R, OUTPUT);
	pinMode(DIRECTION_L, OUTPUT);
	pinMode(MIC, INPUT);
	pinMode(KEY, INPUT);
	pinMode(LED_PIN, OUTPUT);
	pinMode(MP3Pin, OUTPUT);
	pinMode(SP1,OUTPUT);

	led_.begin();
	nBus.begin();
	
	writeRegister(ULTRASOUND_ADDR, REG_U_ENABLE, 0x01); //enable ultrasonic
	writeRegister(EMOTICONS_ADDR, REG_E_ENABLE, 0x01); //enable emoticons
	setVolume(0xe7); //set max volume

	servo_.attach(SP1);
}

uint32_t DFRobot_MAX::micValue()
{
	return digitalRead(MIC);
}

uint32_t DFRobot_MAX::buttonValue()
{
	return digitalRead(KEY);
}

void DFRobot_MAX::servoControl(uint8_t io, uint8_t angle)
{
	static uint8_t io_ = SP1;
	if (io_ != io) {
		pinMode(io,OUTPUT);
		servo_.attach(io);
	}
	io_ = io;

	servo_.write(angle);
}

void DFRobot_MAX::rgbLed(uint8_t num, uint8_t r, uint8_t g, uint8_t b)
{
	led_.setPixelColor(num, led_.Color(r, g, b) );
	led_.show();
}

/*****************electric motor*********************/
void DFRobot_MAX::forward(uint8_t speed_l, uint8_t speed_r)
{
	digitalWrite(DIRECTION_L, HIGH);
	delay(1);
	analogWrite(SPEED_L, speed_l);
	delay(1);

	digitalWrite(DIRECTION_R, HIGH);
	delay(1);
	analogWrite(SPEED_R, speed_r);
	delay(1);
}

void DFRobot_MAX::backward(uint8_t speed_l, uint8_t speed_r)
{
	digitalWrite(DIRECTION_L, LOW);
	delay(1);
	analogWrite(SPEED_L, speed_l);
	delay(1);

	digitalWrite(DIRECTION_R, LOW);
	delay(1);
	analogWrite(SPEED_R, speed_r);
	delay(1);
}

void DFRobot_MAX::swerve(uint8_t direction_l, uint8_t speed_l, uint8_t direction_r, uint8_t speed_r)
{
	digitalWrite(DIRECTION_L, direction_l);
	delay(1);
	analogWrite(SPEED_L, speed_l);
	delay(1);

	digitalWrite(DIRECTION_R, direction_r);
	delay(1);
	analogWrite(SPEED_R, speed_r);
	delay(1);
}

void DFRobot_MAX::stopMotor()
{
	analogWrite(SPEED_L, LOW);
	delay(1);
	analogWrite(SPEED_R, LOW);
	delay(1);
}

/*******************EffectPlay**********************/
void DFRobot_MAX::playSound(uint8_t snp)
{
	nvcWrite(snp-1);
	delay(2);
}

void DFRobot_MAX::setVolume(uint8_t vol)
{
	nvcWrite(vol);
	delay(2);
}

void DFRobot_MAX::loopPlay()
{
	nvcWrite(0xf2);
	delay(2);
}

void DFRobot_MAX::stopPlay()
{
	nvcWrite(0xfe);
	delay(2);
}

void DFRobot_MAX::nvcWrite(uint8_t temp)
{
	digitalWrite(MP3Pin,LOW);
	delay(2);
	for(uint8_t i=0; i<8; i++) {
		digitalWrite(MP3Pin,HIGH);
		if(temp & 1) {
			delayMicroseconds(1500);
			digitalWrite(MP3Pin,LOW);
			delayMicroseconds(500);
		} else {
			delayMicroseconds(500);
			digitalWrite(MP3Pin,LOW);
			delayMicroseconds(1500);
		}
		temp >>= 1;
	}

	digitalWrite(MP3Pin,HIGH);
}

/***********************moticons************************/
void DFRobot_MAX::clearScreen()
{
	writeRegister(EMOTICONS_ADDR, 0x06, 0x01);
}

void DFRobot_MAX::setLuminance(uint8_t lmn)
{
	writeRegister(EMOTICONS_ADDR, 0x07, lmn);
}

void DFRobot_MAX::setColor(uint8_t color)
{
	writeRegister(EMOTICONS_ADDR, 0x09, color);
}

void DFRobot_MAX::displayEmoticons(uint8_t exp)
{
	writeRegister(EMOTICONS_ADDR, 0x08, exp);
}

void DFRobot_MAX::showCustomEmoticons(uint8_t *p_data, uint8_t p_colro, uint8_t len)
{
	for(uint8_t i=0; i<len; i++) {
		emoticonsPixel(0x0A, p_data[i], p_colro);
		delay(1);
	}
	writeRegister(EMOTICONS_ADDR, 0x17, 0x01);
}

void DFRobot_MAX::showFace(uint8_t exp, uint8_t color)
{
	setColor(color);
	displayEmoticons(exp);
}

void DFRobot_MAX::customFace(uint8_t *data, uint8_t color)
{
	static uint8_t axis_x=0, axis_y=0, len=0;

	for(; axis_y<8; axis_y++) {
		for(axis_x=0; axis_x<16; axis_x++) {
			if(data[axis_x+(axis_y<<4)] != 0) {
				data[len++] = (axis_y<<4)|axis_x;
			}
		}
	}

	showCustomEmoticons(data, color, len);
}

void DFRobot_MAX::emoticonsPixel(uint8_t registerAddr, uint8_t p_data, uint8_t p_colro)
{
	nBus.beginTransmission(EMOTICONS_ADDR,WRITE);
	nBus.write(registerAddr);//register address
	nBus.write(p_data);//data
	delay(1);
	nBus.write(p_colro);//color
	nBus.endTransmission();
	delayMicroseconds(500);
}

/*********************Ultrasound*************************/
int16_t DFRobot_MAX::distanceValue()
{
	return readRegister(ULTRASOUND_ADDR, REG_U_DISTANCE, 0x02);
}

/********************LedControl************************/
void DFRobot_MAX::lineLED(uint8_t data)
{
	writeRegister(LINE_PATROL_ADDR, 0x14, data);
}

/***********************StratchPatrolSensor***********************/
int16_t DFRobot_MAX::patrolValue()
{
	return readRegister(LINE_PATROL_ADDR, REG_SP_ADDR, 0x01);
}

int16_t DFRobot_MAX::lineValue(int8_t num)
{
	int16_t data;
	int8_t select_n = (0x01<<num);
	
	data = readRegister(LINE_PATROL_ADDR, REG_SP_ADDR, 0x01);
	
	if(data != -1) {
		data = (data & select_n)>>num;
	}
	
	return data;
}

/************************LightSensor********************************/
int16_t DFRobot_MAX::lightValue(uint8_t num)
{
	if (num) {
		return readRegister(LIGHT_SENSOR_ADDR, REG_L_LEFT, 0x02);
	} else {
		return readRegister(LIGHT_SENSOR_ADDR, REG_L_RIGHT, 0x02);
	}
}

/**********************************************************************************************/
int16_t DFRobot_MAX::readRegister(uint8_t hardwareAddr, uint8_t registerAddr, uint8_t len)
{
	int16_t data;
	uint8_t temp = 0;
	nBus.beginTransmission(hardwareAddr,READ);
	nBus.write(registerAddr);///<register address
	delayMicroseconds(500);
	nBus.write(len); ///<read length
	nBus.endTransmission();
	nBus.requestFrom(hardwareAddr, len);
	if(nBus.available() == 0x02) {
		temp = nBus.read();
		data = (temp<<8)|(nBus.read());
	} else if(nBus.available() == 0x01) {
		data = nBus.read();
	} else {
		data = -1;
	}
	delayMicroseconds(500);
	return data;
}

void DFRobot_MAX::writeRegister(uint8_t hardwareAddr, uint8_t registerAddr, uint8_t data)
{
	nBus.beginTransmission(hardwareAddr, WRITE);
	nBus.write(registerAddr);//register address
	nBus.write(data);//data
	nBus.endTransmission();
	delayMicroseconds(500);
}