/* ROM address: 0x00018db8; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000199b4 (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00018db8(void)

{
  uint uVar1;
  
  if (DAT_ffffa966 == '\x01') {
    DAT_ffffa968 = 0x36ef;
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)DAT_ffffaa68;
    if ((uVar1 == 1) && (uVar1 = 0, DAT_ffffa968 != 0)) {
      uVar1 = (int)DAT_ffffa968 + 0xffff;
      DAT_ffffa968 = (short)uVar1;
    }
  }
  if ((DAT_ffffa968 == 0) && (uVar1 = (uint)decel_cut_request_b_ffffa96c, uVar1 != 1)) {
    DAT_ffffa965 = 0;
  }
  else {
    DAT_ffffa965 = 1;
  }
  return uVar1;
}


