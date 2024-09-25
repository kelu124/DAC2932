//!
//! \file       main.c
//! \date       2024-09-24
//!
//! \brief      idac vdac entry.
//!

//---------------------------------------------------------------------------
// INCLUDES
//--------------------------------------------------------------------------
#include "idac/idac.h"
#include "vdac/vdac.h"

//---------------------------------------------------------------------------
// MAIN FUNCTION
//---------------------------------------------------------------------------

void core1_entry()
{

    while (true)
    {
        vdac();
    }
}

int main()
{
    stdio_init_all();
    sleep_ms(100);
    idac_init();
    sleep_ms(100);
    vdac_init();
    sleep_ms(100);
    multicore_launch_core1(core1_entry);
    while (true)
    {
        idac();
    }
}
