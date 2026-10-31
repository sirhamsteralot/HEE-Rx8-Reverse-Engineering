/* ROM address: 0x0005b018; body bytes: 62; decompiled */

uint FUN_0005b018(byte param_1)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  bVar1 = param_1;
  if (uVar2 != 1) {
    if (uVar2 == 2) {
      uVar2 = (uint)DAT_ffffd2e0;
      if (uVar2 == 1) {
        uVar2 = ref_whileLoop();
        return uVar2;
      }
      DAT_ffffd2e0 = 0;
      bVar1 = DAT_ffffd2e0;
    }
    else {
      DAT_ffffd2e0 = 0;
      bVar1 = DAT_ffffd2e0;
    }
  }
  DAT_ffffd2e0 = bVar1;
  return uVar2;
}


