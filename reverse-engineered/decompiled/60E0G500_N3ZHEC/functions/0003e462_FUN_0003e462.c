/* ROM address: 0x0003e462; body bytes: 238; decompiled */

undefined1 * FUN_0003e462(void)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  cVar1 = DAT_ffffb5ab;
  DAT_ffffc694 = 30.08 < DAT_ffffbc1c;
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc692 = '\0';
    DAT_ffffc690 = '\b';
    DAT_ffffc69a = 0;
    DAT_ffffc69b = 0;
    puVar2 = (undefined1 *)0x1;
  }
  else {
    if (DAT_ffffc693 != DAT_ffffb5ab) {
      DAT_ffffc692 = '\x01';
    }
    if (DAT_ffffc692 == '\x01') {
      DAT_ffffc690 = '\b';
      puVar2 = (undefined1 *)(uint)DAT_ffffb5a4;
      if (puVar2 == (undefined1 *)0x1) {
        uVar3 = FUN_000671a4(0x4c);
        puVar2 = (undefined1 *)(uVar3 & 0xff);
        if (puVar2 == (undefined1 *)0x0) {
          DAT_ffffc69b = 1;
          DAT_ffffc69a = 0;
        }
      }
    }
    else {
      puVar2 = (undefined1 *)(uint)(byte)DAT_ffffc694;
      if ((puVar2 == (undefined1 *)0x1) && (puVar2 = &DAT_ffffc697, DAT_ffffc004 != DAT_ffffc697)) {
        if (DAT_ffffc690 != '\0') {
          DAT_ffffc690 = DAT_ffffc690 + -1;
        }
        if (DAT_ffffc690 == '\0') {
          uVar3 = FUN_000671a4(0x4c);
          puVar2 = (undefined1 *)(uVar3 & 0xff);
          if ((puVar2 == (undefined1 *)0x0) &&
             (puVar2 = (undefined1 *)(uint)DAT_ffffb5a4, puVar2 == (undefined1 *)0x1)) {
            DAT_ffffc69a = 1;
            DAT_ffffc69b = 0;
          }
        }
      }
    }
  }
  DAT_ffffc693 = cVar1;
  return puVar2;
}


