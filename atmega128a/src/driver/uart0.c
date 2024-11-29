#include "uart0.h"
//프로그램 보낼때는 보드의 isp모드
//그다음 uarto모드
// sudo apt install moserial
//ls /dev/tty*
//sudo chmod 777 /dev/ttyUSB0
//ls -l /dev/ttyUSB0
void UART0_init(unsigned int baud) {
    unsigned int ubrr = F_CPU / 16 / baud - 1; // UBRR 값 계산
    UBRR0H = (unsigned char)(ubrr >> 8);       // 상위 8비트 설정
    UBRR0L = (unsigned char)ubrr;             // 하위 8비트 설정
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);     // 송신(TX)과 수신(RX) 활성화
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);   // 데이터 프레임: 8비트, 1 스톱 비트, 비패리티
}
void UART0_transmit(unsigned char data)
{
    while (!(UCSR0A & (1<<UDRE0))); 
    //UDRE0에서 E 한글자가 빠져 있었음
    //송신가능 대기, udr이 비어 있는지 
    //ctc 모두와 같음
    UDR0 = data;
}

// 문자열 송신 함수
void UART0_transmit_string(const char *str) {
    while (*str) {
        UART0_transmit(*str++);
    }
}

unsigned UART0_receive(void)
{
    while(!(UCSR0A & (1<<RXC0)));

    return UDR0;
}