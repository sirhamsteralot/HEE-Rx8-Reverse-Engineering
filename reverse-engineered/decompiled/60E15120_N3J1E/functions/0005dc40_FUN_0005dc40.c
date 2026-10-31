/* ROM address: 0x0005dc40; body bytes: 4; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0005dd66) */
/* WARNING: Removing unreachable block (ram,0x0005dd68) */
/* WARNING: Removing unreachable block (ram,0x0005dd18) */
/* WARNING: Removing unreachable block (ram,0x0005dd1e) */
/* WARNING: Removing unreachable block (ram,0x0005dd24) */
/* WARNING: Removing unreachable block (ram,0x0005dd2a) */
/* WARNING: Removing unreachable block (ram,0x0005dd60) */

undefined4 FUN_0005dc40(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  DAT_ffffd37a = 0x271;
  DAT_ffffd37c = 0;
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


