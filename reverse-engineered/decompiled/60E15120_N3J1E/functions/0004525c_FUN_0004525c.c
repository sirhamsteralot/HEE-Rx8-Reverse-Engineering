/* ROM address: 0x0004525c; body bytes: 388; decompiled */

uint FUN_0004525c(void)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint unaff_r11;
  uint unaff_r12;
  uint uVar4;
  
  bVar1 = false;
  bVar2 = false;
  uVar4 = (uint)DAT_ffffa415;
  if ((uVar4 == 3) || (uVar4 == 0xf)) {
    unaff_r12 = 0;
    unaff_r11 = 1;
  }
  else if ((uVar4 == 9) || (uVar4 == 0x15)) {
    unaff_r12 = 2;
    unaff_r11 = 3;
  }
  if ((((uVar4 != 3) && (uVar4 != 9)) && (uVar4 != 0xf)) && (uVar4 != 0x15)) {
    return uVar4;
  }
  if (DAT_ffffcbb4 == '\x01') {
    bVar1 = DAT_ffffcbaf == '\x01';
    if (bVar1) {
      FUN_0004546a(unaff_r12);
    }
    if (DAT_ffffcbac == '\x01') {
      FUN_0004546a(unaff_r11);
      bVar2 = true;
    }
  }
  uVar3 = unaff_r12 & 0xff;
  uVar4 = unaff_r11 & 0xff;
  if (DAT_ffffd1ad == '\x01') {
    (&DAT_ffffcbbe)[uVar3] = 0;
  }
  else {
    if (bVar1) {
      (&DAT_ffffcbbe)[uVar3] = 0;
    }
    else if ((DAT_ffffcbb4 == '\x01') && ((DAT_ffffcbad == '\x01' || (DAT_ffffcbae == '\x01')))) {
      FUN_0004549c(unaff_r12);
    }
    if (!bVar2) {
      if ((DAT_ffffcbb4 == '\x01') && ((DAT_ffffcbaa == '\x01' || (DAT_ffffcbab == '\x01')))) {
        FUN_0004549c(unaff_r11);
      }
      goto LAB_00045394;
    }
  }
  (&DAT_ffffcbbe)[uVar4] = 0;
LAB_00045394:
  if (0xfe < (byte)(&DAT_ffffcbbe)[uVar3]) {
    (&DAT_ffffcbba)[uVar3] = 1;
    (&DAT_ffffcbb6)[uVar3] = 0;
  }
  if (0xfe < (byte)(&DAT_ffffcbbe)[uVar4]) {
    (&DAT_ffffcbba)[uVar4] = 1;
    (&DAT_ffffcbb6)[uVar4] = 0;
  }
  FUN_00045426(unaff_r12);
  uVar4 = FUN_00045426(unaff_r11);
  return uVar4;
}


