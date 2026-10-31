/* ROM address: 0x00036e1c; body bytes: 134; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003753c (134 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00036e1c(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  byte local_10;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  
  uVar2 = 0;
  iVar3 = 0;
  ref_udsServiceResponse(0xb1,&local_10,4);
  if ((DAT_ffffc27a == 0) &&
     ((cVar1 = FUN_00055e3e(0), cVar1 == '\0' || (cVar1 = FUN_00055e3e(2), cVar1 == '\0')))) {
    DAT_ffffc27a = (ushort)local_10 * 0x100 + (ushort)bStack_f;
    DAT_ffffc27c = (ushort)bStack_e * 0x100 + (ushort)bStack_d;
    DAT_ffffc251 = 1;
  }
  else {
    iVar3 = 0x22;
  }
  if (iVar3 != 0) {
    uVar2 = ref_udsErrorResponse(0xb1,iVar3);
  }
  return uVar2;
}


