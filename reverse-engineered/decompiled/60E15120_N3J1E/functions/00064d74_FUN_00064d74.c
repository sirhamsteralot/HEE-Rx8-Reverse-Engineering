/* ROM address: 0x00064d74; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00063664 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00064d74(byte param_1,uint param_2)

{
  if ((uint)param_1 != (param_2 & 0xff)) {
    FUN_00062dd8(param_2);
    FUN_000621d8((int)(char)param_1,param_2);
    return;
  }
  return;
}


