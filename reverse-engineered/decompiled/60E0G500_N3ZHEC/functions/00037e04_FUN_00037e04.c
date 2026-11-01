/* ROM address: 0x00037e04; body bytes: 134; decompiled */

/* Function candidate recovered from ROM pointer at 5f86c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_00037e04(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  byte local_10;
  byte bStack_f;
  byte bStack_e;
  byte bStack_d;
  
  uVar2 = 0;
  iVar3 = 0;
  FUN_00068928(0xb1,&local_10,4);
  if ((DAT_ffffc2ea == 0) &&
     ((cVar1 = FUN_000565e2(0), cVar1 == '\0' || (cVar1 = FUN_000565e2(2), cVar1 == '\0')))) {
    DAT_ffffc2ea = (ushort)local_10 * 0x100 + (ushort)bStack_f;
    DAT_ffffc2ec = (ushort)bStack_e * 0x100 + (ushort)bStack_d;
    DAT_ffffc2c1 = 1;
  }
  else {
    iVar3 = 0x22;
  }
  if (iVar3 != 0) {
    uVar2 = FUN_00055112(0xb1,iVar3);
  }
  return uVar2;
}


