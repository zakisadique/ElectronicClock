/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "tft.h"

ISR(systick_handler)
{
    CounterTick(cnt_systick);
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    //Set systick period to 1 ms. Enable the INT and start it.
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, BCLK__BUS_CLK__HZ));
	EE_systick_enable_int();
    
    
    
    // Start Operating System
    for(;;)	    
    	StartOS(OSDEFAULTAPPMODE);
}

void unhandledException()
{
    //Ooops, something terrible happened....check the call stack to see how we got here...
    __asm("bkpt");
}

TASK(tsk_init)
{
    
    //Init MCAL Drivers

//    UART_Logs_Start();

    TFT_init();


    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
	
    
    
    //Start the alarm with 100ms cycle time
//    SetRelAlarm(alrm_250ms_input,250,250);
    SetRelAlarm(alrm_50ms_input,50,50);
//    SetRelAlarm(alrm1min_input,60000,60000);
    SetRelAlarm(alrm_250ms_display,1,250);

    

    ActivateTask(tsk_input);
    ActivateTask(tsk_control);
    ActivateTask(tsk_display);
    ActivateTask(tsk_background);

    TerminateTask();
    
}



TASK(tsk_background)
{
    while(1)
    {
     
    }
    TerminateTask();
    
}



/* [] END OF FILE */
