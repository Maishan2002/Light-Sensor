int input = A0;
int i = 0;
int totalReadings = 0;
int t1,t2;

void setup() {
  // put your setup code here, to run once:
  pinMode(input , INPUT);
  Serial.begin(9600);
  t1 = millis();
  t2 = millis();
  // Records the number of readings and the total of those readings within 1 second
  while(t2-t1 < 1000){
    totalReadings = totalReadings + analogRead(input);
    i+=1;
    delay(50);
    t2 = millis();
  }
}

void loop() {
  // Calculation of the Average Reading in terms of voltage
  int AvgReading = totalReadings/i;
  int AvgVoltage = AvgReading * (5./1023.);
  delay(500);
  // Current Reading of the Voltage on the photoresistor.
  int newReading = (analogRead(input) * (5./1023.));
  // Calculation of difference in relation to the average light intensity
  int lightDifference = AvgVoltage - newReading;
  Serial.println(lightDifference);

}
