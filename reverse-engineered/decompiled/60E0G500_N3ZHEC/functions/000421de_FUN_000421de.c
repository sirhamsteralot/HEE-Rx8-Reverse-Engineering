/* ROM address: 0x000421de; body bytes: 610; decompiled */

undefined4 * FUN_000421de(void)

{
  undefined4 *puVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined4 *)(uint)DAT_ffffc978;
  if (puVar1 == (undefined4 *)0x1) {
    uVar5 = 0;
    if (DAT_ffffd201 == '\x01') {
      DAT_ffffc85a = '\0';
      DAT_ffffc856 = '\0';
      DAT_ffffc85b = '\0';
      DAT_ffffc857 = '\0';
      DAT_ffffc85c = '\0';
      DAT_ffffc858 = '\0';
      DAT_ffffc85d = '\0';
      DAT_ffffc859 = '\0';
      DAT_ffffc772 = '\0';
      DAT_ffffc773 = '\0';
      DAT_ffffc84a = 0;
      DAT_ffffc810 = 0.0;
      DAT_ffffc814 = 0.0;
      DAT_ffffc818 = 0.0;
      DAT_ffffc81c = 0.0;
      DAT_ffffc768 = 0.0;
      DAT_ffffc76c = 0.0;
      DAT_ffffc808 = 0.0;
      DAT_ffffc80c = 0.0;
    }
    else {
      uVar3 = DAT_ffffc12c;
      uVar4 = DAT_ffffb5b8;
      DAT_ffffc7f8 = (float)FUN_000020dc(DAT_ffffc12c,DAT_ffffb5b8,&DAT_0006ba20);
      DAT_ffffc7fc = (float)FUN_000020dc(uVar3,uVar4,&DAT_0006ba3c);
      DAT_ffffc800 = (float)FUN_000020dc(uVar3,uVar4,&PTR_DAT_00010000_1_0006ba58);
      DAT_ffffc804 = (float)FUN_000020dc(uVar3,uVar4,&PTR_DAT_00010000_1_0006ba74);
      if ((DAT_ffffc774 == '\x01') && (DAT_ffffae99 == '\x01')) {
        DAT_ffffc84a = FUN_00002460((int)DAT_ffffc84a,1);
        fVar2 = (float)FUN_000024c0(0x3f800000,uVar5,(int)DAT_ffffc84a);
        DAT_ffffc810 = DAT_ffffc7f8 + DAT_ffffc810;
        DAT_ffffc814 = DAT_ffffc7fc + DAT_ffffc814;
        DAT_ffffc818 = DAT_ffffc800 + DAT_ffffc818;
        DAT_ffffc81c = DAT_ffffc804 + DAT_ffffc81c;
        DAT_ffffc768 = DAT_ffffc810 / fVar2;
        DAT_ffffc76c = DAT_ffffc814 / fVar2;
        DAT_ffffc808 = DAT_ffffc818 / fVar2;
        DAT_ffffc80c = DAT_ffffc81c / fVar2;
      }
      if (DAT_ffffc771 == '\x01') {
        if (DAT_ffffc760 <= DAT_ffffc768) {
          DAT_ffffc85a = '\x01';
        }
        else {
          DAT_ffffc856 = '\x01';
        }
        if (DAT_ffffc764 <= DAT_ffffc76c) {
          DAT_ffffc85b = '\x01';
        }
        else {
          DAT_ffffc857 = '\x01';
        }
        if (DAT_ffffc7f0 <= DAT_ffffc808) {
          DAT_ffffc85c = '\x01';
        }
        else {
          DAT_ffffc858 = '\x01';
        }
        if (DAT_ffffc7f4 <= DAT_ffffc80c) {
          DAT_ffffc85d = '\x01';
        }
        else {
          DAT_ffffc859 = '\x01';
        }
      }
      if ((((DAT_ffffc856 == '\x01') && (DAT_ffffc857 == '\x01')) && (DAT_ffffc858 == '\x01')) &&
         (DAT_ffffc859 == '\x01')) {
        DAT_ffffc772 = '\x01';
      }
      if (((DAT_ffffc85a == '\x01') || (DAT_ffffc85b == '\x01')) ||
         ((DAT_ffffc85c == '\x01' || (DAT_ffffc85d == '\x01')))) {
        DAT_ffffc773 = '\x01';
      }
      if (DAT_ffffc773 == '\x01') {
        FUN_000604dc(0x1c,1);
      }
      else if (DAT_ffffc772 == '\x01') {
        FUN_000604dc(0x1c,2);
      }
    }
    puVar1 = &DAT_00042530;
    DAT_ffffc75c = (DAT_ffffc760 + DAT_ffffc764) * 0.5;
  }
  return puVar1;
}


