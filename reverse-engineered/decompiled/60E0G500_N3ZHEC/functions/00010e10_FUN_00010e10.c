/* ROM address: 0x00010e10; body bytes: 116; decompiled */

/* Function candidate recovered from ROM pointer at 4eac0 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

undefined4 FUN_00010e10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = (char *)(param_1 + 0xc);
  while( true ) {
    if ((char *)(param_1 + 0x2c) <= pcVar3) {
      return 1;
    }
    if (param_2 <= *(int *)(pcVar3 + 0xc)) break;
    iVar1 = FUN_00010f80((int)*pcVar3);
    iVar2 = FUN_00010f72((int)*pcVar3);
    iVar1 = FUN_00002158(iVar2 + iVar1,DAT_ffff9f88);
    if (param_2 < iVar1 * 0xb4 + *(int *)(pcVar3 + 0xc)) {
      return 0;
    }
    pcVar3 = pcVar3 + 0x10;
  }
  return 0;
}


