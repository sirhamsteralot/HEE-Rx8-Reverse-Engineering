/* ROM address: 0x00057a74; body bytes: 62; decompiled */

/* Function candidate recovered from ROM pointer at 5fc18 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057a74(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  byte bVar3;
  
  uVar1 = DAT_fffff76c;
  bVar3 = (uVar1 & 0x80) != 0;
  if (DAT_ffffbfd4 == '\x01') {
    bVar3 = bVar3 | 0x10;
  }
  uVar2 = FUN_0005814c(bVar3,1);
  FUN_000581d2((int)param_1,uVar2);
  return;
}


