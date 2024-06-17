/*
 * Filename: sc_buttons_type.c
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * description: Signalclass
 * name: sc_buttons
 * shortname: buttons
 *
 */

#include "project.h"
#include "global.h"
#include "rte.h"
#include "rte_types.h"
#include "sc_buttons_type.h"



/* USER CODE START SC_BUTTONS_INCLUDE */

/* USER CODE END SC_BUTTONS_INCLUDE */




/* USER CODE START SC_BUTTONS_USERDEFINITIONS */

/* USER CODE END SC_BUTTONS_USERDEFINITIONS */


/*****************************************************************************************
 *************** Port Wrapper Implementation for SC_BUTTONS signal  ****************
 *****************************************************************************************/
 
 

/**
 * Default IN driver API
 */
inline RC_t SC_BUTTONS_driverIn(SC_BUTTONS_data_t *const data)
{
	/* USER CODE START driverInSC_BUTTONS */
//#error "Add your code here"

	//Read data from the MCAL driver
    data -> m_buttonRightPressed = FALSE;
    data -> m_buttonLeftPressed = FALSE;
    
    if (BUTTON_1_Read() == 1 || BUTTON_3_Read() == 1){
        data -> m_buttonRightPressed = FALSE;
        data -> m_buttonLeftPressed = TRUE;
        data -> m_buttonRightPressedTime = 0;
    
    } 
    if (BUTTON_2_Read() == 1 || BUTTON_4_Read() == 1){
        data -> m_buttonRightPressed = TRUE;
        data -> m_buttonLeftPressed = FALSE;
        
        data -> m_buttonRightPressedTime += 1;
        
    }

	//Scale it to the application type

	return RC_SUCCESS;
	/* USER CODE END driverInSC_BUTTONS */
}



