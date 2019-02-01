/*
*	
*	The Kernel
*	
*/

#include "kernel.h"

/*
 *		Kernel's entry point
 *
**/
void main(uint32_t r0, uint32_t r1, uint32_t atags){
	
	hal_io_video_init();
	
	
	//Begin the one-line typewriter
	hal_io_serial_init();
	
	hal_io_serial_putc( SERIAL_ID, 'H' );
	hal_io_serial_putc( SERIAL_ID, 'e' );
	hal_io_serial_putc( SERIAL_ID, 'l' );
	hal_io_serial_putc( SERIAL_ID, 'l' );
	hal_io_serial_putc( SERIAL_ID, 'o' );
	hal_io_serial_putc( SERIAL_ID, '\n' );
	hal_io_serial_putc( SERIAL_ID, '\r' );
 
	while (1)
		hal_io_serial_putc( SERIAL_ID, hal_io_serial_getc(SERIAL_ID) );  // <<---- This is why your CPU goes crazy when you run the kernel
}
