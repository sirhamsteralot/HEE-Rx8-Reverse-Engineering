/* ROM address: 0x00004b64; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00004b64 (24 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00004b64(byte *param_1,byte param_2,short param_3)

{
  if (param_3 == 0) {
    *param_1 = *param_1 & ~param_2;
    return;
  }
  *param_1 = *param_1 | param_2;
  return;
}


