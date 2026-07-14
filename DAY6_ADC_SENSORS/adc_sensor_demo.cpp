#include <Arduino.h>

#define SOIL_SENSOR_PIN 34

#define SAMPLES 10

int rawValue = 0;
int moisturePercentage = 0;


int readFilteredADC()
{
    long total = 0;

    for(int i = 0; i < SAMPLES; i++)
    {
        total += analogRead(SOIL_SENSOR_PIN);
        delay(10);
    }

    return total / SAMPLES;
}


void setup()
{
    Serial.begin(115200);

    // Increase ADC measurement range
    analogSetPinAttenuation(
        SOIL_SENSOR_PIN,
        ADC_11db
    );

    Serial.println("ESP32 ADC Soil Moisture Sensor Demo");
}


void loop()
{
    // Read filtered ADC value
    rawValue = readFilteredADC();


    // Convert ADC value to moisture percentage
    moisturePercentage = map(
        rawValue,
        3200,  // Dry soil calibration value
        1500,  // Wet soil calibration value
        0,
        100
    );


    // Limit value between 0-100%
    moisturePercentage = constrain(
        moisturePercentage,
        0,
        100
    );


    Serial.print("Filtered ADC: ");
    Serial.print(rawValue);

    Serial.print(" | Moisture: ");
    Serial.print(moisturePercentage);

    Serial.println("%");


    delay(5000);
}