#include <string.h>

const int PLOT_POINTS = 360;
int plotCounter = 0;

void setup() {
  Serial.begin(9600);  // Initialize Serial communication at 9600 baud rate
  while (!Serial) {
    ; // Wait for Serial port to connect. Needed for native USB port only
  }
}
 
void loop() {

  // Add data for Serial Plotter
  Serial.println("\n--- Data for Serial Plotter ---");
  for (int i = 0; i < PLOT_POINTS; i++) {
    float angle = (i + plotCounter) * (2 * PI / PLOT_POINTS);
    float sineValue = sin(angle);
    float cosineValue = cos(angle);
    
    Serial.print("Sine:");
    Serial.print(sineValue);
    Serial.print(",Cosine:");
    Serial.println(cosineValue);

    delay(10);  // Small delay to control the plot speed
  }

  plotCounter = (plotCounter + 1) % PLOT_POINTS;

  // Add a longer delay to make the output more readable
  delay(5000);  // Wait for 5 seconds before the next iteration
}
