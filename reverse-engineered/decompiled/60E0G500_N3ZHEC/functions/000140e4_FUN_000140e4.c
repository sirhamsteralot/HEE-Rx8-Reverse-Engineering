/* ROM address: 0x000140e4; body bytes: 82; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001410a) */

uint iat_timing_compensation_on_throttle(void)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 extraout_fr0;
  
  if (DAT_ffffaada == 1) {
    puVar2 = &DAT_0006a65c;
  }
  else {
    if (DAT_ffffc12c < 0.5) {
      DAT_ffffa788 = 0;
      DAT_ffffa78c = 0;
      return (uint)DAT_ffffaada;
    }
    puVar2 = &DAT_0006a648;
  }
  uVar1 = FUN_00002068(DAT_ffffae54,puVar2);
  DAT_ffffa788 = extraout_fr0;
  DAT_ffffa78c = extraout_fr0;
  return uVar1;
}


