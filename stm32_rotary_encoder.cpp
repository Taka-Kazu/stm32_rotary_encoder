#include "../stm32_rotary_encoder/stm32_rotary_encoder.h"

//NUCLEO-64ボード用

STM32RotaryEncoder::~STM32RotaryEncoder(void)
{

}

//TIM1
//PA_8:TIM1_CH1(AF1)
//PA_9:TIM1_CH2(AF1)
STM32RotaryEncoder1::STM32RotaryEncoder1(void) {
	printf("stm32re1 is ready\r\n");
}

void STM32RotaryEncoder1::initialise(void) {
	__GPIOA_CLK_ENABLE(); 
	GPIOA->MODER &= 0xFFF0FFFF;
	GPIOA->MODER |= 0xA0000;
	GPIOA->OTYPER |= 0x300;
	GPIOA->OSPEEDR |= 0x50000;
	GPIOA->PUPDR |= 0x0;
	GPIOA->AFR[0] |= 0x00000000;
	GPIOA->AFR[1] |= 0x00000011;

	__TIM1_CLK_ENABLE();

	TIM1->CR1 |= 0x0001;
	TIM1->SMCR |= TIM_ENCODERMODE_TI12;
	TIM1->CCMR1 |= 0xF1F1;
	TIM1->CCMR2 |= 0x0000;
	TIM1->CCER |= 0x0011;
	TIM1->PSC |= 0x0000;
	TIM1->ARR |= 0xffffffff;

	TIM1->CNT = 0x0000;
}

long int STM32RotaryEncoder1::get_pulse(void) {
	uint16_t count = (uint16_t) TIM1->CNT;
	long int pulse;
	if (count & 0x8000) {
		count = ~count + 1;
		pulse = (long int) (count * (-1));
	} else {
		pulse = (long int) count;
	}
	return pulse;
}

void STM32RotaryEncoder1::reset(void) {
	TIM1->CNT = 0;
}

//TIM2
//PA_0:TIM2_CH1
//PA_1:TIM2_CH2
STM32RotaryEncoder2::STM32RotaryEncoder2(void) {
	printf("stm32re2 is ready\r\n");
}

void STM32RotaryEncoder2::initialise(void) {
	__GPIOA_CLK_ENABLE();
	GPIOA->MODER &= 0xFFFFFFF0;
	GPIOA->MODER |= 0xA;
	GPIOA->OTYPER |= 0x3;
	GPIOA->OSPEEDR |= 0x5;
	GPIOA->PUPDR |= 0x0;
	GPIOA->AFR[0] |= 0x00000022;
	GPIOA->AFR[1] |= 0x00000000;


	__TIM2_CLK_ENABLE();

	TIM2->CR1 |= 0x0001;
	TIM2->SMCR |= TIM_ENCODERMODE_TI12;
	TIM2->CCMR1 |= 0xF1F1;
	TIM2->CCMR2 |= 0x0000;
	TIM2->CCER |= 0x0011;
	TIM2->PSC |= 0x0000;
	TIM2->ARR |= 0xffffffff;

	TIM2->CNT = 0x0000;
}

long int STM32RotaryEncoder2::get_pulse(void) {
	uint16_t count = (uint16_t) TIM2->CNT;
	long int pulse;
	if (count & 0x8000) {
		count = ~count + 1;
		pulse = (long int) (count * (-1));
	} else {
		pulse = (long int) count;
	}
	return pulse;
}

void STM32RotaryEncoder2::reset(void) {
	TIM2->CNT = 0;
}

STM32RotaryEncoder3::STM32RotaryEncoder3(void) {
	printf("stm32re3 is ready\r\n");
}

void STM32RotaryEncoder3::initialise(void) {
	__GPIOA_CLK_ENABLE();

	GPIOA->MODER &= 0xFFFF0FFF;
	GPIOA->MODER |= 0xA000;
	GPIOA->OTYPER |= 0xC0;
	GPIOA->OSPEEDR |= 0x5000;
	GPIOA->PUPDR |= 0x0; 
	GPIOA->AFR[0] |= 0x22000000;
	GPIOA->AFR[1] |= 0x00000000;

	__TIM3_CLK_ENABLE();

	TIM3->CR1 |= 0x0001;
	TIM3->SMCR |= TIM_ENCODERMODE_TI12;
	TIM3->CCMR1 |= 0xF1F1;
	TIM3->CCMR2 |= 0x0000;
	TIM3->CCER |= 0x0011;
	TIM3->PSC |= 0x0000;
	TIM3->ARR |= 0xffffffff;

	TIM3->CNT = 0x0000;
}

long int STM32RotaryEncoder3::get_pulse(void) {
	uint16_t count = (uint16_t) TIM3->CNT;
	long int pulse;
	if (count & 0x8000) {
		count = ~count + 1;
		pulse = (long int) (count * (-1));
	} else {
		pulse = (long int) count;
	}
	return pulse;
}

void STM32RotaryEncoder3::reset(void) {
	TIM3->CNT = 0;
}

STM32RotaryEncoder4::STM32RotaryEncoder4(void) {
	printf("stm32re4 is ready\r\n");
}

void STM32RotaryEncoder4::initialise(void) {
	__GPIOB_CLK_ENABLE();

	GPIOB->MODER &= 0xFFFF0FFF;
	GPIOB->MODER |= 0xA000;
	GPIOB->OTYPER |= 0xC0;
	GPIOB->OSPEEDR |= 0x5000;
	GPIOB->PUPDR |= 0x0;
	GPIOB->AFR[0] |= 0x22000000;
	GPIOB->AFR[1] |= 0x00000000;

	__TIM4_CLK_ENABLE();

	TIM4->CR1 |= 0x0001;
	TIM4->SMCR |= TIM_ENCODERMODE_TI12;
	TIM4->CCMR1 |= 0xF1F1;
	TIM4->CCMR2 |= 0x0000;
	TIM4->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E;
	TIM4->PSC |= 0x0000;
	TIM4->ARR |= 0xffff;

	TIM4->CNT = 0x0000;
}

long int STM32RotaryEncoder4::get_pulse(void) {
	uint16_t count = (uint16_t) TIM4->CNT;
	long int pulse;
	if (count & 0x8000) {
		count = ~count + 1;
		pulse = (long int) (count * (-1));
	} else {
		pulse = (long int) count;
	}
	return pulse;
}

void STM32RotaryEncoder4::reset(void) {
	TIM4->CNT = 0;
}


//TIM5
//PA_0:TIM5_CH1
//PA_1:TIM5_CH2
STM32RotaryEncoder5::STM32RotaryEncoder5(void) {
	printf("stm32re5 is ready\r\n");
}

void STM32RotaryEncoder5::initialise(void) {
	__GPIOA_CLK_ENABLE();
	GPIOA->MODER &= 0xFFFFFFF0;
	GPIOA->MODER |= 0xA;
	GPIOA->OTYPER |= 0x3;
	GPIOA->OSPEEDR |= 0x5;
	GPIOA->PUPDR |= 0x0;
	GPIOA->AFR[0] |= 0x00000022;
	GPIOA->AFR[1] |= 0x00000000;

	__TIM5_CLK_ENABLE();
	TIM5->CR1 |= 0x0001;
	TIM5->SMCR |= TIM_ENCODERMODE_TI12;
	TIM5->CCMR1 |= 0xF1F1;
	TIM5->CCMR2 |= 0x0000;
	TIM5->CCER |= 0x0011;
	TIM5->PSC |= 0x0000;
	TIM5->ARR |= 0xffffffff;

	TIM5->CNT = 0x0000;
}

long int STM32RotaryEncoder5::get_pulse(void) {
	uint16_t count = (uint16_t) TIM5->CNT;
	long int pulse;
	if (count & 0x8000) {
		count = ~count + 1;
		pulse = (long int) (count * (-1));
	} else {
		pulse = (long int) count;
	}
	return pulse;
}

void STM32RotaryEncoder5::reset(void) {
	TIM5->CNT = 0;
}


//TIM8
//PC_6:TIM8_CH1
//PC_7:TIM8_CH2
STM32RotaryEncoder8::STM32RotaryEncoder8(void) {
	printf("stm32re8 is ready\r\n");
}

void STM32RotaryEncoder8::initialise(void) {
	__GPIOC_CLK_ENABLE();

	GPIOC->MODER &= 0xFFFF0FFF;
	GPIOC->MODER |= 0xA000;
	GPIOC->OTYPER |= 0xC0;
	GPIOC->OSPEEDR = 0x5000;
	GPIOC->PUPDR |= 0x0;
	GPIOC->AFR[0] |= 0x33000000;
	GPIOC->AFR[1] |= 0x00000000;

	// configure TIM8 as Encoder input
	// Enable clock for TIM8
	__TIM8_CLK_ENABLE()
	;

	TIM8->CR1 |= 0x0001;
	TIM8->SMCR |= TIM_ENCODERMODE_TI12;
	TIM8->CCMR1 |= 0xF1F1;
	TIM8->CCMR2 |= 0x0000;
	TIM8->CCER |= 0x0011;
	TIM8->PSC |= 0x0000;
	TIM8->ARR |= 0xffffffff;

	TIM8->CNT = 0x0000;
}

long int STM32RotaryEncoder8::get_pulse(void) {
	uint16_t count = (uint16_t) TIM8->CNT;
	long int pulse;
	if (count & 0x8000) {
		count = ~count + 1;
		pulse = (long int) (count * (-1));
	} else {
		pulse = (long int) count;
	}
	return pulse;
}

void STM32RotaryEncoder8::reset(void) {
	TIM8->CNT = 0;
}
