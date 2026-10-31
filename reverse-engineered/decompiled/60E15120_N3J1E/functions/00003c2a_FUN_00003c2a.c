/* ROM address: 0x00003c2a; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003c2a (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void FUN_00003c2a(int param_1)

{
  if (*(short *)(param_1 + 6) != -1) {
    FUN_00003c68();
    return;
  }
  *(undefined4 *)(param_1 + 8) = 0x80000000;
  *(undefined2 *)(param_1 + 4) = 0xffff;
  *(undefined **)(param_1 + 0x18) = &DAT_00004990;
  *(undefined1 **)(param_1 + 0x14) = &DAT_ffff7408;
  FUN_00003dac(param_1,0);
  return;
}


