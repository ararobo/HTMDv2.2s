/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "A3921Driver.hpp"
#include "CANManager.hpp"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_OCD_Pin GPIO_PIN_13
#define LED_OCD_GPIO_Port GPIOC
#define OCD1_Pin GPIO_PIN_14
#define OCD1_GPIO_Port GPIOC
#define OCD2_Pin GPIO_PIN_15
#define OCD2_GPIO_Port GPIOC
#define PWM_L_Pin GPIO_PIN_1
#define PWM_L_GPIO_Port GPIOA
#define PHASE_Pin GPIO_PIN_2
#define PHASE_GPIO_Port GPIOA
#define SR_Pin GPIO_PIN_3
#define SR_GPIO_Port GPIOA
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define LED6_Pin GPIO_PIN_5
#define LED6_GPIO_Port GPIOA
#define LED5_Pin GPIO_PIN_4
#define LED5_GPIO_Port GPIOC
#define LED4_Pin GPIO_PIN_0
#define LED4_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_1
#define LED3_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_2
#define LED2_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_11
#define LED1_GPIO_Port GPIOB
#define SPI2_CS_Pin GPIO_PIN_12
#define SPI2_CS_GPIO_Port GPIOB
#define LED_CAN_Pin GPIO_PIN_10
#define LED_CAN_GPIO_Port GPIOA
#define LED_lim2_Pin GPIO_PIN_3
#define LED_lim2_GPIO_Port GPIOB
#define LIM2_Pin GPIO_PIN_5
#define LIM2_GPIO_Port GPIOB
#define LED_lim1_Pin GPIO_PIN_6
#define LED_lim1_GPIO_Port GPIOB
#define LIM1_Pin GPIO_PIN_9
#define LIM1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
extern A3921Driver A3921DriverInstance;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
