/* ROM address: 0x000546f8; body bytes: 120; decompiled */

uint FUN_000546f8(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_getKnownBooleanValue__();
  if (((cVar2 == '\x01') && (DAT_ffffd1c1 == '\0')) || (DAT_ffffd1c5 == '\x01')) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fe4,0);
  }
  else if (((DAT_ffffcb6e == '\x01') || (DAT_ffffcb9e == '\x01')) ||
          ((uVar1 = (uint)DAT_ffffcb6d, uVar1 == 1 && (uVar1 = (uint)DAT_ffffcb9d, uVar1 == 1)))) {
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8fe4,1);
  }
  DAT_ffffd1c1 = cVar2;
  return uVar1;
}


