/* ROM address: 0x00062420; body bytes: 198; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060d10 (198 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062420(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  short local_18 [2];
  char cStack_14;
  
  local_18[0] = -1;
  uVar2 = 1;
  cStack_14 = param_1;
  if (DAT_ffff87a6._0_1_ == '\x02') {
    iVar3 = (int)DAT_ffff879c;
    DAT_ffff87a6 = rx8_pack_u8_with_complement(1);
    cVar1 = FUN_00062d2c(iVar3);
    if (cVar1 == '\0') {
      sh_copy_bytes_forward_r0_r1_r2(&DAT_ffff87b0);
      FUN_00062dae(iVar3);
    }
    else if (cVar1 == '\x01') {
      FUN_000634b8(iVar3);
    }
    else {
      cVar1 = FUN_00063396(iVar3,(int)cStack_14,local_18);
      if (cVar1 == '\x02') {
        FUN_000634b8(iVar3);
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else if (DAT_ffff87a6._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87a6 = rx8_pack_u8_with_complement(1);
  }
  DAT_ffff8790 = rx8_pack_u16_with_complement((int)local_18[0]);
  return uVar2;
}


