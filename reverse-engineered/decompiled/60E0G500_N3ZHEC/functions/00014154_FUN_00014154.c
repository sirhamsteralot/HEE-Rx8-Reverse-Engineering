/* ROM address: 0x00014154; body bytes: 82; decompiled */

undefined4 * FUN_00014154(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 extraout_fr0;
  
  if (DAT_ffffaada == '\x01') {
    puVar2 = &DAT_0006e450;
    puVar1 = (undefined4 *)&UNK_00000001;
  }
  else {
    puVar1 = &DAT_0006e44c;
    if ((-40.0 <= DAT_ffffaa10) && (0.5 <= DAT_ffffc12c)) {
      puVar1 = (undefined4 *)FUN_000020dc(DAT_ffffb5b8,&DAT_00069914);
      DAT_ffffa790 = extraout_fr0;
      DAT_ffffa794 = extraout_fr0;
      return puVar1;
    }
    puVar2 = &DAT_0006e454;
  }
  DAT_ffffa790 = *puVar2;
  DAT_ffffa794 = *puVar2;
  return puVar1;
}


