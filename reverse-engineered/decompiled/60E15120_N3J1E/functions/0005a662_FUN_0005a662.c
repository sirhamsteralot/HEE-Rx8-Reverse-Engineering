/* ROM address: 0x0005a662; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00058e1a (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005a662(void)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    ref_updateMemoryAtAddress_32bit_ADDR_VAL(&DAT_ffff9110 + iVar2 * 8,0);
    uVar1 = FUN_0005aa38(iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return uVar1;
}


