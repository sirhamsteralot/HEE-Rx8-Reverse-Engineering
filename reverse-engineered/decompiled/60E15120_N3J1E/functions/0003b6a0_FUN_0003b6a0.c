/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003b6a0; body bytes: 236; decompiled */

uint FUN_0003b6a0(void)

{
  uint uVar1;
  float fVar2;
  float extraout_fr0;
  undefined4 uVar3;
  undefined4 uVar4;
  float snapshot_DAT_ffffcf90;
  
  uVar4 = 0;
  snapshot_DAT_ffffcf90 = DAT_ffffcf90;
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff867c);
  if (fVar2 < 100.0) {
    if (fVar2 < 99.9) {
      DAT_ffffc5bf = '\0';
    }
  }
  else {
    DAT_ffffc5bf = '\x01';
  }
  if (fVar2 < 0.0) {
    if (fVar2 < -0.1) {
      DAT_ffffc5c0 = '\0';
    }
  }
  else {
    DAT_ffffc5c0 = '\x01';
  }
  if ((DAT_ffffc5c0 == '\x01') && (DAT_ffffc5bf == '\0')) {
    DAT_ffffc5ac = 1;
  }
  else {
    DAT_ffffc5ac = 0;
  }
  uVar3 = 0x42c80000;
  if (DAT_ffffd1c5 == '\x01') {
    ref_updateMemoryAtAddress_float_VAL_ADDR(uVar4,&DAT_ffff86ec);
    ref_updateMemoryAtAddress_float_VAL_ADDR(uVar3,&DAT_ffff86f4);
    uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(uVar4,&DAT_ffff86fc);
  }
  else {
    uVar1 = (uint)DAT_ffffc5ac;
    if (uVar1 == 1) {
      fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x42c80000,&DAT_ffff86f4);
      if (snapshot_DAT_ffffcf90 < fVar2) {
        ref_updateMemoryAtAddress_float_VAL_ADDR(snapshot_DAT_ffffcf90,&DAT_ffff86f4);
      }
      uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(uVar4,&DAT_ffff86fc);
      if (extraout_fr0 < snapshot_DAT_ffffcf90) {
        uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(snapshot_DAT_ffffcf90,&DAT_ffff86fc);
      }
    }
  }
  return uVar1;
}


