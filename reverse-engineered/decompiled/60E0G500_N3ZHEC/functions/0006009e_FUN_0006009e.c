/* ROM address: 0x0006009e; body bytes: 86; decompiled */

int FUN_0006009e(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = FUN_00061fa4(0);
  if (((cVar1 == -0x40) || (cVar1 == -0x3f)) || (cVar1 == 'p')) {
    iVar2 = 1;
  }
  cVar1 = FUN_00061fa4(1);
  if (((cVar1 == -0x40) || (cVar1 == -0x3f)) || (cVar1 == 'p')) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


