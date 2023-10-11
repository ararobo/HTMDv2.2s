/**
  ******************************************************************************
  * @file    CANManager.cpp
  * @brief   CAN通信処理用のプログラム
  * @author @hamuchan214
  * @date 2023/10/11
  ******************************************************************************
**/

#include "stm32g4xx_hal.h"
#include "main.h"
#include "fdcan.h"

// Message IDs
#define STOP_COMMAND_ID           0x00F
#define STOP_RESPONSE_ID          0x010
#define OCD_NOTIFICATION_ID       0x040
#define OVERHEAT_NOTIFICATION_ID  0x041

//データ宣言
FDCAN_TxHeaderTypeDef  TxHeader;
FDCAN_RxHeaderTypeDef  RxHeader;

uint8_t TxData[8];
uint8_t RxData[8];
uint32_t TxMailbox;

//CANのフィルタの宣言
FDCAN_FilterTypeDef  sFilterConfig;

//CANのフィルタ適用関数
void CAN_FilterSetup(void)
{
    sFilterConfig.IdType = FDCAN_STANDARD_ID;
    sFilterConfig.FilterIndex = 0;
    sFilterConfig.FilterType = FDCAN_FILTER_MASK;
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0; 
    sFilterConfig.FilterID1 = 0x000;
    sFilterConfig.FilterID2 = 0x000;

    //設定の適用
    if(HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK)
    {
        Error_Handler();
    }
}

//CANの開始関数
void CAN_Start(void)
{
  if(HAL_FDCAN_Start(&hfdcan1) != HAL_OK)//CANモジュールの開始
  {
    Error_Handler();
  }

  if (HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)//CAN受信開始API呼び出し
  {
    Error_Handler();
  }
}

//CAN送信関数
void CAN_Start_Send(uint8_t id)
{
    TxHeader.Identifier =id;
    TxHeader.IdType = FDCAN_STANDARD_ID;
    TxHeader.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader.DataLength = FDCAN_DLC_BYTES_8;
    TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader.FDFormat = FDCAN_CLASSIC_CAN;
    TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader.MessageMarker = 0;
    
    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, TxData) != HAL_OK)//CAN送信開始
	{
		Error_Handler();
	}

    while(HAL_FDCAN_GetTxFifoFreeLevel(&hfdcan1) != 3) {}
}

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
  if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
  {
    /* Retrieve Rx messages from RX FIFO0 */
    if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK)
    {
    Error_Handler();
    }

    switch (RxHeader.Identifier){
            //TODO:処理の分岐かく
			case STOP_COMMAND_ID:
				//ID：0x000の時の受信動作
			break;
			case 0x001:
				//ID：0x001の時の受信動作
			break;
		}
  }
}



// StopCommandの処理
void Process_StopCommand(uint8_t* data)
{
    // データからMD_IDを取得
    uint8_t md_id = data[0];

    // 必要な処理をここで行う

    // 応答としてStopResponseを送信
    Send_StopResponse(md_id);
}

// StopResponseの送信
void Send_StopResponse(uint8_t md_id)
{

}