/* ROM address: 0x0000b2c0; body bytes: 72; decompiled */

uint FUN_0000b2c0(float param_1,byte param_2)

{
  uint uVar1;
  
  (&DAT_ffffa210)[param_2] = (int)(param_1 * 65536.0);
  uVar1 = (uint)(byte)(&DAT_ffffa214)[param_2];
  if ((uVar1 == 1) && (param_2 == 0)) {
    uVar1 = FUN_0000231c(DAT_ffffa210,DAT_ffff9f50);
    DAT_fffff596 = (short)uVar1;
  }
  return uVar1;
}


