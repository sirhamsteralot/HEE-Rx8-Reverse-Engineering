/* ROM address: 0x000692b4; body bytes: 18; decompiled */

void uds_rx_channel_set_service(byte param_1,undefined1 param_2)

{
  (&DAT_ffffde2f)[(uint)param_1 * 2] = param_2;
  (&DAT_ffffde30)[(uint)param_1 * 2] = 4;
  FUN_00068530();
  return;
}


