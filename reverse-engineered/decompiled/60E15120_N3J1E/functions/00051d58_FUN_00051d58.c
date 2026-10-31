/* ROM address: 0x00051d58; body bytes: 188; decompiled */

uint FUN_00051d58(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  byte bVar3;
  
  uVar1 = (uint)DAT_ffffcfb5;
  bVar3 = -(((uVar1 & 0x80) == 0) + -1);
  if ((DAT_ffffd12a == '\0') && (uVar1 = (uint)bVar3, uVar1 == 1)) {
    uVar2 = sh_raise_interrupt_mask_return_previous(0x10);
    DAT_ffffd10c = 0;
    ref_setSR(uVar2);
    DAT_ffffd10e = 0;
    DAT_ffffd10f = 0;
    DAT_ffffd110 = 0;
    DAT_ffffd111 = 0;
    DAT_ffffd112 = 0;
    DAT_ffffd113 = 0;
    DAT_ffffd114 = 0;
    DAT_ffffd115 = 0;
    DAT_ffffd116 = 0;
    DAT_ffffd117 = 0;
    DAT_ffffd118 = 0;
    DAT_ffffd119 = 0;
    DAT_ffffd11a = 0;
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86c8,0,param_3,param_4,uVar2);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86ca,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86cc,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86ce,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d0,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d2,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d4,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d6,0);
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86d8,0);
    uVar1 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86da,0);
  }
  DAT_ffffd12a = bVar3;
  return uVar1;
}


