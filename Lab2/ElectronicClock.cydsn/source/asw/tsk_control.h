
/*
 * Filename: tsk_control.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Task doing work
 */

#ifndef _H_DEFINE_TSK_CONTROL
#define _H_DEFINE_TSK_CONTROL

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START TSK_CONTROL_INCLUDES */

/* USER CODE END TSK_CONTROL_INCLUDES */



/*
 * description: Task doing work
 * events: ev_events_onData
 * mode: Event
 * name: tsk_control
 * shortname: control
 * signalpoolsRO: sp_common
 * signalpoolsRW: sp_common
 * tickEvent: 0
 * timertickperiod: 1
 */
DeclareTask(tsk_control);

/* USER CODE START TSK_CONTROL_TASKUSERFUNCTION */

/* USER CODE END TSK_CONTROL_TASKUSERFUNCTION */


#endif