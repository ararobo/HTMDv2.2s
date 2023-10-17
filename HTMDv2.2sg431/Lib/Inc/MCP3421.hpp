/**
  ******************************************************************************
  * @file    A3921Driver.hpp
  * @brief   A3921駆動用のプログラム
  * @author @hamuchan214
  * @date 2023/10/11
  ******************************************************************************
**/

#pragma once

#ifndef MCP3421_HPP_
#define MCP3421_HPP_

#include "main.h"
#include <cstring>

class MCP3421
{
public:
    MCP3421(I2C_HandleTypeDef* pI2C, UART_HandleTypeDef* pUART);
    void read_ADC();

private:
    I2C_HandleTypeDef* pI2CHandle;
    UART_HandleTypeDef* pUARTHandle;

    const uint8_t ADCdatarec[5] = {0};
    const uint8_t MCP3421add = 0b1101000;
    uint32_t ADCval;
    int Resolution;
    const uint8_t config;
};


#endif