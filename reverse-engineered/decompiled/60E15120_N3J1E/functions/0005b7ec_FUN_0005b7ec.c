/* ROM address: 0x0005b7ec; body bytes: 162; decompiled */

uint FUN_0005b7ec(void)

{
  uint uVar1;
  undefined1 local_98 [132];
  
  uVar1 = (uint)DAT_ffffd308;
  if (uVar1 == 1) {
    if (DAT_ffffd309 == '\0') {
      DAT_ffffd309 = '\x01';
      FUN_0005b984();
      DAT_ffffd304 = DAT_ffffd2f4;
      local_98[0] = 99;
      ref_setupForUdsResponse_(0x23,local_98,1);
    }
    for (uVar1 = 0; (DAT_ffffd304 < DAT_ffffd2f8 && ((uVar1 & 0xffff) < 0x80)); uVar1 = uVar1 + 1) {
      local_98[uVar1 & 0xffff] = *DAT_ffffd304;
      DAT_ffffd304 = DAT_ffffd304 + 1;
    }
    uVar1 = ref_setupForUdsResponse_(0x23,local_98,uVar1);
    if (DAT_ffffd2f8 <= DAT_ffffd304) {
      DAT_ffffd308 = 0;
      DAT_ffffd309 = '\0';
      uVar1 = ref_udsResponseRelated__(0x23,DAT_ffffd2fc + 1);
    }
  }
  return uVar1;
}


