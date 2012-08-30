#ifndef SQUID_STORE_REBUILD_H_
#define SQUID_STORE_REBUILD_H_
/*
 * DEBUG: section 
 * AUTHOR: 
 *
 * SQUID Web Proxy Cache          http://www.squid-cache.org/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from
 *  the Internet community; see the CONTRIBUTORS file for full
 *  details.   Many organizations have provided support for Squid's
 *  development; see the SPONSORS file for full details.  Squid is
 *  Copyrighted (C) 2001 by the Regents of the University of
 *  California; see the COPYRIGHT file for full details.  Squid
 *  incorporates software developed and/or copyrighted by other
 *  sources; see the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

extern void storeRebuildStart(void);
extern void storeRebuildComplete(struct _store_rebuild_data *);
extern void storeRebuildProgress(int sd_index, int total, int sofar);

/// loads entry from disk; fills supplied memory buffer on success
extern bool storeRebuildLoadEntry(int fd, int diskIndex, MemBuf &buf, struct _store_rebuild_data &counts);
/// parses entry buffer and validates entry metadata; fills e on success
extern bool storeRebuildParseEntry(MemBuf &buf, StoreEntry &e, cache_key *key, struct _store_rebuild_data &counts, uint64_t expectedSize);
/// checks whether the loaded entry should be kept; updates counters
extern bool storeRebuildKeepEntry(const StoreEntry &e, const cache_key *key, struct _store_rebuild_data &counts);



#endif /* SQUID_STORE_REBUILD_H_ */
