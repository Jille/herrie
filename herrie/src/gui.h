/*
 * Copyright (c) 2006 Ed Schouten <ed@fxq.nl>
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
 *
 * $Id: gui.h 1043 2006-12-21 17:10:37Z ed $
 */
/**
 * @file gui.h
 */

#ifndef _GUI_H_
#define _GUI_H_

#include <glib.h>

#include "audio.h"

/**
 * @brief Initialize the curses GUI.
 */
void gui_draw_init_pre(void);
/**
 * @brief Initialize trailing GUI components that can only be
 *        initialized after initializing locks and chroot()'ing.
 */
void gui_draw_init_post(void);
/**
 * @brief Destroy the curses GUI.
 */
void gui_draw_destroy(void);

/**
 * @brief Mask certain signals that are only need by the GUI. Call this
 *        function right after starting a new thread.
 */
void gui_input_sigmask(void);
/**
 * @brief Read commands from the keyboard. Function terminates when user
 *        quits the application.
 */
void gui_input_loop(void);

/**
 * @brief Update the text in the message bar.
 */
void gui_msgbar_update(const char *msg, int prio, int cursor);
/**
 * @brief Show a message in the message bar that will be overwritten
 *        when another message is show.
 */
#define gui_msgbar_warn(msg)	gui_msgbar_update((msg), 0, 0)
/**
 * @brief Show a message in the message bar that will only be
 *        overwritten by other messages with this priority. This
 *        routine will also unhide the cursor and show it right after
 *        the message.
 */
#define gui_msgbar_ask(msg)	gui_msgbar_update((msg), 1, 1)

/**
 * @brief Set the name of the song and time showed in the status bar
 */
void gui_playq_song_update(struct audio_file *fd, int timeonly);
/**
 * @brief Adjust the cursor and the viewport offset of the playlist
 *        right before the removal of the actual entry.
 */
void gui_playq_notify_pre_removal(unsigned int index);
/**
 * @brief Adjust the cursor and the viewport offset of the playlist
 *        right after the insertion of the actual entry.
 */
void gui_playq_notify_post_insertion(unsigned int index);
/**
 * @brief Adjust the cursor and the viewport offset of the playlist
 *        right after the randomization of the playlist.
 */
void gui_playq_notify_post_randomization(void);
/**
 * @brief Redraw the playlist, as the manipulation of the playlist is
 *        finished.
 */
void gui_playq_notify_done(void);

#endif /* !_GUI_H_ */
