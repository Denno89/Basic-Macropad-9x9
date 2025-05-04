#include <Mouse.h>
#include <Keyboard.h>
#include <Encoder.h>

// Encoder Pins
#define ENC_CLK 16  // Clock
#define ENC_DT 14  // Data
#define ENC_SW 15   // Encoder button

// Switch Pins (in order according to the new layout)
const int numKeys = 9;
const int keyPins[numKeys] = {8, 9, 10, 5, 6, 7, 2, 3, 4};
const char keyChars[numKeys] = {'l', 'c', 'x', 'f', 'k', 't', 'e', 'u', 'o'};

Encoder encoder(ENC_CLK, ENC_DT);
long previousPosition = 0;

void setup() {
    for (int i = 0; i < numKeys; i++) {
      pinMode(keyPins[i], INPUT_PULLUP);
    }
    Keyboard.begin();
    Mouse.begin();
}

void loop() {

    // Encoder scroll 
    long currentPosition = encoder.read();
    if (currentPosition > previousPosition) {
        Mouse.move(0, 0, 1); // Scroll UP (Zoom in)
    } 
    else if (currentPosition < previousPosition) {
        Mouse.move(0, 0, -1); // Scroll DOWN (Zoom out)
    }
    previousPosition = currentPosition;

    // Encoder Press (CTRL + Z)
    if (digitalRead(ENC_SW) == LOW) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('z');
        delay(200);
        Keyboard.releaseAll();
    }

    // Key Press
    for (int i = 0; i < numKeys; i++) {
        if (digitalRead(keyPins[i]) == LOW) {
            Keyboard.write(keyChars[i]);
            delay(200); // Debounce
        }
    }
}