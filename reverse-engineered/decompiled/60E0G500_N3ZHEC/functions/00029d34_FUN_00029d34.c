/* ROM address: 0x00029d34; body bytes: 6; decompiled */

void FUN_00029d34(void)

{
  DAT_ffffbb74 = 0xffff;
  FUN_00029dac();
  can201_pack_and_queue_payload();
  DAT_ffffbb74 = 0;
  return;
}


