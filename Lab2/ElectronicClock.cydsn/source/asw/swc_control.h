
/*
 * Filename: swc_control.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Software component
 */

#ifndef _H_DEFINE_SWC_CONTROL
#define _H_DEFINE_SWC_CONTROL

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SWC_CONTROL_INCLUDES */

/* USER CODE END SWC_CONTROL_INCLUDES */



/* USER CODE START SWC_CONTROL_USERDEFINITIONS */
    

/* USER CODE END SWC_CONTROL_USERDEFINITIONS */


/*
 * component: swc_control
 * cycletime: 0
 * description: Runnable
 * events: ev_events_onData
 * name: CONTROL_runStateMachine_run
 * shortname: runStateMachine
 * signalIN: so_events
 * signalOUT: so_clockData
 * task: tsk_control
 */
void CONTROL_runStateMachine_run(RTE_event ev);


#endif