/* ROM address: 0x0004b808; body bytes: 66; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0004a9c0 (66 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_0004b808(void)

{
  undefined1 *puVar1;
  
  puVar1 = &DAT_ffffc4c0;
  if (((DAT_ffffce52 == '\0') &&
      (puVar1 = (undefined1 *)(uint)DAT_ffffc4c0, puVar1 == (undefined1 *)0x1)) &&
     (DAT_ffffce51 == '\0')) {
    puVar1 = (undefined1 *)(int)DAT_ffffcd0c;
    if (((uint)puVar1 & 0x80) == 0) {
      DAT_ffffce44 = DAT_ffffc4c2;
    }
    else {
      puVar1 = (undefined1 *)0xf;
      DAT_ffffce44 = 0xf;
    }
    DAT_ffffce51 = '\x01';
  }
  DAT_ffffce52 = DAT_ffffc4c0;
  return puVar1;
}


