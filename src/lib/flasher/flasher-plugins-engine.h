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

#pragma once

#include <glib.h>
#include <libpeas/peas.h>

G_BEGIN_DECLS

#define FLASHER_TYPE_PLUGINS_ENGINE (flasher_plugins_engine_get_type ())
G_DECLARE_FINAL_TYPE (FlasherPluginsEngine, flasher_plugins_engine, FLASHER, PLUGINS_ENGINE, PeasEngine)

FlasherPluginsEngine *flasher_plugins_engine_get_default (void);
void                  flasher_plugins_engine_shut_down (FlasherPluginsEngine *self);

G_END_DECLS

