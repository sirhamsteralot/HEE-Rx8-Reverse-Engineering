/* ROM address: 0x000334f0; body bytes: 158; decompiled */

undefined * FUN_000334f0(void)

{
  undefined *puVar1;
  float fVar2;
  
  fVar2 = (float)FUN_0003eb72(0,&DAT_ffff8694);
  puVar1 = &DAT_ffffc03b;
  if ((((DAT_ffffc03b == '\0') &&
       (puVar1 = (undefined *)(uint)DAT_ffffc022, puVar1 == &UNK_00000001)) ||
      ((DAT_ffffc03c == '\0' && (puVar1 = (undefined *)(uint)DAT_ffffc021, puVar1 == &UNK_00000001))
      )) || ((((DAT_ffffc03d == '\0' &&
               (puVar1 = (undefined *)(uint)DAT_ffffc01e, puVar1 == &UNK_00000001)) ||
              (DAT_ffffbd59 == '\0')) || (fVar2 - DAT_ffffc008 <= 0.1)))) {
    DAT_ffffc023 = 0;
  }
  else {
    puVar1 = (undefined *)(int)(char)DAT_ffffc03e;
    if ((puVar1 == (undefined *)0x0) &&
       (puVar1 = (undefined *)(uint)DAT_ffffc020, puVar1 == &UNK_00000001)) {
      DAT_ffffc023 = 1;
    }
  }
  DAT_ffffc03b = DAT_ffffc022;
  DAT_ffffc03c = DAT_ffffc021;
  DAT_ffffc03d = DAT_ffffc01e;
  DAT_ffffc03e = DAT_ffffc020;
  return puVar1;
}


