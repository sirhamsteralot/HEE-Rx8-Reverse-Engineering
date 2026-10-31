/* ROM address: 0x0004595a; body bytes: 290; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000449e6 (118 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004595a(void)

{
  char cVar2;
  uint uVar1;
  float *pfVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = DAT_ffffa9b0;
  fVar4 = rx8_absolute_difference(DAT_ffffa9ac,DAT_ffffa9b0);
  if (DAT_ffffcbf0 != '\x01') {
    DAT_ffffcbf2 = 0;
    goto LAB_00045a72;
  }
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8078,0);
  if (cVar2 == '\x01') {
    if (fVar5 < 0.6) {
      pfVar3 = (float *)&DAT_0007c77c;
      goto LAB_00045a24;
    }
    if (1.2 <= fVar5) {
      if (fVar5 < 2.0) {
        pfVar3 = (float *)&DAT_0007c784;
        goto LAB_000459d0;
      }
      if (fVar5 < 4.0) {
        pfVar3 = (float *)&DAT_0007c788;
        goto LAB_000459d0;
      }
      fVar5 = 3.5;
    }
    else {
      pfVar3 = (float *)&DAT_0007c780;
LAB_000459d0:
      fVar5 = *pfVar3;
    }
  }
  else {
    pfVar3 = (float *)&DAT_0007c790;
LAB_00045a24:
    fVar5 = *pfVar3;
  }
  if (fVar4 < fVar5) {
    if (0x18 < DAT_ffffcbf2) {
      DAT_ffffcbee = 0;
      DAT_ffffcbec = 1;
    }
    DAT_ffffcbf2 = rx8_add_u16_saturate((int)(short)DAT_ffffcbf2,1);
  }
  else {
    DAT_ffffcbf2 = 0;
    DAT_ffffcbee = rx8_add_u16_saturate((int)(short)DAT_ffffcbee,1);
    if (0x1c < DAT_ffffcbee) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff872c,1);
    }
  }
LAB_00045a72:
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff872c,0);
  if (cVar2 == '\x01') {
    uVar1 = FUN_0005fd38(0x6c,1);
    return uVar1;
  }
  if (DAT_ffffcbec == 1) {
    uVar1 = FUN_0005fd38(0x6c,2);
    return uVar1;
  }
  return (uint)DAT_ffffcbec;
}


