/*
 * Filename: swc_input.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Software component
 * name: swc_input
 * shortname: input
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "swc_input.h"



/* USER CODE START SWC_INPUT_INCLUDE */

/* USER CODE END SWC_INPUT_INCLUDE */


#include "sp_common.h"

/* USER CODE START SWC_INPUT_USERDEFINITIONS */

#define POLLINGRATE 25
#define LONG_PRESS_DURATION 1000

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
void INPUT_readButtons_run(RTE_event ev){
	
	/* USER CODE START INPUT_readButtons_run */
    
//    UART_Logs_PutString("INPUT_readButtons_run\n");
    
    RTE_SC_BUTTONS_pullPort(&SO_BUTTONS_signal);
    
    SC_BUTTONS_data_t input = SC_BUTTONS_INIT_DATA;
    RTE_SC_BUTTONS_getThreadSafe(&SO_BUTTONS_signal, &input);
    
    SC_EVENTS_data_t event = SC_EVENTS_INIT_DATA;
    
    
    if (input.m_buttonLeftPressed == FALSE && input.m_buttonRightPressed == FALSE){
        
        if (input.m_buttonLeftPressedTime != 0){
            input.m_buttonLeftPressedTime = 0;
            RTE_SC_BUTTONS_set(&SO_BUTTONS_signal, input);
            
            event.m_event = EV_KEYLEFT;
            
//            UART_Logs_PutString("EV_KEYLEFT\n");
            RTE_SC_EVENTS_set(&SO_EVENTS_signal, event);
           

        
        }
        
        else if ((input.m_buttonRightPressedTime > 0) && (input.m_buttonRightPressedTime < (LONG_PRESS_DURATION / POLLINGRATE))){
            
            
            input.m_buttonRightPressedTime = 0;
            RTE_SC_BUTTONS_set(&SO_BUTTONS_signal, input);
            
            
            event.m_event = EV_KEYRIGHT;
            RTE_SC_EVENTS_set(&SO_EVENTS_signal, event);

//            UART_Logs_PutString("EV_KEYRIGHT\n");
            
        } else if (input.m_buttonRightPressedTime >= (LONG_PRESS_DURATION / POLLINGRATE)){
            
            event.m_event = EV_KEYRIGHTLONGPRESS;
            RTE_SC_EVENTS_set(&SO_EVENTS_signal, event);
            
//            UART_Logs_PutString("EV_KEYRIGHTLONGPRESS\n");
            
            input.m_buttonRightPressedTime = 0;
            RTE_SC_BUTTONS_set(&SO_BUTTONS_signal, input);
        }

//        CancelAlarm(alrm_buttonPressed);
    }
    
    
    
    


    /* USER CODE END INPUT_readButtons_run */
}

/*
 * component: swc_input
 * cycletime: 60000
 * description: Runnable
 * events: ev_60000ms
 * name: INPUT_1min_run
 * shortname: 1sec
 * signalIN: 
 * signalOUT: so_events
 * task: tsk_input
 */
void INPUT_1min_run(RTE_event ev){
	
	/* USER CODE START INPUT_1sec_run */
//    UART_Logs_PutString("INPUT_1sec_run\n");
    
    static boolean_t firstUse = TRUE;
    if (firstUse == TRUE){
        
        // do not set event for 1 min at time t = 0
        firstUse = FALSE;
        return;
    
    }
    
    SC_EVENTS_data_t event = SC_EVENTS_INIT_DATA;
    event.m_event = EV_1MIN;
    RTE_SC_EVENTS_set(&SO_EVENTS_signal, event);
    

    /* USER CODE END INPUT_1sec_run */
}

/*
 * component: swc_input
 * cycletime: 250
 * description: Runnable
 * events: ev_250ms
 * name: INPUT_250ms_run
 * shortname: 250ms
 * signalIN: 
 * signalOUT: so_events
 * task: tsk_input
 */
void INPUT_250ms_run(RTE_event ev){
	
	/* USER CODE START INPUT_250ms_run */
//    UART_Logs_PutString("INPUT_250ms_run\n");
    
    SC_EVENTS_data_t event = SC_EVENTS_INIT_DATA;
    event.m_event = EV_250MS;
    RTE_SC_EVENTS_set(&SO_EVENTS_signal, event);

    /* USER CODE END INPUT_250ms_run */
}

/* USER CODE START SWC_INPUT_FUNCTIONS */

/* USER CODE END SWC_INPUT_FUNCTIONS */

