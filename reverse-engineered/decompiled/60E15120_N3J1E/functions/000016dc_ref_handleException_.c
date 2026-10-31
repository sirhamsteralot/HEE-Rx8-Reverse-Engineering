/* ROM address: 0x000016dc; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000016dc (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * ref_handleException_(undefined1 *param_1)

{
  DAT_ffffdfb3 = param_1 == (undefined1 *)((int)&vector_Poweron_Reset + 1);
  DAT_ffffdfb2 = 0;
  DAT_ffffdfb4._0_1_ = 0;
  DAT_ffffdfb4._1_1_ = 0;
  if (DAT_ffffdfb3) {
    param_1 = &DAT_ffffdfb1;
  }
  DAT_ffffdfb1 = DAT_ffffdfb3;
  DAT_ffffdfb0 = DAT_ffffdfb3;
  return param_1;
}


