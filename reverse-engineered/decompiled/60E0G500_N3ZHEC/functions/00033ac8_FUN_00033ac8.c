/* ROM address: 0x00033ac8; body bytes: 100; decompiled */

undefined1 * FUN_00033ac8(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  float fVar3;
  
  puVar1 = &DAT_ffffa428;
  if (DAT_ffffa428 == '\0') {
    uVar2 = DAT_ffffae58;
    fVar3 = DAT_ffffaa1c;
    DAT_ffffc088 = FUN_000020dc(DAT_ffffaa1c,DAT_ffffae58,&DAT_0006b330);
    DAT_ffffc08c = (float)FUN_000020dc(fVar3,uVar2,&DAT_0006b34c);
    puVar1 = (undefined1 *)(uint)DAT_ffffce6f;
    if (((puVar1 == (undefined1 *)0x1) && (0.0 <= fVar3)) && (fVar3 <= 26.6)) {
      DAT_ffffc08c = DAT_ffffc08c * 0.75;
    }
  }
  return puVar1;
}


