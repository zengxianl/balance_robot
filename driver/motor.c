/*
 * @Author: zengxianl 2833995945@qq.com
 * @Date: 2024-08-31 15:10:27
 * @LastEditors: zengxianl 2833995945@qq.com
 * @LastEditTime: 2024-08-31 16:30:26
 * @FilePath: \Project\driver\motor.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "motor.h"
static void pwm_limit(int *pwm);
static int abs(int num);

void motor_init()
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 开启时钟

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;

    GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void pwm_limit(int *pwm)
{
    if (*pwm > PWM_MAX)
        *pwm = PWM_MAX;
    if (*pwm < PWM_MIN)
        *pwm = PWM_MIN;
}
int abs(int num)
{
    return num < 0 ? -num : num;
}
void set_pwm1(int pwm)
{
    pwm_limit(&pwm);
    if (pwm > 0) Ain1=1,Ain2=0;
    else Ain1=0,Ain2=1;
    TIM1->CCR1 = abs(pwm);
}
void set_pwm4(int pwm)
{
    pwm_limit(&pwm);
    if (pwm > 0)Bin1=1,Bin2=0;
    else Bin1=0,Bin2=1;
    TIM1->CCR4 = abs(pwm);
}
