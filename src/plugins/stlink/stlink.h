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

#include <flasher/flasher-device-extension.h>
#include <libpeas/peas.h>

G_BEGIN_DECLS

#define FLASHER_TYPE_STLINK (flasher_stlink_get_type ())

G_DECLARE_FINAL_TYPE (FlasherSTLink, flasher_stlink, FLASHER, STLINK, PeasExtensionBase)

struct _FlasherSTLink
{
  PeasExtensionBase parent_instance;

  FlasherObject *flasher;
};

enum
{
  PROP_FLASHER = 1,
  N_PROPERTIES
};

void flasher_stlink_device_extension_activate (FlasherDeviceExtension *extension);

G_MODULE_EXPORT void peas_register_types (PeasObjectModule *module);

G_END_DECLS

