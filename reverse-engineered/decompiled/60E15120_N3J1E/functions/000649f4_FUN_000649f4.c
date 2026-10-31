/* ROM address: 0x000649f4; body bytes: 230; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000632e4 (230 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000649f4(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_00062df8(1);
  uVar2 = FUN_0006559c(uVar1);
  uVar2 = uVar2 & 0xff;
  if (uVar2 == 0x60) {
    FUN_000623a0(1);
    FUN_00062420(8);
    FUN_00062dd8(0x50);
    FUN_0006310a(7);
    FUN_00062e4a(0);
    FUN_00062ebc(3);
    FUN_00062f2e(0x28);
    FUN_00062fa0(0x50);
    FUN_00063026(0);
    FUN_00063098(0);
    FUN_000628b8();
    FUN_00062668();
    FUN_00067760();
    FUN_0006763c(0);
    FUN_000676c8(0);
    FUN_000628f4();
    FUN_000606be();
    uVar2 = FUN_000627a0();
    return uVar2;
  }
  if (uVar2 == 0x70) {
    FUN_000623a0(1);
    FUN_00062420(8);
    FUN_00062dd8(0xc1);
    FUN_00062e4a(0);
    FUN_00062ebc(3);
    FUN_00062fa0(0x50);
    FUN_00063026(0);
    FUN_00063098(0);
    FUN_000628b8();
    FUN_00062668();
    FUN_00067760();
    FUN_000628f4();
    uVar2 = FUN_000627a0();
    return uVar2;
  }
  return uVar2;
}


