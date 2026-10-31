/* ROM address: 0x00065158; body bytes: 158; decompiled */

void FUN_00065158(ushort *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  
  cVar1 = (&DAT_ffff8d54)[(uint)*param_1 * 2];
  iVar2 = (int)*(char *)(param_1 + 6);
  if (*param_1 == 0) {
    cVar3 = '\0';
  }
  else {
    cVar3 = FUN_000678b4((int)(short)*param_1);
  }
  cVar4 = FUN_0006559c((int)*(char *)(param_1 + 3));
  if ((cVar4 == '`') || (cVar4 == 'p')) {
    if ((0x4f < *(byte *)(param_2 + 10)) || ((cVar1 == '\x11' && (cVar3 == '\0')))) {
      iVar2 = 0;
    }
  }
  else if ((cVar1 == '\x11') && (cVar3 == '\0')) {
    iVar2 = 0;
  }
  FUN_00063098(iVar2);
  *(char *)(param_2 + 0xc) = (char)iVar2;
  return;
}


