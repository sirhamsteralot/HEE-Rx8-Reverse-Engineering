/* ROM address: 0x0005a3f4; body bytes: 358; decompiled */

uint FUN_0005a3f4(void)

{
  short sVar3;
  undefined4 uVar1;
  byte bVar4;
  uint uVar2;
  uint uVar5;
  uint *puVar6;
  byte *pbVar7;
  
  pbVar7 = &DAT_ffffd2b4;
  puVar6 = &DAT_ffffd2ac;
  if (DAT_ffffd2db == '\x01') {
    DAT_ffffd2db = '\0';
    DAT_ffffd2ac = 0x2000;
    DAT_ffffd2b4 = 1;
    DAT_ffffd2b0 = 0;
    DAT_ffffd2b2 = 0;
    DAT_ffffd2b6 = '\x01';
    DAT_ffffd2b7 = '\0';
  }
  if (DAT_ffffd2b6 == '\x01') {
    uVar2 = 0;
    while ((uVar2 < 0x1000 && (DAT_ffffd2ac < 0x80000))) {
      if (((undefined2 *)*puVar6 < &DAT_0007fb00) || ((int)&PTR_0007fb7c + 3U < *puVar6)) {
        uVar5 = (uint)*pbVar7;
        sVar3 = FUN_00003fe8();
        DAT_ffffd2b0 = DAT_ffffd2b0 + sVar3;
        sVar3 = FUN_00004144();
        DAT_ffffd2b2 = DAT_ffffd2b2 + sVar3;
        if ((int)uVar5 < 0xff) {
          *pbVar7 = *pbVar7 + 1;
        }
        else {
          *pbVar7 = 1;
        }
      }
      uVar2 = uVar2 + 2;
      *puVar6 = *puVar6 + 2;
    }
    if (0x7ffff < *puVar6) {
      FUN_0005a714();
      DAT_ffffd2b7 = '\x01';
    }
    if (DAT_ffffd2b7 == '\x01') {
      DAT_ffffd2b6 = '\0';
      uVar2 = (uint)DAT_ffffd2b0;
      uVar5 = (uint)DAT_ffffd2b2;
      uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
      ref_updateMemoryAtAddress_32bit_ADDR_VAL(&DAT_ffff9104,uVar2 * 0x10000 + uVar5);
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff910c,1);
      ref_setSR(uVar1);
    }
  }
  bVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff910c,0);
  ref_readValue_32bit_ADDRESS_VAL(&DAT_ffff9104,0);
  uVar2 = (uint)DAT_ffffd2dc;
  if (((uVar2 == 1) && (uVar2 = (uint)bVar4, uVar2 == 1)) && (DAT_ffffc63c == '\0')) {
    DAT_ffffd2dc = 0;
    uVar2 = FUN_0006647c();
    return uVar2;
  }
  return uVar2;
}


