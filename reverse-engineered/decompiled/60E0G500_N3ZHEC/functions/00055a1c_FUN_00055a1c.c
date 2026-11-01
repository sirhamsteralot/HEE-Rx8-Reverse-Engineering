/* ROM address: 0x00055a1c; body bytes: 40; decompiled */

uint FUN_00055a1c(void)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = FUN_00060218();
  cVar2 = FUN_0003eaa4(&DAT_ffff9000,0);
  if (cVar2 == '\x01') {
    uVar1 = uVar1 | 0x80;
  }
  return uVar1;
}


