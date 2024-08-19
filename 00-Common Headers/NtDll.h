///////////////////////////////////////////////////////////////////////////////
//
// Module Name:
//
//     NtDll.h
//
// Abstract:
//
//     Windows NT Native API
//
//     PSA: If you try and use this header file outside of VxKex, keep in mind
//     that many of the structures in here are defined for Windows 7 only. No
//     attempt is made to make anything compatible with anything other than
//     Windows 7.
//
// Author:
//
//     vxiiduu (26-Mar-2022)
//
// Environment:
//
//     Any environment.
//
// Revision History:
//
//     vxiiduu               26-Mar-2022  Initial creation.
//     vxiiduu               26-Sep-2022  Add header.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <KexTypes.h>
#include <WinIoCtl.h>
#include <WinNT.h>
#undef WIN32_NO_STATUS
#include <ntstatus.h>
#define WIN32_NO_STATUS

#if defined(KEX_TARGET_TYPE_EXE) || defined(KEX_TARGET_TYPE_DLL)
#  if defined(KEX_ARCH_X64)
#    pragma comment(lib, "ntdll_x64.lib")
#  elif defined(KEX_ARCH_X86)
#    pragma comment(lib, "ntdll_x86.lib")
#  endif
#endif

#pragma region Macro Definitions

#define NT_SUCCESS(st) (((NTSTATUS) (st)) >= 0)

#define HARDERROR_OVERRIDE_ERRORMODE		0x10000000L

#define PAGE_SIZE 0x1000

#define RTL_MAX_DRIVE_LETTERS 32
#define PROCESSOR_FEATURE_MAX 64
#define GDI_HANDLE_BUFFER_SIZE32 34
#define GDI_HANDLE_BUFFER_SIZE64 60

#define PF_FLOATING_POINT_PRECISION_ERRATA			0
#define PF_FLOATING_POINT_EMULATED					1
#define PF_COMPARE_EXCHANGE_DOUBLE					2
#define PF_MMX_INSTRUCTIONS_AVAILABLE				3
#define PF_PPC_MOVEMEM_64BIT_OK						4
#define PF_ALPHA_BYTE_INSTRUCTIONS					5
#define PF_XMMI_INSTRUCTIONS_AVAILABLE				6
#define PF_3DNOW_INSTRUCTIONS_AVAILABLE				7
#define PF_RDTSC_INSTRUCTION_AVAILABLE				8
#define PF_PAE_ENABLED								9
#define PF_XMMI64_INSTRUCTIONS_AVAILABLE			10
#define PF_SSE_DAZ_MODE_AVAILABLE					11
#define PF_NX_ENABLED								12
#define PF_SSE3_INSTRUCTIONS_AVAILABLE				13
#define PF_COMPARE_EXCHANGE128						14
#define PF_COMPARE64_EXCHANGE128					15
#define PF_CHANNELS_ENABLED							16
#define PF_XSAVE_ENABLED							17

#define OBJ_INHERIT             0x00000002L
#define OBJ_PERMANENT           0x00000010L
#define OBJ_EXCLUSIVE           0x00000020L
#define OBJ_CASE_INSENSITIVE    0x00000040L
#define OBJ_OPENIF              0x00000080L
#define OBJ_OPENLINK            0x00000100L
#define OBJ_KERNEL_HANDLE       0x00000200L
#define OBJ_FORCE_ACCESS_CHECK  0x00000400L
#define OBJ_VALID_ATTRIBUTES    0x000007F2L

#define FILE_DIRECTORY_FILE                     0x00000001
#define FILE_WRITE_THROUGH                      0x00000002
#define FILE_SEQUENTIAL_ONLY                    0x00000004
#define FILE_NO_INTERMEDIATE_BUFFERING          0x00000008

#define FILE_SYNCHRONOUS_IO_ALERT               0x00000010
#define FILE_SYNCHRONOUS_IO_NONALERT            0x00000020
#define FILE_NON_DIRECTORY_FILE                 0x00000040
#define FILE_CREATE_TREE_CONNECTION             0x00000080

#define FILE_COMPLETE_IF_OPLOCKED               0x00000100
#define FILE_NO_EA_KNOWLEDGE                    0x00000200
#define FILE_OPEN_FOR_RECOVERY                  0x00000400
#define FILE_RANDOM_ACCESS                      0x00000800

#define FILE_DELETE_ON_CLOSE                    0x00001000
#define FILE_OPEN_BY_FILE_ID                    0x00002000
#define FILE_OPEN_FOR_BACKUP_INTENT             0x00004000
#define FILE_NO_COMPRESSION                     0x00008000

#define FILE_RESERVE_OPFILTER                   0x00100000
#define FILE_OPEN_REPARSE_POINT                 0x00200000
#define FILE_OPEN_NO_RECALL                     0x00400000
#define FILE_OPEN_FOR_FREE_SPACE_QUERY          0x00800000


#define FILE_COPY_STRUCTURED_STORAGE            0x00000041
#define FILE_STRUCTURED_STORAGE                 0x00000441


#define FILE_VALID_OPTION_FLAGS                 0x00ffffff
#define FILE_VALID_PIPE_OPTION_FLAGS            0x00000032
#define FILE_VALID_MAILSLOT_OPTION_FLAGS        0x00000032
#define FILE_VALID_SET_FLAGS                    0x00000036

#define FILE_SUPERSEDE                  0x00000000
#define FILE_OPEN                       0x00000001
#define FILE_CREATE                     0x00000002
#define FILE_OPEN_IF                    0x00000003
#define FILE_OVERWRITE                  0x00000004
#define FILE_OVERWRITE_IF               0x00000005
#define FILE_MAXIMUM_DISPOSITION        0x00000005

#define FILE_SUPERSEDED                 0x00000000
#define FILE_OPENED                     0x00000001
#define FILE_CREATED                    0x00000002
#define FILE_OVERWRITTEN                0x00000003
#define FILE_EXISTS                     0x00000004
#define FILE_DOES_NOT_EXIST             0x00000005

#define FILE_PIPE_BYTE_STREAM_TYPE      0x00000000
#define FILE_PIPE_MESSAGE_TYPE          0x00000001

#define FILE_PIPE_QUEUE_OPERATION       0x00000000
#define FILE_PIPE_COMPLETE_OPERATION    0x00000001

#define FILE_PIPE_BYTE_STREAM_MODE      0x00000000
#define FILE_PIPE_MESSAGE_MODE          0x00000001

#define FILE_PIPE_INBOUND               0x00000000
#define FILE_PIPE_OUTBOUND              0x00000001
#define FILE_PIPE_FULL_DUPLEX           0x00000002

#define FILE_PIPE_DISCONNECTED_STATE    0x00000001
#define FILE_PIPE_LISTENING_STATE       0x00000002
#define FILE_PIPE_CONNECTED_STATE       0x00000003
#define FILE_PIPE_CLOSING_STATE         0x00000004

#define FILE_PIPE_CLIENT_END            0x00000000
#define FILE_PIPE_SERVER_END            0x00000001

#define FILE_WRITE_TO_END_OF_FILE       0xffffffff
#define FILE_USE_FILE_POINTER_POSITION  0xfffffffe

#define FSCTL_PIPE_ASSIGN_EVENT				CTL_CODE(FILE_DEVICE_NAMED_PIPE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define FSCTL_PIPE_DISCONNECT				CTL_CODE(FILE_DEVICE_NAMED_PIPE, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define FSCTL_PIPE_LISTEN					CTL_CODE(FILE_DEVICE_NAMED_PIPE, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define FSCTL_PIPE_PEEK						CTL_CODE(FILE_DEVICE_NAMED_PIPE, 3, METHOD_BUFFERED, FILE_READ_DATA)
#define FSCTL_PIPE_QUERY_EVENT				CTL_CODE(FILE_DEVICE_NAMED_PIPE, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define FSCTL_PIPE_TRANSCEIVE				CTL_CODE(FILE_DEVICE_NAMED_PIPE, 5, METHOD_NEITHER,  FILE_READ_DATA | FILE_WRITE_DATA)
#define FSCTL_PIPE_WAIT						CTL_CODE(FILE_DEVICE_NAMED_PIPE, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define FSCTL_PIPE_IMPERSONATE				CTL_CODE(FILE_DEVICE_NAMED_PIPE, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define FSCTL_PIPE_SET_CLIENT_PROCESS		CTL_CODE(FILE_DEVICE_NAMED_PIPE, 8, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define FSCTL_PIPE_QUERY_CLIENT_PROCESS		CTL_CODE(FILE_DEVICE_NAMED_PIPE, 9, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define FSCTL_PIPE_GET_CONNECTION_ATTRIBUTE	CTL_CODE(FILE_DEVICE_NAMED_PIPE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)

// RTL_USER_PROCESS_PARAMETERS->Flags
#define RTL_USER_PROCESS_PARAMETERS_NORMALIZED              0x01
#define RTL_USER_PROCESS_PARAMETERS_PROFILE_USER            0x02
#define RTL_USER_PROCESS_PARAMETERS_PROFILE_KERNEL          0x04
#define RTL_USER_PROCESS_PARAMETERS_PROFILE_SERVER          0x08
#define RTL_USER_PROCESS_PARAMETERS_UNKNOWN                 0x10
#define RTL_USER_PROCESS_PARAMETERS_RESERVE_1MB             0x20
#define RTL_USER_PROCESS_PARAMETERS_RESERVE_16MB            0x40
#define RTL_USER_PROCESS_PARAMETERS_CASE_SENSITIVE          0x80
#define RTL_USER_PROCESS_PARAMETERS_DISABLE_HEAP_CHECKS     0x100
#define RTL_USER_PROCESS_PARAMETERS_PROCESS_OR_1            0x200
#define RTL_USER_PROCESS_PARAMETERS_PROCESS_OR_2            0x400
#define RTL_USER_PROCESS_PARAMETERS_PRIVATE_DLL_PATH        0x1000
#define RTL_USER_PROCESS_PARAMETERS_LOCAL_DLL_PATH          0x2000
#define RTL_USER_PROCESS_PARAMETERS_IMAGE_KEY_MISSING       0x4000
#define RTL_USER_PROCESS_PARAMETERS_NX                      0x20000
#define RTL_USER_PROCESS_PARAMETERS_USER_CALLBACK_FILTER	0x80000 // see LdrpIsSystemwideUserCallbackExceptionFilterDisabled

#define PROCESS_CREATE_FLAGS_BREAKAWAY 0x00000001 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_NO_DEBUG_INHERIT 0x00000002 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_INHERIT_HANDLES 0x00000004 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_OVERRIDE_ADDRESS_SPACE 0x00000008 // NtCreateProcessEx only
#define PROCESS_CREATE_FLAGS_LARGE_PAGES 0x00000010 // NtCreateProcessEx only, requires SeLockMemory (last in 5.2)

#define PROCESS_CREATE_FLAGS_LARGE_PAGE_SYSTEM_DLL 0x00000020 // NtCreateProcessEx only, requires SeLockMemory (6.0+)
#define PROCESS_CREATE_FLAGS_PROTECTED_PROCESS 0x00000040 // NtCreateUserProcess only
#define PROCESS_CREATE_FLAGS_CREATE_SESSION 0x00000080 // NtCreateProcessEx & NtCreateUserProcess, requires SeLoadDriver
#define PROCESS_CREATE_FLAGS_INHERIT_FROM_PARENT 0x00000100 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_SUSPENDED 0x00000200 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_FORCE_BREAKAWAY 0x00000400 // NtCreateProcessEx & NtCreateUserProcess, requires SeTcb
#define PROCESS_CREATE_FLAGS_MINIMAL_PROCESS 0x00000800 // NtCreateProcessEx only
#define PROCESS_CREATE_FLAGS_RELEASE_SECTION 0x00001000 // NtCreateProcessEx & NtCreateUserProcess
#define PROCESS_CREATE_FLAGS_CLONE_MINIMAL 0x00002000 // NtCreateProcessEx only
#define PROCESS_CREATE_FLAGS_CLONE_MINIMAL_REDUCED_COMMIT 0x00004000 //
#define PROCESS_CREATE_FLAGS_AUXILIARY_PROCESS 0x00008000 // NtCreateProcessEx & NtCreateUserProcess, requires SeTcb
#define PROCESS_CREATE_FLAGS_CREATE_STORE 0x00020000 // NtCreateProcessEx only
#define PROCESS_CREATE_FLAGS_USE_PROTECTED_ENVIRONMENT 0x00040000 // NtCreateProcessEx & NtCreateUserProcess

#define THREAD_CREATE_FLAGS_CREATE_SUSPENDED 0x00000001 // NtCreateUserProcess & NtCreateThreadEx
#define THREAD_CREATE_FLAGS_SKIP_THREAD_ATTACH 0x00000002 // NtCreateThreadEx only
#define THREAD_CREATE_FLAGS_HIDE_FROM_DEBUGGER 0x00000004 // NtCreateThreadEx only
#define THREAD_CREATE_FLAGS_LOADER_WORKER 0x00000010 // NtCreateThreadEx only
#define THREAD_CREATE_FLAGS_SKIP_LOADER_INIT 0x00000020 // NtCreateThreadEx only
#define THREAD_CREATE_FLAGS_BYPASS_PROCESS_FREEZE 0x00000040 // NtCreateThreadEx only
#define THREAD_CREATE_FLAGS_INITIAL_THREAD 0x00000080 // ?

#define PS_ATTRIBUTE_NUMBER_MASK 0x0000ffff
#define PS_ATTRIBUTE_THREAD 0x00010000 // may be used with thread creation
#define PS_ATTRIBUTE_INPUT 0x00020000 // input only
#define PS_ATTRIBUTE_ADDITIVE 0x00040000 // "accumulated" e.g. bitmasks, counters, etc.

#define PsAttributeValue(Number, Thread, Input, Additive) \
    (((Number) & PS_ATTRIBUTE_NUMBER_MASK) | \
    ((Thread) ? PS_ATTRIBUTE_THREAD : 0) | \
    ((Input) ? PS_ATTRIBUTE_INPUT : 0) | \
    ((Additive) ? PS_ATTRIBUTE_ADDITIVE : 0))

#define PS_ATTRIBUTE_PARENT_PROCESS PsAttributeValue(PsAttributeParentProcess, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_DEBUG_PORT PsAttributeValue(PsAttributeDebugPort, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_TOKEN PsAttributeValue(PsAttributeToken, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_CLIENT_ID PsAttributeValue(PsAttributeClientId, TRUE, FALSE, FALSE)
#define PS_ATTRIBUTE_TEB_ADDRESS PsAttributeValue(PsAttributeTebAddress, TRUE, FALSE, FALSE)
#define PS_ATTRIBUTE_IMAGE_NAME PsAttributeValue(PsAttributeImageName, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_IMAGE_INFO PsAttributeValue(PsAttributeImageInfo, FALSE, FALSE, FALSE)
#define PS_ATTRIBUTE_MEMORY_RESERVE PsAttributeValue(PsAttributeMemoryReserve, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_PRIORITY_CLASS PsAttributeValue(PsAttributePriorityClass, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_ERROR_MODE PsAttributeValue(PsAttributeErrorMode, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_STD_HANDLE_INFO PsAttributeValue(PsAttributeStdHandleInfo, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_HANDLE_LIST PsAttributeValue(PsAttributeHandleList, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_GROUP_AFFINITY PsAttributeValue(PsAttributeGroupAffinity, TRUE, TRUE, FALSE)
#define PS_ATTRIBUTE_PREFERRED_NODE PsAttributeValue(PsAttributePreferredNode, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_IDEAL_PROCESSOR PsAttributeValue(PsAttributeIdealProcessor, TRUE, TRUE, FALSE)
#define PS_ATTRIBUTE_UMS_THREAD PsAttributeValue(PsAttributeUmsThread, TRUE, TRUE, FALSE)
#define PS_ATTRIBUTE_MITIGATION_OPTIONS PsAttributeValue(PsAttributeMitigationOptions, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_PROTECTION_LEVEL PsAttributeValue(PsAttributeProtectionLevel, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_SECURE_PROCESS PsAttributeValue(PsAttributeSecureProcess, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_JOB_LIST PsAttributeValue(PsAttributeJobList, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_CHILD_PROCESS_POLICY PsAttributeValue(PsAttributeChildProcessPolicy, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_ALL_APPLICATION_PACKAGES_POLICY PsAttributeValue(PsAttributeAllApplicationPackagesPolicy, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_WIN32K_FILTER PsAttributeValue(PsAttributeWin32kFilter, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_SAFE_OPEN_PROMPT_ORIGIN_CLAIM PsAttributeValue(PsAttributeSafeOpenPromptOriginClaim, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_BNO_ISOLATION PsAttributeValue(PsAttributeBnoIsolation, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_DESKTOP_APP_POLICY PsAttributeValue(PsAttributeDesktopAppPolicy, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_CHPE PsAttributeValue(PsAttributeChpe, FALSE, TRUE, TRUE)
#define PS_ATTRIBUTE_MITIGATION_AUDIT_OPTIONS PsAttributeValue(PsAttributeMitigationAuditOptions, FALSE, TRUE, FALSE)
#define PS_ATTRIBUTE_MACHINE_TYPE PsAttributeValue(PsAttributeMachineType, FALSE, TRUE, TRUE)

#define NX_SUPPORT_POLICY_ALWAYSOFF	0
#define NX_SUPPORT_POLICY_ALWAYSON	1
#define NX_SUPPORT_POLICY_OPTIN		2
#define NX_SUPPORT_POLICY_OPTOUT	3

#define LDR_LOCK_LOADER_LOCK_FLAG_RAISE_ON_ERRORS	(0x00000001)
#define LDR_LOCK_LOADER_LOCK_FLAG_TRY_ONLY			(0x00000002) // Required to pass Disposition ptr with this flag

#define LDR_LOCK_LOADER_LOCK_DISPOSITION_INVALID			(0)
#define LDR_LOCK_LOADER_LOCK_DISPOSITION_LOCK_ACQUIRED		(1)
#define LDR_LOCK_LOADER_LOCK_DISPOSITION_LOCK_NOT_ACQUIRED	(2)

// The maximum one in Windows XP is KACF_OLE32ENABLEASYNCDOCFILE.
// This list is from Windows 10 and I don't know how many apply to Win7.
// See nt5src for the descriptions. They are not very relevant to VxKex so
// it doesn't really matter that we don't know what the rest of them do.
//
// The naming for these is complete garbage btw.
#define KACF_OLDGETSHORTPATHNAME						0x00000001
#define KACF_VERSIONLIE									0x00000002
#define KACF_GETDISKFREESPACE							0x00000008
#define KACF_FTMFROMCURRENTAPT							0x00000020
#define KACF_DISALLOWORBINDINGCHANGES					0x00000040
#define KACF_OLE32VALIDATEPTRS							0x00000080
#define KACF_DISABLECICERO								0x00000100
#define KACF_OLE32ENABLEASYNCDOCFILE					0x00000200
#define KACF_OLE32ENABLELEGACYEXCEPTIONHANDLING			0x00000400
#define KACF_RPCDISABLENDRCLIENTHARDENING				0x00000800
#define KACF_RPCDISABLENDRMAYBENULL_SIZEIS				0x00001000
#define KACF_DISABLEALLDDEHACK_NOT_USED					0x00002000
#define KACF_RPCDISABLENDR61_RANGE						0x00004000
#define KACF_RPC32ENABLELEGACYEXCEPTIONHANDLING			0x00008000
#define KACF_OLE32DOCFILEUSELEGACYNTFSFLAGS				0x00010000
#define KACF_RPCDISABLENDRCONSTIIDCHECK					0x00020000
#define KACF_USERDISABLEFORWARDERPATCH					0x00040000
#define KACF_OLE32DISABLENEW_WMPAINT_DISPATCH			0x00100000
#define KACF_ADDRESTRICTEDSIDINCOINITIALIZESECURITY		0x00200000
#define KACF_ALLOCDEBUGINFOFORCRITSECTIONS				0x00400000
#define KACF_OLEAUT32ENABLEUNSAFELOADTYPELIBRELATIVE	0x00800000
#define KACF_ALLOWMAXIMIZEDWINDOWGAMMA					0x01000000
#define KACF_DONOTADDTOCACHE							0x80000000

#define FLG_STOP_ON_EXCEPTION           0x00000001      // user and kernel mode
#define FLG_SHOW_LDR_SNAPS              0x00000002      // user and kernel mode
#define FLG_DEBUG_INITIAL_COMMAND       0x00000004      // kernel mode only up until WINLOGON started
#define FLG_STOP_ON_HUNG_GUI            0x00000008      // kernel mode only while running

#define FLG_HEAP_ENABLE_TAIL_CHECK      0x00000010      // user mode only
#define FLG_HEAP_ENABLE_FREE_CHECK      0x00000020      // user mode only
#define FLG_HEAP_VALIDATE_PARAMETERS    0x00000040      // user mode only
#define FLG_HEAP_VALIDATE_ALL           0x00000080      // user mode only

#define FLG_APPLICATION_VERIFIER        0x00000100      // user mode only
#define FLG_POOL_ENABLE_TAGGING         0x00000400      // kernel mode only
#define FLG_HEAP_ENABLE_TAGGING         0x00000800      // user mode only

#define FLG_USER_STACK_TRACE_DB         0x00001000      // x86 user mode only
#define FLG_KERNEL_STACK_TRACE_DB       0x00002000      // x86 kernel mode only at boot time
#define FLG_MAINTAIN_OBJECT_TYPELIST    0x00004000      // kernel mode only at boot time
#define FLG_HEAP_ENABLE_TAG_BY_DLL      0x00008000      // user mode only

#define FLG_DISABLE_STACK_EXTENSION     0x00010000      // user mode only
#define FLG_ENABLE_CSRDEBUG             0x00020000      // kernel mode only at boot time
#define FLG_ENABLE_KDEBUG_SYMBOL_LOAD   0x00040000      // kernel mode only
#define FLG_DISABLE_PAGE_KERNEL_STACKS  0x00080000      // kernel mode only at boot time

#define FLG_ENABLE_SYSTEM_CRIT_BREAKS   0x00100000      // user mode only
#define FLG_HEAP_DISABLE_COALESCING     0x00200000      // user mode only
#define FLG_ENABLE_CLOSE_EXCEPTIONS     0x00400000      // kernel mode only
#define FLG_ENABLE_EXCEPTION_LOGGING    0x00800000      // kernel mode only

#define FLG_ENABLE_HANDLE_TYPE_TAGGING  0x01000000      // kernel mode only
#define FLG_HEAP_PAGE_ALLOCS            0x02000000      // user mode only
#define FLG_DEBUG_INITIAL_COMMAND_EX    0x04000000      // kernel mode only up until WINLOGON started
#define FLG_DISABLE_DBGPRINT            0x08000000      // kernel mode only

#define FLG_CRITSEC_EVENT_CREATION      0x10000000      // user mode only, Force early creation of resource events
#define FLG_LDR_TOP_DOWN                0x20000000      // user mode only, win64 only
#define FLG_ENABLE_HANDLE_EXCEPTIONS    0x40000000      // kernel mode only
#define FLG_DISABLE_PROTDLLS            0x80000000      // user mode only (smss/winlogon)

// IFEO VerifierDebug
#define AVRF_DBG_SHOW_SNAPS             0x0001
#define AVRF_DBG_SHOW_VERIFIED_EXPORTS  0x0002
#define AVRF_DBG_SHOW_DLLS_WITH_EXPORTS 0x0004
#define AVRF_DBG_SHOW_PROVIDER_LOADS    0x0008
#define AVRF_DBG_SHOW_CHAIN_ACTIVITY    0x0010
#define AVRF_DBG_SHOW_CHAIN_DETAILS     0x0020
#define AVRF_DBG_SHOW_PAGE_HEAP_DETAILS 0x0040

// IFEO VerifierFlags
#define RTL_VRF_FLG_FULL_PAGE_HEAP					0x00000001
#define RTL_VRF_FLG_RESERVED_DONOTUSE				0x00000002
#define RTL_VRF_FLG_HANDLE_CHECKS					0x00000004
#define RTL_VRF_FLG_STACK_CHECKS					0x00000008
#define RTL_VRF_FLG_APPCOMPAT_CHECKS				0x00000010
#define RTL_VRF_FLG_TLS_CHECKS						0x00000020
#define RTL_VRF_FLG_DIRTY_STACKS					0x00000040
#define RTL_VRF_FLG_RPC_CHECKS						0x00000080
#define RTL_VRF_FLG_COM_CHECKS						0x00000100
#define RTL_VRF_FLG_DANGEROUS_APIS					0x00000200
#define RTL_VRF_FLG_RACE_CHECKS						0x00000400
#define RTL_VRF_FLG_DEADLOCK_CHECKS					0x00000800
#define RTL_VRF_FLG_FIRST_CHANCE_EXCEPTION_CHECKS	0x00001000
#define RTL_VRF_FLG_VIRTUAL_MEM_CHECKS				0x00002000
#define RTL_VRF_FLG_ENABLE_LOGGING					0x00004000
#define RTL_VRF_FLG_FAST_FILL_HEAP					0x00008000
#define RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING			0x00010000
#define RTL_VRF_FLG_ENABLED_SYSTEM_WIDE				0x00020000
#define RTL_VRF_FLG_MISCELLANEOUS_CHECKS			0x00020000
#define RTL_VRF_FLG_LOCK_CHECKS						0x00040000

#define INSPECT_LEAKS 1
#define BREAK_ON_LEAKS 2

#define DLL_PROCESS_VERIFIER 4

#ifdef _M_X64
#  define GDI_HANDLE_BUFFER_SIZE GDI_HANDLE_BUFFER_SIZE64
#else
#  define GDI_HANDLE_BUFFER_SIZE GDI_HANDLE_BUFFER_SIZE32
#endif

#define EVENT_QUERY_STATE		0x0001
#define EVENT_MODIFY_STATE		0x0002

// Key creation disposition
#define REG_CREATED_NEW_KEY			(0x00000001L)
#define REG_OPENED_EXISTING_KEY		(0x00000002L)

// Key save flags
#define REG_STANDARD_FORMAT		1
#define REG_LATEST_FORMAT		2
#define REG_NO_COMPRESSION		4

// Key restore flags
#define REG_WHOLE_HIVE_VOLATILE		(0x00000001L)	// Restore whole hive volatile
#define REG_REFRESH_HIVE			(0x00000002L)	// Unwind changes to last flush
#define REG_NO_LAZY_FLUSH			(0x00000004L)	// Never lazy flush this hive
#define REG_FORCE_RESTORE			(0x00000008L)	// Force the restore process even when we have open handles on subkeys

// Unload flags
#define REG_FORCE_UNLOAD			1

// Notify filter flags
#define REG_NOTIFY_CHANGE_NAME			(0x00000001L) // Create or delete (child)
#define REG_NOTIFY_CHANGE_ATTRIBUTES	(0x00000002L)
#define REG_NOTIFY_CHANGE_LAST_SET		(0x00000004L) // time stamp
#define REG_NOTIFY_CHANGE_SECURITY		(0x00000008L)

#define RTL_IMAGE_NT_HEADER_EX_FLAG_NO_RANGE_CHECK (0x00000001)

#define RTL_HASH_ALLOCATED_HEADER 1
#define RTL_HASH_RESERVED_SIGNATURE 0

#define HASH_STRING_ALGORITHM_DEFAULT	(0)
#define HASH_STRING_ALGORITHM_X65599	(1)
#define HASH_STRING_ALGORITHM_INVALID	(0xffffffff)

// for LDR_DATA_TABLE_ENTRY
#define LDRP_STATIC_LINK				0x00000002
#define LDRP_IMAGE_DLL					0x00000004
#define LDRP_SHIMENG_ENTRY_PROCESSED	0x00000008
#define LDRP_TELEMETRY_ENTRY_PROCESSED	0x00000010
#define LDRP_IMAGE_INTEGRITY_FORCED		0x00000020
#define LDRP_LOAD_IN_PROGRESS			0x00001000
#define LDRP_UNLOAD_IN_PROGRESS			0x00002000
#define LDRP_ENTRY_PROCESSED			0x00004000
#define LDRP_ENTRY_INSERTED				0x00008000
#define LDRP_CURRENT_LOAD				0x00010000
#define LDRP_FAILED_BUILTIN_LOAD		0x00020000
#define LDRP_DONT_CALL_FOR_THREADS		0x00040000
#define LDRP_PROCESS_ATTACH_CALLED		0x00080000
#define LDRP_DEBUG_SYMBOLS_LOADED		0x00100000
#define LDRP_IMAGE_NOT_AT_BASE			0x00200000
#define LDRP_COR_IMAGE					0x00400000
#define LDRP_COR_OWNS_UNMAP				0x00800000
#define LDRP_SYSTEM_MAPPED				0x01000000
#define LDRP_IMAGE_VERIFYING			0x02000000
#define LDRP_DRIVER_DEPENDENT_DLL		0x04000000
#define LDRP_ENTRY_NATIVE				0x08000000
#define LDRP_REDIRECTED					0x10000000
#define LDRP_NON_PAGED_DEBUG_INFO		0x20000000
#define LDRP_MM_LOADED					0x40000000
#define LDRP_COMPAT_DATABASE_PROCESSED	0x80000000

#define RTL_FIND_CHAR_IN_UNICODE_STRING_START_AT_END		(0x00000001)
#define RTL_FIND_CHAR_IN_UNICODE_STRING_COMPLEMENT_CHAR_SET	(0x00000002)
#define RTL_FIND_CHAR_IN_UNICODE_STRING_CASE_INSENSITIVE	(0x00000004)

#define HEAP_SIGNATURE						(ULONG) 0xEEFFEEFF
#define HEAP_LOCK_USER_ALLOCATED			(ULONG) 0x80000000
#define HEAP_VALIDATE_PARAMETERS_ENABLED	(ULONG) 0x40000000
#define HEAP_VALIDATE_ALL_ENABLED			(ULONG) 0x20000000
#define HEAP_SKIP_VALIDATION_CHECKS			(ULONG) 0x10000000
#define HEAP_CAPTURE_STACK_BACKTRACES		(ULONG) 0x08000000
#define HEAP_FLAG_PAGE_ALLOCS				(ULONG) 0x01000000

#define HEAP_DEBUG_FLAGS	(HEAP_VALIDATE_PARAMETERS_ENABLED	| \
							 HEAP_VALIDATE_ALL_ENABLED			| \
							 HEAP_CAPTURE_STACK_BACKTRACES		| \
							 HEAP_CREATE_ENABLE_TRACING			| \
							 HEAP_FLAG_PAGE_ALLOCS)

#define HEAP_CLASS_0					0x00000000		// process heap
#define HEAP_CLASS_1					0x00001000		// private heap
#define HEAP_CLASS_2					0x00002000		// Kernel Heap
#define HEAP_CLASS_3					0x00003000		// GDI heap
#define HEAP_CLASS_4					0x00004000		// User heap
#define HEAP_CLASS_5					0x00005000		// Console heap
#define HEAP_CLASS_6					0x00006000		// User Desktop heap
#define HEAP_CLASS_7					0x00007000		// Csrss Shared heap
#define HEAP_CLASS_8					0x00008000		// Csr Port heap
#define HEAP_CLASS_MASK					0x0000F000

// win8+ only - use with NtUnmapViewOfSectionEx
#define MEM_UNMAP_WITH_TRANSIENT_BOOST	1
#define MEM_PRESERVE_PLACEHOLDER		2
#define MEM_UNMAP_VALID_FLAGS			(MEM_UNMAP_WITH_TRANSIENT_BOOST | MEM_PRESERVE_PLACEHOLDER)

// win10+ only - NtMapViewOfSectionEx
#define MEM_EXTENDED_PARAMETER_GRAPHICS                 0x00000001
#define MEM_EXTENDED_PARAMETER_NONPAGED                 0x00000002
#define MEM_EXTENDED_PARAMETER_ZERO_PAGES_OPTIONAL      0x00000004
#define MEM_EXTENDED_PARAMETER_NONPAGED_LARGE           0x00000008
#define MEM_EXTENDED_PARAMETER_NONPAGED_HUGE            0x00000010
#define MEM_EXTENDED_PARAMETER_SOFT_FAULT_PAGES         0x00000020
#define MEM_EXTENDED_PARAMETER_NUMA_NODE_MANDATORY      MINLONG64

#define MEM_REPLACE_PLACEHOLDER 0x4000

// win10+ only - NtMapViewOfSectionEx
typedef enum _MEM_EXTENDED_PARAMETER_TYPE {
	MemExtendedParameterInvalidType = 0,
	MemExtendedParameterAddressRequirements,
	MemExtendedParameterNumaNode,
	MemExtendedParameterPartitionHandle,
	MemExtendedParameterUserPhysicalHandle,
	MemExtendedParameterAttributeFlags,
	MemExtendedParameterMax
} TYPEDEF_TYPE_NAME(MEM_EXTENDED_PARAMETER_TYPE);

// win10+ only - NtMapViewOfSectionEx
#define MEM_EXTENDED_PARAMETER_TYPE_BITS    8

typedef struct DECLSPEC_ALIGN(8) _MEM_EXTENDED_PARAMETER {
	struct {
		DWORD64 Type : MEM_EXTENDED_PARAMETER_TYPE_BITS;
		DWORD64 Reserved : 64 - MEM_EXTENDED_PARAMETER_TYPE_BITS;
	};

	union {
		DWORD64 ULong64;
		PVOID Pointer;
		SIZE_T Size;
		HANDLE Handle;
		DWORD ULong;
	};
} TYPEDEF_TYPE_NAME(MEM_EXTENDED_PARAMETER);

typedef struct _MEM_ADDRESS_REQUIREMENTS {
	PVOID	LowestStartingAddress;
	PVOID	HighestStartingAddress;
	SIZE_T	Alignment;
} TYPEDEF_TYPE_NAME(MEM_ADDRESS_REQUIREMENTS);

#define MEM_EXECUTE_OPTION_DISABLE					0x1
#define MEM_EXECUTE_OPTION_ENABLE					0x2
#define MEM_EXECUTE_OPTION_DISABLE_THUNK_EMULATION	0x4
#define MEM_EXECUTE_OPTION_PERMANENT				0x8
#define MEM_EXECUTE_OPTION_EXECUTE_DISPATCH_ENABLE	0x10
#define MEM_EXECUTE_OPTION_IMAGE_DISPATCH_ENABLE	0x20 
#define MEM_EXECUTE_OPTION_SEHOP					0x40
#define MEM_EXECUTE_OPTION_VALID_FLAGS				0x7F

#define PROCESS_PRIORITY_CLASS_UNKNOWN		0
#define PROCESS_PRIORITY_CLASS_IDLE			1
#define PROCESS_PRIORITY_CLASS_NORMAL		2
#define PROCESS_PRIORITY_CLASS_HIGH			3
#define PROCESS_PRIORITY_CLASS_REALTIME		4
#define PROCESS_PRIORITY_CLASS_BELOW_NORMAL	5
#define PROCESS_PRIORITY_CLASS_ABOVE_NORMAL	6

#define RTL_HASH_RESERVED_SIGNATURE			0
#define RTL_BASE_DYNAMIC_HASH_TABLE_SIZE	0x80
#define RTL_MAX_DYNAMIC_HASH_TABLE_SIZE		0xFFFF
#define RTL_HT_FIRST_LEVEL_DIR_SIZE			0x1FF

#define RTL_HT_FLAG_HEAP_ALLOCATED			1

//
// Object Manager Directory Specific Access Rights.
//

#define DIRECTORY_QUERY					(0x0001)
#define DIRECTORY_TRAVERSE				(0x0002)
#define DIRECTORY_CREATE_OBJECT			(0x0004)
#define DIRECTORY_CREATE_SUBDIRECTORY	(0x0008)

#define DIRECTORY_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | 0xF)

#define DLL_CHARACTERISTIC_LOAD_AS_DATA				0x000002
#define DLL_CHARACTERISTIC_IGNORE_CODE_AUTHZ_LEVEL	0x001000
#define DLL_CHARACTERISTIC_REQUIRE_SIGNATURE		0x800000

// LDR_GET_DLL_HANDLE_EX_UNCHANGED_REFCOUNT cannot be used together with
// LDR_GET_DLL_HANDLE_EX_PIN.
#define LDR_GET_DLL_HANDLE_EX_UNCHANGED_REFCOUNT	0x0001 // The DLL's reference count will not be incremented.
#define LDR_GET_DLL_HANDLE_EX_PIN					0x0002 // The DLL will remain loaded until the process exits.
#define LDR_GET_DLL_HANDLE_EX_UNKNOWN				0x0004 // Is valid, but appears to do nothing.

#pragma endregion

#pragma region Data Type Definitions

typedef LONG NTSTATUS;
typedef LONG KPRIORITY;
typedef SHORT CSHORT;

typedef ULONG GDI_HANDLE_BUFFER32[GDI_HANDLE_BUFFER_SIZE32];
typedef ULONG GDI_HANDLE_BUFFER64[GDI_HANDLE_BUFFER_SIZE64];
typedef ULONG GDI_HANDLE_BUFFER[GDI_HANDLE_BUFFER_SIZE];
typedef VOID (*PPS_POST_PROCESS_INIT_ROUTINE) (VOID);

typedef struct _PEB *PPEB;
typedef struct _PEB *__ptr64 PPEB64;
typedef struct _TEB *PTEB;
typedef struct _TEB *__ptr64 PTEB64;

typedef struct _CLIENT_ID {
	HANDLE								UniqueProcess;
	HANDLE								UniqueThread;
} TYPEDEF_TYPE_NAME(CLIENT_ID);

typedef struct _PROCESS_BASIC_INFORMATION {
    NTSTATUS	ExitStatus;
    PPEB		PebBaseAddress;
    ULONG_PTR	AffinityMask;
    KPRIORITY	BasePriority;
    ULONG_PTR	UniqueProcessId;
    ULONG_PTR	InheritedFromUniqueProcessId;
} TYPEDEF_TYPE_NAME(PROCESS_BASIC_INFORMATION);

// Use with NtWow64QueryInformationProcess64.
typedef struct _PROCESS_BASIC_INFORMATION64 {
    NTSTATUS	ExitStatus;
    PPEB64		PebBaseAddress;
    ULONGLONG	AffinityMask;
    KPRIORITY	BasePriority;
    ULONGLONG	UniqueProcessId;
    ULONGLONG	InheritedFromUniqueProcessId;
} TYPEDEF_TYPE_NAME(PROCESS_BASIC_INFORMATION64);

typedef struct _THREAD_BASIC_INFORMATION {
	NTSTATUS	ExitStatus;
	PTEB		TebBaseAddress;
	CLIENT_ID	ClientId;
	ULONG_PTR	AffinityMask;
	KPRIORITY	Priority;
	LONG		BasePriority;
} TYPEDEF_TYPE_NAME(THREAD_BASIC_INFORMATION);

typedef struct _THREAD_TEB_INFORMATION {
	PVOID		TebInformation;
	ULONG		TebOffset;
	ULONG		BytesToRead;
} TYPEDEF_TYPE_NAME(THREAD_TEB_INFORMATION);

typedef struct _THREAD_LAST_SYSCALL_INFORMATION {
	PVOID		FirstArgument;
	USHORT		SystemCallNumber;
} TYPEDEF_TYPE_NAME(THREAD_LAST_SYSCALL_INFORMATION);

typedef struct _PAGE_PRIORITY_INFORMATION {
    ULONG		PagePriority;
} TYPEDEF_TYPE_NAME(PAGE_PRIORITY_INFORMATION);

#pragma pack(push, 1)
typedef struct _PROCESS_DEVICEMAP_INFORMATION {
	union {
		struct {
			HANDLE DirectoryHandle;
		} Set;
		
		struct {
			ULONG DriveMap;
			UCHAR DriveType[32];
		} Query;
	};
} TYPEDEF_TYPE_NAME(PROCESS_DEVICEMAP_INFORMATION);
#pragma pack(pop)

typedef enum _HARDERROR_RESPONSE_OPTION {
	OptionAbortRetryIgnore,
	OptionOk,
	OptionOkCancel,
	OptionRetryCancel,
	OptionYesNo,
	OptionYesNoCancel,
	OptionShutdownSystem,
	OptionOkNoWait,
	OptionCancelTryContinue
} TYPEDEF_TYPE_NAME(HARDERROR_RESPONSE_OPTION);

typedef enum _HARDERROR_RESPONSE
{
	ResponseReturnToCaller,
	ResponseNotHandled,
	ResponseAbort,
	ResponseCancel,
	ResponseIgnore,
	ResponseNo,
	ResponseOk,
	ResponseRetry,
	ResponseYes,
	ResponseTryAgain,
	ResponseContinue
} TYPEDEF_TYPE_NAME(HARDERROR_RESPONSE);

typedef enum _PROCESSINFOCLASS {
	ProcessBasicInformation,					// PROCESS_BASIC_INFORMATION
	ProcessQuotaLimits,							// QUOTA_LIMITS
	ProcessIoCounters,							// IO_COUNTERS
	ProcessVmCounters,							// VM_COUNTERS or VM_COUNTERS_EX
	ProcessTimes,								// KERNEL_USER_TIMES
	ProcessBasePriority,						// KPRIORITY
	ProcessRaisePriority,						// ULONG
	ProcessDebugPort,							// HANDLE
	ProcessExceptionPort,						// HANDLE
	ProcessAccessToken,							// PROCESS_ACCESS_TOKEN
	ProcessLdtInformation,						// PROCESS_LDT_INFORMATION
	ProcessLdtSize,								// ULONG
	ProcessDefaultHardErrorMode,				// ULONG
	ProcessIoPortHandlers,						// (Kernel mode only)
	ProcessPooledUsageAndLimits,				// POOLED_USAGE_AND_LIMITS
	ProcessWorkingSetWatch,						// PROCESS_WS_WATCH_INFORMATION
	ProcessUserModeIOPL,						// ULONG
	ProcessEnableAlignmentFaultFixup,			// BOOLEAN
	ProcessPriorityClass,						// PROCESS_PRIORITY_CLASS
	ProcessWx86Information,						// ULONG
	ProcessHandleCount,							// ULONG or PROCESS_HANDLE_INFORMATION
	ProcessAffinityMask,						// KAFFINITY or GROUP_AFFINITY
	ProcessPriorityBoost,						// ULONG
	ProcessDeviceMap,							// PROCESS_DEVICEMAP_INFORMATION or PROCESS_DEVICEMAP_INFORMATION_EX
	ProcessSessionInformation,
	ProcessForegroundInformation,
	ProcessWow64Information,					// ULONG_PTR (returns address of 32-bit PEB, or 0 if not wow64)
	ProcessImageFileName,						// UNICODE_STRING
	ProcessLUIDDeviceMapsEnabled,
	ProcessBreakOnTermination,					// ULONG
	ProcessDebugObjectHandle,					// HANDLE
	ProcessDebugFlags,							// ULONG
	ProcessHandleTracing,
	ProcessIoPriority,							// IO_PRIORITY_HINT
	ProcessExecuteFlags,						// ULONG
	ProcessTlsInformation,
	ProcessCookie,
	ProcessImageInformation,					// SECTION_IMAGE_INFORMATION
	ProcessCycleTime,
	ProcessPagePriority,						// PAGE_PRIORITY_INFORMATION
	ProcessInstrumentationCallback,				// PROCESS_INSTRUMENTATION_CALLBACK_INFORMATION
	ProcessThreadStackAllocation,
	ProcessWorkingSetWatchEx,
	ProcessImageFileNameWin32,					// UNICODE_STRING
	ProcessImageFileMapping,
	ProcessAffinityUpdateMode,
	ProcessMemoryAllocationMode,
	ProcessGroupInformation,					// USHORT[]
	ProcessTokenVirtualizationEnabled,
	ProcessConsoleHostProcess,					// HANDLE
	ProcessWindowInformation,
	MaxProcessInfoClass
} PROCESSINFOCLASS;

typedef enum _THREADINFOCLASS {
	ThreadBasicInformation,					// THREAD_BASIC_INFORMATION, get
	ThreadTimes,							// KERNEL_USER_TIMES, get
	ThreadPriority,							// KPRIORITY, set
	ThreadBasePriority,						// LONG, set
	ThreadAffinityMask,						// KAFFINITY, set
	ThreadImpersonationToken,				// HANDLE, set
	ThreadDescriptorTableEntry,				// DESCRIPTOR_TABLE_ENTRY, get (Not implemented on x64)
	ThreadEnableAlignmentFaultFixup,		// BOOLEAN, set
	ThreadEventPair,						// unused
	ThreadQuerySetWin32StartAddress,		// PVOID, get/set
	ThreadZeroTlsCell,						// ULONG, set
	ThreadPerformanceCount,					// ULONGLONG, get (Always return 0 on normal OS)
	ThreadAmILastThread,					// BOOL, get
	ThreadIdealProcessor,					// ULONG, set
	ThreadPriorityBoost,					// BOOL, get/set
	ThreadSetTlsArrayAddresses,				// PVOID, set
	ThreadIsIoPending,						// BOOL, get
	ThreadHideFromDebugger,					// VOID, set
	ThreadBreakOnTermination,				// BOOL, get/set
	ThreadSwitchLegacyState,				// , set
	ThreadIsTerminated,						// BOOL, get, last member for Windows Research Kernel
	ThreadLastSystemCall,					// THREAD_LAST_SYSCALL_INFORMATION, get
	ThreadIoPriority,
	ThreadCycleTime,						// THREAD_CYCLE_TIME_INFORMATION, get
	ThreadPagePriority,						// PAGE_PRIORITY_INFORMATION, get
	ThreadActualBasePriority,
	ThreadTebInformation,					// THREAD_TEB_INFORMATION, get (reads bytes out of specified thread's TEB)
	ThreadCSwitchMon,
	ThreadCSwitchPmu,
	ThreadWow64Context,						// WOW64_CONTEXT, get
	ThreadGroupInformation,
	ThreadUmsInformation,
	ThreadCounterProfiling,
	ThreadIdealProcessorEx,					// PROCESSOR_NUMBER, get, last member for Windows 7
	ThreadCpuAccountingInformation,			// Last member for Windows 8
	ThreadSuspendCount,						// Last member for Windows 8.1
	ThreadHeterogeneousCpuPolicy,
	ThreadContainerId,
	ThreadNameInformation,					// UNICODE_STRING, get/set
	ThreadSelectedCpuSets,
	ThreadSystemThreadInformation,
	ThreadActualGroupAffinity,
	ThreadDynamicCodePolicyInfo,
	ThreadExplicitCaseSensitivity,
	ThreadWorkOnBehalfTicket,
	ThreadSubsystemInformation,
	ThreadDbgkWerReportActive,
	ThreadAttachContainer,
	ThreadManageWritesToExecutableMemory,
	ThreadPowerThrottlingState,
	ThreadWorkloadClass,					// Last member for Windows 10
	ThreadCreateStateChange,				// Windows 11+
	ThreadApplyStateChange,
	ThreadStrongerBadHandleChecks,
	ThreadEffectiveIoPriority,
	ThreadEffectivePagePriority,
	MaxThreadInfoClass
} THREADINFOCLASS;

typedef enum _SYSINFOCLASS {
	SystemBasicInformation,								// SYSTEM_BASIC_INFORMATION
	SystemProcessorInformation,							// SYSTEM_PROCESSOR_INFORMATION
	SystemPerformanceInformation,						// SYSTEM_PERFORMANCE_INFORMATION
	SystemTimeOfDayInformation,							// SYSTEM_TIMEOFDAY_INFORMATION
	SystemPathInformation,								// always returns STATUS_NOT_IMPLEMENTED
	SystemProcessInformation,
	SystemCallCountInformation,
	SystemDeviceInformation,
	SystemProcessorPerformanceInformation,
	SystemFlagsInformation,
	SystemCallTimeInformation,
	SystemModuleInformation,
	SystemLocksInformation,
	SystemStackTraceInformation,
	SystemPagedPoolInformation,
	SystemNonPagedPoolInformation,
	SystemHandleInformation,
	SystemObjectInformation,
	SystemPageFileInformation,
	SystemVdmInstemulInformation,
	SystemVdmBopInformation,
	SystemFileCacheInformation,
	SystemPoolTagInformation,
	SystemInterruptInformation,
	SystemDpcBehaviorInformation,
	SystemFullMemoryInformation,
	SystemLoadGdiDriverInformation,
	SystemUnloadGdiDriverInformation,
	SystemTimeAdjustmentInformation,
	SystemSummaryMemoryInformation,
	SystemMirrorMemoryInformation,
	SystemPerformanceTraceInformation,
	SystemObsolete0,
	SystemExceptionInformation,
	SystemCrashDumpStateInformation,
	SystemKernelDebuggerInformation,
	SystemContextSwitchInformation,
	SystemRegistryQuotaInformation,
	SystemExtendServiceTableInformation,
	SystemPrioritySeperation,
	SystemVerifierAddDriverInformation,
	SystemVerifierRemoveDriverInformation,
	SystemProcessorIdleInformation,
	SystemLegacyDriverInformation,
	SystemCurrentTimeZoneInformation,
	SystemLookasideInformation,
	SystemTimeSlipNotification,
	SystemSessionCreate,
	SystemSessionDetach,
	SystemSessionInformation,
	SystemRangeStartInformation,
	SystemVerifierInformation,
	SystemVerifierThunkExtend,
	SystemSessionProcessInformation,					// SYSTEM_SESSION_PROCESS_INFORMATION
	SystemLoadGdiDriverInSystemSpace,
	SystemNumaProcessorMap,
	SystemPrefetcherInformation,
	SystemExtendedProcessInformation,
	SystemRecommendedSharedDataAlignment,
	SystemComPlusPackage,
	SystemNumaAvailableMemory,
	SystemProcessorPowerInformation,
	SystemEmulationBasicInformation,
	SystemEmulationProcessorInformation,				// SYSTEM_PROCESSOR_INFORMATION
	SystemExtendedHandleInformation,
	SystemLostDelayedWriteInformation,
	SystemBigPoolInformation,
	SystemSessionPoolTagInformation,
	SystemSessionMappedViewInformation,
	SystemHotpatchInformation,
	SystemObjectSecurityMode,
	SystemWatchdogTimerHandler,
	SystemWatchdogTimerInformation,
	SystemLogicalProcessorInformation,
	SystemWow64SharedInformation,
	SystemRegisterFirmwareTableInformationHandler,
	SystemFirmwareTableInformation,
	SystemModuleInformationEx,
	SystemVerifierTriageInformation,
	SystemSuperfetchInformation,
	SystemMemoryListInformation,
	SystemFileCacheInformationEx,						// last member in WRK
	SystemThreadPriorityClientIdInformation,
	SystemProcessorIdleCycleTimeInformation,
	SystemVerifierCancellationInformation,
	SystemProcessorPowerInformationEx,
	SystemRefTraceInformation,
	SystemSpecialPoolInformation,
	SystemProcessIdInformation,
	SystemErrorPortInformation,
	SystemBootEnvironmentInformation,
	SystemHypervisorInformation,
	SystemVerifierInformationEx,						// SYSTEM_VERIFIER_INFORMATION_EX
	SystemTimeZoneInformation,
	SystemImageFileExecutionOptionsInformation,			// SYSTEM_IMAGE_FILE_EXECUTION_OPTIONS_INFORMATION
	SystemCoverageInformation,
	SystemPrefetchPatchInformation,
	SystemVerifierFaultsInformation,
	SystemSystemPartitionInformation,
	SystemSystemDiskInformation,
	SystemProcessorPerformanceDistribution,
	SystemNumaProximityNodeInformation,
	SystemDynamicTimeZoneInformation,
	SystemCodeIntegrityInformation,
	SystemProcessorMicrocodeUpdateInformation,
	SystemProcessorBrandString,
	SystemVirtualAddressInformation,
	SystemLogicalProcessorAndGroupInformation,
	SystemProcessorCycleTimeInformation,
	SystemStoreInformation,
	SystemRegistryAppendString,
	SystemAitSamplingValue,
	SystemVhdBootInformation,
	SystemCpuQuotaInformation,
	SystemNativeBasicInformation,
	SystemErrorPortTimeouts,
	SystemLowPriorityIoInformation,
	SystemBootEntropyInformation,
	SystemVerifierCountersInformation,
	SystemPagedPoolInformationEx,
	SystemSystemPtesInformationEx,
	SystemNodeDistanceInformation,
	SystemAcpiAuditInformation,
	SystemBasicPerformanceInformation,					// SYSTEM_BASIC_PERFORMANCE_INFORMATION, last member in Win7
	SystemQueryPerformanceCounterInformation,			// Win7 SP1+ only
	SystemSessionBigPoolInformation,
	SystemBootGraphicsInformation,
	SystemScrubPhysicalMemoryInformation,
	SystemBadPageInformation,
	SystemProcessorProfileControlArea,
	SystemCombinePhysicalMemoryInformation,
	SystemEntropyInterruptTimingInformation,
	SystemConsoleInformation,
	SystemPlatformBinaryInformation,
	SystemPolicyInformation,
	SystemHypervisorProcessorCountInformation,
	SystemDeviceDataInformation,
	SystemDeviceDataEnumerationInformation,
	SystemMemoryTopologyInformation,
	SystemMemoryChannelInformation,
	SystemBootLogoInformation,
	SystemProcessorPerformanceInformationEx,
	SystemCriticalProcessErrorLogInformation,
	SystemSecureBootPolicyInformation,
	SystemPageFileInformationEx,
	SystemSecureBootInformation,
	SystemEntropyInterruptTimingRawInformation,
	SystemPortableWorkspaceEfiLauncherInformation,
	SystemFullProcessInformation,						// last member in Windows 8
	SystemKernelDebuggerInformationEx,
	SystemBootMetadataInformation,
	SystemSoftRebootInformation,
	SystemElamCertificateInformation,
	SystemOfflineDumpConfigInformation,
	SystemProcessorFeaturesInformation,
	SystemRegistryReconciliationInformation,
	SystemEdidInformation,								// last member in Windows 8.1
	SystemManufacturingInformation,
	SystemEnergyEstimationConfigInformation,
	SystemHypervisorDetailInformation,
	SystemProcessorCycleStatsInformation,
	SystemVmGenerationCountInformation,
	SystemTrustedPlatformModuleInformation,
	SystemKernelDebuggerFlags,
	SystemCodeIntegrityPolicyInformation,
	SystemIsolatedUserModeInformation,
	SystemHardwareSecurityTestInterfaceResultsInformation,
	SystemSingleModuleInformation,
	SystemAllowedCpuSetsInformation,
	SystemDmaProtectionInformation,
	SystemInterruptCpuSetsInformation,
	SystemSecureBootPolicyFullInformation,
	SystemCodeIntegrityPolicyFullInformation,
	SystemAffinitizedInterruptProcessorInformation,
	SystemRootSiloInformation,
	SystemCpuSetInformation,
	SystemCpuSetTagInformation,
	SystemWin32WerStartCallout,
	SystemSecureKernelProfileInformation,
	SystemCodeIntegrityPlatformManifestInformation,
	SystemInterruptSteeringInformation,
	SystemSuppportedProcessorArchitectures,
	SystemMemoryUsageInformation,
	SystemCodeIntegrityCertificateInformation,
	SystemPhysicalMemoryInformation,
	SystemControlFlowTransition,
	SystemKernelDebuggingAllowed,
	SystemActivityModerationExeState,
	SystemActivityModerationUserSettings,
	SystemCodeIntegrityPoliciesFullInformation,
	SystemCodeIntegrityUnlockInformation,
	SystemIntegrityQuotaInformation,
	SystemFlushInformation,
	SystemProcessorIdleMaskInformation,
	SystemSecureDumpEncryptionInformation,
	SystemWriteConstraintInformation,
	SystemKernelVaShadowInformation,
	SystemHypervisorSharedPageInformation,
	SystemFirmwareBootPerformanceInformation,
	SystemCodeIntegrityVerificationInformation,
	SystemFirmwarePartitionInformation,
	SystemSpeculationControlInformation,
	SystemDmaGuardPolicyInformation,
	SystemEnclaveLaunchControlInformation,
	SystemWorkloadAllowedCpuSetsInformation,
	SystemCodeIntegrityUnlockModeInformation,
	SystemLeapSecondInformation,
	SystemFlags2Information,
	SystemSecurityModelInformation,
	SystemCodeIntegritySyntheticCacheInformation,
	SystemFeatureConfigurationInformation,
	SystemFeatureConfigurationSectionInformation,
	SystemFeatureUsageSubscriptionInformation,
	SystemSecureSpeculationControlInformation,
	MaxSystemInfoClass
} SYSINFOCLASS;

typedef struct _SYSTEM_BASIC_PERFORMANCE_INFORMATION {
	ULONG_PTR	AvailablePages;
	ULONG_PTR	CommittedPages;
	ULONG_PTR	CommitLimit;
	ULONG_PTR	PeakCommitment;
} TYPEDEF_TYPE_NAME(SYSTEM_BASIC_PERFORMANCE_INFORMATION);

#define LDRP_STATIC_LINK				0x00000002
#define LDRP_IMAGE_DLL					0x00000004
#define LDRP_LOAD_IN_PROGRESS			0x00001000
#define LDRP_UNLOAD_IN_PROGRESS			0x00002000
#define LDRP_ENTRY_PROCESSED			0x00004000
#define LDRP_ENTRY_INSERTED				0x00008000
#define LDRP_CURRENT_LOAD				0x00010000
#define LDRP_FAILED_BUILTIN_LOAD		0x00020000
#define LDRP_DONT_CALL_FOR_THREADS		0x00040000
#define LDRP_PROCESS_ATTACH_CALLED		0x00080000
#define LDRP_DEBUG_SYMBOLS_LOADED		0x00100000
#define LDRP_IMAGE_NOT_AT_BASE			0x00200000
#define LDRP_COR_IMAGE					0x00400000
#define LDRP_COR_OWNS_UNMAP				0x00800000
#define LDRP_SYSTEM_MAPPED				0x01000000
#define LDRP_IMAGE_VERIFYING			0x02000000
#define LDRP_DRIVER_DEPENDENT_DLL		0x04000000
#define LDRP_ENTRY_NATIVE				0x08000000
#define LDRP_REDIRECTED					0x10000000
#define LDRP_NON_PAGED_DEBUG_INFO		0x20000000
#define LDRP_MM_LOADED					0x40000000
#define LDRP_COMPAT_DATABASE_PROCESSED	0x80000000

// https://www.geoffchappell.com/studies/windows/km/ntoskrnl/inc/api/ntldr/rtl_process_module_information.htm
typedef struct _RTL_PROCESS_MODULE_INFORMATION {
	PVOID			Section;
	PVOID			MappedBase;
	PVOID			ImageBase;
	ULONG			ImageSize;
	ULONG			Flags;					// LDRP_* flags defined above
	USHORT			LoadOrderIndex;
	USHORT			InitOrderIndex;
	USHORT			LoadCount;
	USHORT			OffsetToFileName;		// &FullPathName[OffsetToFileName] is the base name.
	CHAR			FullPathName[0x100];
} TYPEDEF_TYPE_NAME(RTL_PROCESS_MODULE_INFORMATION);

// definition from this structure can be found in 8175 leaked symbols and probably other symbols too
// usage example:
// https://raw.githubusercontent.com/gtworek/PSBits/master/DFIR/SystemModuleInformationEx.c
typedef struct _RTL_PROCESS_MODULE_INFORMATION_EX {
	USHORT							NextOffset;
	RTL_PROCESS_MODULE_INFORMATION	BaseInfo;
	ULONG							ImageChecksum;	// I'm guessing these are the fields straight out of the PE headers
	ULONG							TimeDateStamp;
	PVOID							DefaultBase;
} TYPEDEF_TYPE_NAME(RTL_PROCESS_MODULE_INFORMATION_EX);

// https://www.geoffchappell.com/studies/windows/km/ntoskrnl/inc/api/ntldr/rtl_process_modules.htm
typedef struct _RTL_PROCESS_MODULES {
	ULONG							NumberOfModules;
	RTL_PROCESS_MODULE_INFORMATION	Modules[];
} TYPEDEF_TYPE_NAME(RTL_PROCESS_MODULES);

typedef enum _MEMINFOCLASS {
	MemoryBasicInformation,				// MEMORY_BASIC_INFORMATION
	MemoryWorkingSetInformation,		// ULONG_PTR
	MemoryMappedFilenameInformation,	// UNICODE_STRING followed by a buffer to store the filename
	MemoryRegionInformation,			// MEMORY_REGION_INFORMATION
	MemoryWorkingSetExInformation		// MEMORY_WORKING_SET_EX_INFORMATION
} MEMINFOCLASS;

typedef struct _MEMORY_REGION_INFORMATION {
	PVOID								AllocationBase;
	PVOID								AllocationProtect;

	union {
		ULONG							RegionType;

		struct {
			UCHAR						Private:1;
			UCHAR						MappedDataFile:1;
			UCHAR						MappedImage:1;
			UCHAR						MappedPageFile:1;
			UCHAR						MappedPhysical:1;
			UCHAR						DirectMapped:1;
			ULONG						Reserved:26;
		};
	};

	SIZE_T								RegionSize; 
} TYPEDEF_TYPE_NAME(MEMORY_REGION_INFORMATION);

typedef struct _MEMORY_RANGE_ENTRY {
	PVOID	VirtualAddress;
	SIZE_T	NumberOfBytes;
} TYPEDEF_TYPE_NAME(MEMORY_RANGE_ENTRY);

typedef struct _MEMORY_WORKING_SET_EX_INFORMATION {
	PVOID			VirtualAddress;

	union {
		struct {
		    ULONG_PTR Valid				: 1;
			ULONG_PTR ShareCount		: 3;
			ULONG_PTR Win32Protection	: 11;
			ULONG_PTR Shared			: 1;
			ULONG_PTR Node				: 6;
			ULONG_PTR Locked			: 1;
			ULONG_PTR LargePage			: 1;
			ULONG_PTR Priority			: 3;
		};

		ULONG_PTR	AsUlongPtr;
	} Flags;
} TYPEDEF_TYPE_NAME(MEMORY_WORKING_SET_EX_INFORMATION);

typedef enum _NT_PRODUCT_TYPE {
	NtProductWinNt = 1,
	NtProductLanManNt,
	NtProductServer
} TYPEDEF_TYPE_NAME(NT_PRODUCT_TYPE);

typedef enum _ALTERNATIVE_ARCHITECTURE_TYPE {
	StandardDesign,
	NEC98x86
} ALTERNATIVE_ARCHITECTURE_TYPE;

typedef struct _STRING {
	USHORT								Length;
	USHORT								MaximumLength;
	PCHAR								Buffer;
} STRING, ANSI_STRING;

GEN_STD_TYPEDEFS(STRING);
GEN_STD_TYPEDEFS(ANSI_STRING);

typedef struct _UNICODE_STRING {
	USHORT								Length;
	USHORT								MaximumLength;
	PWCHAR								Buffer;
} TYPEDEF_TYPE_NAME(UNICODE_STRING);

typedef struct _UNICODE_STRING32 {
	USHORT								Length;
	USHORT								MaximumLength;
	DWORD								Buffer;
} TYPEDEF_TYPE_NAME(UNICODE_STRING32);

typedef struct _PEB_LDR_DATA {
	ULONG								Length;
	BOOLEAN								Initialized;
	PVOID								SsHandle;
	LIST_ENTRY							InLoadOrderModuleList;
	LIST_ENTRY							InMemoryOrderModuleList;
	LIST_ENTRY							InInitializationOrderModuleList;
	PVOID								EntryInProgress;
	BOOLEAN								ShutdownInProgress;
	HANDLE								ShutdownThreadId;
} TYPEDEF_TYPE_NAME(PEB_LDR_DATA);

typedef struct _LDR_DATA_TABLE_ENTRY {
	LIST_ENTRY							InLoadOrderLinks;
	LIST_ENTRY							InMemoryOrderLinks;
	LIST_ENTRY							InInitializationOrderLinks;

	PVOID								DllBase;
	PVOID								EntryPoint;
	ULONG								SizeOfImage;

	UNICODE_STRING						FullDllName;
	UNICODE_STRING						BaseDllName;

	ULONG								Flags;											// LDRP_
	USHORT								LoadCount;
	USHORT								TlsIndex;

	union {
		LIST_ENTRY						HashLinks;

		struct {
			PVOID						SectionPointer;
			ULONG						CheckSum;
		};
	};

	union {
		ULONG							TimeDateStamp;
		PVOID							LoadedImports;
	};

	PVOID								EntryPointActivationContext;
	PVOID								PatchInformation;

	LIST_ENTRY							ForwarderLinks;
	LIST_ENTRY							ServiceTagLinks;
	LIST_ENTRY							StaticLinks;

	PVOID								ContextInformation;
	ULONG_PTR							OriginalBase;
	LARGE_INTEGER						LoadTime;
} TYPEDEF_TYPE_NAME(LDR_DATA_TABLE_ENTRY);

typedef struct _CURDIR {
	UNICODE_STRING						DosPath;
	HANDLE								Handle;
} TYPEDEF_TYPE_NAME(CURDIR);

typedef struct _RTL_DRIVE_LETTER_CURDIR {
	USHORT								Flags;
	USHORT								Length;
	ULONG								TimeStamp;
	STRING								DosPath;
} TYPEDEF_TYPE_NAME(RTL_DRIVE_LETTER_CURDIR);

typedef struct _RTL_RELATIVE_NAME_U {
	UNICODE_STRING						RelativeName;
	HANDLE								ContainingDirectory;
	PVOID								CurDirRef;
} TYPEDEF_TYPE_NAME(RTL_RELATIVE_NAME_U);

typedef struct _PEB_FREE_BLOCK {
	struct _PEB_FREE_BLOCK				*Next;
	ULONG								Size;
} TYPEDEF_TYPE_NAME(PEB_FREE_BLOCK);

typedef struct _RTL_USER_PROCESS_PARAMETERS {
	ULONG								MaximumLength;
	ULONG								Length;

	ULONG								Flags; // RTL_USER_PROCESS_PARAMETERS_*
	ULONG								DebugFlags;

	HANDLE								ConsoleHandle;
	ULONG								ConsoleFlags;
	HANDLE								StandardInput;
	HANDLE								StandardOutput;
	HANDLE								StandardError;

	CURDIR								CurrentDirectory;
	UNICODE_STRING						DllPath;
	UNICODE_STRING						ImagePathName;
	UNICODE_STRING						CommandLine;
	PVOID								Environment;

	ULONG								StartingX;
	ULONG								StartingY;
	ULONG								CountX;
	ULONG								CountY;
	ULONG								CountCharsX;
	ULONG								CountCharsY;
	ULONG								FillAttribute;

	ULONG								WindowFlags;
	ULONG								ShowWindowFlags;
	UNICODE_STRING						WindowTitle;
	UNICODE_STRING						DesktopInfo;
	UNICODE_STRING						ShellInfo;
	UNICODE_STRING						RuntimeData;
	RTL_DRIVE_LETTER_CURDIR				CurrentDirectories[RTL_MAX_DRIVE_LETTERS];

	ULONG_PTR VOLATILE					EnvironmentSize;
	ULONG_PTR VOLATILE					EnvironmentVersion;
} TYPEDEF_TYPE_NAME(RTL_USER_PROCESS_PARAMETERS);

// for more info on this "API set" crap - https://lucasg.github.io/2017/10/15/Api-set-resolution
typedef struct _API_SET_NAMESPACE {
	ULONG	Version;
	ULONG	Size;
	ULONG	Flags;
	ULONG	Count;
	ULONG	EntryOffset;
	ULONG	HashOffset;
	ULONG	HashFactor;
} TYPEDEF_TYPE_NAME(API_SET_NAMESPACE);

typedef struct _API_SET_HASH_ENTRY {
	ULONG	Hash;
	ULONG	Index;
} TYPEDEF_TYPE_NAME(API_SET_HASH_ENTRY);

typedef struct _API_SET_NAMESPACE_ENTRY {
	ULONG	Flags;
	ULONG	NameOffset;
	ULONG	NameLength;
	ULONG	HashedLength;
	ULONG	ValueOffset;
	ULONG	ValueCount;
} TYPEDEF_TYPE_NAME(API_SET_NAMESPACE_ENTRY);

typedef struct _API_SET_VALUE_ENTRY {
	ULONG	Flags;
	ULONG	NameOffset;
	ULONG	NameLength;
	ULONG	ValueOffset;
	ULONG	ValueLength;
} TYPEDEF_TYPE_NAME(API_SET_VALUE_ENTRY);

typedef struct _PEB {
	BOOLEAN								InheritedAddressSpace;
	BOOLEAN								ReadImageFileExecOptions;
	BOOLEAN								BeingDebugged;

	union {
		UCHAR							BitField;
		struct {
			UCHAR						ImageUsedLargePages : 1;
			UCHAR						IsProtectedProcess : 1;
			UCHAR						IsLegacyProcess : 1;
			UCHAR						IsImageDynamicallyRelocated : 1;
			UCHAR						SkipPatchingUser32Forwarders : 1;
			UCHAR						SpareBits0 : 2;

			// windows 10 only but we might use it for vxkex in the future
			UCHAR						IsLongPathAwareProcess : 1;
		};
	};

	HANDLE								Mutant;

	PVOID								ImageBaseAddress;
	PPEB_LDR_DATA						Ldr;
	PRTL_USER_PROCESS_PARAMETERS		ProcessParameters;
	PVOID								SubSystemData;
	HANDLE								ProcessHeap;
	PRTL_CRITICAL_SECTION				FastPebLock;

	PVOID								AtlThunkSListPtr;
	PVOID								IFEOKey;

	union {
		ULONG						CrossProcessFlags;
		struct {
			ULONG					ProcessInJob : 1;
			ULONG					ProcessInitializing : 1;
			ULONG					ProcessUsingVEH : 1;
			ULONG					ProcessUsingVCH : 1;
			ULONG					ProcessUsingFTH : 1;
			ULONG					ReservedBits0 : 27;
		};
	};

	union {
		// array of function pointers for KiUserCallbackDispatcher
		PVOID							KernelCallbackTable;

		// UserSharedInfoPtr is only relevant when starting "protected processes".
		PVOID							UserSharedInfoPtr;
	};

	ULONG								SystemReserved[1];
	ULONG								AtlThunkSListPtr32;

	PAPI_SET_NAMESPACE					ApiSetMap;

	ULONG								TlsExpansionCounter;
	PVOID								TlsBitmap;
	ULONG								TlsBitmapBits[2];
	PVOID								ReadOnlySharedMemoryBase;

	PVOID								HotpatchInformation;

	PPVOID								ReadOnlyStaticServerData;
	PVOID								AnsiCodePageData;
	PVOID								OemCodePageData;
	PVOID								UnicodeCaseTableData;

	ULONG								NumberOfProcessors;
	ULONG								NtGlobalFlag;

	// I believe this block of entries is derived from the registry values located
	// inside HKLM\SYSTEM\CurrentControlSet\Control\Session Manager
	LARGE_INTEGER						CriticalSectionTimeout;
	SIZE_T								HeapSegmentReserve;
	SIZE_T								HeapSegmentCommit;
	SIZE_T								HeapDeCommitTotalFreeThreshold;
	SIZE_T								HeapDeCommitFreeBlockThreshold;

    // Where heap manager keeps track of all heaps created for a process
    // Fields initialized by MmCreatePeb. ProcessHeaps is initialized
    // to point to the first free byte after the PEB and MaximumNumberOfHeaps
    // is computed from the page size used to hold the PEB, less the fixed
    // size of this data structure.
	ULONG								NumberOfHeaps;
	ULONG								MaximumNumberOfHeaps;
	PPVOID								ProcessHeaps;

	PVOID								GdiSharedHandleTable;
	PVOID								ProcessStarterHelper;
	ULONG								GdiDCAttributeList;
	PRTL_CRITICAL_SECTION				LoaderLock;

	ULONG								OSMajorVersion;
	ULONG								OSMinorVersion;
	USHORT								OSBuildNumber;
	USHORT								OSCSDVersion;
	ULONG								OSPlatformId;
	ULONG								ImageSubsystem;
	ULONG								ImageSubsystemMajorVersion;
	ULONG								ImageSubsystemMinorVersion;
	ULONG_PTR							ImageProcessAffinityMask;
	GDI_HANDLE_BUFFER					GdiHandleBuffer;

	// PostProcessInitRoutine is called by NTDLL after all DLL entry points are called.
	// However, it is still useless, because user32.dll will overwrite it with NULL when
	// its DLL entry point is called. This makes its usage very unreliable.
	PPS_POST_PROCESS_INIT_ROUTINE		PostProcessInitRoutine;

	PVOID								TlsExpansionBitmap;
	ULONG								TlsExpansionBitmapBits[32];
	ULONG								SessionId;

	// See KACF_*
	ULONGLONG							AppCompatFlags;
	ULONGLONG							AppCompatFlagsUser;

	PVOID								pShimData;
	PVOID								AppCompatInfo;

	UNICODE_STRING						CSDVersion;

	PVOID								ActivationContextData;
	PVOID								ProcessAssemblyStorageMap;
	PVOID								SystemDefaultActivationContextData;
	PVOID								SystemAssemblyStorageMap;

	SIZE_T								MinimumStackCommit;

	PPVOID								FlsCallback;
	PVOID								SparePointers[4];
	LIST_ENTRY							FlsListHead;
	PVOID								FlsBitmap;
	ULONG								FlsBitmapBits[4];
	ULONG								FlsHighIndex;

	PVOID								WerRegistrationData;
	PVOID								WerShipAssetPtr;

	PVOID								pContextData;
	PVOID								pImageHeaderHash;

	union {
		ULONG							TracingFlags;
		struct {
			ULONG						HeapTracingEnabled : 1;
			ULONG						CritSecTracingEnabled : 1;
			ULONG						SpareTracingBits : 30;
		};
	};

	//
	// Extending this structure to store our own data is not allowed.
	// See the comment for "NumberOfHeaps" to find out why.
	//
} TYPEDEF_TYPE_NAME(PEB);

#define GDI_BATCH_BUFFER_SIZE 310

typedef struct _GDI_TEB_BATCH {
	ULONG								Offset;
	ULONG_PTR							HDC;
	ULONG								Buffer[GDI_BATCH_BUFFER_SIZE];
} TYPEDEF_TYPE_NAME(GDI_TEB_BATCH);

typedef struct _TEB_ACTIVE_FRAME_CONTEXT {
	ULONG								Flags;
	PCSTR								FrameName;
} TYPEDEF_TYPE_NAME(TEB_ACTIVE_FRAME_CONTEXT);

typedef struct _TEB_ACTIVE_FRAME {
	ULONG								Flags;
	struct _TEB_ACTIVE_FRAME			*Previous;
	PCTEB_ACTIVE_FRAME_CONTEXT			Context;
} TYPEDEF_TYPE_NAME(TEB_ACTIVE_FRAME);

typedef struct _TEB {
	NT_TIB								NtTib;

	union {
		struct {
			//
			// KexLdrShouldRewriteDll is set if the current call stack
			// includes one of the following functions:
			//
			//   Ext_GetModuleHandleA
			//   Ext_GetModuleHandleW
			//   Ext_GetModuleHandleExA
			//   Ext_GetModuleHandleExW
			//   Ext_LoadLibraryA
			//   Ext_LoadLibraryW
			//   Ext_LoadLibraryExA
			//   Ext_LoadLibraryExW
			//

			BOOLEAN						KexLdrShouldRewriteDll	: 1;
		};

		ULONG_PTR						KexPerThreadData;
		PVOID							EnvironmentPointer; // unused
	};

	CLIENT_ID							ClientId; // GetCurrentProcessId & GetCurrentThreadId
	PVOID								ActiveRpcHandle; // unused
	PVOID								ThreadLocalStoragePointer;
	PPEB								ProcessEnvironmentBlock;
	ULONG								LastErrorValue; // GetLastError & SetLastError
	ULONG								CountOfOwnedCriticalSections; // used by app verifier

	PVOID								CsrClientThread;
	PVOID								Win32ThreadInfo;
	ULONG								User32Reserved[0x1A];
	ULONG								UserReserved[5];
	PVOID								WOW32Reserved;

	ULONG								CurrentLocale; // GetThreadLocale & SetThreadLocale
	ULONG								FpSoftwareStatusRegister; // unused

	PVOID								SystemReserved1[0x36];
	LONG								ExceptionCode;

	// The original type of this entry is PACTIVATION_CONTEXT_STACK but it's irrelevant
	// to me and there were shitloads of structures to copy so I gave up.
	PVOID								ActivationContextStackPointer;

	UCHAR								SpareBytes[0x24];
	ULONG								TxFsContext;
	
	GDI_TEB_BATCH						GdiTebBatch;
	CLIENT_ID							RealClientId;
	PVOID								GdiCachedProcessHandle;
	ULONG								GdiClientPID;
	ULONG								GdiClientTID;
	PVOID								GdiThreadLocalInfo;
	ULONG_PTR							Win32ClientInfo[0x3E];
	
	PVOID								glDispatchTable[0xE9];
	ULONG_PTR							glReserved1[0x1D];
	PVOID								glReserved2;
	PVOID								glSectionInfo;
	PVOID								glSection;
	PVOID								glTable;
	PVOID								glCurrentRC;
	PVOID								glContext;

	ULONG								LastStatusValue; // set by RtlNtStatusToDosError
	UNICODE_STRING						StaticUnicodeString; // temporary scratch buffer
	WCHAR								StaticUnicodeBuffer[MAX_PATH + 1];
	PVOID								DeallocationStack;
	PVOID								TlsSlots[0x40];
	LIST_ENTRY							TlsLinks;
	PVOID								Vdm;
	PVOID								ReservedForNtRpc; // rpcrt4.dll
	HANDLE								DbgSsReserved[2];

	ULONG								HardErrorMode;

#ifdef _M_X64
	PVOID								Instrumentation[0x0B];
#else
	PVOID								Instrumentation[0x09];
#endif

	GUID								ActivityId;
	PVOID								SubProcessTag;
	PVOID								EtwLocalData;
	PVOID								EtwTraceData;

	PVOID								WinSockData;
	ULONG								GdiBatchCount;

	union {
		PROCESSOR_NUMBER				CurrentIdealProcessor;
		ULONG							IdealProcessorValue;

		struct {
			UCHAR						ReservedPad0;
			UCHAR						ReservedPad1;
			UCHAR						ReservedPad2;
			UCHAR						IdealProcessor;
		};
	};

	ULONG								GuaranteedStackBytes;
	PVOID								ReservedForPerf;
	PVOID								ReservedForOle;
	ULONG								WaitingOnLoaderLock;

	PVOID								SavedPriorityState;
	ULONG_PTR							SoftPatchPtr1;
	PVOID								ThreadPoolData;

	PVOID								*TlsExpansionSlots;
	PVOID								DeallocationBStore;
	PVOID								BStoreLimit;
	ULONG								MuiGeneration;
	ULONG								IsImpersonating;
	PVOID								NlsCache;

	PVOID								pShimData;
	ULONG								HeapVirtualAffinity;
	PVOID								CurrentTransactionHandle;
	PTEB_ACTIVE_FRAME					ActiveFrame;
	PVOID								FlsData;

	PVOID								PreferredLanguages;
	PVOID								UserPrefLanguages;
	PVOID								MergedPrefLanguages;
	ULONG								MuiImpersonation;

	union {
		USHORT VOLATILE					CrossTebFlags;

		struct {
			USHORT						SpareCrossTebBits : 16;
		};
	};

	union {
		USHORT							SameTebFlags;

		struct {
			USHORT						SafeThunkCall : 1;
			USHORT						InDbgPrint : 1;
			USHORT						HasFiberData : 1;
			USHORT						SkipThreadAttach : 1;
			USHORT						WerInShipAssertCode : 1;
			USHORT						RanProcessInit : 1;
			USHORT						ClonedThread : 1;
			USHORT						SuppressDbgMsg : 1;
			USHORT						DisableUserStackWalk : 1;
			USHORT						RtlExceptionAttached : 1;
			USHORT						InitialThread : 1;
			USHORT						SpareSameTebBits : 5;
		};
	};

	PVOID								TxnScopeEnterCallback;
	PVOID								TxnScopeExitCallback;
	PVOID								TxnScopeContext;
	ULONG								LockCount;
	ULONG								SpareUlong0;
	PVOID								ResourceRetValue;
} TYPEDEF_TYPE_NAME(TEB);

typedef struct _KSYSTEM_TIME {
	ULONG	LowPart;
	LONG	High1Time;
	LONG	High2Time;
} TYPEDEF_TYPE_NAME(KSYSTEM_TIME);

// KUSER_SHARED_DATA has been checked and is 100% accurate for Windows 7,
// with SP1 and all security updates as of 30-Sep-2022. It is very likely
// to be accurate for Win7 RTM and plain SP1 as well.
//
// Also see:
// https://www.geoffchappell.com/studies/windows/km/ntoskrnl/inc/api/ntexapi_x/kuser_shared_data/index.htm
typedef struct _KUSER_SHARED_DATA {
	ULONG VOLATILE						TickCountLowDeprecated;
	ULONG								TickCountMultiplier;
	KSYSTEM_TIME VOLATILE				InterruptTime;
	KSYSTEM_TIME VOLATILE				SystemTime;
	KSYSTEM_TIME VOLATILE				TimeZoneBias;

	USHORT								ImageNumberLow;
	USHORT								ImageNumberHigh;

	// Contains the path of the Windows directory, e.g. L"C:\\Windows"
	WCHAR								NtSystemRoot[MAX_PATH];
	
	// These values seem to be unused and all set to 0.
	ULONG								MaxStackTraceDepth;
	ULONG								CryptoExponent;
	ULONG								TimeZoneId;
	ULONG								LargePageMinimum;
	ULONG								Reserved2[6];		// actually Reserved2[7]
	ULONG								NtBuildNumber;		// win10 only but used for vxkex

	NT_PRODUCT_TYPE						NtProductType;
	BOOLEAN								ProductTypeIsValid;

	// Checked by CreateProcessInternalW.
	ULONG								NtMajorVersion;
	ULONG								NtMinorVersion;

	// Search for PF_* in this file
	BOOLEAN								ProcessorFeatures[PROCESSOR_FEATURE_MAX];

	// these two NOT VALID FOR 64BIT since they are ULONGs.
	// They are however valid for wow64 apps.
	ULONG								MmHighestUserAddress;
	ULONG								MmSystemRangeStart;

	ULONG VOLATILE						TimeSlip;
	ALTERNATIVE_ARCHITECTURE_TYPE		AlternativeArchitecture;
	ULONG								AltArchitecturePad[1];
	LARGE_INTEGER						SystemExpirationDate;
	ULONG								SuiteMask;
	BOOLEAN								KdDebuggerEnabled;

	// NX_SUPPORT_POLICY_*
	UCHAR								NXSupportPolicy;

	ULONG VOLATILE						ActiveConsoleId;
	ULONG VOLATILE						DismountCount;

	// ComPlusPackage is the cached value initialized from the registry value
	// HKLM\Software\Microsoft\.NETFramework\Enable64Bit (as DWORD).
	ULONG								ComPlusPackage;

	// Time in tick count for system-wide last user input across all terminal
	// sessions. For MP performance, it is not updated all the time (e.g. once
	// a minute per session). It is used for idle detection.
	ULONG								LastSystemRITEventTickCount;

	// Multiply by page size to get amount of physical memory in the computer
	ULONG								NumberOfPhysicalPages;

	// TRUE if system booted in safe mode
	BOOLEAN								SafeBootMode;

	union {
		UCHAR							TscQpcData;

		struct {
			UCHAR						TscQpcEnabled : 1;
			UCHAR						TscQpcSpareFlag : 1;
			UCHAR						TscQpcShift : 6;
		};
	};

	UCHAR								TscQpcPad[2];
	
	union {
		ULONG							SharedDataFlags;

		struct {
			ULONG						DbgErrorPortPresent : 1;
			ULONG						DbgElevationEnabled : 1;
			ULONG						DbgVirtEnabled : 1;
			ULONG						DbgInstallerDetectEnabled : 1;
			ULONG						DbgSystemDllRelocated : 1;
			ULONG						DbgDynProcessorEnabled : 1;
			ULONG						DbgSEHValidationEnabled : 1;
			ULONG						SpareBits : 25;
		};
	};

	ULONG								DataFlagsPad[1];

	ULONGLONG							TestRetInstruction;
	ULONG								SystemCall;
	ULONG								SystemCallReturn;
	ULONGLONG							SystemCallPad[3];

	union {
		KSYSTEM_TIME VOLATILE			TickCount;
		ULONGLONG VOLATILE				TickCountQuad;
	};

	// Cookie is used by EncodeSystemPointer and DecodeSystemPointer APIs.
	// It is most likely to be a random value chosen at system boot.
	ULONG								Cookie;
	ULONG								CookiePad[1];

	LONGLONG							ConsoleSessionForegroundProcessId;
	ULONG								Wow64SharedInformation[0x10];
	USHORT								UserModeGlobalLogger[16];
	ULONG								LangGenerationCount;
	ULONGLONG							Reserved5;
	ULONGLONG VOLATILE					InterruptTimeBias;
	ULONGLONG VOLATILE					TscQpcBias;
	ULONG VOLATILE						ActiveProcessorCount;
	USHORT VOLATILE						ActiveGroupCount;
	USHORT								Reserved4;
	ULONG VOLATILE						AitSamplingValue;
	ULONG VOLATILE						AppCompatFlag;

	// The following two members are often set to zero with certain Win7
	// security updates installed, because they decrease the effectiveness
	// of ASLR. Do not use these to obtain the address of NTDLL - they are
	// not reliable.
	ULONGLONG							SystemDllNativeRelocation;
	ULONG								SystemDllWowRelocation;
	
	ULONG								XStatePad[1];
	XSTATE_CONFIGURATION				XState;
} TYPEDEF_TYPE_NAME(KUSER_SHARED_DATA);

typedef struct _OBJECT_ATTRIBUTES {
	ULONG							Length;
	HANDLE							RootDirectory;
	PUNICODE_STRING					ObjectName;
	ULONG							Attributes;
	PSECURITY_DESCRIPTOR			SecurityDescriptor;
	PSECURITY_QUALITY_OF_SERVICE	SecurityQualityOfService;
} TYPEDEF_TYPE_NAME(OBJECT_ATTRIBUTES);

#define LDR_DLL_LOADED_FLAG_RELOCATED (0x00000001)

typedef struct _LDR_DLL_NOTIFICATION_DATA {
	ULONG				Flags; // always zero on win7
	PCUNICODE_STRING	FullDllName;
	PCUNICODE_STRING	BaseDllName;
	PVOID				DllBase;
	ULONG				SizeOfImage;
} TYPEDEF_TYPE_NAME(LDR_DLL_NOTIFICATION_DATA);

typedef struct _IO_STATUS_BLOCK {
	union {
		NTSTATUS Status;
		PVOID Pointer;
	};

	ULONG_PTR Information;
} TYPEDEF_TYPE_NAME(IO_STATUS_BLOCK);

typedef struct _ALPC_PORT_ATTRIBUTES
{
    ULONG Flags;
    SECURITY_QUALITY_OF_SERVICE SecurityQos;
    SIZE_T MaxMessageLength;
    SIZE_T MemoryBandwidth;
    SIZE_T MaxPoolUsage;
    SIZE_T MaxSectionSize;
    SIZE_T MaxViewSize;
    SIZE_T MaxTotalSectionSize;
    ULONG DupObjectTypes;
#ifdef _M_X64
    ULONG Reserved;
#endif
} TYPEDEF_TYPE_NAME(ALPC_PORT_ATTRIBUTES);

typedef struct _PORT_MESSAGE
{
    union
    {
        struct
        {
            CSHORT DataLength;
            CSHORT TotalLength;
        } s1;
        ULONG Length;
    } u1;
    union
    {
        struct
        {
            CSHORT Type;
            CSHORT DataInfoOffset;
        } s2;
        ULONG ZeroInit;
    } u2;
    union
    {
        CLIENT_ID ClientId;
        double DoNotUseThisField;
    };
    ULONG MessageId;
    union
    {
        SIZE_T ClientViewSize; // only valid for LPC_CONNECTION_REQUEST messages
        ULONG CallbackId; // only valid for LPC_REQUEST messages
    };
} TYPEDEF_TYPE_NAME(PORT_MESSAGE);

#if defined(USE_LPC6432)
#  define LPC_CLIENT_ID CLIENT_ID64
#  define LPC_SIZE_T ULONGLONG
#  define LPC_PVOID ULONGLONG
#  define LPC_HANDLE ULONGLONG
#else
#  define LPC_CLIENT_ID CLIENT_ID
#  define LPC_SIZE_T SIZE_T
#  define LPC_PVOID PVOID
#  define LPC_HANDLE HANDLE
#endif

typedef struct _PORT_VIEW {
	ULONG Length;
	LPC_HANDLE SectionHandle;
	ULONG SectionOffset;
	LPC_SIZE_T ViewSize;
	LPC_PVOID ViewBase;
	LPC_PVOID ViewRemoteBase;
} TYPEDEF_TYPE_NAME(PORT_VIEW);

typedef struct _REMOTE_PORT_VIEW {
	ULONG Length;
	LPC_SIZE_T ViewSize;
	LPC_PVOID ViewBase;
} TYPEDEF_TYPE_NAME(REMOTE_PORT_VIEW);

typedef struct _ALPC_MESSAGE_ATTRIBUTES
{
    ULONG AllocatedAttributes;
    ULONG ValidAttributes;
} TYPEDEF_TYPE_NAME(ALPC_MESSAGE_ATTRIBUTES);

typedef enum _PS_ATTRIBUTE_NUM {
	PsAttributeParentProcess, // in HANDLE
	PsAttributeDebugPort, // in HANDLE
	PsAttributeToken, // in HANDLE
	PsAttributeClientId, // out PCLIENT_ID
	PsAttributeTebAddress, // out PTEB
	PsAttributeImageName, // in PWSTR
	PsAttributeImageInfo, // out PSECTION_IMAGE_INFORMATION
	PsAttributeMemoryReserve, // in PPS_MEMORY_RESERVE
	PsAttributePriorityClass, // in UCHAR
	PsAttributeErrorMode, // in ULONG
	PsAttributeStdHandleInfo, // 10, in PPS_STD_HANDLE_INFO
	PsAttributeHandleList, // in PHANDLE
	PsAttributeGroupAffinity, // in PGROUP_AFFINITY
	PsAttributePreferredNode, // in PUSHORT
	PsAttributeIdealProcessor, // in PPROCESSOR_NUMBER
	PsAttributeUmsThread, // see UpdateProcThreadAttributeList in msdn (CreateProcessA/W...) in PUMS_CREATE_THREAD_ATTRIBUTES
	PsAttributeMitigationOptions, // in UCHAR
	PsAttributeProtectionLevel,
	PsAttributeSecureProcess, // since THRESHOLD (Virtual Secure Mode, Device Guard)
	PsAttributeJobList,
	PsAttributeMax
} PS_ATTRIBUTE_NUM;

typedef enum _PS_CREATE_STATE {
	PsCreateInitialState = 0,
	PsCreateFailOnFileOpen = 1,
	PsCreateFailOnSectionCreate = 2,
	PsCreateFailExeFormat = 3,
	PsCreateFailMachineMismatch = 4,
	PsCreateFailExeName = 5,
	PsCreateSuccess = 6,
	PsCreateMaximumStates = 7
} PS_CREATE_STATE;

typedef struct _PS_CREATE_INFO {
	ULONG_PTR Size;
	PS_CREATE_STATE State;

	union {
		struct {
			union {
				ULONG InitFlags;

				struct {
					UCHAR WriteOutputOnExit : 1;
					UCHAR DetectManifest : 1;
					UCHAR SpareBits1 : 6;
					UCHAR Unknown : 2;
					UCHAR SpareBits2 : 6;
					USHORT ProhibitedImageCharacteristics : 16;
				};
			};

			ACCESS_MASK AdditionalFileAccess;
		} InitState;
		
		struct {
			HANDLE FileHandle;
		} FailSection;

		struct {
			USHORT DllCharacteristics;
		} ExeFormat;

		struct {
			HANDLE IFEOKey;
		} ExeName;

		struct {
			union {
				ULONG OutputFlags;

				struct {
					UCHAR ProtectedProcess : 1;
					UCHAR AddressSpaceOverride : 1;
					UCHAR DevOverrideEnabled : 1;
					UCHAR ManifestDetected : 1;
					ULONG SpareBits : 28;
				};
			};

			HANDLE FileHandle;
			HANDLE SectionHandle;
			ULONGLONG UserProcessParametersNative;
			ULONG UserProcessParametersWow64;
			ULONG CurrentParameterFlags;
			ULONGLONG PebAddressNative;
			ULONG PebAddressWow64;
			ULONGLONG ManifestAddress;
			ULONG ManifestSize;
		} SuccessState;
	};
} TYPEDEF_TYPE_NAME(PS_CREATE_INFO);

typedef struct _PS_ATTRIBUTE {
	ULONG Attribute;
	SIZE_T Size;
	ULONG_PTR Value;
	PSIZE_T ReturnLength;
} TYPEDEF_TYPE_NAME(PS_ATTRIBUTE);

typedef struct _PS_ATTRIBUTE_LIST {
	SIZE_T TotalLength;
	PS_ATTRIBUTE Attributes[];
} TYPEDEF_TYPE_NAME(PS_ATTRIBUTE_LIST);

typedef struct _SECTION_IMAGE_INFORMATION {
	PVOID TransferAddress;
	ULONG ZeroBits;
	SIZE_T MaximumStackSize;
	SIZE_T CommittedStackSize;
	ULONG SubSystemType;
	
	union {
		struct {
			USHORT SubSystemMinorVersion;
			USHORT SubSystemMajorVersion;
		};

		ULONG SubSystemVersion;
	};

	ULONG GpValue;
	USHORT ImageCharacteristics;
	USHORT DllCharacteristics;
	USHORT Machine;
	BOOLEAN ImageContainsCode;
	
	union {
		UCHAR ImageFlags;

		struct {
			UCHAR ComPlusNativeReady : 1;
			UCHAR ComPlusILOnly : 1;
			UCHAR ImageDynamicallyRelocated : 1;
			UCHAR ImageMappedFlat : 1;
			UCHAR Reserved : 4;
		};
	};

	ULONG LoaderFlags;
	ULONG ImageFileSize;
	ULONG CheckSum;
} TYPEDEF_TYPE_NAME(SECTION_IMAGE_INFORMATION);

typedef struct _RTL_USER_PROCESS_INFORMATION {
	ULONG Length;
	HANDLE Process;
	HANDLE Thread;
	CLIENT_ID ClientId;
	SECTION_IMAGE_INFORMATION ImageInformation;
} TYPEDEF_TYPE_NAME(RTL_USER_PROCESS_INFORMATION);

typedef enum _LDR_DLL_NOTIFICATION_REASON {
	LDR_DLL_NOTIFICATION_REASON_LOADED		= 1,
	LDR_DLL_NOTIFICATION_REASON_UNLOADED	= 2
} LDR_DLL_NOTIFICATION_REASON;

typedef VOID (NTAPI *PLDR_DLL_NOTIFICATION_FUNCTION)(
	IN	LDR_DLL_NOTIFICATION_REASON	NotificationReason,
	IN	PCLDR_DLL_NOTIFICATION_DATA	NotificationData,
	IN	PVOID						Context);

typedef enum _EVENT_TYPE {
	NotificationEvent,
	SynchronizationEvent
} EVENT_TYPE;

typedef enum _OBJECT_WAIT_TYPE {
	WaitAllObject,
	WaitAnyObject
} TYPEDEF_TYPE_NAME(OBJECT_WAIT_TYPE);

typedef enum _SEMAPHORE_INFORMATION_CLASS {
	SemaphoreBasicInformation
} TYPEDEF_TYPE_NAME(SEMAPHORE_INFORMATION_CLASS);

typedef enum _FILE_INFORMATION_CLASS {
	FileDirectoryInformation                         = 1,
	FileFullDirectoryInformation,                   // 2
	FileBothDirectoryInformation,                   // 3
	FileBasicInformation,                           // 4
	FileStandardInformation,                        // 5
	FileInternalInformation,                        // 6
	FileEaInformation,                              // 7
	FileAccessInformation,                          // 8
	FileNameInformation,                            // 9
	FileRenameInformation,                          // 10
	FileLinkInformation,                            // 11
	FileNamesInformation,                           // 12
	FileDispositionInformation,                     // 13
	FilePositionInformation,                        // 14
	FileFullEaInformation,                          // 15
	FileModeInformation,                            // 16
	FileAlignmentInformation,                       // 17
	FileAllInformation,                             // 18
	FileAllocationInformation,                      // 19
	FileEndOfFileInformation,                       // 20
	FileAlternateNameInformation,                   // 21
	FileStreamInformation,                          // 22
	FilePipeInformation,                            // 23
	FilePipeLocalInformation,                       // 24
	FilePipeRemoteInformation,                      // 25
	FileMailslotQueryInformation,                   // 26
	FileMailslotSetInformation,                     // 27
	FileCompressionInformation,                     // 28
	FileObjectIdInformation,                        // 29
	FileCompletionInformation,                      // 30
	FileMoveClusterInformation,                     // 31
	FileQuotaInformation,                           // 32
	FileReparsePointInformation,                    // 33
	FileNetworkOpenInformation,                     // 34
	FileAttributeTagInformation,                    // 35
	FileTrackingInformation,                        // 36
	FileIdBothDirectoryInformation,                 // 37
	FileIdFullDirectoryInformation,                 // 38
	FileValidDataLengthInformation,                 // 39
	FileShortNameInformation,                       // 40
	FileIoCompletionNotificationInformation,        // 41
	FileIoStatusBlockRangeInformation,              // 42
	FileIoPriorityHintInformation,                  // 43
	FileSfioReserveInformation,                     // 44
	FileSfioVolumeInformation,                      // 45
	FileHardLinkInformation,                        // 46
	FileProcessIdsUsingFileInformation,             // 47
	FileNormalizedNameInformation,                  // 48
	FileNetworkPhysicalNameInformation,             // 49
	FileIdGlobalTxDirectoryInformation,             // 50
	FileIsRemoteDeviceInformation,                  // 51
	FileUnusedInformation,                          // 52
	FileNumaNodeInformation,                        // 53
	FileStandardLinkInformation,                    // 54
	FileRemoteProtocolInformation,                  // 55
	FileMaximumInformation
} TYPEDEF_TYPE_NAME(FILE_INFORMATION_CLASS);

//
// Using this structure (returned by NtQueryInformationFile with the file
// information class of FileProcessIdsUsingFileInformation) we can figure
// out which processes have a file open.
// This is useful for the installer. (Although there is a better, documented
// api for that, the Rm* functions in RstrtMgr.dll) and also it can tell you
// which processes have loaded a particular DLL.
//
typedef struct _FILE_PROCESS_IDS_USING_FILE_INFORMATION {
	ULONG		NumberOfProcessIdsInList;
	ULONG_PTR	ProcessIdList[];
} TYPEDEF_TYPE_NAME(FILE_PROCESS_IDS_USING_FILE_INFORMATION);

typedef struct _FILE_NAMES_INFORMATION {
	ULONG		NextEntryOffset;
	ULONG		FileIndex;
	ULONG		FileNameLength;
	WCHAR		FileName[];
} TYPEDEF_TYPE_NAME(FILE_NAMES_INFORMATION);

typedef struct _FILE_BASIC_INFORMATION {
	LARGE_INTEGER	CreationTime;
	LARGE_INTEGER	LastAccessTime;
	LARGE_INTEGER	LastWriteTime;
	LARGE_INTEGER	ChangeTime;
	ULONG			FileAttributes;
} TYPEDEF_TYPE_NAME(FILE_BASIC_INFORMATION);

typedef struct _FILE_STANDARD_INFORMATION {
	LARGE_INTEGER	AllocationSize;
	LARGE_INTEGER	EndOfFile;
	ULONG			NumberOfLinks;
	BOOLEAN			DeletePending;
	BOOLEAN			Directory;
} TYPEDEF_TYPE_NAME(FILE_STANDARD_INFORMATION);

typedef struct _FILE_POSITION_INFORMATION {
	LARGE_INTEGER	CurrentByteOffset;
} TYPEDEF_TYPE_NAME(FILE_POSITION_INFORMATION);

typedef struct _FILE_NETWORK_OPEN_INFORMATION {
	LARGE_INTEGER	CreationTime;
	LARGE_INTEGER	LastAccessTime;
	LARGE_INTEGER	LastWriteTime;
	LARGE_INTEGER	ChangeTime;
	LARGE_INTEGER	AllocationSize;
	LARGE_INTEGER	EndOfFile;
	ULONG			FileAttributes;
} TYPEDEF_TYPE_NAME(FILE_NETWORK_OPEN_INFORMATION);

typedef struct _FILE_FULL_EA_INFORMATION {
	ULONG			NextEntryOffset;
	UCHAR			Flags;
	UCHAR			EaNameLength;
	USHORT			EaValueLength;
	CHAR			EaName[1];
} TYPEDEF_TYPE_NAME(FILE_FULL_EA_INFORMATION);

typedef struct _SYSTEM_PROCESS_INFORMATION {
	ULONG			NextEntryOffset;
	ULONG			NumberOfThreads;
	LARGE_INTEGER	SpareLi1;
	LARGE_INTEGER	SpareLi2;
	LARGE_INTEGER	SpareLi3;
	LARGE_INTEGER	CreateTime;
	LARGE_INTEGER	UserTime;
	LARGE_INTEGER	KernelTime;
	UNICODE_STRING	ImageName;
	KPRIORITY		BasePriority;
	HANDLE			UniqueProcessId;
	HANDLE			InheritedFromUniqueProcessId;
	ULONG			HandleCount;
	ULONG			SessionId;
	ULONG_PTR		PageDirectoryBase;
	SIZE_T			PeakVirtualSize;
	SIZE_T			VirtualSize;
	ULONG			PageFaultCount;
	SIZE_T			PeakWorkingSetSize;
	SIZE_T			WorkingSetSize;
	SIZE_T			QuotaPeakPagedPoolUsage;
	SIZE_T			QuotaPagedPoolUsage;
	SIZE_T			QuotaPeakNonPagedPoolUsage;
	SIZE_T			QuotaNonPagedPoolUsage;
	SIZE_T			PagefileUsage;
	SIZE_T			PeakPagefileUsage;
	SIZE_T			PrivatePageCount;
	LARGE_INTEGER	ReadOperationCount;
	LARGE_INTEGER	WriteOperationCount;
	LARGE_INTEGER	OtherOperationCount;
	LARGE_INTEGER	ReadTransferCount;
	LARGE_INTEGER	WriteTransferCount;
	LARGE_INTEGER	OtherTransferCount;
} TYPEDEF_TYPE_NAME(SYSTEM_PROCESS_INFORMATION);

typedef struct _SYSTEM_THREAD_INFORMATION {
	LARGE_INTEGER	KernelTime;
	LARGE_INTEGER	UserTime;
	LARGE_INTEGER	CreateTime;
	ULONG			WaitTime;
	PVOID			StartAddress;
	CLIENT_ID		ClientId;
	KPRIORITY		Priority;
	LONG			BasePriority;
	ULONG			ContextSwitches;
	ULONG			ThreadState;
	ULONG			WaitReason;
} TYPEDEF_TYPE_NAME(SYSTEM_THREAD_INFORMATION);

typedef VOID (NTAPI *RTL_VERIFIER_DLL_LOAD_CALLBACK) (
	PWSTR DllName,
	PVOID DllBase,
	SIZE_T DllSize,
	PVOID Reserved
);

typedef VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (
	PWSTR DllName,
	PVOID DllBase,
	SIZE_T DllSize,
	PVOID Reserved
);

typedef VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK) (
	PVOID AllocationBase,
	SIZE_T AllocationSize
);

typedef struct _RTL_VERIFIER_THUNK_DESCRIPTOR {
	PCHAR ThunkName;
	PVOID ThunkOldAddress;
	PVOID ThunkNewAddress;
} TYPEDEF_TYPE_NAME(RTL_VERIFIER_THUNK_DESCRIPTOR);

typedef struct _RTL_VERIFIER_DLL_DESCRIPTOR {
	PWCHAR DllName;
	DWORD DllFlags;
	PVOID DllAddress;
	PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
} TYPEDEF_TYPE_NAME(RTL_VERIFIER_DLL_DESCRIPTOR);

typedef struct _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
	// Filled by verifier provider DLL
	DWORD Length;        
	PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
	RTL_VERIFIER_DLL_LOAD_CALLBACK ProviderDllLoadCallback;
	RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
    
	// Filled by verifier engine
    PWSTR VerifierImage;
	DWORD VerifierFlags;
	DWORD VerifierDebug;
    
	PVOID RtlpGetStackTraceAddress;
	PVOID RtlpDebugPageHeapCreate;
	PVOID RtlpDebugPageHeapDestroy;

	// Filled by verifier provider DLL 
	RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK ProviderNtdllHeapFreeCallback;
} TYPEDEF_TYPE_NAME(RTL_VERIFIER_PROVIDER_DESCRIPTOR);

typedef enum _KEY_INFORMATION_CLASS {
	KeyBasicInformation,
	KeyNodeInformation,
	KeyFullInformation,
	KeyNameInformation,
	KeyCachedInformation,
	KeyFlagsInformation,
	KeyVirtualizationInformation,
	KeyHandleTagsInformation,			// ULONG
	MaxKeyInfoClass
} KEY_INFORMATION_CLASS;

typedef enum _KEY_VALUE_INFORMATION_CLASS {
	KeyValueBasicInformation,
	KeyValueFullInformation,
	KeyValuePartialInformation,
	KeyValueFullInformationAlign64,
	KeyValuePartialInformationAlign64,
	KeyValueLayerInformation,
	MaxKeyValueInfoClass
} KEY_VALUE_INFORMATION_CLASS;

typedef enum _KEY_SET_INFORMATION_CLASS {
	KeyWriteTimeInformation,
	KeyWow64FlagsInformation,
	KeyControlFlagsInformation,
	KeySetVirtualizationInformation,
	KeySetDebugInformation,
	KeySetHandleTagsInformation,
	KeySetLayerInformation,
	MaxKeySetInfoClass
} KEY_SET_INFORMATION_CLASS;

// for KeyControlFlagsInformation
#define REG_KEY_DONT_VIRTUALIZE		2
#define REG_KEY_DONT_SILENT_FAIL	4
#define REG_KEY_RECURSE_FLAG		8

typedef struct _KEY_BASIC_INFORMATION {
	LARGE_INTEGER	LastWriteTime;
	ULONG			TitleIndex;
	ULONG			NameLength;
	WCHAR			Name[1];
} TYPEDEF_TYPE_NAME(KEY_BASIC_INFORMATION);

typedef struct _KEY_NODE_INFORMATION {
	LARGE_INTEGER	LastWriteTime;
	ULONG			TitleIndex;
	ULONG			ClassOffset;
	ULONG			ClassLength;
	ULONG			NameLength;
	WCHAR			Name[1];
} TYPEDEF_TYPE_NAME(KEY_NODE_INFORMATION);

typedef struct _KEY_FULL_INFORMATION {
	LARGE_INTEGER	LastWriteTime;
	ULONG			TitleIndex;
	ULONG			ClassOffset;
	ULONG			ClassLength;
	ULONG			SubKeys;
	ULONG			MaxNameLen;
	ULONG			MaxClassLen;
	ULONG			Values;
	ULONG			MaxValueNameLen;
	ULONG			MaxValueDataLen;
	WCHAR			Class[];
} TYPEDEF_TYPE_NAME(KEY_FULL_INFORMATION);

typedef struct _KEY_NAME_INFORMATION {
	ULONG			NameLength;
	WCHAR			Name[];
} TYPEDEF_TYPE_NAME(KEY_NAME_INFORMATION);

typedef struct _KEY_CACHED_INFORMATION {
	LARGE_INTEGER	LastWriteTime;
	ULONG			TitleIndex;
	ULONG			SubKeys;
	ULONG			MaxNameLen;
	ULONG			Values;
	ULONG			MaxValueNameLen;
	ULONG			MaxValueDataLen;
	ULONG			NameLength;
} TYPEDEF_TYPE_NAME(KEY_CACHED_INFORMATION);

typedef struct _KEY_VALUE_BASIC_INFORMATION {
	ULONG			TitleIndex;
	ULONG			Type;
	ULONG			NameLength;
	WCHAR			Name[];
} TYPEDEF_TYPE_NAME(KEY_VALUE_BASIC_INFORMATION);

typedef struct _KEY_VALUE_FULL_INFORMATION {
	ULONG			TitleIndex;
	ULONG			Type;
	ULONG			DataOffset;
	ULONG			DataLength;
	ULONG			NameLength;
	WCHAR			NameAndData[];
} TYPEDEF_TYPE_NAME(KEY_VALUE_FULL_INFORMATION);

typedef struct _KEY_VALUE_PARTIAL_INFORMATION {
	ULONG			TitleIndex;
	ULONG			Type;
	ULONG			DataLength;
	UCHAR			Data[];
} TYPEDEF_TYPE_NAME(KEY_VALUE_PARTIAL_INFORMATION);

typedef struct _KEY_VALUE_ENTRY {
	PUNICODE_STRING	ValueName;
	ULONG			DataLength;
	ULONG			DataOffset;
	ULONG			Type;
} TYPEDEF_TYPE_NAME(KEY_VALUE_ENTRY);

typedef enum _RTL_QUERY_REGISTRY_RELATIVE_TO {
	RTL_REGISTRY_ABSOLUTE,				// Path is a full path
	RTL_REGISTRY_SERVICES,				// \Registry\Machine\System\CurrentControlSet\Services
	RTL_REGISTRY_CONTROL,				// \Registry\Machine\System\CurrentControlSet\Control
	RTL_REGISTRY_WINDOWS_NT,			// \Registry\Machine\Software\Microsoft\Windows NT\CurrentVersion
	RTL_REGISTRY_DEVICEMAP,				// \Registry\Machine\Hardware\DeviceMap
	RTL_REGISTRY_USER,					// \Registry\User\CurrentUser
	RTL_REGISTRY_MAXIMUM,

	RTL_REGISTRY_HANDLE = 0x40000000,	// Low order bits are registry handle
	RTL_REGISTRY_OPTIONAL = 0x80000000	// Indicates the key node is optional
} RTL_QUERY_REGISTRY_RELATIVE_TO;

typedef NTSTATUS (NTAPI *PRTL_QUERY_REGISTRY_ROUTINE)(
	IN PWSTR ValueName,
	IN ULONG ValueType,
	IN PVOID ValueData,
	IN ULONG ValueLength,
	IN PVOID Context,
	IN PVOID EntryContext);

typedef struct _RTL_QUERY_REGISTRY_TABLE {
	PRTL_QUERY_REGISTRY_ROUTINE QueryRoutine;
	ULONG Flags;
	PWSTR Name;
	PVOID EntryContext;
	ULONG DefaultType;
	PVOID DefaultData;
	ULONG DefaultLength;
} TYPEDEF_TYPE_NAME(RTL_QUERY_REGISTRY_TABLE);

typedef enum _RTL_PATH_TYPE {
	RtlPathTypeUnknown,
	RtlPathTypeUncAbsolute,
	RtlPathTypeDriveAbsolute,
	RtlPathTypeDriveRelative,
	RtlPathTypeRooted,
	RtlPathTypeRelative,
	RtlPathTypeLocalDevice,
	RtlPathTypeRootLocalDevice
} RTL_PATH_TYPE;

typedef struct _RTL_DYNAMIC_HASH_TABLE_ENTRY {
	LIST_ENTRY	Linkage;
	ULONG_PTR	Signature;
} TYPEDEF_TYPE_NAME(RTL_DYNAMIC_HASH_TABLE_ENTRY);

typedef struct _RTL_DYNAMIC_HASH_TABLE_CONTEXT {
	PLIST_ENTRY	ChainHead;
	PLIST_ENTRY	PrevLinkage;
	ULONG_PTR	Signature;
} TYPEDEF_TYPE_NAME(RTL_DYNAMIC_HASH_TABLE_CONTEXT);

typedef struct _RTL_DYNAMIC_HASH_TABLE_ENUMERATOR {
	RTL_DYNAMIC_HASH_TABLE_ENTRY	HashEntry;
	PLIST_ENTRY						ChainHead;
	ULONG							BucketIndex;
} TYPEDEF_TYPE_NAME(RTL_DYNAMIC_HASH_TABLE_ENUMERATOR);

typedef struct _RTL_DYNAMIC_HASH_TABLE {
	ULONG	Flags;
	ULONG	Shift;

	ULONG	TableSize;
	ULONG	Pivot;
	ULONG	DivisorMask;

	ULONG	NumEntries;
	ULONG	NonEmptyBuckets;
	ULONG	NumEnumerators;

	PVOID	Directory;
} TYPEDEF_TYPE_NAME(RTL_DYNAMIC_HASH_TABLE);

typedef enum _SECTION_INHERIT {
	ViewShare = 1,
	ViewUnmap = 2
} SECTION_INHERIT;

typedef enum _SECTION_INFORMATION_CLASS {
	SectionBasicInformation,
	SectionImageInformation,
	SectionRelocationInformation,
	MaxSectionInfoClass
} SECTION_INFORMATION_CLASS;

typedef VOID (*PKNORMAL_ROUTINE) (
	IN PVOID NormalContext,
	IN PVOID SystemArgument1,
	IN PVOID SystemArgument2);

typedef enum _OBJECT_INFORMATION_CLASS {
	ObjectBasicInformation,				// OBJECT_BASIC_INFORMATION
	ObjectNameInformation,				// UNICODE_STRING
	ObjectTypeInformation,				// OBJECT_TYPE_INFORMATION
	ObjectTypesInformation,				// ULONG (NumberOfTypes)
	ObjectHandleFlagInformation,		// OBJECT_HANDLE_FLAG_INFORMATION
	ObjectSessionInformation,			// none, set only, and requires SeTcbPrivilege
	MaxObjectInfoClass
} OBJECT_INFORMATION_CLASS;

typedef struct _OBJECT_BASIC_INFORMATION {
	ULONG			Attributes;
	ACCESS_MASK		GrantedAccess;
	ULONG			HandleCount;
	ULONG			PointerCount;
	ULONG			PagedPoolCharge;
	ULONG			NonPagedPoolCharge;
	ULONG			Reserved[3];
	ULONG			NameInfoSize;
	ULONG			TypeInfoSize;
	ULONG			SecurityDescriptorSize;
	LARGE_INTEGER	CreationTime;
} TYPEDEF_TYPE_NAME(OBJECT_BASIC_INFORMATION);

typedef struct _OBJECT_TYPE_INFORMATION {
	UNICODE_STRING	TypeName;
	ULONG			TotalNumberOfObjects;
	ULONG			TotalNumberOfHandles;
	ULONG			TotalPagedPoolUsage;
	ULONG			TotalNonPagedPoolUsage;
	ULONG			TotalNamePoolUsage;
	ULONG			TotalHandleTableUsage;
	ULONG			HighWaterNumberOfObjects;
	ULONG			HighWaterNumberOfHandles;
	ULONG			HighWaterPagedPoolUsage;
	ULONG			HighWaterNonPagedPoolUsage;
	ULONG			HighWaterNamePoolUsage;
	ULONG			HighWaterHandleTableUsage;
	ULONG			InvalidAttributes;
	GENERIC_MAPPING	GenericMapping;
	ULONG			ValidAccessMask;
	BOOLEAN			SecurityRequired;
	BOOLEAN			MaintainHandleCount;
	ULONG			PoolType;
	ULONG			DefaultPagedPoolCharge;
	ULONG			DefaultNonPagedPoolCharge;
} TYPEDEF_TYPE_NAME(OBJECT_TYPE_INFORMATION);

typedef struct _OBJECT_HANDLE_FLAG_INFORMATION {
	BOOLEAN			Inherit;
	BOOLEAN			ProtectFromClose;
} TYPEDEF_TYPE_NAME(OBJECT_HANDLE_FLAG_INFORMATION);

// Not the real structure, but same size
typedef struct _HEAP_ENTRY {
	PVOID			Data1;
	PVOID			Data2;
} TYPEDEF_TYPE_NAME(HEAP_ENTRY);

typedef struct _HEAP *PHEAP;

// This structure is not complete.
typedef struct _HEAP {
	HEAP_ENTRY		Entry;
	ULONG			SegmentSignature;
	ULONG			SegmentFlags;
	LIST_ENTRY		SegmentListEntry;
	PHEAP			Heap;
	PVOID			BaseAddress;
	ULONG			NumberOfPages;
	PHEAP_ENTRY		FirstEntry;
	PHEAP_ENTRY		LastValidEntry;
	ULONG			NumberOfUnCommittedPages;
	ULONG			NumberOfUnCommittedRanges;
	USHORT			SegmentAllocatorBackTraceIndex;
	USHORT			Reserved;
	LIST_ENTRY		UCRSegmentList;
	ULONG			Flags;
	ULONG			ForceFlags;
	ULONG			CompatibilityFlags;
} TYPEDEF_TYPE_NAME(HEAP);

typedef BOOLEAN (NTAPI *PDLL_INIT_ROUTINE) (
	IN	PVOID	DllHandle,
	IN	ULONG	Reason,
	IN	PVOID	Context OPTIONAL);

typedef VOID (NTAPI *PLDR_LOADED_MODULE_ENUMERATION_CALLBACK_FUNCTION) (
	IN		PCLDR_DATA_TABLE_ENTRY	DataTableEntry,
	IN		PVOID					Context,
	IN OUT	PBOOLEAN				StopEnumeration);

typedef NTSTATUS (NTAPI *PUSER_THREAD_START_ROUTINE)(
	IN		PVOID	ThreadParameter);

typedef struct _TIME_FIELDS {
	SHORT	Year;			// range [1601...]
	SHORT	Month;			// range [1..12]
	SHORT	Day;			// range [1..31]
	SHORT	Hour;			// range [0..23]
	SHORT	Minute;			// range [0..59]
	SHORT	Second;			// range [0..59]
	SHORT	Milliseconds;	// range [0..999]
	SHORT	Weekday;		// range [0..6] == [Sunday..Saturday]
} TYPEDEF_TYPE_NAME(TIME_FIELDS);

typedef struct _KERNEL_USER_TIMES {
	LONGLONG	CreateTime;
	LONGLONG	ExitTime;
	LONGLONG	KernelTime;
	LONGLONG	UserTime;
} TYPEDEF_TYPE_NAME(KERNEL_USER_TIMES);

typedef struct _POOLED_USAGE_AND_LIMITS {
	SIZE_T	PeakPagedPoolUsage;
	SIZE_T	PagedPoolUsage;
	SIZE_T	PagedPoolLimit;
	SIZE_T	PeakNonPagedPoolUsage;
	SIZE_T	NonPagedPoolUsage;
	SIZE_T	NonPagedPoolLimit;
	SIZE_T	PeakPagefileUsage;
	SIZE_T	PagefileUsage;
	SIZE_T	PagefileLimit;
} TYPEDEF_TYPE_NAME(POOLED_USAGE_AND_LIMITS);

typedef enum _IO_PRIORITY_HINT {
	IoPriorityVeryLow,
	IoPriorityLow,
	IoPriorityNormal,
	IoPriorityHigh,
	IoPriorityCritical,
	MaxIoPriorityTypes
} IO_PRIORITY_HINT;

typedef struct _VM_COUNTERS {
	SIZE_T	PeakVirtualSize;
	SIZE_T	VirtualSize;
	ULONG	PageFaultCount;
	SIZE_T	PeakWorkingSetSize;
	SIZE_T	WorkingSetSize;
	SIZE_T	QuotaPeakPagedPoolUsage;
	SIZE_T	QuotaPagedPoolUsage;
	SIZE_T	QuotaPeakNonPagedPoolUsage;
	SIZE_T	QuotaNonPagedPoolUsage;
	SIZE_T	PagefileUsage;
	SIZE_T	PeakPagefileUsage;
} TYPEDEF_TYPE_NAME(VM_COUNTERS);

typedef struct _VM_COUNTERS_EX {
	SIZE_T	PeakVirtualSize;
	SIZE_T	VirtualSize;
	ULONG	PageFaultCount;
	SIZE_T	PeakWorkingSetSize;
	SIZE_T	WorkingSetSize;
	SIZE_T	QuotaPeakPagedPoolUsage;
	SIZE_T	QuotaPagedPoolUsage;
	SIZE_T	QuotaPeakNonPagedPoolUsage;
	SIZE_T	QuotaNonPagedPoolUsage;
	SIZE_T	PagefileUsage;
	SIZE_T	PeakPagefileUsage;
	SIZE_T	PrivateUsage;
} TYPEDEF_TYPE_NAME(VM_COUNTERS_EX);

typedef struct _PROCESS_ACCESS_TOKEN {
    HANDLE Token;
    HANDLE Thread;
} TYPEDEF_TYPE_NAME(PROCESS_ACCESS_TOKEN);

typedef struct _PROCESS_LDT_INFORMATION {
    ULONG Start;
    ULONG Length;
    LDT_ENTRY LdtEntries[1];
} TYPEDEF_TYPE_NAME(PROCESS_LDT_INFORMATION);

typedef struct _PROCESS_PRIORITY_CLASS {
	BOOLEAN	Foreground;
	UCHAR	PriorityClass; // PROCESS_PRIORITY_CLASS_*
} TYPEDEF_TYPE_NAME(PROCESS_PRIORITY_CLASS);

typedef struct _PROCESS_HANDLE_INFORMATION {
	ULONG	HandleCount;
	ULONG	HighWaterHandleCount;
} TYPEDEF_TYPE_NAME(PROCESS_HANDLE_INFORMATION);

typedef struct _PROCESS_DEVICEMAP_INFORMATION_EX {
	union {
		struct {
			HANDLE DirectoryHandle;
		} Set;

		struct {
			ULONG DriveMap;
			UCHAR DriveType[32];
		} Query;
	};

	ULONG Flags;
} TYPEDEF_TYPE_NAME(PROCESS_DEVICEMAP_INFORMATION_EX);

typedef struct _PROCESS_INSTRUMENTATION_CALLBACK_INFORMATION {
	ULONG	Version;
	ULONG	Reserved;
	PVOID	Callback;
} TYPEDEF_TYPE_NAME(PROCESS_INSTRUMENTATION_CALLBACK_INFORMATION);

typedef struct _RTL_MEMORY_ZONE_SEGMENT {
	struct _RTL_MEMORY_ZONE_SEGMENT	*NextSegment;
	SIZE_T							Size;
	PVOID							Next;
	PVOID							Limit;
} TYPEDEF_TYPE_NAME(RTL_MEMORY_ZONE_SEGMENT);

typedef struct _RTL_MEMORY_ZONE {
	RTL_MEMORY_ZONE_SEGMENT		Segment;
	RTL_SRWLOCK					Lock;
	ULONG						LockCount;
	PRTL_MEMORY_ZONE_SEGMENT	FirstSegment;
} TYPEDEF_TYPE_NAME(RTL_MEMORY_ZONE);

typedef struct _IMAGE_DELAYLOAD_DESCRIPTOR {
	union {
		DWORD AllAttributes;

		struct {
			ULONG RvaBased : 1;				// Delay load version 2
			ULONG ReservedAttributes : 31;
		};
	} Attributes;

	ULONG DllNameRVA;						// RVA to the name of the target library (NULL-terminate ASCII string)
	ULONG ModuleHandleRVA;					// RVA to the HMODULE caching location (PHMODULE)
	ULONG ImportAddressTableRVA;			// RVA to the start of the IAT (PIMAGE_THUNK_DATA)
	ULONG ImportNameTableRVA;				// RVA to the start of the name table (PIMAGE_THUNK_DATA::AddressOfData)
	ULONG BoundImportAddressTableRVA;		// RVA to an optional bound IAT
	ULONG UnloadInformationTableRVA;		// RVA to an optional unload info table
	ULONG TimeDateStamp;					// 0 if not bound,
											// Otherwise, date/time of the target DLL

} TYPEDEF_TYPE_NAME(IMAGE_DELAYLOAD_DESCRIPTOR);

typedef struct _DELAYLOAD_PROC_DESCRIPTOR {
	ULONG		ImportDescribedByName;

	union {
		PCSTR	Name;
		ULONG	Ordinal;
	} Description;
} TYPEDEF_TYPE_NAME(DELAYLOAD_PROC_DESCRIPTOR);

typedef struct _DELAYLOAD_INFO {
	ULONG							Size;
	PCIMAGE_DELAYLOAD_DESCRIPTOR	DelayloadDescriptor;
	PIMAGE_THUNK_DATA				ThunkAddress;
	PCSTR							TargetDllName;
	DELAYLOAD_PROC_DESCRIPTOR		TargetApiDescriptor;
	PVOID							TargetModuleBase;
	PVOID							Unused;
	ULONG							LastError;
} TYPEDEF_TYPE_NAME(DELAYLOAD_INFO);

#define DELAYLOAD_GPA_FAILURE 4

typedef PVOID (NTAPI *PDELAYLOAD_FAILURE_DLL_CALLBACK) (
    IN	ULONG			NotificationReason,	// only value is DELAYLOAD_GPA_FAILURE -
    IN	PDELAYLOAD_INFO	DelayloadInfo);		// see delayimp.h for origin reason

typedef PVOID (NTAPI *PDELAYLOAD_FAILURE_SYSTEM_ROUTINE) (
	IN	PCSTR	DllName,
	IN	PCSTR	ProcedureName);

typedef enum _VIRTUAL_MEMORY_INFORMATION_CLASS {
	VmPrefetchInformation,
	VmPagePriorityInformation,
	VmCfgCallTargetInformation,
	VmMaxInformationClass
} TYPEDEF_TYPE_NAME(VIRTUAL_MEMORY_INFORMATION_CLASS);

typedef struct _RTL_BITMAP {
	ULONG	SizeOfBitMap;
	PULONG	Buffer;
} TYPEDEF_TYPE_NAME(RTL_BITMAP);

#pragma endregion

STATIC PKUSER_SHARED_DATA SharedUserData = (PKUSER_SHARED_DATA) 0x7FFE0000;

#pragma region Nt* function declarations

NTSYSCALLAPI NTSTATUS NTAPI NtQueryObject(
	IN		HANDLE						ObjectHandle,
	IN		OBJECT_INFORMATION_CLASS	ObjectInformationClass,
	OUT		PVOID						ObjectInformation,
	IN		ULONG						Length,
	OUT		PULONG						ReturnLength OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtFlushInstructionCache(
	IN	HANDLE			ProcessHandle,
	IN	PVOID			BaseAddress OPTIONAL,
	IN	SIZE_T			Length);

NTSYSCALLAPI NTSTATUS NTAPI NtQuerySystemInformation(
	IN	SYSINFOCLASS	SystemInformationClass,
	OUT	PVOID			SystemInformation,
	IN	ULONG			SystemInformationLength,
	OUT	PULONG			ReturnLength OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtQuerySystemInformationEx(
	IN	SYSINFOCLASS	SystemInformationClass,
	IN	PVOID			InputBuffer,
	IN	ULONG			InputBufferLength,
	OUT	PVOID			SystemInformation,
	IN	ULONG			SystemInformationLength,
	OUT	PULONG			ReturnLength);

NTSYSCALLAPI NTSTATUS NTAPI NtSetInformationFile(
	IN	HANDLE					FileHandle,
	OUT	PIO_STATUS_BLOCK		IoStatusBlock,
	IN	PVOID					FileInformation,
	IN	ULONG					FileInformationLength,
	IN	FILE_INFORMATION_CLASS	FileInformationClass);

// Handle must be opened with at least FILE_READ_ATTRIBUTES access
NTSYSCALLAPI NTSTATUS NTAPI NtQueryInformationFile(
	IN	HANDLE					FileHandle,
	OUT	PIO_STATUS_BLOCK		IoStatusBlock,
	OUT	PVOID					FileInformation,
	IN	ULONG					FileInformationLength,
	IN	FILE_INFORMATION_CLASS	FileInformationClass);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryInformationProcess(
	IN	HANDLE				ProcessHandle,
	IN	PROCESSINFOCLASS	ProcessInformationClass,
	OUT	PVOID				ProcessInformation,
	IN	ULONG				ProcessInformationLength,
	OUT	PULONG				ReturnLength OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtSetInformationProcess(
	IN	HANDLE				ProcessHandle,
	IN	PROCESSINFOCLASS	ProcessInformationClass,
	IN	PVOID				ProcessInformation,
	IN	ULONG				ProcessInformationLength);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryInformationThread(
	IN	HANDLE				ThreadHandle,
	IN	THREADINFOCLASS		ThreadInformationClass,
	OUT	PVOID				ThreadInformation,
	IN	ULONG				ThreadInformationLength,
	OUT	PULONG				ReturnLength OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtSetInformationThread(
	IN	HANDLE				ThreadHandle,
	IN	THREADINFOCLASS		ThreadInformationClass,
	IN	PVOID				ThreadInformation,
	IN	ULONG				ThreadInformationLength);

// NtGetNextProcess and NtGetNextThread do not accept any Flags.
// Flags parameters must be set to 0.
NTSYSCALLAPI NTSTATUS NTAPI NtGetNextProcess(
	IN	HANDLE		ProcessHandle,
	IN	ACCESS_MASK	DesiredAccess,
	IN	ULONG		HandleAttributes,
	IN	ULONG		Flags OPTIONAL,
	OUT	PHANDLE		NextProcessHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtGetNextThread(
	IN	HANDLE		ProcessHandle,
	IN	HANDLE		ThreadHandle,
	IN	ACCESS_MASK	DesiredAccess,
	IN	ULONG		HandleAttributes,
	IN	ULONG		Flags,
	OUT	PHANDLE		NextThreadHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtSuspendProcess(
	IN	HANDLE	ProcessHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtResumeProcess(
	IN	HANDLE	ProcessHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtSuspendThread(
	IN	HANDLE	ThreadHandle,
	OUT	PULONG	PreviousSuspendCount OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtResumeThread(
	IN	HANDLE	ThreadHandle,
	IN	PULONG	PreviousSuspendCount OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenProcess(
	OUT		PHANDLE						ProcessHandle,
	IN		ACCESS_MASK					DesiredAccess,
	IN		POBJECT_ATTRIBUTES			ObjectAttributes,
	IN		PCLIENT_ID					ClientId OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtTerminateProcess(
	IN	HANDLE		ProcessHandle OPTIONAL,
	IN	NTSTATUS	ExitStatus);

NTSYSCALLAPI NTSTATUS NTAPI NtWaitForSingleObject(
	IN	HANDLE			Handle,
	IN	BOOLEAN			Alertable,
	IN	PLARGE_INTEGER	Timeout);

NTSYSCALLAPI NTSTATUS NTAPI NtWaitForMultipleObjects(
	IN	ULONG				ObjectCount,
	IN	PHANDLE				ObjectArray,
	IN	OBJECT_WAIT_TYPE	WaitType,
	IN	BOOLEAN				Alertable,
	IN	PLONGLONG			Timeout OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtSignalAndWaitForSingleObject(
	IN	HANDLE			SignalHandle,
	IN	HANDLE			WaitHandle,
	IN	BOOLEAN			Alertable,
	IN	PLARGE_INTEGER	Timeout);

NTSYSCALLAPI NTSTATUS NTAPI NtClose(
	IN	HANDLE	Handle);

NTSYSCALLAPI NTSTATUS NTAPI NtRaiseHardError(
	IN	NTSTATUS	ErrorStatus,
	IN	ULONG		NumberOfParameters,
	IN	ULONG		UnicodeStringParameterMask,
	IN	PULONG_PTR	Parameters,
	IN	ULONG		ValidResponseOptions,
	OUT	PULONG		Response);

NTSYSCALLAPI NTSTATUS NTAPI NtAllocateVirtualMemory(
	IN		HANDLE		ProcessHandle,
	IN OUT	PVOID		*BaseAddress,
	IN		ULONG_PTR	ZeroBits,
	IN OUT	PSIZE_T		RegionSize,
	IN		ULONG		AllocationType,
	IN		ULONG		Protect);

NTSYSCALLAPI NTSTATUS NTAPI NtFreeVirtualMemory(
	IN		HANDLE		ProcessHandle,
	IN OUT	PVOID		*BaseAddress,
	IN OUT	PSIZE_T		RegionSize,
	IN		ULONG		FreeType);

NTSYSCALLAPI NTSTATUS NTAPI NtUnmapViewOfSection(
	IN		HANDLE		ProcessHandle,
	IN		PVOID		BaseAddress OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryVirtualMemory(
	IN		HANDLE			ProcessHandle,
	IN		PVOID			BaseAddress OPTIONAL,
	IN		MEMINFOCLASS	MemoryInformationClass,
	OUT		PVOID			MemoryInformation,
	IN		SIZE_T			MemoryInformationLength,
	OUT		PSIZE_T			ReturnLength OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtProtectVirtualMemory(
	IN		HANDLE		ProcessHandle,
	IN OUT	PPVOID		BaseAddress,
	IN OUT	PSIZE_T		RegionSize,
	IN		ULONG		NewProtect,
	OUT		PULONG		OldProtect);

NTSYSCALLAPI NTSTATUS NTAPI NtReadVirtualMemory(
	IN		HANDLE		ProcessHandle,
	IN		PVOID		BaseAddress,
	OUT		PVOID		Buffer,
	IN		SIZE_T		BufferSize,
	OUT		PSIZE_T		NumberOfBytesRead OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtWriteVirtualMemory(
	IN		HANDLE		ProcessHandle,
	IN		PVOID		BaseAddress,
	IN		PCVOID		Buffer,
	IN		SIZE_T		BufferSize,
	OUT		PSIZE_T		NumberOfBytesWritten OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtFlushVirtualMemory(
	IN		HANDLE				ProcessHandle,
	IN OUT	PPVOID				BaseAddress,
	IN OUT	PSIZE_T				RegionSize,
	OUT		PIO_STATUS_BLOCK	IoStatusBlock);

// Please note: The DefaultTimeout parameter is marked as optional
// in some NT5 source code, but it appears to be REQUIRED in most
// cases. If you are getting STATUS_INVALID_PARAMETER from this
// system call, pass DefaultTimeout and it will usually fix the
// problem.
NTSYSCALLAPI NTSTATUS NTAPI NtCreateNamedPipeFile(
	OUT		PHANDLE				FileHandle,
	IN		ULONG				DesiredAccess,
	IN		POBJECT_ATTRIBUTES	ObjectAttributes,
	OUT		PIO_STATUS_BLOCK	IoStatusBlock,
	IN		ULONG				ShareAccess,
	IN		ULONG				CreateDisposition,
	IN		ULONG				CreateOptions,
	IN		ULONG				NamedPipeType,
	IN		ULONG				ReadMode,
	IN		ULONG				CompletionMode,
	IN		ULONG				MaximumInstances,
	IN		ULONG				InboundQuota,
	IN		ULONG				OutboundQuota,
	IN		PLONGLONG			DefaultTimeout OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtCreateEvent(
	OUT		PHANDLE				EventHandle,
	IN		ACCESS_MASK			DesiredAccess,
	IN		POBJECT_ATTRIBUTES	ObjectAttributes OPTIONAL,
	IN		EVENT_TYPE			EventType,
	IN		BOOLEAN				InitialState);

NTSYSCALLAPI NTSTATUS NTAPI NtSetEvent(
	IN		HANDLE				EventHandle,
	OUT		PLONG				PreviousState OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtCreateSemaphore(
	OUT		PHANDLE				SemaphoreHandle,
	IN		ACCESS_MASK			DesiredAccess,
	IN		POBJECT_ATTRIBUTES	ObjectAttributes OPTIONAL,
	IN		LONG				InitialCount,
	IN		LONG				MaximumCount);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenSemaphore(
	OUT		PHANDLE				SemaphoreHandle,
	IN		ACCESS_MASK			DesiredAccess,
	IN		POBJECT_ATTRIBUTES	ObjectAttributes);

NTSYSCALLAPI NTSTATUS NTAPI NtQuerySemaphore(
	IN		HANDLE						SemaphoreHandle,
	IN		SEMAPHORE_INFORMATION_CLASS	SemaphoreInformationClass,
	OUT		PVOID						SemaphoreInformation,
	IN		ULONG						SemaphoreInformationLength,
	OUT		PULONG						ReturnLength OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtReleaseSemaphore(
	IN		HANDLE						SemaphoreHandle,
	IN		LONG						ReleaseCount,
	OUT		PLONG						PreviousCount OPTIONAL);

typedef VOID (NTAPI *PIO_APC_ROUTINE) (
	IN		PVOID				ApcContext,
	IN		PIO_STATUS_BLOCK	IoStatusBlock,
	IN		ULONG				Reserved);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenFile(
	OUT		PHANDLE				FileHandle,
	IN		ACCESS_MASK			DesiredAccess,
	IN		POBJECT_ATTRIBUTES	ObjectAttributes,
	OUT		PIO_STATUS_BLOCK	IoStatusBlock,
	IN		ULONG				ShareAccess,
	IN		ULONG				OpenOptions);

NTSYSCALLAPI NTSTATUS NTAPI NtCreateFile(
	OUT		PHANDLE				FileHandle,
	IN		ACCESS_MASK			DesiredAccess,
	IN		POBJECT_ATTRIBUTES	ObjectAttributes,
	OUT		PIO_STATUS_BLOCK	IoStatusBlock,
	IN		PLONGLONG			AllocationSize OPTIONAL,
	IN		ULONG				FileAttributes,
	IN		ULONG				ShareAccess,
	IN		ULONG				CreateDisposition,
	IN		ULONG				CreateOptions,
	IN		PVOID				EaBuffer,
	IN		ULONG				EaLength);

NTSYSCALLAPI NTSTATUS NTAPI NtReadFile(
	IN		HANDLE				FileHandle,
	IN		HANDLE				Event OPTIONAL,
	IN		PIO_APC_ROUTINE		ApcRoutine OPTIONAL,
	IN		PVOID				ApcContext OPTIONAL,
	OUT		PIO_STATUS_BLOCK	IoStatusBlock,
	OUT		PVOID				Buffer,
	IN		ULONG				Length,
	IN		PLONGLONG			ByteOffset OPTIONAL,
	IN		PULONG				Key OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtWriteFile(
	IN		HANDLE				FileHandle,
	IN		HANDLE				Event OPTIONAL,
	IN		PIO_APC_ROUTINE		ApcRoutine OPTIONAL,
	IN		PVOID				ApcContext OPTIONAL,
	OUT		PIO_STATUS_BLOCK	IoStatusBlock,
	IN		PVOID				Buffer,
	IN		ULONG				Length,
	IN		PLONGLONG			ByteOffset OPTIONAL,
	IN		PULONG				Key OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtFsControlFile(
	IN		HANDLE				FileHandle,
	IN		HANDLE				Event OPTIONAL,
	IN		PIO_APC_ROUTINE		ApcRoutine OPTIONAL,
	IN		PVOID				ApcContext OPTIONAL,
	OUT		PIO_STATUS_BLOCK	IoStatusBlock,
	IN		ULONG				FsControlCode,
	IN		PVOID				InputBuffer OPTIONAL,
	IN		ULONG				InputBufferLength,
	OUT		PVOID				OutputBuffer OPTIONAL,
	IN		ULONG				OutputBufferLength);

NTSYSCALLAPI NTSTATUS NTAPI NtDeviceIoControlFile(
	IN		HANDLE				FileHandle,
	IN		HANDLE				Event OPTIONAL,
	IN		PIO_APC_ROUTINE		ApcRoutine OPTIONAL,
	IN		PVOID				ApcContext OPTIONAL,
	OUT		PIO_STATUS_BLOCK	IoStatusBlock,
	IN		ULONG				IoControlCode,
	IN		PVOID				InputBuffer OPTIONAL,
	IN		ULONG				InputBufferLength,
	OUT		PVOID				OutputBuffer OPTIONAL,
	IN		ULONG				OutputBufferLength);

NTSYSCALLAPI NTSTATUS NTAPI NtAlpcCreatePort(
    OUT		PHANDLE					PortHandle,
    IN		POBJECT_ATTRIBUTES		ObjectAttributes OPTIONAL,
    IN		PALPC_PORT_ATTRIBUTES	PortAttributes OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtAlpcSendWaitReceivePort(
    IN		HANDLE						PortHandle,
    IN		ULONG						Flags,
    IN		PPORT_MESSAGE				SendMessage OPTIONAL,
    IN OUT	PALPC_MESSAGE_ATTRIBUTES	SendMessageAttributes OPTIONAL,
    OUT		PPORT_MESSAGE				ReceiveMessage OPTIONAL,
    IN OUT	PSIZE_T						BufferLength OPTIONAL,
    IN OUT	PALPC_MESSAGE_ATTRIBUTES	ReceiveMessageAttributes OPTIONAL,
    IN		PLARGE_INTEGER				Timeout OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtAlpcAcceptConnectPort(
    OUT		PHANDLE						PortHandle,
    IN		HANDLE						ConnectionPortHandle,
    IN		ULONG						Flags,
    IN		POBJECT_ATTRIBUTES			ObjectAttributes OPTIONAL,
    IN		PALPC_PORT_ATTRIBUTES		PortAttributes OPTIONAL,
    IN		PVOID						PortContext OPTIONAL,
    IN		PPORT_MESSAGE				ConnectionRequest,
    IN OUT	PALPC_MESSAGE_ATTRIBUTES	ConnectionMessageAttributes OPTIONAL,
    IN		BOOLEAN						AcceptConnection);

NTSYSCALLAPI NTSTATUS NTAPI NtAlpcConnectPort(
    OUT		PHANDLE						PortHandle,
    IN		PUNICODE_STRING				PortName,
    IN		POBJECT_ATTRIBUTES			ObjectAttributes OPTIONAL,
    IN		PALPC_PORT_ATTRIBUTES		PortAttributes OPTIONAL,
    IN		ULONG						Flags,
    IN		PSID						RequiredServerSid OPTIONAL,
    IN OUT	PPORT_MESSAGE				ConnectionMessage OPTIONAL,
    IN OUT	PULONG						BufferLength OPTIONAL,
    IN OUT	PALPC_MESSAGE_ATTRIBUTES	OutMessageAttributes OPTIONAL,
    IN OUT	PALPC_MESSAGE_ATTRIBUTES	InMessageAttributes OPTIONAL,
    IN		PLARGE_INTEGER				Timeout OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtCreatePort(
    OUT		PHANDLE				PortHandle,
    IN		POBJECT_ATTRIBUTES	ObjectAttributes,
    IN		ULONG				MaxConnectionInfoLength,
    IN		ULONG				MaxMessageLength,
    IN		ULONG				MaxPoolUsage OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtListenPort(
	IN		HANDLE				PortHandle,
	OUT		PPORT_MESSAGE		ConnectionRequest);

NTSYSCALLAPI NTSTATUS NTAPI NtConnectPort(
	OUT		PHANDLE							PortHandle,
	IN		PUNICODE_STRING					PortName,
	IN		PSECURITY_QUALITY_OF_SERVICE	SecurityQos,
	IN OUT	PPORT_VIEW						ClientView OPTIONAL,
	IN OUT	PREMOTE_PORT_VIEW				ServerView OPTIONAL,
	OUT		PULONG							MaxMessageLength OPTIONAL,
	IN OUT	PVOID							ConnectionInformation OPTIONAL,
	IN OUT	PULONG							ConnectionInformationLength OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtAcceptConnectPort(
	OUT		PHANDLE				PortHandle,
	IN		PVOID				PortContext OPTIONAL,
	IN		PPORT_MESSAGE		ConnectionRequest,
	IN		BOOLEAN				AcceptConnection,
	IN OUT	PPORT_VIEW			ServerView OPTIONAL,
	OUT		PREMOTE_PORT_VIEW	ClientView OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtCompleteConnectPort(
	IN		HANDLE				PortHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtReplyPort(
	IN		HANDLE				PortHandle,
	IN		PPORT_MESSAGE		ReplyMessage);

NTSYSCALLAPI NTSTATUS NTAPI NtReplyWaitReceivePort(
	IN		HANDLE				PortHandle,
	OUT		PPVOID				PortContext OPTIONAL,
	IN		PPORT_MESSAGE		ReplyMessage OPTIONAL,
	OUT		PPORT_MESSAGE		ReceiveMessage);

NTSYSCALLAPI NTSTATUS NTAPI NtReplyWaitReceivePortEx(
	IN		HANDLE				PortHandle,
	OUT		PPVOID				PortContext OPTIONAL,
	IN		PPORT_MESSAGE		ReplyMessage OPTIONAL,
	OUT		PPORT_MESSAGE		ReceiveMessage,
	IN		PLARGE_INTEGER		Timeout OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtReplyWaitReplyPort(
	IN		HANDLE				PortHandle,
	IN OUT	PPORT_MESSAGE		ReplyMessage);

NTSYSCALLAPI NTSTATUS NTAPI NtRequestPort(
	IN		HANDLE				PortHandle,
	IN		PPORT_MESSAGE		RequestMessage);

NTSYSCALLAPI NTSTATUS NTAPI NtRequestWaitReplyPort(
	IN		HANDLE				PortHandle,
	IN		PPORT_MESSAGE		RequestMessage,
	IN		PPORT_MESSAGE		ReplyMessage);

NTSYSCALLAPI NTSTATUS NTAPI NtReadRequestData(
	IN		HANDLE				PortHandle,
	IN		PPORT_MESSAGE		Message,
	IN		ULONG				DataEntryIndex,
	OUT		PVOID				Buffer,
	IN		SIZE_T				BufferSize,
	OUT		PSIZE_T				NumberOfBytesRead OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtWriteRequestData(
	IN		HANDLE				PortHandle,
	IN		PPORT_MESSAGE		Message,
	IN		ULONG				DataEntryIndex,
	IN		PVOID				Buffer,
	IN		SIZE_T				BufferSize,
	OUT		PSIZE_T				NumberOfBytesWritten OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtCreateUserProcess(
	OUT		PHANDLE							ProcessHandle,
	OUT		PHANDLE							ThreadHandle,
	IN		ACCESS_MASK						ProcessDesiredAccess,
	IN		ACCESS_MASK						ThreadDesiredAccess,
	IN		POBJECT_ATTRIBUTES				ProcessObjectAttributes OPTIONAL,
	IN		POBJECT_ATTRIBUTES				ThreadObjectAttributes OPTIONAL,
	IN		ULONG							ProcessFlags,
	IN		ULONG							ThreadFlags,
	IN		PRTL_USER_PROCESS_PARAMETERS	ProcessParameters,
	IN OUT	PPS_CREATE_INFO					CreateInfo,
	IN		PPS_ATTRIBUTE_LIST				AttributeList OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtCreateThreadEx(
	OUT		PHANDLE							ThreadHandle,
	IN		ACCESS_MASK						DesiredAccess,
	IN		POBJECT_ATTRIBUTES				ObjectAttributes,
	IN		HANDLE							ProcessHandle,
	IN		PUSER_THREAD_START_ROUTINE		StartRoutine,
	IN		PVOID							Parameter,
	IN		ULONG							CreateFlags,
	IN		SIZE_T							StackZeroBits,
	IN		SIZE_T							StackSize,
	IN		SIZE_T							MaximumStackSize,
	IN OUT	PPS_ATTRIBUTE_LIST				AttributeList OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtDelayExecution(
	IN		BOOLEAN						Alertable,
	IN		PLONGLONG					DelayInterval);

NTSYSCALLAPI NTSTATUS NTAPI NtCreateTransaction(
	OUT		PHANDLE						TransactionHandle,
	IN		ACCESS_MASK					DesiredAccess,
	IN		POBJECT_ATTRIBUTES			ObjectAttributes OPTIONAL,
	IN		LPGUID						Uow OPTIONAL,
	IN		HANDLE						TmHandle OPTIONAL,
	IN		ULONG						CreateOptions OPTIONAL,
	IN		ULONG						IsolationLevel OPTIONAL,		// reserved must be 0
	IN		ULONG						IsolationFlags OPTIONAL,		// reserved must be 0
	IN		PLONGLONG					Timeout OPTIONAL,
	IN		PUNICODE_STRING				Description OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtCommitTransaction(
	IN		HANDLE						TransactionHandle,
	IN		BOOLEAN						Synchronous);

NTSYSCALLAPI NTSTATUS NTAPI NtRollbackTransaction(
	IN		HANDLE						TransactionHandle,
	IN		BOOLEAN						Synchronous);

NTSYSCALLAPI NTSTATUS NTAPI NtCreateKey(
	OUT		PHANDLE						KeyHandle,
	IN		ACCESS_MASK					DesiredAccess,
	IN		POBJECT_ATTRIBUTES			ObjectAttributes,
	IN		ULONG						TitleIndex,
	IN		PUNICODE_STRING				Class OPTIONAL,
	IN		ULONG						CreateOptions,
	OUT		PULONG						Disposition OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtDeleteKey(
	IN		HANDLE						KeyHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtDeleteValueKey(
	IN		HANDLE						KeyHandle,
	IN		PUNICODE_STRING				ValueName);

NTSYSCALLAPI NTSTATUS NTAPI NtEnumerateKey(
	IN		HANDLE						KeyHandle,
	IN		ULONG						Index,
	IN		KEY_INFORMATION_CLASS		KeyInformationClass,
	OUT		PVOID						KeyInformation,
	IN		ULONG						Length,
	OUT		PULONG						ResultLength);

NTSYSCALLAPI NTSTATUS NTAPI NtEnumerateValueKey(
	IN		HANDLE						KeyHandle,
	IN		ULONG						Index,
	IN		KEY_VALUE_INFORMATION_CLASS	KeyValueInformationClass,
	OUT		PVOID						KeyValueInformation,
	IN		ULONG						Length,
	OUT		PULONG						ResultLength);

NTSYSCALLAPI NTSTATUS NTAPI NtFlushKey(
	IN		HANDLE						KeyHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtNotifyChangeKey(
	IN		HANDLE						KeyHandle,
	IN		HANDLE						Event OPTIONAL,
	IN		PIO_APC_ROUTINE				ApcRoutine OPTIONAL,
	IN		PVOID						ApcContext OPTIONAL,
	OUT		PIO_STATUS_BLOCK			IoStatusBlock,
	IN		ULONG						CompletionFilter,
	IN		BOOLEAN						WatchTree,
	OUT		PVOID						Buffer OPTIONAL,
	IN		ULONG						BufferSize,
	IN		BOOLEAN						Asynchronous);

NTSYSCALLAPI NTSTATUS NTAPI NtNotifyChangeMultipleKeys(
	IN		HANDLE						MasterKeyHandle,
	IN		ULONG						Count OPTIONAL,
	IN		OBJECT_ATTRIBUTES			SlaveObjects[] OPTIONAL,
	IN		HANDLE						Event OPTIONAL,
	IN		PIO_APC_ROUTINE				ApcRoutine OPTIONAL,
	IN		PVOID						ApcContext OPTIONAL,
	OUT		PIO_STATUS_BLOCK			IoStatusBlock,
	IN		ULONG						CompletionFilter,
	IN		BOOLEAN						WatchTree,
	OUT		PVOID						Buffer OPTIONAL,
	IN		ULONG						BufferSize,
	IN		BOOLEAN						Asynchronous);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenKey(
	OUT		PHANDLE						KeyHandle,
	IN		ACCESS_MASK					DesiredAccess,
	IN		POBJECT_ATTRIBUTES			ObjectAttributes);

// OpenOptions is the same as CreateOptions from NtCreateKey.
// OpenOptions can be one, none or both of the following:
//   REG_OPTION_OPEN_LINK
//   REG_OPTION_BACKUP_RESTORE
// Other values are invalid.
NTSYSCALLAPI NTSTATUS NTAPI NtOpenKeyEx(
	OUT		PHANDLE						KeyHandle,
	IN		ACCESS_MASK					DesiredAccess,
	IN		POBJECT_ATTRIBUTES			ObjectAttributes,
	IN		ULONG						OpenOptions);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenKeyTransacted(
	OUT		PHANDLE						KeyHandle,
	IN		ACCESS_MASK					DesiredAccess,
	IN		POBJECT_ATTRIBUTES			ObjectAttributes,
	IN		HANDLE						TransactionHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenKeyTransactedEx(
	OUT		PHANDLE						KeyHandle,
	IN		ACCESS_MASK					DesiredAccess,
	IN		POBJECT_ATTRIBUTES			ObjectAttributes,
	IN		ULONG						OpenOptions,
	IN		HANDLE						TransactionHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryKey(
	IN		HANDLE						KeyHandle,
	IN		KEY_INFORMATION_CLASS		KeyInformationClass,
	OUT		PVOID						KeyInformation,
	IN		ULONG						Length,
	OUT		PULONG						ResultLength);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryValueKey(
	IN		HANDLE						KeyHandle,
	IN		PCUNICODE_STRING			ValueName,
	IN		KEY_VALUE_INFORMATION_CLASS	KeyValueInformationClass,
	OUT		PVOID						KeyValueInformation,
	IN		ULONG						Length,
	OUT		PULONG						ResultLength);

NTSYSCALLAPI NTSTATUS NTAPI NtRestoreKey(
	IN		HANDLE						KeyHandle,
	IN		HANDLE						FileHandle,
	IN		ULONG						Flags);

NTSYSCALLAPI NTSTATUS NTAPI NtSaveKey(
	IN		HANDLE						KeyHandle,
	IN		HANDLE						FileHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtSaveKeyEx(
	IN		HANDLE						KeyHandle,
	IN		HANDLE						FileHandle,
	IN		ULONG						Format);

NTSYSCALLAPI NTSTATUS NTAPI NtSaveMergedKeys(
	IN		HANDLE						HighPrecedenceKeyHandle,
	IN		HANDLE						LowPrecedenceKeyHandle,
	IN		HANDLE						FileHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtSetValueKey(
	IN		HANDLE						KeyHandle,
	IN		PUNICODE_STRING				ValueName,
	IN		ULONG						TitleIndex OPTIONAL,
	IN		ULONG						Type,
	IN		PVOID						Data OPTIONAL,
	IN		ULONG						DataSize);

NTSYSCALLAPI NTSTATUS NTAPI NtLoadKey(
	IN		POBJECT_ATTRIBUTES			TargetKey,
	IN		POBJECT_ATTRIBUTES			SourceFile);

NTSYSCALLAPI NTSTATUS NTAPI NtLoadKey2(
	IN		POBJECT_ATTRIBUTES			TargetKey,
	IN		POBJECT_ATTRIBUTES			SourceFile,
	IN		ULONG						Flags);

NTSYSCALLAPI NTSTATUS NTAPI NtLoadKeyEx(
	IN		POBJECT_ATTRIBUTES			TargetKey,
	IN		POBJECT_ATTRIBUTES			SourceFile,
	IN		ULONG						Flags,
	IN		HANDLE						TrustClassKey OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtUnloadKey(
	IN		POBJECT_ATTRIBUTES			TargetKey);

NTSYSCALLAPI NTSTATUS NTAPI NtUnloadKey2(
	IN		POBJECT_ATTRIBUTES			TargetKey,
	IN		ULONG						Flags);

NTSYSCALLAPI NTSTATUS NTAPI NtUnloadKeyEx(
	IN		POBJECT_ATTRIBUTES			TargetKey,
	IN		HANDLE						Event OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtSetInformationKey(
	IN		HANDLE						KeyHandle,
	IN		KEY_SET_INFORMATION_CLASS	KeySetInformationClass,
	IN		PVOID						KeySetInformation,
	IN		ULONG						KeySetInformationLength);

NTSYSCALLAPI NTSTATUS NTAPI NtReplaceKey(
	IN		POBJECT_ATTRIBUTES			NewFile,
	IN		HANDLE						TargetHandle,
	IN		POBJECT_ATTRIBUTES			OldFile);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryMultipleValueKey(
	IN		HANDLE						KeyHandle,
	IN OUT	PKEY_VALUE_ENTRY			ValueEntries,
	IN		ULONG						EntryCount,
	OUT		PVOID						ValueBuffer,
	IN OUT	PULONG						BufferLength,
	OUT		PULONG						RequiredBufferLength OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryOpenSubKeys(
	IN		POBJECT_ATTRIBUTES			TargetKey,
	OUT		PULONG						HandleCount);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryOpenSubKeysEx(
	IN		POBJECT_ATTRIBUTES			TargetKey,
	IN		ULONG						BufferLength,
	OUT		PVOID						Buffer,
	OUT		PULONG						RequiredSize);

NTSYSCALLAPI NTSTATUS NTAPI NtRenameKey(
	IN		HANDLE						KeyHandle,
	IN		PUNICODE_STRING				NewName);

NTSYSCALLAPI NTSTATUS NTAPI NtCompactKeys(
	IN		ULONG						Count,
	IN		HANDLE						KeyArray[]);

NTSYSCALLAPI NTSTATUS NTAPI NtCompressKey(
	IN		HANDLE						Key);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenSection(
	OUT		PHANDLE						SectionHandle,
	IN		ACCESS_MASK					DesiredAccess,
	IN		POBJECT_ATTRIBUTES			ObjectAttributes);

NTSYSCALLAPI NTSTATUS NTAPI NtCreateSection(
	OUT		PHANDLE						SectionHandle,
	IN		ULONG						DesiredAccess,
	IN		POBJECT_ATTRIBUTES			ObjectAttributes OPTIONAL,
	IN		PLONGLONG					MaximumSize OPTIONAL,
	IN		ULONG						PageAttributes,
	IN		ULONG						SectionAttributes,
	IN		HANDLE						FileHandle OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtQuerySection(
	IN		HANDLE						SectionHandle,
	IN		SECTION_INFORMATION_CLASS	SectionInformationClass,
	OUT		PVOID						SectionInformation,
	IN		SIZE_T						SectionInformationLength,
	OUT		PSIZE_T						ReturnLength OPTIONAL);

NTSYSCALLAPI NTSTATUS NTAPI NtExtendSection(
	IN		HANDLE						SectionHandle,
	IN		PLONGLONG					NewSectionSize);

NTSYSCALLAPI NTSTATUS NTAPI NtMapViewOfSection(
	IN		HANDLE						SectionHandle,
	IN		HANDLE						ProcessHandle,
	IN OUT	PPVOID						BaseAddress OPTIONAL,
	IN		ULONG						ZeroBits OPTIONAL,
	IN		SIZE_T						CommitSize,
	IN OUT	PLONGLONG					SectionOffset OPTIONAL,
	IN OUT	PSIZE_T						ViewSize,
	IN		SECTION_INHERIT				InheritDisposition,
	IN		ULONG						AllocationType,
	IN		ULONG						MemoryProtection);

NTSYSCALLAPI NTSTATUS NTAPI NtUnmapViewOfSection(
	IN		HANDLE						ProcessHandle,
	IN		PVOID						BaseAddress);

NTSYSCALLAPI NTSTATUS NTAPI NtQueueApcThread(
	IN		HANDLE						ThreadHandle,
	IN		PKNORMAL_ROUTINE			ApcRoutine,
	IN		PVOID						NormalContext,
	IN		PVOID						SystemArgument1,
	IN		PVOID						SystemArgument2);

NTSYSCALLAPI NTSTATUS NTAPI NtAlertThread(
	IN		HANDLE						ThreadHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtQuerySystemTime(
	OUT		PLONGLONG					SystemTime);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryDirectoryFile(
	IN		HANDLE						DirectoryHandle,
	IN		HANDLE						Event OPTIONAL,
	IN		PIO_APC_ROUTINE				ApcRoutine OPTIONAL,
	IN		PVOID						ApcContext OPTIONAL,
	OUT		PIO_STATUS_BLOCK			IoStatusBlock,
	OUT		PVOID						FileInformation,
	IN		ULONG						FileInformationLength,
	IN		FILE_INFORMATION_CLASS		FileInformationClass,
	IN		BOOLEAN						ReturnSingleEntry,
	IN		PUNICODE_STRING				FileName OPTIONAL,
	IN		BOOLEAN						RestartScan);

NTSYSCALLAPI NTSTATUS NTAPI NtCreateEvent(
	OUT		PHANDLE				EventHandle,
	IN		ACCESS_MASK			DesiredAccess,
	IN		POBJECT_ATTRIBUTES	ObjectAttributes OPTIONAL,
	IN		EVENT_TYPE			EventType,
	IN		BOOLEAN				InitialState);

NTSYSCALLAPI NTSTATUS NTAPI NtDisplayString(
	IN		PCUNICODE_STRING	String);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenProcessToken(
	IN		HANDLE		ProcessHandle,
	IN		ACCESS_MASK	DesiredAccess,
	OUT		PHANDLE		TokenHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenProcessTokenEx(
	IN		HANDLE		ProcessHandle,
	IN		ACCESS_MASK	DesiredAccess,
	IN		ULONG		HandleAttributes,
	OUT		PHANDLE		TokenHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenThreadToken(
	IN		HANDLE		ThreadHandle,
	IN		ACCESS_MASK	DesiredAccess,
	IN		BOOLEAN		OpenAsSelf,
	OUT		PHANDLE		TokenHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenThreadTokenEx(
	IN		HANDLE		ThreadHandle,
	IN		ACCESS_MASK	DesiredAccess,
	IN		BOOLEAN		OpenAsSelf,
	IN		ULONG		HandleAttributes,
	OUT		PHANDLE		TokenHandle);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryInformationToken(
	IN		HANDLE					TokenHandle,
	IN		TOKEN_INFORMATION_CLASS	TokenInformationClass,
	OUT		PVOID					TokenInformation,
	IN		ULONG					TokenInformationLength,
	OUT		PULONG					ReturnLength);

NTSYSCALLAPI NTSTATUS NTAPI NtPowerInformation(
	IN		POWER_INFORMATION_LEVEL	InformationLevel,
	IN		PVOID					InputBuffer OPTIONAL,
	IN		ULONG					InputBufferLength,
	OUT		PVOID					OutputBuffer OPTIONAL,
	IN		ULONG					OutputBufferLength);

NTSYSCALLAPI NTSTATUS NTAPI NtCreateDirectoryObject(
	OUT		PHANDLE				DirectoryHandle,
	IN		ACCESS_MASK			DesiredAccess,
	IN		POBJECT_ATTRIBUTES	ObjectAttributes);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenDirectoryObject(
	OUT		PHANDLE				DirectoryHandle,
	IN		ACCESS_MASK			DesiredAccess,
	IN		POBJECT_ATTRIBUTES	ObjectAttributes);

NTSYSCALLAPI NTSTATUS NTAPI NtSetSecurityObject(
	IN		HANDLE					Handle,
	IN		SECURITY_INFORMATION	SecurityInformation,
	IN		PSECURITY_DESCRIPTOR	SecurityDescriptor);

NTSYSCALLAPI NTSTATUS NTAPI NtQuerySecurityObject(
	IN		HANDLE					Handle,
	IN		SECURITY_INFORMATION	SecurityInformation,
	OUT		PSECURITY_DESCRIPTOR	SecurityDescriptor OPTIONAL,
	IN		ULONG					Length,
	OUT		PULONG					LengthNeeded);

NTSYSCALLAPI NTSTATUS NTAPI NtDuplicateObject(
	IN		HANDLE		SourceProcessHandle,
	IN		HANDLE		SourceHandle,
	IN		HANDLE		TargetProcessHandle OPTIONAL,
	OUT		PHANDLE		TargetHandle,
	IN		ACCESS_MASK	DesiredAccess,
	IN		ULONG		HandleAttributes,
	IN		ULONG		Options);

NTSYSCALLAPI NTSTATUS NTAPI NtOpenThread(
	OUT		PHANDLE				ThreadHandle,
	IN		ACCESS_MASK			DesiredAccess,
	IN		POBJECT_ATTRIBUTES	ObjectAttributes,
	IN		PCLIENT_ID			ClientId);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryAttributesFile(
	IN		POBJECT_ATTRIBUTES		ObjectAttributes,
	OUT		PFILE_BASIC_INFORMATION	FileInformation);

NTSYSCALLAPI NTSTATUS NTAPI NtQueryFullAttributesFile(
	IN		POBJECT_ATTRIBUTES				ObjectAttributes,
	OUT		PFILE_NETWORK_OPEN_INFORMATION	FileInformation);

NTSYSCALLAPI NTSTATUS NTAPI NtAssignProcessToJobObject(
	IN		HANDLE		JobHandle,
	IN		HANDLE		ProcessHandle);

#pragma endregion

#pragma region Nt* function declarations (not in Windows 7)

NTSYSCALLAPI NTSTATUS NTAPI NtSetInformationVirtualMemory(
	IN		HANDLE								ProcessHandle,
	IN		VIRTUAL_MEMORY_INFORMATION_CLASS	VmInformationClass,
	IN		ULONG_PTR							NumberOfEntries,
	IN		PMEMORY_RANGE_ENTRY					VirtualAddresses,
	IN		PVOID								VmInformation,
	IN		ULONG								VmInformationLength);

#pragma endregion

#pragma region NtWow64* function declarations

typedef NTSTATUS (NTAPI *NT_WOW64_WRITE_VIRTUAL_MEMORY64) (
	IN		HANDLE		ProcessHandle,
	IN		PVOID64		BaseAddress,
	IN		PCVOID		Buffer,
	IN		ULONGLONG	BufferSize,
	OUT		PSIZE_T		NumberOfBytesWritten OPTIONAL);

typedef NTSTATUS (NTAPI *NT_WOW64_READ_VIRTUAL_MEMORY64) (
	IN		HANDLE		ProcessHandle,
	IN		PVOID64		BaseAddress,
	OUT		PVOID		Buffer,
	IN		ULONGLONG	BufferSize,
	OUT		PULONGLONG	NumberOfBytesRead OPTIONAL);

typedef NTSTATUS (NTAPI *NT_WOW64_QUERY_INFORMATION_PROCESS64) (
	IN		HANDLE				ProcessHandle,
	IN		PROCESSINFOCLASS	ProcessInformationClass,
	OUT		PVOID				ProcessInformation64,
	IN		ULONG				ProcessInformationLength,
	OUT		PULONG				ReturnLength OPTIONAL);

#pragma endregion

#pragma region Rtl* function declarations
NTSYSAPI NTSTATUS NTAPI RtlCreateProcessParameters(
	OUT	PRTL_USER_PROCESS_PARAMETERS *pProcessParameters,
	IN	PUNICODE_STRING ImagePathName,
	IN	PUNICODE_STRING DllPath OPTIONAL,
	IN	PUNICODE_STRING CurrentDirectory OPTIONAL,
	IN	PUNICODE_STRING CommandLine OPTIONAL,
	IN	PVOID Environment OPTIONAL,
	IN	PUNICODE_STRING WindowTitle OPTIONAL,
	IN	PUNICODE_STRING DesktopInfo OPTIONAL,
	IN	PUNICODE_STRING ShellInfo OPTIONAL,
	IN	PUNICODE_STRING RuntimeData OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlCreateUserProcess(
	IN	PUNICODE_STRING NtImagePathName,
	IN	ULONG Attributes,
	IN	PRTL_USER_PROCESS_PARAMETERS ProcessParameters,
	IN	PSECURITY_DESCRIPTOR ProcessSecurityDescriptor OPTIONAL,
	IN	PSECURITY_DESCRIPTOR ThreadSecurityDescriptor OPTIONAL,
	IN	HANDLE ParentProcess OPTIONAL,
	IN	BOOLEAN InheritHandles,
	IN	HANDLE DebugPort OPTIONAL,
	IN	HANDLE ExceptionPort OPTIONAL,
	OUT	PRTL_USER_PROCESS_INFORMATION ProcessInformation);

NTSYSAPI NTSTATUS NTAPI RtlCreateProcessParametersEx(
	OUT		PRTL_USER_PROCESS_PARAMETERS	*ProcessParameters,
	IN		PUNICODE_STRING					ImagePathName,
	IN		PUNICODE_STRING					DllPath OPTIONAL,
	IN		PUNICODE_STRING					CurrentDirectory OPTIONAL,
	IN		PUNICODE_STRING					CommandLine OPTIONAL,
	IN		PVOID							Environment OPTIONAL,
	IN		PUNICODE_STRING					WindowTitle OPTIONAL,
	IN		PUNICODE_STRING					DesktopInfo OPTIONAL,
	IN		PUNICODE_STRING					ShellInfo OPTIONAL,
	IN		PUNICODE_STRING					RuntimeData OPTIONAL,
	IN		ULONG							Flags);

NTSYSAPI NTSTATUS NTAPI RtlDestroyProcessParameters(
	IN		PRTL_USER_PROCESS_PARAMETERS	ProcessParameters);

NTSYSAPI NTSTATUS NTAPI RtlCreateUserThread(
	IN		HANDLE						Process,
	IN		PSECURITY_DESCRIPTOR		ThreadSecurityDescriptor OPTIONAL,
	IN		BOOLEAN						CreateSuspended,
	IN		ULONG						ZeroBits OPTIONAL,
	IN		SIZE_T						MaximumStackSize OPTIONAL,
	IN		SIZE_T						CommittedStackSize OPTIONAL,
	IN		PUSER_THREAD_START_ROUTINE	StartAddress,
	IN		PVOID						Parameter OPTIONAL,
	OUT		PHANDLE						Thread OPTIONAL,
	OUT		PCLIENT_ID					ClientId OPTIONAL);

NTSYSAPI NORETURN VOID NTAPI RtlExitUserThread(
	IN		NTSTATUS					ExitStatus);

NTSYSAPI NORETURN VOID NTAPI RtlExitUserProcess(
	IN		NTSTATUS					ExitStatus);

NTSYSAPI VOID NTAPI RtlAcquirePebLock(
	VOID);

NTSYSAPI VOID NTAPI RtlReleasePebLock(
	VOID);

NTSYSAPI ULONG NTAPI RtlNtStatusToDosError(
	IN	NTSTATUS	Status);

NTSYSAPI ULONG NTAPI RtlNtStatusToDosErrorNoTeb(
	IN	NTSTATUS	Status);

NTSYSAPI VOID NTAPI RtlSetLastWin32Error(
	IN	LONG	Win32Error);

NTSYSAPI VOID NTAPI RtlInitAnsiString(
	OUT	PANSI_STRING	DestinationString,
	IN	PCSTR			SourceString OPTIONAL);

NTSYSAPI VOID NTAPI RtlInitUnicodeString(
	OUT	PUNICODE_STRING	DestinationString,
	IN	PCWSTR			SourceString OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlInitAnsiStringEx(
	OUT	PANSI_STRING	DestinationString,
	IN	PCSTR			SourceString OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlInitUnicodeStringEx(
	OUT	PUNICODE_STRING	DestinationString,
	IN	PCWSTR			SourceString OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlAnsiStringToUnicodeString(
	OUT	PUNICODE_STRING	DestinationString,
	IN	PCANSI_STRING	SourceString,
	IN	BOOLEAN			AllocateDestinationString);

NTSYSAPI BOOLEAN NTAPI RtlCreateUnicodeStringFromAsciiz(
	OUT	PUNICODE_STRING	DestinationString,
	IN	PCSTR			SourceString OPTIONAL);

NTSYSAPI BOOLEAN NTAPI RtlCreateUnicodeString(
	OUT	PUNICODE_STRING	DestinationString,
	IN	PCWSTR			SourceString);

NTSYSAPI NTSTATUS NTAPI RtlUpcaseUnicodeString(
	OUT	PUNICODE_STRING		DestinationString,
	IN	PCUNICODE_STRING	SourceString,
	IN	BOOLEAN				AllocateDestinationString);

NTSYSAPI NTSTATUS NTAPI RtlDowncaseUnicodeString(
	OUT	PUNICODE_STRING		DestinationString,
	IN	PCUNICODE_STRING	SourceString,
	IN	BOOLEAN				AllocateDestinationString);

NTSYSAPI VOID NTAPI RtlFreeUnicodeString(
	IN OUT	PUNICODE_STRING	UnicodeString);

NTSYSAPI BOOLEAN NTAPI RtlEqualUnicodeString(
	IN	PCUNICODE_STRING	String1,
	IN	PCUNICODE_STRING	String2,
	IN	BOOLEAN				CaseInsensitive);

NTSYSAPI LONG NTAPI RtlCompareUnicodeString(
	IN	PCUNICODE_STRING	String1,
	IN	PCUNICODE_STRING	String2,
	IN	BOOLEAN				CaseInsensitive);

NTSYSAPI BOOLEAN NTAPI RtlPrefixUnicodeString(
	IN	PCUNICODE_STRING	Prefix,
	IN	PCUNICODE_STRING	String,
	IN	BOOLEAN				CaseInsensitive);

NTSYSAPI VOID NTAPI RtlCopyString(
	OUT	PANSI_STRING		DestinationString,
	IN	PCANSI_STRING		SourceString OPTIONAL);

#define RtlCopyAnsiString RtlCopyString

NTSYSAPI VOID NTAPI RtlCopyUnicodeString(
	OUT	PUNICODE_STRING		DestinationString,
	IN	PCUNICODE_STRING	SourceString OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlAppendUnicodeToString(
	IN	PUNICODE_STRING		DestinationString,
	IN	PCWSTR				SourceString OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlAppendUnicodeStringToString(
	IN OUT	PUNICODE_STRING		DestinationString,
	IN		PCUNICODE_STRING	SourceString);

NTSYSAPI NTSTATUS NTAPI RtlHashUnicodeString(
	IN	PCUNICODE_STRING	String,
	IN	BOOLEAN				CaseInsensitive,
	IN	ULONG				HashAlgorithm,
	OUT	PULONG				HashValue);

NTSYSAPI NTSTATUS NTAPI RtlUnicodeStringToAnsiString(
	OUT	PANSI_STRING		DestinationString,
	IN	PCUNICODE_STRING	SourceString,
	IN	BOOLEAN				AllocateDestinationString);

NTSYSAPI NTSTATUS NTAPI RtlAnsiStringToUnicodeString(
	OUT	PUNICODE_STRING		DestinationString,
	IN	PCANSI_STRING		SourceString,
	IN	BOOLEAN				AllocateDestinationString);

NTSYSAPI NTSTATUS NTAPI RtlIntegerToUnicodeString(
	IN		ULONG			Value,
	IN		ULONG			Base OPTIONAL,
	IN OUT	PUNICODE_STRING	String);

NTSYSAPI NTSTATUS NTAPI RtlInt64ToUnicodeString(
	IN		ULONGLONG		Value,
	IN		ULONG			Base,
	IN OUT	PUNICODE_STRING	String);

NTSYSAPI NTSTATUS NTAPI RtlUnicodeStringToInteger(
	IN		PCUNICODE_STRING	String,
	IN		ULONG				Base OPTIONAL,
	OUT		PULONG				Value);

// Flags can be RTL_FIND_CHAR_IN_UNICODE_STRING_*
NTSYSAPI NTSTATUS NTAPI RtlFindCharInUnicodeString(
	IN		ULONG				Flags,
	IN		PCUNICODE_STRING	StringToSearch,
	IN		PCUNICODE_STRING	CharSet,
	OUT		PUSHORT				NonInclusivePrefixLength);

NTSYSAPI PVOID NTAPI RtlAllocateHeap(
	IN	PVOID	HeapHandle,
	IN	ULONG	Flags OPTIONAL,
	IN	SIZE_T	Size);

NTSYSAPI PVOID NTAPI RtlReAllocateHeap(
	IN	PVOID	HeapHAndle,
	IN	ULONG	Flags OPTIONAL,
	IN	PVOID	BaseAddress OPTIONAL,
	IN	SIZE_T	Size);

NTSYSAPI BOOLEAN NTAPI RtlFreeHeap(
	IN	PVOID	HeapHandle,
	IN	ULONG	Flags OPTIONAL,
	IN	PVOID	BaseAddress OPTIONAL);

NTSYSAPI SIZE_T NTAPI RtlCompactHeap(
	IN	PVOID	HeapHandle,
	IN	ULONG	Flags);

NTSYSAPI NTSTATUS NTAPI RtlCreateEnvironment(
	IN	BOOLEAN	CloneCurrentEnvironment,
	OUT	PVOID	*Environment);

NTSYSAPI NTSTATUS NTAPI RtlDestroyEnvironment(
	IN	PVOID	Environment);

NTSYSAPI NTSTATUS NTAPI RtlSetCurrentEnvironment(
	IN	PVOID	Environment,
	OUT	PVOID	*PreviousEnvironment OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlQueryEnvironmentVariable_U(
	IN		PVOID				Environment OPTIONAL,
	IN		PCUNICODE_STRING	Name,
	IN OUT	PUNICODE_STRING		Value);

NTSYSAPI NTSTATUS NTAPI RtlSetEnvironmentVariable(
	IN OUT	PVOID				*Environment OPTIONAL,
	IN		PCUNICODE_STRING	Name,
	IN		PCUNICODE_STRING	Value OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlSetEnvironmentStrings(
	IN	PWCHAR	NewEnvironment,
	IN	SIZE_T	NewEnvironmentSize);

NTSYSAPI NTSTATUS NTAPI RtlInitializeCriticalSection(
	IN	PRTL_CRITICAL_SECTION	CriticalSection);

NTSYSAPI NTSTATUS NTAPI RtlInitializeCriticalSectionAndSpinCount(
	IN	PRTL_CRITICAL_SECTION	CriticalSection,
	IN	ULONG					SpinCount);

NTSYSAPI NTSTATUS NTAPI RtlInitializeCriticalSectionEx(
	IN	PRTL_CRITICAL_SECTION	CriticalSection,
	IN	ULONG					SpinCount,
	IN	ULONG					Flags); // RTL_CRITICAL_SECTION_FLAG_

NTSYSAPI NTSTATUS NTAPI RtlEnterCriticalSection(
	IN	PRTL_CRITICAL_SECTION	CriticalSection);

NTSYSAPI BOOLEAN NTAPI RtlTryEnterCriticalSection(
	IN	PRTL_CRITICAL_SECTION	CriticalSection);

NTSYSAPI NTSTATUS NTAPI RtlLeaveCriticalSection(
	IN	PRTL_CRITICAL_SECTION	CriticalSection);

NTSYSAPI NTSTATUS NTAPI RtlDeleteCriticalSection(
	IN	PRTL_CRITICAL_SECTION	CriticalSection);

// Note: This is exactly identical to zeroing the memory of the SRW lock.
// If running on Windows 7 only, no need to call this function.
#define RtlInitializeSRWLock(SRWLock) (SRWLock)->Ptr = NULL
#define InitializeSRWLock RtlInitializeSRWLock
//NTSYSAPI VOID NTAPI RtlInitializeSRWLock(
//	OUT	PRTL_SRWLOCK			SRWLock);

NTSYSAPI VOID NTAPI RtlAcquireSRWLockExclusive(
	IN OUT	PRTL_SRWLOCK		SRWLock);

NTSYSAPI VOID NTAPI RtlAcquireSRWLockShared(
	IN OUT	PRTL_SRWLOCK		SRWLock);

NTSYSAPI VOID NTAPI RtlReleaseSRWLockExclusive(
	IN OUT	PRTL_SRWLOCK		SRWLock);

NTSYSAPI VOID NTAPI RtlReleaseSRWLockShared(
	IN OUT	PRTL_SRWLOCK		SRWLock);

NTSYSAPI BOOLEAN NTAPI RtlTryAcquireSRWLockExclusive(
	IN OUT	PRTL_SRWLOCK		SRWLock);

NTSYSAPI BOOLEAN NTAPI RtlTryAcquireSRWLockShared(
	IN OUT	PRTL_SRWLOCK		SRWLock);

NTSYSAPI NTSTATUS NTAPI RtlGetLengthWithoutLastFullDosOrNtPathElement(
	IN	ULONG				Flags,
	IN	PCUNICODE_STRING	Path,
	OUT	PULONG				CchLengthOut);

NTSYSAPI NTSTATUS NTAPI RtlQueryRegistryValues(
	IN	RTL_QUERY_REGISTRY_RELATIVE_TO	RelativeTo,
	IN	PCWSTR							Path,
	IN	PRTL_QUERY_REGISTRY_TABLE		QueryTable,
	IN	PVOID							Context OPTIONAL,
	IN	PVOID							Environment OPTIONAL);

NTSYSAPI PIMAGE_NT_HEADERS NTAPI RtlImageNtHeader(
	IN	PVOID	ImageBaseAddress);

// ViewSize is only optional when Flags & RTL_IMAGE_NT_HEADER_EX_FLAG_NO_RANGE_CHECK.
NTSYSAPI NTSTATUS NTAPI RtlImageNtHeaderEx(
	IN	ULONG				Flags,
	IN	PVOID				ImageBaseAddress,
	IN	ULONG64				ViewSize OPTIONAL,
	OUT	PIMAGE_NT_HEADERS	*NtHeadersOut);

NTSYSAPI PVOID NTAPI RtlImageDirectoryEntryToData(
	IN	PVOID				ImageBaseAddress,
	IN	BOOLEAN				MappedAsImage,
	IN	USHORT				DirectoryEntry,
	OUT	PULONG				Size);

NTSYSAPI ULONG NTAPI RtlRandom(
	IN OUT	PULONG			Seed);

NTSYSAPI ULONG NTAPI RtlRandomEx(
	IN OUT	PULONG			Seed);

NTSYSAPI RTL_PATH_TYPE NTAPI RtlDetermineDosPathNameType_U(
	IN	PCWSTR				String);

NTSYSAPI RTL_PATH_TYPE NTAPI RtlDetermineDosPathNameType_Ustr(
	IN	PCUNICODE_STRING	String);

#define RtlDetermineDosPathNameType RtlDetermineDosPathNameType_Ustr

// May be useful:
// https://googleprojectzero.blogspot.com/2016/02/the-definitive-guide-on-win32-to-nt.html
// Notes on the following 4 APIs:
// The NtFileName output parameter will fill the Buffer member of the UNICODE_STRING
// with a pointer that points to memory newly allocated from the RtlProcessHeap.
// As such, when you are done with it, you should use RtlFreeUnicodeString on the
// *NtFileName parameter.

NTSYSAPI BOOLEAN NTAPI RtlDosPathNameToRelativeNtPathName_U(
	IN	PCWSTR					DosFileName,
	OUT	PUNICODE_STRING			NtFileName,
	OUT	PPWSTR					FilePart OPTIONAL,
	OUT	PRTL_RELATIVE_NAME_U	RelativeName OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlDosPathNameToRelativeNtPathName_U_WithStatus(
	IN	PCWSTR					DosFileName,
	OUT	PUNICODE_STRING			NtFileName,
	OUT	PPWSTR					FilePart OPTIONAL,
	OUT	PRTL_RELATIVE_NAME_U	RelativeName OPTIONAL);

NTSYSAPI BOOLEAN NTAPI RtlDosPathNameToNtPathName_U(
	IN	PCWSTR					DosFileName,
	OUT	PUNICODE_STRING			NtFileName,
	OUT	PPWSTR					FilePart OPTIONAL,
	OUT	PRTL_RELATIVE_NAME_U	RelativeName OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlDosPathNameToNtPathName_U_WithStatus(
	IN	PCWSTR					DosFileName,
	OUT	PUNICODE_STRING			NtFileName,
	OUT	PPWSTR					FilePart OPTIONAL,
	OUT	PRTL_RELATIVE_NAME_U	RelativeName OPTIONAL);

NTSYSAPI BOOLEAN NTAPI RtlCreateHashTable(
	IN OUT	PRTL_DYNAMIC_HASH_TABLE	*HashTable,
	IN		ULONG					Shift OPTIONAL,
	IN		ULONG					Flags OPTIONAL);

NTSYSAPI BOOLEAN NTAPI RtlDeleteHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE	HashTable);

NTSYSAPI BOOLEAN NTAPI RtlInsertEntryHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE			HashTable,
	IN		PRTL_DYNAMIC_HASH_TABLE_ENTRY	Entry,
	IN		ULONG_PTR						Signature,
	IN OUT	PRTL_DYNAMIC_HASH_TABLE_CONTEXT	Context OPTIONAL);

NTSYSAPI BOOLEAN NTAPI RtlRemoveEntryHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE			HashTable,
	IN		PRTL_DYNAMIC_HASH_TABLE_ENTRY	Entry,
	IN OUT	PRTL_DYNAMIC_HASH_TABLE_CONTEXT	Context OPTIONAL);

NTSYSAPI PRTL_DYNAMIC_HASH_TABLE_ENTRY NTAPI RtlLookupEntryHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE			HashTable,
	IN		ULONG_PTR						Signature,
	OUT		PRTL_DYNAMIC_HASH_TABLE_CONTEXT	Context OPTIONAL);

NTSYSAPI PRTL_DYNAMIC_HASH_TABLE_ENTRY NTAPI RtlGetNextEntryHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE			HashTable,
	IN		PRTL_DYNAMIC_HASH_TABLE_CONTEXT	Context);

NTSYSAPI BOOLEAN NTAPI RtlInitEnumerationHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable,
	OUT		PRTL_DYNAMIC_HASH_TABLE_ENUMERATOR	Enumerator);

NTSYSAPI PRTL_DYNAMIC_HASH_TABLE_ENTRY NTAPI RtlEnumerateEntryHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable,
	IN OUT	PRTL_DYNAMIC_HASH_TABLE_ENUMERATOR	Enumerator);

NTSYSAPI VOID NTAPI RtlEndEnumerationHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable,
	IN OUT	PRTL_DYNAMIC_HASH_TABLE_ENUMERATOR	Enumerator);

NTSYSAPI BOOLEAN NTAPI RtlInitWeakEnumerationHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable,
	OUT		PRTL_DYNAMIC_HASH_TABLE_ENUMERATOR	Enumerator);

NTSYSAPI PRTL_DYNAMIC_HASH_TABLE_ENTRY NTAPI RtlWeaklyEnumerateEntryHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable,
	IN OUT	PRTL_DYNAMIC_HASH_TABLE_ENUMERATOR	Enumerator);

NTSYSAPI VOID NTAPI RtlEndWeakEnumerationHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable,
	IN OUT	PRTL_DYNAMIC_HASH_TABLE_ENUMERATOR	Enumerator);

NTSYSAPI BOOLEAN NTAPI RtlExpandHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable);

NTSYSAPI BOOLEAN NTAPI RtlContractHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable);

NTSYSAPI VOID NTAPI RtlApplicationVerifierStop(
    IN	ULONG_PTR		Code,
    IN	PCHAR			Message,
    IN	ULONG_PTR		Param1,
	IN	PCHAR			Description1,
	IN	ULONG_PTR		Param2,
	IN	PCHAR			Description2,
    IN	ULONG_PTR		Param3,
	IN	PCHAR			Description3,
    IN	ULONG_PTR		Param4,
	IN	PCHAR			Description4);

NTSYSAPI VOID NTAPI RtlGetNtVersionNumbers(
	OUT	PULONG	MajorVersion OPTIONAL,
	OUT	PULONG	MinorVersion OPTIONAL,
	OUT	PULONG	BuildNumber OPTIONAL);

NTSYSAPI VOID NTAPI RtlRaiseStatus(
	IN	NTSTATUS	Status);

NTSYSAPI BOOLEAN NTAPI RtlSetCurrentTransaction(
	IN	HANDLE	TransactionHandle);

NTSYSAPI HANDLE NTAPI RtlGetCurrentTransaction(
	VOID);

NTSYSAPI VOID NTAPI RtlTimeToTimeFields(
	IN	PLONGLONG		Time,
	IN	PTIME_FIELDS	TimeFields);

#define RtlSetCurrentDirectory RtlSetCurrentDirectory_U
NTSYSAPI NTSTATUS NTAPI RtlSetCurrentDirectory_U(
	IN	PCUNICODE_STRING	Path);

NTSYSAPI NTSTATUS NTAPI RtlOpenCurrentUser(
	IN	ULONG	DesiredAccess,
	OUT	PHANDLE	CurrentUserKey);

#define RtlExpandEnvironmentStrings RtlExpandEnvironmentStrings_U
NTSYSAPI NTSTATUS NTAPI RtlExpandEnvironmentStrings_U(
	IN	PVOID				Environment OPTIONAL,
	IN	PCUNICODE_STRING	Source,
	OUT	PUNICODE_STRING		Destination,
	OUT	PULONG				ReturnedLength OPTIONAL);

//
// I don't know what any of these MemoryZone APIs are supposed to be used for.
// I just saw them, decompiled them and wrote their prototypes here.
//

NTSYSAPI NTSTATUS NTAPI RtlCreateMemoryZone(
	OUT	PRTL_MEMORY_ZONE	*MemoryZone,
	IN	SIZE_T				InitialSize,
	IN	ULONG				Flags); // no valid flags - set to 0

NTSYSAPI NTSTATUS NTAPI RtlDestroyMemoryZone(
	IN	PRTL_MEMORY_ZONE	MemoryZone);

NTSYSAPI NTSTATUS NTAPI RtlResetMemoryZone(
	IN	PRTL_MEMORY_ZONE	MemoryZone);

NTSYSAPI NTSTATUS NTAPI RtlLockMemoryZone(
	IN	PRTL_MEMORY_ZONE	MemoryZone);

NTSYSAPI NTSTATUS NTAPI RtlUnlockMemoryZone(
	IN	PRTL_MEMORY_ZONE	MemoryZone);

NTSYSAPI NTSTATUS NTAPI RtlAllocateMemoryZone(
	IN	PRTL_MEMORY_ZONE	MemoryZone,
	IN	SIZE_T				BlockSize,
	OUT	PVOID				Block);

NTSYSAPI NTSTATUS NTAPI RtlExtendMemoryZone(
	IN	PRTL_MEMORY_ZONE	MemoryZone,
	IN	SIZE_T				Increment);

//
// These thread profiling functions are more or less documented in their
// Win32 forms, e.g. EnableThreadProfiling.
//

NTSYSAPI NTSTATUS NTAPI RtlEnableThreadProfiling(
	IN	HANDLE		ThreadHandle,
	IN	ULONG		Flags,
	IN	ULONGLONG	HardwareCounters,
	OUT	PPVOID		PerformanceDataHandle);

NTSYSAPI NTSTATUS NTAPI RtlDisableThreadProfiling(
	IN	PVOID		PerformanceDataHandle);

NTSYSAPI NTSTATUS NTAPI RtlQueryThreadProfiling(
	IN	HANDLE		ThreadHandle,
	OUT	PBOOLEAN	Enabled);

NTSYSAPI NTSTATUS NTAPI RtlReadThreadProfilingData(
	IN	PVOID				PerformanceDataHandle,
	IN	ULONG				Flags,
	OUT	PPERFORMANCE_DATA	Data);

//
// This function supports the typical * and ? wildcards.
//
NTSYSAPI BOOLEAN NTAPI RtlIsNameInExpression(
	IN	PCUNICODE_STRING	Expression,
	IN	PCUNICODE_STRING	Name,
	IN	BOOLEAN				IgnoreCase,
	IN	PWCHAR				UpcaseTable OPTIONAL);

NTSYSAPI NTSTATUS NTAPI RtlSetProcessIsCritical(
	IN	BOOLEAN		NewValue,
	OUT	PBOOLEAN	OldValue OPTIONAL,
	IN	BOOLEAN		CheckFlag);

NTSYSAPI NTSTATUS NTAPI RtlSetThreadIsCritical(
	IN	BOOLEAN		NewValue,
	OUT	PBOOLEAN	OldValue OPTIONAL,
	IN	BOOLEAN		CheckFlag);

typedef NTSTATUS (NTAPI *PRTL_ENUM_HEAPS_CALLBACK_ROUTINE) (
	IN	PVOID	HeapHandle,
	IN	PVOID	CallbackContext);

NTSYSAPI NTSTATUS NTAPI RtlEnumProcessHeaps(
	IN	PRTL_ENUM_HEAPS_CALLBACK_ROUTINE	EnumRoutine,
	IN	PVOID								CallbackContext OPTIONAL);

NTSYSAPI PVOID NTAPI RtlCreateHeap(
	IN	ULONG	Flags,
	IN	PVOID	HeapBase OPTIONAL,
	IN	SIZE_T	ReserveSize,
	IN	SIZE_T	CommitSize,
	IN	PVOID	Lock OPTIONAL,
	IN	PVOID	Parameters OPTIONAL);

NTSYSAPI PVOID NTAPI RtlDestroyHeap(
	IN	PVOID	HeapHandle);

NTSYSAPI NTSTATUS NTAPI RtlVerifyVersionInfo(
	IN	PRTL_OSVERSIONINFOEXW	VersionInfo,
	IN	ULONG					TypeMask,
	IN	ULONGLONG				ConditionMask);

NTSYSAPI NTSTATUS NTAPI RtlGetVersion(
	OUT	PRTL_OSVERSIONINFOEXW	VersionInfo);

NTSYSAPI BOOLEAN NTAPI RtlGetNtProductType(
	OUT	PNT_PRODUCT_TYPE	ProductType);

NTSYSAPI NTSTATUS NTAPI RtlCreateAcl(
	OUT		PACL		Acl,
	IN		ULONG		AclLength,
	IN		ULONG		AclRevision);

NTSYSAPI NTSTATUS NTAPI RtlAddMandatoryAce(
	IN OUT	PACL	Acl,
	IN		ULONG	Revision,
	IN		ULONG	Flags,
	IN		PSID	LabelSid,
	IN		UCHAR	AceType,
	IN		ULONG	AccessMask);

NTSYSAPI NTSTATUS NTAPI RtlCreateSecurityDescriptor(
	OUT		PSECURITY_DESCRIPTOR	SecurityDescriptor,
	IN		ULONG					Revision);

NTSYSAPI NTSTATUS NTAPI RtlSetDaclSecurityDescriptor(
	IN OUT	PSECURITY_DESCRIPTOR	SecurityDescriptor,
	IN		BOOLEAN					DaclPresent,
	IN		PACL					Dacl OPTIONAL,
	IN		BOOLEAN					DaclDefaulted);

NTSYSAPI NTSTATUS NTAPI RtlSetSaclSecurityDescriptor(
	IN OUT	PSECURITY_DESCRIPTOR	SecurityDescriptor,
	IN		BOOLEAN					SaclPresent,
	IN		PACL					Sacl OPTIONAL,
	IN		BOOLEAN					SaclDefaulted);

#ifdef _M_X64
NTSYSAPI BOOLEAN NTAPI RtlAddFunctionTable(
	IN		PRUNTIME_FUNCTION		FunctionTable,
	IN		ULONG					EntryCount,
	IN		ULONGLONG				BaseAddress);
#endif

#pragma endregion

#pragma region Ldr* function declarations
NTSYSAPI NTSTATUS NTAPI LdrRegisterDllNotification(
	IN	ULONG							Flags,					// Unused. Must be zero.
	IN	PLDR_DLL_NOTIFICATION_FUNCTION	NotificationFunction,	// function called when any DLL is loaded/unloaded
	IN	PVOID							Context OPTIONAL,		// opaque data passed to the notification function
	OUT	PVOID							*Cookie);				// Store a opaque cookie which you can pass to unregister

NTSYSAPI NTSTATUS NTAPI LdrUnregisterDllNotification(
	IN	PVOID	Cookie);

NTSYSAPI NTSTATUS NTAPI LdrLockLoaderLock(
	IN	ULONG	Flags,
	OUT	PULONG	Disposition OPTIONAL,
	OUT	PPVOID	Cookie);

NTSYSAPI NTSTATUS NTAPI LdrUnlockLoaderLock(
	IN	ULONG	Flags,
	IN	PVOID	Cookie);

// internally known as RtlQueryImageFileKeyOption.
// https://www.geoffchappell.com/studies/windows/win32/ntdll/api/rtl/rtlexec/queryimagefilekeyoption.htm
NTSYSAPI NTSTATUS NTAPI LdrQueryImageFileKeyOption(
	IN	HANDLE	KeyHandle,
	IN	PCWSTR	Option,
	IN	ULONG	Type,
	OUT	PVOID	Buffer OPTIONAL,
	IN	ULONG	BufferCb,
	OUT	PULONG	BufferCbOut OPTIONAL);

// https://www.geoffchappell.com/studies/windows/win32/ntdll/api/ldrinit/queryimagefileexecutionoptions.htm
NTSYSAPI NTSTATUS NTAPI LdrQueryImageFileExecutionOptions(
	IN	PUNICODE_STRING	ImagePathName OPTIONAL,
	IN	PCWSTR			OptionName,
	IN	ULONG			Type,
	OUT	PVOID			Buffer,
	IN	ULONG			BufferSize,
	OUT	PULONG			ResultSize);

//
// The flags in *DllCharacteristics that I know of are:
// IMAGE_FILE_EXECUTABLE_IMAGE
//   Does the same thing as DONT_RESOLVE_DLL_REFERENCES from LoadLibrary.
// IMAGE_FILE_SYSTEM
//   Same thing as LOAD_IGNORE_CODE_AUTHZ_LEVEL from LoadLibrary
//
// There could be more, and these descriptions could be wrong. Do more research
// if you intend to use these flags.
// 

NTSYSAPI NTSTATUS NTAPI LdrLoadDll(
	IN	PCWSTR				DllPath OPTIONAL,
	IN	PULONG				DllCharacteristics OPTIONAL,
	IN	PCUNICODE_STRING	DllName,
	OUT	PPVOID				DllHandle);

NTSYSAPI NTSTATUS NTAPI LdrUnloadDll(
	IN	PVOID				DllHandle);

NTSYSAPI NTSTATUS NTAPI LdrGetDllHandle(
	IN	PCWSTR				DllPath OPTIONAL,
	IN	PULONG				DllCharacteristics OPTIONAL,
	IN	PCUNICODE_STRING	DllName,
	OUT	PPVOID				DllHandle);

NTSYSAPI NTSTATUS NTAPI LdrGetDllHandleEx(
	IN	ULONG				Flags, // LDR_GET_DLL_HANDLE_EX_*
	IN	PCWSTR				DllPath OPTIONAL,
	IN	PULONG				DllCharacteristics OPTIONAL,
	IN	PCUNICODE_STRING	DllName,
	OUT	PPVOID				DllHandle OPTIONAL); // only optional with LDR_GET_DLL_HANDLE_EX_PIN

// LdrGetDllHandleByName is better than LdrGetDllHandle for internal use.
// The prior two functions do a lot of extra bullshit that you probably don't need.
//
// NB: It is faster to search for a DLL by its base name rather than its full name,
// since the base names are hashed and stored in a hash table. If you use a full
// name then Ldr needs to search the entire loaded module list.
NTSYSAPI NTSTATUS NTAPI LdrGetDllHandleByName(
	IN	PUNICODE_STRING		DllBaseName OPTIONAL, // one or the other must be specified
	IN	PUNICODE_STRING		DllFullName OPTIONAL,
	OUT	PPVOID				DllHandle);

// This function is quite strange and I can't think of a good
// reason to use it. If you are thinking about using it, I strongly
// recommend you to decompile it and look at what it does exactly,
// since the nuances of its operation are too long to explain here.
NTSYSAPI NTSTATUS NTAPI LdrGetDllHandleByMapping(
	IN	PVOID				ViewBase,
	OUT	PPVOID				DllHandle);

NTSYSAPI NTSTATUS NTAPI LdrDisableThreadCalloutsForDll(
	IN	PVOID				DllHandle);

NTSYSAPI NTSTATUS NTAPI LdrGetProcedureAddress(
	IN	PVOID				DllHandle,
	IN	PCANSI_STRING		ProcedureName OPTIONAL,
	IN	ULONG				ProcedureNumber OPTIONAL,
	OUT	PPVOID				ProcedureAddress);

NTSYSAPI NTSTATUS NTAPI LdrGetProcedureAddressEx(
	IN	PVOID				DllHandle,
	IN	PCANSI_STRING		ProcedureName OPTIONAL,
	IN	ULONG				ProcedureNumber OPTIONAL,
	OUT	PPVOID				ProcedureAddress,
	IN	ULONG				Flags); // Takes a flag value of 0 or 1 only. Don't know what it does.

NTSYSAPI NTSTATUS NTAPI LdrFindEntryForAddress(
	IN	PVOID					Address,
	OUT	PPLDR_DATA_TABLE_ENTRY	TableEntry);

NTSYSAPI VOID NTAPI LdrShutdownThread(
	VOID);

NTSYSAPI VOID NTAPI LdrShutdownProcess(
	VOID);

NTSYSAPI NTSTATUS NTAPI LdrOpenImageFileOptionsKey(
	IN	PCUNICODE_STRING	ImageFileName,
	IN	BOOLEAN				Wow64,			// no effect - just set to FALSE
	OUT	PHANDLE				KeyHandle);

NTSYSAPI NTSTATUS NTAPI LdrEnumerateLoadedModules(
	IN	ULONG												Flags,
	IN	PLDR_LOADED_MODULE_ENUMERATION_CALLBACK_FUNCTION	CallbackFunction,
	IN	PVOID												Context OPTIONAL);

//
// Non-Exported Functions - Must manually find, or reimplement.
//

BOOLEAN NTAPI LdrpFindLoadedDllByHandle(
	IN	PVOID					DllHandle,
	OUT	PPLDR_DATA_TABLE_ENTRY	DataTableEntry);

PLDR_DATA_TABLE_ENTRY NTAPI LdrpAllocateDataTableEntry(
	IN	PVOID	DllBase);

#pragma endregion

#pragma region Dbg* function declarations
NTSYSAPI NTSTATUS NTAPI DbgUiConnectToDbg(
	VOID);

NTSYSAPI NTSTATUS NTAPI DbgUiDebugActiveProcess(
	IN	HANDLE	ProcessHandle);

NTSYSAPI ULONG NTAPI DbgPrint(
	IN	PCSTR	Format,
	IN	...);

NTSYSAPI ULONG NTAPI DbgPrintEx(
	IN	ULONG	ComponentId,
	IN	ULONG	Level,
	IN	PCSTR	Format,
	IN	...);
#pragma endregion

#pragma region Function-like Macros

#define WELL_FORMED_UNICODE_STRING(s) ((s) != NULL && !((s)->Length & 1) && !((s)->MaximumLength & 1) && ((s)->Length <= (s)->MaximumLength))
#define VALID_UNICODE_STRING(s) (WELL_FORMED_UNICODE_STRING(s) && (s)->Buffer != NULL && (s)->MaximumLength != 0)

// example: UNICODE_STRING Name = RTL_CONSTANT_STRING(L"\\??\\pipe\\Something");
#define RTL_CONSTANT_STRING(s) { sizeof( s ) - sizeof( (s)[0] ), sizeof( s ), s }

// This macro is compatible with RtlInitUnicodeString when you are initializing
// a UNICODE_STRING using a string literal.
// Initializing local variables at declaration is forbidden by VxKex coding style,
// so use this macro instead of RTL_CONSTANT_STRING whenever possible.
#define RtlInitConstantUnicodeString(UnicodeString, StringLiteral) do { \
	(UnicodeString)->Length = sizeof(StringLiteral) - sizeof((StringLiteral)[0]); \
	(UnicodeString)->MaximumLength = sizeof(StringLiteral); \
	(UnicodeString)->Buffer = StringLiteral; \
} while(0)
#define RtlInitConstantAnsiString RtlInitConstantUnicodeString

#define DECLARE_CONST_UNICODE_STRING(_variablename, _string) \
	const WCHAR _variablename ## _buffer[] = _string; \
	const UNICODE_STRING _variablename = { sizeof(_string) - sizeof(WCHAR), sizeof(_string), (PWSTR) _variablename ## _buffer };

#define DECLARE_GLOBAL_CONST_UNICODE_STRING(_variablename, _string) \
	DECLSPEC_SELECTANY extern UNICODE_STRING CONST _variablename = RTL_CONSTANT_STRING(_string)

#define ARGUMENT_PRESENT(Argument) (!!(Argument))

#ifndef __INTELLISENSE__
#  define ForEachListEntry(pListHead, pListEntry) for (((PLIST_ENTRY) (pListEntry)) = (pListHead)->Flink; ((PLIST_ENTRY) (pListEntry)) != (pListHead); ((PLIST_ENTRY) (pListEntry)) = ((PLIST_ENTRY) (pListEntry))->Flink)
#else
#  define ForEachListEntry(pListHead, pListEntry)
#endif

#define RtlProcessHeap() (NtCurrentPeb()->ProcessHeap)
#define GetProcessHeap RtlProcessHeap
#define HeapAlloc RtlAllocateHeap
#define HeapFree RtlFreeHeap
#define NtCurrentProcess() ((HANDLE) -1)
#define NtCurrentThread() ((HANDLE) -2)
#define GetCurrentProcess NtCurrentProcess

#define RtlAnsiStringToUnicodeSize(AnsiString) (((AnsiString)->Length + sizeof(ANSI_NULL)) * sizeof(WCHAR))
#define RtlUnicodeStringToAnsiSize(UnicodeString) (((UnicodeString)->Length + sizeof(UNICODE_NULL)) / sizeof(WCHAR))
#define RtlInitEmptyUnicodeString(UnicodeString, InitBuffer, BufferCb) \
    ((UnicodeString)->Buffer = (InitBuffer), \
     (UnicodeString)->Length = 0, \
     (UnicodeString)->MaximumLength = (USHORT)(BufferCb))
#define RtlInitEmptyAnsiString(AnsiString, InitBuffer, BufferCb) RtlInitEmptyUnicodeString(AnsiString, InitBuffer, BufferCb)

#define RtlInitEmptyUnicodeStringFromTeb(UnicodeString) \
	((UnicodeString)->Buffer = NtCurrentTeb()->StaticUnicodeBuffer, \
	 (UnicodeString)->Length = 0, \
	 (UnicodeString)->MaximumLength = RTL_FIELD_SIZE(TEB, StaticUnicodeBuffer))
#define RtlInitEmptyAnsiStringFromTeb(AnsiString) RtlInitEmptyUnicodeStringFromTeb(AnsiString)

#define HASH_ENTRY_KEY(x) ((x)->Signature)

#define LdrpCallInitRoutine(InitRoutine, DllHandle, Reason, Context) \
	(InitRoutine)((DllHandle), (Reason), (Context))

#ifdef _M_X64
#  ifdef __INTELLISENSE__
#    define __readgsdword() 0
#  endif
#  define RtlGetLastWin32Error() __readgsdword(0x68)
#  define GetCurrentProcessId() __readgsdword(0x40)
#  define GetCurrentThreadId() __readgsdword(0x48)
#else
#  define RtlGetLastWin32Error() __readfsdword(0x34)
#  define GetCurrentProcessId() __readfsdword(0x20)
#  define GetCurrentThreadId() __readfsdword(0x24)
#endif

#define GetLastError RtlGetLastWin32Error
#define CloseHandle NtClose // not technically the same thing, but whatever

#pragma endregion

#pragma region Inline Functions

FORCEINLINE PPEB NtCurrentPeb(
	VOID)
{
#ifdef _M_X64
#  ifndef __INTELLISENSE__
	return (PPEB) __readgsqword(0x60);
#  endif
#else
	return (PPEB) __readfsdword(0x30);
#endif
}

FORCEINLINE VOID InitializeObjectAttributes(
	OUT	POBJECT_ATTRIBUTES		ObjectAttributes,
	IN	PUNICODE_STRING			ObjectName,
	IN	ULONG					Attributes,
	IN	HANDLE					RootDirectory,
	IN	PSECURITY_DESCRIPTOR	SecurityDescriptor)
{
	ObjectAttributes->Length = sizeof(OBJECT_ATTRIBUTES);
	ObjectAttributes->RootDirectory = RootDirectory;
	ObjectAttributes->Attributes = Attributes;
	ObjectAttributes->ObjectName = ObjectName;
	ObjectAttributes->SecurityDescriptor = SecurityDescriptor;
	ObjectAttributes->SecurityQualityOfService = NULL;
}

// doubly linked list functions

FORCEINLINE VOID InitializeListHead(
	OUT	PLIST_ENTRY ListHead)
{
	ListHead->Flink = ListHead;
	ListHead->Blink = ListHead;
}

FORCEINLINE BOOL IsListEmpty(
	IN	PLIST_ENTRY	ListHead)
{
	return ListHead->Flink == ListHead;
}

FORCEINLINE VOID RemoveEntryList(
	OUT	PLIST_ENTRY	Entry)
{
	PLIST_ENTRY Blink = Entry->Blink;
	PLIST_ENTRY Flink = Entry->Flink;
	Blink->Flink = Flink;
	Flink->Blink = Blink;
}

FORCEINLINE PLIST_ENTRY RemoveHeadList(
	OUT	PLIST_ENTRY ListHead)
{
	PLIST_ENTRY Ret = ListHead->Flink;
	RemoveEntryList(ListHead->Flink);
	return Ret;
}

FORCEINLINE PLIST_ENTRY RemoveTailList(
	OUT	PLIST_ENTRY	ListHead)
{
	PLIST_ENTRY Blink = ListHead->Blink;
	RemoveEntryList(ListHead->Blink);
	return Blink;
}

FORCEINLINE VOID InsertTailList(
	OUT	PLIST_ENTRY ListHead,
	IN	PLIST_ENTRY	Entry)
{
	Entry->Flink = ListHead;
	Entry->Blink = ListHead->Blink;
	ListHead->Blink->Flink = Entry;
	ListHead->Blink = Entry;
}

FORCEINLINE VOID InsertHeadList(
	OUT	PLIST_ENTRY	ListHead,
	IN	PLIST_ENTRY	Entry)
{
	Entry->Flink = ListHead->Flink;
	Entry->Blink = ListHead;
	ListHead->Flink->Blink = Entry;
	ListHead->Flink = Entry;
}

// singly linked list functions

FORCEINLINE VOID PushEntryList(
	OUT	PSINGLE_LIST_ENTRY	ListHead,
	IN	PSINGLE_LIST_ENTRY	Entry)
{
	Entry->Next = ListHead->Next;
	ListHead->Next = Entry;
}

FORCEINLINE PSINGLE_LIST_ENTRY PopEntryList(
	OUT	PSINGLE_LIST_ENTRY	ListHead)
{
	PSINGLE_LIST_ENTRY FirstEntry = ListHead->Next;

	if (FirstEntry) {
		ListHead->Next = FirstEntry->Next;
	}

	return FirstEntry;
}

// hash table functions

FORCEINLINE VOID RtlInitHashTableContext(
	IN OUT	PRTL_DYNAMIC_HASH_TABLE_CONTEXT Context)
{
	Context->ChainHead = NULL;
	Context->PrevLinkage = NULL;
}

FORCEINLINE VOID RtlInitHashTableContextFromEnumerator(
	IN OUT	PRTL_DYNAMIC_HASH_TABLE_CONTEXT		Context,
	IN		PRTL_DYNAMIC_HASH_TABLE_ENUMERATOR	Enumerator)
{
	Context->ChainHead = Enumerator->ChainHead;
	Context->PrevLinkage = Enumerator->HashEntry.Linkage.Blink;
}

FORCEINLINE VOID RtlReleaseHashTableContext(
	IN OUT	PRTL_DYNAMIC_HASH_TABLE_CONTEXT		Context)
{
	return;
}

FORCEINLINE ULONG RtlTotalBucketsHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable)
{
	return HashTable->TableSize;
}

FORCEINLINE ULONG RtlNonEmptyBucketsHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable)
{
	return HashTable->NonEmptyBuckets;
}

FORCEINLINE ULONG RtlEmptyBucketsHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable)
{
	return HashTable->TableSize - HashTable->NonEmptyBuckets;
}

FORCEINLINE ULONG RtlTotalEntriesHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable)
{
	return HashTable->NumEntries;
}

FORCEINLINE ULONG RtlActiveEnumeratorsHashTable(
	IN		PRTL_DYNAMIC_HASH_TABLE				HashTable)
{
	return HashTable->NumEnumerators;
}

#pragma endregion