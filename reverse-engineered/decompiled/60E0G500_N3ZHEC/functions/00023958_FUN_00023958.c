/* ROM address: 0x00023958; body bytes: 274; decompiled */

uint FUN_00023958(void)

{
  byte bVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float arg0;
  
  fVar3 = (float)FUN_0003eb72(0x41700000,&DAT_ffff80a4);
  bVar1 = DAT_ffffccfc;
  arg0 = (fVar3 + 0.5) - 0.0;
  if (DAT_ffffb520 < fVar3 + 0.5) {
    if (DAT_ffffb520 < arg0) {
      DAT_ffffb470 = '\0';
    }
  }
  else {
    DAT_ffffb470 = '\x01';
  }
  uVar2 = (uint)DAT_ffffccfc;
  if (uVar2 == 1) {
    if (DAT_ffffb471 == '\0') {
      fVar4 = fVar3 + 0.5;
      if (DAT_ffffb520 < fVar3 + 0.5) {
        fVar4 = rx8_min_float(arg0,DAT_ffffb480 + fVar3);
      }
    }
    else {
      fVar4 = DAT_ffffb468;
      if (DAT_ffffb470 == '\x01') {
        if (1 < DAT_ffffb46c) {
          fVar4 = rx8_max_float(5.0,DAT_ffffb468 - 0.05);
          DAT_ffffb46c = 0;
        }
      }
      else if (1 < DAT_ffffb46e) {
        fVar4 = rx8_max_float(5.0,DAT_ffffb468 - 0.05);
        DAT_ffffb46e = 0;
      }
    }
  }
  else {
    DAT_ffffb468 = 0.0;
    fVar4 = DAT_ffffb468;
  }
  DAT_ffffb468 = fVar4;
  if (uVar2 == 1) {
    if (DAT_ffffb470 != '\x01') {
      DAT_ffffb46c = 0;
      uVar2 = FUN_00002460((int)(short)DAT_ffffb46e,1);
      DAT_ffffb46e = (short)uVar2;
      DAT_ffffb471 = bVar1;
      return uVar2;
    }
    uVar2 = FUN_00002460((int)(short)DAT_ffffb46c,1);
    DAT_ffffb46c = (ushort)uVar2;
  }
  else {
    DAT_ffffb46c = 0;
  }
  DAT_ffffb46e = 0;
  DAT_ffffb471 = bVar1;
  return uVar2;
}


