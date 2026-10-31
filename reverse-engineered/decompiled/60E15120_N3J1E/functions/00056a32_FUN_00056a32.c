/* ROM address: 0x00056a32; body bytes: 38; decompiled */

/* Function candidate recovered from ROM pointer at 5f1c8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00056a32(char param_1)

{
  byte bVar2;
  uint uVar1;
  
  bVar2 = FUN_00055586();
  uVar1 = FUN_000555ac();
  diag_append_u16_be((int)param_1,(uVar1 & 0xff) + (uint)bVar2 * 0x100);
  return;
}


