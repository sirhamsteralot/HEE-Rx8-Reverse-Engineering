/* ROM address: 0x0005538c; body bytes: 132; decompiled */

void FUN_0005538c(void)

{
  undefined4 uVar1;
  byte bVar2;
  undefined1 *puVar3;
  char *pcVar4;
  
  uVar1 = FUN_00003920(0x10);
  DAT_ffff9038 = 0;
  puVar3 = &DAT_ffff9010;
  DAT_ffff9039 = '\0';
  for (pcVar4 = &DAT_0005f560; *pcVar4 != -1; pcVar4 = pcVar4 + 2) {
    if (*pcVar4 == '\x02') {
      bVar2 = pcVar4[1];
      *puVar3 = 0xa5;
      puVar3[1] = 0x5a;
    }
    else {
      bVar2 = FUN_00055534((int)*pcVar4,puVar3);
    }
    puVar3 = puVar3 + bVar2;
    DAT_ffff9039 = DAT_ffff9039 + bVar2;
  }
  DAT_ffff903a = FUN_0005544a();
  DAT_ffff9038 = 0xa5;
  FUN_00003934(uVar1);
  return;
}


