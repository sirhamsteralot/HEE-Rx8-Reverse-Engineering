/* ROM address: 0x000579ec; body bytes: 116; decompiled */

/* Function candidate recovered from ROM pointer at 5fc0c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_000579ec(char param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar1 = DAT_fffff754;
  uVar2 = DAT_fffff754;
  if ((uVar1 & 0x800) != 0) {
    uVar4 = 4;
  }
  if ((uVar2 & 0x10) != 0) {
    uVar4 = uVar4 | 8;
  }
  if (DAT_ffffcb24 == '\x01') {
    uVar4 = uVar4 | 0x10;
  }
  if ((DAT_ffffd1de == '\x01') || (DAT_ffffd1dd == '\x01')) {
    uVar4 = uVar4 | 0x20;
  }
  uVar3 = FUN_0005814c(uVar4,1);
  FUN_000581d2((int)param_1,uVar3);
  return;
}


