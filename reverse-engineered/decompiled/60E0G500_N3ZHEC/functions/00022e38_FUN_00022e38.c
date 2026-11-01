/* ROM address: 0x00022e38; body bytes: 224; decompiled */

undefined4 * FUN_00022e38(void)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar2 = DAT_ffffb600;
  fVar3 = DAT_ffffc12c;
  fVar4 = DAT_ffffaa10;
  DAT_ffffb3bc = FUN_000020c4(DAT_ffffaa1c,&PTR_DAT_0006a800);
  DAT_ffffb3b4 = (float)FUN_00002068(DAT_ffffb5b8,&DAT_0006a80c);
  if (fVar4 < 5.0) {
    if (fVar4 < 2.5) {
      DAT_ffffb3c0 = 0;
    }
  }
  else {
    DAT_ffffb3c0 = 1;
  }
  if (fVar3 < DAT_ffffb3b4) {
    if (fVar3 < DAT_ffffb3b4 + -0.04) {
      DAT_ffffb3c1 = '\0';
    }
  }
  else {
    DAT_ffffb3c1 = '\x01';
  }
  puVar1 = &DAT_00022f4c;
  if (((((DAT_ffffa42c != '\0') ||
        (puVar1 = (undefined4 *)(uint)DAT_ffffa428, puVar1 != (undefined4 *)0x1)) ||
       (puVar1 = (undefined4 *)(int)DAT_ffffa422, puVar1 < (undefined4 *)(int)DAT_ffffb3bc)) ||
      ((puVar1 = (undefined4 *)(uint)DAT_ffffb3c0, puVar1 != (undefined4 *)0x1 || (fVar2 < 9.0))))
     || ((15.0 <= fVar2 ||
         ((puVar1 = (undefined4 *)0x0, DAT_ffffb3c1 != '\0' &&
          (puVar1 = (undefined4 *)(uint)DAT_ffffb13a, puVar1 != (undefined4 *)0x1)))))) {
    DAT_ffffb3a8 = 0;
  }
  else {
    DAT_ffffb3a8 = 1;
  }
  return puVar1;
}


