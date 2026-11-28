/* [ADDITIONAL SOURCE REVIEW]
 * misfire_window_snapshot [high]: At DAT_ffffba9c == 400 (0x190): DAT_ffffb690 = max(DAT_ffffcb78, DAT_ffffcb7c); at DAT_ffffba9e == 2000 (0x7d0): DAT_ffffb692 = max(DAT_ffffcb7a, DAT_ffffcb7e); max helper 0x23e4. Pools verified: 0x26b14=0xba9c, 0x26b16=0x0190, 0x26b18=0xcb7c, 0x26b1a=0xcb78, 0x26b30=0x23e4, 0x26b1c=0xb690, 0x26b1e=0xba9e. Called from 0x287aa.
 * RAM 0xffffb690 misfire_event_count_400 (uint16): Snapshot at ba9c==400: max(cb78, cb7c) (0x26aa0); compared in the 400-tick DTC evaluation 0x44b46.
 * RAM 0xffffb692 misfire_event_count_2000 (uint16): Snapshot at ba9e==2000: max(cb7a, cb7e) (0x26aa0); compared in the 2000-tick DTC evaluation 0x445ba against cb72 and the rpm-lookup product.
 */
/* ROM address: 0x00026aa0; body bytes: 100; decompiled */

undefined2 * misfire_window_snapshot(void)

{
  undefined2 *puVar1;
  undefined2 *extraout_r0;
  float fVar2;
  
  if (misfire_window_400_ffffba9c == 400) {
    fVar2 = rx8_max_float((float)misfire_rpm_counter_a_ffffcb78,(float)misfire_load_counter_a_ffffcb7c);
    misfire_event_count_400_ffffb690 = (undefined2)(int)fVar2;
  }
  puVar1 = &misfire_window_2000_ffffba9e;
  if (misfire_window_2000_ffffba9e == 2000) {
    fVar2 = rx8_max_float((float)misfire_rpm_counter_b_ffffcb7a,(float)misfire_load_counter_b_ffffcb7e);
    misfire_event_count_2000_ffffb692 = (undefined2)(int)fVar2;
    puVar1 = extraout_r0;
  }
  return puVar1;
}


