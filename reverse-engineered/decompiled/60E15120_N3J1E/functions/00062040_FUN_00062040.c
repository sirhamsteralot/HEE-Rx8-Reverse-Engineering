/* ROM address: 0x00062040; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060930 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00062040(uint param_1)

{
  bool bVar1;
  int iVar2;
  
  param_1 = param_1 & 0xff;
  if ((param_1 == 1) && (iVar2 = (int)DAT_ffff8788._0_2_, bVar1 = DAT_ffff8788._0_2_ != -1, bVar1))
  {
    param_1 = rx8_pack_u16_with_complement(iVar2 + 1);
    DAT_ffff8788 = param_1;
  }
  return param_1;
}


