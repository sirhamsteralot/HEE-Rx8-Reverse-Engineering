/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_send_command2 [high]: Send a 2-byte command frame: 0xbf3a() CS up, 0xbfa0(cmd, 2), CS down (same helper pools 0xbecc/0xbed4/0xbed0). Used with 0x4c00000 (from 0x379e4, pool 0x37bd4).
 */
/* ROM address: 0x0000be30; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000be30 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 e2ram_send_command2(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 local_c;
  undefined4 uStack_8;
  
  uStack_8 = param_1;
  e2ram_cs_port_setup();
  sci4_send_bytes(uStack_8,2);
  ref_setSR_PARAM(&local_c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,0x400,0);
  uVar1 = FUN_00002064(local_c);
  return uVar1;
}


