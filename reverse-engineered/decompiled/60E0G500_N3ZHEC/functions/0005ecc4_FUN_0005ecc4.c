/* ROM address: 0x0005ecc4; body bytes: 104; decompiled */

void FUN_0005ecc4(void)

{
  undefined1 *puVar1;
  
  DAT_ffffd3c4 = DAT_ffffad90 == '\x01';
  if (DAT_ffffbfa4 == '\x01') {
    DAT_ffffd3c4 = DAT_ffffd3c4 + '\x04';
  }
  if (DAT_ffffc004 == '\x01') {
    DAT_ffffd3c4 = DAT_ffffd3c4 + ' ';
  }
  if (DAT_ffffb5ab == '\x01') {
    DAT_ffffd3c4 = DAT_ffffd3c4 + '@';
  }
  DAT_ffffd3c5 = 0;
  if (DAT_ffffb5a4 == '\x01') {
    puVar1 = &DAT_0007dac2;
    DAT_ffffd3c6 = 0x65;
  }
  else {
    puVar1 = &DAT_0007dac3;
    DAT_ffffd3c6 = 5;
  }
  DAT_ffffd3c7 = *puVar1;
  return;
}


