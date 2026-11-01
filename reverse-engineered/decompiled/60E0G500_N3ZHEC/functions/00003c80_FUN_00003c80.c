/* ROM address: 0x00003c80; body bytes: 190; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00003c80(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  char cVar4;
  uint uVar3;
  int iVar5;
  
  if (DAT_ffff7674 == 0) {
    if (DAT_ffff7670 == 0) {
      if (DAT_ffff766c == 0) {
        iVar2 = 0;
        if (_DAT_ffff7668 == 0) {
          *param_1 = 0xff;
          *(undefined2 *)(param_1 + 6) = 0xffff;
          return;
        }
        iVar5 = 0;
      }
      else {
        iVar2 = 4;
        iVar5 = 0x20;
      }
    }
    else {
      iVar2 = 8;
      iVar5 = 0x40;
    }
  }
  else {
    iVar2 = 0xc;
    iVar5 = 0x60;
  }
  puVar1 = &DAT_ffff7668;
  if (*(short *)(&DAT_ffff766a + iVar2) == 0) {
    cVar4 = (&DAT_ffff7669)[iVar2];
  }
  else {
    puVar1 = &DAT_ffff766a;
    iVar5 = iVar5 + 0x10;
    cVar4 = (&DAT_ffff766b)[iVar2];
  }
  if (cVar4 == '\0') {
    cVar4 = puVar1[iVar2];
  }
  else {
    iVar5 = iVar5 + 8;
    cVar4 = (puVar1 + iVar2)[1];
  }
  uVar3 = (uint)cVar4;
  if ((uVar3 & 0x80) == 0) {
    if ((uVar3 & 0x40) == 0) {
      if ((uVar3 & 0x20) == 0) {
        if ((uVar3 & 0x10) == 0) {
          if ((uVar3 & 8) == 0) {
            if ((uVar3 & 4) == 0) {
              if ((uVar3 & 2) != 0) {
                iVar5 = iVar5 + 1;
              }
            }
            else {
              iVar5 = iVar5 + 2;
            }
          }
          else {
            iVar5 = iVar5 + 3;
          }
        }
        else {
          iVar5 = iVar5 + 4;
        }
      }
      else {
        iVar5 = iVar5 + 5;
      }
    }
    else {
      iVar5 = iVar5 + 6;
    }
  }
  else {
    iVar5 = iVar5 + 7;
  }
  *param_1 = (char)iVar5;
  *(undefined2 *)(param_1 + 6) =
       *(undefined2 *)
        (*(int *)(param_1 + 0x24) + **(short **)(*(int *)(param_1 + 0x20) + iVar5 * 8 + 4) * 2);
  return;
}


