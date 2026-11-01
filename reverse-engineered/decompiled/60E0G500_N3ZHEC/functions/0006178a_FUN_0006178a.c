/* ROM address: 0x0006178a; body bytes: 28; decompiled */

uint FUN_0006178a(ushort *param_1)

{
  uint uVar1;
  
  if ((byte)(&DAT_ffff8d7c)[(uint)*param_1 * 2] == 0x10) {
    uVar1 = FUN_0006383c(0);
    return uVar1;
  }
  return (uint)(byte)(&DAT_ffff8d7c)[(uint)*param_1 * 2];
}


