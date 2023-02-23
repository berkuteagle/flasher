/* MIT License
 *
 * Copyright (c) 2023 Anton Snigirev
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * SPDX-License-Identifier: MIT
 */

#include <flasher/flasher-object.h>

#include "config.h"

#include "flasher-application.h"
#include "flasher-window.h"

typedef struct
{
  FlasherObject        *flasher;
} FlasherApplicationPrivate;

struct _FlasherApplication
{
  AdwApplication parent_instance;
};

G_DEFINE_TYPE_WITH_PRIVATE (FlasherApplication, flasher_application, ADW_TYPE_APPLICATION)

FlasherApplication *
flasher_application_new (const char *application_id, GApplicationFlags flags)
{
  g_return_val_if_fail (application_id != NULL, NULL);

  return g_object_new (FLASHER_TYPE_APPLICATION, "application-id", application_id, "flags", flags, NULL);
}

static void
flasher_application_activate (GApplication *app)
{
  GtkWindow *window;

  g_assert (FLASHER_IS_APPLICATION (app));

  window = gtk_application_get_active_window (GTK_APPLICATION (app));
  if (window == NULL)
    window = g_object_new (FLASHER_TYPE_WINDOW, "application", app, NULL);

  gtk_window_present (window);
}

static void
flasher_application_startup (GApplication *app)
{
  FlasherApplicationPrivate *priv;

  priv = flasher_application_get_instance_private (FLASHER_APPLICATION (app));

  G_APPLICATION_CLASS (flasher_application_parent_class)->startup (app);

  priv->flasher    = flasher_object_new ();
}

static void
flasher_application_class_init (FlasherApplicationClass *klass)
{
  GApplicationClass *app_class = G_APPLICATION_CLASS (klass);

  app_class->startup  = flasher_application_startup;
  app_class->activate = flasher_application_activate;
}

static void
flasher_application_about_action (GSimpleAction *action, GVariant *parameter, gpointer user_data)
{
  static const char  *developers[] = { "Anton Snigirev", NULL };
  FlasherApplication *self         = user_data;
  GtkWindow          *window       = NULL;

  g_assert (FLASHER_IS_APPLICATION (self));

  window = gtk_application_get_active_window (GTK_APPLICATION (self));

  adw_show_about_window (window, "application-name", "flasher", "application-icon", "com.github.berkuteagle.flasher",
                         "developer-name", "Anton Snigirev", "version", "0.1.0", "developers", developers, "copyright",
                         "© 2023 Anton Snigirev", NULL);
}

static void
flasher_application_quit_action (GSimpleAction *action, GVariant *parameter, gpointer user_data)
{
  FlasherApplication *self = user_data;

  g_assert (FLASHER_IS_APPLICATION (self));

  g_application_quit (G_APPLICATION (self));
}

static const GActionEntry app_actions[] = {
  {"quit",   flasher_application_quit_action },
  { "about", flasher_application_about_action},
};

static void
flasher_application_init (FlasherApplication *self)
{
  g_action_map_add_action_entries (G_ACTION_MAP (self), app_actions, G_N_ELEMENTS (app_actions), self);
  gtk_application_set_accels_for_action (GTK_APPLICATION (self), "app.quit", (const char *[]){ "<primary>q", NULL });
}
