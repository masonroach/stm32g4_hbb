/*!
 * \file rcc.h
 * \brief Header file for RCC registers
 * \author Mason Roach
 * \date March 17, 2021
 */

#ifndef __RCC_CORE_H
#define __RCC_CORE_H
// =============================================================================
// Defines
// =============================================================================
#include "stm32wb_corelib.hpp"

#define RCC_GPIOA_ENABLE() (RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN)
#define RCC_GPIOB_ENABLE() (RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN)
#define RCC_GPIOC_ENABLE() (RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN)
#define RCC_GPIOD_ENABLE() (RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN)
#define RCC_GPIOE_ENABLE() (RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN)
#define RCC_GPIOH_ENABLE() (RCC->AHB2ENR |= RCC_AHB2ENR_GPIOHEN)

#endif

