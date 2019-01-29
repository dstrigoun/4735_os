#include "hal.h"

void hal_io_serial_init() {
    uart_init();
}

void hal_io_serial_putc(uint32_t address, uint8_t c) {
    switch(address) {
        case SERIAL_ID:
            uart_putc(c);
        default:
            break;
    }
}

uint8_t hal_io_serial_getc(uint32_t address) {
    switch(address) {
        case SERIAL_ID:
            return uart_getc();
        default:
            return 0;
            break;
    }
}

void hal_io_video_init() {
	_video_init();
	_video_sample();
}
