/* ROM address: 0x00048484; body bytes: 120; decompiled */

uint FUN_00048484(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff874a,0);
  if (((cVar2 == '\x01') ||
      (cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8752,0), cVar2 == '\x01')) ||
     (DAT_ffffb51b == '\x01')) {
    DAT_ffffcca5 = 1;
  }
  else {
    DAT_ffffcca5 = 0;
  }
  uVar1 = (uint)DAT_ffffcca5;
  if (uVar1 == 1) {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffcc8e,1);
    DAT_ffffcc8e = (ushort)uVar1;
  }
  else {
    DAT_ffffcc8e = 0;
  }
  if (2 < DAT_ffffcc8e) {
    uVar1 = ref_whileLoop();
    return uVar1;
  }
  return uVar1;
}


