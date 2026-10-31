/* ROM address: 0x00068184; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066a74 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_udsServiceResponse(char param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if ((&DAT_ffffddf3)[iVar2 * 2] == param_1) {
      puVar1 = (undefined1 *)FUN_00067e78(iVar2);
      return puVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  return &DAT_ffffddf3;
}


