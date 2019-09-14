
# For compiling FW
fw:
	pio run -e attiny85

# For running unit tests
test:
	pio test -e native

# For loading onto MCU
install: fw
	avrdude -c usbtiny -p t85 -U flash:w:.pio/build/attiny85/firmware.hex

# For checking the status of the programmer
status:
	avrdude -c usbtiny -p t85