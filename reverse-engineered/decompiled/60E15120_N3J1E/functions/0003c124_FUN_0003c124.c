/* ROM address: 0x0003c124; body bytes: 260; decompiled */

char FUN_0003c124(void)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  
  bVar3 = false;
  cVar2 = '\x01';
  if (DAT_ffffc58e == '\0') {
    if (maf_scaled_latched_ffffa9e8 <= 2.0) {
      if (DAT_ffffc5c8 == '\0') {
        bVar3 = true;
      }
      else {
        DAT_ffffc5c8 = DAT_ffffc5c8 + -1;
      }
    }
    else {
      DAT_ffffc5c8 = '\x03';
    }
  }
  else {
    DAT_ffffc5c8 = '\0';
    bVar3 = true;
  }
  if (((engine_stopped_latch_ffffa41c == '\0') || (DAT_ffffc590 == '\x01')) || (DAT_ffffc594 == '\x01')) {
    DAT_ffffc5c9 = -0x7d;
  }
  else if (DAT_ffffc5c9 == '\0') {
    cVar2 = '\0';
  }
  else {
    DAT_ffffc5c9 = DAT_ffffc5c9 + -1;
  }
  cVar1 = DAT_ffffd1c5;
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc5cb = 0;
    DAT_ffffc5cc = 0;
  }
  else if (((engine_stopped_latch_ffffa41c != '\0') && (cVar1 = '\x01', !bVar3)) && (cVar1 = '\x01', cVar2 != '\x01')
          ) {
    if (DAT_ffffc5ca != '\0') {
      DAT_ffffc5ca = DAT_ffffc5ca + -1;
      return cVar2;
    }
    if (DAT_ffffc5cd != '\x01') {
      return DAT_ffffc5cd;
    }
    cVar2 = ref_getFaultStatus__(0x25);
    if (cVar2 != '\0') {
      return cVar2;
    }
    DAT_ffffc5cb = 0;
    DAT_ffffc5cc = 1;
    return '\0';
  }
  DAT_ffffc5ca = 0x83;
  return cVar1;
}


