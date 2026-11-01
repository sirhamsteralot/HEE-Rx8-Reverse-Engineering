/* ROM address: 0x0004f586; body bytes: 104; decompiled */

undefined * FUN_0004f586(void)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = (undefined *)(uint)DAT_ffffcff9;
  if (puVar2 == &UNK_00000001) {
    if (DAT_ffffd00e == '\0') {
      DAT_ffffcff6 = 1;
      puVar1 = &UNK_00000001;
    }
    else {
      puVar1 = (undefined *)0x0;
      if (DAT_ffffcfe8 == '\0') {
        DAT_ffffcff6 = 0;
      }
    }
  }
  else {
    DAT_ffffcff6 = 0;
    puVar1 = puVar2;
  }
  if (puVar2 == (undefined *)0x0) {
    if (DAT_ffffd00e == '\x01') {
      DAT_ffffcff7 = 1;
      puVar1 = &UNK_00000001;
    }
    else {
      puVar1 = &DAT_0007d0c8;
      if (DAT_ffffcfea == '\0') {
        DAT_ffffcff7 = 0;
      }
    }
  }
  else {
    DAT_ffffcff7 = 0;
  }
  DAT_ffffd00e = DAT_ffffcff9;
  return puVar1;
}


