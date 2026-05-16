#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ESP32 Keyboard", "Espressif", 100);

// Функция медленной печати
void slowPrint(const char* text, int delayMs = 50) {
  for (int i = 0; i < strlen(text); i++) {
    bleKeyboard.print(text[i]);
    delay(delayMs);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Запуск BLE клавиатуры...");
  bleKeyboard.begin();
  
  // Ожидание подключения
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
  delay(3000);  

  bleKeyboard.press(KEY_LEFT_GUI);
  bleKeyboard.press('r');
  delay(200);
  bleKeyboard.releaseAll();
  delay(1000);  


  slowPrint("cmd", 80);
  delay(500);
  bleKeyboard.write(KEY_RETURN);
  delay(2000);  

  slowPrint("cd /d C:\\Users\\Admin\\PycharmProjects\\mthwb", 50);
  delay(500);
  bleKeyboard.write(KEY_RETURN);
  delay(1500);

  slowPrint(".venv\\Scripts\\activate.bat", 50);
  delay(500);
  bleKeyboard.write(KEY_RETURN);
  delay(1500);

  slowPrint("python main.py", 50);
  delay(500);
  bleKeyboard.write(KEY_RETURN);
}

void loop() {}
