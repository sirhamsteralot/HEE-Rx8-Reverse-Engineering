/* ROM address: 0x0004cbc4; body bytes: 288; decompiled */

uint FUN_0004cbc4(void)

{
  uint uVar1;
  char cVar2;
  
  DAT_ffffcee0 = DAT_ffffcb20 < -1.0;
  DAT_ffffcee1 = 6.0 < DAT_ffffcb20;
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcedc = -0x60;
    uVar1 = 0xffffffa0;
    DAT_ffffcedd = -0x60;
    DAT_ffffcee5 = 0;
    DAT_ffffcee2 = '\0';
    DAT_ffffcee3 = 0;
    DAT_ffffcee4 = 0;
  }
  else if (((DAT_ffffcb20 < -1.0) || (6.0 < DAT_ffffcb20)) ||
          (cVar2 = FUN_000671a4(0x57), cVar2 != '\0')) {
    if (DAT_ffffcee0 == '\x01') {
      if (DAT_ffffcedc == '\0') {
        DAT_ffffcee2 = '\x01';
      }
      else {
        DAT_ffffcedc = DAT_ffffcedc + -1;
      }
    }
    if (DAT_ffffcee1 == '\x01') {
      if (DAT_ffffcedd == '\0') {
        DAT_ffffcee3 = 1;
      }
      else {
        DAT_ffffcedd = DAT_ffffcedd + -1;
      }
    }
    if ((DAT_ffffcee2 == '\x01') || (uVar1 = (uint)DAT_ffffcee3, uVar1 == 1)) {
      uVar1 = FUN_000671a4(0x57);
      uVar1 = uVar1 & 0xff;
      if (uVar1 == 0) {
        DAT_ffffcee5 = 1;
        DAT_ffffcee4 = 0;
      }
    }
  }
  else {
    DAT_ffffcee4 = 1;
    DAT_ffffcedc = -0x60;
    DAT_ffffcedd = -0x60;
    DAT_ffffcee5 = 0;
    DAT_ffffcee2 = '\0';
    DAT_ffffcee3 = 0;
    uVar1 = 0;
  }
  return uVar1;
}


