# tapasco_counter_versions (test version)

The original counter PE in TaPaSCo source code is currently developed in SystemC. Since Vitis HLS 2020.2 has no support for SystemC this repo contains an alternative version of TaPaSCo counter PE using only C/C++ pragmas of Vitis 2020.2. This is trial and test code.


The repo contains two source codes.

- counter_test1: Delay using pragma  ``` ap_wait_n(X)```
- counter_test2: Delay using pragma ``` ap_wait()```

Some brief information about these function-like MACROS
  
  - ``` ap_wait()```         Takes no argument. Already defined for a single clock cycle in the library.
  - ``` ap_wait_n(X)```      Here X is the delay. For multiple clock cycles.
  - ``` ap_wait_until(X)```  Here X is the trigger

These MACROS are defined in following libraries of Vitis:

   - #include "etc/autopilot_enum.h"
   - #include "etc/autopilot_ssdm_op.h"


Observation: Writing a delayed function without adhering to Vitis HLS pragmas is not efficent. Not recommended from Co-simulation point of view.
