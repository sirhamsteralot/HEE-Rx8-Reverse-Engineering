/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_busy_status_read [high]: E2RAM status/busy read: pulse PFDR_W 0xfffff74e bit 0x400 high then low (via 0x4bbc, pools 0xc014-0xc020), wait 0x239c (sh_busy_wait_count_times_8(1)), read PBDR_W 0xfffff738, return (val & 0x800) == 0. PBDR_W at symbols.tsv 0xfffff738.
 */
/* ROM address: 0x0000bed8; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000bed8 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool e2ram_busy_status_read(void)

{
  ushort uVar1;
  undefined4 local_1c;
  undefined4 auStack_18 [2];
  
  ref_setSR_PARAM(auStack_18,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,0x400,1);
  FUN_00002064(auStack_18[0]);
  sh_busy_wait_count_times_8(1);
  uVar1 = PBDR_W;
  ref_setSR_PARAM(&local_1c,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff74e,0x400,0);
  FUN_00002064(local_1c);
  return (uVar1 & 0x800) == 0;
}


