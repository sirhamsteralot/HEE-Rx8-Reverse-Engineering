/* ROM address: 0x0000481c; body bytes: 82; decompiled */

uint FUN_0000481c(void)

{
  int iVar1;
  uint in_stack_00000000;
  uint in_stack_00000004;
  
  if ((short)in_stack_00000000 < 0x7fff) {
    iVar1 = (short)in_stack_00000000 + 0x7f;
    if (iVar1 < 0xff) {
      if (iVar1 < 1) {
        iVar1 = 0;
        in_stack_00000004 = 0;
      }
      goto LAB_00004880;
    }
  }
  else if (in_stack_00000004 != 0) {
    iVar1 = 0xff;
    in_stack_00000000 = 0;
    in_stack_00000004 = 0x100;
    goto LAB_00004880;
  }
  iVar1 = 0xff;
  in_stack_00000004 = 0;
LAB_00004880:
  return ((in_stack_00000004 & 0x7fffffff) >> 7 | iVar1 << 0x18) >> 1 |
         (uint)((in_stack_00000000 & 0x80000000) != 0) * -0x80000000;
}


