/**                                                                                
 *  @file       counter_test2.cpp (test version)                                                      
 *  @brief      HLS implementation of a simple 32bit counter:
 *              Waits the number of clock cycles specified in first arg before
 *              raising the interrupt.              
 **/


void defined_delay()  {
	
	#pragma HLS inline
        #pragma HLS PROTOCOL fixed
	ap_wait();
}


uint32_t counter_test2 (const uint32_t clock_cycles) {

        #ifdef __SYNTHESIS__
	if (clock_cycles > 15) {

	for (int i=0; i < clock_cycles - 15; i++) {
	#pragma HLS unroll
	defined_delay();
	   }
	}

 #else
 usleep(clock_cycles);
 #endif

 return clock_cycles;
	
}







