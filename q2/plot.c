// ./plot <data_txt> <output_png> <title>
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    FILE *g;
    assert(g=popen("gnuplot", "w"));

    fprintf(g, "set term png\n");
    assert(fprintf(g, "set output '%s'\n", argv[2]));
    assert(fprintf(g, "set title '%s'\n", argv[3]));

    fprintf(g, "set grid\n");
    fprintf(g, "set style data histogram\n");
    fprintf(g, "set style fill transparent solid 0.9 noborder\n");
    fprintf(g, "set boxwidth 0.9 relative\n");
    fprintf(g, "set style histogram gap 1.6\n");
    fprintf(g, "\n");

    assert(fprintf(g, "p '%s' u 2:xtic(1) lc rgb 'royalblue' notitle, ", argv[1]));
    fprintf(g, "'' u 0:2:2 with labels notitle\n");
    fclose(g);
    return 0;
}
