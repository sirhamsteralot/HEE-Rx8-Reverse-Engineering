/* ROM address: 0x0000fcec; body bytes: 18; decompiled */

/* Function candidate recovered from ROM pointer at 4ea64 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_0000fcec(int param_1,int param_2)

{
  byte bVar3;
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar4;
  byte *pbVar5;
  
  if ((*(char *)(param_1 + 7) == '\0') && (*(char *)(param_1 + 2) == '\x01')) {
    for (pbVar5 = (byte *)(param_1 + 0x10); pbVar5 < (byte *)(param_1 + 0x58);
        pbVar5 = pbVar5 + 0x18) {
      if (pbVar5[1] == 1) {
        if ((&DAT_ffffa017)[(uint)*pbVar5 * 0x18] == '\0') {
LAB_0000fd5a:
          *(undefined1 *)(param_1 + 7) = 1;
          break;
        }
      }
      else if (((pbVar5[1] == 0) && (pbVar5[0x14] == 0)) &&
              (iVar1 = FUN_0000feb4(pbVar5), param_2 < iVar1)) goto LAB_0000fd5a;
    }
  }
  if (*(char *)(param_1 + 7) == '\0') {
    for (pbVar5 = (byte *)(param_1 + 0x10); pbVar5 < (byte *)(param_1 + 0x58);
        pbVar5 = pbVar5 + 0x18) {
      if (pbVar5[1] == 1) {
        if (pbVar5[0x14] == 0) {
          *(undefined4 *)(pbVar5 + 4) = *(undefined4 *)(pbVar5 + 8);
          FUN_000084c6((int)(char)*pbVar5,*(undefined4 *)(pbVar5 + 8));
        }
        else {
          if ((&DAT_ffffa017)[(uint)*pbVar5 * 0x18] == '\0') {
            FUN_000084c6((int)(char)*pbVar5,0);
            bVar3 = 2;
          }
          else {
            FUN_000085e4((int)(char)*pbVar5);
            bVar3 = 0;
          }
          pbVar5[1] = bVar3;
        }
      }
      else if ((pbVar5[1] == 0) && (pbVar5[0x14] == 0)) {
        if ((*(char *)(param_1 + 2) == '\0') || (iVar1 = FUN_0000feb4(pbVar5), iVar1 <= param_2)) {
          *(undefined4 *)(pbVar5 + 4) = *(undefined4 *)(pbVar5 + 8);
          iVar1 = *(int *)(pbVar5 + 0xc) - param_2;
          if (0 < iVar1) {
            iVar1 = 0;
          }
          uVar2 = FUN_0000fa0e(iVar1);
          FUN_000083ca((int)(char)*pbVar5,uVar2,*(undefined4 *)(pbVar5 + 4));
          bVar3 = 1;
        }
        else {
          bVar3 = 2;
        }
        pbVar5[1] = bVar3;
      }
    }
    FUN_0000fa06();
    uVar4 = 1;
  }
  else {
    uVar4 = 2;
  }
  *(undefined1 *)(param_1 + 2) = uVar4;
  *(undefined1 *)(param_1 + 6) = 0;
  return;
}


