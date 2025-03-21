#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD (Alamat I2C bisa 0x27 atau 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Deklarasi pin motor sebagai variabel global
const int IN1 = 7;
const int IN2 = 8;
const int ENA = 9; // Pin PWM untuk kecepatan motor

void setup() {
  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, Arduino!");

  // Atur pin sebagai output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
  // Nyalakan motor maju
  analogWrite(ENA, 150); // Atur kecepatan motor (0-255)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  lcd.setCursor(0, 1);
  lcd.print("Maju ");
  delay(5000); // Motor maju 5 detik

  // Nyalakan motor mundur
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("Mundur ");
  delay(5000); // Motor mundur 5 detik

  // Matikan motor
  analogWrite(ENA, 0); // Berhenti
  lcd.setCursor(0, 1);
  lcd.print("Berhenti ");
  delay(5000);
}
