#include <EEPROMforAuth.h>
EEPROMforAuth::EEPROMforAuth(){

}
void EEPROMforAuth::clearEEPROM(){
	EEPROM.begin(LENGTHEEPROM);
  for(int i=0;i<LENGTHEEPROM;i++){
    EEPROM.write(i,0);

    }
  EEPROM.commit();
}
void EEPROMforAuth::writeString(int start,String lab,String str){
	int index=0;
	for(int j=0;j<lab.length();j++){
	EEPROM.write(j+start,lab[j]);
	index=j;
	}
	index++;
	for(int i=0;i<str.length();i++){
	EEPROM.write(i+index+start,str[i]);
	}
	EEPROM.commit();
}
void EEPROMforAuth::writeToEEPROM(String ess,String psw, String key){
	EEPROM.begin(LENGTHEEPROM);
	  String ret;
	  int index=0;
	  clearEEPROM();
	writeString(0,"#ESS=",ess);
	writeString(5+ess.length(),"#PSW=",psw);
	writeString(5+5+ess.length()+psw.length(),"#KEY=",key);
  writeString(5+5+5+ess.length()+psw.length()+key.length(),"#","");
  }

String EEPROMforAuth::readFromEEPROM(String arg1){
  String ret;
	EEPROM.begin(LENGTHEEPROM);
  int index=0;
  for(int i=0;i<LENGTHEEPROM-5;i++){
      char value1=(char)EEPROM.read(i);
      char value2=(char)EEPROM.read(i+1);
      char value3=(char)EEPROM.read(i+2);
      char value4=(char)EEPROM.read(i+3);
      char value5=(char)EEPROM.read(i+4);
      if(arg1=="ESSID"){
         if(value1=='#'&&value2=='E'&&value3=='S'&&value4=='S'&&value5=='='){
        index=i+5;
        break;
           }
        }
       else if(arg1=="PSW"){
         if(value1=='#'&&value2=='P'&&value3=='S'&&value4=='W'&&value5=='='){
        index=i+5;
        break;
           }
        }
        else if(arg1=="KEY"){
         if(value1=='#'&&value2=='K'&&value3=='E'&&value4=='Y'&&value5=='='){
        index=i+5;
        break;
           }
        }
    }
    for(int j=index;j<LENGTHEEPROM;j++){
      char value=(char)EEPROM.read(j);
      if(value=='#'){
        break;
        }
       ret+=value;
      }
      return ret;

  }
