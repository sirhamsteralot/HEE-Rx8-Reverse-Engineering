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


