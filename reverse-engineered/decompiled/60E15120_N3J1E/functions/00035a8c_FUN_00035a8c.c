/* [ADDITIONAL SOURCE REVIEW]
 * e2ram_param_write_dispatch [medium]: Dispatch on param id (0..N) to 0x37ea4 / thunk 0x35d36 with (index, &src cell in 0xffffc268-0xffffc282, len): e.g. id 2 -> (2, 0xffffc26c, 8), id 0xd -> (0x1e, 0xffffc282, 1), id 3 -> (0, 0xffffc268, 1), id 4 -> (0xc/0xe/0x10), id 7 -> (0x16/0x18, 2). 30 calls total; pool 0x35b70-0x35b84. Called from 0x35ea0, 0x360c8, 0x36142, 0x361e4, 0x3665a, 0x36700, 0x3677a, 0x36830, 0x36acc, 0x36c3c, 0x36ed4, 0x3703c, 0x37134, 0x3728c, 0x374be.
 */
/* ROM address: 0x00035a8c; body bytes: 592; decompiled */

uint candidate_e2ram_param_write_dispatch(uint param_1)

{
  uint uVar1;
  
  param_1 = param_1 & 0xff;
  if (param_1 != 1) {
    if (param_1 == 2) {
      uVar1 = e2ram_shadow_byte_write_trampoline(2,&DAT_ffffc26c,8);
      return uVar1;
    }
    if (param_1 == 0xd) {
      uVar1 = e2ram_shadow_byte_write_trampoline(0x1e,&DAT_ffffc282,1);
      return uVar1;
    }
    if (param_1 == 3) {
      uVar1 = e2ram_shadow_byte_write_trampoline(0,&e2ram_param_block_ffffc268,1);
      return uVar1;
    }
    if (param_1 == 4) {
      e2ram_shadow_byte_write(0xc,&DAT_ffffc275,1);
      e2ram_shadow_byte_write(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
      uVar1 = e2ram_shadow_byte_write_trampoline(0x10,&inferred_ram_c1d2_ffffc1d2_ffffc1d2,1);
      return uVar1;
    }
    if (param_1 == 5) {
      e2ram_shadow_byte_write(0x12,&inferred_ram_c1d4_ffffc1d4_ffffc1d4,1);
      uVar1 = e2ram_shadow_byte_write_trampoline(0x13,&DAT_ffffc278,1);
      return uVar1;
    }
    if (param_1 == 6) {
      uVar1 = e2ram_shadow_byte_write_trampoline(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
      return uVar1;
    }
    if (param_1 == 7) {
      e2ram_shadow_byte_write(0x16,&DAT_ffffc27a,2);
      uVar1 = e2ram_shadow_byte_write_trampoline(0x18,&DAT_ffffc27c,2);
      return uVar1;
    }
    if (param_1 == 8) {
      uVar1 = e2ram_shadow_byte_write_trampoline(0x14,&DAT_ffffc279,1);
      return uVar1;
    }
    if (param_1 == 0xc) {
      e2ram_shadow_byte_write(0xc,&DAT_ffffc275,1);
      e2ram_shadow_byte_write(0xd,&DAT_ffffc276,1);
      e2ram_shadow_byte_write(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
      e2ram_shadow_byte_write(0xf,&DAT_ffffc277,1);
      e2ram_shadow_byte_write(0x10,&inferred_ram_c1d2_ffffc1d2_ffffc1d2,1);
      e2ram_shadow_byte_write(0x14,&DAT_ffffc279,1);
      e2ram_shadow_byte_write(0x12,&inferred_ram_c1d4_ffffc1d4_ffffc1d4,1);
      e2ram_shadow_byte_write(0x13,&DAT_ffffc278,1);
      e2ram_shadow_byte_write(0x1a,&DAT_ffffc27e,1);
      e2ram_shadow_byte_write(0x1b,&DAT_ffffc27f,1);
      e2ram_shadow_byte_write(0x1c,&DAT_ffffc280,1);
      e2ram_shadow_byte_write(0x1d,&DAT_ffffc281,1);
      uVar1 = e2ram_shadow_byte_write_trampoline(0x1e,&DAT_ffffc282,1);
      return uVar1;
    }
    if (param_1 == 9) {
      e2ram_shadow_byte_write(0xc,&DAT_ffffc275,1);
      e2ram_shadow_byte_write(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
      e2ram_shadow_byte_write(0x10,&inferred_ram_c1d2_ffffc1d2_ffffc1d2,1);
      e2ram_shadow_byte_write(0x12,&inferred_ram_c1d4_ffffc1d4_ffffc1d4,1);
      uVar1 = e2ram_shadow_byte_write_trampoline(0x13,&DAT_ffffc278,1);
      return uVar1;
    }
    if (param_1 == 10) {
      e2ram_shadow_byte_write(0x1a,&DAT_ffffc27e,1);
      e2ram_shadow_byte_write(0x1b,&DAT_ffffc27f,1);
      e2ram_shadow_byte_write(0x1c,&DAT_ffffc280,1);
      uVar1 = e2ram_shadow_byte_write_trampoline(0x1d,&DAT_ffffc281,1);
      return uVar1;
    }
    if (param_1 != 0xb) {
      if (param_1 == 0xe) {
        uVar1 = e2ram_shadow_byte_write_trampoline(0xd,&DAT_ffffc276,1);
        return uVar1;
      }
      if (param_1 != 0xf) {
        if (param_1 == 0xff) {
          e2ram_shadow_byte_write(0,&e2ram_param_block_ffffc268,1);
          e2ram_shadow_byte_write(2,&DAT_ffffc26c,8);
          e2ram_shadow_byte_write(10,&inferred_ram_c274_ffffc274_ffffc274,1);
          e2ram_shadow_byte_write(0xc,&DAT_ffffc275,1);
          e2ram_shadow_byte_write(0xd,&DAT_ffffc276,1);
          e2ram_shadow_byte_write(0xe,&inferred_ram_c1d3_ffffc1d3_ffffc1d3,1);
          e2ram_shadow_byte_write(0xf,&DAT_ffffc277,1);
          e2ram_shadow_byte_write(0x10,&inferred_ram_c1d2_ffffc1d2_ffffc1d2,1);
          e2ram_shadow_byte_write(0x12,&inferred_ram_c1d4_ffffc1d4_ffffc1d4,1);
          e2ram_shadow_byte_write(0x13,&DAT_ffffc278,1);
          e2ram_shadow_byte_write(0x16,&DAT_ffffc27a,2);
          e2ram_shadow_byte_write(0x18,&DAT_ffffc27c,2);
          e2ram_shadow_byte_write(0x14,&DAT_ffffc279,1);
          e2ram_shadow_byte_write(0x1a,&DAT_ffffc27e,1);
          e2ram_shadow_byte_write(0x1b,&DAT_ffffc27f,1);
          e2ram_shadow_byte_write(0x1c,&DAT_ffffc280,1);
          e2ram_shadow_byte_write(0x1d,&DAT_ffffc281,1);
          param_1 = e2ram_shadow_byte_write(0x1e,&DAT_ffffc282,1);
        }
        return param_1;
      }
      uVar1 = e2ram_shadow_byte_write_trampoline(0xf,&DAT_ffffc277,1);
      return uVar1;
    }
    e2ram_shadow_byte_write(2,&DAT_ffffc26c,8);
  }
  uVar1 = e2ram_shadow_byte_write_trampoline(10,&inferred_ram_c274_ffffc274_ffffc274,1);
  return uVar1;
}


