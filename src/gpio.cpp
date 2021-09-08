/*!
 * \file gpio.cpp
 * \brief Function definitions for GPIO functions
 * \author Mason Roach
 * \date February 20, 2021
 */
#include "stm32wb.hpp"
#include "gpio.hpp"

//==============================================================================
// Pin specific functions
//==============================================================================

#define GPIO_MODER_PIN_BITWIDTH (2)
#define GPIO_MODER_PIN_BITMASK ((1 << GPIO_MODER_PIN_BITWIDTH)-1)
#define GPIO_MODER_BITFIELD_POS(pin) (pin * GPIO_MODER_PIN_BITWIDTH)

#define GPIO_OSPEEDR_PIN_BITWIDTH (2)
#define GPIO_OSPEEDR_PIN_BITMASK ((1 << GPIO_OSPEEDR_PIN_BITWIDTH)-1)
#define GPIO_OSPEEDR_BITFIELD_POS(pin) (pin * GPIO_OSPEEDR_PIN_BITWIDTH)

#define GPIO_OTYPER_PIN_BITWIDTH (1)
#define GPIO_OTYPER_PIN_BITMASK ((1 << GPIO_OTYPER_PIN_BITWIDTH)-1)
#define GPIO_OTYPER_BITFIELD_POS(pin) (pin * GPIO_OTYPER_PIN_BITWIDTH)

#define GPIO_PUPDR_PIN_BITWIDTH (2)
#define GPIO_PUPDR_PIN_BITMASK ((1 << GPIO_PUPDR_PIN_BITWIDTH)-1)
#define GPIO_PUPDR_BITFIELD_POS(pin) (pin * GPIO_PUPDR_PIN_BITWIDTH)

#define GPIO_IDR_PIN_BITWIDTH (1)
#define GPIO_IDR_PIN_BITMASK ((1 << GPIO_IDR_PIN_BITWIDTH)-1)
#define GPIO_IDR_BITFIELD_POS(pin) (pin * GPIO_IDR_PIN_BITWIDTH)

#define GPIO_ODR_PIN_BITWIDTH (1)
#define GPIO_ODR_PIN_BITMASK ((1 << GPIO_ODR_PIN_BITWIDTH)-1)
#define GPIO_ODR_BITFIELD_POS(pin) (pin * GPIO_ODR_PIN_BITWIDTH)

#define GPIO_BSRR_PIN_BITWIDTH (1)
#define GPIO_BSRR_PIN_BITMASK ((1 << GPIO_BSRR_PIN_BITWIDTH)-1)
#define GPIO_BSRR_SET_BITFIELD_POS(pin) (pin * GPIO_BSRR_PIN_BITWIDTH)
#define GPIO_BSRR_RST_BITFIELD_POS(pin) (pin * GPIO_BSRR_PIN_BITWIDTH + 16)

#define GPIO_AFR_PIN_BITWIDTH (4)
#define GPIO_AFR_PIN_BITMASK ((1 << GPIO_AFR_PIN_BITWIDTH)-1)
#define GPIO_AFR_BITFIELD_POS(pin) ((pin%8) * GPIO_AFR_PIN_BITWIDTH)

#define GPIO_LCKR_PIN_BITWIDTH (1)
#define GPIO_LCKR_PIN_BITMASK ((1 << GPIO_LCKR_PIN_BITWIDTH)-1)
#define GPIO_LCKR_BITFIELD_POS(pin) (pin * GPIO_LCKR_PIN_BITWIDTH)

#define GPIO_BRR_PIN_BITWIDTH (1)
#define GPIO_BRR_PIN_BITMASK ((1 << GPIO_BRR_PIN_BITWIDTH)-1)
#define GPIO_BRR_BITFIELD_POS(pin) (pin * GPIO_BRR_PIN_BITWIDTH)

/*!
 * \group??
 */

/*!
 * \brief
 */
GPIO_Pin_t::GPIO_Pin_t(

)
{

}

/*!
 * \brief
 */
GPIO_Pin_t::GPIO_Pin_t(
	GPIO_Regs_t *port_base_addr,
	uint8_t pin,
	GPIO_Mode_t mode,
	GPIO_OutType_t otype,
	GPIO_Speed_t speed,
	GPIO_Pull_t pull,
	bool lock_en
)
{
	uint32_t reg_temp;

	// TODO add assertions
	// assert(port)
	// assert(pin)
	// assert(mode)
	// assert(speed)
	// assert(pull)

	port = port_base_addr;

	// Configure speed
	reg_temp = port->OSPEEDR;
	reg_temp &= ~(GPIO_OSPEEDR_PIN_BITMASK << GPIO_OSPEEDR_BITFIELD_POS(pin));
	reg_temp |= (speed & GPIO_OSPEEDR_PIN_BITMASK) << GPIO_OSPEEDR_BITFIELD_POS(pin);
	port->OSPEEDR = reg_temp; // Push changes back

	// Configure output type
	reg_temp = port->OTYPER;
	reg_temp &= ~(GPIO_OTYPER_PIN_BITMASK << GPIO_OTYPER_BITFIELD_POS(pin));
	reg_temp |= (otype & GPIO_OTYPER_PIN_BITMASK) << GPIO_OTYPER_BITFIELD_POS(pin);
	port->OTYPER = reg_temp; // Push changes back

	// Configure pull-up pull-down register
	reg_temp = port->PUPDR;
	reg_temp &= ~(GPIO_PUPDR_PIN_BITMASK << GPIO_PUPDR_BITFIELD_POS(pin));
	reg_temp |= (pull & GPIO_PUPDR_PIN_BITMASK) << GPIO_PUPDR_BITFIELD_POS(pin);
	port->PUPDR = reg_temp; // Push changes back

	// Configure mode
	reg_temp = port->MODER;
	reg_temp &= ~(GPIO_MODER_PIN_BITMASK << GPIO_MODER_BITFIELD_POS(pin)); 
	reg_temp |= (mode & GPIO_MODER_PIN_BITMASK) << GPIO_MODER_BITFIELD_POS(pin);
	port->MODER = reg_temp; // Push changes back

	// Set alternate function registers if applicable
	if (mode > MODE_ANALOG) {
		
		// Shift mode to only include alternate function code
		mode = (GPIO_Mode_t)(mode >> 2);

		// Determine boundry of the pin
		if (pin < 8) {
			
			// Configure lower alternate function register
			reg_temp = port->AFRL;
			reg_temp &= ~(GPIO_AFR_PIN_BITMASK << GPIO_AFR_BITFIELD_POS(pin));
			reg_temp |= (mode & GPIO_AFR_PIN_BITMASK) << GPIO_AFR_BITFIELD_POS(pin);
			port->AFRL = reg_temp; // Push changes back

		} else {
			
			// Configure upper alternate function register
			reg_temp = port->AFRH;
			reg_temp &= ~(GPIO_AFR_PIN_BITMASK << GPIO_AFR_BITFIELD_POS(pin));
			reg_temp |= (mode & GPIO_AFR_PIN_BITMASK) << GPIO_AFR_BITFIELD_POS(pin);
			port->AFRH = reg_temp; // Push changes back

		}

	}

	// Apply lock
	if (lock_en) {
		port->LCKR |= GPIO_LCKR_BITFIELD_POS(pin);
	}

	// Save pin value for later
	this->pin = pin;

	return;


}

/*!
 * \brief
 */
GPIO_Pin_t::~GPIO_Pin_t(

)
{

}

/*!
 * \brief
 */
void GPIO_Pin_t::config_pin(
	GPIO_Mode_t mode,
	GPIO_OutType_t otype,
	GPIO_Speed_t speed,
	GPIO_Pull_t pull,
	bool lock_en
)
{
	uint32_t reg_temp;

	// TODO add assertions
	// assert(port)
	// assert(pin)
	// assert(mode)
	// assert(speed)
	// assert(pull)

	// Configure speed
	reg_temp = port->OSPEEDR;
	reg_temp &= ~(GPIO_OSPEEDR_PIN_BITMASK << GPIO_OSPEEDR_BITFIELD_POS(pin));
	reg_temp |= (speed & GPIO_OSPEEDR_PIN_BITMASK) << GPIO_OSPEEDR_BITFIELD_POS(pin);
	port->OSPEEDR = reg_temp; // Push changes back

	// Configure output type
	reg_temp = port->OTYPER;
	reg_temp &= ~(GPIO_OTYPER_PIN_BITMASK << GPIO_OTYPER_BITFIELD_POS(pin));
	reg_temp |= (otype & GPIO_OTYPER_PIN_BITMASK) << GPIO_OTYPER_BITFIELD_POS(pin);
	port->OTYPER = reg_temp; // Push changes back

	// Configure pull-up pull-down register
	reg_temp = port->PUPDR;
	reg_temp &= ~(GPIO_PUPDR_PIN_BITMASK << GPIO_PUPDR_BITFIELD_POS(pin));
	reg_temp |= (pull & GPIO_PUPDR_PIN_BITMASK) << GPIO_PUPDR_BITFIELD_POS(pin);
	port->PUPDR = reg_temp; // Push changes back

	// Configure mode
	reg_temp = port->MODER;
	reg_temp &= ~(GPIO_MODER_PIN_BITMASK << GPIO_MODER_BITFIELD_POS(pin)); 
	reg_temp |= (mode & GPIO_MODER_PIN_BITMASK) << GPIO_MODER_BITFIELD_POS(pin);
	port->MODER = reg_temp; // Push changes back

	// Set alternate function registers if applicable
	if (mode > MODE_ANALOG) {
		
		// Shift mode to only include alternate function code
		mode = (GPIO_Mode_t)(mode >> 2);

		// Determine boundry of the pin
		if (pin < 8) {
			
			// Configure lower alternate function register
			reg_temp = port->AFRL;
			reg_temp &= ~(GPIO_AFR_PIN_BITMASK << GPIO_AFR_BITFIELD_POS(pin));
			reg_temp |= (mode & GPIO_AFR_PIN_BITMASK) << GPIO_AFR_BITFIELD_POS(pin);
			port->AFRL = reg_temp; // Push changes back

		} else {
			
			// Configure upper alternate function register
			reg_temp = port->AFRH;
			reg_temp &= ~(GPIO_AFR_PIN_BITMASK << GPIO_AFR_BITFIELD_POS(pin));
			reg_temp |= (mode & GPIO_AFR_PIN_BITMASK) << GPIO_AFR_BITFIELD_POS(pin);
			port->AFRH = reg_temp; // Push changes back

		}

	}

	// Apply lock
	if (lock_en) {
		port->LCKR |= GPIO_LCKR_BITFIELD_POS(pin);
	}

	// Save pin value for later
	this->pin = pin;

	return;

}

/*!
 * \brief
 */
void GPIO_Pin_t::set_pin(
	bool value
)
{

	if (value) {
	
		port->BSRR |= (1 << GPIO_BSRR_SET_BITFIELD_POS(pin));

	} else {

		port->BSRR |= (1 << GPIO_BSRR_RST_BITFIELD_POS(pin));

	}

	return;

}

