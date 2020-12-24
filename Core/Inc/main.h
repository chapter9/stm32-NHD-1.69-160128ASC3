/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "nhd_oled.h"
#include "stm32f3xx_hal_spi.h"
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
void NHD_OLED_DataWrite(NHD_OLED_HandleTypeDef* holed, uint8_t* pData, size_t size);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define NHD_DC_Pin GPIO_PIN_0
#define NHD_DC_GPIO_Port GPIOA
#define NHD_OLED_CS_Pin GPIO_PIN_1
#define NHD_OLED_CS_GPIO_Port GPIOA
#define NHD_RES_Pin GPIO_PIN_3
#define NHD_RES_GPIO_Port GPIOA
#define NHD_SCK_Pin GPIO_PIN_5
#define NHD_SCK_GPIO_Port GPIOA
#define NHD_MOSI_Pin GPIO_PIN_7
#define NHD_MOSI_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_3
#define LED1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
