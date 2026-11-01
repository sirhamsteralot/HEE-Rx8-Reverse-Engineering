/* ROM address: 0x000082b8; body bytes: 32; decompiled */

undefined4 FUN_000082b8(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = FUN_000085e4(uVar2);
    uVar2 = uVar2 + 1;
  } while ((uVar2 & 0xff) < 6);
  return uVar1;
}


