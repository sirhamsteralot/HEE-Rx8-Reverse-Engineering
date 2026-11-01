/* ROM address: 0x0004f110; body bytes: 64; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0004f120) */

void FUN_0004f110(void)

{
  if (DAT_ffffd183 == '\x01') {
    if (DAT_ffffd00d == '\0') {
      DAT_ffffcfee = '\x02';
    }
    else if (DAT_ffffcfee != '\0') {
      DAT_ffffcfee = DAT_ffffcfee + -1;
    }
  }
  DAT_ffffd00d = DAT_ffffd183;
  return;
}


