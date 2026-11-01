/* ROM address: 0x00037958; body bytes: 164; decompiled */

/* Function candidate recovered from ROM pointer at 5f83c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_00037958(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char local_18 [4];
  undefined1 local_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  iVar3 = 0;
  FUN_00068928(0xb1,local_18,1);
  if (((DAT_ffffaae0 == '\x01') && (DAT_ffffa41c == '\x01')) &&
     ((cVar1 = FUN_000565e2(0), cVar1 == '\0' || (cVar1 = FUN_000565e2(2), cVar1 == '\0')))) {
    if (local_18[0] == '\x10') {
      DAT_ffffc2a8 = 1;
    }
    else {
      iVar3 = 0x31;
    }
  }
  else {
    iVar3 = 0x22;
  }
  if (iVar3 == 0) {
    uVar2 = 3;
    local_14 = 0xf1;
    uStack_13 = 0;
    uStack_12 = 0x50;
    FUN_000688c8(0xb1,&local_14,3);
  }
  else {
    uVar2 = FUN_00055112(0xb1,iVar3);
  }
  return uVar2;
}


