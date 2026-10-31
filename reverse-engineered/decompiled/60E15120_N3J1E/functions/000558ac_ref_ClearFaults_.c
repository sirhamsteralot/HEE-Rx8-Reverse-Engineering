/* ROM address: 0x000558ac; body bytes: 150; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00053bc8 (150 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_ClearFaults_(short param_1,uint param_2)

{
  uint uVar1;
  undefined1 local_10;
  undefined1 uStack_f;
  
  param_2 = param_2 & 0xff;
  if (param_2 == 1) {
    if (param_1 == 2) {
      ref_udsServiceResponse(0x14,&local_10,2);
      DAT_ffffd1c6 = CONCAT11(local_10,uStack_f);
      if (DAT_ffffd1c6 == -0x100) {
        FUN_00055992(0x14);
        param_2 = FUN_00061b02(&PTR_ref_LongFunc_0000ff00);
        uVar1 = 0;
      }
      else {
        param_2 = ref_udsErrorResponse(0x14,0x31);
        uVar1 = param_2;
      }
    }
    else {
      param_2 = ref_udsErrorResponse(0x14,0x12);
      uVar1 = param_2;
    }
    if ((uVar1 & 0xffff) != 0) {
      param_2 = ref_udsResponseRelated__(0x14,uVar1);
    }
  }
  else if (param_2 == 0) {
    param_2 = FUN_0005494a(0x14);
  }
  return param_2;
}


