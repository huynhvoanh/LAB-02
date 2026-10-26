/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);

/* USER CODE BEGIN 0 */

void display7SEG(int num)
{
    switch (num)
    {
    case 0:
        HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_SET);
        break;

    case 1:
        HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_SET);
        break;

    case 2:
        HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
        break;

    case 3:
        HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
        break;

    case 4:
        HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
        break;

    case 5:
        HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
        break;

    case 6:
        HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
        break;

    case 7:
        HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_SET);
        break;

    case 8:
        HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
        break;

    case 9:
        HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
        break;

    default:
        break;
    }
}

const int MAX_LED = 4;

int index_led = 0;

int led_buffer[4];


void update7SEG(int index)
{
    /* Turn off all displays first */

    HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_SET);

    switch (index)
    {
        case 0:
            display7SEG(led_buffer[0]);
            HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
            break;

        case 1:
            display7SEG(led_buffer[1]);
            HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
            break;

        case 2:
            display7SEG(led_buffer[2]);
            HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
            break;

        case 3:
            display7SEG(led_buffer[3]);
            HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
            break;

        default:
            break;
    }
}


/* ============================================================================
 * CLOCK
 * ============================================================================ */

int hour = 15;
int minute = 8;
int second = 50;


void updateClockBuffer(void)
{
    led_buffer[0] = hour / 10;
    led_buffer[1] = hour % 10;
    led_buffer[2] = minute / 10;
    led_buffer[3] = minute % 10;
}


/* ============================================================================
 * SOFTWARE TIMERS
 * ============================================================================ */

#define TIMER_CYCLE 10


int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int timer3_counter = 0;
int timer3_flag = 0;


void setTimer0(int duration)
{
    timer0_counter = duration / TIMER_CYCLE;
    timer0_flag = 0;
}


void setTimer1(int duration)
{
    timer1_counter = duration / TIMER_CYCLE;
    timer1_flag = 0;
}


void setTimer2(int duration)
{
    timer2_counter = duration / TIMER_CYCLE;
    timer2_flag = 0;
}


void setTimer3(int duration)
{
    timer3_counter = duration / TIMER_CYCLE;
    timer3_flag = 0;
}


void timer_run(void)
{
    if (timer0_counter > 0)
    {
        timer0_counter--;

        if (timer0_counter == 0)
            timer0_flag = 1;
    }


    if (timer1_counter > 0)
    {
        timer1_counter--;

        if (timer1_counter == 0)
            timer1_flag = 1;
    }


    if (timer2_counter > 0)
    {
        timer2_counter--;

        if (timer2_counter == 0)
            timer2_flag = 1;
    }


    if (timer3_counter > 0)
    {
        timer3_counter--;

        if (timer3_counter == 0)
            timer3_flag = 1;
    }
}

#define MAX_LED_MATRIX 8

int index_led_matrix = 0;
int matrix_shift_count = 0;

const uint8_t matrix_A[8] =
{
    0x00,
    0xFC,
    0x12,
    0x11,
    0x11,
    0x12,
    0xFC,
    0x00
};

uint8_t matrix_buffer[8] =
{
    0x00,
    0xFC,
    0x12,
    0x11,
    0x11,
    0x12,
    0xFC,
    0x00
};

void turnOffMatrix(void)
{
    HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_SET);
}


void writeMatrixRows(uint8_t data)
{
    HAL_GPIO_WritePin(
        GPIOB,
        ROW0_Pin,
        (data & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET
    );

    HAL_GPIO_WritePin(
        GPIOB,
        ROW1_Pin,
        (data & 0x02) ? GPIO_PIN_RESET : GPIO_PIN_SET
    );

    HAL_GPIO_WritePin(
        GPIOB,
        ROW2_Pin,
        (data & 0x04) ? GPIO_PIN_RESET : GPIO_PIN_SET
    );

    HAL_GPIO_WritePin(
        GPIOB,
        ROW3_Pin,
        (data & 0x08) ? GPIO_PIN_RESET : GPIO_PIN_SET
    );

    HAL_GPIO_WritePin(
        GPIOB,
        ROW4_Pin,
        (data & 0x10) ? GPIO_PIN_RESET : GPIO_PIN_SET
    );

    HAL_GPIO_WritePin(
        GPIOB,
        ROW5_Pin,
        (data & 0x20) ? GPIO_PIN_RESET : GPIO_PIN_SET
    );

    HAL_GPIO_WritePin(
        GPIOB,
        ROW6_Pin,
        (data & 0x40) ? GPIO_PIN_RESET : GPIO_PIN_SET
    );

    HAL_GPIO_WritePin(
        GPIOB,
        ROW7_Pin,
        (data & 0x80) ? GPIO_PIN_RESET : GPIO_PIN_SET
    );
}


void updateLEDMatrix(int index)
{
    if (index < 0 || index >= MAX_LED_MATRIX)
        return;

    turnOffMatrix();

    writeMatrixRows(matrix_buffer[index]);

    switch (index)
    {
        case 0:
            HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_RESET);
            break;

        case 1:
            HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_RESET);
            break;

        case 2:
            HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_RESET);
            break;

        case 3:
            HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_RESET);
            break;

        case 4:
            HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_RESET);
            break;

        case 5:
            HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_RESET);
            break;

        case 6:
            HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_RESET);
            break;

        case 7:
            HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_RESET);
            break;

        default:
            break;
    }
}


/* ============================================================================
 * MATRIX SCAN
 * ============================================================================ */

void matrixScanTask(void)
{
    static uint32_t last_scan = 0;

    if ((HAL_GetTick() - last_scan) >= 2)
    {
        last_scan = HAL_GetTick();

        updateLEDMatrix(index_led_matrix);

        index_led_matrix++;

        if (index_led_matrix >= MAX_LED_MATRIX)
        {
            index_led_matrix = 0;
        }
    }
}


/* ============================================================================
 * LOAD LETTER A
 * ============================================================================ */

void loadLetterA(void)
{
    int i;

    for (i = 0; i < MAX_LED_MATRIX; i++)
    {
        matrix_buffer[i] = matrix_A[i];
    }

    index_led_matrix = 0;
    matrix_shift_count = 0;
}


/* ============================================================================
 * SHIFT MATRIX LEFT
 * ============================================================================ */

void shiftMatrixLeft(void)
{
    int i;

    for (i = 0; i < MAX_LED_MATRIX - 1; i++)
    {
        matrix_buffer[i] = matrix_buffer[i + 1];
    }

    matrix_buffer[MAX_LED_MATRIX - 1] = 0x00;

    matrix_shift_count++;

    if (matrix_shift_count >= MAX_LED_MATRIX)
    {
        loadLetterA();
    }
}


/* USER CODE END 0 */


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    HAL_Init();

    SystemClock_Config();


    /*
     * PA13 / PA14 / PA15 are used by ENM5 / ENM6 / ENM7.
     * Release these pins from JTAG/SWD.
     */
    __HAL_RCC_AFIO_CLK_ENABLE();
    __HAL_AFIO_REMAP_SWJ_DISABLE();


    MX_GPIO_Init();
    MX_TIM2_Init();


    /* Start TIM2 interrupt */
    HAL_TIM_Base_Start_IT(&htim2);


    /* Initialize clock */
    updateClockBuffer();


    /* Initialize matrix */
    loadLetterA();


    /* Software timers */

    setTimer0(1000);

    /* 10 ms refresh for 7 segment */
    setTimer1(10);

    setTimer2(10);

    /* Move matrix every 500 ms */
    setTimer3(500);


    while (1)
    {
        /* =====================================================
         * CLOCK
         * ===================================================== */

        if (timer0_flag == 1)
        {
            second++;

            if (second >= 60)
            {
                second = 0;
                minute++;
            }

            if (minute >= 60)
            {
                minute = 0;
                hour++;
            }

            if (hour >= 24)
            {
                hour = 0;
            }

            updateClockBuffer();

            HAL_GPIO_TogglePin(GPIOA, DOT_Pin);

            setTimer0(1000);
        }


        /* =====================================================
         * 7-SEGMENT
         * ===================================================== */

        if (timer1_flag == 1)
        {
            update7SEG(index_led);

            index_led++;

            if (index_led >= MAX_LED)
            {
                index_led = 0;
            }

            setTimer1(10);
        }


        /* =====================================================
         * MATRIX SCAN
         * ===================================================== */

        matrixScanTask();


        /* =====================================================
         * MATRIX SHIFT
         * ===================================================== */

        if (timer3_flag == 1)
        {
            shiftMatrixLeft();

            setTimer3(500);
        }
    }
}


/* ============================================================================
 * SYSTEM CLOCK
 * ============================================================================ */

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


    RCC_OscInitStruct.OscillatorType =
        RCC_OSCILLATORTYPE_HSI;

    RCC_OscInitStruct.HSIState =
        RCC_HSI_ON;

    RCC_OscInitStruct.HSICalibrationValue =
        RCC_HSICALIBRATION_DEFAULT;

    RCC_OscInitStruct.PLL.PLLState =
        RCC_PLL_NONE;


    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }


    RCC_ClkInitStruct.ClockType =
          RCC_CLOCKTYPE_HCLK
        | RCC_CLOCKTYPE_SYSCLK
        | RCC_CLOCKTYPE_PCLK1
        | RCC_CLOCKTYPE_PCLK2;


    RCC_ClkInitStruct.SYSCLKSource =
        RCC_SYSCLKSOURCE_HSI;

    RCC_ClkInitStruct.AHBCLKDivider =
        RCC_SYSCLK_DIV1;

    RCC_ClkInitStruct.APB1CLKDivider =
        RCC_HCLK_DIV1;

    RCC_ClkInitStruct.APB2CLKDivider =
        RCC_HCLK_DIV1;


    if (HAL_RCC_ClockConfig(
            &RCC_ClkInitStruct,
            FLASH_LATENCY_0) != HAL_OK)
    {
        Error_Handler();
    }
}


/* ============================================================================
 * TIM2
 * ============================================================================ */

static void MX_TIM2_Init(void)
{
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};


    htim2.Instance = TIM2;

    htim2.Init.Prescaler = 7999;

    htim2.Init.CounterMode =
        TIM_COUNTERMODE_UP;

    htim2.Init.Period = 9;

    htim2.Init.ClockDivision =
        TIM_CLOCKDIVISION_DIV1;

    htim2.Init.AutoReloadPreload =
        TIM_AUTORELOAD_PRELOAD_DISABLE;


    if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
    {
        Error_Handler();
    }


    sClockSourceConfig.ClockSource =
        TIM_CLOCKSOURCE_INTERNAL;


    if (HAL_TIM_ConfigClockSource(
            &htim2,
            &sClockSourceConfig) != HAL_OK)
    {
        Error_Handler();
    }


    sMasterConfig.MasterOutputTrigger =
        TIM_TRGO_RESET;

    sMasterConfig.MasterSlaveMode =
        TIM_MASTERSLAVEMODE_DISABLE;


    if (HAL_TIMEx_MasterConfigSynchronization(
            &htim2,
            &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }
}

static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};


    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_AFIO_CLK_ENABLE();

    HAL_GPIO_WritePin(
        GPIOA,
          ENM0_Pin
        | ENM1_Pin
        | ENM2_Pin
        | ENM3_Pin
        | ENM4_Pin
        | ENM5_Pin
        | ENM6_Pin
        | ENM7_Pin,
        GPIO_PIN_SET
    );

    HAL_GPIO_WritePin(
        GPIOA,
          DOT_Pin
        | LED_RED_Pin
        | EN0_Pin
        | EN1_Pin
        | EN2_Pin
        | EN3_Pin,
        GPIO_PIN_RESET
    );

    HAL_GPIO_WritePin(
        GPIOB,
          ROW0_Pin
        | ROW1_Pin
        | ROW2_Pin
        | ROW3_Pin
        | ROW4_Pin
        | ROW5_Pin
        | ROW6_Pin
        | ROW7_Pin,
        GPIO_PIN_SET
    );

    HAL_GPIO_WritePin(
        GPIOB,
          a_Pin
        | b_Pin
        | c_Pin
        | d_Pin
        | e_Pin
        | f_Pin
        | g_Pin,
        GPIO_PIN_RESET
    );

    GPIO_InitStruct.Pin =
          ENM0_Pin
        | ENM1_Pin
        | DOT_Pin
        | LED_RED_Pin
        | EN0_Pin
        | EN1_Pin
        | EN2_Pin
        | EN3_Pin
        | ENM2_Pin
        | ENM3_Pin
        | ENM4_Pin
        | ENM5_Pin
        | ENM6_Pin
        | ENM7_Pin;

    GPIO_InitStruct.Mode =
        GPIO_MODE_OUTPUT_PP;

    GPIO_InitStruct.Pull =
        GPIO_NOPULL;

    GPIO_InitStruct.Speed =
        GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


    GPIO_InitStruct.Pin =
          a_Pin
        | b_Pin
        | c_Pin
        | d_Pin
        | e_Pin
        | f_Pin
        | g_Pin
        | ROW0_Pin
        | ROW1_Pin
        | ROW2_Pin
        | ROW3_Pin
        | ROW4_Pin
        | ROW5_Pin
        | ROW6_Pin
        | ROW7_Pin;

    GPIO_InitStruct.Mode =
        GPIO_MODE_OUTPUT_PP;

    GPIO_InitStruct.Pull =
        GPIO_NOPULL;

    GPIO_InitStruct.Speed =
        GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


    /*
     * Free PA13 / PA14 / PA15
     */
    __HAL_AFIO_REMAP_SWJ_DISABLE();
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        timer_run();
    }
}

void Error_Handler(void)
{
    __disable_irq();

    while (1)
    {
    }
}


#ifdef USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
    /* User can add implementation here */
}

#endif
