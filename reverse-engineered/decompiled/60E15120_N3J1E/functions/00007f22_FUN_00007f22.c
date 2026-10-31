/* ROM address: 0x00007f22; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00007f22 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00007f22(void)

{
  undefined1 *puVar1;
  
  DAT_ffff9fce = 0;
  puVar1 = (undefined1 *)(uint)DAT_ffff9fa3;
  if (puVar1 != (undefined1 *)0x2) {
    puVar1 = &DAT_ffff9f8c;
    DAT_ffff9f8c = 0;
  }
  ATUII_TSR10_W = 0xe;
  return puVar1;
}


