/* ROM address: 0x0000ad40; body bytes: 316; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000ae28) */

void FUN_0000ad40(void)

{
  float fVar1;
  float arg3;
  ushort local_20;
  
  arg3 = 0.0;
  if (3 < DAT_ffffa207) {
    local_20 = DAT_ffff9efc;
    if (DAT_ffffa1f8 + 0x41 < (uint)DAT_ffff9efc) {
      local_20 = DAT_ffffa1f8 + 0x41;
    }
    if ((int)(uint)local_20 < (int)(DAT_ffffa1f8 - 0x41)) {
      local_20 = DAT_ffffa1f8 - 0x41;
    }
    DAT_ffffa1f8 = local_20;
    DAT_ffffa1e0 = (float)local_20 * -0.625 * 7.6293945e-05 + 1.75;
    if (((DAT_ffffa208 < 0x14) && (DAT_ffffa203 == '\x01')) && (15233.0 <= DAT_ffffa1d8)) {
      DAT_ffffa208 = DAT_ffffa208 + 1;
      DAT_ffffa1f4 = DAT_ffffa1f4 + DAT_ffffa1e0;
      fVar1 = rx8_clamp_float(DAT_ffffa1f4 / ((float)DAT_ffffa208 + 1.0),0.0,0.0);
      FUN_0003ec20(fVar1,&DAT_ffff8030);
    }
  }
  fVar1 = (float)FUN_0003eb72(arg3,&DAT_ffff8030);
  DAT_ffffa1d0 = rx8_first_order_filter(DAT_ffffa1e0 - fVar1,DAT_ffffa1d0,0.3439,arg3);
  DAT_ffffa1cc = FUN_00002068(DAT_ffffa1d0,&DAT_00069e7c);
  return;
}


