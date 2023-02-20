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

#include <config.h>
#include <glib.h>
#include <girepository.h>

#include "flasher-plugins-engine.h"

struct _FlasherPluginsEngine
{
  PeasEngine parent_instance;

  GSettings *plugin_settings;
};

G_DEFINE_TYPE(FlasherPluginsEngine, flasher_plugins_engine, PEAS_TYPE_ENGINE)

static FlasherPluginsEngine *default_engine = NULL;

static void
flasher_plugins_engine_init(FlasherPluginsEngine *engine)
{
  engine->plugin_settings = g_settings_new("com.github.berkuteagle.flasher.plugins");

  g_irepository_require(g_irepository_get_default (), "Peas", "1.0", 0, NULL);
  g_irepository_require(g_irepository_get_default (), "PeasGtk", "1.0", 0, NULL);

  peas_engine_add_search_path (PEAS_ENGINE (engine),
                               g_build_filename(LIBDIR,
                                                "flasher",
                                                NULL),
                               g_build_filename(DATADIR,
                                                "flasher",
                                                "plugins",
                                                NULL));

  g_settings_bind(engine->plugin_settings,
                  "active-plugins",
                  engine,
                  "loaded-plugins",
                  G_SETTINGS_BIND_DEFAULT);
}

static void
flasher_plugins_engine_dispose(GObject *object)
{
  FlasherPluginsEngine *engine = FLASHER_PLUGINS_ENGINE (object);

  g_clear_object(&engine->plugin_settings);

  G_OBJECT_CLASS(flasher_plugins_engine_parent_class)->dispose(object);
}

static void
flasher_plugins_engine_class_init(FlasherPluginsEngineClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->dispose = flasher_plugins_engine_dispose;
}

FlasherPluginsEngine *
flasher_plugins_engine_get_default (void)
{
  if (default_engine == NULL)
  {
    default_engine = FLASHER_PLUGINS_ENGINE (g_object_new (FLASHER_TYPE_PLUGINS_ENGINE,
                                                           NULL));

    g_object_add_weak_pointer (G_OBJECT (default_engine),
                                 (gpointer) &default_engine);
  }

  return default_engine;
}

