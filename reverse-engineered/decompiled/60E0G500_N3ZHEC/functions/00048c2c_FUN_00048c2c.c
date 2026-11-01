/* ROM address: 0x00048c2c; body bytes: 120; decompiled */

uint FUN_00048c2c(void)

{
  char cVar2;
  uint uVar1;
  
  cVar2 = FUN_0003eaa4(&DAT_ffff8772,0);
  if (((cVar2 == '\x01') || (cVar2 = FUN_0003eaa4(&DAT_ffff877a,0), cVar2 == '\x01')) ||
     (DAT_ffffb58b == '\x01')) {
    DAT_ffffcce5 = 1;
  }
  else {
    DAT_ffffcce5 = 0;
  }
  uVar1 = (uint)DAT_ffffcce5;
  if (uVar1 == 1) {
    uVar1 = FUN_00002460((int)(short)DAT_ffffccce,1);
    DAT_ffffccce = (ushort)uVar1;
  }
  else {
    DAT_ffffccce = 0;
  }
  if (2 < DAT_ffffccce) {
    uVar1 = FUN_00009efe();
    return uVar1;
  }
  return uVar1;
}


