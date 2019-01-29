#include "ass.h"

#define SERIAL_ID 1

void _video_init(void);
void _video_sample(void);

void hal_io_serial_init();
void hal_io_serial_putc(uint32_t address, uint8_t c);
uint8_t hal_io_serial_getc(uint32_t address);

void hal_io_video_init();
// void hal_io_video_putpixel(int x, int y, int color);

// void hal_io_video_putc(int x, int y, int color, uint8_t c);
