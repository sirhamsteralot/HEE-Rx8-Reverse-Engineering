/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00053054; body bytes: 238; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00050fd8 (238 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined1 * FUN_00053054(void)

{
  ushort snapshot_DAT_ffffcfa8;
  ushort snapshot_DAT_ffffcfaa;
  float fVar3;
  ushort uVar5;
  undefined1 *puVar4;
  undefined1 *puVar6;
  float fVar7;
  float snapshot_DAT_ffffcfe0;
  
  snapshot_DAT_ffffcfaa = DAT_ffffcfaa;
  snapshot_DAT_ffffcfa8 = DAT_ffffcfa8;
  fVar7 = DAT_ffffcfe0 - DAT_ffffd14c;
  snapshot_DAT_ffffcfe0 = DAT_ffffcfe0;
  uVar5 = rx8_add_u16_saturate((int)(short)DAT_ffffcfa8,1);
  puVar6 = (undefined1 *)(uint)DAT_ffffcfc6;
  if ((snapshot_DAT_ffffcfaa < uVar5) && (DAT_ffffcfc6 == 1)) {
    DAT_ffffd140 = 0.0;
    fVar3 = DAT_ffffd140;
  }
  else {
    fVar3 = DAT_ffffd140;
    if ((puVar6 == (undefined1 *)0x1) &&
       (((fVar3 = fVar7, snapshot_DAT_ffffcfaa != uVar5 && (DAT_ffffd144 != 1)) &&
        (fVar3 = DAT_ffffd140, DAT_ffffd144 < 3)))) {
      fVar3 = DAT_ffffd140 + fVar7;
    }
  }
  DAT_ffffd140 = fVar3;
  puVar4 = (undefined1 *)0x1;
  if (DAT_ffffcf78 != '\x01') {
    if (puVar6 != (undefined1 *)0x1) {
      DAT_ffffd14c = snapshot_DAT_ffffcfe0;
      return puVar6;
    }
    puVar4 = (undefined1 *)0x1;
    if ((snapshot_DAT_ffffcfaa != uVar5) && (puVar4 = &DAT_ffffd144, DAT_ffffd144 != 2)) {
      if (1 < DAT_ffffd144) {
        DAT_ffffd14c = snapshot_DAT_ffffcfe0;
        return puVar4;
      }
      if (snapshot_DAT_ffffcfaa <= snapshot_DAT_ffffcfa8) {
        DAT_ffffd14c = snapshot_DAT_ffffcfe0;
        return puVar4;
      }
      DAT_ffffd14c = snapshot_DAT_ffffcfe0;
      puVar6 = (undefined1 *)rx8_add_u8_saturate((int)(char)DAT_ffffd144,1);
      DAT_ffffd144 = (char)puVar6;
      return puVar6;
    }
  }
  DAT_ffffd14c = snapshot_DAT_ffffcfe0;
  DAT_ffffd144 = 1;
  return puVar4;
}


