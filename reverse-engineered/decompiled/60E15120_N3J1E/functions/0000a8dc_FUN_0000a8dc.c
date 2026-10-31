/* ROM address: 0x0000a8dc; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a8dc (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_0000a8dc(void)

{
  undefined4 local_14;
  undefined4 auStack_10 [2];
  
  DAT_ffffa1be = 0xffff;
  DAT_ffffa1c8 = 0;
  DAT_ffffa1c9 = 0;
  apv_drive_status_ffffa1bc = 3;
  ref_setSR_PARAM(auStack_10,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff75e,0x20,1);
  FUN_00002064(auStack_10[0]);
  ref_setSR_PARAM(&local_14,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff75e,0x100,0);
  FUN_00002064(local_14);
  return;
}


