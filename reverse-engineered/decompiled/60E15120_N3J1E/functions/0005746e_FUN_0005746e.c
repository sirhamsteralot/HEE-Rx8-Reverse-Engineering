/* ROM address: 0x0005746e; body bytes: 72; decompiled */

/* Function candidate recovered from ROM pointer at 5f4d4 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_0005746e(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = PEDR_W;
  if ((uVar1 & 0x80) != 0) {
    uVar3 = 0x40;
  }
  uVar1 = PDDR_W;
  if ((uVar1 & 0x20) != 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar2 = FUN_000579a8(uVar3,1);
  diag_append_u8((int)param_1,uVar2);
  return;
}


