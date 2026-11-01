/* ROM address: 0x0000cd74; body bytes: 136; decompiled */

/* Function candidate recovered from ROM pointer at 9cc8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_0000cd74(byte param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = can_mailbox_reg_addr((int)(char)param_1,&DAT_ffffe420);
  iVar1 = iVar1 + (param_1 & 0xf) * 8;
  if ((*(byte *)(iVar1 + 4) & 8) == 0) {
    uVar2 = (uint)(*(byte *)(iVar1 + 4) >> 5);
    uVar3 = (uint)*(byte *)(iVar1 + 5) << 3;
  }
  else {
    uVar2 = (*(byte *)(iVar1 + 4) & 3) << 0x10 | (*(byte *)(iVar1 + 4) & 0xe0) << 0xd |
            (uint)*(byte *)(iVar1 + 5) << 0x15 | (uint)*(byte *)(iVar1 + 7) << 8;
    uVar3 = (uint)*(byte *)(iVar1 + 6);
  }
  return uVar2 | uVar3;
}


