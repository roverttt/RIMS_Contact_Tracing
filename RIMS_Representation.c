/*
This code was automatically generated using the Riverside-Irvine State machine Builder tool
Version 2.7 --- 12/13/2020 6:26:4 PST
*/

#include "rims.h"

/*Define user variables and functions for this state machine here.*/
#define population 4
unsigned long AccumulatedRisk[population];
unsigned char SM1_Clk;
void TimerISR() {
   SM1_Clk = 1;
}

enum SM1_States { SM1_Init, SM1_Base_State, SM1_Menu, SM1_Report_Infected, SM1_Adjust_Notify_Threshold } SM1_State;

TickFct_State_machine_1() {
   switch(SM1_State) { // Transitions
      case -1:
         SM1_State = SM1_Init;
         break;
         case SM1_Init: 
         if (1) {
            SM1_State = SM1_Base_State;
         }
         break;
      case SM1_Base_State: 
         if (A7) {
            SM1_State = SM1_Menu;
         }
         else if (!A7) {
            SM1_State = SM1_Base_State;
         }
         break;
      case SM1_Menu: 
         if (!A2 && !A7) {
            SM1_State = SM1_Base_State;
         }
         else if (A2&&!A7) {
            SM1_State = SM1_Init;
         }
         else if (A0) {
            SM1_State = SM1_Adjust_Notify_Threshold;
         }
         else if (A1) {
            SM1_State = SM1_Report_Infected;
         }
         else if (!A0 && !A1 && !A2 && A7) {
            SM1_State = SM1_Menu;
         }
         break;
      case SM1_Report_Infected: 
         if (!A7) {
            SM1_State = SM1_Base_State;
         }
         else if (A7) {
            SM1_State = SM1_Report_Infected;
         }
         break;
      case SM1_Adjust_Notify_Threshold: 
         if (!A7) {
            SM1_State = SM1_Base_State;
         }
         else if (A7) {
            SM1_State = SM1_Adjust_Notify_Threshold;
         }
         break;
      default:
         SM1_State = SM1_Init;
   } // Transitions

   switch(SM1_State) { // State actions
      case SM1_Init:
         for(int i = 0; i < population; i++) {
             AccumulatedRisk[8];
         }
         break;
      case SM1_Base_State:
         break;
      case SM1_Menu:
         break;
      case SM1_Report_Infected:
         break;
      case SM1_Adjust_Notify_Threshold:
         break;
      default: // ADD default behaviour below
      break;
   } // State actions

}

int main() {

   const unsigned int periodState_machine_1 = 1000; // 1000 ms default
   TimerSet(periodState_machine_1);
   TimerOn();
   
   SM1_State = -1; // Initial state
   B = 0; // Init outputs

   while(1) {
      TickFct_State_machine_1();
      while(!SM1_Clk);
      SM1_Clk = 0;
   } // while (1)
} // Main