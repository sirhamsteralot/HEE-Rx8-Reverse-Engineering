/* ROM address: 0x0002bbd6; body bytes: 216; decompiled */

undefined4 * FUN_0002bbd6(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  puVar3 = (undefined4 *)0xffff;
  uVar7 = 0x3c23d70a;
  puVar1 = &DAT_0002bca0;
  uVar8 = 0xc2c80000;
  if (((DAT_ffffc68e == '\0') && (puVar1 = (undefined4 *)0x6, DAT_ffffbc24 < 6)) &&
     ((DAT_ffffbc14 != -1 || (puVar1 = (undefined4 *)0x6, DAT_ffffbc16 != -1)))) {
    puVar1 = (undefined4 *)0x6;
    puVar3 = (undefined4 *)(int)DAT_ffffbc16;
    if ((DAT_ffffbc14 != -1) &&
       (puVar1 = (undefined4 *)0x6, puVar3 = (undefined4 *)(int)DAT_ffffbc14, DAT_ffffbc16 != -1)) {
      fVar4 = (float)FUN_000024c0(0x3c23d70a,0xc2c80000,(undefined4 *)(int)DAT_ffffbc14);
      fVar5 = (float)FUN_000024c0(uVar7,uVar8,(int)DAT_ffffbc16);
      puVar1 = (undefined4 *)FUN_00002490((fVar4 + fVar5) * 0.5,uVar7,uVar8);
      puVar3 = puVar1;
    }
  }
  uVar6 = 0;
  if (((uint)puVar3 & 0xffff) == 0xffff) {
    uVar7 = 0;
    DAT_ffffbc23 = 1;
  }
  else {
    uVar7 = FUN_000024c0(uVar7,uVar8);
    uVar2 = FUN_00002440(uVar7,uVar6,0x3ba3d70a);
    puVar1 = (undefined4 *)(uVar2 & 0xff);
    if (puVar1 == (undefined4 *)0x0) {
      uVar7 = uVar6;
    }
    DAT_ffffbc23 = 0;
  }
  DAT_ffffbc1c = uVar7;
  return puVar1;
}


