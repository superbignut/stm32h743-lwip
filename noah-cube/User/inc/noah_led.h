#ifndef _NOAH_LED_H_
#define _NOAH_LED_H_

#include "stm32h743xx.h"
#include "stm32h7xx.h"

// red LED
#define LED1_PIN    GPIO_PIN_10
#define LED1_GPIO_PORT  GPIOH
#define LED1_GPIO_CLK_ENABLE() __GPIOH_CLK_ENABLE() //

// green LED
#define LED2_PIN    GPIO_PIN_11
#define LED2_GPIO_PORT  GPIOH
#define LED2_GPIO_CLK_ENABLE() __GPIOH_CLK_ENABLE() //

// blue LED
#define LED3_PIN    GPIO_PIN_12
#define LED3_GPIO_PORT  GPIOH
#define LED3_GPIO_CLK_ENABLE() __GPIOH_CLK_ENABLE() //

#define LED_ON GPIO_PIN_RESET   // 0
#define LED_OFF GPIO_PIN_SET    // 1

#define LED1(a) HAL_GPIO_WritePin(LED1_GPIO_PORT, LED1_PIN, a)
#define LED2(a) HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, a)
#define LED3(a) HAL_GPIO_WritePin(LED3_GPIO_PORT, LED3_PIN, a)

// Port->ODR is uint32 (16-31 unused), while i is uint16, each bit represent a GPIO_PIN.
// Because 1^0 = 1; 0^0 = 0; which is unchanged, while 1^1 = 0; 0^1 = 1; which is toggled.
// So port->ODR ^= i; just toggle the corresponding single Pin.
#define digitalToggle(port, pin)  {port->ODR ^= pin;} // xor

#define LED1_TOGGLE digitalToggle(LED1_GPIO_PORT, LED1_PIN)
#define LED2_TOGGLE digitalToggle(LED2_GPIO_PORT, LED2_PIN)
#define LED3_TOGGLE digitalToggle(LED3_GPIO_PORT, LED3_PIN)

// 使用cubemax之后，就不再需要配置初始化了，但是其他的配置和功能函数还是可以写的

#endif
