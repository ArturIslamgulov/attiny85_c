#include <softuart.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#define READ_PIN PB0

int main()
{
	softuart_init();
  char count[3];
  uint8_t i = 0;
  DDRB &= 0 << READ_PIN;
  uint8_t char_count = 2;
  
	while(1)
	{
		if( !(PINB & 0b00000001 )){
      i++;
      while(i){
      count[char_count] = i % 10;
      i /= 10;
      char_count--;
      }
     char_count = 2;
    softuart_puts(count);
	};
  }
}
