/* ROM address: 0x00010d58; body bytes: 184; decompiled */

/* Function candidate recovered from ROM pointer at 4eabc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00010d58(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  float fVar3;
  
  fVar3 = 65536.0;
  for (pcVar2 = (char *)(param_1 + 0xc); pcVar2 < (char *)(param_1 + 0x2c); pcVar2 = pcVar2 + 0x10)
  {
    if (pcVar2[4] == '\0') {
      *(undefined4 *)(pcVar2 + 8) = *(undefined4 *)(pcVar2 + 0xc);
      if (pcVar2[3] == '\x01') {
        iVar1 = *(int *)(pcVar2 + 8) - param_2;
        if (0 < iVar1) {
          iVar1 = 0;
        }
        iVar1 = FUN_000107c4(iVar1);
        FUN_00008de8((float)iVar1 / fVar3,(int)*pcVar2);
      }
      else if (pcVar2[3] == '\0') {
        iVar1 = *(int *)(pcVar2 + 8) - param_2;
        if (0 < iVar1) {
          iVar1 = 0;
        }
        iVar1 = FUN_000107c4(iVar1);
        FUN_00008dae((float)iVar1 / fVar3,(int)*pcVar2);
        pcVar2[3] = '\x01';
      }
    }
  }
  *(undefined1 *)(param_1 + 1) = 1;
  *(undefined1 *)(param_1 + 2) = 0;
  return;
}


