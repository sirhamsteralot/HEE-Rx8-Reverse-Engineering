/* ROM address: 0x00063b3a; body bytes: 290; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_00063b3a(undefined4 param_1,byte param_2,undefined2 *param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  undefined1 local_20;
  
  local_20 = 3;
  uVar2 = (uint)DAT_ffff8928;
  bVar3 = DAT_ffff87e5;
  if (uVar2 == 0) {
    bVar3 = DAT_ffff87f5;
  }
  uVar4 = (uint)(uVar2 == 0);
  uVar1 = 0;
  do {
    if (uVar1 != uVar2) {
      if (bVar3 < (&DAT_ffff87e5)[uVar1 * 0x10]) {
        bVar3 = (&DAT_ffff87e5)[uVar1 * 0x10];
        uVar4 = uVar1;
      }
      else if (bVar3 == (&DAT_ffff87e5)[uVar1 * 0x10]) {
        if (((&DAT_ffff87de)[uVar1 * 0x10] == 0) || (0x3f < (byte)(&DAT_ffff87de)[uVar1 * 0x10])) {
          if ((((&DAT_ffff87de)[uVar1 * 0x10] & 0x80) == 0x80) &&
             ((ushort)(&DAT_ffff87dc)[(uVar4 & 0xffff) * 8] < (ushort)(&DAT_ffff87dc)[uVar1 * 8])) {
            uVar4 = uVar1;
          }
        }
        else if ((ushort)(&DAT_ffff87da)[(uVar4 & 0xffff) * 8] < (ushort)(&DAT_ffff87da)[uVar1 * 8])
        {
          uVar4 = uVar1;
        }
      }
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x15);
  if (param_2 < bVar3) {
    *param_3 = (&DAT_ffff87d8)[(uVar4 & 0xffff) * 8];
    _DAT_ffff892c = FUN_00002430(uVar4);
    local_20 = 2;
  }
  return local_20;
}


