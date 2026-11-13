/* ROM address: 0x0005e7e4; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005cff0 (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005e7e4(void)

{
  uint uVar1;
  
  uVar1 = (uint)engine_running_flag_ffffaa68;
  DAT_ffffd3a4 = inferred_ram_c6ac_ffffc6ac_ffffc6ac;
  if (uVar1 == 1) {
    if (inferred_ram_c6ac_ffffc6ac_ffffc6ac < 1.374) {
      uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffd3aa,1);
      DAT_ffffd3aa = (ushort)uVar1;
      if ((0x18 < DAT_ffffd3aa) && (DAT_ffffd3aa = 0, DAT_ffffd3a8 != 0)) {
        uVar1 = (int)(short)DAT_ffffd3a8 - 1;
        DAT_ffffd3a8 = (ushort)uVar1;
      }
    }
    DAT_ffffd3af = 1;
  }
  else {
    if ((DAT_ffffd3aa != 0) && (uVar1 = (uint)(short)DAT_ffffd3a8, uVar1 != 0)) {
      DAT_ffffd3aa = 0;
      DAT_ffffd3a8 = DAT_ffffd3a8 - 1;
    }
    if (DAT_ffffd3a8 < inferred_ram_d3a0_ffffd3a0_ffffd3a0) {
      DAT_ffffd3af = 2;
    }
    else {
      uVar1 = 3;
      DAT_ffffd3af = 3;
    }
  }
  return uVar1;
}


