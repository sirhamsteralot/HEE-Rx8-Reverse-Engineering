/* ROM address: 0x00051430; body bytes: 220; decompiled */

undefined2 * FUN_00051430(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffd201 == '\x01') {
    puVar1 = &DAT_ffffd0de;
    DAT_ffffd0c8 = 0.0;
    DAT_ffffd0cc = 0.0;
    DAT_ffffd0dc = 0;
    DAT_ffffd0de = 0;
    DAT_ffffd0e0 = 0;
    DAT_ffffd0e2 = 0;
  }
  else {
    puVar1 = (undefined2 *)(uint)DAT_ffffd0e7;
    if (puVar1 == (undefined2 *)0x1) {
      puVar1 = (undefined2 *)(int)(char)DAT_ffffd10f;
      if (puVar1 == (undefined2 *)0x0) {
        DAT_ffffd0c8 = DAT_ffffd020 - 0.00035;
        DAT_ffffd0cc = DAT_ffffd020 - 0.0007;
      }
      if (((DAT_ffffd0dc == 0) && (DAT_ffffd0ec < DAT_ffffd0c8)) && (DAT_ffffd0c8 <= DAT_ffffd01c))
      {
        DAT_ffffd0dc = DAT_ffffcfe6;
      }
      if (((DAT_ffffd0e2 == 0) && (DAT_ffffd0ec < DAT_ffffd0cc)) && (DAT_ffffd0cc <= DAT_ffffd01c))
      {
        DAT_ffffd0e2 = DAT_ffffcfe6;
      }
      if ((DAT_ffffd0ec < DAT_ffffd020) && (DAT_ffffd020 <= DAT_ffffd01c)) {
        DAT_ffffd0de = DAT_ffffcfe6;
        puVar1 = (undefined2 *)0x4e;
        if (DAT_ffffcfe6 < 0x4e) {
          DAT_ffffd0e0 = 0;
        }
        else {
          DAT_ffffd0e0 = DAT_ffffcfe6 - 0x4e;
        }
      }
    }
  }
  DAT_ffffd0ec = DAT_ffffd01c;
  DAT_ffffd10f = DAT_ffffd0e7;
  return puVar1;
}


