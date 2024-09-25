//!
//! \file       vdac.c 
//! \date       2024-09-24
//!
//! \brief      vdac spi bit banging.
//!

//---------------------------------------------------------------------------
// INCLUDES
//---------------------------------------------------------------------------

#include "vdac.h"

//---------------------------------------------------------------------------
// DAC INIT FUNCTION
//---------------------------------------------------------------------------
void vdac_init()
{
    gpio_init(PIN_SCLK);
    gpio_init(PIN_DIN);
    gpio_init(PIN_SYNC);
    gpio_set_dir(PIN_SCLK, GPIO_OUT);
    gpio_set_dir(PIN_DIN, GPIO_OUT);
    gpio_set_dir(PIN_SYNC, GPIO_OUT);
    gpio_put(PIN_SCLK, 0);
    gpio_put(PIN_DIN, 0);
    gpio_put(PIN_SYNC, 1);
}

//---------------------------------------------------------------------------
// DAC SPI WRITE FUNCTION
//---------------------------------------------------------------------------
void vdac_spi_write(uint16_t data)
{
    gpio_put(PIN_SYNC, 0);
    for (int16_t bit = 15; bit >= 0; --bit)
    {
        gpio_put(PIN_DIN, (data >> bit) & 1);
        delay_250ns();
        gpio_put(PIN_SCLK, 1);
        delay_250ns();
        gpio_put(PIN_SCLK, 0);
        delay_250ns();
    }
    gpio_put(PIN_SYNC, 1);
}

//---------------------------------------------------------------------------
// VDAC CALIBERATION FUNCTION
//---------------------------------------------------------------------------
void vdac_generate_calibration_signals()
{
    uint16_t value = 0;

    while (value < 4096)
    {
        // VOUT1 Ramp Up
        vdac_spi_write((0x1000) | (value & 0x0FFF));

        // VOUT2 Ramp Down
        vdac_spi_write((0x2000) | ((4095 - value) & 0x0FFF));

        // VOUT3 CLK
        static int toggle = 0;
        if (toggle == 0)
        {
            vdac_spi_write((0x4000) | 0xFFF);
        }
        else
        {
            vdac_spi_write((0x4000) | 0x000);
        }
        toggle = !toggle;

        // VOUT4 Half CLK
        static int half_toggle = 0;
        if (half_toggle == 0)
        {
            vdac_spi_write((0x8000) | 0xFFF);
        }
        else
        {
            vdac_spi_write((0x8000) | 0x000);
        }
        half_toggle = (half_toggle + 1) % 2;

        ++value;

        // sleep_us(100);
    }
}

//---------------------------------------------------------------------------
// DAC WRITE FUNCTION
//---------------------------------------------------------------------------
void vdac_write()
{
    vdac_generate_calibration_signals();
}

//---------------------------------------------------------------------------
// GPIO delays
//---------------------------------------------------------------------------
void delay_250ns()
{
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
    __asm volatile("nop" :);
}

//---------------------------------------------------------------------------
// DAC MAIN FUNCTION
//---------------------------------------------------------------------------
void vdac()
{
    vdac_write();
}

//---------------------------------------------------------------------------
// END OF FILE
//---------------------------------------------------------------------------
