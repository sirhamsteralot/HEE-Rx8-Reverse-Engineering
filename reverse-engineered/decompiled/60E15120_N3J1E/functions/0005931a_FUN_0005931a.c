/* ROM address: 0x0005931a; body bytes: 110; decompiled */

undefined1 * FUN_0005931a(char param_1)

{
  undefined1 *puVar1;
  
  DAT_ffffd250 = param_1;
  if (param_1 == '\x02') {
    DAT_ffffd254 = '\x01';
    DAT_ffffd261 = 1;
  }
  else if (param_1 == -0x7e) {
    DAT_ffffd255 = '\x01';
    DAT_ffffd266 = 1;
  }
  else if (param_1 == '\x0f') {
    DAT_ffffd256 = 1;
    DAT_ffffd26f = 1;
  }
  if (((DAT_ffffd254 == '\x01') || (DAT_ffffd255 == '\x01')) ||
     (puVar1 = (undefined1 *)(uint)DAT_ffffd256, puVar1 == (undefined1 *)0x1)) {
    puVar1 = &DAT_ffffd25c;
    DAT_ffffd25a = 1;
    DAT_ffffd25b = 0;
    DAT_ffffd25c = 1;
  }
  return puVar1;
}


