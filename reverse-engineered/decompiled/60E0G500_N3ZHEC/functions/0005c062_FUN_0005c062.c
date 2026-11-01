/* ROM address: 0x0005c062; body bytes: 144; decompiled */

undefined4 FUN_0005c062(void)

{
  undefined4 uVar1;
  
  DAT_ffffd330 = (undefined *)
                 (((uint)DAT_ffffd33a * 0x100 + (uint)DAT_ffffd33b) * 0x10000 +
                 (uint)DAT_ffffd33c * 0x100 + (uint)DAT_ffffd33d);
  DAT_ffffd338 = (ushort)DAT_ffffd33e * 0x100 + (ushort)DAT_ffffd33f;
  DAT_ffffd334 = DAT_ffffd330 + DAT_ffffd338;
  if ((DAT_ffffd338 == 0) || (0x400 < DAT_ffffd338)) {
    uVar1 = 0xff;
  }
  else if (((DAT_ffffd334 < (undefined *)0x80001) ||
           (((undefined *)0xffff5fff < DAT_ffffd330 && (DAT_ffffd334 < &UNK_ffffe001)))) ||
          (((undefined *)0x8000007f < DAT_ffffd330 && (DAT_ffffd334 < (undefined *)0x80000101)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xff;
  }
  return uVar1;
}


