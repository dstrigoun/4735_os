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

void hal_io_video_putpixel(int x, int y, int color) {
    // y     -> add fb, (#1280 * y)
    // x     -> add fb, x
    // color -> get hex... (#0xFFFFFFFF)
}

void hal_io_video_putc(int x, int y, int color, uint8_t c) {
    // get pattern for letter
    // start at (x, y)
        // call hal_io_video_putpixel for each x and y

    switch (c) {
        case 'a':
            break;
    }
}
