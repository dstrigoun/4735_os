
/*
*	
*	The Kernel
*	
*/

#include "kernel.h"
#include "hal.h"

//uart
// void uart_init(void);
//void uart_putc(uint8_t);
uint8_t uart_getc();

//memory
//uint32_t memory_read(uint32_t);
// void memory_write(uint32_t, uint32_t );


// void delay(int32_t);


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
 

// /*
// *	From 
// *	https://wiki.osdev.org/Raspberry_Pi_Bare_Bones#Building_a_Cross-Compiler
// *
// */
// void delay(int32_t count) {
// 	asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n"
// 		 : "=r"(count): [count]"0"(count) : "cc");
// }
 
 
// /*
// *	From 
// *	https://wiki.osdev.org/Raspberry_Pi_Bare_Bones#Building_a_Cross-Compiler
// *
// */
// void uart_init(void){
	
// 	// Disable UART0.
// 	memory_write(UART0_CR, 0x00000000);
// 	// Setup the GPIO pin 14 && 15.
 
// 	// Disable pull up/down for all GPIO pins & delay for 150 cycles.
// 	memory_write(GPPUD, 0x00000000);
// 	delay(150);
 
// 	// Disable pull up/down for pin 14,15 & delay for 150 cycles.
// 	memory_write(GPPUDCLK0, (1 << 14) | (1 << 15));
// 	delay(150);
 
// 	// Write 0 to GPPUDCLK0 to make it take effect.
// 	memory_write(GPPUDCLK0, 0x00000000);
 
// 	// Clear pending interrupts.
// 	memory_write(UART0_ICR, 0x7FF);
 
// 	// Set integer & fractional part of baud rate.
// 	// Divider = UART_CLOCK/(16 * Baud)
// 	// Fraction part register = (Fractional part * 64) + 0.5
// 	// UART_CLOCK = 3000000; Baud = 115200.
 
// 	// Divider = 3000000 / (16 * 115200) = 1.627 = ~1.
// 	memory_write(UART0_IBRD, 1);
// 	// Fractional part register = (.627 * 64) + 0.5 = 40.6 = ~40.
// 	memory_write(UART0_FBRD, 40);
 
// 	// Enable FIFO & 8 bit data transmissio (1 stop bit, no parity).
// 	memory_write(UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));
 
// 	// Mask all interrupts.
// 	memory_write(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
// 	                       (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));
 
// 	// Enable UART0, receive & transfer part of UART.
// 	memory_write(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
// }
 