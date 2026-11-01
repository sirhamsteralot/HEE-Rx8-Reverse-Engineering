/* ROM address: 0x00003588; body bytes: 34; decompiled */

void FUN_00003588(void)

{
  DAT_ffff7640 = DAT_ffff7640 | (uint)&DAT_00010000;
  (*(code *)0x0)();
  DAT_ffff7640 = DAT_ffff7640 & 0xfffeffff;
  return;
}


