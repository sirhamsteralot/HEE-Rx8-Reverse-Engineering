/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0003bbc4; body bytes: 194; decompiled */

uint FUN_0003bbc4(void)

{
  uint uVar1;
  char cVar2;
  float extraout_fr0;
  float fVar3;
  float fVar4;
  undefined4 snapshot_DAT_ffffcf90;
  undefined4 uVar6;
  
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5b3 = 0;
    DAT_ffffc5b4 = 0;
    uVar1 = 1;
  }
  else {
    uVar6 = 0;
    uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff86ec);
    if (100000.0 <= extraout_fr0) {
      if ((DAT_ffffc5b1 == '\0') && (cVar2 = ref_getFaultStatus__(0x33), cVar2 == '\0')) {
        fVar3 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(uVar6,&DAT_ffff86fc);
        fVar4 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0x42c80000,&DAT_ffff86f4);
        if (-100.0 <= fVar3 - fVar4) {
          cVar2 = ref_getFaultStatus__(0x33);
          if (cVar2 == '\0') {
            DAT_ffffc5b4 = 1;
            DAT_ffffc5b3 = 0;
          }
        }
        else {
          DAT_ffffc5b3 = 1;
          DAT_ffffc5b4 = 0;
        }
      }
      uVar1 = (uint)DAT_ffffc5ac;
      if (uVar1 == 1) {
        snapshot_DAT_ffffcf90 = DAT_ffffcf90;
        ref_updateMemoryAtAddress_float_VAL_ADDR(uVar6,&DAT_ffff86ec);
        ref_updateMemoryAtAddress_float_VAL_ADDR(snapshot_DAT_ffffcf90,&DAT_ffff86f4);
        uVar1 = ref_updateMemoryAtAddress_float_VAL_ADDR(snapshot_DAT_ffffcf90,&DAT_ffff86fc);
      }
    }
  }
  return uVar1;
}


