#include <Mouse.h>
#include <Keyboard.h>
#include <Encoder.h>

// Encoder Pins
#define ENC_CLK 16
#define ENC_DT 14
#define ENC_SW 15

// Nuova mappa con 9 tasti
const int buttons[] = {8, 9, 10, 5, 6, 7, 2, 3, 4};

// Mappa tasti semplici
const char simpleKeys[] = {'a', '1', '5', 'z'}; // primi 4

// Encoder
Encoder encoder(ENC_CLK, ENC_DT);
long previousPosition = 0;

void setup() {
    Mouse.begin();
    Keyboard.begin();
    pinMode(ENC_SW, INPUT_PULLUP);
    for (int i = 0; i < 9; i++) {
        pinMode(buttons[i], INPUT_PULLUP);
    }
}

void loop() {
    // Encoder scroll
    long currentPosition = encoder.read();
    if (currentPosition > previousPosition) {
        Mouse.move(0, 0, 1);
    } else if (currentPosition < previousPosition) {
        Mouse.move(0, 0, -1);
    }
    previousPosition = currentPosition;

    // Encoder click: Ctrl+0
    if (digitalRead(ENC_SW) == LOW) {
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('0');
        delay(200);
        Keyboard.releaseAll();
    }

    // Pulsanti
    for (int i = 0; i < 9; i++) {
        if (digitalRead(buttons[i]) == LOW) {
            switch (i) {
                case 0: Keyboard.write(simpleKeys[0]); break; // 'a'
                case 1: Keyboard.write(simpleKeys[1]); break; // '1'
                case 2: Keyboard.write(simpleKeys[2]); break; // '5'
                case 3: Keyboard.write(simpleKeys[3]); break; // 'z'

                case 4: // Ctrl + C
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press('c');
                    delay(200);
                    Keyboard.releaseAll();
                    break;
                case 5: // Ctrl + V
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press('v');
                    delay(200);
                    Keyboard.releaseAll();
                    break;
                case 6: // Ctrl + Alt + Canc
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press(KEY_LEFT_ALT);
                    Keyboard.press(KEY_DELETE);
                    delay(200);
                    Keyboard.releaseAll();
                    break;
                case 7: // Ctrl + Z
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press('z');
                    delay(200);
                    Keyboard.releaseAll();
                    break;
                case 8: // Ctrl + Shift + Z
                    Keyboard.press(KEY_LEFT_CTRL);
                    Keyboard.press(KEY_LEFT_SHIFT);
                    Keyboard.press('z');
                    delay(200);
                    Keyboard.releaseAll();
                    break;
            }
            delay(250); // debounce
        }
    }
}
