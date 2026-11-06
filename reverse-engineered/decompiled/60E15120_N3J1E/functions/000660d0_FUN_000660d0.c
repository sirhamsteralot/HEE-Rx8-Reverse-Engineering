/* [ADDITIONAL SOURCE REVIEW]
 * obd_mode04_clear_dtc [high]: service table record 0x5eb64 (service 0x04) -> handler; ROM bytes verified; OBD Mode 04 (also ref_ClearFaults_ at 0x558ac for service 0x14)
 */
/* ROM address: 0x000660d0; body bytes: 162; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000649c0 (162 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint obd_mode04_clear_dtc(short param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 local_2c [4];
  char cStack_28;
  undefined4 local_24;
  undefined **ppuStack_20;
  
  bVar1 = param_1 != 0;
  cStack_28 = (char)param_2;
  if (!bVar1) {
    param_2 = FUN_0006619a();
    if ((param_2 & 0xff) == 0) {
      DAT_ffffd958 = 1;
      local_24 = 4;
      ppuStack_20 = &PTR_ref_LongFunc_0000ff00;
      os_schedule_task_event(2,3);
      local_2c[0] = 0x44;
      param_2 = ref_setupForUdsResponse_(4,local_2c,1);
    }
    else {
      bVar1 = false;
    }
  }
  uVar2 = (uint)bVar1;
  if (uVar2 != 0) {
    if (uVar2 == 1) {
      if (cStack_28 == '\x01') {
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      param_2 = FUN_0006672a(4,0x12,uVar3);
    }
    else {
      param_2 = uVar2;
      if (uVar2 == 2) {
        param_2 = FUN_0006672a(4,0x22,1);
      }
    }
  }
  return param_2;
}


