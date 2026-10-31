/* [ADDITIONAL SOURCE REVIEW]
 * knock_sensor_monitor_task [medium]: 0x49fac health persistence + 0x4a084 DTC report + 0x384de/0x3856c monitor counters; reached from task[10] 0x64f6 -> 0x11744.
 */
/* ROM address: 0x000390b8; body bytes: 42; decompiled */

void candidate_knock_sensor_monitor_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  knock_sensor_health_persistence();
  knock_sensor_dtc_report();
  FUN_000384de();
  FUN_0003856c();
  ref_setSR(uVar1);
  return;
}


