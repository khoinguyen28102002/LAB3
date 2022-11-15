/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define SEGA1_Pin GPIO_PIN_3
#define SEGA1_GPIO_Port GPIOA
#define SEGA2_Pin GPIO_PIN_4
#define SEGA2_GPIO_Port GPIOA
#define SEGA3_Pin GPIO_PIN_5
#define SEGA3_GPIO_Port GPIOA
#define SEGA4_Pin GPIO_PIN_6
#define SEGA4_GPIO_Port GPIOA
#define SEGA5_Pin GPIO_PIN_7
#define SEGA5_GPIO_Port GPIOA
#define BUT1_Pin GPIO_PIN_0
#define BUT1_GPIO_Port GPIOB
#define BUT2_Pin GPIO_PIN_1
#define BUT2_GPIO_Port GPIOB
#define BUT3_Pin GPIO_PIN_2
#define BUT3_GPIO_Port GPIOB
#define SEGB2_Pin GPIO_PIN_10
#define SEGB2_GPIO_Port GPIOB
#define SEGB3_Pin GPIO_PIN_11
#define SEGB3_GPIO_Port GPIOB
#define SEGB4_Pin GPIO_PIN_12
#define SEGB4_GPIO_Port GPIOB
#define SEGB5_Pin GPIO_PIN_13
#define SEGB5_GPIO_Port GPIOB
#define SEGB6_Pin GPIO_PIN_14
#define SEGB6_GPIO_Port GPIOB
#define SEGB7_Pin GPIO_PIN_15
#define SEGB7_GPIO_Port GPIOB
#define SEGA6_Pin GPIO_PIN_8
#define SEGA6_GPIO_Port GPIOA
#define SEGA7_Pin GPIO_PIN_9
#define SEGA7_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_10
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_11
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_12
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_13
#define EN3_GPIO_Port GPIOA
#define REDA_Pin GPIO_PIN_3
#define REDA_GPIO_Port GPIOB
#define YELLOWA_Pin GPIO_PIN_4
#define YELLOWA_GPIO_Port GPIOB
#define GREENA_Pin GPIO_PIN_5
#define GREENA_GPIO_Port GPIOB
#define REDB_Pin GPIO_PIN_6
#define REDB_GPIO_Port GPIOB
#define YELLOWB_Pin GPIO_PIN_7
#define YELLOWB_GPIO_Port GPIOB
#define GREENB_Pin GPIO_PIN_8
#define GREENB_GPIO_Port GPIOB
#define SEGB1_Pin GPIO_PIN_9
#define SEGB1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
