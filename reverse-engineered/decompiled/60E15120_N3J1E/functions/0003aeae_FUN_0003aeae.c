/* ROM address: 0x0003aeae; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003b2e2 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 * FUN_0003aeae(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x1;
  if ((((DAT_ffffd1c5 == '\x01') || (puVar1 = (undefined4 *)0x1, DAT_ffffd1ad == '\x01')) ||
      (puVar1 = &DAT_0003af84, DAT_ffffb2f0 < 8.0)) || (puVar1 = &DAT_0003af84, 92.0 < DAT_ffffb2f0)
     ) {
    DAT_ffffc587 = 0;
  }
  else {
    puVar1 = (undefined4 *)(uint)DAT_ffffc583;
    if (puVar1 != (undefined4 *)0x1) {
      if (DAT_ffffc57c == -1) {
        DAT_ffffc587 = 0;
        return puVar1;
      }
      DAT_ffffc57c = DAT_ffffc57c + '\x01';
      DAT_ffffc587 = 0;
      return puVar1;
    }
    DAT_ffffc587 = 1;
    puVar1 = (undefined4 *)((int)&vector_Poweron_Reset + 1);
  }
  DAT_ffffc57c = 0;
  return puVar1;
}


