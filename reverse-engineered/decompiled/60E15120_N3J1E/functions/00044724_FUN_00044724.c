/* ROM address: 0x00044724; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00043f40 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint misfire_dtc_set(void)

{
  char cVar2;
  uint uVar1;
  undefined4 uVar3;
  byte bVar4;
  
  DAT_ffffbaa1 = DAT_ffffbaa0;
  if (DAT_ffffcb6d == '\x01') {
    cVar2 = ref_driveCycleDetectMAYBE_(1);
    if (cVar2 == '\0') {
      uVar3 = 4;
    }
    else {
      uVar3 = 2;
    }
    uVar1 = dtc_set_fault_xdefault(1,uVar3,0);
  }
  else {
    uVar1 = (uint)DAT_ffffcb6e;
    if (uVar1 == 1) {
      bVar4 = (DAT_ffffcb6c & 1) != 0;
      if ((DAT_ffffcb6c & 2) != 0) {
        bVar4 = bVar4 | 2;
      }
      uVar1 = dtc_set_fault_xdefault(1,1,bVar4);
    }
  }
  return uVar1;
}


