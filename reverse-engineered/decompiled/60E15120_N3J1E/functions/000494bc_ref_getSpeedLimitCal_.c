/* ROM address: 0x000494bc; body bytes: 188; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000483c0 (188 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_getSpeedLimitCal_(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = FUN_00049584();
  uVar2 = 0x80;
  DAT_ffffcd0c = uVar2;
  if (cVar1 != '\n') {
    if (cVar1 == '\x01') {
      DAT_ffffcd0c = 0x40;
    }
    else if (cVar1 == '\x02') {
      DAT_ffffcd0c = 0x20;
    }
    else if (cVar1 == '\x06') {
      DAT_ffffcd0c = 0x10;
    }
    else if (cVar1 == -0xf) {
      DAT_ffffcd0c = 8;
    }
    else if (cVar1 == -0x10) {
      DAT_ffffcd0c = 4;
    }
    else {
      DAT_ffffcd0c = 0;
      if (cVar1 == '\x05') {
        DAT_ffffcd0c = 2;
      }
    }
  }
  cVar1 = FUN_000495e0();
  DAT_ffffcd0d = uVar2;
  if ((cVar1 != '\0') && (DAT_ffffcd0d = 0, cVar1 == '\x01')) {
    DAT_ffffcd0d = 0x40;
  }
  cVar1 = FUN_0004963e();
  DAT_ffffcd0e = uVar2;
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      DAT_ffffcd0e = 0x40;
    }
    else {
      DAT_ffffcd0e = 0;
      if (cVar1 == '\x02') {
        DAT_ffffcd0e = 0x20;
      }
    }
  }
  FUN_000496c6();
  return;
}


