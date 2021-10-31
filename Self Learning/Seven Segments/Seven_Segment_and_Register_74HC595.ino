#define OFF ~255
// untuk brightness
#define BRIGHTNESS 100
// konversi angka
// 8 bit data : A B C D E F G DP
const byte Angka[] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110 // - 
};
// konfigurasi pin Arduino
const byte DataPin = 2; // data
const byte LatchPin = 3; // ST_CP
const byte ClockPin = 4; // SH_CP
// untuk mengontrol digit,
// kita masih pakai pin Arduino
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
