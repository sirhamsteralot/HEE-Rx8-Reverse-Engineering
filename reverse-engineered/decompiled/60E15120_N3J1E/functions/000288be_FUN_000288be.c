/* ROM address: 0x000288be; body bytes: 54; decompiled */

void FUN_000288be(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_00026ce0();
  e2ram_learned_table_load();
  FUN_00027808();
  e2ram_learned_table_save();
  candidate_e2ram_learned_table_erase();
  FUN_0002698e();
  ref_setSR(uVar1);
  return;
}


