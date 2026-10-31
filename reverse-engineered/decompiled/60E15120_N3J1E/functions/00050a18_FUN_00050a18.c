/* ROM address: 0x00050a18; body bytes: 278; decompiled */

uint FUN_00050a18(void)

{
  char cVar1;
  char cVar3;
  uint uVar2;
  undefined4 uVar4;
  
  cVar1 = DAT_ffffd0a8;
  if (((((((DAT_ffffd00e == '\x01') && (((int)DAT_ffffcfb5 & 0x80U) != 0)) && (DAT_ffffd010 == '\0')
         ) && ((DAT_ffffccc6 == '\0' && (DAT_ffffa8ea == '\0')))) &&
       ((DAT_ffffbda0 == '\0' &&
        ((cVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86e4,0), cVar3 == '\x01' ||
         (cVar3 = FUN_0005f9f0(0x31,2), cVar3 == '\x01')))))) && (0x249 < DAT_ffffd00c)) ||
     (uVar2 = (uint)DAT_ffffcf78, uVar2 == 1)) {
    uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c0,0);
    uVar2 = uVar2 & 0xff;
    if (uVar2 == 0) {
      uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c2,0);
      uVar2 = uVar2 & 0xff;
      if ((uVar2 == 0) && (DAT_ffffcfb1 != '\0')) {
        uVar2 = 1;
        DAT_ffffd0a8 = 1;
        goto LAB_00050b0e;
      }
    }
  }
  DAT_ffffd0a8 = 0;
LAB_00050b0e:
  if ((cVar1 == '\0') && (uVar2 = (uint)DAT_ffffd0a8, uVar2 == 1)) {
    uVar4 = 0;
    DAT_ffffd0a0 = 0;
    DAT_ffffd0a2 = 0;
    DAT_ffffd0a4 = 0;
    DAT_ffffd0a6 = 0;
    DAT_ffffd094 = 0;
    ref_updateMemoryAtAddress_float_VAL_ADDR(0,&DAT_ffff86a8);
    ref_updateMemoryAtAddress_float_VAL_ADDR(uVar4,&DAT_ffff86b0);
    uVar2 = ref_updateMemoryAtAddress_float_VAL_ADDR(uVar4,&DAT_ffff86b8);
  }
  return uVar2;
}


