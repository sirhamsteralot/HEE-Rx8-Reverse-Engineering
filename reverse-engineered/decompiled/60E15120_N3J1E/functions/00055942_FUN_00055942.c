/* ROM address: 0x00055942; body bytes: 52; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00053c5e (52 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00055942(void)

{
  undefined1 local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  
  local_c = 0x54;
  uStack_b = (undefined1)((ushort)DAT_ffffd1c6 >> 8);
  uStack_a = (undefined1)DAT_ffffd1c6;
  ref_setupForUdsResponse_(0x14,&local_c,3);
  ref_udsResponseRelated__(0x14,3);
  return;
}


