/* ROM address: 0x00037f60; body bytes: 134; decompiled */

/* Function candidate recovered from ROM pointer at 5f878 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_00037f60(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  byte local_10 [8];
  
  uVar2 = 0;
  iVar3 = 0;
  FUN_00068928(0xb1,local_10,1);
  if ((DAT_ffffc242 == -0x56) &&
     ((cVar1 = FUN_000565e2(0), cVar1 == '\0' || (cVar1 = FUN_000565e2(2), cVar1 == '\0')))) {
    if ((local_10[0] < 8) || (0x3f < local_10[0])) {
      iVar3 = 0x31;
    }
    else {
      DAT_ffffc244 = local_10[0];
      DAT_ffffc2c3 = 1;
    }
  }
  else {
    iVar3 = 0x22;
  }
  if (iVar3 != 0) {
    uVar2 = FUN_00055112(0xb1,iVar3);
  }
  return uVar2;
}


