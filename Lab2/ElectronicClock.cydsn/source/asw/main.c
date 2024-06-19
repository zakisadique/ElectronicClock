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

    UART_Logs_Start();

    TFT_init();
    
//    TFT_setCursor(20, 50);
//    TFT_setTextSize(3);
    
//    uint8_t value = 0;
//    unsigned char value_char = value + 48;
//    TFT_drawChar(10, 60, value_char, WHITE, GRAY, 3);
//    TFT_drawChar(30, 60, value_char, WHITE, GRAY, 3);
//    TFT_drawChar(55, 60, ':', WHITE, GRAY, 3);
//    TFT_drawChar(80, 60, value_char, WHITE, GRAY, 3);
//    TFT_drawChar(100,60, value_char, WHITE, GRAY, 3);
//    TFT_drawChar(30, 50, value_char, WHITE, GRAY, 3);
    
//        uint8_t hours = 0;
//        
//        uint8_t hoursFirstDigit = hours / 10;
////        uint8_t hoursFirstDigit = 0;
//        TFT_drawChar(10, 60, hoursFirstDigit + 48, WHITE, BLACK, 3);
//        
//        uint8_t hoursSecondDigit = hours % 10;
//        TFT_drawChar(30, 60, hoursSecondDigit + 48, WHITE, BLACK, 3);
    
    

    
    //Reconfigure ISRs with OS parameters.
    //This line MUST be called after the hardware driver initialisation!
    EE_system_init();
	
    //Start SysTick
	//Must be done here, because otherwise the isr vector is not overwritten yet
    EE_systick_start();  
	
    
    
    //Start the alarm with 100ms cycle time
    SetRelAlarm(alrm_250ms_input,250,250);
    SetRelAlarm(alrm_50ms_input,50,50);
    SetRelAlarm(alrm1min_input,60000,60000);
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
