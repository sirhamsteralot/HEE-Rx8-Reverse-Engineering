/* ROM address: 0x00035a8c; body bytes: 592; decompiled */

uint FUN_00035a8c(uint param_1)

{
  uint uVar1;
  
  param_1 = param_1 & 0xff;
  if (param_1 != 1) {
    if (param_1 == 2) {
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(2,&DAT_ffffc26c,8);
      return uVar1;
    }
    if (param_1 == 0xd) {
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0x1e,&DAT_ffffc282,1);
      return uVar1;
    }
    if (param_1 == 3) {
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0,&DAT_ffffc268,1);
      return uVar1;
    }
    if (param_1 == 4) {
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xc,&DAT_ffffc275,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0x10,&inferred_ram_c1d2_ffffc1d2_ffffc1d2,1);
      return uVar1;
    }
    if (param_1 == 5) {
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x12,&inferred_ram_c1d4_ffffc1d4_ffffc1d4,1);
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0x13,&DAT_ffffc278,1);
      return uVar1;
    }
    if (param_1 == 6) {
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
      return uVar1;
    }
    if (param_1 == 7) {
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x16,&DAT_ffffc27a,2);
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0x18,&DAT_ffffc27c,2);
      return uVar1;
    }
    if (param_1 == 8) {
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0x14,&DAT_ffffc279,1);
      return uVar1;
    }
    if (param_1 == 0xc) {
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xc,&DAT_ffffc275,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xd,&DAT_ffffc276,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xf,&DAT_ffffc277,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x10,&inferred_ram_c1d2_ffffc1d2_ffffc1d2,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x14,&DAT_ffffc279,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x12,&inferred_ram_c1d4_ffffc1d4_ffffc1d4,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x13,&DAT_ffffc278,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1a,&DAT_ffffc27e,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1b,&DAT_ffffc27f,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1c,&DAT_ffffc280,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1d,&DAT_ffffc281,1);
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0x1e,&DAT_ffffc282,1);
      return uVar1;
    }
    if (param_1 == 9) {
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xc,&DAT_ffffc275,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x10,&inferred_ram_c1d2_ffffc1d2_ffffc1d2,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x12,&inferred_ram_c1d4_ffffc1d4_ffffc1d4,1);
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0x13,&DAT_ffffc278,1);
      return uVar1;
    }
    if (param_1 == 10) {
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1a,&DAT_ffffc27e,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1b,&DAT_ffffc27f,1);
      ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1c,&DAT_ffffc280,1);
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0x1d,&DAT_ffffc281,1);
      return uVar1;
    }
    if (param_1 != 0xb) {
      if (param_1 == 0xe) {
        uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0xd,&DAT_ffffc276,1);
        return uVar1;
      }
      if (param_1 != 0xf) {
        if (param_1 == 0xff) {
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0,&DAT_ffffc268,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(2,&DAT_ffffc26c,8);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(10,&inferred_ram_c274_ffffc274_ffffc274,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xc,&DAT_ffffc275,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xd,&DAT_ffffc276,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0xf,&DAT_ffffc277,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x10,&inferred_ram_c1d2_ffffc1d2_ffffc1d2,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x12,&inferred_ram_c1d4_ffffc1d4_ffffc1d4,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x13,&DAT_ffffc278,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x16,&DAT_ffffc27a,2);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x18,&DAT_ffffc27c,2);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x14,&DAT_ffffc279,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1a,&DAT_ffffc27e,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1b,&DAT_ffffc27f,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1c,&DAT_ffffc280,1);
          ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1d,&DAT_ffffc281,1);
          param_1 = ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x1e,&DAT_ffffc282,1);
        }
        return param_1;
      }
      uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(0xf,&DAT_ffffc277,1);
      return uVar1;
    }
    ref_writeToE2RAMArea_INDEX_ADDR_LEN(2,&DAT_ffffc26c,8);
  }
  uVar1 = ref_writeToE2RAMAreaTHUNK_INDEX_ADDR_LEN(10,&inferred_ram_c274_ffffc274_ffffc274,1);
  return uVar1;
}


