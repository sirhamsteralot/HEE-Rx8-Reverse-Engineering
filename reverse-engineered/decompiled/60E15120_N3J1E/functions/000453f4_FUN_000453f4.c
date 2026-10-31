/* ROM address: 0x000453f4; body bytes: 50; decompiled */

uint FUN_000453f4(void)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = (uint)DAT_ffffd1c5;
  if (uVar1 == 1) {
    bVar2 = 0;
    do {
      uVar1 = (uint)bVar2;
      bVar2 = bVar2 + 1;
      (&DAT_ffffcbb6)[uVar1] = 0;
      (&DAT_ffffcbba)[uVar1] = 0;
      (&DAT_ffffcbbe)[uVar1] = 0;
    } while (bVar2 < 4);
  }
  return uVar1;
}


