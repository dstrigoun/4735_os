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
}

void hal_io_video_putpixel(int x, int y, uint32_t color) {
    _draw(x, 1280*y, color);    
}

void hal_io_video_putc(int x, int y, int color, uint8_t c) {
    for (int ypos = 0; ypos < 21; ypos++) {
        for (int xpos = 0; xpos < 11; xpos++) {
            switch(c) {
                case 'a':
                    if (aChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'b':
                    if (bChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'c':
                    if (cChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'd':
                    if (dChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'e':
                    if (eChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'f':
                    if (fChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'g':
                    if (gChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'h':
                    if (hChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'i':
                    if (iChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'j':
                    if (jChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'k':
                    if (kChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'l':
                    if (lChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'm':
                    if (mChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'n':
                    if (nChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'o':
                    if (oChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'p':
                    if (pChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'q':
                    if (qChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'r':
                    if (rChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 's':
                    if (sChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 't':
                    if (tChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'u':
                    if (uChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'v':
                    if (vChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'w':
                    if (wChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'x':
                    if (xChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'y':
                    if (yChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
                case 'z':
                    if (zChar[ypos][xpos] == 1) {
                        hal_io_video_putpixel(x+xpos, y+ypos, color);
                    }
                    break;
            }
        }
    }
}
