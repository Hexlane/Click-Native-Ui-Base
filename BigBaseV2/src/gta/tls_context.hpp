#pragma once
#include <intrin.h>
#include "fwddec.hpp"


#define DEFINE_RAGE_RTTI(className)    private:\
								virtual void* _0x00() = 0;\
								virtual void* _0x08() = 0;\
								virtual uint32_t _0x10() = 0;\
								virtual className* _0x18(void*) = 0;\
								virtual bool _0x20(void*) = 0;\
								virtual bool _0x28(void**) = 0;\
								virtual void destructor() = 0;\
								public:
namespace rage
{
    class sysMemAllocator
    {
    public:
        DEFINE_RAGE_RTTI(rage::sysMemAllocator);
        virtual void SetQuitOnFail(bool) = 0;
        virtual void* Allocate(std::size_t size, std::size_t align, int subAllocator) = 0;
        virtual void* TryAllocate(std::size_t size, std::size_t align, int subAllocator) = 0;
        virtual void Free(void* pointer) = 0;
        virtual void TryFree(void* pointer) = 0;
        virtual void Resize(void* pointer, std::size_t size) = 0;
        virtual sysMemAllocator* GetAllocator(int allocator) const = 0;
        virtual sysMemAllocator* GetAllocator(int allocator) = 0;
        virtual sysMemAllocator* GetPointerOwner(void* pointer) = 0;
        virtual std::size_t GetSize(void* pointer) const = 0;
        virtual std::size_t GetMemoryUsed(int memoryBucket) = 0;
        virtual std::size_t GetMemoryAvailable() = 0;

    };
#pragma pack(push, 1)
    class tlsContext
    {
    public:
        char gap0[8884];
        std::uint8_t m_unk_byte; // 0x22B4
        char gapB5[3];
        sysMemAllocator* m_allocator; // 0x22B8
        sysMemAllocator* m_allocator2; // 0x22C0 - Same as 0x22B8
        sysMemAllocator* m_allocator3; // 0x22C8 - Same as 0x22B8
        uint32_t m_console_smth; // 0x22D0
        char gapD4[188];
        uint64_t m_unk; // 0x2390
        char gap198[1720];
        rage::scrThread* m_script_thread; // 0x2A50
        bool m_is_script_thread_active; // 0x2A58

#if _WIN32
        static tlsContext* get()
        {
            constexpr std::uint32_t TlsIndex = 0x0;
            return *reinterpret_cast<tlsContext**>(__readgsqword(0x58) + TlsIndex);
        }
#endif
    };
    static_assert(sizeof(tlsContext) == 0x2A59);
#pragma pack(pop)
}
