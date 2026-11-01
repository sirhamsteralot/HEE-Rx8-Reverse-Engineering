/* ROM address: 0x00009440; body bytes: 80; decompiled */

void FUN_00009440(byte param_1)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  sVar1 = *(short *)(&PTR_DAT_0000d828)[uVar2 * 6];
  *(short *)(&PTR_DAT_0000d820)[uVar2 * 6] = sVar1 + 0x7fff;
  *(short *)(&PTR_DAT_0000d824)[uVar2 * 6] = sVar1 + -1;
  FUN_0000a8a4((&PTR_DAT_0000d81c)[uVar2 * 6]);
  (&DAT_ffffa0dd)[(uint)param_1 * 8] = 1;
  (&DAT_ffffa0de)[(uint)param_1 * 8] = 0;
  return;
}


