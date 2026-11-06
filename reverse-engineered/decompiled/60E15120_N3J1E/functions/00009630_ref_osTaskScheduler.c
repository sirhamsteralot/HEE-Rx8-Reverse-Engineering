/* [ADDITIONAL SOURCE REVIEW]
 * os_schedule_task_event [high]: The scheduler API: looks up group descriptor (ptr table 0xd87c[group] + idx*8 = {i16 target, u16 nargs, u32 handler}); target -1 -> call handler inline in caller context, else 0x5f1c posts {handler,args} to queue slot 'target' and wakes the consumer task. Upgrades inherited ref_osTaskScheduler. Dynamic: 0x9630(1,9,..) posted to slot 2 and 0x9630(1,12,..) ran 0x11d88 inline from the CAN RX ISR. Wrappers at 0xa0de-0xa22c.
 */
/* ROM address: 0x00009630; body bytes: 110; decompiled_with_warnings */

/* WARNING: Type propagation algorithm not settling */
/* Unique exact-byte match to related 60E0FC00 function at 00009630 (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 os_schedule_task_event(uint param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  short *psVar3;
  undefined4 local_24 [6];
  
  psVar3 = (short *)((&tbl_os_schedule_group_ptrs_0000d87c)[param_1 & 0xff] + (param_2 & 0xffff) * 8);
  local_24[0] = *(undefined4 *)(psVar3 + 2);
  for (iVar1 = 1; iVar1 <= (int)(uint)(ushort)psVar3[1]; iVar1 = iVar1 + 1) {
    uVar2 = *param_3;
    param_3 = param_3 + 1;
    local_24[iVar1] = uVar2;
  }
  uVar2 = 0;
  if (*psVar3 == -1) {
    (**(code **)(psVar3 + 2))(local_24 + 1);
  }
  else {
    iVar1 = os_post_message((int)*psVar3,local_24);
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}


