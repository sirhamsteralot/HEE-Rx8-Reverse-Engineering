/* ROM address: 0x00050c8c; body bytes: 220; decompiled */

undefined2 * FUN_00050c8c(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffd1c5 == '\x01') {
    puVar1 = &DAT_ffffd0a2;
    DAT_ffffd08c = 0.0;
    DAT_ffffd090 = 0.0;
    DAT_ffffd0a0 = 0;
    DAT_ffffd0a2 = 0;
    DAT_ffffd0a4 = 0;
    DAT_ffffd0a6 = 0;
  }
  else {
    puVar1 = (undefined2 *)(uint)DAT_ffffd0ab;
    if (puVar1 == (undefined2 *)0x1) {
      puVar1 = (undefined2 *)(int)(char)DAT_ffffd0d3;
      if (puVar1 == (undefined2 *)0x0) {
        DAT_ffffd08c = DAT_ffffcfe4 - 0.00035;
        DAT_ffffd090 = DAT_ffffcfe4 - 0.0007;
      }
      if (((DAT_ffffd0a0 == 0) && (DAT_ffffd0b0 < DAT_ffffd08c)) && (DAT_ffffd08c <= DAT_ffffcfe0))
      {
        DAT_ffffd0a0 = DAT_ffffcfaa;
      }
      if (((DAT_ffffd0a6 == 0) && (DAT_ffffd0b0 < DAT_ffffd090)) && (DAT_ffffd090 <= DAT_ffffcfe0))
      {
        DAT_ffffd0a6 = DAT_ffffcfaa;
      }
      if ((DAT_ffffd0b0 < DAT_ffffcfe4) && (DAT_ffffcfe4 <= DAT_ffffcfe0)) {
        DAT_ffffd0a2 = DAT_ffffcfaa;
        puVar1 = (undefined2 *)0x4e;
        if (DAT_ffffcfaa < 0x4e) {
          DAT_ffffd0a4 = 0;
        }
        else {
          DAT_ffffd0a4 = DAT_ffffcfaa - 0x4e;
        }
      }
    }
  }
  DAT_ffffd0b0 = DAT_ffffcfe0;
  DAT_ffffd0d3 = DAT_ffffd0ab;
  return puVar1;
}


