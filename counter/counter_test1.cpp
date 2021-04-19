/**                                                                                
 *  @file       counter_test1.cpp (test version)                                                      
 *  @brief      HLS implementation of a simple 32bit counter:
 *              Waits the number of clock cycles specified in first arg before
 *              raising the interrupt.              
 **/


#include "counter.h"

uint32_t counter_test1(const uint32_t clock_cycles) {

   #ifdef __SYNTHESIS__

   if (clock_cycles > 15) {

   #pragma HLS PROTOCOL fixed
   ap_wait_n (clock_cycles - 15);
   
   }

  #else
  usleep(clock_cycles);
  #endif

  return clock_cycles;
}







