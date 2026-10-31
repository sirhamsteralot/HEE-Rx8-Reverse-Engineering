/* ROM address: 0x000533fc; body bytes: 106; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00051380 (106 bytes). Names prefixed ref_
   are inherited hypotheses. */

ushort FUN_000533fc(void)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = rx8_add_u16_saturate((int)DAT_ffffcfa8,0x10);
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffd180 = 0;
    DAT_ffffd181 = 0;
    DAT_ffffd168 = 0;
    DAT_ffffd16c = 0;
    DAT_ffffd170 = 0;
    DAT_ffffd174 = 0;
    DAT_ffffd178 = 0;
    DAT_ffffd17c = 0;
    uVar2 = 1;
  }
  else {
    uVar2 = (ushort)DAT_ffffcfc6;
    if ((DAT_ffffcfc6 == 1) && (uVar2 = DAT_ffffcfaa, DAT_ffffcfaa == uVar1)) {
      DAT_ffffd180 = 0x27;
    }
  }
  return uVar2;
}


