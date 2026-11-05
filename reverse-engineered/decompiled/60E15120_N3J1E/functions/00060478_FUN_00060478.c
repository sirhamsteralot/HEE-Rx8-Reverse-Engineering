/* ROM address: 0x00060478; body bytes: 74; decompiled */

undefined4 FUN_00060478(ushort param_1)

{
  char cVar1;
  
  cVar1 = ref_faultEnableStatus2((int)(short)param_1,0x20);
  if (cVar1 == '\0') {
    if ((&dtc_eval_state_array_ffffd458)[param_1] != '\x01') {
      return 0;
    }
  }
  else if ((&dtc_state_array_ffffd5fc)[param_1] != -0x40) {
    return 0;
  }
  return 1;
}


