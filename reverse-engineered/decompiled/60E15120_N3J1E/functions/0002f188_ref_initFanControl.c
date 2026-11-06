/* [ADDITIONAL SOURCE REVIEW]
 * fan_output_gpio_init [high]: Same two PEDR_W 0xfffff754 bits (0x800 PE11 / 0x10 PE4) written directly from 0xffffbda1/0xffffbda2 without diag arbitration (pool 0x2f240-0x2f25c shared with 0x2f1dc, jsr @r13 = 0x4bbc at 0x2f1aa); reached via thunk 0x2f260 from the init fan-out 0x1102a (callgraph 0x1102a -> 0x2f260). Inherited ref_initFanControl name confirmed as init-time output writer.
 */
/* ROM address: 0x0002f188; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002f640 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

void fan_output_gpio_init(void)

{
  undefined4 local_14;
  undefined4 auStack_10 [2];
  
  ref_setSR_PARAM(auStack_10,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,0x800,fan_low_speed_cmd_ffffbda1 == '\x01');
  FUN_00002064(auStack_10[0]);
  ref_setSR_PARAM(&local_14,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,0x10,fan_high_speed_cmd_ffffbda2 == '\x01');
  FUN_00002064(local_14);
  return;
}


