/**
  ******************************************************************************
  * @file    A3921Driver.cpp
  * @brief   A3921駆動用のプログラム
  * @author @hamuchan214
  * @date 2023/10/10
  ******************************************************************************
**/

#include "stm32g4xx_hal.h"
#include "tim.h"
#include "math.h"

class A3921Driver
{
  private:
    //不変定数
    const uint16_t _duty_max = 3999;
    const uint16_t _duty_min = 1;
    


    //可変定数
    uint16_t _duty;
    bool _sr = 1;
    bool _pwml=1;
    bool _phase;

}