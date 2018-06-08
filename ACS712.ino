
/*
Measuring Current Using ACS712
*/
int analogIn = A0;
int mVperAmp = 66; // use 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 2500; 
double Voltage = 0;
double Amps = 0;
#define LED 13
#define D0 5
#define D1 4
#define D2 3
#define D3 2
#define SENSOR 8
void setup(){ 
Serial.begin(9600);
}

void loop(){
digitalWrite(D0, 0);
digitalWrite(D1, 0);
digitalWrite(D2, 0);
digitalWrite(D3, 0);
digitalWrite(LED, HIGH);
RawValue = analogRead(analogIn);
Voltage = (RawValue / 1023.0) * 5000; // Gets you mV
Amps = ((Voltage - ACSoffset) / mVperAmp);


Serial.print("Raw Value = " ); // shows pre-scaled value 
Serial.print(RawValue); 
Serial.print("\t mV = "); // shows the voltage measured 
Serial.print(Voltage,3); // the '3' after voltage allows you to display 3 digits after decimal point
Serial.print("\t Amps = "); // shows the voltage measured 
Serial.println(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point
delay(2500); 

}
