/* ROM address: 0x00029808; body bytes: 118; decompiled */

char FUN_00029808(void)

{
  DAT_ffffbb1a = 0;
  if (DAT_ffffd1dd == '\x01') {
    DAT_ffffbb1a = 0x8000;
  }
  else if (DAT_ffffd1de == '\x01') {
    DAT_ffffbb1a = 0x4000;
  }
  if (DAT_ffffbbcc == '\x01') {
    DAT_ffffbb1a = DAT_ffffbb1a | 0x400;
  }
  if (DAT_ffffbbcd == '\x01') {
    DAT_ffffbb1a = DAT_ffffbb1a | 0x100;
  }
  if (DAT_ffffbbce == '\x01') {
    DAT_ffffbb1a = DAT_ffffbb1a | 0x80;
  }
  if (DAT_ffffb624 == '\x01') {
    DAT_ffffbb1a = DAT_ffffbb1a | 0x40;
  }
  if (DAT_ffffbbcf == '\x01') {
    DAT_ffffbb1a = DAT_ffffbb1a | 2;
  }
  return DAT_ffffbbcf;
}


