/* ROM address: 0x0005dde8; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005c5d8 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_setDiagMode85Bool2(uint param_1)

{
  param_1 = param_1 & 0xff;
  if (param_1 == 1) {
    param_1 = dtc_set_eval_enable(1);
    DAT_ffffd378 = 0;
  }
  else if (param_1 == 2) {
    param_1 = dtc_set_eval_enable(0);
    DAT_ffffd378 = 1;
  }
  return param_1;
}


