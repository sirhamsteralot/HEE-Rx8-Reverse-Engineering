/* ROM address: 0x00000806; body bytes: 94; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00000806 (94 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00000806(int param_1)

{
  int iVar1;
  undefined1 local_18 [4];
  int iStack_14;
  byte bStack_10;
  uint uStack_c;
  
  bStack_10 = *(byte *)(param_1 + 1) & 7;
  if (DAT_ffffdfb8 == '\0') {
    DAT_ffffdfb8 = '\x01';
    DAT_ffffdfbc = DAT_ffffdfa0;
  }
  uStack_c = (uint)bStack_10;
  iStack_14 = param_1;
  iVar1 = FUN_0000087c(param_1 + 2,uStack_c,DAT_ffffdfbc);
  DAT_ffffdfbc = uStack_c + DAT_ffffdfbc;
  if (iVar1 == -1) {
    local_18[0] = 2;
    FUN_00000338(0xa8,1,local_18);
  }
  return;
}


