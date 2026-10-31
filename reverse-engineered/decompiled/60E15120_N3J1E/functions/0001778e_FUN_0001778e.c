/* ROM address: 0x0001778e; body bytes: 340; decompiled */

uint FUN_0001778e(char param_1)

{
  char cVar2;
  uint uVar1;
  byte *pbVar3;
  byte bVar4;
  
  if (param_1 == '\0') {
    DAT_ffffa900 = 0;
    DAT_ffffa901 = 0;
  }
  if (DAT_ffffa900 == 1) {
    cVar2 = '\0';
    bVar4 = 0;
    if (DAT_ffffa8e8 == '\x01') {
      cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8050,0);
      if (((cVar2 == '\0') ||
          (cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8054,0), cVar2 != '\x01')) ||
         (inferred_coolant_temperature_ffffa98c < -40.0)) {
        bVar4 = 1;
        pbVar3 = &DAT_00078d3e;
        cVar2 = '\0';
      }
      else {
        pbVar3 = &DAT_00078d3f;
        cVar2 = '\x01';
        bVar4 = 0;
      }
      DAT_ffffa8fd = *pbVar3;
    }
    DAT_ffffa900 = 2;
    DAT_ffffa8f6 = cVar2;
    DAT_ffffa8f7 = bVar4;
  }
  if (DAT_ffffa900 == 0) {
    if (DAT_ffffa8fb == 5) {
      DAT_ffffa8fa = -0x80;
      DAT_ffffa900 = 1;
    }
    else if (DAT_ffffa8fb == 4) {
      DAT_ffffa8fa = '0';
      FUN_000174b4(0);
      if (DAT_ffffa8f4 < 0x3c) {
        DAT_ffffa8fe = DAT_ffffa8f4 + 1;
      }
    }
    else {
      DAT_ffffa8fa = '\x10';
      FUN_000174b4(2);
    }
  }
  uVar1 = (uint)DAT_ffffa900;
  if ((uVar1 == 2) && ((DAT_ffffa8f6 == '\x01' || (uVar1 = (uint)DAT_ffffa8f7, uVar1 == 1)))) {
    if ((DAT_ffffa8fb & 1) == 0) {
      DAT_ffffa8fa = '0';
      FUN_000174b4(1);
      uVar1 = (uint)DAT_ffffa8fb;
      if ((uVar1 == 5) && (DAT_ffffa8fd < 2)) {
        DAT_ffffa901 = 1;
        DAT_ffffa8fe = '\0';
        DAT_ffffa8fd = 0;
        uVar1 = rx8_add_u8_saturate((int)DAT_ffffa8fa,0x30);
        DAT_ffffa8fa = (char)uVar1;
      }
    }
    else {
      DAT_ffffa8fa = '\b';
      uVar1 = FUN_000174b4(1);
      if (DAT_ffffa8fd != 0) {
        DAT_ffffa8fd = DAT_ffffa8fd - 1;
      }
    }
  }
  return uVar1;
}


