/* ROM address: 0x0002bcc0; body bytes: 70; decompiled */

int FUN_0002bcc0(void)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  
  pcVar3 = &DAT_ffffbc2a;
  if (DAT_ffffbc2a == '\0') {
    iVar1 = FUN_00004144(0,DAT_ffffa415,&DAT_ffffbc2a,6);
    if (iVar1 == 0) {
      DAT_ffffbc24 = 0;
    }
  }
  else {
    cVar2 = DAT_ffffbc2a;
    iVar1 = FUN_00004144();
    if (iVar1 == 0) {
      *pcVar3 = cVar2 + -1;
    }
  }
  return iVar1;
}


