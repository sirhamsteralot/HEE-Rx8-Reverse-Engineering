/* ROM address: 0x00030b50; body bytes: 146; decompiled */

void injector_latency_cal_lookup(void)

{
  int iVar1;
  int iVar2;
  
  DAT_ffffbeac = (float)FUN_000020dc(DAT_ffffbe70,DAT_ffffb600,&DAT_0006af38);
  DAT_ffffbeb0 = (float)FUN_000020dc(DAT_ffffbe74,DAT_ffffb600,&DAT_0006af54);
  iVar2 = 0x7fffffff;
  iVar1 = iVar2;
  if (DAT_ffffbeac < 5.3687088e+08) {
    if (0.0 < DAT_ffffbeac) {
      iVar1 = (int)(DAT_ffffbeac / 0.25);
    }
    else {
      iVar1 = 0;
    }
  }
  if (DAT_ffffbeb0 < 5.3687088e+08) {
    if (0.0 < DAT_ffffbeb0) {
      iVar2 = (int)(DAT_ffffbeb0 / 0.25);
    }
    else {
      iVar2 = 0;
    }
  }
  set_fuel_injector_latency(0,iVar1);
  set_fuel_injector_latency(1,iVar2);
  set_fuel_injector_latency(2,iVar2);
  return;
}


