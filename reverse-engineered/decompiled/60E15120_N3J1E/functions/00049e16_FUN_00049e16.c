/* ROM address: 0x00049e16; body bytes: 92; decompiled */

undefined2 * FUN_00049e16(void)

{
  undefined2 *puVar1;
  ushort uVar2;
  
  if (DAT_ffffcd40 < 0x3fff) {
    uVar2 = DAT_ffffcd40 << 2;
  }
  else {
    uVar2 = 0xffff;
  }
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcd44 = 0;
    DAT_ffffcd45 = 0;
    puVar1 = (undefined2 *)0x1;
  }
  else if (uVar2 < 10) {
    DAT_ffffcd44 = 1;
    puVar1 = (undefined2 *)0x5;
    DAT_ffffcd42 = 5;
  }
  else {
    puVar1 = &DAT_ffffcd42;
    if (4 < DAT_ffffcd42) {
      DAT_ffffcd45 = 1;
    }
  }
  return puVar1;
}


