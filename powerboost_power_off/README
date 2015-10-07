Allows Arduino to power itself off when powered by an Adafruit Powerboost 1000.

Assumes a NC switch in series with an NPN transistor from EN to GND.

A resistor is then connected to the NPN's base to V+.

The Arduino pin 12 is then connected to the NPN's base.

Normally, EN is shorted to ground, disabling the system.

When the push button is pressed, it raises EN to high, enabling the system.

Once the Arduino starts to run, it sets its own pin low to keep EN high.

Then, to turn itself off, it sets its pin high, activating the NPN transistor and setting EN low.

Circuit1 was manually confirmed to work, but requires a transistor.

Circuit2 is simpler, but untested, and assumes you've removed the pullup resistor on EN, otherwise the pulldown resistor will create a constant load across the battery even when the Powerboost is off.