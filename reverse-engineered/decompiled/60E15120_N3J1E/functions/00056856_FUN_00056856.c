/* ROM address: 0x00056856; body bytes: 58; decompiled */

uint FUN_00056856(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffd1ec;
  if (uVar1 == 1) {
    uVar1 = diag22_find_and_dispatch_identifier();
    if (DAT_ffffd1e8 != -0x80) {
      DAT_ffffd1e8 = 0;
      DAT_ffffd1ec = 0;
      diag22_current_identifier_ffffd1ea = 0;
      uVar1 = ref_udsResponseRelated__(0x22,uVar1);
      return uVar1;
    }
  }
  return uVar1;
}


