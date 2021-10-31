/*
 * MONSTER ARDUINO V2
 * Program Seven Segmen 1D dg Shift Register
 * www.ElangSakti.com
*/

// common cathode
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
  B11110110, // 9
  B00000010  // -
};

// konfigurasi pin Arduino
const byte DataPin = 2; // data
const byte LatchPin = 3; // ST_CP
const byte ClockPin = 4; // SH_CP

// untuk mengontrol digit,
// kita masih pakai pin Arduino
// untuk lebih menghemat, bisa tambah
// IC shift register lagi
const byte Digit1 = A0;
const byte Digit2 = A1;
const byte Digit3 = A2;
const byte Digit4 = A3;
const byte DIGIT[] = {Digit1, Digit2, Digit3, Digit4};

// jumlah digit seven segment
const byte jumlah_digit = sizeof(DIGIT);

// digit terpilih untuk diaktifkan
byte DIGIT_SELECT = 0;

// pengaturan untuk brightness
unsigned long brightness_now = 0;
unsigned long brightness_last = 0;
unsigned long brightness_limit = 0;

int counter = 0;

  

void setup() {
  // konfigurasi pin sebagai output
  pinMode(LatchPin, OUTPUT);
  pinMode(ClockPin, OUTPUT);
  pinMode(DataPin, OUTPUT);

  // pastikan bahwa display mati
  for(byte i=0; i<sizeof(DIGIT);i++){
    pinMode(DIGIT[i],OUTPUT);
    digitalWrite(DIGIT[i],HIGH);
  }

  // pastikan semua segment mati
  // mulai transfer
  digitalWrite(LatchPin,LOW);
  // kirim data
  shiftOut(DataPin, ClockPin, LSBFIRST, OFF);
  // stop transfer
  digitalWrite(LatchPin,HIGH);
}

void loop() {
  // delay 1 detik
  if(nonblocking_delay(1000)){
    counter++;
    if(counter>=10000) counter=0;
  }

  // cetak angka
  PrintDigit(counter, jumlah_digit);
}

// fungsi untuk mencetak angka
// INPUT: angka dan jumlah_digit
void PrintDigit(int angka, byte jumlah_digit){

  // delay nyala segment, efeknya pada brightness
  brightness_limit = constrain(BRIGHTNESS,1,100);
  brightness_limit = map(brightness_limit,1,100,1,5000);

  // konversi angka jadi string
  String numstr = String(angka);
  byte lenstr = numstr.length();

  // mulai transfer
  digitalWrite(LatchPin, LOW);
  brightness_now = micros();
  if(brightness_now - brightness_last < brightness_limit){
    // nyalakan digit yang dipilih
    digitalWrite(DIGIT[DIGIT_SELECT], LOW);

    if(DIGIT_SELECT < lenstr){
      // jika digit yang terpilih < jumlah angka
      // cetak angka pada digit tersebut
      byte angka = (numstr.substring(DIGIT_SELECT, DIGIT_SELECT + 1)).toInt();
      shiftOut(DataPin, ClockPin, LSBFIRST, Angka[angka]);
    }else {
        // jika tidak, matikan semua segment
        shiftOut(DataPin, ClockPin, LSBFIRST, OFF);
      }
    } else {
      // matikan semua digit
      for(byte d=0; d<sizeof(DIGIT); d++){
        digitalWrite(DIGIT[d], HIGH);
      }

      // matikan semua segment
      shiftOut(DataPin, ClockPin, LSBFIRST, OFF);

      DIGIT_SELECT++;
      if(DIGIT_SELECT >= lenstr) DIGIT_SELECT=0;

      brightness_last = brightness_now;
    }

    // stop transfer
    digitalWrite(LatchPin, HIGH);
}

// tambahan untuk membuat delay non blocking
  unsigned long nonblocking_time = millis();
  unsigned long nonblocking_last = millis();
  boolean nonblocking_delay(long milidetik){
    nonblocking_time = millis();
    if(nonblocking_time - nonblocking_last >= milidetik){
      nonblocking_last = nonblocking_time;
      return true;
    }
    return false;
  }
