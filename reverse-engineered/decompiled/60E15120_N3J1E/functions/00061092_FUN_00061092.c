/* [EXPORT CLEANUP]
 * The two call sites formerly named thunk_FUN_00060c7a were resolved to
 * distinct thunks from the disassembly: the jsr at 0x61132 loads
 * ROM32[0x61254] = 0x64912 and the jsr at 0x61146 loads ROM32[0x61258] =
 * 0x64004. Both tail-jump to FUN_00060c7a; the call-site names now carry the
 * thunk addresses.
 */
/* ROM address: 0x00061092; body bytes: 458; decompiled */

/* Function candidate recovered from ROM pointer at 67d14 and register-save prologue. Heuristic
   boundary; inspect disassembly. */

void FUN_00061092(uint *param_1)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined **ppuVar8;
  
  uVar3 = *param_1;
  uVar5 = param_1[1];
  uVar6 = param_1[2];
  ppuVar8 = (undefined **)(uVar5 & 0xff);
  uVar2 = *(ushort *)(&DAT_0007df42 + (uVar3 & 0xffff) * 2);
  iVar7 = (int)(short)uVar2;
  DAT_ffffd6c4 = uVar2;
  if ((ppuVar8 == &vector_Illegal_instr) ||
     (ppuVar8 == (undefined **)((int)&vector_Illegal_instr + 1))) {
    ppuVar8 = (undefined **)FUN_00060538(iVar7,0x10);
    cVar1 = (&DAT_0007e32a)[uVar2];
    FUN_000623a0(iVar7);
    if (*(ushort *)ppuVar8 == uVar2) {
      FUN_00062420(8);
      FUN_00063026(0);
      FUN_000628b8();
      ppuVar8 = ppuVar8 + 1;
    }
    if (cVar1 == '\0') {
      FUN_00060c7a(iVar7,0x10);
    }
    else if (cVar1 == '\x01') {
      FUN_000648cc(iVar7,uVar5);
    }
    else if (cVar1 == '\x02') {
      thunk_FUN_00060c7a_00064912(iVar7,uVar5);
    }
    else if (cVar1 == '\x03') {
      thunk_FUN_00060c7a_00064004(iVar7,uVar5);
    }
    FUN_000627a0();
  }
  else if (ppuVar8 == (undefined **)&UNK_00000020) {
    ppuVar8 = (undefined **)FUN_00060538(iVar7,0x20);
  }
  for (uVar4 = 0; (*(ushort *)ppuVar8 != 0xffff && (uVar4 < 2)); uVar4 = uVar4 + 1) {
    FUN_000623a0((int)(short)*(ushort *)ppuVar8);
    DAT_ffffd6bc = *(ushort *)ppuVar8;
    cVar1 = (&DAT_0007e32a)[DAT_ffffd6bc];
    if (cVar1 == '\0') {
      FUN_00060b14((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2));
    }
    else if (cVar1 == '\x01') {
      FUN_00064620((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2),uVar6);
    }
    else if (cVar1 == '\x02') {
      FUN_0006477c((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2),uVar6);
    }
    else if (cVar1 == '\x03') {
      FUN_00063f64((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2));
    }
    if (*(ushort *)ppuVar8 == uVar2) {
      FUN_00061eb0((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2),uVar6);
      sh_copy_bytes_forward_r0_r1_r2();
    }
    else {
      FUN_00061fc0((int)(short)*(ushort *)ppuVar8,(int)*(char *)((int)ppuVar8 + 2));
      sh_copy_bytes_forward_r0_r1_r2();
    }
    FUN_00060596();
    FUN_000627a0();
    ppuVar8 = ppuVar8 + 1;
  }
  FUN_00060a96();
  *param_1 = uVar3 & 0xffff;
  FUN_000602a4(*param_1,(int)*(char *)((int)param_1 + 7),param_1[2]);
  return;
}


