
/*
 * Filename: sp_common.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: The common global signal pool, all signals will be stored here
 */

#ifndef _H_DEFINE_SP_COMMON
#define _H_DEFINE_SP_COMMON

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START SP_COMMON_INCLUDES */

/* USER CODE END SP_COMMON_INCLUDES */



#include "sc_buttons.h"
#include "sc_events.h"
#include "sc_clockdata.h"



/*
 * description: A Signal for the input buttons
 * indriver: default
 * name: so_buttons
 * onDataError: 0
 * onDataUpdate: 0
 * outdriver: 0
 * resource: res_buttons_Lock
 * shortname: buttons
 * signalclass: sc_buttons
 * signalpool: sp_common
 */
extern SC_BUTTONS_t SO_BUTTONS_signal;


/*
 * description: A Signal for events
 * indriver: 0
 * name: so_events
 * onDataError: 0
 * onDataUpdate: ev_events_onData
 * outdriver: 0
 * resource: res_events_Lock
 * shortname: events
 * signalclass: sc_events
 * signalpool: sp_common
 */
extern SC_EVENTS_t SO_EVENTS_signal;


/*
 * description: A Signal for the clock data
 * indriver: 0
 * name: so_clockData
 * onDataError: 0
 * onDataUpdate: 0
 * outdriver: default
 * resource: res_clockdata_Lock
 * shortname: clockData
 * signalclass: sc_clockData
 * signalpool: sp_common
 */
extern SC_CLOCKDATA_t SO_CLOCKDATA_signal;



/*
 * Increments the age of the signals in this pool 
 */
void RTE_timertick_sp_common_tick(uint32_t tick);

/*
 * Reset all signals in this pool
 */
void RTE_reset_sp_common();

#endif