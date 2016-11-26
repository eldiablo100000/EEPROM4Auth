#ifndef EEPROMforAuth_h
#define EEPROMforAuth_h

#include <EEPROM.h>
#include <Arduino.h>
#define LENGTHEEPROM 512

class EEPROMforAuth{
	public:
		EEPROMforAuth();
		void clearEEPROM();
		void writeToEEPROM(String ess,String psw, String key);
		String readFromEEPROM(String arg1);

	private:
		void writeString(int start,String lab,String str);

};
#endif
