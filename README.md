# tapasco_counter_versions (test version)

The original counter PE/kernel in TaPaSCo source code is currently developed in SystemC. Since Vitis HLS 2020.2 has no support for SystemC this repo contains an alternative version of TaPaSCo counter PE using only C/C++ pragmas of Vitis 2020.2. This is trial and test code. 

May be this will not be merged in the new release and finally the counter PE/kernel written in Bluespec will be used. 

Some brief information about these function-like MACROS.
  
  - ``` ap_wait()```         Takes no argument. Already defined for a single clock cycle in the library.
  - ``` ap_wait_n(X)```      Here X is the delay. For multiple clock cycles.
  - ``` ap_wait_until(X)```  Here X is the trigger

All these MACROS can be controlled by AXI Lite Interface.

These MACROS are defined in following libraries of Vitis:

   - #include "etc/autopilot_enum.h"
   - #include "etc/autopilot_ssdm_op.h"

The repo contains two source codes namely counter_test1 and counter_test2. 

- counter_test1: Delay using pragma  ``` ap_wait_n(X)```
- counter_test2: Delay using pragma ``` ap_wait()```

So far ``` ap_wait_until(X)```  has not been used as there is no need of trigger in the use case.


Observation: Writing a delayed function without adhering to Vitis HLS pragmas is not efficent. Not recommended from Co-simulation point of view. Have tried it already but all in vain.
