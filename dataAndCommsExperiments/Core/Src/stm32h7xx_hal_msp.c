/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32h7xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
extern DMA_HandleTypeDef hdma_tim24_up;

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{

  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
  * @brief TIM_Encoder MSP Initialization
  * This function configures the hardware resources used in this example
  * @param htim_encoder: TIM_Encoder handle pointer
  * @retval None
  */
void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef* htim_encoder)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(htim_encoder->Instance==TIM24)
  {
    /* USER CODE BEGIN TIM24_MspInit 0 */

    /* USER CODE END TIM24_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_TIM24_CLK_ENABLE();

    __HAL_RCC_GPIOF_CLK_ENABLE();
    /**TIM24 GPIO Configuration
    PF11     ------> TIM24_CH1
    PF12     ------> TIM24_CH2
    */
    GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF14_TIM24;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    /* TIM24 DMA Init */
    /* TIM24_UP Init */
    hdma_tim24_up.Instance = DMA1_Stream0;
    hdma_tim24_up.Init.Request = DMA_REQUEST_TIM24_UP;
    hdma_tim24_up.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_tim24_up.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_tim24_up.Init.MemInc = DMA_MINC_ENABLE;
    hdma_tim24_up.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tim24_up.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_tim24_up.Init.Mode = DMA_NORMAL;
    hdma_tim24_up.Init.Priority = DMA_PRIORITY_LOW;
    hdma_tim24_up.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_tim24_up) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(htim_encoder,hdma[TIM_DMA_ID_UPDATE],hdma_tim24_up);

    /* USER CODE BEGIN TIM24_MspInit 1 */

    /* USER CODE END TIM24_MspInit 1 */

  }

}

/**
  * @brief TIM_Encoder MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param htim_encoder: TIM_Encoder handle pointer
  * @retval None
  */
void HAL_TIM_Encoder_MspDeInit(TIM_HandleTypeDef* htim_encoder)
{
  if(htim_encoder->Instance==TIM24)
  {
    /* USER CODE BEGIN TIM24_MspDeInit 0 */

    /* USER CODE END TIM24_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM24_CLK_DISABLE();

    /**TIM24 GPIO Configuration
    PF11     ------> TIM24_CH1
    PF12     ------> TIM24_CH2
    */
    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_11|GPIO_PIN_12);

    /* TIM24 DMA DeInit */
    HAL_DMA_DeInit(htim_encoder->hdma[TIM_DMA_ID_UPDATE]);
    /* USER CODE BEGIN TIM24_MspDeInit 1 */

    /* USER CODE END TIM24_MspDeInit 1 */
  }

}

/**
  * @brief UART MSP Initialization
  * This function configures the hardware resources used in this example
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(huart->Instance==USART1)
  {
    /* USER CODE BEGIN USART1_MspInit 0 */

    /* USER CODE END USART1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    PeriphClkInitStruct.Usart16ClockSelection = RCC_USART16910CLKSOURCE_D2PCLK2;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PB14     ------> USART1_TX
    PB15     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF4_USART1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USER CODE BEGIN USART1_MspInit 1 */

    /* USER CODE END USART1_MspInit 1 */

  }

}

/**
  * @brief UART MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
  if(huart->Instance==USART1)
  {
    /* USER CODE BEGIN USART1_MspDeInit 0 */

    /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PB14     ------> USART1_TX
    PB15     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_14|GPIO_PIN_15);

    /* USER CODE BEGIN USART1_MspDeInit 1 */

    /* USER CODE END USART1_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
