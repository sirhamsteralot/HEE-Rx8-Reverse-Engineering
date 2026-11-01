/* ROM address: 0x0002ddc8; body bytes: 172; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0002de2e) */
/* WARNING: Removing unreachable block (ram,0x0002de40) */
/* WARNING: Removing unreachable block (ram,0x0002de3a) */
/* WARNING: Removing unreachable block (ram,0x0002de42) */

uint FUN_0002ddc8(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffbd59;
  if (((uVar1 == 1) &&
      (((10.0 <= DAT_ffffc008 - DAT_ffffc00c || (10.0 <= DAT_ffffc00c - DAT_ffffc008)) &&
       (90.0 <= DAT_ffffaa40)))) && (uVar1 = 0x271, 0x270 < DAT_ffffbd5c)) {
    uVar1 = 0;
  }
  DAT_ffffbd5a = 0;
  DAT_ffffbd54 = 0;
  if (DAT_ffffaa40 < 90.0) {
    DAT_ffffbd5c = 0;
  }
  else {
    uVar1 = FUN_00002460((int)(short)DAT_ffffbd5c,1);
    DAT_ffffbd5c = (ushort)uVar1;
  }
  return uVar1;
}


