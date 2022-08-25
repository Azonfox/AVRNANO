cd D:\avr\nano\Load
avrdude -Cavrdude.conf -v -patmega328p -carduino -PCOM4 -b57600 -D -Ueeprom:r:printer_eeprom.EEP:r
pause

