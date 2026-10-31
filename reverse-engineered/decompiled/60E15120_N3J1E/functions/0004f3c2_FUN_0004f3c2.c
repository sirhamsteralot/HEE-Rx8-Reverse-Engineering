/* ROM address: 0x0004f3c2; body bytes: 74; decompiled */

uint FUN_0004f3c2(void)

{
  uint uVar1;
  undefined4 uVar2;
  byte bVar3;
  
  uVar1 = (uint)DAT_ffffcfb5;
  bVar3 = -(((uVar1 & 0x80) == 0) + -1);
  if ((DAT_ffffd005 == '\0') && (uVar1 = (uint)bVar3, uVar1 == 1)) {
    uVar2 = sh_raise_interrupt_mask_return_previous(0x10);
    DAT_ffffcfec = 0;
    DAT_ffffcff0 = 0x3d1ba5e3;
    uVar1 = ref_setSR(uVar2);
  }
  DAT_ffffd005 = bVar3;
  return uVar1;
}


