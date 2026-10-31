/* ROM address: 0x000431ba; body bytes: 244; decompiled */

undefined4 * FUN_000431ba(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0004326c;
  if (DAT_ffffca08 < 2.5) {
    DAT_ffffc9f0 = DAT_ffffc9f4;
  }
  else {
    puVar1 = &DAT_00043270;
    DAT_ffffc9f0 = DAT_ffffca6c;
    if (((3.5 <= DAT_ffffca08) &&
        (puVar1 = &DAT_00043274, DAT_ffffc9f0 = DAT_ffffca70, 4.5 <= DAT_ffffca08)) &&
       (puVar1 = &DAT_00043328, DAT_ffffc9f0 = DAT_ffffca74, 5.5 <= DAT_ffffca08)) {
      if (DAT_ffffca08 < 6.5) {
        puVar1 = &DAT_0004332c;
        DAT_ffffc9f0 = DAT_ffffca78;
      }
      else if (7.5 <= DAT_ffffca08) {
        puVar1 = &DAT_00043334;
        DAT_ffffc9f0 = DAT_ffffca80;
        if (((8.5 <= DAT_ffffca08) &&
            (puVar1 = &DAT_00043338, DAT_ffffc9f0 = DAT_ffffca84, 9.5 <= DAT_ffffca08)) &&
           ((puVar1 = &DAT_0004333c, DAT_ffffc9f0 = DAT_ffffca88, 10.5 <= DAT_ffffca08 &&
            (puVar1 = &DAT_00043340, DAT_ffffc9f0 = DAT_ffffca90, DAT_ffffca08 < 11.5)))) {
          DAT_ffffc9f0 = DAT_ffffca8c;
        }
      }
      else {
        puVar1 = &DAT_00043330;
        DAT_ffffc9f0 = DAT_ffffca7c;
      }
    }
  }
  DAT_ffffca90 = DAT_ffffca8c;
  DAT_ffffca8c = DAT_ffffca88;
  DAT_ffffca88 = DAT_ffffca84;
  DAT_ffffca84 = DAT_ffffca80;
  DAT_ffffca80 = DAT_ffffca7c;
  DAT_ffffca7c = DAT_ffffca78;
  DAT_ffffca78 = DAT_ffffca74;
  DAT_ffffca74 = DAT_ffffca70;
  DAT_ffffca70 = DAT_ffffca6c;
  DAT_ffffca6c = DAT_ffffc9f4;
  return puVar1;
}


