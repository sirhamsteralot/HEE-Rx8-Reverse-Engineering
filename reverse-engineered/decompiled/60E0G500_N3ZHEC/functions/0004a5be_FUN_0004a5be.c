/* ROM address: 0x0004a5be; body bytes: 92; decompiled */

undefined2 * FUN_0004a5be(void)

{
  undefined2 *puVar1;
  ushort uVar2;
  
  if (DAT_ffffcd80 < 0x3fff) {
    uVar2 = DAT_ffffcd80 << 2;
  }
  else {
    uVar2 = 0xffff;
  }
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcd84 = 0;
    DAT_ffffcd85 = 0;
    puVar1 = (undefined2 *)0x1;
  }
  else if (uVar2 < 10) {
    DAT_ffffcd84 = 1;
    puVar1 = (undefined2 *)0x5;
    DAT_ffffcd82 = 5;
  }
  else {
    puVar1 = &DAT_ffffcd82;
    if (4 < DAT_ffffcd82) {
      DAT_ffffcd85 = 1;
    }
  }
  return puVar1;
}


