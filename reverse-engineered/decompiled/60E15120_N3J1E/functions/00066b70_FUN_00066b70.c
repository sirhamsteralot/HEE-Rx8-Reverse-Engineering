/* ROM address: 0x00066b70; body bytes: 30; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065460 (30 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_00066b70(uint param_1)

{
  return (&DAT_ffff8d54)[(uint)*(ushort *)(&DAT_0007df42 + (param_1 & 0xffff) * 2) * 2] != '\0';
}


