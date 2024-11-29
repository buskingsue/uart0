#include "ap.h"
#include "driver/led.h"
#include "driver/button.h"
#include "driver/pwm8.h"
#include "driver/uart0.h"
#include <avr/interrupt.h>
#include <driver/pwm16.h>
// 속도 증가 함수


// 속도 감소 함수

void apInit()
{
    UART0_init(9600); // UART 초기화, 통신 속도 9600 bps

    UART0_transmit_string("UART0 Ready\r\n");// 초기화가 필요한 부분이 있다면 여기에 추가

    // B포트 0번 핀을 출력으로 설정
    DDRB |= (1 << PB0); // DDRB의 0번 비트를 1로 설정
    PORTB &= ~(1 << PB0); // 초기값은 OFF (LOW)
}

void apMain(void)
{
    while (1)
    {
       
        unsigned char received = UART0_receive(); // 데이터 수신
        if (received == '\r' || received == '\n') {
            continue;
        }
        if (received == 'a') 
        { 
            UART0_transmit_string("LED ON\r\n");  // "LED ON" 메시지 출력
            PORTB |= (1 << PB0); // B포트 0번 핀 HIGH (LED ON)
        } else if (received == 'b') {
            UART0_transmit_string("LED OFF\r\n"); // "LED OFF" 메시지 출력
            PORTB &= ~(1 << PB0); // B포트 0번 핀 LOW (LED OFF)
        } else  {
            UART0_transmit_string("Invalid Input\r\n"); // 잘못된 입력 메시지 출력
        }
    }
}
