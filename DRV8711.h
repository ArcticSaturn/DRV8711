

#ifndef DRV8711_h
#define DRV8711_h
#include "Energia.h"
#include <SPI.h>
//#include "DRV8711_h_defines.h"

// defaults
#define SPI_SlaveSelect 11	// G2553 Launchpad SlaveSelect Pin P2.3

// Address Bit
#define ADDR_CTRL	(0*0x1000u)
#define ADDR_TORQUE	(1*0x1000u)



// CTRL Register Address = 0x0h
#define ENBL		(0x0001)	// Enable/Disable Motor
#define RDIR		(0x0002)	// Direction select
#define RSTEP		(0x0004)	// Perform one step
#define MODE_0		(0x0008)	// Step Size Mode bit 0
#define MODE_1		(0x0010)	// Step Size Mode bit 1
#define MODE_2		(0x0020)	// Step Size Mode bit 2
#define MODE_3		(0x0040)	// Step Size Mode bit 3
#define EXSTALL		(0x0080)	// Internal/External stall detect
#define ISGAIN_0	(0x0100)	// ISENSE amplifier bit 0
#define ISGAIN_1	(0x0200)	// ISENSE amplifier bit 1
#define DTIME_0		(0x0400)	// Dead Time bit 0
#define DTIME_1		(0x0400)	// Dead Time bit 1

#define STEP1_1		(0*8u)		// 0000: Full-step, 71% current
#define STEP1_2		(1*8u)		// 0001: Half step
#define STEP1_4		(2*8u)		// 0010: 1/4 step
#define STEP1_8		(3*8u)		// 0011: 1/8 step
#define STEP1_16	(4*8u)		// 0100: 1/16 step
#define STEP1_32	(5*8u)		// 0101: 1/32 step
#define STEP1_64	(6*8u)		// 0110: 1/64 step
#define STEP1_128	(7*8u)		// 0111: 1/128 step
#define STEP1_256	(8*8u)		// 1000: 1/126 step

#define ISGAIN_5	(0*0x100u)	// 00: Gain of 5
#define ISGAIN_10	(1*0x100u)	// 01: Gain of 10
#define ISGAIN_20	(2*0x100u)	// 10: Gain of 20
#define ISGAIN_40	(3*0x100u)	// 11: Gain of 40

#define DTIME_400	(0*0x400u)	// 00: 400 ns dead time
#define DTIME_450	(1*0x400u)	// 01: 450 ns dead time
#define DTIME_650	(2*0x400u)	// 10: 650 ns dead time
#define DTIME_850	(3*0x400u)	// 11: 850 ns dead time

// TORQUE Register Address = 0x1h
#define TORQUE_0	(0x0001)	// Torque bit 0
#define TORQUE_1	(0x0002)	// Torque bit 1
#define TORQUE_2	(0x0004)	// Torque bit 2
#define TORQUE_3	(0x0008)	// Torque bit 3
#define TORQUE_4	(0x0010)	// Torque bit 4
#define TORQUE_5	(0x0020)	// Torque bit 5
#define TORQUE_6	(0x0040)	// Torque bit 6
#define TORQUE_7	(0x0080)	// Torque bit 7
#define SMPLTH_0	(0x0100)	// Sample Threshold bit 0
#define SMPLTH_1	(0x0200)	// Sample Threshold bit 1
#define SMPLTH_2	(0x0400)	// Sample Threshold bit 2

#define SMPLTH_50	(0*0x100u)	// 000: 50 μs
#define SMPLTH_100	(1*0x100u)	// 001: 100 μs
#define SMPLTH_200	(2*0x100u)	// 010: 200 μs
#define SMPLTH_300	(3*0x100u)	// 011: 300 μs
#define SMPLTH_400	(4*0x100u)	// 100: 400 μs
#define SMPLTH_600	(5*0x100u)	// 101: 600 μs
#define SMPLTH_800	(6*0x100u)	// 110: 800 μs
#define SMPLTH_1000	(7*0x100u)	// 111: 1000 μs





class DRV8711 {
public:
	DRV8711();
	DRV8711(uint8_t SlaveSelectPin);
	
	void configureRegisters();
	//DRV8711(uint8_t deviceAddress);
	//DRV8711(uint8_t deviceAddress, uint8_t channel);
/*	void begin();
	void setDeviceAddress(uint8_t deviceAddress);
	void setChannel(uint8_t channel);
	uint8_t getChipVersion(); 
	uint8_t getStatusByte(); 
*/	



//private:
		// global variable
	void writeRegister(uint16_t Data);

//	uint8_t _channel;
//	uint8_t _deviceAddress;
//	uint8_t _gdo0;
/*
	void writeRegister(uint8_t addr, uint8_t data);
	void writeRegisterBurst(uint8_t saddr, uint8_t *data, uint8_t size);
	uint8_t readRegister(uint8_t addr);
	void readRegisterBurst(uint8_t saddr, uint8_t *data, uint8_t size);
	uint8_t readStatusRegister(uint8_t addr);
	void sendTxBuffer(uint8_t *txBuffer, uint8_t size);
	int8_t receiveRxBuffer(uint8_t *rxBuffer, uint8_t size);
	void execStrobeCommand(uint8_t command);
	void resetDevice();
	void configureDeviceSettings();
*/
};

#endif
