/* ROM address: 0x00007be4; body bytes: 40; decompiled */

undefined * FUN_00007be4(void)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)(uint)DAT_ffff9f96;
  if (puVar1 == &UNK_00000001) {
    puVar1 = &DAT_ffff9f97;
    DAT_ffff9fc6 = DAT_ffff9f95;
    if (0xb < DAT_ffff9f97) {
      DAT_ffff9fc6 = DAT_ffff9f95 + '$';
    }
  }
  else {
    DAT_ffff9fc6 = -1;
  }
  return puVar1;
}


