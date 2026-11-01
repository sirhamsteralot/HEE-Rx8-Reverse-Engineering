/* ROM address: 0x00027ca2; body bytes: 94; decompiled */

void FUN_00027ca2(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  float fVar4;
  
  fVar4 = DAT_ffffc12c;
  uVar1 = FUN_000020c4(DAT_ffffb5b8,&DAT_0006abb0);
  DAT_ffffba7c = (undefined2)uVar1;
  uVar2 = DAT_ffffba7c;
  if (0.4 <= fVar4) {
    if (0.65 <= fVar4) {
      if (3.0 <= fVar4) {
        uVar3 = 0x33;
      }
      else {
        uVar3 = 0x22;
      }
      uVar2 = FUN_00002460(uVar1,uVar3);
    }
    else {
      uVar2 = FUN_00002460(uVar1,0x11);
    }
  }
  DAT_ffffb734 = uVar2;
  return;
}


