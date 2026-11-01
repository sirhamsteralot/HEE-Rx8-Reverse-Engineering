/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0001722e; body bytes: 512; decompiled */

uint FUN_0001722e(void)

{
  bool bVar1;
  byte snapshot_DAT_ffffa8e8;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  
  cVar6 = DAT_ffffa914;
  cVar5 = DAT_ffffa8eb;
  cVar4 = DAT_ffffa8ea;
  cVar3 = DAT_ffffa8e9;
  snapshot_DAT_ffffa8e8 = DAT_ffffa8e8;
  if ((DAT_ffff9ecd & 2) == 0) {
    inferred_ram_a8f5_ffffa8f5_ffffa8f5 = '\0';
  }
  else {
    bVar1 = inferred_ram_a8f5_ffffa8f5_ffffa8f5 == '\0';
    inferred_ram_a8f5_ffffa8f5_ffffa8f5 = '\x01';
    if (bVar1) {
      DAT_ffffa906 = '\x01';
    }
  }
  uVar9 = (uint)DAT_ffffa8e8;
  if (uVar9 == 0) {
    DAT_ffffa8f6 = '\0';
    DAT_ffffa8f7 = 0;
  }
  if (DAT_ffffa8fa != 0) {
    DAT_ffffa8fa = DAT_ffffa8fa - 1;
  }
  uVar7 = (uint)DAT_ffffa8fa;
  if (((DAT_ffffa8fa == 1) && (uVar7 = uVar9, uVar9 == 1)) &&
     (uVar7 = (uint)DAT_ffffa901, uVar7 == 1)) {
    inferred_ram_a8f4_ffffa8f4_ffffa8f4 = 0;
    DAT_ffffa8fe = 0;
    ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8054,0);
    DAT_ffffa8f8 = 1;
    if (DAT_ffffa8f6 == '\x01') {
      DAT_ffffa8f6 = '\0';
      DAT_ffffa902 = '\x01';
      uVar7 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8050,0);
      if ((uVar7 & 0xff) != 0) {
        ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8050,uVar7 + 0xff);
      }
    }
    uVar7 = (uint)DAT_ffffa8f7;
    if (uVar7 == 1) {
      DAT_ffffa8f7 = 0;
      uVar7 = ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8050,2);
    }
  }
  if (DAT_ffffa8fa == 0) {
    inferred_ram_a8f4_ffffa8f4_ffffa8f4 = DAT_ffffa8fe;
    if (cVar6 == '\x01') {
      FUN_00017b98();
    }
    else if (uVar9 == 1) {
      FUN_0001778e((int)(char)DAT_ffffa904);
    }
    else if ((cVar4 == '\x01') && (DAT_ffffccc6 == '\0')) {
      FUN_00017b34();
    }
    else if (cVar5 == '\x01') {
      FUN_00017b88();
    }
    else if (cVar3 == '\x01') {
      FUN_0001791a((int)DAT_ffffa903);
    }
    if ((DAT_ffffa8ec == '\x01') && (DAT_ffffa906 == '\x01')) {
      ref_updateMemoryAtAddress_8bit_ADDR_VAL(&DAT_ffff8052,(int)(char)inferred_ram_a8f4_ffffa8f4_ffffa8f4);
    }
    bVar8 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8052,0x37);
    if (((bVar8 < 0x34) || ((DAT_ffffa902 == '\x01' && (inferred_ram_a8f5_ffffa8f5_ffffa8f5 == '\x01')))) ||
       ((0x3b < inferred_ram_a8f4_ffffa8f4_ffffa8f4 && ((inferred_ram_a8f5_ffffa8f5_ffffa8f5 == '\0' && (DAT_ffffa8ec == '\x01')))))) {
      DAT_ffffa8f9 = 1;
    }
    DAT_ffffa902 = '\0';
    DAT_ffffa906 = '\0';
    DAT_ffffa904 = snapshot_DAT_ffffa8e8;
    DAT_ffffa903 = cVar3;
    uVar7 = (uint)cVar4;
    DAT_ffffa905 = cVar4;
  }
  return uVar7;
}


