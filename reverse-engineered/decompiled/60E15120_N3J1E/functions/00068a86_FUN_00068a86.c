/* ROM address: 0x00068a86; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00067376 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00068a86(char param_1)

{
  bool bVar1;
  int iVar2;
  int unaff_r14;
  
  bVar1 = true;
  iVar2 = 0;
  do {
    if ((&DAT_ffffddf4)[iVar2 * 2] == '\x04') {
      bVar1 = false;
      unaff_r14 = iVar2;
      break;
    }
    if (((&DAT_ffffddf4)[iVar2 * 2] == '\0') && (bVar1)) {
      bVar1 = false;
      unaff_r14 = iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 1);
  if (!bVar1) {
    FUN_00068b10(unaff_r14,(int)param_1);
  }
  return unaff_r14;
}


