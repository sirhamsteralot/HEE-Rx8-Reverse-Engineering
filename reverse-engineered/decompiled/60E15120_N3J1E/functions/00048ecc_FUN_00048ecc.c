/* ROM address: 0x00048ecc; body bytes: 230; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00047f58 (230 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00048ecc(void)

{
  bool bVar1;
  byte bVar3;
  uint uVar2;
  byte bVar4;
  undefined4 *puVar5;
  float fVar6;
  float fVar7;
  
  DAT_ffffccd0 = DAT_ffffb4b0;
  fVar7 = DAT_ffffb4b0;
  fVar6 = rx8_absolute_difference(DAT_ffffb4bc,0.0);
  fVar7 = rx8_absolute_difference(fVar7,DAT_ffffcce0);
  bVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff80a0,0);
  uVar2 = (uint)DAT_ffffccbc;
  if (((uVar2 != 1) || (fVar6 < 80.0)) ||
     (((bVar3 != 0 || (100.0 <= fVar7)) && ((uVar2 = (uint)bVar3, uVar2 != 1 || (100.0 <= fVar7)))))
     ) {
    DAT_ffffcccc = 0;
  }
  else {
    uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff873e,0);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 0) {
      uVar2 = rx8_add_u16_saturate((int)(short)DAT_ffffcccc,1);
      DAT_ffffcccc = (ushort)uVar2;
    }
  }
  if (DAT_ffffcccc < 10) {
    uVar2 = 0;
  }
  DAT_ffffccc7 = DAT_ffffcccc >= 10;
  bVar3 = 4;
  puVar5 = (undefined4 *)0xffffcce4;
  bVar1 = true;
  bVar4 = bVar3;
  while (bVar1) {
    bVar4 = bVar4 - 1;
    uVar2 = (uint)bVar4 * 4;
    bVar3 = bVar3 - 1;
    puVar5 = puVar5 + -1;
    *puVar5 = (&DAT_ffffccd0)[bVar4];
    bVar1 = bVar3 != 0;
  }
  return uVar2;
}


