/**
  ******************************************************************************
  * @file    A3921Driver.hpp
  * @brief   A3921駆動用のプログラム
  * @author @hamuchan214
  * @date 2023/10/11
  ******************************************************************************
**/

#pragma once

// A3921_motor.hpp

#ifndef A3921_MOTOR_HPP_
#define A3921_MOTOR_HPP_

#include "main.h"

class A3921Motor {
private:
    static const uint8_t A3921_DIR_FW = 0; // static constant for forward direction
    static const uint8_t A3921_DIR_BC = 1; // static constant for backward direction
    
    TIM_HandleTypeDef* timer;     // timer structure
    uint32_t channel;             // timer channel
    uint8_t direction;            // motor rotation direction
    GPIO_TypeDef* phase_port;     // GPIO port
    uint16_t phase_pin;           // GPIO pin

public:
    A3921Motor(TIM_HandleTypeDef* _timer, uint32_t _channel, uint8_t _direction, GPIO_TypeDef* _phase_port, uint16_t _phase_pin)
        : timer(_timer), channel(_channel), direction(_direction), phase_port(_phase_port), phase_pin(_phase_pin) {} // Constructor

    // Initialize the motor
    void init();

    // Run the motor with given speed
    void run(float speed);
};

#endif /* A3921_MOTOR_HPP_ */