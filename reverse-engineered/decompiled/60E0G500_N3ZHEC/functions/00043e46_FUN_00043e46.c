/* ROM address: 0x00043e46; body bytes: 60; decompiled */

void FUN_00043e46(void)

{
  DAT_ffffca48 = ((DAT_ffffca5c * DAT_ffffca4c - DAT_ffffcac4 * DAT_ffffca4c) -
                 DAT_ffffca50 * DAT_ffffcac8) - DAT_ffffca54 * DAT_ffffcacc;
  DAT_ffffcac4 = DAT_ffffca5c;
  DAT_ffffcacc = DAT_ffffcac8;
  DAT_ffffcac8 = DAT_ffffca48;
  return;
}


