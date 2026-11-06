/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002e3dc; body bytes: 310; decompiled */

uint FUN_0002e3dc(void)

{
  byte snapshot_DAT_ffffbfb5;
  char cVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float snapshot_DAT_ffffbfa4;
  float snapshot_DAT_ffffbccc;
  float snapshot_DAT_ffffbfa0;
  
  cVar2 = DAT_ffffbfb9;
  snapshot_DAT_ffffbfb5 = DAT_ffffbfb5;
  snapshot_DAT_ffffbfa4 = DAT_ffffbfa4;
  snapshot_DAT_ffffbccc = DAT_ffffbccc;
  snapshot_DAT_ffffbfa0 = DAT_ffffbfa0;
  fVar4 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff866c);
  fVar5 = DAT_ffffbfac - 0.5;
  if ((((DAT_ffffbced == '\0') || (cruise_set_speed_ffffbcf8 < DAT_ffffa9b4)) ||
      ((cVar2 == '\0' && (snapshot_DAT_ffffbfb5 == 0)))) ||
     ((snapshot_DAT_ffffbfb5 == 1 &&
      (((0.0 <= snapshot_DAT_ffffbfa0 - fVar4 && (snapshot_DAT_ffffbfa0 - fVar4 <= 1.6)) ||
       ((0.0 <= fVar4 - snapshot_DAT_ffffbfa0 && (fVar4 - snapshot_DAT_ffffbfa0 <= 0.5)))))))) {
    DAT_ffffbd60 = 0;
  }
  else if ((((cVar2 == '\x01') || (snapshot_DAT_ffffbfb5 == 1)) && (0x7c < DAT_ffffbd62)) &&
          ((((snapshot_DAT_ffffbccc < 2.0 && (snapshot_DAT_ffffbfa0 < snapshot_DAT_ffffbfa4)) && (snapshot_DAT_ffffbfa0 < fVar5)) && (0x18 < DAT_ffffbd64)))) {
    DAT_ffffbd60 = 1;
  }
  if ((cVar2 == '\x01') || (uVar3 = (uint)snapshot_DAT_ffffbfb5, uVar3 == 1)) {
    uVar3 = rx8_add_u16_saturate((int)(short)DAT_ffffbd62,1);
    DAT_ffffbd62 = (ushort)uVar3;
  }
  else {
    DAT_ffffbd62 = 0;
  }
  if (((2.0 <= snapshot_DAT_ffffbccc) || (snapshot_DAT_ffffbfa4 <= snapshot_DAT_ffffbfa0)) || (fVar5 <= snapshot_DAT_ffffbfa0)) {
    DAT_ffffbd64 = 0;
  }
  else {
    uVar3 = rx8_add_u16_saturate((int)(short)DAT_ffffbd64,1);
    DAT_ffffbd64 = (ushort)uVar3;
  }
  return uVar3;
}


