#include <Mouse.h>
#include <Keyboard.h>
#include <Encoder.h>

// Encoder pins (CLK, DT, SW)
#define ENC_CLK 16
#define ENC_DT 14
#define ENC_SW 15

// Define the 9 button input pins
const int buttons[] = {8, 9, 10, 5, 6, 7, 2, 3, 4};

// Simple key mapping for first 4 buttons (alphanumeric keys only)
const char simpleKeys[] = {'a', '1', '5', 'z'}; // Button 0 → 'a', 1 → '1', etc.

// Initialize encoder with CLK and DT pins
Encoder encoder(ENC_CLK, ENC_DT);
long previousPosition = 0;

void setup() {
    Mouse.begin();
    Keyboard.begin();
    
    pinMode(ENC_SW, INPUT_PULLUP); // Encoder button with internal pull-up
    
    // Set all button pins as input with internal pull-up resistors
    for (int i = 0; i < 9; i++) {
        pinMode(buttons[i], INPUT_PULLUP);
    }
}

void loop() {
    // --- ENCODER SCROLL FUNCTIONALITY ---
    // Move mouse scroll wheel based on encoder rotation
    long currentPosition = encoder.read();
    if (currentPosition > previousPosition) {
        Mouse.move(0, 0, 1); // Scroll up
    } else if (currentPosition < previousPosition) {
        Mouse.move(0, 0, -1); // Scroll down
    }
    previousPosition = currentPosition;

    // --- ENCODER BUTTON FUNCTION ---
    // If encoder button is pressed, send Ctrl + 0 (can be changed if needed)
    if (digitalRead(ENC_SW) == LOW) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('0');
        delay(200);
        Keyboard.releaseAll();
    }

    // --- MAIN BUTTON LOOP ---
    // Check each of the 9 buttons
    for (int i = 0; i < 9; i++) {
        if (digitalRead(buttons[i]) == LOW) {
            switch (i) {
                case 0: Keyboard.write(simpleKeys[0]); break; // Sends 'a'
                case 1: Keyboard.write(simpleKeys[1]); break; // Sends '1'
                case 2: Keyboard.write(simpleKeys[2]); break; // Sends '5'
                case 3: Keyboard.write(simpleKeys[3]); break; // Sends 'z'

                case 4: // Ctrl + C (Copy)
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press('c');
                    delay(200);
                    Keyboard.releaseAll();
                    break;

                case 5: // Ctrl + V (Paste)
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press('v');
                    delay(200);
                    Keyboard.releaseAll();
                    break;

                case 6: // Ctrl + Alt + Delete
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press(KEY_LEFT_ALT);
                    Keyboard.press(KEY_DELETE);
                    delay(200);
                    Keyboard.releaseAll();
                    break;

                case 7: // Ctrl + Z (Undo)
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press('z');
                    delay(200);
                    Keyboard.releaseAll();
                    break;

                case 8: // Ctrl + Shift + Z (Redo)
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press(KEY_LEFT_SHIFT);
                    Keyboard.press('z');
                    delay(200);
                    Keyboard.releaseAll();
                    break;
            }

            delay(250); // Basic debounce delay (can be adjusted)
        }
    }
}
