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
    // 초기화가 필요한 부분이 있다면 여기에 추가
}

void apMain(void)
{
  /*  // LED 초기화
    LED led;
    led.port = &PORTB;
    led.pinNumber = 0;
    ledInit(&led);

    // 버튼 초기화
    Button btnOn;
    Button btnOff;
    Button btnTog;

    Button_init(&btnOn, &BUTTON_DDR, &BUTTON_PIN, BUTTON_ON);
    Button_init(&btnOff, &BUTTON_DDR, &BUTTON_PIN, BUTTON_OFF);
    Button_init(&btnTog, &BUTTON_DDR, &BUTTON_PIN, BUTTON_TOGGLE);

    // PWM 초기화
    pwm8Init();
    uint8_t dutyCycle = 0;  // 초기 듀티 사이클 0 (최소 속도)*/
    //pwm16Init();
    uart0Init();

    while (1)
    {
        uart0Transmit(uart0Receive());
        //OCR3A= 125;
        //_delay_ms(1000);
        //OCR3A= 620;
        //_delay_ms(1000);
       /* // ON 버튼을 눌렀을 때: LED 켜기 및 속도 증가
        if (Button_getState(&btnOn) == ACT_RELEASE)
        {
            ledon(&led);  // LED 켬
            // 듀티 사이클을 점차 증가
            {
            for (uint8_t i = 0; i <= 255; i++)
            {
                OCR0 = i;  // PWM 듀티 사이클 설정
                _delay_ms(10);  // 10ms 대기하여 점진적으로 속도 증가
            }

            pwm8Run(255);  // 최대 속도로 PWM 출력

            // 최대 속도에 도달하면 일정 시간 후 속도 감소
            if (dutyCycle == 255)
            {
                _delay_ms(500);  // 500ms 대기 후 속도 감소
                pwm8Run(0);      // 속도 감소 (PWM 출력 0)
            }
            _delay_ms(200);  // 버튼 디바운스 처리
            }
        }

        
        // OFF 버튼을 눌렀을 때: LED 끄기 및 PWM 출력 0 (속도 0)
        if (Button_getState(&btnOff) == ACT_RELEASE)
        {
            // 버튼 눌림 상태 출력
            printf("Button OFF pressed\n");
            ledoff(&led);        // LED 끔
            pwm8Run(0);          // PWM 출력 0 (속도 0)
            _delay_ms(200);      // 버튼 디바운스 처리
        }
       

        // TOGGLE 버튼을 눌렀을 때: LED 상태 반전
        if (Button_getState(&btnTog) == ACT_RELEASE)
        {
            ledTog(&led);  // LED 상태 반전
            _delay_ms(200);  // 버튼 디바운스 처리 
        }*/
    }
}
