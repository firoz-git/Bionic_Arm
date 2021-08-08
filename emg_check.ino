#define EMGPin0 A0 //preprocessing
#define EMGPin1 A1
int EMGVal0;
int EMGVal1;

void setup() {
Serial.begin(9600);
}

void loop() {
  
EMGVal0 = analogRead(EMGPin0);

EMGVal1 = analogRead(EMGPin1);

Serial.print(EMGVal0);
Serial.print(",");
Serial.print(EMGVal1);
delay(500);

//print new line
Serial.println();

}
