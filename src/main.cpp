#include <Arduino.h>
// The ISR can change it at any moment
volatile int counter =0; // Main program and ISR(Interrupt Service Routine) both access this variable 

//The timer physically exists inside the ESP-32 hardware
//This is just a pointer that lets our software control it
hw_timer_t *timer = NULL;

//The function that executes when the interrupt happens
void IRAM_ATTR timerISR(){  //IRAM_ATTR tells compiler to keep this function in 
    //internal RAM so it acan execute quickly
    counter++;
}
void setup(){
    Serial.begin(115200); //Start Serial Communication
    timer = timerBegin(0, 80, true);//Timer frequency = 1MHz
    timerAttachInterrupt(timer, &timerISR,true);
    timerAlarmWrite(timer, 1000000,true);
    timerAlarmEnable(timer);



}
void loop(){
    Serial.println(counter);
    delay(1000);
}