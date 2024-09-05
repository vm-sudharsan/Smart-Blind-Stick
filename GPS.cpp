#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// Create a TinyGPS++ object
TinyGPSPlus gps;

// Set up software serial on pins D1 (TX) and D2 (RX)
SoftwareSerial ss(D1, D2);

void setup()
{
  // Start the serial communication with the computer
  Serial.begin(115200);
  // Start the serial communication with the GPS module
  ss.begin(9600);

  Serial.println(F("GPS Module Test"));
}

void loop()
{
  // Read data from the GPS module
  while (ss.available() > 0)
  {
    gps.encode(ss.read());
    // If a new valid GPS data is available
    if (gps.location.isUpdated())
    {
      Serial.print(F("Latitude: "));
      Serial.println(gps.location.lat(), 6);
      Serial.print(F("Longitude: "));
      Serial.println(gps.location.lng(), 6);
      Serial.print(F("Altitude: "));
      Serial.println(gps.altitude.meters());
      Serial.print(F("Speed: "));
      Serial.println(gps.speed.kmph());
      Serial.print(F("Satellites: "));
      Serial.println(gps.satellites.value());
    }
  }
}
