/* ROM address: 0x00044cec; body bytes: 98; decompiled */

uint FUN_00044cec(void)

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


