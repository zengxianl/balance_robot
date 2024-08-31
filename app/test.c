/*
 * @Author: zengxianl 2833995945@qq.com
 * @Date: 2024-08-31 15:57:01
 * @LastEditors: zengxianl 2833995945@qq.com
 * @LastEditTime: 2024-08-31 16:31:56
 * @FilePath: \Project\app\test.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include"test.h"
void motor_test()
{
    motor_init();
    pwm_init(0,7199);
    set_pwm1(1000);
    set_pwm4(1000);
}

