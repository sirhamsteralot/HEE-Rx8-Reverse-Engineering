/* ROM address: 0x0001ce0e; body bytes: 30; decompiled */

int FUN_0001ce0e(void)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 1;
  iVar1 = 4;
  do {
    bVar2 = bVar2 + 1;
    *(undefined4 *)((int)&DAT_ffffafc0 + iVar1) = 0;
    *(undefined4 *)((int)&DAT_ffffb014 + iVar1) = 0;
    iVar1 = iVar1 + 4;
  } while (bVar2 < 0x15);
  return iVar1;
}


