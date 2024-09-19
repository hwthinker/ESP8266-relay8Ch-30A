# Modul ESP8266 ESP-12f Relay 8 Channel 10A 
![](https://github.com/hwthinker/esp8266-relay8ch-30A/blob/main/picture/3.png)


## koneksi
| Board | Serial USB         |
|-----  |--------------------|
| 5v    | x (tidak terhubung)| 
| txd   | rx ( Putih)        |
| rxd   | tx ( Hijau )       |
| Gnd   | GND ( Hitam )      |
| GND   | x (tidak terhubung)| 
| GPIO0 | x (tidak terhubung)| 

## Cara download dengan Serial USB biasa
![](https://github.com/hwthinker/esp8266-relay8ch-30A/blob/main/picture/2.png)
- Pasang serial USB TTL dengan ketentuan: 
   - TX Board-> RX USB Serial (Kabel Putih)
   - RX Board-> TX USB Serial (Kabel Hijau)
   - GND Board-> GND USB Serial (Kabel Hitam)
   - 5V Board-> x (not connected)
- Tekan dan Tahan tombol Key (GPIO0)
- Tekan dan lepas tombol reset
- Lepas tombol Key
- Upload program sederhana(bisa blink lED arduino)
- Tunggu upload selesai
- Reset (wajib) supaya program baru running
- Ulangi prosedur diatas bila upload program lagi.

## Kode Program
- Kode program bisa dicek di link https://github.com/hwthinker/esp8266-relay8ch-10A/blob/main/src/main.cpp 

## Warning:❗⚠️
Aktifkan daya untuk menghidupkan alat hanya dengan satu jenis sumber daya, bisa 9VDC atau 5VDC. Jangan menghubungkan beberapa sumber daya secara bersamaan, karena akan menyebabkan kerusakan pada alat.