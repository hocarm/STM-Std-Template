/******************** (C) COPYRIGHT 2016 HocARM.org ********************

* Description        : Blink LED
*/
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

GPIO_InitTypeDef GPIO_InitStructure;


void RCC_Configuration(void);
void GPIO_Configuration(void);
void Delay(__IO uint32_t nCount);

int main(void)
{

  GPIO_Configuration();
  while (1)
  {  
    GPIO_SetBits(GPIOC, GPIO_Pin_12|GPIO_Pin_13);                
    Delay(0xFFFFFF);
 
    GPIO_ResetBits(GPIOC, GPIO_Pin_12|GPIO_Pin_13);
    Delay(0xFFFFFF);
  }
}

void GPIO_Configuration(void)
{
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1 |RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
                         RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
                         RCC_APB2Periph_GPIOE, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13;            //D1  D2
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);  
}

void RCC_Configuration(void)
{   
  /* Setup the microcontroller system. Initialize the Embedded Flash Interface,  
     initialize the PLL and update the SystemFrequency variable. */
  SystemInit();
}

void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */

void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif



/******************* (C) COPYRIGHT 2016 HocARM.org *****END OF FILE****/
