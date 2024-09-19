//*****************************************
// Program check Modul Relay 8ch ESP-12F
// v1.0 september 17,2023 by HwThinker
// ****************************************

// ---Komunikasi Modul dengan serial programmer ----
// 5v-> x (not connected)
// tx-> rx(kabel putih)
// rx-> tx(kabel hijau)
// Gnd-> GND (kabel hitam)
// GND-> x (not connected)
// GPIO0->x (no connected)

// --- Prosedur upload -----
// 1. Tekan dan Tahan tombol Key (GPIO0)
// 2. Tekan dan lepas tombol reset
// 3. Lepas tombol Key
// 4. upload program sederhana(bisa blink lED arduino)
// 5. tunggu upload selesai
// 6. reset (wajib) supaya program baru running
// 7. Ulangi prosedur diatas bila upload program lagi.


#include <Arduino.h>

// hubungan koneksi antara PIN ESP-12F dengan  74HC595
const int latchPin = 12;   // Pin ST_CP (RCLK/12)
const int clockPin = 13;  // Pin SH_CP (SRCLK/11)
const int dataPin = 14;   // Pin DS (SER/14)
const int OE = 5;   // Pin OE (SER/13)

//untuk pin SRCLR(10) pada 74HC595 tidak sudah dikawatkan dengan VCC secara default.

const int LED_internal=2; //led internal pada modul ESP-12F
const int key = 0;   // Tombol  yang tersambung ke GPIO0

void setup() {
  // Atur pin sebagai OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(OE, OUTPUT);
  pinMode(LED_internal, OUTPUT);
  digitalWrite(OE,LOW); //aktif LOW
}

void loop() {
  // Array untuk menyimpan pola LED
  byte rlyPola[] = {
    B00000001,
    B00000010,
    B00000100,
    B00001000,
    B00010000,
    B00100000,
    B01000000,
    B10000000
  };

  // Loop untuk menghidupkan Relay satu per satu
  for (int i = 0; i < 8; i++) {
    // Kirim pola ke 74HC595
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, rlyPola[i]);
    digitalWrite(latchPin, HIGH);
    //blinky LED internal
    digitalWrite(LED_internal, !digitalRead(LED_internal));
    // Tunggu sebentar sebelum menghidupkan Relay berikutnya
    delay(800);
  }

  // Matikan semua LED
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, B00000000);
  digitalWrite(latchPin, HIGH);

  // Tunggu sebentar sebelum mengulangi loop
  delay(1000);
}