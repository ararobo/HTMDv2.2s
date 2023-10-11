/**
  ******************************************************************************
  * @file    A3921Driver.hpp
  * @brief   A3921駆動用のプログラム
  * @author @hamuchan214
  * @date 2023/10/10
  ******************************************************************************
**/

#pragma once

#include "stm32g4xx_hal.h"
#include "tim.h"

class A3921Driver
{
  private:
    // Immutable constants
    const uint16_t _duty_max = 3999;
    const uint16_t _duty_min = 1;

    // Mutable constants
    uint16_t _duty;
    bool _sr = 1;
    bool _pwml = 1;
    bool _phase;

    //初期化フラグ
    bool _isinit = false;

    // Set phase
    void setPhase(bool phase)
    {
      _phase = phase;
      if(_phase) {
        HAL_GPIO_WritePin(PHASE_GPIO_Port, PHASE_Pin, GPIO_PIN_SET);
      } else {
        HAL_GPIO_WritePin(PHASE_GPIO_Port, PHASE_Pin, GPIO_PIN_RESET);
      }
    }

    // Set duty cycle
    void setDuty(uint16_t duty)
    {
      if(duty > _duty_max) {
        duty = _duty_max;
      }
      if(duty < _duty_min) {
        duty = _duty_min;
      }
      _duty = duty;
      __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, _duty);
    }

    void _init()
    {
      HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
      setDuty(1);
      setPhase(1);
      HAL_GPIO_WritePin(PWM_L_GPIO_Port,PWM_L_Pin,GPIO_PIN_RESET);
      HAL_GPIO_WritePin(SR_GPIO_Port,SR_Pin,GPIO_PIN_SET);
      _isinit = true;  // Set the initialization flag
    }

  public:
    // Constructor
    A3921Driver() : _duty(_duty_min), _sr(true), _pwml(true), _phase(true) {}

    //initialize
    void init_Driver()
    {
      _init();
    }

    // run motor driver
    void run(uint16_t duty, bool phase)
    {
      if(_isinit) {
        setDuty(duty);
        setPhase(phase);
      }
    }
};
