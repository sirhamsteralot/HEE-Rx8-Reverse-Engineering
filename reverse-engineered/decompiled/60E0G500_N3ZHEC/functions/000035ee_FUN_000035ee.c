/* ROM address: 0x000035ee; body bytes: 34; decompiled */

void FUN_000035ee(void)

{
  DAT_ffff7640 = DAT_ffff7640 | (uint)(undefined *)0x8000;
  (*(code *)0x0)();
  DAT_ffff7640 = DAT_ffff7640 & (uint)&DAT_ffff7fff;
  return;
}


