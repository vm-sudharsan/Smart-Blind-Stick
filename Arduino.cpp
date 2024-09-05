const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;
const int thresholdDistance = 10; // Distance threshold in centimeters

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is below the threshold
  if (distance <= thresholdDistance) {
    // Activate the buzzer
    digitalWrite(buzzerPin, HIGH);
  } else {
    // Deactivate the buzzer
    digitalWrite(buzzerPin, LOW);
  }

  // Wait for 100 milliseconds before the next reading
  delay(100);
}
