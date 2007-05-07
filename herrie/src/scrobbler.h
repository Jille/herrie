/*
 * Copyright (c) 2006-2007 Ed Schouten <ed@fxq.nl>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
/**
 * @file scrobbler.h
 * @brief AudioScrobbler submission.
 */

#ifndef _SCROBBLER_H_
#define _SCROBBLER_H_

struct audio_file;

#ifdef BUILD_SCROBBLER
/**
 * @brief Initialize locking for the AudioScrobbler submission thread.
 */
void scrobbler_init(void);
/**
 * @brief Spawn an AudioScrobbler submission thread.
 */
void scrobbler_spawn(void);
/**
 * @brief Shut down the AudioScrobbler submission thread.
 */
void scrobbler_shutdown(void);
/**
 * @brief Notify the AudioScrobbler thread that a read from the file has
 *        been performed.
 */
void scrobbler_notify_read(struct audio_file *fd, int eof);
/**
 * @brief Notify the AudioScrobbler thread that a seek on the file has
 *        been performed.
 */
void scrobbler_notify_seek(struct audio_file *fd);
#endif /* BUILD_SCROBBLER */

#endif /* !_SCROBBLER_H_ */
