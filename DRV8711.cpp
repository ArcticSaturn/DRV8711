

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
	
	Serial.println(CTRL_REG,HEX);
	Serial.println(TORQUE_REG,HEX);
	
}



//
// writes data from MCU to DRV8711
//
void DRV8711::writeRegister(uint16_t Data){
	digitalWrite(_SlaveSelectPin,HIGH);  	// enable slave select
	SPI.transfer(0x00FF&(Data/256)); 	// transfer higher byte
	SPI.transfer(0x00FF&Data); 		// transfer lower byte
	digitalWrite(_SlaveSelectPin,LOW);  	// disable slave select
}
