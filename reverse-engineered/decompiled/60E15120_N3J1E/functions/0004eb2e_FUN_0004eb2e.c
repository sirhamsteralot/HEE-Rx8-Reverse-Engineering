/* ROM address: 0x0004eb2e; body bytes: 334; decompiled */

uint FUN_0004eb2e(void)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  char cVar4;
  
  cVar2 = DAT_ffffcfc6;
  uVar3 = (uint)(char)DAT_ffffcfb5;
  bVar1 = (uVar3 & 0x80) != 0;
  if (DAT_ffffd1c5 == '\0') {
    if ((DAT_ffffcfd0 == '\0') && (DAT_ffffcfc6 == '\x01')) {
      DAT_ffffcfc3 = '\0';
      DAT_ffffcfc1 = 0;
      DAT_ffffcfc2 = 0;
      uVar3 = 1;
    }
    else {
      cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a4,0);
      if (((((cVar4 == '\x01') ||
            ((((cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86a0,0), cVar4 == '\x01' ||
               (DAT_ffffcfca == '\x01')) ||
              (cVar4 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86e2,0), cVar4 == '\x01')) ||
             (DAT_ffffcfc5 == '\x01')))) && (bVar1)) ||
          ((((DAT_ffffcfb5 & 0x20) != 0 && (DAT_ffffd131 == '\x01')) || (DAT_ffffcfb1 == '\0')))) ||
         (((DAT_ffffcfe4 < DAT_ffffcfe0 && (0x1f < DAT_ffffcfaa)) &&
          ((DAT_ffffd0f2 == '\x01' && (DAT_ffffcff8 == '\0')))))) {
        DAT_ffffcfc3 = '\x01';
      }
      if (((DAT_ffffcfc3 == '\x01') || (DAT_ffffd10e == '\x01')) ||
         ((DAT_ffffd147 == '\x01' && (bVar1)))) {
        DAT_ffffcfc1 = 1;
      }
      uVar3 = 1;
      if ((DAT_ffffcfc3 == '\x01') || (uVar3 = (uint)DAT_ffffcfc8, uVar3 == 1)) {
        DAT_ffffcfc2 = 1;
      }
    }
  }
  DAT_ffffcfd0 = cVar2;
  return uVar3;
}


