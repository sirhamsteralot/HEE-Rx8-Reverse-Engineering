/* ROM address: 0x00008268; body bytes: 80; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00008268 (80 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00008268(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  bVar1 = ATUII_TIOR1A_B;
  ATUII_TIOR1A_B = bVar1 & 0xf8 | 1;
  bVar1 = ATUII_TIOR1A_B;
  ATUII_TIOR1A_B = bVar1 & 0x8f | 0x10;
  bVar1 = ATUII_TIOR1B_B;
  ATUII_TIOR1B_B = bVar1 & 0xf8 | 1;
  bVar1 = ATUII_TIOR1B_B;
  ATUII_TIOR1B_B = bVar1 & 0x8f | 0x10;
  bVar1 = ATUII_TIOR1C_B;
  ATUII_TIOR1C_B = bVar1 & 0xf8 | 1;
  bVar1 = ATUII_TIOR1C_B;
  ATUII_TIOR1C_B = bVar1 & 0x8f | 0x10;
  uVar2 = FUN_00002064(local_8[0]);
  return uVar2;
}


