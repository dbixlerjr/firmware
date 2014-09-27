/**
 ******************************************************************************
 * @file    syshealth_hal.h
 * @author  Matthew McGowan
 * @version V1.0.0
 * @date    25-Sept-2014
 * @brief
 ******************************************************************************
  Copyright (c) 2013-14 Spark Labs, Inc.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

#ifndef SYSHEALTH_HAL_H
#define	SYSHEALTH_HAL_H

#ifdef	__cplusplus
extern "C" {
#endif

enum eSystemHealth {
  FIRST_RETRY = 1,
  SECOND_RETRY = 2,
  THIRD_RETRY = 3,
  ENTERED_SparkCoreConfig,
  ENTERED_Main,
  ENTERED_WLAN_Loop,
  ENTERED_Setup,
  ENTERED_Loop,
  RAN_Loop,
  PRESERVE_APP,
};

#ifdef STM32_DEVICE
#include "hw_config.h"
#define SET_SYS_HEALTH(health) BKP_WriteBackupRegister(BKP_DR1, (health))
#define GET_SYS_HEALTH() BKP_ReadBackupRegister(BKP_DR1)

extern uint16_t sys_health_cache;
#define DECLARE_SYS_HEALTH(health)  do { if ((health) > sys_health_cache) {SET_SYS_HEALTH(sys_health_cache=(health));}} while(0)

#else

#define SET_SYS_HEALTH(health)
#define GET_SYS_HEALTH()  (0)
#define DECLARE_SYS_HEALTH(health)

#endif


#ifdef	__cplusplus
}
#endif

#endif	/* SYSHEALTH_HAL_H */

