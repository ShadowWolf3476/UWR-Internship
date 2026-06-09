#include <Arduino.h>
#line 1 "C:\\Users\\hp\\UWR-Internship\\Day6\\Day6.ino"
#line 1 "C:\\Users\\hp\\UWR-Internship\\Day6\\Day6.ino"
void setup();
#line 8 "C:\\Users\\hp\\UWR-Internship\\Day6\\Day6.ino"
void loop();
#line 1 "C:\\Users\\hp\\UWR-Internship\\Day6\\Day6.ino"
void setup()
{
	pinMode(A0,INPUT);
    pinMode(13,OUTPUT);
    Serial.begin(9600);
}
int ldr_value;
void loop()
{
	ldr_value=analogRead(A0);
    Serial.print("LDR Value: ");
    Serial.println(ldr_value);
    if(ldr_value>=500){
        digitalWrite(13,HIGH);
    }else{
        digitalWrite(13,LOW);
    }
    delay(1000);
}

