/* ROM address: 0x000687e8; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000670d8 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_000687e8(void)

{
  uds_tx_buffer_ffffddd0 = uds_tx_buffer_ffffddd0 | (byte)((ushort)DAT_ffffdddc >> 8);
  DAT_ffffddd1 = (undefined1)DAT_ffffdddc;
  FUN_00067e78((int)DAT_ffffdde2,&DAT_ffffddd2,6);
  DAT_ffffdde3 = 1;
  DAT_ffffdde1 = 6;
  FUN_00068bc6(4,0x30);
  return;
}


