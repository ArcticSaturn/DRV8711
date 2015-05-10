

#include "DRV8711.h"
uint8_t _SlaveSelectPin;

DRV8711::DRV8711() {
	DRV8711(SPI_SlaveSelect);
}
DRV8711::DRV8711(uint8_t SlaveSelectPin) {
	_SlaveSelectPin = SlaveSelectPin;
}



void DRV8711::configureRegisters(){
	uint16_t CTRL_REG = 0x0000;
	uint16_t TORQUE_REG = 0x0000;
	CTRL_REG = DTIME_850 + ISGAIN_40 + STEP1_8 + ENBL;
	TORQUE_REG = ADDR_TORQUE + SMPLTH_50 + 186;
	
	writeRegister(CTRL_REG);
	writeRegister(TORQUE_REG);
	writeRegister(0x2030); // off register
	writeRegister(0x3108); // ABT register
	writeRegister(0x4310); // DECAY register
	writeRegister(0x5F40); // STALL register
	writeRegister(0x60AA); // STALL register
	writeRegister(0x7000); // clear status register
	
	//Serial.println(CTRL_REG,HEX);
	//Serial.println(TORQUE_REG,HEX);
	
}



//
// writes data from MCU to DRV8711
//
void DRV8711::writeRegister(uint16_t Data)
{
	digitalWrite(_SlaveSelectPin,HIGH);  	// enable slave select
	SPI.transfer(0x00FF&(Data/256)); 	// transfer higher byte
	SPI.transfer(0x00FF&Data); 		// transfer lower byte
	digitalWrite(_SlaveSelectPin,LOW);  	// disable slave select
}

//
// reads data from DRV8711 to MCU
// input: uint8_taddress
// valid data from 0x00 to 0x07
// return: uint16_t data (MSB first)
//
uint16_t DRV8711::readRegister(uint8_t Address)
{
	
	uint16_t ReadDataLo, ReadDataHi;
	uint16_t ReadData;
	// High Byte
	// Bit7    Bit6    Bit5     Bit 4    Bit3   Bit2    Bit1    Bit0
	// 1        Addr2 Addr1  Addr0  0       0        0         0
	
	Address=(Address<<4)+0x80;   // shift address 4 bits to left and add 0x80
	
	digitalWrite(_SlaveSelectPin,HIGH);       // enable slave select
	ReadDataHi = (SPI.transfer(Address)) & 0x0F;    // read high byte, mask lower 4bit
	ReadDataLo = SPI.transfer(0x00);         // read lower byte
	digitalWrite(_SlaveSelectPin,LOW);      // disable slave select
	
	ReadData = (uint16_t)ReadDataHi*256 + ReadDataLo;
	return ReadData;
}

// send one pulse on Step Pin
// input: uint8_t StepPin   - step input pin of DRV8711
//           uint8_t usTime   - high and low time in microseconds

void DRV8711::MoveOneStep(uint8_t StepPin, long usTime)
{
	digitalWrite(StepPin, HIGH);
	delayMicroseconds(usTime);
	digitalWrite(StepPin, LOW);
	delayMicroseconds(usTime);
	
}

void DRV8711::MoveNoOfSteps(uint8_t StepPin, long usTime, long NoOfSteps)
{
	for(long i=0;i<NoOfSteps;i++)
	{
		MoveOneStep(StepPin, usTime);
	}
	
}

void DRV8711::SetStepMode(uint8_t Mode){
	uint16_t Register, Mask;
	
	Mask = (0x0F00 + Mode) + 0x0003;
	
	Register = readRegister(0x00);
	
	writeRegister(Register&Mask);  // clear enable bit 0
	
}

void DRV8711::StopMotor()
{
	uint16_t Register;
	Register = readRegister(0x00);
	writeRegister(Register&0x0FFE);  // clear enable bit 0
}

