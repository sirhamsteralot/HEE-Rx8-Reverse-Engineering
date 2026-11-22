/* [ADDITIONAL SOURCE REVIEW]
 * throttle_torque_request_batch [high]: Throttle torque batch from task rec[18] 0x64e8 -> 0x11534 -> 0x1150e (pool 0x116e4=0x00021b4c); mask 0x10; calls 0x21970 (gear mode flags), 0x218c4 ref_throttlePlateControl_Related (DSC torque-request limit), 0x21ae8 ref_getThrottleBasedTorque_Related (callgraph.tsv rows for caller 00021b4c).
 */
/* ROM address: 0x00021b4c; body bytes: 36; decompiled */

void throttle_torque_request_batch(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  throttle_gear_mode_flags();
  ref_throttlePlateControl_Related();
  ref_getThrottleBasedTorque_Related();
  ref_setSR(uVar1);
  return;
}


