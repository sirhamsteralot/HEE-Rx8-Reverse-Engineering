/* ROM address: 0x00008320; body bytes: 32; decompiled */

undefined4 FUN_00008320(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = FUN_0000871c(uVar2);
    uVar2 = uVar2 + 1;
  } while ((uVar2 & 0xff) < 6);
  return uVar1;
}


