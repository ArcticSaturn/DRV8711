

#ifndef DRV8711_h
#define DRV8711_h
#include "Energia.h"
#include <SPI.h>
//#include "DRV8711_h_defines.h"

// defaults
#define SPI_SlaveSelect 11	// G2553 Launchpad SlaveSelect Pin P2.3

// Address definition
#define ADDR_CTRL		(0*0x1000u)
#define ADDR_TORQUE	(1*0x1000u)
#define ADDR_OFF		(2*0x1000u)
#define ADDR_BLANK	(3*0x1000u)
#define ADDR_DECAY	(4*0x1000u)
#define ADDR_STALL	(5*0x1000u)
#define ADDR_DRIVE		(6*0x1000u)
#define ADDR_STATUS	(7*0x1000u)



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

// OFF Register Address = 0x2h
#define TOFF_0	(0x0001)		// TOFF bit 0
#define TOFF_1	(0x0002)		// TOFF bit 1
#define TOFF_2	(0x0004)		// TOFF bit 2
#define TOFF_3	(0x0008)		// TOFF bit 3
#define TOFF_4	(0x0010)		// TOFF bit 4
#define TOFF_5	(0x0020)		// TOFF bit 5
#define TOFF_6	(0x0040)		// TOFF bit 6
#define TOFF_7	(0x0080)		// TOFF bit 7
#define PWMMODE	(0x0100)	// PWMMODE , internal indexer

// BLANK Register Address = 0x3h
#define TBLANK_0	(0x0001)		// TBLANK bit 0
#define TBLANK_1	(0x0002)		// TBLANK bit 1
#define TBLANK_2	(0x0004)		// TBLANK bit 2
#define TBLANK_3	(0x0008)		// TBLANK bit 3
#define TBLANK_4	(0x0010)		// TBLANK bit 4
#define TBLANK_5	(0x0020)		// TBLANK bit 5
#define TBLANK_6	(0x0040)		// TBLANK bit 6
#define TBLANK_7	(0x0080)		// TBLANK bit 7
#define ABT			(0x0100)		// adaptive blanking time

// DECAY Register Address = 0x4h
#define TDECAY_0	(0x0001)		// TDECAY bit 0
#define TDECAY_1	(0x0002)		// TDECAY bit 1
#define TDECAY_2	(0x0004)		// TDECAY bit 2
#define TDECAY_3	(0x0008)		// TDECAY bit 3
#define TDECAY_4	(0x0010)		// TDECAY bit 4
#define TDECAY_5	(0x0020)		// TDECAY bit 5
#define TDECAY_6	(0x0040)		// TDECAY bit 6
#define TDECAY_7	(0x0080)		// TDECAY bit 7
#define DECMOD_0	(0x0100)		// Decay Mode bit 0
#define DECMOD_1	(0x0200)		// Decay Mode bit 1
#define DECMOD_2	(0x0400)		// Decay Mode bit 2

#define DECMOD0	(0*0x100u)		// 000: Force slow decay at all times
#define DECMOD1 	(1*0x100u)		// 001: Slow decay for increasing current, mixed decay for decreasing current (indexer mode only)
#define DECMOD2 	(2*0x100u)		// 010: Force fast decay at all times
#define DECMOD3 	(3*0x100u)		// 011: Use mixed decay at all times
#define DECMOD4 	(4*0x100u)		// 100: Slow decay for increasing current, auto mixed decay for decreasing current (indexer mode only)
#define DECMOD5 	(5*0x100u)		// 101: Use auto mixed decay at all times

// STALL Register Address = 0x5h
#define SDTHR_0		(0x0001)		// SDTHR bit 0
#define SDTHR_1		(0x0002)		// SDTHR bit 1
#define SDTHR_2		(0x0004)		// SDTHR bit 2
#define SDTHR_3		(0x0008)		// SDTHR bit 3
#define SDTHR_4		(0x0010)		// SDTHR bit 4
#define SDTHR_5		(0x0020)		// SDTHR bit 5
#define SDTHR_6		(0x0040)		// SDTHR bit 6
#define SDTHR_7		(0x0080)		// SDTHR bit 7
#define SDCNT_0		(0x0100)		// STALL assertion bit 0
#define SDCNT_1		(0x0200)		// STALL assertion bit 1
#define VDIV_0		(0x0400)		// back EMF divider bit 0
#define VDIV_1		(0x0800)		// back EMF divider bit 1

#define SDCNT0		(0x0100)		// 00: STALLn asserted on first step with back EMF below SDTHR
#define SDCNT1		(1x0100)		// 01: STALLn asserted after 2 steps 
#define SDCNT2		(2x0100)		// 10: STALLn asserted after 4 steps
#define SDCNT3		(3x0100)		// 11: STALLn asserted after 8 steps

// DRIVE Register Address = 0x6h
#define OCPTH_0		(0x0001)		// OCP threshold bit 0
#define OCPTH_1		(0x0002)		// OCP threshold bit 1
#define OCPDEG_0	(0x0004)		// OCP deglitch time bit 0
#define OCPDEG_1	(0x0008)		// OCP deglitch time bit 1
#define TDRIVEN_0	(0x0010)		// Low-side gate drive time bit 0
#define TDRIVEN_1	(0x0020)		// Low-side gate drive time bit 1
#define TDRIVEP_0	(0x0040)		// High-side gate drive time bit 0
#define TDRIVEP_1	(0x0080)		// High-side gate drive time bit 1
#define IDRIVEN_0	(0x0100)		// Low-side gate drive peak current bit 0
#define IDRIVEN_1	(0x0200)		// Low-side gate drive peak current bit 1
#define IDRIVEP_0	(0x0400)		// High-side gate drive peak current bit 0
#define IDRIVEP_1	(0x0800)		// High-side gate drive peak current bit 1

//  STATUS Register Address = 0x7h
#define OTS		(0x0001)		// overtemperature shutdown
#define AOCP		(0x0002)		// Channel A overcurrent shutdown
#define BOCP		(0x0004)		// Channel B overcurrent shutdown
#define APDF		(0x0008)		// Channel A predriver fault
#define BPDF		(0x0010)		// Channel B predriver fault
#define UVLO		(0x0020)		// Undervoltage lockout
#define STD		(0x0040)		// Stall detected
#define STDLAT	(0x0080)		// Latched stall detect

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
