#include<MyDelay.h>

MyDelay LEDtime1(250);
MyDelay LEDtime2(500);//Creats a MyDelay varible set to 1000ms
int LEDpin = 13;
int ledState = LOW;
const int lm35_pin = A0;	/* LM35 O/P pin */
void setup() {
  pinMode(LEDpin, OUTPUT);
  LEDtime1.start();
  LEDtime2.start();
}

void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);	/* Read Temperature */
  temp_val = (temp_adc_val * 4.88);	/* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10);	/* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");
  if(temp_val < 30)
  {
  if(LEDtime1.update())//Checks to see if set time has past
  {
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(LEDpin, ledState);
  }
  }
    else
  {
      if(LEDtime2.update())//Checks to see if set time has past
  {
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(LEDpin, ledState);
  }
  }
}