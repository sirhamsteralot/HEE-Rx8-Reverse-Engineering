/* ROM address: 0x00054be8; body bytes: 132; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00052cd4 (132 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00054be8(void)

{
  undefined4 uVar1;
  byte bVar2;
  undefined1 *puVar3;
  char *pcVar4;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  DAT_ffff9010 = 0;
  puVar3 = &DAT_ffff8fe8;
  DAT_ffff9011 = '\0';
  for (pcVar4 = &DAT_0005edbc; *pcVar4 != -1; pcVar4 = pcVar4 + 2) {
    if (*pcVar4 == '\x02') {
      bVar2 = pcVar4[1];
      *puVar3 = 0xa5;
      puVar3[1] = 0x5a;
    }
    else {
      bVar2 = FUN_00054d90((int)*pcVar4,puVar3);
    }
    puVar3 = puVar3 + bVar2;
    DAT_ffff9011 = DAT_ffff9011 + bVar2;
  }
  DAT_ffff9012 = FUN_00054ca6();
  DAT_ffff9010 = 0xa5;
  ref_setSR(uVar1);
  return;
}


