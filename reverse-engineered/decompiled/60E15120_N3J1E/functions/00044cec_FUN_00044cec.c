/* [ADDITIONAL SOURCE REVIEW]
 * misfire_dtc_set_400 [high]: Calls dtc_set_fault_xdefault (pool 0x44d54 = 0x5fd3c, ROM-verified) with slot 0: code 4 (or 2 when ref_driveCycleDetectMAYBE_ 0x65690 detects a drive cycle) when DAT_ffffcb9d==1, else code 1 with rotor bits (cb9c&3) when cb9e==1. Pools verified: 0x44d54=0x5fd3c, 0x44d50=0xcb9d, 0x44d58=0x65690, 0x44d52=0xcb9e. DTC slot table 0x7e560 slots 0/1 = 0x0300 (P0300). Called from 0x44b46.
 */
/* ROM address: 0x00044cec; body bytes: 98; decompiled */

uint misfire_dtc_set_400(void)

{
  char cVar2;
  uint uVar1;
  undefined4 uVar3;
  byte bVar4;
  
  if (DAT_ffffcb9d == '\x01') {
    cVar2 = ref_driveCycleDetectMAYBE_(0);
    if (cVar2 == '\0') {
      uVar3 = 4;
    }
    else {
      uVar3 = 2;
    }
    uVar1 = dtc_set_fault_xdefault(0,uVar3);
  }
  else {
    uVar1 = (uint)DAT_ffffcb9e;
    if (uVar1 == 1) {
      bVar4 = (DAT_ffffcb9c & 1) != 0;
      if ((DAT_ffffcb9c & 2) != 0) {
        bVar4 = bVar4 | 2;
      }
      uVar1 = dtc_set_fault_xdefault(0,1,bVar4);
    }
  }
  return uVar1;
}


