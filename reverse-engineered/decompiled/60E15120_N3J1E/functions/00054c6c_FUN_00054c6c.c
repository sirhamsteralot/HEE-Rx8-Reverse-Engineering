/* ROM address: 0x00054c6c; body bytes: 58; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00052d58 (58 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00054c6c(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  puVar2 = &DAT_ffff8fe8;
  DAT_ffff9011 = 0;
  do {
    DAT_ffff9011 = DAT_ffff9011 + 1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (DAT_ffff9011 < 0x28);
  DAT_ffff9012 = (ushort)DAT_ffff9011;
  DAT_ffff9010 = 0xa5;
  ref_setSR(uVar1);
  return;
}


