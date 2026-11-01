/* ROM address: 0x000495f4; body bytes: 78; decompiled */

undefined2 * FUN_000495f4(void)

{
  char cVar1;
  
  cVar1 = FUN_0003eaa4(&DAT_ffff80c6,0);
  if (((cVar1 == '\x01') && (DAT_ffffb55e == '\0')) &&
     (cVar1 = FUN_0003eaa4(&DAT_ffff8766,0), cVar1 == '\0')) {
    DAT_ffffcd06 = 0;
    return (undefined2 *)0x0;
  }
  if (0x752 < DAT_ffffccf6) {
    DAT_ffffcd06 = 0;
    return &DAT_0007c2c4;
  }
  DAT_ffffcd06 = 1;
  return (undefined2 *)&UNK_00000001;
}


