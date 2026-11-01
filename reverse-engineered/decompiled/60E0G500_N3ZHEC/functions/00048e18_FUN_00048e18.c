/* ROM address: 0x00048e18; body bytes: 48; decompiled */

undefined1 FUN_00048e18(void)

{
  bool bVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  
  uVar2 = DAT_ffffb520;
  DAT_ffffcd06 = 1;
  DAT_ffffcd10 = DAT_ffffb520;
  cVar3 = '\x04';
  bVar1 = true;
  puVar4 = (undefined4 *)0xffffcd24;
  while (bVar1) {
    cVar3 = cVar3 + -1;
    bVar1 = cVar3 != '\0';
    puVar4 = puVar4 + -1;
    *puVar4 = uVar2;
  }
  return 4;
}


