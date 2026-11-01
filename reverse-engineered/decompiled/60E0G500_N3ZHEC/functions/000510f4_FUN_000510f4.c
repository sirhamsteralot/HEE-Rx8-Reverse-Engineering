/* ROM address: 0x000510f4; body bytes: 58; decompiled */

uint FUN_000510f4(void)

{
  uint uVar1;
  float extraout_fr0;
  
  uVar1 = (uint)DAT_ffffcfc2;
  if ((uVar1 == 1) && (uVar1 = FUN_0003eb72(0,&DAT_ffff86ac), extraout_fr0 < 0.0004)) {
    uVar1 = FUN_000671a4(0x2e);
    uVar1 = uVar1 & 0xff;
    if (uVar1 == 0) {
      DAT_ffffd081 = 1;
    }
  }
  return uVar1;
}


