/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 *  Copyright (C) 2005 Takuro Ashie
 *  Copyright (C) 2012 CSSlayer
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __FCITX_ANTHY_KANA_H__
#define __FCITX_ANTHY_KANA_H__

#include "key2kana_base.h"
#include "default_tables.h"
#include "key2kana_table.h"

class AnthyInstance;

class KanaConvertor : public Key2KanaConvertorBase
{
public:
               KanaConvertor      (AnthyInstance    & anthy);
    virtual   ~KanaConvertor      ();

    bool       can_append         (const KeyEvent   & key,
                                   bool               ignore_space = false);
    bool       append             (const KeyEvent   & key,
                                   std::string       & result,
                                   std::string       & pending,
                                   std::string           & raw);
    bool       append             (const std::string     & raw,
                                   std::string       & result,
                                   std::string       & pending);
    void       clear              (void);

    bool       is_pending         (void);
    std::string get_pending        (void);
    std::string flush_pending      (void);
    void       reset_pending      (const std::string & result,
                                   const std::string     & raw);

private:
    AnthyInstance &m_anthy;

    // state
    std::string         m_pending;
};

#endif /* __FCITX_ANTHY_KANA_H__ */
/*
vi:ts=4:nowrap:ai:expandtab
*/
