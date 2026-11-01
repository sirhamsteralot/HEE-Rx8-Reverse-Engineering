/* ROM address: 0x00019840; body bytes: 176; decompiled */

undefined1 * FUN_00019840(void)

{
  undefined1 *puVar1;
  
  if (DAT_ffffbc1c < 3.0) {
    if (DAT_ffffbc1c < 1.0) {
      DAT_ffffaa02 = '\0';
    }
  }
  else {
    DAT_ffffaa02 = '\x01';
  }
  if (DAT_ffffaa10 < 40.0) {
    if (DAT_ffffaa10 < 37.0) {
      DAT_ffffaa03 = '\0';
    }
  }
  else {
    DAT_ffffaa03 = '\x01';
  }
  puVar1 = (undefined1 *)(uint)DAT_ffffb5aa;
  if (((puVar1 == (undefined1 *)0x1) ||
      ((DAT_ffffb5a4 == '\0' && (puVar1 = &DAT_ffffccd1, 2 < DAT_ffffccd1)))) &&
     ((DAT_ffffaa02 == '\0' &&
      (((DAT_ffffa401 == '\0' || (puVar1 = &DAT_ffffa402, DAT_ffffa402 == '\0')) &&
       ((puVar1 = (undefined1 *)0x1, DAT_ffffaa03 == '\x01' ||
        (puVar1 = (undefined1 *)(uint)DAT_ffffc656, puVar1 == (undefined1 *)0x1)))))))) {
    DAT_ffffa9ef = 1;
  }
  else {
    DAT_ffffa9ef = 0;
  }
  return puVar1;
}


