/* ROM address: 0x0004ea14; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004c4d0 (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004ea14(void)

{
  undefined2 *puVar1;
  uint uVar2;
  
  if (DAT_ffffcfc6 == '\x01') {
    DAT_ffffcfa6 = 0x17;
    puVar1 = &DAT_0007d672;
  }
  else {
    if (DAT_ffffd0f2 != '\x01') {
      if (DAT_ffffcf85 != '\0') {
        DAT_ffffcfa6 = 0;
        DAT_ffffcfa8 = 0x18;
      }
      if (DAT_ffffcfbf == 1) {
        DAT_ffffcfb0 = 0x4b;
      }
      else if (DAT_ffffcf85 != '\0') {
        DAT_ffffcfb0 = 0x46;
      }
      return (uint)DAT_ffffcfbf;
    }
    DAT_ffffcfa6 = 0;
    puVar1 = &DAT_0007d674;
  }
  DAT_ffffcfa8 = *puVar1;
  uVar2 = FUN_0004ea5e();
  return uVar2;
}


