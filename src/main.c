#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "examples/triangle.h"
#include "examples/rectangle.h"
#include "examples/two_triangles_1.h"
#include "examples/two_triangles_2.h"
#include "examples/two_triangles_3.h"
#include "examples/uniforms.h"
#include "examples/more_attributes.h"
#include "examples/invert_triangle.h"
#include "examples/horizontal_offset.h"
#include "examples/vert_color.h"
#include "examples/smiling_box.h"
#include "examples/transformations.h"
#include "examples/coordinates.h"

int main(int argc, char **argv)
{
    int i = 0;

    int (*render_loop)(void) = NULL;

    while (argv[i] != NULL)
    {
        if (!strcmp(argv[i], "--example"))
        {
            if (argv[++i] == NULL)
            {
                break;
            }

            if (!strcmp(argv[i], "triangle"))
            {
                render_loop = triangle_lesson;
            }
            else if (!strcmp(argv[i], "rectangle"))
            {
                render_loop = rectangle_lesson;
            }
            else if (!strcmp(argv[i], "two_triangles_1"))
            {
                render_loop = two_triangles_1_lesson;
            }
            else if (!strcmp(argv[i], "two_triangles_2"))
            {
                render_loop = two_triangles_2_lesson;
            }
            else if (!strcmp(argv[i], "two_triangles_3"))
            {
                render_loop = two_triangles_3_lesson;
            }
            else if (!strcmp(argv[i], "uniform"))
            {
                render_loop = uniforms_lesson;
            }
            else if (!strcmp(argv[i], "attributes"))
            {
                render_loop = more_attributes_lesson;
            }
            else if (!strcmp(argv[i], "invert"))
            {
                render_loop = invert_triangle_lesson;
            }
            else if (!strcmp(argv[i], "horizontal"))
            {
                render_loop = horizontal_offset_lesson;
            }
            else if (!strcmp(argv[i], "vertex_as_color"))
            {
                render_loop = vert_color_lesson;
            }
            else if (!strcmp(argv[i], "smiling_box"))
            {
                render_loop = smiling_box_lesson;
            }
            else if (!strcmp(argv[i], "transformation"))
            {
                render_loop = transformation_lesson;
            }
            else if (!strcmp(argv[i], "coordinates"))
            {
                render_loop = coordinate_lesson;
            }

            if (render_loop != NULL)
            {
                break;
            }
        }

        i++;
    }

    if (render_loop != NULL)
    {
        int res = render_loop();
        return res;
    }

    const char *help = "\n[ HELP ]\n"
                       "--example\tone of the following:\n"
                       "\t\ttriangle\n"
                       "\t\trectangle\n"
                       "\t\ttwo_triangles_1\n"
                       "\t\ttwo_triangles_2\n"
                       "\t\ttwo_triangles_3\n"
                       "\t\tuniform\n"
                       "\t\tattributes\n"
                       "\t\tinvert\n"
                       "\t\thorizontal\n"
                       "\t\tvertex_as_color\n"
                       "\t\tsmiling_box\n"
                       "\t\ttransformation\n";

    fprintf(stderr, "%s", "[ ERROR ]: No render loop assigned\n");
    fprintf(stderr, "%s", help);
    return 1;
}
