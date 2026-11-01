/* ROM address: 0x000371b6; body bytes: 146; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000378d6 (146 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000371b6(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char local_10 [8];
  
  uVar2 = 0;
  iVar3 = 0;
  ref_udsServiceResponse(0xb1,local_10,1);
  if ((inferred_ram_c1d2_ffffc1d2_ffffc1d2 == -0x56) &&
     ((cVar1 = FUN_00055e3e(0), cVar1 == '\0' || (cVar1 = FUN_00055e3e(2), cVar1 == '\0')))) {
    if (local_10[0] == ' ') {
      FUN_000360a8();
      inferred_ram_c274_ffffc274_ffffc274 = 0xff;
      DAT_ffffc248 = 1;
      DAT_ffffc259 = 1;
      inferred_ram_c1d3_ffffc1d3_ffffc1d3 = inferred_ram_c1d3_ffffc1d3_ffffc1d3 & 0xbf;
      DAT_ffffc255 = 1;
    }
    else {
      iVar3 = 0x31;
    }
  }
  else {
    iVar3 = 0x22;
  }
  if (iVar3 != 0) {
    uVar2 = ref_udsErrorResponse(0xb1,iVar3);
  }
  return uVar2;
}


