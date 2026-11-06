/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_send_command4_b [medium]: Send a 4-byte frame: same shape as 0xbe5e (0xbf3a + 0xbfa0(cmd,4) + CS down).
 */
/* ROM address: 0x0000be8c; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000be8c (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 candidate_e2ram_send_command4_b(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_c;
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  e2ram_cs_port_setup();
  sci4_send_bytes(uStack_8,4);
  ref_setSR_PARAM(&local_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,0x400,0);
  uVar1 = FUN_00002064(local_c);
  return uVar1;
}


