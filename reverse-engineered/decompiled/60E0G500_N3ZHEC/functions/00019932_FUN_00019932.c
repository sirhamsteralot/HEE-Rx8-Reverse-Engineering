/* ROM address: 0x00019932; body bytes: 428; decompiled */

uint FUN_00019932(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  
  bVar1 = DAT_ffffccd1;
  if (DAT_ffffb5b8 < 8500.0) {
    if (DAT_ffffb5b8 < 8400.0) {
      DAT_ffffaa04 = '\0';
    }
  }
  else {
    DAT_ffffaa04 = '\x01';
  }
  if (DAT_ffffb5b8 < 3000.0) {
    if (DAT_ffffb5b8 < 2900.0) {
      DAT_ffffaa05 = '\0';
    }
  }
  else {
    DAT_ffffaa05 = '\x01';
  }
  if (DAT_ffffb5b8 < 1300.0) {
    if (DAT_ffffb5b8 < 1200.0) {
      DAT_ffffaa06 = 0;
    }
  }
  else {
    DAT_ffffaa06 = 1;
  }
  if (DAT_ffffb5b8 < 1300.0) {
    if (DAT_ffffb5b8 < 1200.0) {
      DAT_ffffaa07 = 0;
    }
  }
  else {
    DAT_ffffaa07 = 1;
  }
  uVar2 = (uint)DAT_ffffa9ef;
  if ((DAT_ffffaada == 1) || (2 < DAT_ffffccd1)) {
    DAT_ffffa9f4 = 0;
    DAT_ffffa9f6 = 0;
    DAT_ffffa9f8 = 0;
    uVar3 = (uint)DAT_ffffaada;
    DAT_ffffa9ea = 0;
  }
  else if (uVar2 == 1) {
    uVar4 = DAT_ffffa9ea;
    if (DAT_ffffaa04 == '\x01') {
      if (0x4d < DAT_ffffa9f4) {
        uVar4 = 1;
      }
      DAT_ffffa9f4 = FUN_00002460((int)(short)DAT_ffffa9f4,1);
    }
    else {
      DAT_ffffa9f4 = 0;
    }
    if (DAT_ffffaa05 == '\x01') {
      if (0x3a9 < DAT_ffffa9f6) {
        uVar4 = 1;
      }
      DAT_ffffa9f6 = FUN_00002460((int)(short)DAT_ffffa9f6,1);
    }
    else {
      DAT_ffffa9f6 = 0;
    }
    if (DAT_ffffaa06 == 1) {
      if (0x927 < DAT_ffffa9f8) {
        uVar4 = 1;
      }
      uVar3 = FUN_00002460((int)(short)DAT_ffffa9f8,1);
      DAT_ffffa9f8 = (ushort)uVar3;
      DAT_ffffa9ea = uVar4;
    }
    else {
      DAT_ffffa9f8 = 0;
      uVar3 = (uint)DAT_ffffaa06;
      DAT_ffffa9ea = uVar4;
    }
  }
  else {
    DAT_ffffa9f4 = 0;
    DAT_ffffa9f6 = 0;
    DAT_ffffa9f8 = 0;
    uVar3 = uVar2;
  }
  if (((bVar1 < 3) || (uVar3 = uVar2, uVar2 != 1)) || (uVar3 = (uint)DAT_ffffaa07, uVar3 != 1)) {
    DAT_ffffa9fa = 0;
  }
  else {
    if (0x927 < DAT_ffffa9fa) {
      DAT_ffffa9f0 = 1;
    }
    uVar3 = FUN_00002460((int)(short)DAT_ffffa9fa,1);
    DAT_ffffa9fa = (ushort)uVar3;
  }
  return uVar3;
}


