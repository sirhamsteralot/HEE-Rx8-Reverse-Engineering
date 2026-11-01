/* ROM address: 0x00028a40; body bytes: 170; decompiled */

undefined2 * FUN_00028a40(byte param_1)

{
  undefined2 *puVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  
  bVar3 = 0;
  do {
    uVar4 = (uint)(char)param_1;
    bVar2 = 0;
    do {
      uVar4 = FUN_00002478(uVar4,0x11);
      FUN_0000420c();
      bVar2 = bVar2 + 1;
      puVar1 = (undefined2 *)(&DAT_ffff8570 + (uVar4 & 0xff) * 2 + (uint)bVar3 * 0x88);
      *puVar1 = *(undefined2 *)(&DAT_ffff8570 + (uint)param_1 * 2 + (uint)bVar3 * 0x88);
    } while (bVar2 < 3);
    bVar3 = bVar3 + 1;
  } while (bVar3 < 2);
  return puVar1;
}


