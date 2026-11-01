/* ROM address: 0x00063c5c; body bytes: 94; decompiled */

void FUN_00063c5c(ushort param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_ffff8928;
  iVar2 = uVar1 * 0x10;
  (&DAT_ffff87d8)[uVar1 * 8] = 0xffff;
  (&DAT_ffff87da)[uVar1 * 8] = 0xffff;
  (&DAT_ffff87dc)[uVar1 * 8] = 0xffff;
  (&DAT_ffff87de)[iVar2] = 0;
  (&DAT_ffff87df)[iVar2] = 0;
  (&DAT_ffff87e0)[iVar2] = 3;
  (&DAT_ffff87e1)[iVar2] = 0x28;
  (&DAT_ffff87e2)[iVar2] = 0x50;
  (&DAT_ffff87e3)[iVar2] = 0;
  (&DAT_ffff87e4)[iVar2] = 0;
  (&DAT_ffff87e5)[iVar2] = 8;
  (&DAT_ffff87e6)[iVar2] = 0x28;
  FUN_00063552((int)(short)param_1);
  FUN_00063660((int)(char)(&DAT_0007dfea)[param_1]);
  FUN_000636d2((int)(char)(&DAT_0007e076)[param_1]);
  return;
}


