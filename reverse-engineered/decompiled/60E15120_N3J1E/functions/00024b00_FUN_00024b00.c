/* ROM address: 0x00024b00; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00025388 (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00024b00(byte param_1,byte *param_2,byte *param_3)

{
  *param_3 = ~(*param_2 ^ param_1) & param_1 | *param_3 & (*param_2 ^ param_1);
  *param_2 = param_1;
  return;
}


