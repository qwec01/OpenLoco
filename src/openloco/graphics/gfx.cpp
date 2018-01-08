#include "../ui.h"
#include "gfx.h"

namespace openloco::gfx
{
    loco_global<drawpixelinfo_t, 0x0050B884> screen_dpi;

    // 0x0044733C
    void load_g1()
    {
        LOCO_CALLPROC_X(0x0044733C);
    }

    // 0x00447485
    // edi: dpi
    // ebp: fill
    void clear(drawpixelinfo_t &dpi, uint32_t fill)
    {
        registers regs;
        regs.edi = (int32_t)&dpi;
        regs.ebp = (int32_t)fill;
        LOCO_CALLPROC_X(0x00447485, regs);
    }

    // 0x004CD406
    void invalidate_screen()
    {
        set_dirty_blocks(0, 0, ui::width(), ui::height());
    }

    // 0x004C5C69
    void set_dirty_blocks(int32_t left, int32_t top, int32_t right, int32_t bottom)
    {
        registers regs;
        regs.ax = left;
        regs.bx = top;
        regs.dx = right;
        regs.bp = bottom;
        LOCO_CALLPROC_X(0x004C5C69, regs);
    }
}