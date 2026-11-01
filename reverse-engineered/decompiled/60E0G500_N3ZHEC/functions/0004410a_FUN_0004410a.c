/* ROM address: 0x0004410a; body bytes: 244; decompiled */

undefined4 * FUN_0004410a(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_000441bc;
  if (DAT_ffffca78 < 2.5) {
    DAT_ffffca60 = DAT_ffffca64;
  }
  else {
    puVar1 = &DAT_000441c0;
    DAT_ffffca60 = DAT_ffffcadc;
    if (((3.5 <= DAT_ffffca78) &&
        (puVar1 = &DAT_000441c4, DAT_ffffca60 = DAT_ffffcae0, 4.5 <= DAT_ffffca78)) &&
       (puVar1 = &DAT_00044278, DAT_ffffca60 = DAT_ffffcae4, 5.5 <= DAT_ffffca78)) {
      if (DAT_ffffca78 < 6.5) {
        puVar1 = &DAT_0004427c;
        DAT_ffffca60 = DAT_ffffcae8;
      }
      else if (7.5 <= DAT_ffffca78) {
        puVar1 = &DAT_00044284;
        DAT_ffffca60 = DAT_ffffcaf0;
        if (((8.5 <= DAT_ffffca78) &&
            (puVar1 = &DAT_00044288, DAT_ffffca60 = DAT_ffffcaf4, 9.5 <= DAT_ffffca78)) &&
           ((puVar1 = &DAT_0004428c, DAT_ffffca60 = DAT_ffffcaf8, 10.5 <= DAT_ffffca78 &&
            (puVar1 = &DAT_00044290, DAT_ffffca60 = DAT_ffffcb00, DAT_ffffca78 < 11.5)))) {
          DAT_ffffca60 = DAT_ffffcafc;
        }
      }
      else {
        puVar1 = &DAT_00044280;
        DAT_ffffca60 = DAT_ffffcaec;
      }
    }
  }
  DAT_ffffcb00 = DAT_ffffcafc;
  DAT_ffffcafc = DAT_ffffcaf8;
  DAT_ffffcaf8 = DAT_ffffcaf4;
  DAT_ffffcaf4 = DAT_ffffcaf0;
  DAT_ffffcaf0 = DAT_ffffcaec;
  DAT_ffffcaec = DAT_ffffcae8;
  DAT_ffffcae8 = DAT_ffffcae4;
  DAT_ffffcae4 = DAT_ffffcae0;
  DAT_ffffcae0 = DAT_ffffcadc;
  DAT_ffffcadc = DAT_ffffca64;
  return puVar1;
}


