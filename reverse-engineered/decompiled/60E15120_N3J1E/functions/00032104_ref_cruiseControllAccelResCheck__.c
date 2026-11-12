/* ROM address: 0x00032104; body bytes: 190; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000325ac (190 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_cruiseControllAccelResCheck__(void)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  
  uVar4 = 0;
  fVar5 = DAT_ffffbfa0;
  fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&cruise_set_speed_kmh_ffff866c);
  fVar6 = fVar5 - fVar3;
  fVar5 = fVar3 - fVar5;
  uVar1 = rx8_is_outside_tolerance_band(fVar3,uVar4,0x3727c5ac);
  uVar2 = uVar1;
  if ((DAT_ffffbcec == '\0') ||
     ((uVar2 = (uint)DAT_ffffbfb5, uVar2 == 1 &&
      ((((0.0 <= fVar6 && (fVar6 <= 1.6)) || ((0.0 <= fVar5 && (fVar5 <= 0.5)))) ||
       ((uVar2 = 1, DAT_ffffbfba == '\x01' || (uVar2 = (uint)DAT_ffffbfb9, uVar2 == 1)))))))) {
    DAT_ffffbfb5 = 0;
  }
  else if ((DAT_ffffbced == '\0') &&
          (((uVar2 = (uint)(char)DAT_ffffbfcb, uVar2 == 0 &&
            (uVar2 = (uint)DAT_ffffbc36, uVar2 == 1)) && ((uVar1 & 0xff) != 0)))) {
    DAT_ffffbfb5 = 1;
  }
  DAT_ffffbfcb = DAT_ffffbc36;
  return uVar2;
}


