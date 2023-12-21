MCU=atmega328p
F_CPU=1600000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -Wall -g -O0 -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=main
SRCS=main.c 
usbport=/dev/ttyUSB0

all:
	${CC} ${CFLAGS} -o ${TARGET}.bin  ${SRCS}
	#${CC} -mmcu=${MCU} -Wl,-Map=main.map  ---- error
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex
	avr-objdump -h -S ${TARGET}.bin > ${TARGET}.lst
	avr-size -C --mcu=${MCU} ${TARGET}.bin
upload:
	avrdude -v -p ${MCU}    -carduino -P ${usbport}   -b57600 -D -Uflash:w:${TARGET}.hex:i

eep:
	avrdude -v -p ${MCU}    -carduino -P ${usbport}   -b57600 -D -Ueeprom:w:${TARGET}.eep:i

clean:
	rm -f *.bin *.hex *.map *.lst

	# -O ${TARGET}.map -O ${TARGET}.lst
#   -Wa,-Map=main.map
