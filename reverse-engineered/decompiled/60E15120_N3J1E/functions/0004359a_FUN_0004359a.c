/* ROM address: 0x0004359a; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00042dce (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0004359a(void)

{
  uint uVar1;
  undefined4 extraout_fr0;
  
  uVar1 = (uint)DAT_ffffca44;
  if (uVar1 == 1) {
    if (DAT_ffffc9b0 <= 0.0) {
      DAT_ffffc9ac = 0;
    }
    else {
      uVar1 = ref_checkFloatValidity_();
      DAT_ffffc9ac = extraout_fr0;
    }
  }
  return uVar1;
}


