/* ROM address: 0x00018d00; body bytes: 78; decompiled */

uint FUN_00018d00(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff8082,0);
  if (cVar2 == '\x01') {
    FUN_000604dc(0x50,1);
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8084,0);
  if (cVar2 == '\x01') {
    FUN_000604dc(0x51,1);
  }
  uVar1 = FUN_0003eaa4(&DAT_ffff8086,0);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 1) {
    uVar1 = FUN_000604dc(0x52,1);
  }
  return uVar1;
}


