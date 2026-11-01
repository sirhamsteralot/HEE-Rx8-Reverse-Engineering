/* ROM address: 0x00048e86; body bytes: 96; decompiled */

undefined2 * FUN_00048e86(void)

{
  char cVar1;
  undefined2 *puVar2;
  
  cVar1 = DAT_ffffaae0;
  if (DAT_ffffaae0 == '\x01') {
    puVar2 = (undefined2 *)FUN_00002460((int)DAT_ffffccf4,1);
    DAT_ffffccf4 = (short)puVar2;
    DAT_ffffccf6 = 0;
  }
  else {
    DAT_ffffccf4 = 0;
    puVar2 = (undefined2 *)FUN_00002460((int)(short)DAT_ffffccf6,1);
    DAT_ffffccf6 = (ushort)puVar2;
  }
  if ((cVar1 == '\0') && (puVar2 = &DAT_0007c2b4, 5 < DAT_ffffccf6)) {
    DAT_ffffccfa = 1;
  }
  else {
    DAT_ffffccfa = 0;
  }
  return puVar2;
}


