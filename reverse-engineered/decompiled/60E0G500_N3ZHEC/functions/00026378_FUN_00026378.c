/* ROM address: 0x00026378; body bytes: 280; decompiled */

undefined2 * FUN_00026378(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  if (DAT_ffffb600 < 10.0) {
    if (DAT_ffffb600 < 9.0) {
      DAT_ffffb6b5 = '\0';
    }
  }
  else {
    DAT_ffffb6b5 = '\x01';
  }
  if ((18.471 < DAT_ffffb6c4) || (15.938 < DAT_ffffb6c8)) {
    puVar2 = (undefined2 *)0x0;
  }
  else {
    puVar2 = (undefined2 *)&UNK_00000001;
  }
  puVar1 = puVar2;
  if (((((puVar2 == (undefined2 *)&UNK_00000001) || (DAT_ffffa428 == 0)) ||
       ((puVar1 = (undefined2 *)(uint)DAT_ffffa428, puVar1 == (undefined2 *)&UNK_00000001 &&
        (puVar1 = &DAT_000751a2, DAT_ffffb6a8 < 0x3f)))) || (DAT_ffffb6b5 == '\0')) ||
     ((DAT_ffffb6b5 == '\x01' && (puVar1 = (undefined2 *)&UNK_0000003f, DAT_ffffb6aa < 0x3f)))) {
    DAT_ffffb678 = 0x138;
  }
  else {
    puVar1 = (undefined2 *)(uint)DAT_ffffb678;
    if (puVar1 != (undefined2 *)0x0) {
      DAT_ffffb678 = DAT_ffffb678 - 1;
    }
  }
  if (DAT_ffffa428 == 0) {
    DAT_ffffb6a8 = 0;
  }
  else {
    puVar1 = (undefined2 *)FUN_00002460((int)(short)DAT_ffffb6a8,1);
    DAT_ffffb6a8 = (ushort)puVar1;
  }
  if (DAT_ffffb6b5 == '\0') {
    DAT_ffffb6aa = 0;
  }
  else {
    puVar1 = (undefined2 *)FUN_00002460((int)(short)DAT_ffffb6aa,1);
    DAT_ffffb6aa = (ushort)puVar1;
  }
  if (DAT_ffffb678 == 0) {
    DAT_ffffb620 = 1;
    puVar2 = puVar1;
  }
  else if (puVar2 == (undefined2 *)&UNK_00000001) {
    DAT_ffffb620 = 0;
  }
  return puVar2;
}


