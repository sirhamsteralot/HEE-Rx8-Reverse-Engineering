/* ROM address: 0x00029a8c; body bytes: 228; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00029ab0) */
/* WARNING: Removing unreachable block (ram,0x00029aba) */
/* WARNING: Removing unreachable block (ram,0x00029ac4) */
/* WARNING: Removing unreachable block (ram,0x00029ad0) */
/* WARNING: Removing unreachable block (ram,0x00029ada) */
/* WARNING: Removing unreachable block (ram,0x00029ae4) */

byte FUN_00029a8c(void)

{
  if (DAT_ffffbb3c != -1) {
    DAT_ffffbb2c = 0x44000000;
  }
  DAT_ffffbb30 = FUN_000024c0(0x3f800000,0xc4000000,(int)DAT_ffffbb3e);
  DAT_ffffbb34 = FUN_00002500(0x42160000,0,(int)DAT_ffffbb40);
  DAT_ffffbb38 = (DAT_ffffbb44 & 8) == 8;
  FUN_0003ebc0(&DAT_ffff8688,(DAT_ffffbb44 & 2) != 0);
  DAT_ffffbb39 = (DAT_ffffbb44 & 2) == 2;
  return DAT_ffffbb44 & 2;
}


