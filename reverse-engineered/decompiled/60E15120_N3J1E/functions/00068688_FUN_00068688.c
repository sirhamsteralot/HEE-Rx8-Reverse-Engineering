/* ROM address: 0x00068688; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066f78 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00068688(void)

{
  uint uVar1;
  
  uVar1 = (int)uds_rx_buffer_ffffddc8 & 0xf;
  DAT_ffffddf0 = (undefined1)uVar1;
  if (uVar1 == 0) {
    FUN_00068c58(4);
    DAT_ffffdde4 = 0;
    DAT_ffffddf1 = DAT_ffffddc9;
    DAT_ffffddf2 = DAT_ffffddca;
    DAT_ffffdde1 = 9;
    uVar1 = FUN_00068bc6(2,DAT_ffffddca);
    return uVar1;
  }
  if (uVar1 == 1) {
    FUN_00068c58(4);
    DAT_ffffdde1 = 7;
    uVar1 = FUN_00068bc6(4,0x4b);
    return uVar1;
  }
  return uVar1;
}


