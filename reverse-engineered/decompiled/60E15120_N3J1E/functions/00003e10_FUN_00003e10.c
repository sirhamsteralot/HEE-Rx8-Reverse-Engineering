/* [ADDITIONAL SOURCE REVIEW]
 * os_init [high]: Called via literal at 0x9f38 during boot. Sets DAT_ffff7648=0xb0, task table ptr DAT_ffff7650=&DAT_00004990, current task DAT_ffff764c=&DAT_ffff7408, then calls dispatcher 0x3c2a. Emulator boot trace passes through it before reaching idle 0x3dac.
 */
/* ROM address: 0x00003e10; body bytes: 110; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00003e6a) */
/* Unique exact-byte match to related 60E0FC00 function at 00003e10 (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

void os_init(undefined1 param_1)

{
  DAT_ffff7648 = 0xb0;
  DAT_ffff7644 = &DAT_ffff7408;
  DAT_ffff763c = 0xffff;
  DAT_ffff7650 = &DAT_00004990;
  DAT_ffff764c = &DAT_ffff7408;
  DAT_ffff7639 = param_1;
  FUN_00003964(&DAT_ffff7638);
  FUN_00003ec0(&DAT_ffff7638);
  FUN_00003f10(&DAT_ffff7638);
  FUN_00003ac0(&DAT_ffff7638);
  FUN_00003f8c();
  FUN_00003f88();
  FUN_00003f90(&DAT_ffff7638);
  FUN_00003f9c(&DAT_ffff7638);
  FUN_00003fa8();
  os_dispatch(&DAT_ffff7638);
  return;
}


