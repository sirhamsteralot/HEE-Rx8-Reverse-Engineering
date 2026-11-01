/* ROM address: 0x00057c12; body bytes: 72; decompiled */

/* Function candidate recovered from ROM pointer at 5fc78 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057c12(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar1 = DAT_fffff754;
  if ((uVar1 & 0x80) != 0) {
    uVar3 = 0x40;
  }
  uVar1 = DAT_fffff746;
  if ((uVar1 & 0x20) != 0) {
    uVar3 = uVar3 | 0x80;
  }
  uVar2 = FUN_0005814c(uVar3,1);
  FUN_000581d2((int)param_1,uVar2);
  return;
}


