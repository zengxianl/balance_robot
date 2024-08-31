/*
 * @Author: zengxianl 2833995945@qq.com
 * @Date: 2024-08-31 15:10:34
 * @LastEditors: zengxianl 2833995945@qq.com
 * @LastEditTime: 2024-08-31 15:54:22
 * @FilePath: \Project\driver\motor.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
 * prc=0 arr=7199 freq=1000hz
 * 
 */
#ifndef _MOTOR_H
#define _MOTOR_H
#include"stm32f10x.h"
#include"bandbit.h"

#define PWM_MAX 7200
#define PWM_MIN -7200

#define Ain1  PBout(14)
#define Ain2  PBout(15)

#define Bin1  PBout(13)
#define Bin2  PBout(12)



void motor_init();
void set_pwm1(int pwm);
void set_pwm4(int pwm);

#endif
