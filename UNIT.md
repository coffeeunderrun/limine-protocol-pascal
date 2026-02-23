# Limine Unit

The [limine.pas](kernel/src/limine.pas) file contains the types and constants described in the [Limine Protocol](https://codeberg.org/Limine/limine-protocol/src/branch/trunk/PROTOCOL.md).

The [limine.inc](kernel/src/limine.inc) file contains the requests which are enabled using define directives. [Why?](#why-is-limine-include-necessary)

How do I add the requests to a specific section?
> FreePascal does not provide a way to specify section names. Exported symbols use the `_limine_request_` prefix allowing the linker script to target any that are enabled.

Example linker script section:

```ld
.limine_requests : {
    KEEP(*(.data.*_limine_request_*))
} :limine_requests
```

## Enabling C-style macros

To set specific Limine request values you will need to enable C-style macros:

```pascal
{$macro on}
{$define LIMINE_<...> := value}
{$macro off}
```

### Examples:

Set a specific base revision:

```pascal
{$macro on}
{$define LIMINE_BASE_REVISION := 4}
{$macro off}
{$I limine.inc}
```

Set the entry point:

```pascal
{$macro on}
{$define LIMINE_ENTRY_POINT := @procedure_name}
{$macro off}
{$define LIMINE_REQUEST_ENTRY_POINT}
{$I limine.inc}
```

Add internal modules:

```pascal
{$macro on}
{$define LIMINE_MODULE_COUNT := <count of internal module pointers>}
{$define LIMINE_MODULE_ARRAY := @array_of_internal_module_pointers}
{$macro off}
{$define LIMINE_REQUEST_MODULE}
{$I limine.inc}
```

Set multiprocessor flags:

```pascal
{$macro on}
{$define LIMINE_MULTIPROCESSOR_FLAGS := LIMINE_MULTIPROCESSOR_REQUEST_X86_64_X2APIC}
{$macro off}
{$define LIMINE_REQUEST_MULTIPROCESSOR}
{$I limine.inc}
```

Set paging mode:

```pascal
{$macro on}
{$define LIMINE_PAGING_MODE_REVISION := 1}
{$define LIMINE_PAGING_MODE := LIMINE_PAGING_MODE_X86_64_DEFAULT}
{$define LIMINE_PAGING_MODE_MIN := LIMINE_PAGING_MODE_X86_64_4LVL}
{$define LIMINE_PAGING_MODE_MAX := LIMINE_PAGING_MODE_X86_64_5LVL}
{$macro off}
{$define LIMINE_REQUEST_PAGING_MODE}
{$I limine.inc}
```

Set stack size:

```pascal
{$macro on}
{$define LIMINE_STACK_SIZE := <size in bytes>}
{$macro off}
{$define LIMINE_REQUEST_STACK_SIZE}
{$I limine.inc}
```

## Request specific features

Define the request macros prior to including `limine.inc` to request features:

```pascal
{$define LIMINE_REQUEST_BOOTLOADER_INFO}
{$define LIMINE_REQUEST_BOOTLOADER_PERFORMANCE}
{$define LIMINE_REQUEST_DATE_AT_BOOT}
{$define LIMINE_REQUEST_DEVICE_TREE_BLOB}
{$define LIMINE_REQUEST_EFI_MEMORY_MAP}
{$define LIMINE_REQUEST_EFI_SYSTEM_TABLE}
{$define LIMINE_REQUEST_ENTRY_POINT}
{$define LIMINE_REQUEST_EXECUTABLE_ADDRESS}
{$define LIMINE_REQUEST_EXECUTABLE_CMDLINE}
{$define LIMINE_REQUEST_EXECUTABLE_FILE}
{$define LIMINE_REQUEST_FIRMWARE_TYPE}
{$define LIMINE_REQUEST_FRAMEBUFFER}
{$define LIMINE_REQUEST_HHDM}
{$define LIMINE_REQUEST_KEEP_IOMMU}
{$define LIMINE_REQUEST_MEMORY_MAP}
{$define LIMINE_REQUEST_MODULE}
{$define LIMINE_REQUEST_MULTIPROCESSOR}
{$define LIMINE_REQUEST_PAGING_MODE}
{$define LIMINE_REQUEST_RISCV_BSP_HARTID}
{$define LIMINE_REQUEST_RSDP}
{$define LIMINE_REQUEST_SMBIOS}
{$define LIMINE_REQUEST_STACK_SIZE}
```

## Accessing the requests

Available external names for requests:

- `_limine_request_bootloader_info`
- `_limine_request_bootloader_performance`
- `_limine_request_date_at_boot`
- `_limine_request_device_tree_blob`
- `_limine_request_efi_memory_map`
- `_limine_request_efi_system_table`
- `_limine_request_entry_point`
- `_limine_request_executable_address`
- `_limine_request_executable_cmdline`
- `_limine_request_executable_file`
- `_limine_request_firmware_type`
- `_limine_request_framebuffer`
- `_limine_request_hhdm`
- `_limine_request_keep_iommu`
- `_limine_request_memory_map`
- `_limine_request_module`
- `_limine_request_multiprocessor`
- `_limine_request_paging_mode`
- `_limine_request_riscv_bsp_hartid`
- `_limine_request_rsdp`
- `_limine_request_smbios`
- `_limine_request_stack_size`

Corresponding types for requests:

- `TLimineBootloaderInfoRequest`
- `TLimineBootloaderPerformanceRequest`
- `TLimineDateAtBootRequest`
- `TLimineDeviceTreeBlobRequest`
- `TLimineEfiMemoryMapRequest`
- `TLimineEfiSystemTableRequest`
- `TLimineEntryPointRequest`
- `TLimineExecutableAddressRequest`
- `TLimineExecutableCmdLineRequest`
- `TLimineExecutableFileRequest`
- `TLimineFirmwareTypeRequest`
- `TLimineFramebufferRequest`
- `TLimineHhdmRequest`
- `TLimineKeepIommuRequest`
- `TLimineMemoryMapRequest`
- `TLimineModuleRequest`
- `TLimineMultiprocessorRequest`
- `TLiminePagingModeRequest`
- `TLimineRiscvBspHartIdRequest`
- `TLimineRsdpRequest`
- `TLimineSmbiosRequest`
- `TLimineStackSizeRequest`

Example definition for Framebuffer request:

```pascal
var
  Framebuffer: TLimineFramebufferRequest; external name '_limine_request_framebuffer';
```

## Why is limine include necessary?
FreePascal does not support parameterized C-style macros.

Assigning values to records at compile-time is also limited. Static initialization of records requires literal values.

This is possible:

```pascal
const
  FramebufferRequest: TLimineFramebufferRequest = (
    Id: (
      QWord($C7B1DD30DF4C8B88),
      QWord($0A82E883A194F07B),
      QWord($9D5827DCD881DD75),
      QWord($A3148604F6FAB11B)
    );
    Revision: 0;
    Response: nil;
  ); export name '_limine_request_framebuffer';
```

While this is not:

```pascal
const
  FramebufferRequest: TLimineFramebufferRequest = (
    Id: LIMINE_FRAMEBUFFER_REQUEST_ID;
    Revision: 0;
    Response: nil;
  ); export name '_limine_request_framebuffer';
```

FreePascal does support basic C-style macros for assigning values.

```pascal
{$macro on}
{$define LIMINE_BASE_REVISION := 4}
{$macro off}
```

Using these macros with `limine.inc` was the most convenient way I found to make this work. It may change if I find a better alternative.
