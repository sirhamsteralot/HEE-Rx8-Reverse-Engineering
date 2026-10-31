/* ROM address: 0x00062570; body bytes: 248; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00060e60 (248 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00062570(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  short local_24 [2];
  char cStack_20;
  
  uVar2 = 1;
  local_24[0] = -1;
  cStack_20 = param_1;
  if (DAT_ffff87a8._0_1_ == '\x02') {
    iVar3 = (int)DAT_ffff879c;
    DAT_ffff87a8 = rx8_pack_u8_with_complement(1);
    cVar1 = FUN_00063680(iVar3);
    if (cVar1 == '\0') {
      sh_copy_bytes_forward_r0_r1_r2();
    }
    else if (cVar1 == '\x01') {
      iVar4 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
      (&DAT_ffff893a)[iVar4] = (&DAT_ffff893a)[iVar4] + (&DAT_ffff890f)[iVar4];
      (&DAT_ffff890f)[iVar4] = 0;
    }
    else {
      cVar1 = FUN_00063706(iVar3,(int)cStack_20,local_24);
      if (cVar1 != '\x02') {
        uVar2 = 0;
        goto LAB_0006264a;
      }
      iVar4 = (uint)DAT_ffff8d4c._0_2_ * 0x34;
      (&DAT_ffff893a)[iVar4] = (&DAT_ffff893a)[iVar4] + (&DAT_ffff890f)[iVar4];
      (&DAT_ffff890f)[iVar4] = 0;
    }
    FUN_00063862(iVar3);
  }
  else if (DAT_ffff87a8._0_1_ == '\x01') {
    uVar2 = 0;
  }
  else {
    DAT_ffff87a8 = rx8_pack_u8_with_complement(1);
  }
LAB_0006264a:
  DAT_ffff8794 = rx8_pack_u16_with_complement((int)local_24[0]);
  return uVar2;
}


