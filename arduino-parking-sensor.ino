// Ho dovuto mettere degli asterischi al posto dei dati sensibili (secret data)
// in seguito alla pubblicazione di questo file, quindi non sarà eseguibile così com'è.

// Pin definitions
int ECHO = 2;
int TRIG = 3;
int PIEZO = 12;

// Variables for distance measurement
float distanza;
long durata;

// Timing variables
unsigned long startTime = 0;       // When the piezo started sounding
unsigned long soundDuration = 5000; // Max time to sound (5 seconds)
bool isPlaying = false;            // Indicates if the piezo is sounding
bool soundDisabled = false;        // Tracks if the piezo is disabled after 5 seconds
float lastDistance = -1;           // Tracks the last distance measured

void setup() {
  // Pin modes
  pinMode(PIEZO, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  // Send trigger pulse
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Measure echo duration
  durata = pulseIn(ECHO, HIGH);
  distanza = durata * 0.034 / 2;

  // Check if the distance has changed significantly
  if (abs(distanza - lastDistance) > 5) { // Tolerance for noise
    lastDistance = distanza;
    isPlaying = false;     // Reset playing state
    soundDisabled = false; // Allow the piezo to sound again
  }

  unsigned long currentTime = millis();

  // If the piezo is not disabled, allow it to play
  if (!soundDisabled) {
    if (!isPlaying) {
      startTime = millis(); // Reset the start time
      isPlaying = true;
    }

    // If within the allowed 5-second window
    if (currentTime - startTime < soundDuration) {
      if (distanza > 70 && distanza < 110) {
        digitalWrite(PIEZO, HIGH);
        delay(100);
        digitalWrite(PIEZO, LOW);
        delay(400);
      } 
      else if (distanza > 50 && distanza < 70) {
        digitalWrite(PIEZO, HIGH);
        delay(100);
        digitalWrite(PIEZO, LOW);
        delay(300);
      } 
      else if (distanza > 35 && distanza < 50) {
        digitalWrite(PIEZO, HIGH);
        delay(100);
        digitalWrite(PIEZO, LOW);
        delay(200);
      } 
      else if (distanza < 35) {
        digitalWrite(PIEZO, HIGH);
      } 
      else {
        digitalWrite(PIEZO, LOW);
      }
    } else {
      // If the 5 seconds have elapsed, disable the piezo
      digitalWrite(PIEZO, LOW);
      soundDisabled = true; // Prevent further sound until distance changes
    }
  } else {
    digitalWrite(PIEZO, LOW); // Ensure piezo remains off
  }

  delay(100); // Short delay to stabilize readings
}
