/* ROM address: 0x000291a4; body bytes: 6; decompiled */

void FUN_000291a4(void)

{
  DAT_ffffbb0c = 0xffff;
  ref_getCAN201Values();
  can201_pack_and_queue_payload();
  DAT_ffffbb0c = 0;
  return;
}


