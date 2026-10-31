/* ROM address: 0x00001ad6; body bytes: 230; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00001ad6(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  DAT_ffffdfc6 = 0x7f;
  DAT_ffffdfca = 0x34;
  DAT_ffffdfc8 = 2;
  if (DAT_ffffdfb0 == '\0') {
    DAT_ffffdfcb = 0x22;
  }
  else if (DAT_ffffdfb1 == '\0') {
    DAT_ffffdfcb = 0x33;
  }
  else if (*(short *)(param_1 + 2) == 8) {
    if (DAT_ffffdfb3 == '\0') {
      DAT_ffffdfcb = 0x10;
    }
    else if (*(char *)(param_1 + 8) == '\0') {
      _DAT_ffffdfb8 = FUN_00001e4c(param_1 + 4);
      _DAT_ffffdfb8 = (int)&DAT_ffff6000 + _DAT_ffffdfb8;
      iVar1 = FUN_00001e72(param_1 + 9);
      DAT_ffffdfbc = iVar1 - 0x7e000;
      DAT_ffffdfc0 = _DAT_ffffdfb8;
      if ((0 < (int)DAT_ffffdfbc) && ((uint)(_DAT_ffffdfb8 + iVar1 + -0x7e001) < param_1)) {
        if ((int)DAT_ffffdfbc < 0) {
          uVar2 = ~(~DAT_ffffdfbc + 1 & 0x3ff) + 1;
        }
        else {
          uVar2 = DAT_ffffdfbc & 0x3ff;
        }
        if (uVar2 == 0) {
          DAT_ffffdfb3 = '\0';
          DAT_ffffdfb4._0_1_ = 1;
          DAT_ffffdfc6 = 0x74;
          DAT_ffffdfca = 4;
          DAT_ffffdfcb = 1;
          DAT_ffffdfc8 = 2;
          DAT_ffffdfc4 = 0;
          DAT_ffffdfc5 = 1;
          goto LAB_00001bc4;
        }
      }
      DAT_ffffdfcb = 0x31;
    }
    else {
      DAT_ffffdfcb = 0x31;
    }
  }
  else {
    DAT_ffffdfcb = 0x12;
  }
LAB_00001bc4:
  FUN_000011fa(&DAT_ffffdfc6);
  return;
}


