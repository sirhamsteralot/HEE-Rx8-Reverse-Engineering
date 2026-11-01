/* ROM address: 0x00037b80; body bytes: 138; decompiled */

/* Function candidate recovered from ROM pointer at 5f854 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_00037b80(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  if ((((DAT_ffffaae0 == '\x01') && (DAT_ffffa41c == '\x01')) && (((int)DAT_ffffc243 & 0x80U) != 0))
     && ((DAT_ffffc242 == '3' &&
         ((cVar1 = FUN_000565e2(0), cVar1 == '\0' || (cVar1 = FUN_000565e2(2), cVar1 == '\0')))))) {
    DAT_ffffc242 = 'U';
    DAT_ffffc2b7 = 1;
    DAT_ffffc2bf = 1;
  }
  else {
    iVar3 = 0x22;
  }
  if (iVar3 != 0) {
    uVar2 = FUN_00055112(0xb1,iVar3);
  }
  return uVar2;
}


