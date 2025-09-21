#define SENSOR_PIN A0      // ACS712 OUT pin connected to NodeMCU A0
#define SAMPLES 200        // Number of samples for RMS calculation
#define VREF 3.3           // ADC reference voltage for NodeMCU
#define ADC_RES 1024.0     // 10-bit ADC (0–1023)

// Sensitivity (mV per Ampere) based on ACS712 version
// Change according to your module: 185 (5A), 100 (20A), 66 (30A)
#define SENSITIVITY 66.0  

// Vcc/2 (zero current voltage) in volts
#define ZERO_CURRENT_VOLTAGE (VREF / 2.0)

void setup() {
  Serial.begin(9600);
  Serial.println("ACS712 Current Measurement Started...");
}

void loop() {
  float sum = 0;

  // Collect samples
  for (int i = 0; i < SAMPLES; i++) {
    int adcValue = analogRead(SENSOR_PIN);
    float voltage = (adcValue / ADC_RES) * VREF;
    float current = (voltage - ZERO_CURRENT_VOLTAGE) * 1000 / SENSITIVITY; // mA → A
    sum += sq(current);  // Square value
    delayMicroseconds(200); // Small delay for stable sampling
  }

  // Calculate RMS current
  float Irms = sqrt(sum / SAMPLES);

  Serial.print("Current: ");
  Serial.print(Irms, 3);
  Serial.println(" A");

  delay(1000); // 1 sec delay
}
