/* ROM address: 0x00063862; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062152 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00063862(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)DAT_ffff8d4c._0_2_;
  iVar3 = uVar2 * 0x34;
  uVar1 = (&DAT_ffff8908)[uVar2 * 0x1a];
  (&DAT_ffff893a)[iVar3] =
       (&DAT_ffff893a)[iVar3] +
       (((char)uVar1 + (char)((ushort)uVar1 >> 8)) - ((char)((uint)param_1 >> 8) + (char)param_1));
  (&DAT_ffff8908)[uVar2 * 0x1a] = (short)param_1;
  return;
}


