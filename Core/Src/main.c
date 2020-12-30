/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_tx;

/* USER CODE BEGIN PV */
NHD_OLED_HandleTypeDef holed1;
uint8_t fastModeActive = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */
static void MX_OLED1_Init(void);
void MY_HAL_SPI_TX_COMPLETE(SPI_HandleTypeDef *hspi);
void MY_HAL_SPI_HTX_COMPLETE(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_Transmit_UltraFast(uint8_t *outp, uint8_t *inp, int count);
static void PrintResult(char* title, char* subtitle, uint32_t* result);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  MX_OLED1_Init();
  uint32_t last = 0;
  uint32_t result[2] = {0, 0};
  NHD_OLED_FillScreen(&holed1, RGB565[1]);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    for(fastModeActive = 0; fastModeActive < 2; fastModeActive++)
    {
      last = HAL_GetTick();
      for (size_t i = 0; i < 16; i++)
      {
        NHD_OLED_FillScreen(&holed1, RGB565[i]);
      }
      result[fastModeActive] = HAL_GetTick() - last;
    }
    PrintResult("Test #1 - FillScreen", "3 fills, 3 colors", result);

    for(fastModeActive = 0; fastModeActive < 2; fastModeActive++)
    {
      last = HAL_GetTick();
      for (size_t i = 1; i < 100; i++)
      {
        NHD_OLED_Text(&holed1, 0, (i*8) % 128, "0123456789", RGB565[i % 16], RGB565[0], &Font8);
      }
      result[fastModeActive] = HAL_GetTick() - last;
    }
    PrintResult("Test #2 - Text", "1000 char, 16 colors, 8px", result);

    for(fastModeActive = 0; fastModeActive < 2; fastModeActive++)
    {
      last = HAL_GetTick();
      for (size_t i = 1; i < 100; i++)
      {
        NHD_OLED_Text(&holed1, 0, (i*12) % 128, "0123456789", RGB565[i % 16], RGB565[0], &Font12);
      }
      result[fastModeActive] = HAL_GetTick() - last;
    }
    PrintResult("Test #2 - Text", "1000 char, 16 colors, 16px", result);
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */
  
  SET_BIT(SPI1->CR1, SPI_CR1_SPE); // Enable SPI
  if (HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_TX_COMPLETE_CB_ID, MY_HAL_SPI_TX_COMPLETE) !=HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_TX_HALF_COMPLETE_CB_ID, MY_HAL_SPI_HTX_COMPLETE) !=HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE END SPI1_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, NHD_DC_Pin|NHD_OLED_CS_Pin|NHD_RES_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : NHD_DC_Pin NHD_OLED_CS_Pin NHD_RES_Pin */
  GPIO_InitStruct.Pin = NHD_DC_Pin|NHD_OLED_CS_Pin|NHD_RES_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LED1_Pin */
  GPIO_InitStruct.Pin = LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED1_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
static void PrintResult(char* title, char* subtitle, uint32_t* results)
{
  char message[20];

  NHD_OLED_FillScreen(&holed1, RGB565[1]);

  uint16_t pos = 0;
  NHD_OLED_Text(&holed1, 0, pos, title, RGB565[14], RGB565[0], &Font12); pos+=14;
  NHD_OLED_Text(&holed1, 0, pos, subtitle, RGB565[15], RGB565[1], &Font8); pos+=10;

  for(size_t fm = 0; fm < 2; fm++)
  {
    uint32_t result = *(results+fm);
    if (fm)
    {
      sprintf(message, "Fast Mode: %lums", result);
    }
    else
    {
      sprintf(message, "Normal Mode: %lums", result);
    }
    NHD_OLED_Text(&holed1, 0, pos, message, RGB565[15], RGB565[1], &Font8); pos+=10;
  }
  HAL_Delay(10000);

  NHD_OLED_FillScreen(&holed1, RGB565[0]);  
}


static void MX_OLED1_Init(void)
{
    holed1.RES_GPIO_Port = NHD_RES_GPIO_Port;
    holed1.RES_Pin = NHD_RES_Pin;
    holed1.CS_GPIO_Port = NHD_OLED_CS_GPIO_Port;
    holed1.CS_Pin = NHD_OLED_CS_Pin;
    holed1.DC_GPIO_Port = NHD_DC_GPIO_Port;
    holed1.DC_Pin = NHD_DC_Pin;
    holed1.LED_GPIO_Port= LED1_GPIO_Port;
    holed1.LED_Pin = LED1_Pin;
    holed1.hspi = &hspi1;

    NHD_OLED_Init(&holed1);
}

void NHD_OLED_DataWrite(NHD_OLED_HandleTypeDef* holed, uint8_t* pData, size_t size)
{
  if (fastModeActive)
  {
    uint8_t dummy = 0x00;
    if (HAL_SPI_Transmit_UltraFast(pData, &dummy, size) != HAL_OK)
    {
      Error_Handler();
    }
  }
  else
  {
    if (HAL_SPI_Transmit(&hspi1, pData, size, 5000) != HAL_OK)
    {
      Error_Handler();
    }
  }
}


void MY_HAL_SPI_TX_COMPLETE(SPI_HandleTypeDef *hspi)
{
}

void MY_HAL_SPI_HTX_COMPLETE(SPI_HandleTypeDef *hspi)
{
}

HAL_StatusTypeDef HAL_SPI_Transmit_UltraFast(uint8_t *outp, uint8_t *inp, int count)
{
  while(count--) {
      //while(!(SPI1->SR & SPI_SR_TXE));
      *(volatile uint8_t *)&SPI1->DR = *outp++;
      //while(!(SPI1->SR & SPI_SR_RXNE));
      //*inp++ = *(volatile uint8_t *)&SPI1->DR;
      //while(!(SPI1->SR & SPI_FLAG_FTLVL) != SPI_FTLVL_EMPTY);
      //while(!(SPI1->SR & SPI_FLAG_BSY) != RESET);
      //while(!(SPI1->SR & SPI_FLAG_FRLVL) != SPI_FRLVL_EMPTY);
  }
  asm volatile("nop");
  asm volatile("nop");
  asm volatile("nop");
  return HAL_OK;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  //__disable_irq();
  while (1)
  {
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    HAL_Delay(100);
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
