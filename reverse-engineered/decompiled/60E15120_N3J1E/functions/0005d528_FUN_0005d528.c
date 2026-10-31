/* ROM address: 0x0005d528; body bytes: 178; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 0005bd18 (178 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005d528(uint param_1)

{
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x175f) {
      if ((DAT_ffffd36c & 0x60) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd333 = '\0';
      }
      else {
        DAT_ffffd333 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == '\a') {
          _DAT_ffffd365 = DAT_ffffd316;
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0x60) == 0) {
        DAT_ffffd333 = '\0';
      }
    }
  }
  if (DAT_ffffd333 == '\0') {
    _DAT_ffffd365 = (ushort)param_1;
  }
  else if ((DAT_ffffd333 == '\x05') || (DAT_ffffd333 == '\a')) {
    param_1 = (uint)_DAT_ffffd365;
  }
  return param_1;
}


