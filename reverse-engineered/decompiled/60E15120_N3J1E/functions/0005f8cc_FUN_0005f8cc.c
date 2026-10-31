/* ROM address: 0x0005f8cc; body bytes: 46; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005e1d8 (46 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_0005f8cc(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = '\0';
  uVar2 = 1;
  do {
    if ((param_1 & 1) != 0) {
      cVar1 = cVar1 + '\x01';
      param_4 = uVar2;
    }
    param_1 = (param_1 & 0xffff) >> 1;
    uVar2 = uVar2 + 1;
  } while ((uVar2 & 0xffff) < 3);
  if (cVar1 != '\x01') {
    param_4 = 0;
  }
  return param_4;
}


