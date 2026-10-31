/* ROM address: 0x00039d78; body bytes: 30; decompiled */

/* Function candidate recovered from ROM pointer at 11ed8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00039d78(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0004c2e8();
  FUN_0004c3a0();
  ref_setSR(uVar1);
  return;
}


