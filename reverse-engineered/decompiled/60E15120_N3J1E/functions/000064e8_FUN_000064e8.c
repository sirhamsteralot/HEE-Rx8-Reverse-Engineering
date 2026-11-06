/* [ADDITIONAL SOURCE REVIEW]
 * slow_task_entry [high]: Task rec[18] entry (ROM 0x4ab8): thunk {jsr 0x11534; jmp 0x3d58}.
 */
/* ROM address: 0x000064e8; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000064e8 (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void slow_task_entry(void)

{
  slow_background_task();
  ref_taskEndRoutine_();
  return;
}


