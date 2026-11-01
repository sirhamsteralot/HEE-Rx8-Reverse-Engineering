/* ROM address: 0x00065dfc; body bytes: 56; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00065dfc(void)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = (float)FUN_0006041c();
  fVar3 = (float)FUN_00060422();
  puVar1 = &DAT_00065ef8;
  if ((71.0 <= fVar2) && (puVar1 = &DAT_00065efc, 22.0 <= fVar2 - fVar3)) {
    puVar1 = (undefined4 *)FUN_00002420(1);
    _DAT_ffff8ea6 = SUB42(puVar1,0);
  }
  return puVar1;
}


