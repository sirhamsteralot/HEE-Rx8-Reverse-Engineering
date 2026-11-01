/* ROM address: 0x00067424; body bytes: 52; decompiled */

/* Function candidate recovered from ROM pointer at 59928 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00067424(char param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  if (param_1 == '\0') {
    puVar2 = &DAT_ffffd971;
    iVar3 = 0;
    if ((param_3 & 0xffff) != 0) {
      do {
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        iVar3 = iVar3 + 1;
        *puVar2 = uVar1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < (int)(param_3 & 0xffff));
    }
    param_2 = &DAT_ffffd970;
    param_3 = param_3 + 1;
  }
  FUN_00067904(param_1,param_2,param_3);
  return;
}


