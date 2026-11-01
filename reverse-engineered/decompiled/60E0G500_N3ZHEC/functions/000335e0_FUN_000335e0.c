/* ROM address: 0x000335e0; body bytes: 156; decompiled */

undefined * FUN_000335e0(void)

{
  undefined *puVar1;
  float fVar2;
  
  fVar2 = (float)FUN_0003eb72(0,&DAT_ffff8694);
  puVar1 = &DAT_ffffc03f;
  if ((((DAT_ffffc03f == '\0') &&
       (puVar1 = (undefined *)(uint)DAT_ffffc022, puVar1 == &UNK_00000001)) ||
      ((DAT_ffffc040 == '\0' && (puVar1 = (undefined *)(uint)DAT_ffffc021, puVar1 == &UNK_00000001))
      )) || ((((DAT_ffffc042 == '\0' &&
               (puVar1 = (undefined *)(uint)DAT_ffffc020, puVar1 == &UNK_00000001)) ||
              (DAT_ffffbd59 == '\0')) || (DAT_ffffc008 - fVar2 <= 0.1)))) {
    DAT_ffffc024 = 0;
  }
  else {
    puVar1 = (undefined *)(int)(char)DAT_ffffc041;
    if ((puVar1 == (undefined *)0x0) &&
       (puVar1 = (undefined *)(uint)DAT_ffffc01e, puVar1 == &UNK_00000001)) {
      DAT_ffffc024 = 1;
    }
  }
  DAT_ffffc03f = DAT_ffffc022;
  DAT_ffffc040 = DAT_ffffc021;
  DAT_ffffc041 = DAT_ffffc01e;
  DAT_ffffc042 = DAT_ffffc020;
  return puVar1;
}


