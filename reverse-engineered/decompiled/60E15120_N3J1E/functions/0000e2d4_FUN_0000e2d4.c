/* [ADDITIONAL SOURCE REVIEW]
 * fuel_cut_arbitration [high]: 324 B. Computes DAT_ffffa430 (u16) fuel-cut bitmask for both rotor banks from rev-limit/fuel-cut flags and the immobilizer: pool words 0xe406/0xe43c = 0xc1d0 read with 'tst r0,r0' — c1d0==0 sets the cut bits. Disasm at 0xe364-0xe36c (bank A) and 0xe426-0xe42c (bank B); store 'mov.w r4,@r3' at 0xe438 with pool 0xe43e=0xa430. Dynamically verified in the emulator: a430=0x0003 with c1d0=0, 0x0000 with c1d0=1 (all other flags 0). Callers: 0x34a04, 0xedc4, 0x1de6c, 0x2ca10, 0x4737a.
 */
/* ROM address: 0x0000e2d4; body bytes: 324; decompiled */

int FUN_0000e2d4(void)

{
  int iVar1;
  
  DAT_ffffa430 = 0;
  if ((((fuel_cut_flag_a_ffffa444 == '\x01') || (rev_limit_state_a_ffffa4a4 == '\x01')) || (fuel_cut_allowed_ffffa964 == '\x01')) ||
     ((((DAT_ffffc99c == '\x01' || (DAT_ffffcc71 == '\x01')) ||
       ((DAT_ffffbc86 == '\x01' || ((DAT_ffffcc72 == '\x01' || (DAT_ffffca45 == '\x01')))))) ||
      ((DAT_ffffcdbe == '\x01' ||
       ((((DAT_ffffcdbf == '\x01' || (DAT_ffffcdc0 == '\x01')) || (DAT_ffffcdc1 == '\x01')) ||
        (inferred_ram_c1d0_ffffc1d0_ffffc1d0 == '\0')))))))) {
    DAT_ffffa430 = 1;
  }
  iVar1 = 1;
  if (((fuel_cut_flag_b_ffffa445 == '\x01') || (iVar1 = 1, rev_limit_state_b_ffffa4a5 == '\x01')) ||
     ((((iVar1 = 1, fuel_cut_allowed_ffffa964 == '\x01' ||
        ((iVar1 = 1, DAT_ffffc99c == '\x01' || (iVar1 = 1, DAT_ffffcc71 == '\x01')))) ||
       (iVar1 = 1, DAT_ffffbc87 == '\x01')) ||
      ((((iVar1 = 1, DAT_ffffcc73 == '\x01' || (iVar1 = 1, DAT_ffffca45 == '\x01')) ||
        (iVar1 = 1, DAT_ffffcdbe == '\x01')) ||
       (((iVar1 = 1, DAT_ffffcdbf == '\x01' || (iVar1 = 1, DAT_ffffcdc0 == '\x01')) ||
        ((iVar1 = 1, DAT_ffffcdc1 == '\x01' || (iVar1 = (int)inferred_ram_c1d0_ffffc1d0_ffffc1d0, iVar1 == 0)))))))))) {
    DAT_ffffa430 = DAT_ffffa430 | 2;
  }
  return iVar1;
}


