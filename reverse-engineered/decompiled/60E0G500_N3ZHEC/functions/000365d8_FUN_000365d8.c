/* ROM address: 0x000365d8; body bytes: 298; decompiled */

undefined4 * FUN_000365d8(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(uint)DAT_ffffc52f;
  if (puVar1 == (undefined4 *)&UNK_00000001) {
    puVar1 = (undefined4 *)(uint)DAT_ffffc529;
    if (puVar1 == (undefined4 *)0x0) {
      DAT_ffffc28e = 0;
    }
    else if (puVar1 == (undefined4 *)&UNK_00000006) {
      DAT_ffffc28e = 1;
      if ((DAT_ffffc52a == 0) && (DAT_ffffc52b == 0xff)) {
        DAT_ffffc291 = 1;
        puVar1 = (undefined4 *)&UNK_000000ff;
      }
      else if ((DAT_ffffc52a == 1) && (DAT_ffffc52b == 0xff)) {
        DAT_ffffc291 = 3;
        puVar1 = (undefined4 *)&UNK_00000001;
      }
      else {
        puVar1 = (undefined4 *)(uint)DAT_ffffc52a;
        if (puVar1 == (undefined4 *)&UNK_0000007f) {
          DAT_ffffc291 = 2;
        }
        else {
          DAT_ffffc28e = 6;
        }
      }
    }
    else if (puVar1 == (undefined4 *)&UNK_00000008) {
      DAT_ffffc28e = 2;
      DAT_ffffc274 = (uint)DAT_ffffc52a * 0x1000000 + (uint)DAT_ffffc52b * 0x10000 +
                     (uint)DAT_ffffc52c * 0x100 + (uint)DAT_ffffc52d;
      puVar1 = &DAT_ffffc274;
    }
    else if (puVar1 == (undefined4 *)&UNK_00000090) {
      puVar1 = (undefined4 *)(uint)DAT_ffffc52a;
      if ((((puVar1 == (undefined4 *)&UNK_00000001) || (puVar1 == (undefined4 *)&UNK_00000002)) ||
          (puVar1 == (undefined4 *)&UNK_00000003)) || (puVar1 == (undefined4 *)&UNK_00000004)) {
        DAT_ffffc28e = 4;
        DAT_ffffc25c = (uint)DAT_ffffc52a * 0x1000000 + (uint)DAT_ffffc52b * 0x10000 +
                       (uint)DAT_ffffc52c * 0x100 + (uint)DAT_ffffc52d;
        puVar1 = &DAT_ffffc25c;
      }
      else {
        DAT_ffffc28e = 6;
      }
    }
    else if (puVar1 == (undefined4 *)&UNK_000000c9) {
      DAT_ffffc28e = 3;
    }
    else {
      DAT_ffffc28e = 6;
    }
  }
  else {
    DAT_ffffc28e = 5;
  }
  DAT_ffffc52f = 0;
  return puVar1;
}


