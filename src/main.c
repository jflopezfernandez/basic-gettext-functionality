
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <libintl.h>

#ifndef LOCAL_LOCALE_DIRECTORY
#define LOCALE_DIRECTORY "/usr/local/share/locale"
#else
#define LOCALE_DIRECTORY getenv("PWD")
#endif /** LOCAL_LOCALE_DIRECTORY */

#ifndef _
#define _(string) gettext(string)
#endif /** _ */

int main(void)
{
    const char* locale_dir = LOCALE_DIRECTORY;

    char* locale = setlocale(LC_ALL, "");

    if (locale == NULL) {
        fprintf(stderr, "Failed to set the current locale.\n");
        return EXIT_FAILURE;
    }

    locale = bindtextdomain("basic", locale_dir);

    if (locale == NULL) {
        fprintf(stderr, "Failed to bind the text domain.\n");
        return EXIT_FAILURE;
    }

    char* text_domain = textdomain("basic");

    if (text_domain == NULL) {
        fprintf(stderr, "Failed to set the current message domain.\n");
        return EXIT_FAILURE;
    }

    printf("%s\n", _("Hello, world!"));
    
    return EXIT_SUCCESS;
}
