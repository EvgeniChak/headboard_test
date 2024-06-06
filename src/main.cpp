#include <Arduino.h>
#include <EncButton.h>
#include <GyverIO.h>

Button lowerButton = 2;
Button upperButton = 3;

void setup() {
    Serial.begin(9600);
    upperButton.setBtnLevel(HIGH);
    upperButton.setClickTimeout(500);

    lowerButton.setBtnLevel(HIGH);
    lowerButton.setClickTimeout(500);
}

void loop() {
    lowerButton.tick();
    upperButton.tick();

    if (upperButton.press() || upperButton.click() || upperButton.holding())
        Serial.println("Upper button pressed");

    if (lowerButton.press() || lowerButton.click() || lowerButton.holding())
        Serial.println("Lower button pressed");
}