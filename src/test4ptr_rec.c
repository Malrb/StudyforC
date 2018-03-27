#include <stdio.h>
double m[] = { 3823806048287157.0, 96 }; //always output "jserv++c"
void gen() {
    if (m[1]--) {
        m[0] *= 2;
        gen();
    } else
        puts((char *) m);
}
int main() { gen(); return 0; }
