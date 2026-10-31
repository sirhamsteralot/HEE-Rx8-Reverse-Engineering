/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x000529fc; body bytes: 418; decompiled */

void FUN_000529fc(void)

{
  char cVar1;
  ushort snapshot_DAT_ffffcfa8;
  ushort snapshot_DAT_ffffcfaa;
  char cVar4;
  char cVar5;
  ushort uVar8;
  uint uVar6;
  char cVar9;
  char cVar10;
  uint uVar7;
  uint uVar11;
  float snapshot_DAT_ffffcff4;
  
  snapshot_DAT_ffffcfaa = DAT_ffffcfaa;
  snapshot_DAT_ffffcfa8 = DAT_ffffcfa8;
  snapshot_DAT_ffffcff4 = DAT_ffffcff4;
  uVar8 = rx8_add_u16_saturate((int)(short)DAT_ffffcfa8,1);
  uVar6 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86dc,4);
  cVar9 = rx8_add_u8_saturate(0x17,1);
  cVar10 = ref_getKnownBooleanValue__();
  cVar5 = DAT_ffffd1c5;
  cVar4 = DAT_ffffcfc6;
  uVar7 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86e2,0);
  cVar1 = DAT_ffffcf78;
  if (cVar5 == '\x01') {
    uVar7 = 0;
  }
  uVar11 = 4;
  if (DAT_ffffd134 == DAT_ffffcf78) {
    if (((uVar7 & 0xff) == 1) && (DAT_ffffd038 == '\x01')) {
      uVar11 = uVar6;
      if ((uVar6 & 0xff) < 4) {
        uVar11 = uVar6 + 1;
      }
    }
    else if (((((cVar4 != '\x01') || ((snapshot_DAT_ffffcfaa != uVar8 || (0.0012 < snapshot_DAT_ffffcff4)))) &&
              (DAT_ffffd119 != '\x01')) && ((cVar5 != '\x01' && (uVar11 = uVar6, cVar4 == '\x01'))))
            && ((((snapshot_DAT_ffffcfaa == uVar8 && (0.0012 < snapshot_DAT_ffffcff4)) ||
                 (((snapshot_DAT_ffffcfa8 < snapshot_DAT_ffffcfaa && (DAT_ffffcff8 == '\0')) && (DAT_ffffd130 == cVar9)))) &&
                ((uVar6 & 0xff) != 0)))) {
      uVar11 = uVar6 - 1;
    }
  }
  else if (DAT_ffffcf78 == '\x01') {
    uVar11 = 1;
  }
  if (((DAT_ffffd135 == '\0') && (cVar10 == '\x01')) || (cVar5 == '\x01')) {
    uVar7 = 0;
  }
  else if ((((int)DAT_ffffcfb5 & 0x80U) != 0) && ((uVar11 & 0xff) < (uint)DAT_ffffd132)) {
    uVar7 = 1;
  }
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86dc,uVar11);
  ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff86e2,uVar7);
  DAT_ffffd132 = (char)uVar11;
  DAT_ffffd135 = cVar10;
  DAT_ffffd134 = cVar1;
  return;
}


