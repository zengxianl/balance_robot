/*
 * @Author: zengxianl 2833995945@qq.com
 * @Date: 2024-08-31 14:20:30
 * @LastEditors: zengxianl 2833995945@qq.com
 * @LastEditTime: 2024-08-31 14:32:04
 * @FilePath: \Project\driver\delay.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include"delay.h"

void delay_init()
{
    return;
}
void delay_ms(uint32_t ms)
{
    uint32_t i;
    SysTick_Config(SystemCoreClock/1000);
    for(i=0;i<ms;++i)
    {
        while (!((SysTick->CTRL)&(1<<16)));
    }
    SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk; 
}
void delay_us(uint32_t us)
{
    uint32_t i;
    SysTick_Config(SystemCoreClock/1000000);
    for(i=0;i<us;++i)
    {
        while (!((SysTick->CTRL)&(1<<16)));
    }
    SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk; 
}