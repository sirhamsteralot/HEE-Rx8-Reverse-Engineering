/* ROM address: 0x0005de74; body bytes: 178; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005c664 (178 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_getTireSize(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 local_20;
  undefined1 uStack_1f;
  
  uVar1 = e2ram_cached_byte_read(0x9a,&local_20,2);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 0) {
    tire_revolutions_per_mile_ffffd380 = CONCAT11(local_20,uStack_1f);
    if ((DAT_ffffd1b5 == '\x01') || (DAT_ffffd1b8 == '\x01')) {
      uVar1 = 1;
      DAT_ffffd382 = 99;
    }
    else {
      uVar4 = 0;
      uVar5 = 0x3f800000;
      fVar2 = (float)rx8_decode_u16_affine(0x3f800000,0,0x64a);
      fVar3 = (float)rx8_decode_u16_affine(uVar5,uVar4,(int)tire_revolutions_per_mile_ffffd380);
      uVar1 = rx8_is_outside_tolerance_band(fVar3,uVar4,0x3727c5ac);
      if ((uVar1 & 0xff) != 0) {
        uVar1 = rx8_encode_u8_affine_saturate(fVar2 / fVar3,0x3c23d70a,uVar5);
        DAT_ffffd382 = (undefined1)uVar1;
      }
    }
  }
  return uVar1;
}


