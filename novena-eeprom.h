#ifndef __NOVENA_EEPROM_H__
#define __NOVENA_EEPROM_H__

#include <stdint.h>

#define NOVENA_SIGNATURE "Novena"
#define NOVENA_VERSION 1

/*
 * For structure documentation, see:
 * http://www.kosagi.com/w/index.php?title=Novena/EEPROM
 */
struct novena_eeprom_data {
	uint8_t		signature[6];	/* 'Novena' */
	uint8_t		version;	/* 1 */
	uint8_t		reserved1;
	uint32_t	serial;
	uint8_t		mac[6];
	uint16_t	features;
} __attribute__((__packed__));

struct feature {
        uint32_t        flags;
        char            *name;
	char		*descr;
};

struct feature features[] = {
	{
		.name  = "es8328",
		.flags = 0x01,
		.descr = "ES8328 audio codec",
	},
	{
		.name  = "pmb",
		.flags = 0x02,
		.descr = "Power Management Board",
	},
	{
		.name  = "retina",
		.flags = 0x04,
		.descr = "Retina-class dual-LVDS display",
	},
	{
		.name  = "pixelqi",
		.flags = 0x08,
		.descr = "PixelQi LVDS display",
	},
	{
		.name  = "pcie",
		.flags = 0x10,
		.descr = "PCI Express support",
	},
	{
		.name  = "gbit",
		.flags = 0x20,
		.descr = "Gigabit Ethernet",
	},
	{} /* Sentinal */
};


#endif /* __NOVENA_EEPROM_H__ */
