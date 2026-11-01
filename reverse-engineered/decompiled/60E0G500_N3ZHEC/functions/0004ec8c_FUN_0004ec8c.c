/* ROM address: 0x0004ec8c; body bytes: 116; decompiled */

undefined2 * FUN_0004ec8c(void)

{
  byte bVar1;
  undefined2 *puVar2;
  
  bVar1 = DAT_ffffd2a7;
  DAT_ffffcfc0 = 0;
  puVar2 = &DAT_ffffcfe6;
  if ((((DAT_ffffcfe6 < 0x19) || (DAT_ffffcfc1 == '\0')) || (DAT_ffffd034 != '\0')) ||
     (DAT_ffffd01c <= DAT_ffffd020)) {
    if ((DAT_ffffcfc5 == '\0') &&
       (puVar2 = (undefined2 *)(uint)DAT_ffffd2a7, puVar2 == (undefined2 *)0x1)) {
      puVar2 = (undefined2 *)FUN_00002478(0x5e,0x27);
      DAT_ffffcfc1 = (char)puVar2;
    }
  }
  else {
    puVar2 = (undefined2 *)&DAT_ffffcfc1;
    DAT_ffffcfc1 = '\0';
  }
  DAT_ffffcfc5 = bVar1;
  return puVar2;
}


