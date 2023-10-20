/**
  ******************************************************************************
  * @file    CANManager.cpp
  * @brief   Program for CAN communication
  * @author @hamuchan214
  * @date 2023/10/11
  ******************************************************************************
**/

#include "CANManager.hpp"


// Initialize static const members
const uint16_t CANManager::STOP_COMMAND_ID = 0x00F;
const uint16_t CANManager::STOP_RESPONSE_ID = 0x010;
const uint16_t CANManager::OCD_NOTIFICATION_ID = 0x040;
const uint16_t CANManager::OVERHEAT_NOTIFICATION_ID = 0x041;
const uint16_t CANManager::INIT_WITH_CONF_ID = 0x0FF;
const uint16_t CANManager::INIT_RESPONSE_ID = 0x011;
const uint16_t CANManager::MOTOR_RUN = 0x020;
const uint16_t CANManager::STATUS_REQUEST_ID = 0x030;
const uint16_t CANManager::STATUS_RESPONSE_ID = 0x031;

void CANManager::CAN_FilterSetup()
{
    sFilterConfig.IdType = FDCAN_STANDARD_ID;
    sFilterConfig.FilterIndex = 0;
    sFilterConfig.FilterType = FDCAN_FILTER_MASK;
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilterConfig.FilterID1 = 0x000;
    sFilterConfig.FilterID2 = 0x000;

    // Apply the filter settings
    if(HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK)
    {
        Error_Handler();
    }
}

void CANManager::CAN_Start()
{
    if(HAL_FDCAN_Start(&hfdcan1) != HAL_OK)
    {
        Error_Handler();
    }

    if (HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
    {
        Error_Handler();
    }
}

void CANManager::CAN_Start_Send(uint8_t id)
{
    TxHeader.Identifier = id;
    TxHeader.IdType = FDCAN_STANDARD_ID;
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader.DataLength = FDCAN_DLC_BYTES_8;
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker = 0;

    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData) != HAL_OK)
    {
        Error_Handler();
    }

    while(HAL_FDCAN_GetTxFifoFreeLevel(&hfdcan1) != 3) {}
}

void CANManager::HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
    if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
        {
            if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK)
            {
                Error_Handler();
            }

            switch (RxHeader.Identifier){
                case STOP_COMMAND_ID:
                    // Perform operations for ID 0x000
                    break;
                case INIT_WITH_CONF_ID:
                    // Perform operations for ID 0x001
                    break;
                case MOTOR_RUN:
                //TODO:関数実装しろ
                    ;
            }
        }
}
