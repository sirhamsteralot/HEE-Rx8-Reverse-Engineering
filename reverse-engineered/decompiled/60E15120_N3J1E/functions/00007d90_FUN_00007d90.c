/* ROM address: 0x00007d90; body bytes: 172; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007d90 (172 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00007d90(uint param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)DAT_ffff9fa3;
  cVar1 = (char)param_1;
  if (DAT_ffff9f96 == '\0') {
    if (uVar3 != 1) {
      if (DAT_ffff9fbc < 60.0) {
        return uVar3;
      }
      uVar3 = FUN_00007e3c(param_1);
      if ((uVar3 & 0xff) == 0xff) {
        return uVar3;
      }
      DAT_ffff9fca = cVar1 + '\f';
      if ((uVar3 & 0xff) == 0) {
        DAT_ffff9fca = cVar1;
      }
      DAT_ffff9fc9 = (char)uVar3;
      return uVar3;
    }
  }
  else {
    uVar2 = 0xff;
    if (uVar3 != 1) {
      uVar3 = FUN_00007e3c(param_1);
      uVar2 = uVar3;
    }
    if ((uVar2 & 0xff) == 0xff) {
      if ((param_1 & 0xff) == 0) {
        if (DAT_ffff9fc9 == '\0') {
          DAT_ffff9fc9 = '\x01';
        }
        else {
          DAT_ffff9fc9 = '\0';
        }
      }
    }
    else {
      DAT_ffff9fc9 = (char)uVar2;
    }
    if (DAT_ffff9fc9 != '\0') {
      DAT_ffff9fca = cVar1 + '\f';
      return uVar3;
    }
  }
  DAT_ffff9fca = cVar1;
  return uVar3;
}


