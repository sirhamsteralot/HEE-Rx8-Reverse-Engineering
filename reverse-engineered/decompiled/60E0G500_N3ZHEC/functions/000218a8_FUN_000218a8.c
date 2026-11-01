/* ROM address: 0x000218a8; body bytes: 100; decompiled */

uint FUN_000218a8(void)

{
  uint uVar1;
  uint uVar2;
  
  if ((DAT_ffffadc8 < 0.0) || ((DAT_ffffb2f5 == 0 && (0xf9 < DAT_ffffb2f6)))) {
    DAT_ffffb2e0 = '\0';
  }
  uVar2 = (uint)DAT_ffffb2f5;
  uVar1 = uVar2;
  if (uVar2 == 1) {
    uVar1 = FUN_00002478((int)DAT_ffffb2e0,1);
    DAT_ffffb2e0 = (char)uVar1;
  }
  if (uVar2 == 0) {
    uVar1 = FUN_00002460((int)(short)DAT_ffffb2f6,1);
    DAT_ffffb2f6 = (ushort)uVar1;
  }
  else {
    DAT_ffffb2f6 = 0;
  }
  return uVar1;
}


