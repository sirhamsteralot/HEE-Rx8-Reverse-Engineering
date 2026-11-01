/* ROM address: 0x0005a8d4; body bytes: 50; decompiled */

uint FUN_0005a8d4(void)

{
  uint uVar1;
  
  uVar1 = FUN_00061bf4(0x80);
  if (((uVar1 & 0xffff) == 0) || (uVar1 = (uint)DAT_ffffd201, uVar1 == 1)) {
    DAT_ffffd2c2 = 0;
  }
  else {
    DAT_ffffd2c2 = 1;
  }
  return uVar1;
}


