/* ROM address: 0x0002b592; body bytes: 68; decompiled */

void FUN_0002b592(void)

{
  uint uVar1;
  char cVar2;
  undefined4 *puVar3;
  
  cVar2 = '\x03';
  uVar1 = 2;
  puVar3 = (undefined4 *)&DAT_ffffbbf0;
  DAT_ffffbbd4 = DAT_ffffbc1c;
  do {
    cVar2 = cVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = (&DAT_ffffbbe0)[uVar1 & 0xff];
    uVar1 = uVar1 + 0xff;
  } while (cVar2 != '\0');
  DAT_ffffbbe0 = DAT_ffffbbd4;
  DAT_ffffbbd0 = DAT_ffffbbe4;
  return;
}


