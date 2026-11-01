/* ROM address: 0x0000cd10; body bytes: 48; decompiled */

/* Function candidate recovered from ROM pointer at 9b00 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

byte FUN_0000cd10(byte param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = can_mailbox_reg_addr((int)(char)param_1,&DAT_ffffe420);
  *(byte *)(iVar1 + (param_1 & 0xf) * 8) = param_2 & 0xf;
  return param_2 & 0xf;
}


