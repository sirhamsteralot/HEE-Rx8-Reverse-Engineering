/* ROM address: 0x000670ee; body bytes: 116; decompiled */

/* Function candidate recovered from ROM pointer at 622fc and register-save prologue. Heuristic
   boundary; inspect disassembly. */

int FUN_000670ee(ushort *param_1,ushort param_2,short *param_3)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar5 = 0;
  do {
    if ((int)(uint)param_2 <= iVar6) {
      return iVar5;
    }
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    bVar2 = false;
    if ((iVar5 != 0) && (iVar3 = 0, psVar4 = param_3, 0 < iVar5)) {
      do {
        if (*psVar4 == (&DAT_0007e108)[uVar1]) {
          bVar2 = true;
          break;
        }
        iVar3 = iVar3 + 1;
        psVar4 = psVar4 + 1;
      } while (iVar3 < iVar5);
    }
    iVar6 = iVar6 + 1;
    if (!bVar2) {
      param_3[iVar5] = (&DAT_0007e108)[uVar1];
      iVar5 = iVar5 + 1;
    }
  } while( true );
}


