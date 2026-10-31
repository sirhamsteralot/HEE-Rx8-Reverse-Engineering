/* ROM address: 0x0002b046; body bytes: 216; decompiled */

undefined4 * FUN_0002b046(void)

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
  puVar1 = &DAT_0002b110;
  uVar8 = 0xc2c80000;
  if (((DAT_ffffc61e == '\0') && (puVar1 = (undefined4 *)0x6, DAT_ffffbbbc < 6)) &&
     ((DAT_ffffbbac != -1 || (puVar1 = (undefined4 *)0x6, DAT_ffffbbae != -1)))) {
    puVar1 = (undefined4 *)0x6;
    puVar3 = (undefined4 *)(int)DAT_ffffbbae;
    if ((DAT_ffffbbac != -1) &&
       (puVar1 = (undefined4 *)0x6, puVar3 = (undefined4 *)(int)DAT_ffffbbac, DAT_ffffbbae != -1)) {
      fVar4 = (float)rx8_decode_u16_affine
                               (0x3c23d70a,0xc2c80000,(undefined4 *)(int)DAT_ffffbbac);
      fVar5 = (float)rx8_decode_u16_affine(uVar7,uVar8,(int)DAT_ffffbbae);
      puVar1 = (undefined4 *)
               rx8_encode_u16_affine_saturate((fVar4 + fVar5) * 0.5,uVar7,uVar8);
      puVar3 = puVar1;
    }
  }
  uVar6 = 0;
  if (((uint)puVar3 & 0xffff) == 0xffff) {
    uVar7 = 0;
    DAT_ffffbbbb = 1;
  }
  else {
    uVar7 = rx8_decode_u16_affine(uVar7,uVar8);
    uVar2 = rx8_is_outside_tolerance_band(uVar7,uVar6,0x3ba3d70a);
    puVar1 = (undefined4 *)(uVar2 & 0xff);
    if (puVar1 == (undefined4 *)0x0) {
      uVar7 = uVar6;
    }
    DAT_ffffbbbb = 0;
  }
  vehicle_speed_ffffbbb4 = uVar7;
  return puVar1;
}


