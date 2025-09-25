/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
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

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum{
	Red,
	Yellow,
	Green
}Led_State;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define On	0
#define Off 1
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
Led_State state = Red;
Led_State state2 = Green;
int segTable[10][7] = {
			{0,0,0,0,0,0,1},
			{1,0,0,1,1,1,1},
			{0,0,1,0,0,1,0},
			{0,0,0,0,1,1,0},
			{1,0,0,1,1,0,0},
			{0,1,0,0,1,0,0},
			{0,1,0,0,0,0,0},
			{0,0,0,1,1,1,1},
			{0,0,0,0,0,0,0},
			{0,0,0,0,1,0,0}
	};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void xRed_State(int i);
void xYellow_State(int i);
void xGreen_State(int i);
void yRed_State(int i);
void yYellow_State(int i);
void yGreen_State(int i);

void display7SEG(int num);
void y_display7SEG(int num);
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
	uint32_t counter_red = 500;
	uint32_t counter_yellow = 200;
	uint32_t counter_green= 300;

	uint32_t counter_red2 = 500;
	uint32_t counter_yellow2 = 200;
	uint32_t counter_green2 = 300;
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		  switch(state){
		  case Red:
			  xRed_State(On);
			  xYellow_State(Off);
			  xGreen_State(Off);
			  if(counter_red % 100 == 0){
				  display7SEG(counter_red/100);
			  }
			  counter_red--;
			  if(counter_red <= 0){
				  counter_red = 500;
				  state = Green;
			  }
			  break;
		  case Yellow:
		  	  xRed_State(Off);
		  	  xYellow_State(On);
		  	  xGreen_State(Off);
		  	  if(counter_yellow % 100 == 0){
		  			display7SEG(counter_yellow/100);
		  	  }
		  	  counter_yellow--;
		  	  if(counter_yellow <= 0){
		  	  counter_yellow = 200;
		  	  state = Red;
		  	  }
		  	  break;
		  case Green:
			  xRed_State(Off);
			  xYellow_State(Off);
			  xGreen_State(On);
			  if(counter_green % 100 == 0){
			  		display7SEG(counter_green/100);
			  }
			  counter_green--;
			  if(counter_green <= 0){
			  counter_green = 300;
			  state = Yellow;
			  }
			  break;
		  default:
			  break;
		  }

		  switch(state2){
		  case Red:
			  yRed_State(On);
			  yYellow_State(Off);
			  yGreen_State(Off);
			  if(counter_red2 % 100 == 0){
				  y_display7SEG(counter_red2/100);
			  }
			  counter_red2--;
			  if(counter_red2 <= 0){
				  counter_red2 = 500;
				  state2 = Green;
			  }
			  break;
		  case Yellow:
		  	  yRed_State(Off);
		  	  yYellow_State(On);
		  	  yGreen_State(Off);
		  	  if(counter_yellow2 % 100 == 0){
		  		  y_display7SEG(counter_yellow2/100);
		  	  }
		  	  counter_yellow2--;
		  	  if(counter_yellow2 <= 0){
		  	  counter_yellow2 = 200;
		  	  state2 = Red;
		  	  }
		  	  break;
		  case Green:
			  yRed_State(Off);
			  yYellow_State(Off);
			  yGreen_State(On);
			  if(counter_green2 % 100 == 0){
				  y_display7SEG(counter_green2/100);
			  }
			  counter_green2--;
			  if(counter_green2 <= 0){
			  counter_green2 = 300;
			  state2 = Yellow;
			  }
			  break;
		  default:
			  break;
		  }
	  HAL_Delay(10);
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
  HAL_GPIO_WritePin(GPIOA, LED_RED2_Pin|LED_YELLOW2_Pin|LED_GREEN2_Pin|LED_RED_Pin
                          |LED_YELLOW_Pin|LED_GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_7SEG_Pin|b_7SEG_Pin|c_7SEG_Pin|d_7SEG2_Pin
                          |e_7SEG2_Pin|f_7SEG2_Pin|g_7SEG2_Pin|d_7SEG_Pin
                          |e_7SEG_Pin|f_7SEG_Pin|g_7SEG_Pin|a_7SEG2_Pin
                          |b_7SEG2_Pin|c_7SEG2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED2_Pin LED_YELLOW2_Pin LED_GREEN2_Pin LED_RED_Pin
                           LED_YELLOW_Pin LED_GREEN_Pin */
  GPIO_InitStruct.Pin = LED_RED2_Pin|LED_YELLOW2_Pin|LED_GREEN2_Pin|LED_RED_Pin
                          |LED_YELLOW_Pin|LED_GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_7SEG_Pin b_7SEG_Pin c_7SEG_Pin d_7SEG2_Pin
                           e_7SEG2_Pin f_7SEG2_Pin g_7SEG2_Pin d_7SEG_Pin
                           e_7SEG_Pin f_7SEG_Pin g_7SEG_Pin a_7SEG2_Pin
                           b_7SEG2_Pin c_7SEG2_Pin */
  GPIO_InitStruct.Pin = a_7SEG_Pin|b_7SEG_Pin|c_7SEG_Pin|d_7SEG2_Pin
                          |e_7SEG2_Pin|f_7SEG2_Pin|g_7SEG2_Pin|d_7SEG_Pin
                          |e_7SEG_Pin|f_7SEG_Pin|g_7SEG_Pin|a_7SEG2_Pin
                          |b_7SEG2_Pin|c_7SEG2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void xRed_State(int i) {
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, i);
    //HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, i);
}
void xYellow_State(int i) {
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, i);
}
void xGreen_State(int i) {
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, i);
}

void yRed_State(int i) {
    HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, i);
    //HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, i);
}
void yYellow_State(int i) {
    HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, i);
}
void yGreen_State(int i) {
    HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, i);
}

void display7SEG(int num){
	if(num < 0 || num > 9) return;
	    HAL_GPIO_WritePin(a_7SEG_GPIO_Port, a_7SEG_Pin, segTable[num][0]);
	    HAL_GPIO_WritePin(b_7SEG_GPIO_Port, b_7SEG_Pin, segTable[num][1]);
	    HAL_GPIO_WritePin(c_7SEG_GPIO_Port, c_7SEG_Pin, segTable[num][2]);
	    HAL_GPIO_WritePin(d_7SEG_GPIO_Port, d_7SEG_Pin, segTable[num][3]);
	    HAL_GPIO_WritePin(e_7SEG_GPIO_Port, e_7SEG_Pin, segTable[num][4]);
	    HAL_GPIO_WritePin(f_7SEG_GPIO_Port, f_7SEG_Pin, segTable[num][5]);
	    HAL_GPIO_WritePin(g_7SEG_GPIO_Port, g_7SEG_Pin, segTable[num][6]);
}

void y_display7SEG(int num){
	if(num < 0 || num > 9) return;
		HAL_GPIO_WritePin(a_7SEG2_GPIO_Port, a_7SEG2_Pin, segTable[num][0]);
		HAL_GPIO_WritePin(b_7SEG2_GPIO_Port, b_7SEG2_Pin, segTable[num][1]);
		HAL_GPIO_WritePin(c_7SEG2_GPIO_Port, c_7SEG2_Pin, segTable[num][2]);
		HAL_GPIO_WritePin(d_7SEG2_GPIO_Port, d_7SEG2_Pin, segTable[num][3]);
		HAL_GPIO_WritePin(e_7SEG2_GPIO_Port, e_7SEG2_Pin, segTable[num][4]);
		HAL_GPIO_WritePin(f_7SEG2_GPIO_Port, f_7SEG2_Pin, segTable[num][5]);
		HAL_GPIO_WritePin(g_7SEG2_GPIO_Port, g_7SEG2_Pin, segTable[num][6]);
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
  __disable_irq();
  while (1)
  {
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
