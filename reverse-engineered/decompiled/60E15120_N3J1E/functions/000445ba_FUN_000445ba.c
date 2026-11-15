/* ROM address: 0x000445ba; body bytes: 296; decompiled */

undefined4 FUN_000445ba(void)

{
  undefined4 uVar1;
  ushort uVar2;
  ushort uVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  
  uVar3 = DAT_ffffb692;
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcb6d = 0;
    DAT_ffffcb6e = 0;
    DAT_ffffcb6c = 0;
    DAT_ffffcb6f = 0;
    DAT_ffffcb70 = '\0';
    uVar1 = 1;
  }
  else {
    uVar1 = 2000;
    if (DAT_ffffba9e == 2000) {
      uVar1 = 0x3f800000;
      uVar6 = 0;
      fVar4 = (float)rx8_decode_u16_affine(0x3f800000,0,(int)(short)DAT_ffffb692)
      ;
      DAT_ffffcb74 = rx8_lookup_2d_raw_u16(engine_speed_rpm_ffffb548,&DAT_0006b9c0);
      fVar5 = (float)rx8_decode_u16_affine(0x3e800000,uVar6,(int)DAT_ffffcb74);
      uVar2 = rx8_encode_u16_affine_saturate(fVar4 * fVar5,uVar1,uVar6);
      if ((uVar3 < DAT_ffffcb72) || (uVar2 < DAT_ffffcb62)) {
        DAT_ffffcb6d = 1;
        DAT_ffffcb6e = 0;
      }
      else {
        DAT_ffffcb6d = 0;
        DAT_ffffcb6e = 1;
        uVar3 = rx8_encode_u16_affine_saturate(fVar4 * 0.9,uVar1,uVar6);
        if (uVar3 < DAT_ffffb68c) {
          DAT_ffffcb6f = 1;
        }
        if (uVar3 < DAT_ffffb68e) {
          DAT_ffffcb70 = '\x01';
        }
        DAT_ffffcb6c = DAT_ffffcb70 << 1 | DAT_ffffcb6f;
      }
      uVar1 = misfire_dtc_set();
      DAT_ffffcb6c = 0;
      DAT_ffffb68c = 0;
      DAT_ffffb68e = 0;
      DAT_ffffcb7a = 0;
      DAT_ffffcb7e = 0;
      DAT_ffffcb62 = 0;
      DAT_ffffbaa0 = 0;
      DAT_ffffcb6f = 0;
      DAT_ffffcb70 = '\0';
    }
  }
  return uVar1;
}


