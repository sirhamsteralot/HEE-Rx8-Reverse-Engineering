/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffd930 dtc_status_bits (uint32): Status bits ANDed with low16 of ROM mask table 0x7e934 in ref_getFaultStatus__ (0x66a00).
 */
/* ROM address: 0x00066a00; body bytes: 70; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000652f0 (70 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_getFaultStatus__(uint param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = (param_1 & 0xffff) * 4;
  bVar3 = (*(uint *)(&DAT_0007e934 + iVar2) & dtc_status_bits_ffffd930 & 0xffff) != 0;
  if ((!bVar3) &&
     (uVar1 = FUN_00066a58(), (*(uint *)(&DAT_0007e934 + iVar2) & uVar1 & 0xffff0000) != 0)) {
    bVar3 = true;
  }
  return bVar3;
}


