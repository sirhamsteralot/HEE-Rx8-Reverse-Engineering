/* ROM address: 0x0005e17c; body bytes: 304; decompiled */

uint FUN_0005e17c(void)

{
  uint uVar1;
  undefined1 *puVar2;
  ushort uVar3;
  undefined1 local_9c [132];
  
  uVar1 = (uint)DAT_ffffd3b1;
  if (uVar1 == 1) {
    if (DAT_ffffd3b2 == '\x01') {
      FUN_00068928(0x3b,local_9c,(int)(short)DAT_ffffd3ac);
      FUN_00038e8c((&DAT_0005fe81)[(uint)DAT_ffffd3af * 0xc],local_9c,
                   (int)(char)(&DAT_0005fe82)[(uint)DAT_ffffd3af * 0xc]);
      DAT_ffffd3b2 = '\0';
      uVar1 = FUN_000388c4((&DAT_0005fe81)[(uint)DAT_ffffd3af * 0xc],
                           (int)(char)(&DAT_0005fe82)[(uint)DAT_ffffd3af * 0xc],2);
    }
    else {
      if (DAT_ffffd3b0 != '\x01') {
        if (DAT_ffffc2fc == '\x01') {
          DAT_ffffd3b1 = 0;
          puVar2 = local_9c;
          for (uVar3 = 0; uVar3 < DAT_ffffd3ac; uVar3 = uVar3 + 1) {
            *puVar2 = 0xff;
            puVar2 = puVar2 + 1;
          }
          FUN_00038e8c((&DAT_0005fe81)[(uint)DAT_ffffd3af * 0xc],local_9c,
                       (int)(char)(&DAT_0005fe82)[(uint)DAT_ffffd3af * 0xc]);
          uVar1 = FUN_0005e3aa();
          return uVar1;
        }
        if (DAT_ffffc2f9 != 1) {
          return (uint)DAT_ffffc2f9;
        }
        DAT_ffffd3b1 = 0;
        uVar1 = FUN_0005e37e();
        return uVar1;
      }
      uVar1 = FUN_000388c4((&DAT_0005fe81)[(uint)DAT_ffffd3af * 0xc],
                           (int)(char)(&DAT_0005fe82)[(uint)DAT_ffffd3af * 0xc],2);
    }
    DAT_ffffd3b0 = (char)uVar1;
  }
  return uVar1;
}


