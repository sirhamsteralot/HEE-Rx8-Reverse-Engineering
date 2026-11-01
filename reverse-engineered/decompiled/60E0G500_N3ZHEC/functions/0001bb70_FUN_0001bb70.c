/* ROM address: 0x0001bb70; body bytes: 224; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001bb9e) */
/* WARNING: Removing unreachable block (ram,0x0001bba6) */
/* WARNING: Removing unreachable block (ram,0x0001bbbc) */
/* WARNING: Removing unreachable block (ram,0x0001bbd4) */
/* WARNING: Removing unreachable block (ram,0x0001bbc6) */
/* WARNING: Removing unreachable block (ram,0x0001bbb6) */
/* WARNING: Removing unreachable block (ram,0x0001bbca) */

undefined4 FUN_0001bb70(void)

{
  undefined4 uVar1;
  float extraout_fr0;
  float extraout_fr0_00;
  
  uVar1 = FUN_000024c0(0x38a00000,0,(int)DAT_ffffad94);
  DAT_ffffad98 = extraout_fr0;
  DAT_ffffada0 = extraout_fr0;
  if ((DAT_ffffa428 == '\0') || (uVar1 = 1, DAT_ffffcdf8 == '\x01')) {
    DAT_ffffad9c = 0;
  }
  else {
    uVar1 = FUN_00002068(DAT_ffffaa1c,&DAT_00069ea0);
    if (((0.45 <= DAT_ffffad98) && (uVar1 = 0x20, 0x1f < DAT_ffffada4)) ||
       (extraout_fr0_00 <= DAT_ffffb3a4)) {
      DAT_ffffad9c = 1;
    }
  }
  if (DAT_ffffad98 < 0.45) {
    DAT_ffffada4 = 0;
  }
  else {
    uVar1 = FUN_00002460((int)(short)DAT_ffffada4,1);
    DAT_ffffada4 = (ushort)uVar1;
  }
  return uVar1;
}


