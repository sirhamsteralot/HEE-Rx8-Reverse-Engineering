/* ROM address: 0x00028b78; body bytes: 54; decompiled */

uint FUN_00028b78(void)

{
  uint uVar1;
  undefined1 *puVar2;
  
  uVar1 = (int)DAT_ffffb6d0 & 1;
  puVar2 = &DAT_ffffba92 + uVar1;
  if ((DAT_ffffbab8 <= DAT_ffffbae8) || (uVar1 = (uint)DAT_ffffb70c, uVar1 != 1)) {
    *puVar2 = 0;
  }
  else {
    *puVar2 = 1;
  }
  return uVar1;
}


