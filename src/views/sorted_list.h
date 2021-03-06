/* -*- Mode: C; tab-width: 4; c-basic-offset: 4; indent-tabs-mode: nil -*- */

/**
 * @copyright 2013 Couchbase, Inc.
 *
 * @author Filipe Manana  <filipe@couchbase.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 **/

#ifndef _SORTED_LIST_H
#define _SORTED_LIST_H

#include <stddef.h>
#include <libcouchstore/visibility.h>


#ifdef __cplusplus
extern "C" {
#endif


/** Returns:
 *  negative integer if a < b, 0 if a == b, positive integer if a > b
 **/
typedef int (*sorted_list_cmp_t)(const void *a, const void *b);


LIBCOUCHSTORE_API void *sorted_list_create(sorted_list_cmp_t less_fun);

LIBCOUCHSTORE_API int  sorted_list_add(void *list, const void *elem, size_t elem_size);

LIBCOUCHSTORE_API void *sorted_list_get(const void *list, const void *elem);

LIBCOUCHSTORE_API void sorted_list_remove(void *list, const void *elem);

LIBCOUCHSTORE_API int  sorted_list_size(const void *list);

LIBCOUCHSTORE_API void sorted_list_free(void *list);

LIBCOUCHSTORE_API void *sorted_list_iterator(const void *list);

LIBCOUCHSTORE_API void *sorted_list_next(void *iterator);

LIBCOUCHSTORE_API void *sorted_list_free_iterator(void *iterator);


#ifdef __cplusplus
}
#endif

#endif
