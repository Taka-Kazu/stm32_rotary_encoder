#ifndef _STM32_ROTARY_ENCODER
#define _STM32_ROTARY_ENCODER

#include "mbed.h"

//abstruct
class STM32RotaryEncoder
{
public:
	virtual ~STM32RotaryEncoder(void) = 0;
	virtual void initialize(void)= 0;
	virtual long int get_pulse(void) = 0;
	virtual void reset(void) = 0;
};

//TIM1
//PA_8:TIM1_CH1
//PA_9:TIM1_CH2
class STM32RotaryEncoder1:public STM32RotaryEncoder
{
public:
    STM32RotaryEncoder1();
    virtual void initialize(void);
    virtual long int get_pulse(void);
    virtual void reset(void);
private:
};

//TIM2
//PA_0:TIM2_CH1
//PA_1:TIM2_CH2
class STM32RotaryEncoder2:public STM32RotaryEncoder
{
public:
    STM32RotaryEncoder2();
    virtual void initialize(void);
    virtual long int get_pulse(void);
    virtual void reset(void);
private:
};

//TIM3
//PA_6:TIM3_CH1
//PA_7:TIM3_CH2
class STM32RotaryEncoder3:public STM32RotaryEncoder
{
public:
    STM32RotaryEncoder3();
    virtual void initialize(void);
    virtual long int get_pulse(void);
    virtual void reset(void);
private:
};

//TIM4
//PB_6:TIM3_CH1
//PB_7:TIM3_CH2
class STM32RotaryEncoder4:public STM32RotaryEncoder
{
public:
    STM32RotaryEncoder4();
    virtual void initialize(void);
    virtual long int get_pulse(void);
    virtual void reset(void);
private:
};

//TIM5
//PA_0:TIM5_CH1
//PA_1:TIM5_CH2
class STM32RotaryEncoder5:public STM32RotaryEncoder
{
public:
    STM32RotaryEncoder5();
    virtual void initialize(void);
    virtual long int get_pulse(void);
    virtual void reset(void);
private:
};

//TIM8
//PC_6:TIM8_CH1
//PC_7:TIM8_CH2
class STM32RotaryEncoder8:public STM32RotaryEncoder
{
public:
    STM32RotaryEncoder8();
    virtual void initialize(void);
    virtual long int get_pulse(void);
    virtual void reset(void);
private:
};
#endif
