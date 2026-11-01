/* ROM address: 0x0000fcfe; body bytes: 336; decompiled */

/* Function candidate recovered from ROM pointer at 9880 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_0000fcfe(void)

{
  byte bVar3;
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar4;
  int unaff_r9;
  int unaff_r13;
  byte *pbVar5;
  
  if ((*(char *)(unaff_r13 + 7) == '\0') && (*(char *)(unaff_r13 + 2) == '\x01')) {
    for (pbVar5 = (byte *)(unaff_r13 + 0x10); pbVar5 < (byte *)(unaff_r13 + 0x58);
        pbVar5 = pbVar5 + 0x18) {
      if (pbVar5[1] == 1) {
        if ((&DAT_ffffa017)[(uint)*pbVar5 * 0x18] == '\0') {
LAB_0000fd5a:
          *(undefined1 *)(unaff_r13 + 7) = 1;
          break;
        }
      }
      else if (((pbVar5[1] == 0) && (pbVar5[0x14] == 0)) &&
              (iVar1 = FUN_0000feb4(pbVar5), unaff_r9 < iVar1)) goto LAB_0000fd5a;
    }
  }
  if (*(char *)(unaff_r13 + 7) == '\0') {
    for (pbVar5 = (byte *)(unaff_r13 + 0x10); pbVar5 < (byte *)(unaff_r13 + 0x58);
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
            injector_channel_disable((int)(char)*pbVar5);
            bVar3 = 0;
          }
          pbVar5[1] = bVar3;
        }
      }
      else if ((pbVar5[1] == 0) && (pbVar5[0x14] == 0)) {
        if ((*(char *)(unaff_r13 + 2) == '\0') || (iVar1 = FUN_0000feb4(pbVar5), iVar1 <= unaff_r9))
        {
          *(undefined4 *)(pbVar5 + 4) = *(undefined4 *)(pbVar5 + 8);
          iVar1 = *(int *)(pbVar5 + 0xc) - unaff_r9;
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
  *(undefined1 *)(unaff_r13 + 2) = uVar4;
  *(undefined1 *)(unaff_r13 + 6) = 0;
  return;
}


