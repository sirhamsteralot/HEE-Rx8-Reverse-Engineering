/* [ADDITIONAL SOURCE REVIEW]
 * gear_float_band_producer [high]: Writes 0xffffcf1c = float(0xffffbc3d current gear) via rx8_decode_u8_affine(1.0,0,bc3d) (jsr pool 0x4def8 = 0x2500 (rx8_decode_u8_affine); store pool 0x4dedc = 0xcf1c at 0x4de24, fmov.s fr0,@r14 at 0x4de40). Config byte ROM[0x7d07f]=0x00 (read at 0x4de2a via pool 0x4def4) selects the gear decode; the alternative switch-code band map (cf47->0.0, cf48->2.0..cf4c->6.0) is compiled in but disabled; its band floats sit at pools 0x4defc = 0x40400000 (3.0), 0x4df00 = 0x40800000 (4.0), 0x4df04 = 0x40a00000 (5.0), 0x4df08 = 0x40c00000 (6.0). Emulator: gear 0-6 -> cf1c 0.0-6.0, switch flags have no effect. Called from batch 0x2e5c6 (jsr 0x2e5d2, pool 0x2e748).
 * RAM 0xffffbc3d current_gear (uint8): Latched gear (0=neutral when 0xffffb53a==1, else 1-6) written by 0x2c3b2 (pool 0x2c3de) from candidate 0xffffbc3c after >0xb confirmation counts; also read by 0xe64a/0x13bee/0x1ef0a/0x1fd78. Emulator: ratio 71.9 -> 2 latched; neutral -> 0.
 */
/* ROM address: 0x0004de1c; body bytes: 164; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0004de42) */
/* WARNING: Removing unreachable block (ram,0x0004de52) */
/* WARNING: Removing unreachable block (ram,0x0004de64) */
/* WARNING: Removing unreachable block (ram,0x0004de78) */
/* WARNING: Removing unreachable block (ram,0x0004de8c) */
/* WARNING: Removing unreachable block (ram,0x0004dea0) */
/* WARNING: Removing unreachable block (ram,0x0004deb4) */
/* WARNING: Removing unreachable block (ram,0x0004deac) */
/* WARNING: Removing unreachable block (ram,0x0004de98) */
/* WARNING: Removing unreachable block (ram,0x0004de84) */
/* WARNING: Removing unreachable block (ram,0x0004de70) */
/* WARNING: Removing unreachable block (ram,0x0004de5e) */
/* WARNING: Removing unreachable block (ram,0x0004deb0) */
/* WARNING: Removing unreachable block (ram,0x0004de4e) */

undefined4 FUN_0004de1c(void)

{
  undefined4 uVar1;
  undefined4 extraout_fr0;
  
  uVar1 = rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffbc3d);
  DAT_ffffcf1c = extraout_fr0;
  return uVar1;
}


