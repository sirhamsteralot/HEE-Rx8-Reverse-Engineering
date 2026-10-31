/* ROM address: 0x00044b46; body bytes: 326; decompiled */

undefined2 * FUN_00044b46(void)

{
  bool bVar1;
  undefined2 *puVar2;
  ushort uVar3;
  ushort uVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar4 = DAT_ffffb690;
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcb9d = 0;
    DAT_ffffcb9e = 0;
    DAT_ffffcb9c = 0;
    DAT_ffffcb9f = 0;
    DAT_ffffcba0 = '\0';
    puVar2 = (undefined2 *)0x1;
  }
  else {
    puVar2 = (undefined2 *)0x190;
    if (DAT_ffffba9c == 400) {
      uVar7 = 0x3f800000;
      uVar8 = 0;
      fVar5 = (float)rx8_decode_u16_affine(0x3f800000,0,(int)(short)DAT_ffffb690)
      ;
      DAT_ffffcba4 = rx8_lookup_2d_raw_u16(engine_speed_rpm_ffffb548,&DAT_0006ba24);
      fVar6 = (float)rx8_decode_u16_affine(0x3e800000,uVar8,(int)DAT_ffffcba4);
      uVar3 = rx8_encode_u16_affine_saturate(fVar5 * fVar6,uVar7,uVar8);
      bVar1 = false;
      if ((uVar4 < DAT_ffffcba2) || (uVar3 < DAT_ffffcb60)) {
        if (DAT_ffffcb87 == '\0') {
          DAT_ffffcb9d = 1;
          DAT_ffffcb9e = 0;
        }
        else {
          bVar1 = true;
        }
      }
      else {
        DAT_ffffcb9d = 0;
        DAT_ffffcb9e = 1;
        uVar4 = rx8_encode_u16_affine_saturate(fVar5 * 0.9,uVar7,uVar8);
        if (uVar4 < DAT_ffffb688) {
          DAT_ffffcb9f = 1;
        }
        if (uVar4 < DAT_ffffb68a) {
          DAT_ffffcba0 = '\x01';
        }
        DAT_ffffcb9c = DAT_ffffcba0 << 1 | DAT_ffffcb9f;
      }
      if (!bVar1) {
        FUN_00044cec();
      }
      DAT_ffffcb9c = 0;
      DAT_ffffb688 = 0;
      DAT_ffffb68a = 0;
      DAT_ffffcb78 = 0;
      DAT_ffffcb7c = 0;
      DAT_ffffcb60 = 0;
      puVar2 = &DAT_ffffcb84;
      DAT_ffffcb84 = 1000;
      DAT_ffffcb87 = '\0';
      DAT_ffffcb9f = 0;
      DAT_ffffcba0 = '\0';
    }
  }
  return puVar2;
}


