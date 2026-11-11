/* [ADDITIONAL SOURCE REVIEW]
 * dtc_set_fault_x0 [high]: Body is `bra 0x5fe20` with delay slot `mov #0,r6` (words a072/e600 at 0x5fd38/0x5fd3a, ROM-verified): a direct tail-call trampoline to dtc_set_fault 0x5fe20 with param_3 (r6, the x ORed into first-stored-code 0xffffd3c0 by 0x601cc) fixed to 0. 0x5fe20's only callers are the two trampolines 0x5fd38/0x5fd3c (callgraph); 0x5fd38 has 71 monitor callers. Not an indirect call, so no candidate_ prefix: the target is proven exact.
 */
/* ROM address: 0x0005fd38; body bytes: 4; decompiled */

void dtc_set_fault_x0(undefined4 param_1,undefined4 param_2)

{
  FUN_0005fe20(param_1,param_2,0);
  return;
}


