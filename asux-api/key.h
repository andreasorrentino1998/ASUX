/**
* ASUX: A lightweight C++ reactive framework for building terminal-based applications. 
*
* Authors:
* © 2024 - Andrea Sorrentino
* 
* ASUX is free software: you can redistribute it and/or modify it under the
* terms of the GNU General Public License as published by the Free Software Foundation,
* either version 3 of the License, or (at your option) any later version.
*  
* ASUX is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
* PURPOSE. See the GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License along with ASUX.
* If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KEY_H
#define KEY_H

namespace ASUX {

enum ASCIIKey {
    Null = 0,
    Backspace = 8,
    HorizontalTab = 9,
    LineFeed = 10,
    VerticalTab = 11,
    CarriageReturn = 13,
    ShiftOut = 14,
    ShifIn = 15,
    Cancel = 24,
    ESC = 27,
    Space = 32,
    ExclamationMark = 33,

    N0 = 48, N1, N2, N3, N4, N5, N6, N7, N8, N9,

    Semicolon = 59,
    LessThan,
    Equal,
    GreaterThan,
    QuestionMark,

    A = 65, B, C, D, E, F, G, H, I, 
    J, K, L, M, N, O, P, Q, R, S,
    T, U, V, W, X, Y, Z,
    LeftBracket,
    Backslash,
    RightBracket,
    Caret,
    Underscore,
    Backtick,
    a = 97, b, c, d, e, f, g, h, i,
    j, k, l, m, n, o, p, q, r, s,
    t, u, v, w, x, y, z,
    LeftBrace,
    VerticalBar,
    RightBrace,
    Tilde,
    Delete,
};

enum class Key {
    Null = 0,
    Backspace = 8,
    ESC = 27,
    Space = 32,
    N0 = 48, N1, N2, N3, N4, N5, N6, N7, N8, N9,
    A = 65, B, C, D, E, F, G, H, I, 
    J, K, L, M, N, O, P, Q, R, S,
    T, U, V, W, X, Y, Z,
    a = 97, b, c, d, e, f, g, h, i,
    j, k, l, m, n, o, p, q, r, s,
    t, u, v, w, x, y, z,
    Up, Down, Left, Right, Enter,
    Any = 255
};

}

#endif