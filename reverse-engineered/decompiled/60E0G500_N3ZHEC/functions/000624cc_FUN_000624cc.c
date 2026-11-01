/* ROM address: 0x000624cc; body bytes: 214; decompiled */

/* Function candidate recovered from ROM pointer at 66a4c and register-save prologue. Heuristic
   boundary; inspect disassembly. */

uint FUN_000624cc(char param_1,char param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  
  uVar2 = DAT_ffff8928;
  uVar3 = 0;
  uVar5 = 0;
  do {
    uVar1 = (&DAT_ffff87d8)[uVar3 * 8];
    if ((uVar3 != uVar2) && (uVar1 != 0xffff)) {
      if (((param_2 == '\0') || ((param_2 == '\x01' && ((&DAT_0007e220)[uVar1] == '\x01')))) ||
         ((param_2 == '\x02' && ((&DAT_0007e2ac)[uVar1] == '\x01')))) {
        puVar4 = (ushort *)((uVar5 & 0xffff) * 2 + param_3);
        if (param_1 == '\0') {
          if ((&DAT_ffff87e4)[uVar3 * 0x10] == '\0') {
            *puVar4 = uVar1;
            uVar5 = uVar5 + 1;
          }
        }
        else if ((param_1 == '\x01') && ((&DAT_ffff87e4)[uVar3 * 0x10] == '\x01')) {
          *puVar4 = uVar1;
          uVar5 = uVar5 + 1;
        }
      }
    }
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x15);
  return uVar5;
}


