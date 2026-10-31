/* ROM address: 0x0005aa38; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000591f0 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_0005aa38(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = ref_readValue_32bit_ADDRESS_VAL(&DAT_ffff9110 + param_1 * 8,0);
  *(short *)(&DAT_ffffd2b8 + param_1 * 4) = (short)((uint)uVar1 >> 0x10);
  iVar2 = (param_1 * 2 + 1) * 2;
  *(short *)(&DAT_ffffd2b8 + iVar2) = (short)uVar1;
  return iVar2;
}


