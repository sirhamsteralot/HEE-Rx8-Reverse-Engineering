/* ROM address: 0x0001e26e; body bytes: 146; decompiled */

undefined ** FUN_0001e26e(void)

{
  undefined **ppuVar1;
  
  if (DAT_ffffaae4 < 1.2) {
    if ((DAT_ffffb095 == '\x01') && (DAT_ffffaae4 < DAT_ffffae74 + 0.05)) {
      DAT_ffffb095 = '\0';
      DAT_ffffb094 = '\x01';
    }
  }
  else {
    DAT_ffffb095 = '\x01';
    DAT_ffffb094 = '\0';
  }
  ppuVar1 = (undefined **)(uint)DAT_ffffb13a;
  if (ppuVar1 == (undefined **)&UNK_00000001) {
    DAT_ffffae90 = 0x90;
  }
  else if (DAT_ffffb094 == '\0') {
    if (DAT_ffffadbc < 3.5) {
      if (DAT_ffffae90 != 0) {
        DAT_ffffae90 = DAT_ffffae90 - 1;
      }
    }
    else {
      ppuVar1 = &PTR_DAT_00070134;
      if (DAT_ffffae90 < 5) {
        DAT_ffffae90 = 0;
      }
      else {
        DAT_ffffae90 = DAT_ffffae90 - 5;
      }
    }
  }
  else {
    DAT_ffffae90 = 0;
    DAT_ffffb094 = '\0';
  }
  return ppuVar1;
}


