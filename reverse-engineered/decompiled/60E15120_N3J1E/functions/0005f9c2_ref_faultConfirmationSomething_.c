/* ROM address: 0x0005f9c2; body bytes: 20; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e2ce (20 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool ref_faultConfirmationSomething_(uint param_1,ushort param_2)

{
  return (param_2 & *(ushort *)(&DAT_0007e81c + (param_1 & 0xffff) * 2)) == 0;
}


