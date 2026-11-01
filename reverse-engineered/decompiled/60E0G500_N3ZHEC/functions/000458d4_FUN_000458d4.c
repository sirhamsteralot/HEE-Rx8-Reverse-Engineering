/* ROM address: 0x000458d4; body bytes: 72; decompiled */

uint FUN_000458d4(void)

{
  uint uVar1;
  
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcbf0 = 1000;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffb70c;
    if ((uVar1 == 1) &&
       (uVar1 = FUN_0000213c(DAT_ffffc12c,DAT_ffffb5b8,&DAT_0006bd74),
       (uVar1 & 0xffff) < (uint)DAT_ffffcbf0)) {
      DAT_ffffcbf0 = (ushort)uVar1;
    }
  }
  return uVar1;
}


