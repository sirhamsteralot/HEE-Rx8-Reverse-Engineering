/* ROM address: 0x0003b02c; body bytes: 208; decompiled */

undefined1 * FUN_0003b02c(void)

{
  undefined1 *puVar1;
  
  DAT_ffffc584 = 0xfa < DAT_ffffc57c;
  DAT_ffffc585 = 0xfa < DAT_ffffc57d;
  DAT_ffffc586 = 0xfa < DAT_ffffc57e;
  if (((0xfa < DAT_ffffc57d) || (DAT_ffffc584)) || (DAT_ffffd1c5 == '\x01')) {
    DAT_ffffc588 = 0;
  }
  else if ((0xfa < DAT_ffffc57f) || (DAT_ffffc587 == 1)) {
    DAT_ffffc588 = 1;
  }
  if (((0xfa < DAT_ffffc57e) || (DAT_ffffc584)) || (DAT_ffffd1c5 == '\x01')) {
    puVar1 = (undefined1 *)((int)&vector_Poweron_Reset + 1);
    DAT_ffffc589 = 0;
  }
  else {
    puVar1 = &DAT_0007abe1;
    if ((0xfa < DAT_ffffc580) ||
       (puVar1 = (undefined1 *)(uint)DAT_ffffc587,
       puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) {
      DAT_ffffc589 = 1;
    }
  }
  return puVar1;
}


