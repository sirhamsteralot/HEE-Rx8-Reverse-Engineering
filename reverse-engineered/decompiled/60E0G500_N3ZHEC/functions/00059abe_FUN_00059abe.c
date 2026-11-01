/* ROM address: 0x00059abe; body bytes: 110; decompiled */

undefined1 * FUN_00059abe(char param_1)

{
  undefined1 *puVar1;
  
  DAT_ffffd28c = param_1;
  if (param_1 == '\x02') {
    DAT_ffffd290 = '\x01';
    DAT_ffffd29d = 1;
  }
  else if (param_1 == -0x7e) {
    DAT_ffffd291 = '\x01';
    DAT_ffffd2a2 = 1;
  }
  else if (param_1 == '\x0f') {
    DAT_ffffd292 = 1;
    DAT_ffffd2ab = 1;
  }
  if (((DAT_ffffd290 == '\x01') || (DAT_ffffd291 == '\x01')) ||
     (puVar1 = (undefined1 *)(uint)DAT_ffffd292, puVar1 == (undefined1 *)0x1)) {
    puVar1 = &DAT_ffffd298;
    DAT_ffffd296 = 1;
    DAT_ffffd297 = 0;
    DAT_ffffd298 = 1;
  }
  return puVar1;
}


