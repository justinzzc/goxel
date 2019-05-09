/* Goxel 3D voxels editor
 *
 * copyright (c) 2019 Guillaume Chereau <guillaume@noctua-software.com>
 *
 * Goxel is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.

 * Goxel is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.

 * You should have received a copy of the GNU General Public License along with
 * goxel.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "goxel.h"

void gui_view_panel(void)
{
    // XXX: I don't like to use this array.
    const struct {
        uint8_t    *color;
        const char *label;
    } COLORS[] = {
        {goxel.back_color, "Back color"},
        {goxel.grid_color, "Grid color"},
        {goxel.image_box_color, "Box color"},
    };
    int i;
    bool v;

    for (i = 0; i < (int)ARRAY_SIZE(COLORS); i++) {
        gui_color_small(COLORS[i].label, COLORS[i].color);
    }
    gui_checkbox("Hide box", &goxel.hide_box, NULL);

    gui_group_begin("Effects");
    v = goxel.view_effects & EFFECT_GRID;
    if (gui_selectable("Grid", &v, NULL, -1)) {
        set_flag(&goxel.view_effects, EFFECT_GRID, v);
        if (v) set_flag(&goxel.view_effects, EFFECT_EDGES, false);
    }
    v = goxel.view_effects & EFFECT_EDGES;
    if (gui_selectable("Edges", &v, NULL, -1)) {
        set_flag(&goxel.view_effects, EFFECT_EDGES, v);
        if (v) set_flag(&goxel.view_effects, EFFECT_GRID, false);
    }
    gui_group_end();
}
