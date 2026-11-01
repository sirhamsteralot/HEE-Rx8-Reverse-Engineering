/* ROM address: 0x0000a266; body bytes: 54; decompiled */

undefined4 FUN_0000a266(int param_1)

{
  undefined4 uVar1;
  
  param_1 = param_1 * 0xc;
  uVar1 = *(undefined4 *)(&DAT_ffffa170 + (uint)(byte)(&DAT_ffffa179)[param_1] * 4 + param_1);
  (&DAT_ffffa179)[param_1] = (&DAT_ffffa179)[param_1] + 1;
  if (1 < (byte)(&DAT_ffffa179)[param_1]) {
    (&DAT_ffffa179)[param_1] = 0;
  }
  return uVar1;
}


