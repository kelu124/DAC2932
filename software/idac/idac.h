//!
//! \file       idac.h
//! \date       2024-09-24
//!
//! \brief      idac pio.
//!

#ifndef IDAC_H
#define IDAC_H

//---------------------------------------------------------------------------
// INCLUDES
//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/dma.h"
#include "hardware/clocks.h"
//---------------------------------------------------------------------------
// CONSTANTS
//---------------------------------------------------------------------------

#define PIN_BASE 0
#define ADC_CLK 80000000
#define CSV_COUNT 8192

//---------------------------------------------------------------------------
// DAC INIT FUNCTION
//---------------------------------------------------------------------------
void idac_init();

//---------------------------------------------------------------------------
// DAC DMA FUNCTION
//---------------------------------------------------------------------------
void idac_dma();

//---------------------------------------------------------------------------
// DAC OUT FUNCTION
//---------------------------------------------------------------------------
void idac_out();

//---------------------------------------------------------------------------
// DAC MAIN FUNCTION
//---------------------------------------------------------------------------
void idac();

//---------------------------------------------------------------------------
// END OF FILE
//---------------------------------------------------------------------------

#endif