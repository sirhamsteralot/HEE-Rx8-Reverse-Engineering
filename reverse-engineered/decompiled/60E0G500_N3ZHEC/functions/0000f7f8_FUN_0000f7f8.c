/* ROM address: 0x0000f7f8; body bytes: 168; decompiled */

void FUN_0000f7f8(void)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar3 = (uint)DAT_ffff9f97;
  if (0xb < uVar3) {
    uVar3 = uVar3 - 0xc;
  }
  for (pcVar4 = &DAT_ffffa4b4; pcVar4 < &DAT_ffffa564; pcVar4 = pcVar4 + 0x58) {
    uVar1 = FUN_0000fa3a(uVar3 * 0x1e0000,*(undefined4 *)(pcVar4 + 8));
    for (pcVar5 = pcVar4 + 0x10; pcVar5 < pcVar4 + 0x58; pcVar5 = pcVar5 + 0x18) {
      injector_channel_disable((int)*pcVar5);
      pcVar5[1] = '\0';
    }
    FUN_0000ffd6(pcVar4);
    FUN_0000ff32(pcVar4);
    cVar2 = (*(code *)(&PTR_LAB_0004ea58)[*pcVar4 * 4])(pcVar4,uVar1);
    if (cVar2 == '\x01') {
      cVar2 = '\0';
    }
    else {
      cVar2 = '\x02';
    }
    pcVar4[2] = cVar2;
  }
  return;
}


