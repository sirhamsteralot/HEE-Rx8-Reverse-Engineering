/* ROM address: 0x00025674; body bytes: 156; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025efc (156 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00025674(void)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  char cVar4;
  undefined4 local_1c;
  undefined2 uStack_18;
  
  uStack_18 = rx8_mul_s32_shift16_saturate(0,1000);
  ref_setSR_PARAM(&local_1c,0xe0);
  DAT_ffff9f48 = uStack_18;
  DAT_ffff9f44 = 1000;
  DAT_ffff9f4e = 0;
  DAT_ffff9f4c = 0;
  DAT_ffff9f4d = 1;
  sVar2 = ATUII_TCNT5_W;
  ATUII_GR5B_W = sVar2 + 1;
  bVar3 = ATUII_TIOR5A_B;
  ATUII_TIOR5A_B = bVar3 & 0x8f | 0x10;
  ATUII_TSR3_W = 0xf7ff;
  uVar1 = ATUII_TIER3_W;
  ATUII_TIER3_W = uVar1 & 0xf7ff | 0x800;
  DAT_ffff9f4f = 0x5a;
  cVar4 = FUN_00009f12();
  if (cVar4 == '\0') {
    do {
      uVar1 = ATUII_TSR3_W;
    } while ((uVar1 & 0x800) == 0);
    ATUII_GR5B_W = sVar2 + 0x9c6;
    ATUII_TSR3_W = 0xf7ff;
  }
  FUN_00002064(local_1c);
  return;
}


