/* ROM address: 0x0003e102; body bytes: 324; decompiled */

undefined * FUN_0003e102(void)

{
  char cVar1;
  byte bVar2;
  undefined *puVar3;
  char cVar5;
  uint uVar4;
  undefined4 uVar6;
  
  bVar2 = DAT_ffffc684;
  cVar1 = DAT_ffffad90;
  if (DAT_ffffc684 == 0) {
    DAT_ffffc685 = 0;
  }
  else if (DAT_ffffc67c < -3.76) {
    DAT_ffffc685 = 1;
  }
  if (DAT_ffffd201 == '\x01') {
    puVar3 = &DAT_0007a880;
    DAT_ffffc682 = 0;
    DAT_ffffc684 = 0;
    DAT_ffffc680 = '\x17';
    DAT_ffffc681 = '\b';
    DAT_ffffc686 = 0;
    DAT_ffffc687 = 0;
  }
  else {
    uVar6 = DAT_ffffbc1c;
    cVar5 = FUN_00002440(DAT_ffffbc1c,0,0x3727c5ac);
    if (cVar5 == '\0') {
      FUN_0003e2a4(uVar6);
      if (DAT_ffffc680 != '\0') {
        DAT_ffffc680 = DAT_ffffc680 + -1;
      }
    }
    else {
      DAT_ffffc680 = '\x17';
      FUN_0003e2a4(uVar6);
    }
    if (DAT_ffffc683 != cVar1) {
      DAT_ffffc682 = 1;
    }
    puVar3 = (undefined *)(uint)DAT_ffffc682;
    if (puVar3 == &UNK_00000001) {
      DAT_ffffc681 = '\b';
      uVar4 = FUN_000671a4(0x4a);
      puVar3 = (undefined *)(uVar4 & 0xff);
      if (puVar3 == (undefined *)0x0) {
        DAT_ffffc687 = 1;
        DAT_ffffc686 = 0;
      }
    }
    else if (((DAT_ffffc684 == 0) && (puVar3 = (undefined *)(uint)bVar2, puVar3 == &UNK_00000001))
            && (puVar3 = (undefined *)(uint)DAT_ffffc685, puVar3 == &UNK_00000001)) {
      if (DAT_ffffc681 != '\0') {
        DAT_ffffc681 = DAT_ffffc681 + -1;
      }
      if (DAT_ffffc681 == '\0') {
        uVar4 = FUN_000671a4(0x4a);
        puVar3 = (undefined *)(uVar4 & 0xff);
        if (puVar3 == (undefined *)0x0) {
          DAT_ffffc686 = 1;
          DAT_ffffc687 = 0;
        }
      }
    }
  }
  DAT_ffffc683 = cVar1;
  return puVar3;
}


