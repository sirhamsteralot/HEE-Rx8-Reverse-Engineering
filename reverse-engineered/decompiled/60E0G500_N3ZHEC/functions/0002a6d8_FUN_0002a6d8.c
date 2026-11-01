/* ROM address: 0x0002a6d8; body bytes: 170; decompiled */

char * FUN_0002a6d8(void)

{
  byte bVar2;
  char *pcVar1;
  byte bVar3;
  char *pcVar4;
  
  bVar3 = DAT_ffffbcee;
  bVar2 = FUN_000024d0(0x41980000,0x3f800000,0);
  if (bVar2 < bVar3) {
    bVar3 = bVar2;
  }
  pcVar4 = (char *)((short)(ushort)bVar3 * 5);
  pcVar1 = pcVar4;
  if (((((((&DAT_00075d5c)[(int)pcVar4] == '\0') && (pcVar1 = pcVar4 + 0x75d5d, *pcVar1 == '\0')) &&
        (pcVar1 = pcVar4 + 0x75d5e, *pcVar1 == '\0')) &&
       ((pcVar1 = pcVar4 + 0x75d5f, *pcVar1 == '\0' &&
        (pcVar1 = (char *)(uint)DAT_ffffa428, pcVar1 == "")))) &&
      (pcVar1 = (char *)(int)DAT_ffffaada, pcVar1 == (char *)0x0)) ||
     ((DAT_ffffa9bc == 0 && (pcVar1 = (char *)(uint)DAT_ffffa9be, pcVar1 != (char *)0x0)))) {
    DAT_ffffbb8e = 1;
  }
  else {
    DAT_ffffbb8e = 0;
  }
  return pcVar1;
}


