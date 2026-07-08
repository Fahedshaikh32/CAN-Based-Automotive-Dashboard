#include <xc.h>   // include microcontroller header
#include "adc.h"   // include ADC header

void init_adc(void)   // function to initialize ADC
{
	ADFM = 1;   // set right justified result

	ACQT2 = 0;   // acquisition time bit 2
	ACQT1 = 1;   // acquisition time bit 1
	ACQT0 = 0;   // acquisition time bit 0

	ADCS0 = 0;   // ADC clock select bit 0
	ADCS1 = 1;   // ADC clock select bit 1
	ADCS2 = 0;   // ADC clock select bit 2

	GODONE = 0;   // stop conversion initially

	VCFG1 = 0;   // set VSS as reference
	VCFG0 = 0;   // set VDD as reference

	ADRESH = 0;   // clear high register
	ADRESL = 0;   // clear low register

	ADON = 1;   // turn ON ADC module
}

unsigned short read_adc(unsigned char channel)   // function to read ADC value
{
	unsigned short reg_val;   // variable to store result

	ADCON0 = (ADCON0 & 0xC3) | (channel << 2);   // select ADC channel

	GO = 1;   // start conversion
	while (GO);   // wait until conversion complete

	reg_val = (ADRESH << 8) | ADRESL;   // combine result

	return reg_val;   // return ADC value
}