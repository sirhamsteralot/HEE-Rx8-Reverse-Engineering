/* ROM address: 0x000489aa; body bytes: 562; decompiled */

undefined2 * FUN_000489aa(void)

{
  char cVar2;
  undefined2 *puVar1;
  undefined2 *puVar3;
  
  if (DAT_ffffcce4 == '\x01') {
    DAT_ffffcccc = FUN_00002460((int)(short)DAT_ffffcccc,1);
  }
  else {
    DAT_ffffcccc = 0;
  }
  if ((((((((((DAT_ffffcc5c == '\x01') && (DAT_ffffb564 == '\x01')) && (DAT_ffffb566 == '\x01')) &&
           ((DAT_ffffb568 == '\x01' && (DAT_ffffb56a == '\x01')))) &&
          ((DAT_ffffb56e == '\x01' && ((DAT_ffffb56c == '\x01' && (DAT_ffffcc9d == '\x01')))))) &&
         (DAT_ffffcc34 == '\x01')) &&
        (((DAT_ffffcc35 == '\x01' && (DAT_ffffcc40 == '\x01')) && (DAT_ffffcc41 == '\x01')))) &&
       (((DAT_ffffcc2c == '\x01' && (DAT_ffffcc14 == '\x01')) &&
        ((DAT_ffffb57d == '\x01' && ((DAT_ffffccad == '\x01' && (DAT_ffffcc54 == '\x01')))))))) &&
      (((DAT_ffffb561 == '\x01' &&
        (((DAT_ffffb589 == '\x01' && (DAT_ffffb571 == '\x01')) && (DAT_ffffb574 == '\x01')))) &&
       (((DAT_ffffb576 == '\x01' && (DAT_ffffb578 == '\x01')) &&
        (((DAT_ffffb57b == '\x01' && ((DAT_ffffb585 == '\x01' && (DAT_ffffb587 == '\x01')))) &&
         (DAT_ffffb57f == '\x01')))))))) &&
     (((((DAT_ffffb581 == '\x01' && (DAT_ffffb583 == '\x01')) && (DAT_ffffcca4 == '\x01')) &&
       ((DAT_ffffcca8 == '\x01' && (DAT_ffffcc8a == '\x01')))) && (DAT_ffffcc8b == '\x01')))) {
    puVar3 = (undefined2 *)&UNK_00000001;
  }
  else {
    puVar3 = (undefined2 *)0x0;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8784,0);
  puVar1 = (undefined2 *)&UNK_00000001;
  if (((cVar2 == '\x01') || (puVar1 = &DAT_0007c29c, 0x270 < DAT_ffffcccc)) ||
     (puVar1 = puVar3, puVar3 == (undefined2 *)&UNK_00000001)) {
    DAT_ffffcce4 = '\0';
  }
  return puVar1;
}


