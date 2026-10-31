/* ROM address: 0x0005496e; body bytes: 38; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00052a5a (38 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_udsErrorResponse(undefined4 param_1,undefined1 param_2)

{
  undefined1 local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  
  local_c = 0x7f;
  uStack_b = (undefined1)param_1;
  uStack_a = param_2;
  ref_setupForUdsResponse_(param_1,&local_c,3);
  return 3;
}


