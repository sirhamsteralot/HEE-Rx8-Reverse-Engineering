/* ROM address: 0x000305f0; body bytes: 204; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0003066e) */
/* WARNING: Removing unreachable block (ram,0x00030676) */
/* WARNING: Removing unreachable block (ram,0x00030686) */
/* WARNING: Removing unreachable block (ram,0x0003068c) */
/* WARNING: Removing unreachable block (ram,0x00030696) */
/* WARNING: Removing unreachable block (ram,0x000306a2) */

undefined4 FUN_000305f0(void)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  float extraout_fr0;
  undefined4 extraout_fr0_00;
  undefined4 uVar3;
  float fVar4;
  
  uVar3 = DAT_ffffb600;
  fVar4 = DAT_ffffae54;
  uVar1 = FUN_00002068(DAT_ffffad8c,&DAT_0006ae64);
  DAT_ffffbe3c = extraout_fr0;
  if (fVar4 <= extraout_fr0 * 200.0 - DAT_ffffbe34) {
    if (fVar4 <= extraout_fr0 * 190.0 - DAT_ffffbe34) {
      ppuVar2 = &PTR_DAT_0006ae8c;
    }
    else {
      ppuVar2 = &PTR_DAT_0006ae78;
    }
    uVar1 = FUN_00002068(uVar3,ppuVar2);
    DAT_ffffbe38 = 0;
    DAT_ffffbe30 = extraout_fr0_00;
  }
  else {
    DAT_ffffbe30 = 0;
    DAT_ffffbe38 = 1;
  }
  DAT_ffffbe34 = 0.0;
  return uVar1;
}


