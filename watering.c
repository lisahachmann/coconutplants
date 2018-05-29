//This is for arduino code to water plants automatically.
//Supplies needed: 1 arduino per major plant, 9V wall output, 1 USB B cable, transistor and perhaps leds (while watering).

int pumpswitch = 2;
int led = 3;
unsigned long currenttime;
unsigned long prevtime;
boolean extreme = false;
unsigned int delaytime;
unsigned int waittime;

void setup(){
Serial.begin(9600); //mostly for debugging
pinMode(pumpswitch, OUTPUT);
pinMode(led, OUTPUT);
delaytime = 1000;
waittime = 5000; //in millis
prevtime = 0;
}

void loop(){
currenttime = millis();
if (currenttime-prevtime > waittime){ //every minute, 1000 milliseconds in a minute
  digitalWrite(pumpswitch, HIGH);
  Serial.println("HIGH");
  digitalWrite(led, HIGH);
}
if (currenttime-prevtime > (waittime + delaytime)){ //every minute, 1000 milliseconds in a minute
  digitalWrite(pumpswitch, LOW);
  digitalWrite(led, LOW);
  Serial.println("Back low");
  prevtime = currenttime;
}
}
