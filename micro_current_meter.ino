#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup(void) 
{
  uint32_t currentFrequency;
    
  Serial.begin(115200);
  Serial.println("Hello!");
  
  Serial.println("Measuring voltage and current with INA219 ...");
  ina219.begin();
}

void loop(void) 
{
  static float shuntvoltage;
  static float busvoltage;
  static float current_mA;
  static float loadvoltage;
  static int i;
  
  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  float buf_cruuent = current_mA ;
  current_mA = (0.99f * buf_cruuent) +  (0.01f * (ina219.getCurrent_mA() - buf_cruuent));
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  if (i >40)
  {
    i = 0;
    Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
    Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
    Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
    Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
    Serial.println("");
  }
  i++;

}
