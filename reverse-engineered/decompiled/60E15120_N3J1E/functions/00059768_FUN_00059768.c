/* ROM address: 0x00059768; body bytes: 112; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00057f20 (112 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00059768(void)

{
  undefined4 uVar1;
  char cVar2;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  cVar2 = FUN_00055e2a();
  if ((DAT_ffffd272 == '\x01') || (DAT_ffffd27e != cVar2)) {
    DAT_ffffd25c = '\0';
    DAT_ffffd272 = '\0';
  }
  if (DAT_ffffd25c == '\0') {
    DAT_ffffd250 = 0;
  }
  if ((DAT_ffffd27f == '\x01') && (DAT_ffffd25c == '\0')) {
    DAT_ffffd25a = 1;
  }
  DAT_ffffd27f = DAT_ffffd25c;
  DAT_ffffd27e = cVar2;
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


