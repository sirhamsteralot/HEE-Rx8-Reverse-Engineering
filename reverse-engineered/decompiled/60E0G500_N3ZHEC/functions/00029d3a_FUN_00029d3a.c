/* ROM address: 0x00029d3a; body bytes: 42; decompiled */

void FUN_00029d3a(void)

{
  DAT_ffffbb74 = DAT_ffffbb74 + 1;
  if (3 < DAT_ffffbb74) {
    FUN_00029dac();
    can201_pack_and_queue_payload();
    DAT_ffffbb74 = 0;
  }
  return;
}


