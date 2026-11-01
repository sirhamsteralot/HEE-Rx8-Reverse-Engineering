/* [ADDITIONAL SOURCE REVIEW]
 * uds_service_entry [high]: Emulator dynamic: harness.call(0x680a0, r4=0x7e0) after buffer fill -> PCI byte check via 0x683d4, service dispatch 0x6842c, then 0x684b4(0x7e0) schedules the UDS service task via ref_osTaskScheduler(2,0,&local).
 */
/* ROM address: 0x000680a0; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00066990 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

void uds_service_entry(int param_1)

{
  char cVar1;
  
  if ((((param_1 == 0x7e0) || (param_1 == 0x7df)) && (cVar1 = isotp_pci_type_extract(), cVar1 != '@')) &&
     (cVar1 = isotp_frame_type_dispatch(), cVar1 == '\0')) {
    uds_request_schedule_service_task(param_1);
    return;
  }
  return;
}


