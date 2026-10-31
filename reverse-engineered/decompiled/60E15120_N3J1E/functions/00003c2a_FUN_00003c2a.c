/* [ADDITIONAL SOURCE REVIEW]
 * os_dispatch [high]: If ctrl+6 (0xffff763e) != -1 then 0x3c68 runs a task; else inits ctrl block (0x80000000, 0xffff, task table 0x4990) and enters idle loop 0x3dac. Emulator: harness.call(0x3c2a, stop_at=0x3dac) reaches idle.
 */
/* ROM address: 0x00003c2a; body bytes: 40; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00003c2a (36 bytes). Names prefixed ref_
   are inherited hypotheses. */

void os_dispatch(int param_1)

{
  if (*(short *)(param_1 + 6) != -1) {
    os_dispatch_next_task();
    return;
  }
  *(undefined4 *)(param_1 + 8) = 0x80000000;
  *(undefined2 *)(param_1 + 4) = 0xffff;
  *(undefined **)(param_1 + 0x18) = &DAT_00004990;
  *(undefined1 **)(param_1 + 0x14) = &DAT_ffff7408;
  FUN_00003dac(param_1,0);
  return;
}


