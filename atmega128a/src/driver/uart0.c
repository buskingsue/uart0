#include "uart0.h"
//프로그램 보낼때는 보드의 isp모드
//그다음 uarto모드
// sudo apt install moserial
//ls /dev/tty*
//sudo chmod 777 /dev/ttyUSB0
//ls -l /dev/ttyUSB0
void uart0Init()
{
    //통신속도 9600 bps
    UBRR0H = 0;
    UBRR0L = 207;
    //2배속 모드
    UCSR0A |= (1<<U2X0);
    // 비동기, 8비트, 패리티 없음, 1비트 stop
    //UCSR0C |=()초기값으로 설정 되있음
    UCSR0B |= (1<<RXEN0);//수신가능
    UCSR0B |= (1<<TXEN0);//송신가능

}
void uart0Transmit(char data)
{
    while (!(UCSR0A & (1<<UDRE0))); 
    //UDRE0에서 E 한글자가 빠져 있었음
    //송신가능 대기, udr이 비어 있는지 
    //ctc 모두와 같음
    UDR0 = data;
}

unsigned uart0Receive(void)
{
    while(!(UCSR0A & (1<<RXC0)));

    return UDR0;
}