/* ROM address: 0x00068844; body bytes: 62; decompiled */

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


