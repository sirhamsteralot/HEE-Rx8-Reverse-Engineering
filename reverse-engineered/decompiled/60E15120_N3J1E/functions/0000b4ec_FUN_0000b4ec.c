/* ROM address: 0x0000b4ec; body bytes: 180; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000b4ec (180 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000b4ec(void)

{
  byte bVar1;
  ushort uVar2;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 auStack_24 [2];
  
  ref_setSR_PARAM(auStack_24,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,0x80,1);
  FUN_00002064(auStack_24[0]);
  DAT_ffffa229 = 0;
  SCI_SMR1_B = 0x80;
  bVar1 = SCI_SCR1_B;
  SCI_SCR1_B = bVar1 & 0xfc;
  SCI_SDCR1_B = 0xf8;
  SCI_BRR1_B = 4;
  ref_setSR_PARAM(&uStack_28,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff72c,0x100,1);
  FUN_00002064(uStack_28);
  ref_setSR_PARAM(&local_2c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff72c,0x80,1);
  FUN_00002064(local_2c);
  bVar1 = ATUII_TCR9C_B;
  ATUII_TCR9C_B = bVar1 & 0xfc | 2;
  ATUII_GR9E_B = 0;
  ATUII_ECNT9E_B = 0;
  uVar2 = ATUII_TIER9_W;
  ATUII_TIER9_W = uVar2 & 0xffef | 0x10;
  DAT_ffffa322 = 0;
  DAT_ffffa320 = 0;
  DAT_ffffa228 = 0;
  return;
}


