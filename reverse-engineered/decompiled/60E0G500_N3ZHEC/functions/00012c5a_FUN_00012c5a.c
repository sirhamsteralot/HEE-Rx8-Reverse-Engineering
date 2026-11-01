/* ROM address: 0x00012c5a; body bytes: 108; decompiled */

undefined1 * FUN_00012c5a(void)

{
  undefined1 *puVar1;
  
  puVar1 = &DAT_ffffaada;
  if (DAT_ffffaada == '\0') {
    DAT_ffffa68e = '\0';
  }
  else if ((((DAT_ffffa6a7 == '\x01') && (puVar1 = (undefined1 *)0x0, DAT_ffffa444 == '\0')) ||
           ((puVar1 = (undefined1 *)(uint)DAT_ffffa6a8, puVar1 == (undefined1 *)0x1 &&
            (DAT_ffffa445 == '\0')))) && (DAT_ffffb5aa == '\0')) {
    puVar1 = (undefined1 *)0x0;
    DAT_ffffa68e = '\0';
  }
  else if (DAT_ffffa68e != '\0') {
    DAT_ffffa68e = DAT_ffffa68e + -1;
  }
  DAT_ffffa6a7 = DAT_ffffa444;
  DAT_ffffa6a8 = DAT_ffffa445;
  return puVar1;
}


