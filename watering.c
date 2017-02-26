//This is for arduino code to water plants in Mammoth.
//Supplies needed: 1 arduino per major plant, 9V battery and connector, 1 USB B cable, soil sensor, pump, activated switches, led.

//circuit: VDIV on battery output on pin A0
//soil sensor output on A1
//pump activation output on pin 2
//Battery LOW LED on pin 3
int batterysensor = A0;
int soilsensor = A1;
int pumpswitch = 2;
int led = 3;
int soilvalue;
unsigned long time;
unsigned long prevtime;
boolean extreme = false;

void setup(){

Serial.begin(9600); //mostly for debugging
pinMode(batterysensor, INPUT);
pinMode(soilsensor, INPUT);
pinMode(pumpswitch, OUTPUT);
pinmode(led, OUTPUT);

prevtime = 0;

}

void loop(){
//do I want to record when it last watered so I get a sense of how often it gets watered?

// once a minute, check the soil sensor value and battery value
soilvalue = analogRead(soilsensor);
batteryvalue = analogRead(batterysensor);

currenttime = millis();
if (currenttime-prevtime > 1000){ //every minute, 1000 milliseconds in a minute

if (soilvalue <= && soilvalue >= ){
    //perfect range
    //If it's in the perfect range, go back to the timer
    return
}
if (soilvalue <= && soilvalue >= ){
    //tad of water
    //If it's below, give water for a little
    //calc prevtime
    and if !extreme (check)
    digitalWrite(pumpswitch, HIGH);
    //if time >prevTime by more than X seconds, go low
    digitalWrite(pumpswitch, LOW);
}
if (soilvalue < || soilvalue > || batteryvalue < 100){
    //way extreme
    //If it's ABOVE the perfect range or wayyy below (aka something went wrong), shut off all functionality besides the LED pin on high
    //if battery is low, turn on the light. for now. stretch goal: make it somehow communicate to us wherever wer are

    digitalWrite(led, HIGH);
    extreme = true;

}
prevtime = currenttime;

}
}
