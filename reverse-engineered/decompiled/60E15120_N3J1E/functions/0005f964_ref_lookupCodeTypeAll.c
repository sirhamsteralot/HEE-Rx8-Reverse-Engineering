/* ROM address: 0x0005f964; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e270 (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_lookupCodeTypeAll(short param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; ((&DAT_0007e560)[uVar1 & 0xffff] != param_1 && ((uVar1 & 0xffff) < 0x8c));
      uVar1 = uVar1 + 1) {
  }
  return uVar1;
}


