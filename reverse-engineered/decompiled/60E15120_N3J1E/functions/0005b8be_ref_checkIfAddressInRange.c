/* ROM address: 0x0005b8be; body bytes: 144; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005a0ae (144 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_checkIfAddressInRange(void)

{
  undefined4 uVar1;
  
  DAT_ffffd2f4 = (undefined *)
                 (((uint)DAT_ffffd2fe * 0x100 + (uint)DAT_ffffd2ff) * 0x10000 +
                 (uint)DAT_ffffd300 * 0x100 + (uint)DAT_ffffd301);
  DAT_ffffd2fc = (ushort)DAT_ffffd302 * 0x100 + (ushort)DAT_ffffd303;
  DAT_ffffd2f8 = DAT_ffffd2f4 + DAT_ffffd2fc;
  if ((DAT_ffffd2fc == 0) || (0x400 < DAT_ffffd2fc)) {
    uVar1 = 0xff;
  }
  else if (((DAT_ffffd2f8 < (undefined *)0x80001) ||
           (((undefined *)0xffff5fff < DAT_ffffd2f4 && (DAT_ffffd2f8 < &UNK_ffffe001)))) ||
          (((undefined *)0x8000007f < DAT_ffffd2f4 && (DAT_ffffd2f8 < (undefined *)0x80000101)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xff;
  }
  return uVar1;
}


