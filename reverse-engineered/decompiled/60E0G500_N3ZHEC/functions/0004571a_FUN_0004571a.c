/* ROM address: 0x0004571a; body bytes: 152; decompiled */

uint FUN_0004571a(void)

{
  uint uVar1;
  undefined2 *puVar2;
  uint in_r7;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcbe4 = 0;
    DAT_ffffcbe6 = 0;
  }
  puVar2 = &DAT_ffffb6d0;
  if ((DAT_ffffb6d0 & 1) == 0) {
    puVar2 = (undefined2 *)(int)DAT_ffffba91;
    in_r7 = 1;
  }
  else if ((DAT_ffffb6d0 & 1) == 1) {
    puVar2 = (undefined2 *)(int)DAT_ffffba90;
    in_r7 = 0;
  }
  uVar1 = (uint)puVar2 & 0xff;
  if (uVar1 == 1) {
    if ((DAT_ffffcbf8 * DAT_ffffbaac < DAT_ffffbab0) || (DAT_ffffcbfc * DAT_ffffbaac < DAT_ffffbaa8)
       ) {
      uVar1 = in_r7 & 0xffff;
      (&DAT_ffffba90)[uVar1] = 0;
    }
    else if (DAT_ffffd201 == '\0') {
      DAT_ffffcbe4 = FUN_00002460((int)DAT_ffffcbe4,1);
      uVar1 = FUN_00002460((int)DAT_ffffcbe6,1);
      DAT_ffffcbe6 = (short)uVar1;
    }
  }
  return uVar1;
}


