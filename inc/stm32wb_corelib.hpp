/*!
 * \file
 * \brief
 * \author
 * \date
 */

#ifndef __STM32WB_CORELIB_H
#define __STM32WB_CORELIB_H

#include "stm32wb55_memorymap.hpp"

/*!
 * \brief Abstracted return values for drivers
 */
typedef enum {
	ERR_NONE = 0, //! No error, success
	ERR_BUSY, //! Peripheral is busy
	ERR_INIT, //! An error occurred during an initialization process
	ERR_NOPORT, //! No port is declared yet
} Sys_Err_t;

#endif

