/* ROM address: 0x00065c0c; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000644fc (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065c0c(ushort *param_1)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = param_1;
  while( true ) {
    if (param_1[iVar2] == 0xffff) {
      return 0;
    }
    if ((((&DAT_ffff8d55)[(uint)*puVar1 * 2] & 1) != 1) &&
       (((&DAT_ffff8d55)[(uint)*puVar1 * 2] & 2) != 2)) break;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  }
  return 1;
}


