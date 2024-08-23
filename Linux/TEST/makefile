MCU=atmega328p
F_CPU=1600000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=main
SRCS=main.c 
usbport=/dev/ttyUSB0

all:
	${CC} ${CFLAGS} -o ${TARGET}.bin  ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex
	avr-objdump -h -S ${TARGET}.bin > ${TARGET}.lst
	avr-size -C --mcu=${MCU} ${TARGET}.bin
upload:
	avrdude -v -p ${MCU}    -carduino -P ${usbport}   -b57600 -D -Uflash:w:${TARGET}.hex:i
#uno	avrdude -v -p ${MCU}    -carduino -P /dev/ttyACM0   -b115200 -D -Uflash:w:${TARGET}.hex:i
#168	avrdude -v -patmega168 -carduino -P /dev/ttyUSB0   -b19200 -D -Uflash:w:${TARGET}.hex:i


eep:
	avrdude -v -p ${MCU}    -carduino -P ${usbport}   -b57600 -D -Ueeprom:w:${TARGET}.eep:i

clean:
	rm -f *.bin *.hex *.map *.lst

	# -O ${TARGET}.map -O ${TARGET}.lst
#   -Wa,-Map=main.map
#${CC} -mmcu=${MCU} -Wl,-Map=main.map  ---- error
