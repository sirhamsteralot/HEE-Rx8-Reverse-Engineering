/* ROM address: 0x0005bffe; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005a7ee (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0005bffe(byte param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0x1a) && (*(&PTR_DAT_0005f734)[(uint)param_1 * 4] == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


