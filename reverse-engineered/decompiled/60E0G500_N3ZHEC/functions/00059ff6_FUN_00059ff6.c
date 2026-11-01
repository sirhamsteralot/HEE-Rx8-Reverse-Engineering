/* ROM address: 0x00059ff6; body bytes: 36; decompiled */

uint FUN_00059ff6(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffd296;
  if (uVar1 == 1) {
    uVar1 = thunk_FUN_00060956();
    DAT_ffffd297 = 0;
    DAT_ffffd296 = 0;
  }
  return uVar1;
}


