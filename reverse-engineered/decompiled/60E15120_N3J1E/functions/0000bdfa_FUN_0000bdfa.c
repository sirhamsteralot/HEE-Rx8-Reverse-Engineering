/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_read_word [high]: Device read of one u16: 0xbf3a() CS/port setup, 0xbfa0(addr, 2) sends the 2 address bytes over SCI4, 0xc02c() clocks in the u16 from SCI_RDR4_B 0xfffff025, then CS down via ref_setRegister_REG_BIT_VAL 0x4bbc on PFDR_W 0xfffff74e bit 0x400 (pools 0xbecc=0x2054, 0xbed4=0x4bbc, 0xbed0=0x2064).
 */
/* ROM address: 0x0000bdfa; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000bdfa (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

int e2ram_read_word(undefined4 param_1)

{
  short sVar1;
  undefined4 local_c;
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  e2ram_cs_port_setup();
  sci4_send_bytes(uStack_8,2);
  sVar1 = sci4_read_u16();
  uStack_8._0_2_ = sVar1;
  ref_setSR_PARAM(&local_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,0x400,0);
  FUN_00002064(local_c);
  return (int)uStack_8._0_2_;
}


