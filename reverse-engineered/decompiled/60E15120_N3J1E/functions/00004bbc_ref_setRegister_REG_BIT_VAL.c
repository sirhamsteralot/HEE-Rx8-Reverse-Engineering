/* ROM address: 0x00004bbc; body bytes: 24; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004bbc (16 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_setRegister_REG_BIT_VAL(ushort *param_1,ushort param_2,short param_3)

{
  if (param_3 == 0) {
    *param_1 = *param_1 & ~param_2;
    return;
  }
  *param_1 = *param_1 | param_2;
  return;
}


