/* ROM address: 0x00004f00; body bytes: 214; decompiled */

void FUN_00004f00(void)

{
  byte bVar1;
  undefined4 local_c [2];
  
  DAT_fffff401 = 0xff;
  DAT_fffff400 = 0xff;
  DAT_fffff402 = 1;
  DAT_fffff404 = 4;
  DAT_fffff406 = 4;
  DAT_fffff408 = 4;
  DAT_fffff40a = 4;
  DAT_fffff424 = 0;
  DAT_fffff426 = 0;
  DAT_fffff428 = 0;
  DAT_fffff466 = 0x80;
  DAT_fffff484 = 0;
  DAT_fffff4ac = 4;
  DAT_fffff4cc = 4;
  DAT_fffff4ec = 4;
  FUN_00002054(local_c,0xe0);
  bVar1 = DAT_fffff4ab;
  DAT_fffff4ab = bVar1 & 0x77;
  bVar1 = DAT_fffff4aa;
  DAT_fffff4aa = bVar1 & 0x77;
  bVar1 = DAT_fffff4cb;
  DAT_fffff4cb = bVar1 & 0x77;
  bVar1 = DAT_fffff4ca;
  DAT_fffff4ca = bVar1 & 0x77;
  bVar1 = DAT_fffff4eb;
  DAT_fffff4eb = bVar1 & 0x77;
  bVar1 = DAT_fffff4ea;
  DAT_fffff4ea = bVar1 & 0x77;
  FUN_00002064(local_c[0]);
  DAT_fffff521 = 0x44;
  DAT_fffff520 = 0x44;
  DAT_fffff526 = 0;
  DAT_fffff5a1 = 0x44;
  DAT_fffff5a0 = 0x41;
  DAT_fffff668 = 0x44;
  DAT_fffff66e = 0;
  FUN_00002054(local_c,0xe0);
  bVar1 = DAT_fffff698;
  DAT_fffff698 = bVar1 & 0xbb;
  bVar1 = DAT_fffff69a;
  DAT_fffff69a = bVar1 & 0xbb;
  FUN_00002064(local_c[0]);
  DAT_fffff5c8 = 1;
  return;
}


