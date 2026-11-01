/* ROM address: 0x00057b94; body bytes: 46; decompiled */

/* Function candidate recovered from ROM pointer at 5fc54 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00057b94(char param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = DAT_fffff754;
  if ((uVar1 & 2) != 0) {
    uVar2 = 0x80;
  }
  uVar2 = FUN_0005814c(uVar2,1);
  FUN_000581d2((int)param_1,uVar2);
  return;
}


