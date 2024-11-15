
/*
 * Filename: swc_input.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: Software component
 */

#ifndef _H_DEFINE_SWC_INPUT
#define _H_DEFINE_SWC_INPUT

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SWC_INPUT_INCLUDES */

/* USER CODE END SWC_INPUT_INCLUDES */



/* USER CODE START SWC_INPUT_USERDEFINITIONS */

/* USER CODE END SWC_INPUT_USERDEFINITIONS */


/*
 * component: swc_input
 * cycletime: 0
 * description: Runnable
 * events: ev_ButtonsPressed
 * name: INPUT_readButtons_run
 * shortname: readButtons
 * signalIN: so_buttons
 * signalOUT: so_events
 * task: tsk_input
 */
void INPUT_readButtons_run(RTE_event ev);

/*
 * component: swc_input
 * cycletime: 60000
 * description: Runnable
 * events: 
 * name: INPUT_1min_run
 * shortname: 1min
 * signalIN: 
 * signalOUT: so_events
 * task: tsk_input
 */
void INPUT_1min_run(RTE_event ev);

/*
 * component: swc_input
 * cycletime: 250
 * description: Runnable
 * events: 
 * name: INPUT_250ms_run
 * shortname: 250ms
 * signalIN: 
 * signalOUT: so_events
 * task: tsk_input
 */
void INPUT_250ms_run(RTE_event ev);


#endif