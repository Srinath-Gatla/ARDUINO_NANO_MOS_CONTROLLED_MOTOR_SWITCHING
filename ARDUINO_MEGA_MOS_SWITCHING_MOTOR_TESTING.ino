const int buttonPin = 2;   // Push button connected to D2
const int mosfetPin = 9;   // Single pin to control all MOSFET gates (D9)

bool motorState = false;       // false = OFF, true = ON
bool lastButtonState = HIGH;   // for INPUT_PULLUP (HIGH = not pressed)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);   // Internal pull-up enabled
  pinMode(mosfetPin, OUTPUT);         // Single pin for all MOSFETs

  // Ensure motor is OFF at start
  digitalWrite(mosfetPin, LOW);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // Check for button press (transition HIGH -> LOW)
  if (lastButtonState == HIGH && buttonState == LOW) {
    motorState = !motorState;   // Toggle motor state

    if (motorState) {
      // Turn motor ON → MOSFET pin HIGH
      digitalWrite(mosfetPin, HIGH);
    } else {
      // Turn motor OFF → MOSFET pin LOW
      digitalWrite(mosfetPin, LOW);
    }

    delay(50);  // debounce delay
  }

  lastButtonState = buttonState;  // Save state for next loop
}