/* ROM address: 0x0005890c; body bytes: 40; decompiled */

uint FUN_0005890c(byte param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (uVar1 == 0) {
    DAT_ffffd264 = 1;
  }
  else {
    if (uVar1 != 1) {
      uVar1 = FUN_00058616();
      return uVar1;
    }
    DAT_ffffd264 = 2;
  }
  return uVar1;
}


