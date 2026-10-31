/* ROM address: 0x00066afc; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000653ec (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00066afc(uint param_1)

{
  char cVar1;
  ushort uVar2;
  short *psVar3;
  
  cVar1 = '\0';
  uVar2 = 0;
  psVar3 = (short *)(&PTR_PTR_0007f128)[param_1 & 0xffff];
  while( true ) {
    if (*psVar3 == -1) {
      return 0;
    }
    if (0x32 < uVar2) break;
    if (*psVar3 != -2) {
      cVar1 = FUN_00060478((int)*psVar3);
    }
    if (cVar1 == '\x01') {
      return 1;
    }
    psVar3 = psVar3 + 1;
    uVar2 = uVar2 + 1;
  }
  return 0;
}


