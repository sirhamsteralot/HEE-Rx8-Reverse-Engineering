/* ROM address: 0x000444ea; body bytes: 46; decompiled */

uint FUN_000444ea(void)

{
  uint uVar1;
  undefined4 extraout_fr0;
  
  uVar1 = (uint)DAT_ffffcab4;
  if (uVar1 == 1) {
    if (DAT_ffffca20 <= 0.0) {
      DAT_ffffca1c = 0;
    }
    else {
      uVar1 = FUN_000046cc();
      DAT_ffffca1c = extraout_fr0;
    }
  }
  return uVar1;
}


