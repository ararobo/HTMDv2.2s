/**
  ******************************************************************************
  * @file    CANManager.hpp
  * @brief   Program for CAN communication
  * @author @hamuchan214
  * @date 2023/10/11
  ******************************************************************************
**/
#ifndef CAN_MANAGER_HPP
#define CAN_MANAGER_HPP

#include "stm32g4xx_hal.h"
#include "main.h"
#include "fdcan.h"
#include "A3921Driver.hpp"

extern A3921Driver A3921DriverInstance;

class CANManager
{
private:
    static const uint16_t STOP_COMMAND_ID;
    static const uint16_t STOP_RESPONSE_ID;
    static const uint16_t OCD_NOTIFICATION_ID;
    static const uint16_t OVERHEAT_NOTIFICATION_ID;
    static const uint16_t INIT_WITH_CONF_ID;
    static const uint16_t INIT_RESPONSE_ID;
    static const uint16_t MOTOR_RUN;
    static const uint16_t STATUS_REQUEST_ID;
    static const uint16_t STATUS_RESPONSE_ID;

    FDCAN_TxHeaderTypeDef  TxHeader;
    FDCAN_RxHeaderTypeDef  RxHeader;
    uint8_t TxData[8];
    uint8_t RxData[8];
    uint32_t TxMailbox;
    FDCAN_FilterTypeDef  sFilterConfig;

public:
    void CAN_FilterSetup();
    void CAN_Start();
    void CAN_Start_Send(uint8_t id);
    void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs);
};

#endif // CAN_MANAGER_HPP
