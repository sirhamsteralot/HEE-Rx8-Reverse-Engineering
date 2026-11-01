/* ROM address: 0x000446f0; body bytes: 50; decompiled */

void FUN_000446f0(void)

{
  if ((DAT_ffffcb0a == '\0') && (DAT_ffffaada == '\x01')) {
    DAT_ffffcab2 = '\f';
  }
  else if (DAT_ffffcab2 != '\0') {
    DAT_ffffcab2 = DAT_ffffcab2 + -1;
  }
  DAT_ffffcb0a = DAT_ffffaada;
  return;
}


