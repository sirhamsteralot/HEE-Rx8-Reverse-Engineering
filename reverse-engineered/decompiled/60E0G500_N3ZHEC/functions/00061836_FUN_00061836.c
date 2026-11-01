/* ROM address: 0x00061836; body bytes: 458; decompiled */

/* Function candidate recovered from ROM pointer at 684b8 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00061836(uint *param_1)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  uVar3 = *param_1;
  uVar5 = param_1[1];
  uVar6 = param_1[2];
  puVar8 = (ushort *)(uVar5 & 0xff);
  uVar2 = *(ushort *)(&DAT_0007daea + (uVar3 & 0xffff) * 2);
  iVar7 = (int)(short)uVar2;
  DAT_ffffd700 = uVar2;
  if ((puVar8 == (ushort *)&UNK_00000010) || (puVar8 == (ushort *)&UNK_00000011)) {
    puVar8 = (ushort *)FUN_00060cdc(iVar7,0x10);
    cVar1 = (&DAT_0007ded2)[uVar2];
    FUN_00062b44(iVar7);
    if (*puVar8 == uVar2) {
      FUN_00062bc4(8);
      FUN_000637ca(0);
      FUN_0006305c();
      puVar8 = puVar8 + 2;
    }
    if (cVar1 == '\0') {
      FUN_0006141e(iVar7,0x10);
    }
    else if (cVar1 == '\x01') {
      FUN_00065070(iVar7,uVar5);
    }
    else if (cVar1 == '\x02') {
      thunk_FUN_0006141e(iVar7,uVar5);
    }
    else if (cVar1 == '\x03') {
      thunk_FUN_0006141e(iVar7,uVar5);
    }
    FUN_00062f44();
  }
  else if (puVar8 == (ushort *)&UNK_00000020) {
    puVar8 = (ushort *)FUN_00060cdc(iVar7,0x20);
  }
  for (uVar4 = 0; (*puVar8 != 0xffff && (uVar4 < 2)); uVar4 = uVar4 + 1) {
    FUN_00062b44((int)(short)*puVar8);
    DAT_ffffd6f8 = *puVar8;
    cVar1 = (&DAT_0007ded2)[DAT_ffffd6f8];
    if (cVar1 == '\0') {
      FUN_000612b8((int)(short)*puVar8,(int)*(char *)(puVar8 + 1));
    }
    else if (cVar1 == '\x01') {
      FUN_00064dc4((int)(short)*puVar8,(int)*(char *)(puVar8 + 1),uVar6);
    }
    else if (cVar1 == '\x02') {
      FUN_00064f20((int)(short)*puVar8,(int)*(char *)(puVar8 + 1),uVar6);
    }
    else if (cVar1 == '\x03') {
      FUN_00064708((int)(short)*puVar8,(int)*(char *)(puVar8 + 1));
    }
    if (*puVar8 == uVar2) {
      FUN_00062654((int)(short)*puVar8,(int)*(char *)(puVar8 + 1),uVar6);
      FUN_000042b0();
    }
    else {
      FUN_00062764((int)(short)*puVar8,(int)*(char *)(puVar8 + 1));
      FUN_000042b0();
    }
    FUN_00060d3a();
    FUN_00062f44();
    puVar8 = puVar8 + 2;
  }
  FUN_0006123a();
  *param_1 = uVar3 & 0xffff;
  FUN_00060a48(*param_1,(int)*(char *)((int)param_1 + 7),param_1[2]);
  return;
}


