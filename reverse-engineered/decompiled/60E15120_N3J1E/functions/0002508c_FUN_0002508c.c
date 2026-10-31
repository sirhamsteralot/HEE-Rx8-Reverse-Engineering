/* ROM address: 0x0002508c; body bytes: 148; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025914 (148 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0002508c(void)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  char cVar4;
  undefined4 local_18;
  undefined2 uStack_14;
  
  uStack_14 = rx8_mul_s32_shift16_saturate(0,ref_mainInit__);
  ref_setSR_PARAM(&local_18,0xe0);
  DAT_ffff9f3c = uStack_14;
  DAT_ffff9f38 = 25000;
  DAT_ffff9f42 = 0;
  DAT_ffff9f40 = 0;
  DAT_ffff9f41 = 1;
  sVar2 = ATUII_TCNT4_W;
  ATUII_GR4B_W = sVar2 + 1;
  bVar3 = ATUII_TIOR4A_B;
  ATUII_TIOR4A_B = bVar3 & 0x8f | 0x20;
  ATUII_TSR3_W = 0xffbf;
  uVar1 = ATUII_TIER3_W;
  ATUII_TIER3_W = uVar1 & 0xffbf | 0x40;
  DAT_ffff9f43 = 0x5a;
  cVar4 = FUN_00009f12();
  if (cVar4 == '\0') {
    do {
      uVar1 = ATUII_TSR3_W;
    } while ((uVar1 & 0x40) == 0);
    ATUII_GR4B_W = sVar2 + 0x9c6;
    ATUII_TSR3_W = 0xffbf;
  }
  FUN_00002064(local_18);
  return;
}


