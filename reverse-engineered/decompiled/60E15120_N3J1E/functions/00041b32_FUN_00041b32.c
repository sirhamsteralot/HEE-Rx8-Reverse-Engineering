/* ROM address: 0x00041b32; body bytes: 116; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00041366 (116 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00041b32(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc94a = 0;
    DAT_ffffc94d = 0;
    puVar1 = &DAT_ffffc96a;
    DAT_ffffc96a = 0;
  }
  else {
    if ((DAT_ffffc968 == '\x01') && (DAT_ffffc94f == '\0')) {
      DAT_ffffc94a = 0x494;
    }
    else if (DAT_ffffc94a != 0) {
      DAT_ffffc94a = DAT_ffffc94a + -1;
    }
    puVar1 = (undefined1 *)(uint)DAT_ffffc94c;
    if ((puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) && (DAT_ffffc94a == 0)) {
      DAT_ffffc94d = 1;
      DAT_ffffc96a = 1;
    }
    else {
      DAT_ffffc94d = 0;
    }
  }
  DAT_ffffc968 = DAT_ffffc94f;
  return puVar1;
}


