/* ROM address: 0x000384de; body bytes: 74; decompiled */

char FUN_000384de(void)

{
  if (inferred_ram_bf3c_ffffbf3c_ffffbf3c == '\x01') {
    DAT_ffffc4fe = '\x06';
  }
  else if (DAT_ffffc4fe != '\0') {
    DAT_ffffc4fe = DAT_ffffc4fe + -1;
  }
  if (DAT_ffffc4fe == '\0') {
    DAT_ffffc4ff = 0;
  }
  else if (inferred_ram_bf3c_ffffbf3c_ffffbf3c == '\x01') {
    DAT_ffffc4ff = 1;
  }
  return inferred_ram_bf3c_ffffbf3c_ffffbf3c;
}


