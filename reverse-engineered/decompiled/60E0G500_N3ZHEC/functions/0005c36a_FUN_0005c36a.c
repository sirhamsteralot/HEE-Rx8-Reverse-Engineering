/* ROM address: 0x0005c36a; body bytes: 40; decompiled */

uint FUN_0005c36a(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (uVar1 == 0) {
    DAT_ffffd348 = 0;
    uVar1 = FUN_0000daf0();
    return uVar1;
  }
  if (uVar1 != 1) {
    return uVar1;
  }
  DAT_ffffd348 = 1;
  uVar1 = FUN_0000dae8();
  return uVar1;
}


