/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_cs_port_setup [high]: E2RAM chip-select/port setup: PLIR_W 0xfffff75c &= ~0x200, PBCRH_W 0xfffff732 &= ~0x30, PBDR_W 0xfffff738 bit 0x400 = 0 (via 0x4bbc), PFDR_W 0xfffff74e bit 0x400 = 1 (CS high), PBCRH_W |= 0x10. Registers from symbols.tsv.
 */
/* ROM address: 0x0000bf3a; body bytes: 102; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000bf3a (102 bytes). Names prefixed ref_
   are inherited hypotheses. */

void e2ram_cs_port_setup(void)

{
  ushort uVar1;
  undefined4 local_18;
  undefined4 auStack_14 [2];
  
  ref_setSR_PARAM(auStack_14,0xe0);
  uVar1 = PLIR_W;
  PLIR_W = uVar1 & 0xfdff;
  uVar1 = PBCRH_W;
  PBCRH_W = uVar1 & 0xffcf;
  ref_setRegister_REG_BIT_VAL(0xfffff738,0x400,0);
  ref_setSR_PARAM(&local_18,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,0x400,1);
  FUN_00002064(local_18);
  uVar1 = PBCRH_W;
  PBCRH_W = uVar1 & 0xffcf | 0x10;
  FUN_00002064(auStack_14[0]);
  return;
}


