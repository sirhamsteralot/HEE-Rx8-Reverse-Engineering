/* ROM address: 0x0006554a; body bytes: 252; decompiled */

void FUN_0006554a(ushort *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  char cVar5;
  
  cVar1 = (&DAT_ffff8d7c)[(uint)*param_1 * 2];
  iVar2 = (int)*(char *)(param_1 + 3);
  iVar3 = (int)*(char *)((int)param_1 + 0xd);
  if (*param_1 == 0) {
    cVar4 = '\0';
  }
  else {
    cVar4 = FUN_00068058((int)(short)*param_1);
  }
  cVar5 = FUN_00065d40((int)*(char *)(param_1 + 3));
  if (cVar5 == '`') {
    if ((0x4f < *(byte *)(param_2 + 10)) || ((cVar1 == '\x11' && (cVar4 == '\0')))) {
      iVar2 = 0;
      iVar3 = 8;
    }
  }
  else if (cVar5 == 'p') {
    if ((0x4f < *(byte *)(param_2 + 10)) || ((cVar1 == '\x11' && (cVar4 == '\0')))) {
      iVar2 = 0xc1;
    }
  }
  else if (cVar5 == -0x40) {
    if ((byte)(&DAT_0007dfea)[*param_1] <= *(byte *)(param_2 + 9)) {
      iVar2 = 0xc1;
    }
  }
  else if ((cVar5 == -0x3f) && ((byte)(&DAT_0007e076)[*param_1] <= *(byte *)(param_2 + 8))) {
    iVar3 = 8;
    iVar2 = 0;
  }
  FUN_0006357c(iVar2);
  FUN_000638ae(iVar3);
  *(char *)(param_2 + 6) = (char)iVar2;
  *(char *)(param_2 + 0xd) = (char)iVar3;
  return;
}


