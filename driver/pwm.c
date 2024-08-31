/*
 * @Author: zengxianl 2833995945@qq.com
 * @Date: 2024-08-31 14:15:27
 * @LastEditors: zengxianl 2833995945@qq.com
 * @LastEditTime: 2024-08-31 15:31:26
 * @FilePath: \Project\driver\pwm.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include"pwm.h"

void pwm_init(uint16_t psc,uint16_t per)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_TIM1 | RCC_APB2Periph_AFIO,ENABLE);//开启时钟
    
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStructure);

    TIM_TimeBaseStructInit(&TIM_OCInitStructure);
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV4;
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_Period=per;
    TIM_TimeBaseStructure.TIM_Prescaler=psc;
    TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStructure);

    TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Disable;
    TIM_OCInitStructure.TIM_Pulse=0;
    TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
    TIM_OC1Init(TIM1,&TIM_OCInitStructure);
    TIM_OC4Init(TIM1,&TIM_OCInitStructure);

    TIM_CtrlPWMOutputs(TIM1,ENABLE);//高级定时器专属--MOE主输出使能
	
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);/*【3】*///ENABLE//OC1预装载寄存器使能
	TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);//ENABLE//OC4预装载寄存器使能
	TIM_ARRPreloadConfig(TIM1,ENABLE);//TIM1在ARR上预装载寄存器使能
	
	TIM_Cmd(TIM1,ENABLE);//开定时器。
}