# ARDUINO_NANO_MOS_CONTROLLED_MOTOR_SWITCHING

**Components in the Schematic:**

**Arduino Nano (NANO1) –** Used as the microcontroller to control MOSFETs.

**Push Button (with pull-down resistor R4 = 10kΩ) –** Provides manual input.

**MOSFETs (Q1, Q2, Q3 = IRLZ44N) –** Act as electronic switches to control the high-voltage motor load.

**Resistors (R1, R2, R3 = 220Ω) –** Gate resistors to limit current when charging/discharging MOSFET gates.

**DC Motor (right side) –** The load being powered.

**Power Supply (V1 = 50.4V) –** External motor power source (much higher than Arduino’s 5V).

**Ground (common GND) –** Shared between Arduino, MOSFETs, and motor supply.

**How It Works:**

Button Input

The push button is connected to D2 (Arduino Nano pin).

R4 (10kΩ) is a pull-down resistor, so the input is normally LOW (0).

When pressed, the button connects D2 to +5V, making it HIGH (1).

Arduino Output to MOSFETs

Arduino pin D3 is connected to R1, R2, R3.

These resistors go to the Gates of Q1, Q2, Q3.

This means one single Arduino pin controls all three MOSFETs at once.

MOSFET Switching

The MOSFETs (IRLZ44N, logic-level type) are acting as low-side switches.

When Arduino outputs HIGH on D3 → gates go HIGH → Q1, Q2, Q3 turn ON → motor gets connected to ground → motor runs.

When Arduino outputs LOW on D3 → MOSFETs OFF → motor disconnects → motor stops.

Power Separation

Arduino runs at 5V USB or regulated supply.

Motor runs at 50.4V external supply.

Grounds must be common (already shown in your schematic).

**Why 3 MOSFETs?**

Normally one MOSFET would be enough to control the motor.
But you are using 3 MOSFETs in parallel (all gates, sources, and drains tied together).

**Purpose of this:**

To share current load among multiple MOSFETs.

For example, if the motor requires very high current (say 60A), instead of one MOSFET overheating, three MOSFETs split the current (20A each).

This increases efficiency and reliability.

 **Behavior:**

Button released (LOW): Arduino sees LOW → outputs LOW on D3 → MOSFETs OFF → motor OFF.

Button pressed (HIGH): Arduino sees HIGH → outputs HIGH on D3 → MOSFETs ON → motor runs on 50.4V supply.

**Important Notes:**

You must use logic-level MOSFETs (like IRLZ44N, good choice).

Heatsinks may be required depending on motor current.

Flyback diode (like 1N5408 or fast recovery diode) should be placed across the motor to protect MOSFETs from back-EMF (I don’t see it in your schematic).
