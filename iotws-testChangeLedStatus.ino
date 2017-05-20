// project: IoT Weather Station, EAFIT University, Systems Engineering, 20171
// Adaptation done by: Edwin Montoya Munera - emontoya@eafit.edu.co , David Velasquez - dvelas25@eafit.edu.co and Alexander Acosta Jimenez - aacosta8@eafit.edu.co
// github: https://github.com/iotweatherstation/iotws-testChangeLedStatus.git

// Description: This program change  the LED's status,
// Depending on the status, turn on the led, or turn off the led
// Status = 1 turn on the led
// Status = 0 turn off the led

#define LED D4

//Constants
const unsigned long SEND_Timer = 5000;  //Delay between SEND variables, 5000 milliseconds - 5 seconds
unsigned long lastConnectionTime = 0; //Last time  in milliseconds

int statusLed = 0;
int currentStatus = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

int changeStatus(){
  if(statusLed==1){
    statusLed = 0;
  }else{
    statusLed = 1;
  }
  return statusLed;
}

void loop() {
  // put your main code here, to run repeatedly:
   if (millis() - lastConnectionTime > SEND_Timer) {

    currentStatus = changeStatus();

    if(currentStatus == 1){
      Serial.println("Prendido"); // replace for digitalWrite(LED, HIGH) to turn on the led.
    }else{
      Serial.println("Apagado"); // replace for digitalWrite(LED, LOW) to turn off the led.
    }
      lastConnectionTime = millis();
   }
}
