/* ROM address: 0x0000b308; body bytes: 100; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000b308 (100 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000b308(void)

{
  byte bVar1;
  undefined2 uVar2;
  undefined4 local_10 [2];
  
  if (DAT_ffffa214 == '\0') {
    uVar2 = rx8_mul_s32_shift16_saturate(DAT_ffffa210,32000);
    ref_setSR_PARAM(local_10,0xe0);
    DAT_ffff9f50 = 32000;
    bVar1 = ATUII_TSTR2_B;
    ATUII_TSTR2_B = bVar1 & 0x7f;
    ATUII_CYLR7D_W = 32000;
    ATUII_TCNT7D_W = 32000;
    ATUII_BFR7D_W = 32000;
    ATUII_DTR7D_W = 32000;
    ATUII_BFR7D_W = uVar2;
    bVar1 = ATUII_TSTR2_B;
    ATUII_TSTR2_B = bVar1 | 0x80;
    FUN_00002064(local_10[0]);
    DAT_ffffa214 = '\x01';
  }
  return;
}


