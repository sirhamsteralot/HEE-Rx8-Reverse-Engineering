/* ROM address: 0x0000bdbc; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000bdbc (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000bdbc(void)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 local_8 [2];
  
  ref_setSR_PARAM(local_8,0xe0);
  SCI_SMR4_B = 0x80;
  bVar2 = SCI_SCR4_B;
  SCI_SCR4_B = bVar2 & 0xfc;
  SCI_SDCR4_B = 0xf8;
  cVar1 = SCI_BRR4_B;
  if (cVar1 != '\x06') {
    SCI_BRR4_B = 6;
  }
  uVar3 = FUN_00002064(local_8[0]);
  return uVar3;
}


