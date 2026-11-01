/* ROM address: 0x0005bc36; body bytes: 86; decompiled */

uint FUN_0005bc36(void)

{
  uint uVar1;
  
  if (DAT_ffffd32c == 1) {
    FUN_0005bd54();
    (*(code *)(&PTR_LAB_0005fe88)[(uint)DAT_ffffd325 * 3])(0x21);
    DAT_ffffd32c = 0;
    DAT_ffffd32d = 0;
    uVar1 = FUN_000550ca(0x21,(byte)(&DAT_0005fe82)[(uint)DAT_ffffd325 * 0xc] + 2);
    return uVar1;
  }
  return (uint)DAT_ffffd32c;
}


