/**
 * @file hal.h
 * @brief OHM HAL plugin header file
 * @author ismo.h.puustinen@nokia.com
 *
 * Copyright (C) 2008, Nokia. All rights reserved.
 */

#ifndef HAL_H
#define HAL_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#include <glib.h>
#include <glib-object.h>
#include <dbus/dbus.h>

#include <libhal.h>

#include <ohm-plugin.h>
#include <dres/dres.h>
#include <dres/variables.h>
#include <prolog/ohm-fact.h>

typedef struct _hal_plugin {
    LibHalContext *hal_ctx;
    DBusConnection *c;
    GSList *modified_properties;
    OhmFactStore *fs;
} hal_plugin;


hal_plugin * init_hal(DBusConnection *c, int flag_hal, int flag_facts);
void deinit_hal(hal_plugin *plugin);

#endif

/*
 * Local Variables:
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 * vim:set expandtab shiftwidth=4:
 */
