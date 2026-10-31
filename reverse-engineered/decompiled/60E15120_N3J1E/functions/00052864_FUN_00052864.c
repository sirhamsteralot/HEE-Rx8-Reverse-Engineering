/* ROM address: 0x00052864; body bytes: 44; decompiled */

uint FUN_00052864(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (uint)DAT_ffffd03d;
  if (uVar1 == 1) {
    uVar2 = sh_raise_interrupt_mask_return_previous(0x10);
    DAT_ffffd10c = 0;
    uVar1 = ref_setSR(uVar2);
  }
  return uVar1;
}


