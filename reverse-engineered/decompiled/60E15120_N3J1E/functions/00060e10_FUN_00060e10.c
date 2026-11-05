/* ROM address: 0x00060e10; body bytes: 204; decompiled */

undefined ** FUN_00060e10(ushort *param_1)

{
  byte bVar1;
  undefined **ppuVar2;
  
  bVar1 = *(byte *)(param_1 + 3);
  ppuVar2 = (undefined **)&DAT_ffff8d54;
  if (((bVar1 != 0) && (bVar1 < 0x40)) &&
     (ppuVar2 = (undefined **)(uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2],
     ppuVar2 == &vector_Illegal_instr)) {
    FUN_00062dd8(0);
    ppuVar2 = (undefined **)FUN_0006310a(8);
    return ppuVar2;
  }
  if (((bVar1 < 0x81) || (0xbf < bVar1)) ||
     (ppuVar2 = (undefined **)(uint)(byte)(&DAT_ffff8d54)[(uint)*param_1 * 2],
     ppuVar2 != &vector_Illegal_instr)) {
    if (bVar1 == 0xc0) {
      ppuVar2 = (undefined **)(uint)(byte)(&DAT_ffff87b8)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10];
      if ((undefined **)(uint)(byte)(&DAT_0007e442)[*param_1] <= ppuVar2) {
        ppuVar2 = (undefined **)FUN_00062dd8(0xc1);
      }
    }
    else if ((bVar1 == 0xc1) &&
            (ppuVar2 = (undefined **)(uint)(byte)(&DAT_ffff87b9)[(uint)dtc_master_current_index_ffff8900._0_2_ * 0x10],
            (undefined **)(uint)(byte)(&DAT_0007e4ce)[*param_1] <= ppuVar2)) {
      FUN_00062dd8(0);
      ppuVar2 = (undefined **)FUN_0006310a(8);
      return ppuVar2;
    }
  }
  else {
    ppuVar2 = (undefined **)FUN_00062dd8(0xc1);
  }
  return ppuVar2;
}


