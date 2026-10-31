/* ROM address: 0x00008d86; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00008d86 (40 bytes). Names prefixed ref_
   are inherited hypotheses. */

void ref_initSparkOutput(float param_1,byte param_2)

{
  int iVar1;
  
  param_1 = param_1 - 30.0;
  if (param_1 < 0.0) {
    param_1 = param_1 + 720.0;
  }
  iVar1 = (uint)param_2 * 8;
  *(float *)(&DAT_ffffa0d8 + iVar1) = param_1;
  (&DAT_ffffa0dd)[iVar1] = 0;
  (&DAT_ffffa0dc)[iVar1] = 1;
  return;
}


