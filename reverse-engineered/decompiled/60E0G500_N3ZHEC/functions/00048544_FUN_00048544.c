/* ROM address: 0x00048544; body bytes: 916; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0004894c) */
/* WARNING: Removing unreachable block (ram,0x0004889a) */
/* WARNING: Removing unreachable block (ram,0x0004896a) */

undefined * FUN_00048544(void)

{
  char cVar2;
  undefined *puVar1;
  byte bVar3;
  
  bVar3 = 0;
  cVar2 = FUN_0003eaa4(&DAT_ffff8768,0);
  if (cVar2 == '\x01') {
    bVar3 = 3;
  }
  if ((DAT_ffffb563 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb565 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb567 == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  if ((DAT_ffffb569 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb56d == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  if ((DAT_ffffb56b == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff876c,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffccd6 == '\x01') && (bVar3 == 0)) {
    bVar3 = 1;
  }
  if ((DAT_ffffccd7 == '\x01') && (bVar3 == 0)) {
    bVar3 = 1;
  }
  if ((DAT_ffffccde == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8750,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb57c == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8780,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8764,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8770,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  cVar2 = FUN_0003eaa4(&DAT_ffff8778,0);
  if ((cVar2 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb560 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb588 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffccd3 == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  if ((DAT_ffffccd4 == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  if ((DAT_ffffccd5 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb584 == '\x01') && (bVar3 < 2)) {
    bVar3 = 2;
  }
  if ((DAT_ffffb57e == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb580 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  if ((DAT_ffffb582 == '\x01') && (bVar3 < 3)) {
    bVar3 = 3;
  }
  puVar1 = (undefined *)(uint)DAT_ffffcc8d;
  if (puVar1 == &UNK_00000001) {
    puVar1 = &DAT_0007c29b;
  }
  DAT_ffffccd2 = bVar3;
  return puVar1;
}


