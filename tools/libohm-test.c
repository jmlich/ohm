/*
 * Copyright (C) 2007 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <string.h>
#include <unistd.h>
#include <glib.h>

#include <libohm.h>

/**
 * main:
 **/
int
main (int argc, char *argv[])
{
	LibOhm *ctx;
	gboolean ret;
	gint value;
	gchar *version = NULL;
	GError *error;

#if (GLIB_MAJOR_VERSION <= 2) && (GLIB_MINOR_VERSION < 36)
	g_type_init ();
#endif

	g_debug ("Creating ctx");
	ctx = libohm_new ();
	error = NULL;
	ret = libohm_connect (ctx, &error);
	if (ret == FALSE) {
		g_error ("failed to connect: %s", error->message);
		g_error_free (error);
	}

	ret = libohm_server_get_version (ctx, &version, NULL);
	g_debug ("version=%s", version);
	g_free (version);
	g_debug ("ret=%i", ret);

	ret = libohm_keystore_set_key (ctx, "backlight.value_idle", 999, NULL);
	g_debug ("ret=%i", ret);

	ret = libohm_keystore_get_key (ctx, "backlight.value_idle", &value, NULL);
	g_debug ("ret=%i, value=%i", ret, value);

	g_object_unref (ctx);

	return 0;
}
