/* ROM address: 0x00017b34; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00018724 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00017b34(void)

{
  undefined1 *puVar1;
  undefined4 local_c [2];
  
  if (DAT_ffffa8ff == '\x01') {
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8054,1);
    local_c[0] = 0;
    ref_osTaskScheduler(0,3,local_c);
    DAT_ffffa8ff = '\x02';
  }
  puVar1 = &DAT_ffffa8dd;
  if (DAT_ffffa8f4 == DAT_ffffa8dd) {
    DAT_ffffa8fa = 0x30;
    DAT_ffffa8ff = '\x01';
  }
  else {
    puVar1 = (undefined1 *)FUN_0001791a((int)DAT_ffffa903);
  }
  return puVar1;
}


