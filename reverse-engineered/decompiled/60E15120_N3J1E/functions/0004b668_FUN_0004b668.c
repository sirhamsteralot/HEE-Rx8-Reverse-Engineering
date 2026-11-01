/* ROM address: 0x0004b668; body bytes: 192; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0004b67e) */

uint FUN_0004b668(void)

{
  uint uVar1;
  
  if ((DAT_ffffc61e == '\x01') || (8.0 < DAT_ffffce38)) {
    inferred_ram_ce30_ffffce30_ffffce30 = -0x100;
  }
  DAT_ffffce38 = (vehicle_speed_ffffbbb4 * 1024.0) / 3.6e+06 + DAT_ffffce38;
  if (inferred_ram_ce30_ffffce30_ffffce30 != DAT_ffffce46) {
    DAT_ffffce4c = 1;
    ref_writeToE2RAMArea_INDEX_ADDR_LEN(0x7a,&inferred_ram_ce30_ffffce30_ffffce30,2);
    DAT_ffffce4a = FUN_000378dc(0x7a,2);
    DAT_ffffce46 = inferred_ram_ce30_ffffce30_ffffce30;
  }
  uVar1 = (uint)DAT_ffffce4c;
  if (uVar1 == 1) {
    if (DAT_ffffce4a == '\x01') {
      uVar1 = FUN_000378dc(0x7a,2);
      DAT_ffffce4a = (char)uVar1;
    }
    else {
      uVar1 = (uint)DAT_ffffc289;
      if (uVar1 == 1) {
        DAT_ffffce4c = 0;
      }
    }
  }
  return uVar1;
}


