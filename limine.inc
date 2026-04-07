{$push}
{$macro on}

{$define LIMINE_COMMON_MAGIC := QWord($C7B1DD30DF4C8B88), QWord($0A82E883A194F07B)}

const
{ ** Start Marker *********************************************************** }
  LimineRequestStartMarker: array [0..3] of QWord = (
    QWord($F6B8F4B39DE7D1AE),
    QWord($FAB91A6940FCB9CF),
    QWord($785C6ED015D3E316),
    QWord($181E920A7852B9D9)
  ); export name '_limine_request_start_marker';

{ ** Base Revision ********************************************************** }
{$ifndef LIMINE_BASE_REVISION}
  {$define LIMINE_BASE_REVISION := 0}
{$endif LIMINE_BASE_REVISION}
  LimineRequestBaseRevision: array [0..3] of QWord = (
    QWord($F9562B2D5C95A6C8),
    QWord($6A7B384944536BDC),
    LIMINE_BASE_REVISION,
    0
  ); export name '_limine_request_base_revision';

{ ** Booloader Info ********************************************************* }
{$define LIMINE_BOOTLOADER_INFO_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($F55038D8E2A1202F), QWord($279426FCF5F59740))}
{$ifdef LIMINE_REQUEST_BOOTLOADER_INFO}
  {$ifndef LIMINE_BOOTLOADER_INFO_REVISION}
    {$define LIMINE_BOOTLOADER_INFO_REVISION := 0}
  {$endif LIMINE_BOOTLOADER_INFO_REVISION}
  LimineRequestBooloaderInfo: TLimineBootloaderInfoRequest = (
    Id: LIMINE_BOOTLOADER_INFO_REQUEST_ID;
    Revision: LIMINE_BOOTLOADER_INFO_REVISION;
    Response: nil;
  ); export name '_limine_request_bootloader_info';
{$endif LIMINE_REQUEST_BOOTLOADER_INFO}

{ ** Bootloader Performance ************************************************* }
{$define LIMINE_BOOTLOADER_PERFORMANCE_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($6B50AD9BF36D13AD), QWord($DC4C7E88FC759E17))}
{$ifdef LIMINE_REQUEST_BOOTLOADER_PERFORMANCE}
  {$ifndef LIMINE_BOOTLOADER_PERFORMANCE_REVISION}
    {$define LIMINE_BOOTLOADER_PERFORMANCE_REVISION := 0}
  {$endif LIMINE_BOOTLOADER_PERFORMANCE_REVISION}
  LimineRequestBooloaderPerformance: TLimineBootloaderPerformanceRequest = (
    Id: LIMINE_BOOTLOADER_PERFORMANCE_REQUEST_ID;
    Revision: LIMINE_BOOTLOADER_PERFORMANCE_REVISION;
    Response: nil;
  ); export name '_limine_request_bootloader_performance';
{$endif LIMINE_REQUEST_BOOTLOADER_PERFORMANCE}

{ ** Date At Boot *********************************************************** }
{$define LIMINE_DATE_AT_BOOT_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($502746E184C088AA), QWord($FBC5EC83E6327893))}
{$ifdef LIMINE_REQUEST_DATE_AT_BOOT}
  {$ifndef LIMINE_DATE_AT_BOOT_REVISION}
    {$define LIMINE_DATE_AT_BOOT_REVISION := 0}
  {$endif LIMINE_DATE_AT_BOOT_REVISION}
  LimineRequestDateAtBoot: TLimineDateAtBootRequest = (
    Id: LIMINE_DATE_AT_BOOT_REQUEST_ID;
    Revision: LIMINE_DATE_AT_BOOT_REVISION;
    Response: nil;
  ); export name '_limine_request_date_at_boot';
{$endif LIMINE_REQUEST_DATE_AT_BOOT}

{ ** Device Tree Blob ******************************************************* }
{$define LIMINE_DEVICE_TREE_BLOB_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($B40DDB48FB54BAC7), QWord($545081493F81FFB7))}
{$ifdef LIMINE_REQUEST_DEVICE_TREE_BLOB}
  {$ifndef LIMINE_DEVICE_TREE_BLOB_REVISION}
    {$define LIMINE_DEVICE_TREE_BLOB_REVISION := 0}
  {$endif LIMINE_DEVICE_TREE_BLOB_REVISION}
  LimineRequestDeviceTreeBlob: TLimineDeviceTreeBlobRequest = (
    Id: LIMINE_DEVICE_TREE_BLOB_REQUEST_ID;
    Revision: LIMINE_DEVICE_TREE_BLOB_REVISION;
    Response: nil;
  ); export name '_limine_request_device_tree_blob';
{$endif LIMINE_REQUEST_DEVICE_TREE_BLOB}

{ ** EFI Memory Map ********************************************************* }
{$define LIMINE_EFI_MEMORY_MAP_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($7DF62A431D6872D5), QWord($A4FCDFB3E57306C8))}
{$ifdef LIMINE_REQUEST_EFI_MEMORY_MAP}
  {$ifndef LIMINE_EFI_MEMORY_MAP_REVISION}
    {$define LIMINE_EFI_MEMORY_MAP_REVISION := 0}
  {$endif LIMINE_EFI_MEMORY_MAP_REVISION}
  LimineRequestEfiMemoryMap: TLimineEfiMemoryMapRequest = (
    Id: LIMINE_EFI_MEMORY_MAP_REQUEST_ID;
    Revision: LIMINE_EFI_MEMORY_MAP_REVISION;
    Response: nil;
  ); export name '_limine_request_efi_memory_map';
{$endif LIMINE_REQUEST_EFI_MEMORY_MAP}

{ ** EFI System Table ******************************************************* }
{$define LIMINE_EFI_SYSTEM_TABLE_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($5CEBA5163EAAF6D6), QWord($0A6981610CF65FCC))}
{$ifdef LIMINE_REQUEST_EFI_SYSTEM_TABLE}
  {$ifndef LIMINE_EFI_SYSTEM_TABLE_REVISION}
    {$define LIMINE_EFI_SYSTEM_TABLE_REVISION := 0}
  {$endif LIMINE_EFI_SYSTEM_TABLE_REVISION}
  LimineRequestEfiSystemTable: TLimineEfiSystemTableRequest = (
    Id: LIMINE_EFI_SYSTEM_TABLE_REQUEST_ID;
    Revision: LIMINE_EFI_SYSTEM_TABLE_REVISION;
    Response: nil;
  ); export name '_limine_request_efi_system_table';
{$endif LIMINE_REQUEST_EFI_SYSTEM_TABLE}

{ ** Entry Point ************************************************************ }
{$define LIMINE_ENTRY_POINT_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($13D86C035A1CD3E1), QWord($2B0CAA89D8F3026A))}
{$ifdef LIMINE_REQUEST_ENTRY_POINT}
{$ifdef LIMINE_ENTRY_POINT}
  {$ifndef LIMINE_ENTRY_POINT_REVISION}
    {$define LIMINE_ENTRY_POINT_REVISION := 0}
  {$endif LIMINE_ENTRY_POINT_REVISION}
  LimineRequestEntryPoint: TLimineEntryPointRequest = (
    Id: LIMINE_ENTRY_POINT_REQUEST_ID;
    Revision: LIMINE_ENTRY_POINT_REVISION;
    Response: nil;
    Entry: LIMINE_ENTRY_POINT;
  ); export name '_limine_request_entry_point';
{$endif LIMINE_ENTRY_POINT}
{$endif LIMINE_REQUEST_ENTRY_POINT}

{ ** Executable Address Request ********************************************* }
{$define LIMINE_EXECUTABLE_ADDRESS_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($71BA76863CC55F63), QWord($B2644A48C516A487))}
{$ifdef LIMINE_REQUEST_EXECUTABLE_ADDRESS}
  {$ifndef LIMINE_EXECUTABLE_ADDRESS_REVISION}
    {$define LIMINE_EXECUTABLE_ADDRESS_REVISION := 0}
  {$endif LIMINE_EXECUTABLE_ADDRESS_REVISION}
  LimineRequestExecutableAddress: TLimineExecutableAddressRequest = (
    Id: LIMINE_EXECUTABLE_ADDRESS_REQUEST_ID;
    Revision: LIMINE_EXECUTABLE_ADDRESS_REVISION;
    Response: nil;
  ); export name '_limine_request_executable_address';
{$endif LIMINE_REQUEST_EXECUTABLE_ADDRESS}

{ ** Executable Command Line ************************************************ }
{$define LIMINE_EXECUTABLE_CMDLINE_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($B9F1C8E5A3B2D9F4), QWord($C0E7F3A6D5B8E2A1))}
{$ifdef LIMINE_REQUEST_EXECUTABLE_CMDLINE}
  {$ifndef LIMINE_EXECUTABLE_CMDLINE_REVISION}
    {$define LIMINE_EXECUTABLE_CMDLINE_REVISION := 0}
  {$endif LIMINE_EXECUTABLE_CMDLINE_REVISION}
  LimineRequestExecutableCmdLine: TLimineExecutableCmdLineRequest = (
    Id: LIMINE_EXECUTABLE_CMDLINE_REQUEST_ID;
    Revision: LIMINE_EXECUTABLE_CMDLINE_REVISION;
    Response: nil;
  ); export name '_limine_request_executable_cmdline';
{$endif LIMINE_REQUEST_EXECUTABLE_CMDLINE}

{ ** Executable File ******************************************************** }
{$define LIMINE_EXECUTABLE_FILE_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($AD97E90E83F1ED67), QWord($31EB5D1C5FF23B69))}
{$ifdef LIMINE_REQUEST_EXECUTABLE_FILE}
  {$ifndef LIMINE_EXECUTABLE_FILE_REVISION}
    {$define LIMINE_EXECUTABLE_FILE_REVISION := 0}
  {$endif LIMINE_EXECUTABLE_FILE_REVISION}
  LimineRequestExecutableFile: TLimineExecutableFileRequest = (
    Id: LIMINE_EXECUTABLE_FILE_REQUEST_ID;
    Revision: LIMINE_EXECUTABLE_FILE_REVISION;
    Response: nil;
  ); export name '_limine_request_executable_file';
{$endif LIMINE_REQUEST_EXECUTABLE_FILE}

{ ** Firmware Type ********************************************************** }
{$define LIMINE_FIRMWARE_TYPE_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($8C2F75D90BEF28A8), QWord($7045A4688EAC00C3))}
{$ifdef LIMINE_REQUEST_FIRMWARE_TYPE}
  {$ifndef LIMINE_FIRMWARE_TYPE_REVISION}
    {$define LIMINE_FIRMWARE_TYPE_REVISION := 0}
  {$endif LIMINE_FIRMWARE_TYPE_REVISION}
  LimineRequestFirmwareType: TLimineFirmwareTypeRequest = (
    Id: LIMINE_FIRMWARE_TYPE_REQUEST_ID;
    Revision: LIMINE_FIRMWARE_TYPE_REVISION;
    Response: nil;
  ); export name '_limine_request_firmware_type';
{$endif LIMINE_REQUEST_FIRMWARE_TYPE}

{ ** Flanterm FB Init Params ************************************************ }
{$ifdef LIMINE_REQUEST_FLANTERM_FB_INIT_PARAMS}
  {$ifndef LIMINE_FLANTERM_FB_INIT_PARAMS_REVISION}
    {$define LIMINE_FLANTERM_FB_INIT_PARAMS_REVISION := 0}
  {$endif LIMINE_FLANTERM_FB_INIT_PARAMS_REVISION}
  LimineRequestFlantermFbInitParams: TLimineFlantermFbInitParamsRequest = (
    Id: (LIMINE_COMMON_MAGIC, QWord($3259399FE7C5F126), QWord($0E01C1C8C5DB9D1A9));
    Revision: LIMINE_FLANTERM_FB_INIT_PARAMS_REVISION;
    Response: nil;
  ); export name '_limine_request_flanterm_fb_init_params';
{$endif LIMINE_REQUEST_FLANTERM_FB_INIT_PARAMS}

{ ** Framebuffer Request **************************************************** }
{$define LIMINE_FRAMEBUFFER_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($9D5827DCD881DD75), QWord($A3148604F6FAB11B))}
{$ifdef LIMINE_REQUEST_FRAMEBUFFER}
  {$ifndef LIMINE_FRAMEBUFFER_REVISION}
    {$define LIMINE_FRAMEBUFFER_REVISION := 0}
  {$endif LIMINE_FRAMEBUFFER_REVISION}
  LimineRequestFramebuffer: TLimineFramebufferRequest = (
    Id: LIMINE_FRAMEBUFFER_REQUEST_ID;
    Revision: LIMINE_FRAMEBUFFER_REVISION;
    Response: nil;
  ); export name '_limine_request_framebuffer';
{$endif LIMINE_REQUEST_FRAMEBUFFER}

{ ** HHDM - Higher Half Direct Map ****************************************** }
{$define LIMINE_HHDM_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($48DCF1CB8AD2B852), QWord($63984E959A98244B))}
{$ifdef LIMINE_REQUEST_HHDM}
  {$ifndef LIMINE_HHDM_REVISION}
    {$define LIMINE_HHDM_REVISION := 0}
  {$endif LIMINE_HHDM_REVISION}
  LimineRequestHhdm: TLimineHhdmRequest = (
    Id: LIMINE_HHDM_REQUEST_ID;
    Revision: LIMINE_HHDM_REVISION;
    Response: nil;
  ); export name '_limine_request_hhdm';
{$endif LIMINE_REQUEST_HHDM}

{ ** Keep IOMMU ************************************************************* }
{$define LIMINE_KEEP_IOMMU_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($8EBAABE51F490179), QWord($2AA86A59FFB4AB0F))}
{$ifdef LIMINE_REQUEST_KEEP_IOMMU}
  {$ifndef LIMINE_KEEP_IOMMU_REVISION}
    {$define LIMINE_KEEP_IOMMU_REVISION := 0}
  {$endif LIMINE_KEEP_IOMMU_REVISION}
  LimineRequestKeepIommu: TLimineKeepIommuRequest = (
    Id: LIMINE_KEEP_IOMMU_REQUEST_ID;
    Revision: LIMINE_KEEP_IOMMU_REVISION;
    Response: nil;
  ); export name '_limine_request_keep_iommu';
{$endif LIMINE_REQUEST_KEEP_IOMMU}

{ ** Memory Map ************************************************************* }
{$define LIMINE_MEMORY_MAP_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($67CF3D9D378A806F), QWord($E304ACDFC50C3C62))}
{$ifdef LIMINE_REQUEST_MEMORY_MAP}
  {$ifndef LIMINE_MEMORY_MAP_REVISION}
    {$define LIMINE_MEMORY_MAP_REVISION := 0}
  {$endif LIMINE_MEMORY_MAP_REVISION}
  LimineRequestMemoryMap: TLimineMemoryMapRequest = (
    Id: LIMINE_MEMORY_MAP_REQUEST_ID;
    Revision: LIMINE_MEMORY_MAP_REVISION;
    Response: nil;
  ); export name '_limine_request_memory_map';
{$endif LIMINE_REQUEST_MEMORY_MAP}

{ ** Module ***************************************************************** }
{$define LIMINE_MODULE_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($3E7E279702BE32AF), QWord($CA1C4F3BD1280CEE))}
{$ifdef LIMINE_REQUEST_MODULE}

  {$ifndef LIMINE_MODULE_COUNT}
    {$define LIMINE_MODULE_COUNT := 0}
  {$endif LIMINE_MODULE_COUNT}

  {$ifndef LIMINE_MODULE_ARRAY}
    {$define LIMINE_MODULE_ARRAY := nil}
  {$endif LIMINE_MODULE_ARRAY}

  {$ifndef LIMINE_MODULE_REVISION}
    {$define LIMINE_MODULE_REVISION := 0}
  {$endif LIMINE_MODULE_REVISION}

  LimineRequestModule: TLimineModuleRequest = (
    Id: LIMINE_MODULE_REQUEST_ID;
    Revision: LIMINE_MODULE_REVISION;
    Response: nil;
    InternalModuleCount: LIMINE_MODULE_COUNT;
    InternalModules: LIMINE_MODULE_ARRAY;
  ); export name '_limine_request_module';
{$endif LIMINE_REQUEST_MODULE}

{ ** Multiprocessor ********************************************************* }
{$define LIMINE_MULTIPROCESSOR_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($B1E5F8C9A3D2E6F4), QWord($7C9A1B2D5F8E3A6B))}
{$ifdef LIMINE_REQUEST_MULTIPROCESSOR}

  {$ifndef LIMINE_MULTIPROCESSOR_FLAGS}
    {$define LIMINE_MULTIPROCESSOR_FLAGS := 0}
  {$endif LIMINE_MULTIPROCESSOR_FLAGS}

  {$ifndef LIMINE_MULTIPROCESSOR_REVISION}
    {$define LIMINE_MULTIPROCESSOR_REVISION := 0}
  {$endif LIMINE_MULTIPROCESSOR_REVISION}

  LimineRequestMultiprocessor: TLimineMultiprocessorRequest = (
    Id: LIMINE_MULTIPROCESSOR_REQUEST_ID;
    Revision: LIMINE_MULTIPROCESSOR_REVISION;
    Response: nil;
    Flags: LIMINE_MULTIPROCESSOR_FLAGS;
  ); export name '_limine_request_multiprocessor';
{$endif LIMINE_REQUEST_MULTIPROCESSOR}

{ ** Paging Mode ************************************************************ }
{$define LIMINE_PAGING_MODE_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($95C1A0EDAB0944CB), QWord($A4E5CB3842F7488A))}
{$ifdef LIMINE_REQUEST_PAGING_MODE}

{$if defined(CPUX86_64)}
  {$ifndef LIMINE_PAGING_MODE}
    {$define LIMINE_PAGING_MODE := LIMINE_PAGING_MODE_X86_64_DEFAULT}
  {$endif LIMINE_PAGING_MODE}

  {$ifndef LIMINE_PAGING_MODE_MAX}
    {$define LIMINE_PAGING_MODE_MAX := LIMINE_PAGING_MODE_X86_64_DEFAULT}
  {$endif LIMINE_PAGING_MODE_MAX}

  {$ifndef LIMINE_PAGING_MODE_MIN}
    {$define LIMINE_PAGING_MODE_MIN := LIMINE_PAGING_MODE_X86_64_MIN}
  {$endif LIMINE_PAGING_MODE_MIN}

{$elseif defined(CPUAARCH64)}
  {$ifndef LIMINE_PAGING_MODE}
    {$define LIMINE_PAGING_MODE := LIMINE_PAGING_MODE_AARCH64_DEFAULT}
  {$endif LIMINE_PAGING_MODE}

  {$ifndef LIMINE_PAGING_MODE_MAX}
    {$define LIMINE_PAGING_MODE_MAX := LIMINE_PAGING_MODE_AARCH64_DEFAULT}
  {$endif LIMINE_PAGING_MODE_MAX}

  {$ifndef LIMINE_PAGING_MODE_MIN}
    {$define LIMINE_PAGING_MODE_MIN := LIMINE_PAGING_MODE_AARCH64_MIN}
  {$endif LIMINE_PAGING_MODE_MIN}

{$elseif defined(CPULOONGARCH64)}
  {$ifndef LIMINE_PAGING_MODE}
    {$define LIMINE_PAGING_MODE := LIMINE_PAGING_MODE_LOONGARCH_DEFAULT}
  {$endif LIMINE_PAGING_MODE}

  {$ifndef LIMINE_PAGING_MODE_MAX}
    {$define LIMINE_PAGING_MODE_MAX := LIMINE_PAGING_MODE_LOONGARCH_DEFAULT}
  {$endif LIMINE_PAGING_MODE_MAX}

  {$ifndef LIMINE_PAGING_MODE_MIN}
    {$define LIMINE_PAGING_MODE_MIN := LIMINE_PAGING_MODE_LOONGARCH_MIN}
  {$endif LIMINE_PAGING_MODE_MIN}

{$elseif defined(CPURISCV64)}
  {$ifndef LIMINE_PAGING_MODE}
    {$define LIMINE_PAGING_MODE := LIMINE_PAGING_MODE_RISCV_DEFAULT}
  {$endif LIMINE_PAGING_MODE}

  {$ifndef LIMINE_PAGING_MODE_MAX}
    {$define LIMINE_PAGING_MODE_MAX := LIMINE_PAGING_MODE_RISCV_DEFAULT}
  {$endif LIMINE_PAGING_MODE_MAX}

  {$ifndef LIMINE_PAGING_MODE_MIN}
    {$define LIMINE_PAGING_MODE_MIN := LIMINE_PAGING_MODE_RISCV_MIN}
  {$endif LIMINE_PAGING_MODE_MIN}

{$endif defined(CPUX86_64)}

  {$ifndef LIMINE_PAGING_MODE_REVISION}
    {$define LIMINE_PAGING_MODE_REVISION := 0}
  {$endif LIMINE_PAGING_MODE_REVISION}

  LimineRequestPagingMode: TLiminePagingModeRequest = (
    Id: LIMINE_PAGING_MODE_REQUEST_ID;
    Revision: LIMINE_PAGING_MODE_REVISION;
    Response: nil;
    Mode: LIMINE_PAGING_MODE;
    MaxMode: LIMINE_PAGING_MODE_MAX;
    MinMode: LIMINE_PAGING_MODE_MIN;
  ); export name '_limine_request_paging_mode';
{$endif LIMINE_REQUEST_PAGING_MODE}

{ ** RISC-V BSP Hart ID ***************************************************** }
{$define LIMINE_RISCV_BSP_HARTID_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($1369359F025525F9), QWord($2FF2A56178391BB6))}
{$ifdef LIMINE_REQUEST_RISCV_BSP_HARTID}
  {$ifndef LIMINE_RISCV_BSP_HARTID_REVISION}
    {$define LIMINE_RISCV_BSP_HARTID_REVISION := 0}
  {$endif LIMINE_RISCV_BSP_HARTID_REVISION}
  LimineRequestRiscvBspHartId: TLimineRiscvBspHartIdRequest = (
    Id: LIMINE_RISCV_BSP_HARTID_REQUEST_ID;
    Revision: LIMINE_RISCV_BSP_HARTID_REVISION;
    Response: nil;
  ); export name '_limine_request_riscv_bsp_hartid';
{$endif LIMINE_REQUEST_RISCV_BSP_HARTID}

{ ** RSDP ******************************************************************* }
{$define LIMINE_RSDP_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($C5E77B6B397E7B43), QWord($27637845ACCDCF3C))}
{$ifdef LIMINE_REQUEST_RSDP}
  {$ifndef LIMINE_RSDP_REVISION}
    {$define LIMINE_RSDP_REVISION := 0}
  {$endif LIMINE_RSDP_REVISION}
  LimineRequestRsdp: TLimineRsdpRequest = (
    Id: LIMINE_RSDP_REQUEST_ID;
    Revision: LIMINE_RSDP_REVISION;
    Response: nil;
  ); export name '_limine_request_rsdp';
{$endif LIMINE_REQUEST_RSDP}

{ ** SMBIOS ***************************************************************** }
{$define LIMINE_SMBIOS_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($9E9046F11E095391), QWord($AA4A520FEFBDE5EE))}
{$ifdef LIMINE_REQUEST_SMBIOS}
  {$ifndef LIMINE_SMBIOS_REVISION}
    {$define LIMINE_SMBIOS_REVISION := 0}
  {$endif LIMINE_SMBIOS_REVISION}
  LimineRequestSmbios: TLimineSmbiosRequest = (
    Id: LIMINE_SMBIOS_REQUEST_ID;
    Revision: LIMINE_SMBIOS_REVISION;
    Response: nil;
  ); export name '_limine_request_smbios';
{$endif LIMINE_REQUEST_SMBIOS}

{ ** Stack Size ************************************************************* }
{$define LIMINE_STACK_SIZE_REQUEST_ID := (LIMINE_COMMON_MAGIC, QWord($224EF0460A8E8926), QWord($E1CB0FC25F46EA3D))}
{$ifdef LIMINE_REQUEST_STACK_SIZE}
{$ifdef LIMINE_STACK_SIZE}
  {$ifndef LIMINE_STACK_SIZE_REVISION}
    {$define LIMINE_STACK_SIZE_REVISION := 0}
  {$endif LIMINE_STACK_SIZE_REVISION}
  LimineRequestStackSize: TLimineStackSizeRequest = (
    Id: LIMINE_STACK_SIZE_REQUEST_ID;
    Revision: LIMINE_STACK_SIZE_REVISION;
    Response: nil;
    StackSize: LIMINE_STACK_SIZE;
  ); export name '_limine_request_stack_size';
{$endif LIMINE_STACK_SIZE}
{$endif LIMINE_REQUEST_STACK_SIZE}

{ ** End Marker ************************************************************* }
  LimineRequestEndMarker: array [0..1] of QWord = (
    QWord($ADC0E0531BB10D03),
    QWord($9572709F31764C62)
  ); export name '_limine_request_end_marker';

{$pop}
