/* ROM address: 0x00060e62; body bytes: 56; decompiled */

uint FUN_00060e62(void)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)(&DAT_ffff87de)[(uint)DAT_ffff8928 * 0x10];
  if ((uVar1 != 0x50) && (uVar1 != 0)) {
    return uVar1;
  }
  FUN_00062d14(8);
  FUN_00063fc0();
  uVar1 = FUN_0006307a();
  return uVar1;
}


