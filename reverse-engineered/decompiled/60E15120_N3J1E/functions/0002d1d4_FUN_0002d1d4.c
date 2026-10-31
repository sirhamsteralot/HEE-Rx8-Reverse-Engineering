/* ROM address: 0x0002d1d4; body bytes: 172; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002d23a) */
/* WARNING: Removing unreachable block (ram,0x0002d24c) */
/* WARNING: Removing unreachable block (ram,0x0002d246) */
/* WARNING: Removing unreachable block (ram,0x0002d24e) */
/* Unique exact-byte match to related 60E0FC00 function at 0002d878 (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0002d1d4(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffbced;
  if (((uVar1 == 1) &&
      (((10.0 <= DAT_ffffbfa0 - DAT_ffffbfa4 || (10.0 <= DAT_ffffbfa4 - DAT_ffffbfa0)) &&
       (90.0 <= DAT_ffffa9bc)))) && (uVar1 = 0x271, 0x270 < DAT_ffffbcf0)) {
    uVar1 = 0;
  }
  DAT_ffffbcee = 0;
  DAT_ffffbce8 = 0;
  if (DAT_ffffa9bc < 90.0) {
    DAT_ffffbcf0 = 0;
  }
  else {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffbcf0,1);
    DAT_ffffbcf0 = (ushort)uVar1;
  }
  return uVar1;
}


