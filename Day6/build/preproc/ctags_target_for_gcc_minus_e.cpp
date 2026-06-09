# 1 "C:\\Users\\hp\\UWR-Internship\\Day6\\Day6.ino"
void setup()
{
 pinMode(A0,0x0);
    pinMode(13,0x1);
    Serial.begin(9600);
}
int ldr_value;
void loop()
{
 ldr_value=analogRead(A0);
    Serial.print("LDR Value: ");
    Serial.println(ldr_value);
    if(ldr_value>=500){
        digitalWrite(13,0x1);
    }else{
        digitalWrite(13,0x0);
    }
    delay(1000);
}
