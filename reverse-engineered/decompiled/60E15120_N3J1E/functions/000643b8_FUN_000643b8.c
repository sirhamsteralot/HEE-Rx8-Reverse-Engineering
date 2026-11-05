/* ROM address: 0x000643b8; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00062ca8 (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000643b8(ushort *param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(param_1 + 3);
  uVar2 = (uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2];
  if ((uVar2 != 0x11) &&
     ((((bVar1 == 0 || (uVar2 = (uint)bVar1, 0x3f < uVar2)) && ((bVar1 < 0x81 || (0xbf < bVar1))))
      || ((byte)(&DAT_ffff87ba)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10] < 0x50)))) {
    return uVar2;
  }
  uVar2 = FUN_00063098(0);
  return uVar2;
}


