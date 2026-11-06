/* ROM address: 0x0005d9d8; body bytes: 304; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005c1c8 (304 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005d9d8(void)

{
  uint uVar1;
  undefined1 *puVar2;
  ushort uVar3;
  undefined1 local_9c [132];
  
  uVar1 = (uint)DAT_ffffd375;
  if (uVar1 == 1) {
    if (DAT_ffffd376 == '\x01') {
      ref_udsServiceResponse(0x3b,local_9c,(int)(short)DAT_ffffd370);
      e2ram_shadow_byte_write
                ((&DAT_0005f6dd)[(uint)DAT_ffffd373 * 0xc],local_9c,
                 (int)(char)(&DAT_0005f6de)[(uint)DAT_ffffd373 * 0xc]);
      DAT_ffffd376 = '\0';
      uVar1 = FUN_000378dc((&DAT_0005f6dd)[(uint)DAT_ffffd373 * 0xc],
                           (int)(char)(&DAT_0005f6de)[(uint)DAT_ffffd373 * 0xc],2);
    }
    else {
      if (DAT_ffffd374 != '\x01') {
        if (DAT_ffffc28c == '\x01') {
          DAT_ffffd375 = 0;
          puVar2 = local_9c;
          for (uVar3 = 0; uVar3 < DAT_ffffd370; uVar3 = uVar3 + 1) {
            *puVar2 = 0xff;
            puVar2 = puVar2 + 1;
          }
          e2ram_shadow_byte_write
                    ((&DAT_0005f6dd)[(uint)DAT_ffffd373 * 0xc],local_9c,
                     (int)(char)(&DAT_0005f6de)[(uint)DAT_ffffd373 * 0xc]);
          uVar1 = FUN_0005dc06();
          return uVar1;
        }
        if (DAT_ffffc289 != 1) {
          return (uint)DAT_ffffc289;
        }
        DAT_ffffd375 = 0;
        uVar1 = FUN_0005dbda();
        return uVar1;
      }
      uVar1 = FUN_000378dc((&DAT_0005f6dd)[(uint)DAT_ffffd373 * 0xc],
                           (int)(char)(&DAT_0005f6de)[(uint)DAT_ffffd373 * 0xc],2);
    }
    DAT_ffffd374 = (char)uVar1;
  }
  return uVar1;
}


