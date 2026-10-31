/* ROM address: 0x0004fb54; body bytes: 304; decompiled */

uint FUN_0004fb54(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff869c,0);
  cVar1 = DAT_ffffd040;
  if ((((((((int)DAT_ffffcfb5 & 0x80U) != 0) && (DAT_ffffd00e == '\x01')) && (DAT_ffffd010 == '\0'))
       && ((DAT_ffffccc6 == '\0' && (DAT_ffffa8ea == '\0')))) && (DAT_ffffbda0 == '\0')) ||
     (uVar3 = (uint)DAT_ffffcf78, uVar3 == 1)) {
    uVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a4,0);
    uVar3 = uVar3 & 0xff;
    if (uVar3 == 0) {
      uVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a6,0);
      uVar3 = uVar3 & 0xff;
      if (uVar3 == 0) {
        uVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a0,0);
        uVar3 = uVar3 & 0xff;
        if ((uVar3 == 0) && (DAT_ffffcfb1 != '\0')) {
          if (((uVar2 & 0xff) == 1) || ((uVar2 & 0xff) == 3)) {
            uVar3 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff869e,0);
            uVar3 = uVar3 & 0xff;
            if ((uVar2 & 0xff) == uVar3) goto LAB_0004fc1a;
          }
          else {
LAB_0004fc1a:
            uVar3 = (uint)DAT_ffffd0a8;
            if (uVar3 != 1) goto LAB_0004fc5c;
          }
          DAT_ffffd040 = 1;
          goto LAB_0004fc5e;
        }
      }
    }
  }
LAB_0004fc5c:
  DAT_ffffd040 = 0;
LAB_0004fc5e:
  if ((cVar1 == '\0') && (uVar3 = (uint)DAT_ffffd040, uVar3 == 1)) {
    uVar4 = 0;
    DAT_ffffd042 = 0;
    DAT_ffffd043 = 0;
    DAT_ffffd045 = 0;
    DAT_ffffd046 = 0;
    ref_updateMemoryAtAddress_float_VAL_ADDR(0,&DAT_ffff8684);
    ref_updateMemoryAtAddress_float_VAL_ADDR(uVar4,&DAT_ffff868c);
    uVar3 = ref_updateMemoryAtAddress_float_VAL_ADDR(uVar4,&DAT_ffff8694);
  }
  return uVar3;
}


