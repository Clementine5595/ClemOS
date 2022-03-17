#include <libk/stdint.h>

struct gdt_entry_struct
{
   uint16_t limit_low;           // Младшие 16 битов граничного значения limit.
   uint16_t base_low;            // Младшие 16 битов адресной базы.
   uint8_t  base_middle;         // Следующие 8 битов адресной базы.
   uint8_t  access;              // Флаги доступа, определяющие в каком кольце можно использовать этот сегмент.
   uint8_t  granularity;
   uint8_t  base_high;           // Последние 8 битов адресной базы.
} __attribute__((packed));

struct gdt_ptr_struct
{
   uint16_t limit;               // Верхние 16 битов всех предельных значений селектора.
   uint32_t base;                // Адрес первой структуры gdt_entry_t.
}
 __attribute__((packed));
 
typedef struct gdt_ptr_struct gdt_ptr_t; 

typedef struct gdt_entry_struct gdt_entry_t;

void init_descriptor_tables(); 