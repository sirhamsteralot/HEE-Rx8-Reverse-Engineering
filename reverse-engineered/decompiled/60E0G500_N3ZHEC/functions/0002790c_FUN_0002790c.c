/* ROM address: 0x0002790c; body bytes: 304; decompiled */

undefined4 * FUN_0002790c(void)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  
  cVar2 = DAT_ffffd201;
  cVar1 = DAT_ffffbac8;
  fVar4 = 3000.0;
  fVar5 = DAT_ffffb5b8;
  if (((DAT_ffffb730 == '\0') && (DAT_ffffd201 == '\0')) && (DAT_ffffb72f == DAT_ffffbac8)) {
    DAT_ffffb72c = FUN_00002460((int)DAT_ffffb72c,1);
  }
  else {
    DAT_ffffb72c = 0;
  }
  puVar3 = (undefined4 *)(uint)DAT_ffffb71a;
  if ((((puVar3 != (undefined4 *)&UNK_00000001) || (fVar4 <= DAT_ffffb710)) ||
      ((puVar3 = (undefined4 *)(uint)DAT_ffffb71b, puVar3 != (undefined4 *)&UNK_00000001 ||
       ((puVar3 = (undefined4 *)(int)DAT_ffffb13a, puVar3 != (undefined4 *)0x0 ||
        (DAT_ffffaa10 <= 0.0)))))) ||
     ((puVar3 = &DAT_ffffa9b0, 0.0 < DAT_ffffa9b0 ||
      (((((fVar5 < 660.0 || (4500.0 <= fVar5)) ||
         (puVar3 = &DAT_ffffc12c, DAT_ffffc12c < DAT_ffffb708)) ||
        ((DAT_ffffa41c != '\0' || (puVar3 = (undefined4 *)&DAT_ffffb72c, DAT_ffffcfcc <= 0.0)))) ||
       (cVar2 != '\0')))))) {
    DAT_ffffb71c = 0;
  }
  else {
    DAT_ffffb71c = 1;
  }
  DAT_ffffb72f = cVar1;
  DAT_ffffb730 = cVar2;
  return puVar3;
}


