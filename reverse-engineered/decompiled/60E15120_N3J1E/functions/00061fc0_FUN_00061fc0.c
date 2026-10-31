/* ROM address: 0x00061fc0; body bytes: 128; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000608b0 (128 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00061fc0(undefined4 param_1,char param_2)

{
  byte bVar1;
  undefined1 uVar2;
  
  uVar2 = 8;
  bVar1 = FUN_00062df8();
  if (((bVar1 == 0) || (bVar1 == 0x50)) || ((bVar1 != 0 && (bVar1 < 0x40)))) {
    if (param_2 == '\x03') {
      if ((DAT_ffffd6c3 & 0x80) == 0x80) {
        uVar2 = 6;
      }
      else {
        uVar2 = 8;
      }
    }
    else if (param_2 == '\x01') {
      uVar2 = 7;
    }
  }
  else if ((bVar1 & 0x80) == 0x80) {
    uVar2 = 8;
  }
  DAT_ffffd6c2 = uVar2;
  return;
}


