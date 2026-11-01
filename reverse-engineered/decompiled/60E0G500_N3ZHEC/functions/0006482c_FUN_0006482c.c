/* ROM address: 0x0006482c; body bytes: 108; decompiled */

uint FUN_0006482c(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_0006359c();
  uVar3 = uVar1 & 0xff;
  if (((uVar3 == 0) || ((uVar3 != 0 && (uVar3 < 0x40)))) || ((0x80 < uVar3 && (uVar3 < 0xc0)))) {
    uVar2 = FUN_00064898(param_1);
  }
  else {
    uVar2 = uVar1;
    if (((uVar3 != 0xc0) && (uVar2 = 0xc0, uVar3 != 0xc1)) && (uVar2 = uVar1, uVar3 == 0x50)) {
      uVar2 = FUN_00064898(param_1,0);
    }
  }
  return uVar2;
}


