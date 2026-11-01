/* ROM address: 0x0004edc6; body bytes: 112; decompiled */

uint FUN_0004edc6(void)

{
  byte bVar2;
  uint uVar1;
  
  bVar2 = FUN_00011f34();
  if (DAT_ffffd1e9 == '\x01') {
    DAT_ffffcfcc = DAT_ffffcfc8;
  }
  else {
    DAT_ffffcfcc = rx8_first_order_filter(DAT_ffffcfc8,DAT_ffffcfcc,0.0078099966,1e-05);
  }
  uVar1 = (uint)DAT_ffffcff1;
  if ((((uVar1 & 0x80) == 0) && (uVar1 = (uint)bVar2, uVar1 == 1)) &&
     (uVar1 = (uint)DAT_ffffcfd2, uVar1 == 1)) {
    uVar1 = FUN_0003ec20(DAT_ffffcfcc,&DAT_ffff86a4);
  }
  DAT_ffffcfd2 = bVar2;
  return uVar1;
}


