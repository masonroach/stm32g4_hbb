/*!
 * \file gpio.hpp
 * \brief Header file for GPIO functions
 * \author Mason Roach
 * \date February 20, 2021
 */

#ifndef __GPIO_CORE_H
#define __GPIO_CORE_H
// =============================================================================
// Defines
// =============================================================================
#include "stm32wb_corelib.hpp"

/*!
 * \brief GPIO registers structure
 */
typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
	volatile uint32_t BRR;
} GPIO_Regs_t;

#define GPIOA ((GPIO_Regs_t *)GPIOA_BASE)
#define GPIOB ((GPIO_Regs_t *)GPIOB_BASE)
#define GPIOC ((GPIO_Regs_t *)GPIOC_BASE)
#define GPIOD ((GPIO_Regs_t *)GPIOD_BASE)
#define GPIOE ((GPIO_Regs_t *)GPIOE_BASE)
#define GPIOH ((GPIO_Regs_t *)GPIOH_BASE)

typedef enum {
	// Standard modes
	MODE_INPUT = 0x0,
	MODE_OUTPUT = 0x1,
	MODE_ALTERNATE = 0x2,
	MODE_ANALOG = 0x3,

	// Alternate modes
	MODE_AF_0 = (0x0 << 2) | 0x2,	
	MODE_AF_1 = (0x1 << 2) | 0x2,
	MODE_AF_2 = (0x2 << 2) | 0x2,	
	MODE_AF_3 = (0x3 << 2) | 0x2,	
	MODE_AF_4 = (0x4 << 2) | 0x2,	
	MODE_AF_5 = (0x5 << 2) | 0x2,	
	MODE_AF_6 = (0x6 << 2) | 0x2,	
	MODE_AF_7 = (0x7 << 2) | 0x2,	
	MODE_AF_8 = (0x8 << 2) | 0x2,	
	MODE_AF_9 = (0x9 << 2) | 0x2,	
	MODE_AF_10 = (0xA << 2) | 0x2,	
	MODE_AF_11 = (0xB << 2) | 0x2,	
	MODE_AF_12 = (0xC << 2) | 0x2,	
	MODE_AF_13 = (0xD << 2) | 0x2,	
	MODE_AF_14 = (0xE << 2) | 0x2,	
	MODE_AF_15 = (0xF << 2) | 0x2	
} GPIO_Mode_t;

#define MODE_AF0_SYS_AF MODE_AF_0
#define MODE_AF1_TIM1 MODE_AF_1
#define MODE_AF1_TIM2 MODE_AF_1
#define MODE_AF1_LPTIM1 MODE_AF_1
#define MODE_AF2_TIM1 MODE_AF_2
#define MODE_AF2_TIM2 MODE_AF_2
#define MODE_AF3_SPI2 MODE_AF_3
#define MODE_AF3_SAI1 MODE_AF_3
#define MODE_AF3_TIM1 MODE_AF_3
#define MODE_AF4_I2C1 MODE_AF_4
#define MODE_AF4_I2C3 MODE_AF_4
#define MODE_AF5_SPI1 MODE_AF_5
#define MODE_AF5_SPI2 MODE_AF_5
#define MODE_AF6_RF MODE_AF_6
#define MODE_AF7_USART1 MODE_AF_7
#define MODE_AF8_LPUART1 MODE_AF_8
#define MODE_AF9_TSC MODE_AF_9
#define MODE_AF10_USB MODE_AF_10
#define MODE_AF10_QUADSPI MODE_AF_10
#define MODE_AF11_LCD MODE_AF_11
#define MODE_AF12_COMP1 MODE_AF_12
#define MODE_AF12_COMP2 MODE_AF_12
#define MODE_AF12_TIM1 MODE_AF_12
#define MODE_AF13_SAI1 MODE_AF_13
#define MODE_AF14_TIM2 MODE_AF_14
#define MODE_AF14_TIM16 MODE_AF_14
#define MODE_AF14_TIM17 MODE_AF_14
#define MODE_AF14_LPTIM2 MODE_AF_14
#define MODE_AF15_EVENTOUT MODE_AF_15

typedef enum {
	SPEED_LOW = 0x0,
	SPEED_MEDIUM = 0x1,
	SPEED_HIGH = 0x2,
	SPEED_VHIGH = 0x3
} GPIO_Speed_t;

typedef enum {
	OUTTYPE_PUSHPULL = 0x0,
	OUTTYPE_OPENDRAIN = 0x1
} GPIO_OutType_t;

typedef enum {
	PUPD_NOPULL = 0x0,
	PUPD_PULLUP = 0x1,
	PUPD_PULLDOWN = 0x2
	// PUPD_RESERVED = 0x3
} GPIO_Pull_t;

class GPIO_Pin_t {
public:
	// Constructors
	GPIO_Pin_t();
	GPIO_Pin_t(
		GPIO_Regs_t *port_base_addr,
		uint8_t pin,
		GPIO_Mode_t mode,
		GPIO_OutType_t otype,
		GPIO_Speed_t speed,
		GPIO_Pull_t pull,
		bool lock_en = false
	);

	// Destructors
	~GPIO_Pin_t();

	// Init functions
	void config_pin(
		GPIO_Mode_t mode,
		GPIO_OutType_t otype,
		GPIO_Speed_t speed,
		GPIO_Pull_t pull,
		bool lock_en = false
	);

	// Use functions
	void set_pin(
		bool value
	);

protected:
	GPIO_Regs_t *port = 0;
	uint8_t pin;

private:

};

#endif

