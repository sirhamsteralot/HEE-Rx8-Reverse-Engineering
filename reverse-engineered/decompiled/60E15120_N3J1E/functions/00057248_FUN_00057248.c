/* ROM address: 0x00057248; body bytes: 116; decompiled */

/* Function candidate recovered from ROM pointer at 5f468 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057248(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = PEDR_W;
  uVar2 = PEDR_W;
  if ((uVar1 & 0x800) != 0) {
    uVar4 = 4;
  }
  if ((uVar2 & 0x10) != 0) {
    uVar4 = uVar4 | 8;
  }
  if (DAT_ffffcab4 == '\x01') {
    uVar4 = uVar4 | 0x10;
  }
  if ((DAT_ffffd1a2 == '\x01') || (DAT_ffffd1a1 == '\x01')) {
    uVar4 = uVar4 | 0x20;
  }
  uVar3 = FUN_000579a8(uVar4,1);
  diag_append_u8((int)param_1,uVar3);
  return;
}


