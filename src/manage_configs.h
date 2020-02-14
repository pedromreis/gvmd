/* GVM
 * $Id$
 * Description: GVM management layer: Config headers exported from layer
 *
 * Authors:
 * Matthew Mundell <matthew.mundell@greenbone.net>
 *
 * Copyright:
 * Copyright (C) 2019 Greenbone Networks GmbH
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _GVMD_MANAGE_CONFIGS_H
#define _GVMD_MANAGE_CONFIGS_H

#include "iterator.h"
#include "manage_get.h"
#include "manage_preferences.h"

typedef long long int config_t;

preference_t *
get_nvt_preference_by_id (const char *,
                          const char *,
                          const char *,
                          const char *,
                          const char *);

/**
 * @brief An NVT selector.
 */
typedef struct
{
  char *name;           ///< Name of NVT selector.
  char *type;           ///< Name of NVT selector.
  int include;          ///< Whether family/NVT is included or excluded.
  char *family_or_nvt;  ///< Family or NVT that this selector selects.
} nvt_selector_t;

int
create_config (const char*, const char*, int, const char*, const array_t*,
               const array_t*, const char*, const char*, config_t*, char**);

int
create_config_from_scanner (const char*, const char *, const char *,
                            const char *, char **);

int
copy_config (const char*, const char*, const char *, const char *, config_t*);

int
delete_config (const char*, int);

int
sync_config (const char *);

gboolean
find_config_with_permission (const char*, config_t*, const char *);

char *
config_uuid (config_t);

int
config_type (config_t);

char *
config_nvt_timeout (config_t, const char *);

void
init_user_config_iterator (iterator_t*, config_t, int, int, const char*);

int
init_config_iterator (iterator_t*, const get_data_t*);

const char*
config_iterator_nvt_selector (iterator_t*);

int
config_iterator_nvt_count (iterator_t*);

int
config_iterator_family_count (iterator_t*);

int
config_iterator_nvts_growing (iterator_t*);

int
config_iterator_type (iterator_t*);

int
config_iterator_families_growing (iterator_t*);

int
config_iterator_scanner_trash (iterator_t*);

const char*
config_iterator_usage_type (iterator_t*);

char*
config_nvt_selector (config_t);

int
config_in_use (config_t);

int
config_writable (config_t);

int
config_count (const get_data_t *);

int
trash_config_in_use (config_t);

int
trash_config_writable (config_t);

int
trash_config_readable_uuid (const gchar *);

int
config_families_growing (config_t);

int
config_nvts_growing (config_t);

int
manage_set_config_preference (const gchar *, const char*, const char*,
                              const char*);

void
init_config_preference_iterator (iterator_t *, config_t);

const char*
config_preference_iterator_name (iterator_t *);

const char*
config_preference_iterator_value (iterator_t *);

const char*
config_preference_iterator_type (iterator_t *);

const char*
config_preference_iterator_default (iterator_t *);

const char*
config_preference_iterator_hr_name (iterator_t *);

int
manage_set_config (const gchar *, const char*, const char *, const char *);

int
manage_set_config_nvts (const gchar *, const char*, GPtrArray*);

int
manage_set_config_families (const gchar *, GPtrArray*, GPtrArray*, GPtrArray*,
                            int);

void
init_config_timeout_iterator (iterator_t*, config_t);

const char*
config_timeout_iterator_oid (iterator_t *);

const char*
config_timeout_iterator_nvt_name (iterator_t *);

const char*
config_timeout_iterator_value (iterator_t *);

void
update_config_preference (const char *, const char *, const char *,
                          const char *, gboolean);

void
manage_sync_configs ();

#endif /* not _GVMD_MANAGE_CONFIGS_H */
