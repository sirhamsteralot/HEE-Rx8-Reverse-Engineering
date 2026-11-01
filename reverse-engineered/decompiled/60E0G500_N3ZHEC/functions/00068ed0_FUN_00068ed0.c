/* ROM address: 0x00068ed0; body bytes: 56; decompiled */

undefined4 isotp_consecutive_frame_check(void)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((DAT_ffffde27 == '\x04') && (DAT_ffffde29 == (DAT_ffffde04 & 0xf))) {
    if ((DAT_ffffde04 & 0xf) < 0xf) {
      DAT_ffffde29 = DAT_ffffde29 + 1;
    }
    else {
      DAT_ffffde29 = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


