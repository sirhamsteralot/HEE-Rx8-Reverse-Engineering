/* [ADDITIONAL SOURCE REVIEW]
 * crank_sector_advance [high]: 0xffff9f95 = tbl 0xd76c[0xffff9f95*2] (next sector, wrap 0x24 = 36 sectors/720deg), plus period/angle accumulators 0xffff9fbc/9fc1/9fc2/9fc5; re-init if > 0x24.
 * RAM 0xffff9f95 crank_sector_index (uint8): Advanced by 0x787a via tbl 0xd76c (wrap 0x24 = 36 sectors/720 deg); indexes OCR10B reload tbl 0xd76d in 0x7b58 and edge matching in 0xcf96.
 */
/* ROM address: 0x0000787a; body bytes: 470; decompiled */

undefined4 * crank_sector_advance(void)

{
  char cVar2;
  undefined4 *puVar1;
  byte bVar3;
  uint uVar4;
  
  if (0x24 < crank_sector_index_ffff9f95) {
    ref_reInitCrankSensor__();
  }
  crank_sector_index_ffff9f95 = (&tbl_crank_next_sector_0000d76c)[(uint)crank_sector_index_ffff9f95 * 2];
  if ((DAT_ffff9fc3 != 0) && (crank_sector_index_ffff9f95 = crank_sector_index_ffff9f95 + DAT_ffff9fc3, 0x23 < crank_sector_index_ffff9f95)) {
    crank_sector_index_ffff9f95 = crank_sector_index_ffff9f95 - 0x24;
  }
  uVar4 = (uint)DAT_ffff9fc5 + (uint)DAT_ffff9fc3 + 1;
  if (uVar4 < 0x100) {
    DAT_ffff9fc5 = (byte)uVar4;
  }
  else {
    DAT_ffff9fc5 = 0xff;
  }
  DAT_ffff9fbc = DAT_ffff9fbc + (float)(DAT_ffff9fc3 + 1) * 10.0;
  if (DAT_ffff9fc2 != 0xff) {
    DAT_ffff9fc2 = DAT_ffff9fc2 + 1;
  }
  if (DAT_ffff9fc1 == '\x03') {
    puVar1 = (undefined4 *)(uint)crank_sector_index_ffff9f95;
    if ((puVar1 == (undefined4 *)&UNK_0000001c) ||
       (puVar1 == (undefined4 *)((int)&vector_Manual_Reset + 2))) {
      DAT_ffff9fc1 = '\x02';
      DAT_ffff9fc2 = 0;
    }
  }
  else if (DAT_ffff9fc1 == '\x02') {
    cVar2 = FUN_00007ab2(0x3fd872b0);
    if (cVar2 == '\0') {
      puVar1 = (undefined4 *)0x0;
      if (4 < DAT_ffff9fc2) {
        DAT_ffff9fa2 = 2;
        puVar1 = (undefined4 *)ref_reInitCrankSensor__();
        return puVar1;
      }
    }
    else {
      DAT_ffff9fc1 = '\x01';
      crank_sector_index_ffff9f95 = crank_sector_index_ffff9f95 + (&DAT_0000d7b6)[DAT_ffff9fc2];
      puVar1 = (undefined4 *)(uint)DAT_ffff9fc2;
      if (puVar1 == (undefined4 *)((int)&vector_Poweron_Reset + 3)) {
        DAT_ffff9fa2 = 0;
      }
      else {
        DAT_ffff9fa2 = 1;
      }
    }
  }
  else if (DAT_ffff9fc1 == '\x01') {
    if (((DAT_ffff9fa4 != '\x01') || (DAT_ffff9fa1 == '\0')) ||
       (puVar1 = (undefined4 *)((int)&vector_Poweron_Reset + 1), DAT_ffff9fc0 == '\0')) {
      uVar4 = FUN_00007ab2(0x3f256042);
      puVar1 = (undefined4 *)(uVar4 & 0xff);
      if (puVar1 == (undefined4 *)0x0) {
        bVar3 = 0x22;
      }
      else {
        bVar3 = 0x12;
      }
      if (crank_sector_index_ffff9f95 == bVar3) {
        if (DAT_ffff9fa1 != -1) {
          DAT_ffff9fa1 = DAT_ffff9fa1 + '\x01';
        }
      }
      else {
        DAT_ffff9fa1 = '\0';
        crank_sector_index_ffff9f95 = bVar3;
      }
    }
    DAT_ffff9fc1 = '\x03';
  }
  else {
    if (DAT_ffff9fc1 != '\0') {
      puVar1 = (undefined4 *)ref_reInitCrankSensor__();
      return puVar1;
    }
    puVar1 = &crank_icr10ah_sample_ffff9fb0;
    if (0xa2c27 < crank_icr10ah_sample_ffff9fb0) {
      DAT_ffff9fc2 = 1;
    }
    if (2 < DAT_ffff9fc2) {
      cVar2 = FUN_00007ab2(0x3fd872b0);
      puVar1 = (undefined4 *)0x0;
      if (cVar2 != '\0') {
        DAT_ffff9fc1 = '\x01';
        crank_sector_index_ffff9f95 = 0x21;
        puVar1 = &DAT_ffff9fac;
        DAT_ffff9fac = crank_icr0ah_sample_ffff9fb8;
      }
    }
  }
  return puVar1;
}


