 /*
  * UAE - The Un*x Amiga Emulator
  *
  * Interface to the Tcl/Tk GUI
  *
  * Copyright 1996 Bernd Schmidt
  */

#ifndef UAE_GUI_H
#define UAE_GUI_H

#include "uae/types.h"

extern int gui_init (void);
extern int gui_update (void);
extern void gui_exit (void);
extern void gui_led (int, int, int);
extern void gui_filename (int, const TCHAR *);
extern void gui_flicker_led (int, int, int);
extern unsigned int gui_ledstate;
extern void gui_display (int shortcut);

extern bool no_gui;

#define HDLED_OFF		0
#define HDLED_READ		1
#define HDLED_WRITE		2

#define LED_CD_ACTIVE 1
#define LED_CD_ACTIVE2 2
#define LED_CD_AUDIO 4

#define LED_NONE 0
#define LED_POWER 1
#define LED_DF0 2
#define LED_DF1 3
#define LED_DF2 4
#define LED_DF3 5
#define LED_DFs 6         // Define for any DF* access
#define LED_HD 7
#define LED_CD 8
#define LED_FPS 9
#define LED_CPU 10
#define LED_SND 11
#define LED_MD 12
#define LED_MAX 13

struct gui_info
{
    bool drive_motor[4];    /* motor on off */
    uae_u8 drive_track[4];    /* rw-head track */
    bool drive_writing[4];  /* drive is writing */
    bool drive_disabled[4];	/* drive is disabled */
    bool powerled;          /* state of power led */
    uae_s8 drive_side;				/* floppy side */
    uae_s8 hd;			          /* harddrive */
    uae_s8 cd;			          /* CD */
    int cpu_halted;
    int fps, idle;
    int sndbuf, sndbuf_status;
    TCHAR df[4][256];		    /* inserted image */
    uae_u32 crc32[4];		    /* crc32 of image */
};
#define NUM_LEDS (LED_MAX)
#define VISIBLE_LEDS 6

extern struct gui_info gui_data;

void notify_user (int msg);
int translate_message (int msg, TCHAR *out);

typedef enum {
	NUMSG_NEEDEXT2, // 0
	NUMSG_NOROM,
	NUMSG_NOROMKEY,
	NUMSG_KSROMCRCERROR,
	NUMSG_KSROMREADERROR,
	NUMSG_NOEXTROM, // 5
	NUMSG_MODRIP_NOTFOUND,
	NUMSG_MODRIP_FINISHED,
	NUMSG_MODRIP_SAVE,
	NUMSG_KS68EC020,
	NUMSG_KS68020, // 10
	NUMSG_KS68030,
	NUMSG_ROMNEED,
	NUMSG_EXPROMNEED,
	NUMSG_NOZLIB,
	NUMSG_STATEHD, // 15
	NUMSG_NOCAPS,
	NUMSG_OLDCAPS,
	NUMSG_KICKREP,
	NUMSG_KICKREPNO,
	NUMSG_KS68030PLUS, // 20
	NUMSG_NO_PPC,
	NUMSG_UAEBOOTROM_PPC,
	NUMSG_LAST
} notify_user_msg;

#endif /* UAE_GUI_H */
