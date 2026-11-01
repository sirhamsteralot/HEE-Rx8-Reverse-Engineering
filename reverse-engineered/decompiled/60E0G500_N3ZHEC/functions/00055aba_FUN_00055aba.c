/* ROM address: 0x00055aba; body bytes: 72; decompiled */

int FUN_00055aba(void)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_38 [40];
  byte local_10;
  byte bStack_f;
  
  iVar2 = 0;
  cVar1 = FUN_00062298(auStack_38);
  if (cVar1 == '\0') {
    cVar1 = FUN_00055138(auStack_38,2,&local_10);
    if (cVar1 == '\x02') {
      iVar2 = (uint)local_10 * 0x100 + (uint)bStack_f;
    }
  }
  return iVar2;
}


