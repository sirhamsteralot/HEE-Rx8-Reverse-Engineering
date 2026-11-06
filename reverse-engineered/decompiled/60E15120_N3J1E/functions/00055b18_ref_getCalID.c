/* ROM address: 0x00055b18; body bytes: 194; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00053e34 (194 bytes). Names prefixed ref_
   are inherited hypotheses. */

int ref_getCalID(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  byte bVar4;
  char *pcVar5;
  char local_38 [4];
  undefined *puStack_34;
  char *pcStack_30;
  char local_2c [9];
  undefined1 auStack_23 [3];
  undefined1 uStack_20;
  undefined1 auStack_1f [2];
  undefined1 auStack_1d [5];
  
  local_38[0] = '\0';
  uVar2 = ref_updateRAM__(param_1,local_38,1);
  pcVar5 = "N3ZHEB000.HEX";
  bVar4 = 0;
  pcStack_30 = local_2c;
  pcVar3 = pcStack_30;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    bVar4 = bVar4 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4 < 9);
  puStack_34 = &DAT_0005f6e8;
  e2ram_cached_byte_read(100,auStack_23,3);
  puStack_34 = &DAT_0005f6f4;
  e2ram_cached_byte_read(0x68,&uStack_20,1);
  puStack_34 = &DAT_0005f700;
  e2ram_cached_byte_read(0x6a,auStack_1f,2);
  puStack_34 = &DAT_0005f70c;
  e2ram_cached_byte_read(0x6c,auStack_1d,1);
  bVar4 = 0;
  pcVar3 = pcStack_30;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    uVar2 = ref_updateRAM__(uVar2,local_38,(int)cVar1);
    bVar4 = bVar4 + 1;
  } while (bVar4 < 0x10);
  return (int)local_38[0];
}


