/**
  ******************************************************************************
  * @file    A3921Driver.cpp
  * @brief   A3921駆動用のプログラム
  * @author @hamuchan214
  * @date 2023/10/11
  ******************************************************************************
**/

// A3921_motor.cpp

#include "A3921Driver.hpp"
#include <cmath>

void A3921Driver::init() {
    // Start PWM for motor
    HAL_TIM_PWM_Start(timer, channel);
}

void A3921Driver::run(float speed) {
    // Check if absolute speed value is less than or equal to 1
    if (fabsf(speed) <= 1.0f)
    {
        // Set motor direction based on speed and direction
        if ((speed >= 0.0f) ^ direction)
        {
            HAL_GPIO_WritePin(phase_port, phase_pin, GPIO_PIN_SET);
        } else
        {
            HAL_GPIO_WritePin(phase_port, phase_pin, GPIO_PIN_RESET);
        }

        // Convert speed to a 32-bit value and set PWM compare value
        uint32_t mspeed_32 = fabsf(speed * __HAL_TIM_GET_AUTORELOAD(timer));
        __HAL_TIM_SET_COMPARE(timer, channel, mspeed_32);
    }
}
