/* ROM address: 0x00039610; body bytes: 294; decompiled */

undefined2 * FUN_00039610(void)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined *puVar3;
  float fVar4;
  float fVar5;
  
  if (DAT_ffffc574 == '\x01') {
    puVar3 = &DAT_0006b71c;
  }
  else {
    puVar3 = &DAT_0006b708;
  }
  fVar4 = DAT_ffffc554;
  fVar5 = DAT_ffffaa1c;
  DAT_ffffc57c = (float)FUN_00002068(DAT_ffffaa1c,puVar3);
  DAT_ffffc590 = FUN_000020c4(fVar5,&DAT_0006b744);
  DAT_ffffc58c = (float)FUN_00002068(fVar5,&DAT_0006b730);
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffc570 = 0;
    DAT_ffffc571 = 0;
    puVar1 = (undefined2 *)&UNK_00000001;
  }
  else {
    puVar1 = &DAT_ffffc568;
    if ((0x49 < DAT_ffffc568) && (76.25 < DAT_ffffc538)) {
      uVar2 = FUN_000671a4(0x18);
      puVar1 = (undefined2 *)(uVar2 & 0xff);
      if ((puVar1 == (undefined2 *)0x0) && ((fVar5 < 35.625 && (DAT_ffffc66e == '\0')))) {
        uVar2 = FUN_0003eaa4(&DAT_ffff8fe4,0);
        puVar1 = (undefined2 *)(uVar2 & 0xff);
        if ((puVar1 == (undefined2 *)&UNK_00000001) &&
           ((puVar1 = &DAT_ffffc590, DAT_ffffa424 < DAT_ffffc590 && (DAT_ffffc572 == '\0')))) {
          uVar2 = FUN_00060194(0x1e,0);
          puVar1 = (undefined2 *)(uVar2 & 0xff);
          if (puVar1 == (undefined2 *)0x0) {
            uVar2 = FUN_00060194(0x1f,0);
            puVar1 = (undefined2 *)(uVar2 & 0xff);
            if (((puVar1 == (undefined2 *)0x0) && (DAT_ffffc600 == '\0')) &&
               (puVar1 = (undefined2 *)(int)DAT_ffffc656, puVar1 == (undefined2 *)0x0)) {
              if (DAT_ffffc58c <= fVar4) {
                if (DAT_ffffc57c < fVar4) {
                  DAT_ffffc570 = 1;
                  DAT_ffffc571 = 0;
                }
              }
              else {
                DAT_ffffc571 = 1;
                DAT_ffffc570 = 0;
              }
            }
          }
        }
      }
    }
  }
  return puVar1;
}


