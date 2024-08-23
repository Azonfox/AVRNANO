Прошивка различных плат Arduino:

#328	avrdude -v -p ${MCU}    -carduino -P ${usbport}   -b57600 -D -Uflash:w:${TARGET}.hex:i
#uno	avrdude -v -p ${MCU}    -carduino -P /dev/ttyACM0   -b115200 -D -Uflash:w:${TARGET}.hex:i
#168	avrdude -v -patmega168 -carduino -P /dev/ttyUSB0   -b19200 -D -Uflash:w:${TARGET}.hex:i
