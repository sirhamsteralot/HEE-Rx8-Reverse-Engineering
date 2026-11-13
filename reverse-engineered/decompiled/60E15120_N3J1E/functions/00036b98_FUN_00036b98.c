/* ROM address: 0x00036b98; body bytes: 138; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000372b8 (138 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00036b98(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  if ((((engine_running_flag_ffffaa68 == '\x01') && (engine_stopped_latch_ffffa41c == '\x01')) && (((int)inferred_ram_c1d3_ffffc1d3_ffffc1d3 & 0x80U) != 0))
     && ((inferred_ram_c1d2_ffffc1d2_ffffc1d2 == '3' &&
         ((cVar1 = FUN_00055e3e(0), cVar1 == '\0' || (cVar1 = FUN_00055e3e(2), cVar1 == '\0')))))) {
    inferred_ram_c1d2_ffffc1d2_ffffc1d2 = 'U';
    DAT_ffffc247 = 1;
    DAT_ffffc24f = 1;
  }
  else {
    iVar3 = 0x22;
  }
  if (iVar3 != 0) {
    uVar2 = ref_udsErrorResponse(0xb1,iVar3);
  }
  return uVar2;
}


