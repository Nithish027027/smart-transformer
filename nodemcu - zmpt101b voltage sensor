#include <ZMPT101B.h>

// Define the analog pin connected to ZMPT101B
#define SENSITIVITY 265.0  // Adjust after calibration
#define ZMPT_PIN A0

// Create ZMPT101B object
ZMPT101B voltageSensor(ZMPT_PIN, 50.0);  // 50.0 = frequency (Hz)

void setup() {
  Serial.begin(9600);

  // Set sensitivity (calibrate this value)
  voltageSensor.setSensitivity(SENSITIVITY);

  Serial.println("ZMPT101B Voltage Measurement Started...");
}

void loop() {
  // Get RMS voltage
  float voltage = voltageSensor.getRmsVoltage();

  // Print to Serial Monitor
  Serial.print("AC Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(1000);  // 1 second delay
}
