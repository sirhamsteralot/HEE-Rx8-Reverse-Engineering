/* ROM address: 0x00028bac; body bytes: 6; decompiled */

void FUN_00028bac(void)

{
  DAT_ffffbab4 = 0xffff;
  ref_updateCAN420Data();
  ref_can420TXPack();
  DAT_ffffbab4 = 0;
  return;
}


