#include<Servo.h>
//HEADER FILE DECLARATION FOR SERVO DRIVERS
  Servo servo1;
  Servo servo2;
  Servo servo3;
  Servo servo4;
  Servo servo5;
  Servo servo6;
int angle;

#define EMGPin0 A0
//define used to declare and specify the arduino point analogue point for 
//1st EMG signal attached to the A0 pin 

#define EMGPin1 A1
//2nd EMG signal attached to the A1 pin

#define EMGPin1 A2
//3rd EMG signal attached to the Analogue 2

    int EMGVal0=0; // specify the emgval=0
    int EMGVal1=0; // specify the emgval=0
    float x=180; //simply you  can change the values by analyzing muscle and set the correct value
    float y=400;
    
    void setup() {
    // used only one time and initial running
    Serial.begin(9600);

    //FOR SHOWING THE SERIAL PORT VALUES

    servo1.attach(3);
    servo2.attach(5);
    servo3.attach(6);
    servo4.attach(9);
    servo5.attach(10);
    servo6.attach(11);

//ALL SERVOS ARE CONNECTED WITH THE PULSE WIDTH MODULATED SIGNAL GENERATING POINTS


        servo1.write(0); //inside of servo write is the degrree value to the servo shaft rotation
        
        servo2.write(0);
        
        servo3.write(0);
        
        servo4.write(0);
        
        servo5.write(0);
        
        servo6.write(0);
        
        //FOR PROVIDING ALL SERVOS THE 0 DEGREE ROTATION OR THEY ARE IN THE TENSIONLESS OR STABLE STATE

}

void loop() {

          EMGVal0 = analogRead(EMGPin0);
          //analogueRead used to accept analogue value AND stored in the emgval
          EMGVal1 = analogRead(EMGPin1);
          
          Serial.print(EMGVal0);//print the emgval0 value in the serial monitor
          
          Serial.print(",");
          
          Serial.print(EMGVal1);
         
          
          //print new line
          Serial.println();


                if(EMGVal0<=x){
                  angle=map(EMGVal0,0,x,0,180); //value will change based on the muscles
                  servo1.write(angle);
                }
                
                else if(EMGVal0 >x){
                  angle=map(EMGVal0,x,y,0,180);
                  servo2.write(angle);
                }
                else{
                  servo1.write(0);
                  servo2.write(0);
                  
                   }
                        
                        if(EMGVal1<=x){
                          angle=map(EMGVal1,0,x,0,180);
                          servo3.write(angle);
                        }
                        
                        else if(EMGVal1>x){
                          angle=map(EMGVal1,x,y,0,180);
                          servo4.write(angle);
                        }
                        
                        
                        else{
                          servo3.write(0);//non of the above doesnot support then the position of the servo is  in the actual or 0 degree
                          servo4.write(0);
                          
                        }
                          
                          if(EMGVal2<=x){
                          angle=map(EMGVal1,0,x,0,180);
                          servo5.write(angle);
                        }
                        
                        else if(EMGVal2>x){
                          angle=map(EMGVal1,x,y,0,180);
                          servo6.write(angle);
                        }
                        
                        
                        else{
                          
                          servo5.write(0); //non of the above doesnot support then the position of the servo is  in the actual or 0 degree
                          servo6.write(0);
}
