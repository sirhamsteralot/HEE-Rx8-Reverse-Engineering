/* ROM address: 0x00067a00; body bytes: 144; decompiled */

/* Function candidate recovered from ROM pointer at 5f318 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00067a00(undefined4 param_1,char param_2)

{
  char cVar1;
  undefined4 unaff_r12;
  int iVar2;
  undefined1 local_1c [4];
  char cStack_18;
  
  iVar2 = 0;
  local_1c[0] = 0x46;
  cStack_18 = param_2;
  cVar1 = FUN_00067ab4(param_1);
  if (cVar1 == '\0') {
    FUN_00068928(6,&DAT_ffffd98e,param_1);
    unaff_r12 = FUN_00066ebc((int)DAT_ffffd98e);
    cVar1 = FUN_00067aca(unaff_r12,&DAT_ffffd98e,param_1);
    if (cVar1 != '\0') {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = 1;
  }
  if (iVar2 == 0) {
    FUN_000688c8(6,local_1c,1);
    DAT_ffffd98c = 1;
    cVar1 = FUN_000675d4(unaff_r12,&DAT_ffffd98e,param_1);
    if (cVar1 != '\0') {
      iVar2 = 2;
    }
  }
  FUN_00067af0(iVar2,(int)cStack_18);
  return;
}


