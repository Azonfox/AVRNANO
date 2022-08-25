cd D:\avr\nano\Load

rem avrdude -Cavrdude.conf -v -patmega328p -carduino -PCOM4 -b57600 -D -Ueeprom:w:..\default\test1.eep:i

avrdude -Cavrdude.conf -v -patmega328p -carduino -PCOM4 -b57600 -D -Uflash:w:d:\avr\nano\default\test1.hex:i 



pause

