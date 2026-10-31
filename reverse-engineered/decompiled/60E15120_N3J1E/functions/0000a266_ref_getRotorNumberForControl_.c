/* ROM address: 0x0000a266; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000a266 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_getRotorNumberForControl_(int param_1)

{
  undefined4 uVar1;
  
  param_1 = param_1 * 0xc;
  uVar1 = *(undefined4 *)(&DAT_ffffa170 + (uint)(byte)(&DAT_ffffa179)[param_1] * 4 + param_1);
  (&DAT_ffffa179)[param_1] = (&DAT_ffffa179)[param_1] + 1;
  if (1 < (byte)(&DAT_ffffa179)[param_1]) {
    (&DAT_ffffa179)[param_1] = 0;
  }
  return uVar1;
}


