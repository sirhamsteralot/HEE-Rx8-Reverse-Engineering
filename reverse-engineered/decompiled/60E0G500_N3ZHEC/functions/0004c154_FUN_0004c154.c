/* ROM address: 0x0004c154; body bytes: 118; decompiled */

uint FUN_0004c154(void)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bVar1 = DAT_ffffce85;
  uVar2 = (uint)DAT_ffffce8a;
  if ((uVar2 == 1) && (uVar2 = (uint)DAT_ffffce85, uVar2 == 0)) {
    if (DAT_ffffce78 < 0xdbbb) {
      if (DAT_ffffce78 < 0xdbbb) {
        if (DAT_ffffce78 < 0xdbbb) {
          if (DAT_ffffce78 == 0) {
            uVar3 = 4;
          }
          else {
            uVar3 = 3;
          }
          uVar2 = FUN_0003ebc0(&DAT_ffff8798,uVar3);
          DAT_ffffce8a = bVar1;
          return uVar2;
        }
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 0;
    }
    uVar2 = FUN_0003ebc0(&DAT_ffff8798,uVar3);
  }
  DAT_ffffce8a = bVar1;
  return uVar2;
}


