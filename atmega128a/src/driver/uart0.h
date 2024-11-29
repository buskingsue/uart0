#include "common/def.h"

void UART0_init(unsigned int baud);
void UART0_transmit(unsigned char data);
unsigned UART0_receive(void);
void UART0_transmit_string(const char *str);
