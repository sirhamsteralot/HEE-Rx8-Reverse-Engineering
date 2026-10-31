/* ROM address: 0x000634b8; body bytes: 94; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061da8 (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000634b8(ushort param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_ffff8900._0_2_;
  iVar2 = uVar1 * 0x10;
  (&DAT_ffff87b0)[uVar1 * 8] = 0xffff;
  (&DAT_ffff87b2)[uVar1 * 8] = 0xffff;
  (&DAT_ffff87b4)[uVar1 * 8] = 0xffff;
  (&DAT_ffff87b6)[iVar2] = 0;
  (&DAT_ffff87b7)[iVar2] = 0;
  (&DAT_ffff87b8)[iVar2] = 3;
  (&DAT_ffff87b9)[iVar2] = 0x28;
  (&DAT_ffff87ba)[iVar2] = 0x50;
  (&DAT_ffff87bb)[iVar2] = 0;
  (&DAT_ffff87bc)[iVar2] = 0;
  (&DAT_ffff87bd)[iVar2] = 8;
  (&DAT_ffff87be)[iVar2] = 0x28;
  FUN_00062dae((int)(short)param_1);
  FUN_00062ebc((int)(char)(&DAT_0007e442)[param_1]);
  FUN_00062f2e((int)(char)(&DAT_0007e4ce)[param_1]);
  return;
}


