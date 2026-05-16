#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ESP32 Keyboard", "Espressif", 100);

void setup() {
    Serial.begin(115200);
    Serial.println("Запуск BLE клавиатуры...");
    bleKeyboard.begin();
  
    unsigned long startTime = millis();
    while (!bleKeyboard.isConnected() && millis() - startTime < 10000) {
        delay(500);
        Serial.print(".");
    }

    if (!bleKeyboard.isConnected()) {
        Serial.println("\nНе удалось подключиться!");
        return;
    }

    Serial.println("\nПодключено!");
    delay(2000);


    delay(500);


    bleKeyboard.press(KEY_LEFT_GUI);
    bleKeyboard.press('r');
    delay(100);
    bleKeyboard.releaseAll();
    delay(500);


    bleKeyboard.print("dxdiag");
    delay(500);
    bleKeyboard.write(KEY_RETURN);
}

void loop() {
}
