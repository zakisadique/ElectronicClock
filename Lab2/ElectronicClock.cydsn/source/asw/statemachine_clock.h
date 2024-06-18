/**
* \file watchdog.c
* \author P. Fromm
* \date 22.3.20
*
* \brief Watchdog Statemachine
*
* \copyright Copyright ©2020
* Department of electrical engineering and information technology, Hochschule Darmstadt - University of applied sciences (h_da). All Rights Reserved.
* Permission to use, copy, modify, and distribute this software and its documentation for educational, and research purposes in the context of non-commercial
* (unless permitted by h_da) and official h_da projects, is hereby granted for enrolled students of h_da, provided that the above copyright notice,
* this paragraph and the following paragraph appear in all copies, modifications, and distributions.
* Contact Prof.Dr.-Ing. Peter Fromm, peter.fromm@h-da.de, Birkenweg 8 64295 Darmstadt - GERMANY for commercial requests.
*
* \warning This software is a PROTOTYPE version and is not designed or intended for use in production, especially not for safety-critical applications!
* The user represents and warrants that it will NOT use or redistribute the Software for such purposes.
* This prototype is for research purposes only. This software is provided "AS IS," without a warranty of any kind.
*/

#ifndef STATEMACHINE_CLOCK_H
#define STATEMACHINE_CLOCK_H

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "project.h"


#include "statemachine.h"


/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions                                                */
/*****************************************************************************/



/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

typedef enum {
    WIDGET_HOUR,
    WIDGET_MIN

} WIDGET_ACTIVE;

/*****************************************************************************/
/* Local function prototypes ('static') Actions                               */
/*****************************************************************************/
static void CLOCK_dispatch_KL_Hours();
static void CLOCK_dispatch_KL_Mins();
static void CLOCK_dispatch_KL_HoursMins();

static void CLOCK_dispatch_KR_Hours();
static void CLOCK_dispatch_KR_Mins();
static void CLOCK_dispatch_KRLP_Hours();
static void CLOCK_dispatch_KRLP_Mins();

static void CLOCK_dispatch_250MS_Hours();
static void CLOCK_dispatch_250MS_Mins();
static void CLOCK_increment1Minute();



static void CLOCK_setEditFonts();
static void CLOCK_incrementWidget();
static void CLOCK_setDisplayFonts();


/*****************************************************************************/
/* State Machine Table Declarations                                          */
/*****************************************************************************/

//==================================================== CLOCK CONTAINER =======================================

/**  ===== STATE_CLOCK_C_ISDISPLAYING ====   */
const STATE_stateInnerTransitionTable_t STATE_CLOCK_C_ISDISPLAYING_Transitions = {
/*    Event                     ToState                             Guard               Action                      */
    { EV_KEYLEFT,               CLOCK_C_ISEDITINGHOURS,             0,                  CLOCK_dispatch_KL_Hours     },  
    { EV_1MIN,                  CLOCK_C_ISDISPPLAYING,              0,                  CLOCK_increment1Minute      },  
};

   
/**  ===== STATE_CLOCK_C_ISEDITINGHOURS ====   */
const STATE_stateInnerTransitionTable_t STATE_CLOCK_C_ISEDITINGHOURS_Transitions = {
/*    Event                     ToState                             Guard               Action                      */
    { EV_KEYLEFT,               CLOCK_C_ISEDITINGMINUTES,           0,                  CLOCK_dispatch_KL_HoursMins },  
    { EV_KEYRIGHT,              CLOCK_C_ISEDITINGHOURS,             0,                  CLOCK_dispatch_KR_Hours     }, 
    { EV_KEYRIGHTLONGPRESS,     CLOCK_C_ISEDITINGHOURS,             0,                  CLOCK_dispatch_KRLP_Hours   },  
    { EV_250MS,                 CLOCK_C_ISEDITINGHOURS,             0,                  CLOCK_dispatch_250MS_Hours  },  
};

/**  ===== STATE_CLOCK_C_ISEDITINGMINS ====   */
const STATE_stateInnerTransitionTable_t STATE_CLOCK_C_ISEDITINGMins_Transitions = {
/*    Event                     ToState                             Guard               Action                      */
    { EV_KEYLEFT,               CLOCK_C_ISDISPPLAYING,              0,                  CLOCK_dispatch_KL_Mins      },  
    { EV_KEYRIGHT,              CLOCK_C_ISEDITINGMINUTES,           0,                  CLOCK_dispatch_KR_Mins      }, 
    { EV_KEYRIGHTLONGPRESS,     CLOCK_C_ISEDITINGMINUTES,           0,                  CLOCK_dispatch_KRLP_Mins    },  
    { EV_250MS,                 CLOCK_C_ISEDITINGMINUTES,           0,                  CLOCK_dispatch_250MS_Mins   },  
};


const STATE_stateOuterTransitionTable_t CLOCK_Container_Transitions = {
/*    fromState                     Pointer to table                                Size of table [Elements]    */
    { CLOCK_C_ISDISPPLAYING,        &STATE_CLOCK_C_ISDISPLAYING_Transitions,        sizeof(STATE_CLOCK_C_ISDISPLAYING_Transitions)/sizeof(STATE_stateInnerTransition_t)     },
    { CLOCK_C_ISEDITINGHOURS,       &STATE_CLOCK_C_ISEDITINGHOURS_Transitions,      sizeof(STATE_CLOCK_C_ISEDITINGHOURS_Transitions)/sizeof(STATE_stateInnerTransition_t)    },
    { CLOCK_C_ISEDITINGMINUTES,     &STATE_CLOCK_C_ISEDITINGMins_Transitions,       sizeof(STATE_CLOCK_C_ISEDITINGMins_Transitions)/sizeof(STATE_stateInnerTransition_t)    },
};
const uint16_t CLOCK_Container_Transitions_Size = sizeof(CLOCK_Container_Transitions) / sizeof (STATE_stateOuterTransition_t);


// set font - maybe
const STATE_stateActionTable_t CLOCK_Container_StateActions = {
      /* State                      Entry       Exit */
    { CLOCK_C_ISDISPPLAYING,        0,          0       },
    { CLOCK_C_ISEDITINGHOURS,       0,          0       },
    { CLOCK_C_ISEDITINGMINUTES,     0,          0       },
};
const uint16_t CLOCK_Container_StateActions_Size = sizeof(CLOCK_Container_StateActions) / sizeof(STATE_stateAction_t);
    

STATEMACHINE_t CLOCK_CONTAINER_FSM = 
{
    &CLOCK_Container_Transitions,       
    sizeof(CLOCK_Container_Transitions) / sizeof (STATE_stateOuterTransition_t),
    &CLOCK_Container_StateActions,      
    sizeof(CLOCK_Container_StateActions) / sizeof(STATE_stateAction_t),
    CLOCK_C_ISDISPPLAYING,                     
};




//==================================================== CLOCK WIDGETS =======================================

/**  ===== STATE_CLOCK_W_ISDISPLAYING ====   */
const STATE_stateInnerTransitionTable_t STATE_CLOCK_W_ISDISPLAYING_Transitions = {
/*    Event                     ToState                             Guard               Action                      */
    { EV_KEYLEFT,               CLOCK_W_ISEDITING,                  0,                  CLOCK_setEditFonts          },  
};

   
/**  ===== STATE_CLOCK_W_ISEDITING ====   */
const STATE_stateInnerTransitionTable_t STATE_CLOCK_W_ISEDITING_Transitions = {
/*    Event                     ToState                             Guard               Action                      */
    { EV_KEYRIGHT,              CLOCK_W_ISEDITING,                  0,                  CLOCK_incrementWidget       }, 
    { EV_KEYRIGHTLONGPRESS,     CLOCK_W_ISAUTOINCREMENTING,         0,                  0                           },  
    { EV_KEYLEFT,               CLOCK_W_ISDISPPLAYING,              0,                  CLOCK_setDisplayFonts       },  
};

/**  ===== CLOCK_W_ISAUTOINCREMENTING ====   */
const STATE_stateInnerTransitionTable_t CLOCK_W_ISAUTOINCREMENTING_Transitions = {
/*    Event                     ToState                             Guard               Action                      */  
    { EV_KEYRIGHT,              CLOCK_W_ISEDITING,                  0,                  CLOCK_incrementWidget       },  
    { EV_250MS,                 CLOCK_W_ISAUTOINCREMENTING,         0,                  CLOCK_incrementWidget       },  
};


const STATE_stateOuterTransitionTable_t CLOCK_Widget_Transitions = {
/*    fromState                     Pointer to table                                Size of table [Elements]    */
    { CLOCK_W_ISDISPPLAYING,        &STATE_CLOCK_W_ISDISPLAYING_Transitions,        sizeof(STATE_CLOCK_W_ISDISPLAYING_Transitions)/sizeof(STATE_stateInnerTransition_t)     },
    { CLOCK_W_ISEDITING,            &STATE_CLOCK_W_ISEDITING_Transitions,           sizeof(STATE_CLOCK_W_ISEDITING_Transitions)/sizeof(STATE_stateInnerTransition_t)        },
    { CLOCK_W_ISAUTOINCREMENTING,   &CLOCK_W_ISAUTOINCREMENTING_Transitions,        sizeof(CLOCK_W_ISAUTOINCREMENTING_Transitions)/sizeof(STATE_stateInnerTransition_t)     },
};
const uint16_t CLOCK_Widget_Transitions_Size = sizeof(CLOCK_Widget_Transitions) / sizeof (STATE_stateOuterTransition_t);


// set font - maybe
const STATE_stateActionTable_t CLOCK_Widget_StateActions = {
      /* State                      Entry       Exit */
    { CLOCK_W_ISDISPPLAYING,        0,          0       },
    { CLOCK_W_ISEDITING,            0,          0       },
    { CLOCK_W_ISAUTOINCREMENTING,   0,          0       },
};
const uint16_t CLOCK_Widget_StateActions_Size = sizeof(CLOCK_Widget_StateActions) / sizeof(STATE_stateAction_t);
    

STATEMACHINE_t CLOCK_Widget_FSM = 
{
    &CLOCK_Widget_Transitions,       
    sizeof(CLOCK_Widget_Transitions) / sizeof (STATE_stateOuterTransition_t),
    &CLOCK_Widget_StateActions,      
    sizeof(CLOCK_Widget_StateActions) / sizeof(STATE_stateAction_t),
    CLOCK_W_ISDISPPLAYING,                     
};





/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/


static void CLOCK_DISPATCH_WRAPPER(WIDGET_ACTIVE activeWidget, STATE_event_t event);

#endif /* STATEMACHINE_CLOCK_H */



