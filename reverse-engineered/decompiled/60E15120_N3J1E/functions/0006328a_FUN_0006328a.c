/* ROM address: 0x0006328a; body bytes: 268; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00061b7a (268 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0006328a(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    DAT_ffffd79e = 0;
    DAT_ffffd7a0 = dtc_master_current_index_ffff8900._0_2_;
  }
  else if (param_1 == '\x01') {
    DAT_ffffd79e = DAT_ffffd79e + 1;
  }
  if ((DAT_ffffd79e == dtc_master_current_index_ffff8900._0_2_) || (DAT_ffffd79e == DAT_ffffd7a0)) {
    DAT_ffffd79e = DAT_ffffd79e + 1;
  }
  if (DAT_ffffd79e < 0x15) {
    if ((&dtc_master_table_21_ffff87b0)[(uint)DAT_ffffd79e * 8] == -1) {
      uVar1 = 0;
    }
    else {
      DAT_ffffd790 = (&dtc_master_table_21_ffff87b0)[(uint)DAT_ffffd79e * 8];
      DAT_ffffd792 = (&DAT_ffff87b2)[(uint)DAT_ffffd79e * 8];
      DAT_ffffd794 = (&DAT_ffff87b4)[(uint)DAT_ffffd79e * 8];
      DAT_ffffd796 = (&DAT_ffff87b6)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd797 = (&DAT_ffff87b7)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd798 = (&DAT_ffff87b9)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd799 = (&DAT_ffff87b8)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd79a = (&DAT_ffff87ba)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd79b = (&DAT_ffff87bb)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd79c = (&DAT_ffff87bc)[(uint)DAT_ffffd79e * 0x10];
      DAT_ffffd79d = (&DAT_ffff87bd)[(uint)DAT_ffffd79e * 0x10];
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


