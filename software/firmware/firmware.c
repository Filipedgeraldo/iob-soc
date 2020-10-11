//#include "stdlib.h"
#include "system.h"
#include "periphs.h"
#include "iob-uart.h"

int main()
{
  unsigned long long elapsed ;
  unsigned int elapsedu ;

  timer_reset(TIMER_BASE);

  
  //init uart 
  uart_init(UART_BASE,FREQ/BAUD);   
  uart_printf("\n\n\nHello world!\n\n\n");
  uart_txwait();

  //read current time
  elapsed = timer_get_count(TIMER_BASE);
  elapsedu = timer_time_us(TIMER_BASE);
  uart_printf("\nExexution time: %d clocks: %d us at %d MHz\n\n",(unsigned int) elapsed, elapsedu,FREQ/1000000);
  uart_txwait();
  
  //char *a = malloc(10);
  //free(a);

  return 0;
}
