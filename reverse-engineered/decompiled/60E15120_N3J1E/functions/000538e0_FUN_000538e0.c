/* ROM address: 0x000538e0; body bytes: 164; decompiled */

uint FUN_000538e0(void)

{
  uint uVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fc8,0);
    return uVar1;
  }
  if ((DAT_ffffd19c != '\x01') &&
     ((((((uVar1 = (uint)DAT_ffffc702, uVar1 != 1 || (uVar1 = (uint)DAT_ffffc6d6, uVar1 != 1)) ||
         (uVar1 = (uint)DAT_ffffc6d4, uVar1 != 1)) ||
        ((uVar1 = (uint)DAT_ffffc96e, uVar1 != 1 || (uVar1 = (uint)DAT_ffffc96c, uVar1 != 1)))) ||
       ((uVar1 = (uint)DAT_ffffc970, uVar1 != 1 ||
        ((uVar1 = (uint)DAT_ffffcd14, uVar1 != 1 || (uVar1 = (uint)DAT_ffffc6bc, uVar1 != 1)))))) ||
      ((uVar1 = (uint)DAT_ffffc6b8, uVar1 != 1 || (uVar1 = (uint)DAT_ffffc6ba, uVar1 != 1)))))) {
    return uVar1;
  }
  uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fc8,1);
  return uVar1;
}


