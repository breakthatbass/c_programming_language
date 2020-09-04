/* *
 * Exercise 7-3: Revise minprintf to handle more of the other
 * facilities of printf.
 * */

#include <stdarg.h>
#include <stdio.h>

// minprintf: minimal printf with variable argument list
void minprintf(char *fmt, ...)
{
    va_list ap;     // points to each unnamed arg in turn
    char *p, *sval;
    int ival;
    double dval;
    // add ons...
    unsigned uval;
    short shval;
    long lval;

    va_start(ap, fmt);  // make ap point to 1st unnamed arg
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'u':
                uval = va_arg(ap, unsigned);
                printf("%u", uval);
                break; 
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);     // clean up when done
}

int main()
{
    char *s = "hello";
    int n = 23;
    double f = 3.2;
    unsigned u = 12;

    
    minprintf("%s\n", s);
    minprintf("%d\n", n);
    minprintf("%f\n", f);
    minprintf("%u\n", u);

    return 0;

}
