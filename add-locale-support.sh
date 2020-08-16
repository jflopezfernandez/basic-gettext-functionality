#!/usr/bin/bash

if [[ $# -eq 0 ]]
then
    echo 'Usage: add-locale-support <Locale> [<Locale> ...]' >&2
    exit 1
elif [[ "$1" == "save" ]]
then
    shift

    for locale in $@
    do
        msgfmt -o $locale/LC_MESSAGES/basic.mo $locale.po
    done

    exit
fi

for locale in $@
do
    msginit --no-translator --input=po/basic.pot --locale=$locale
    sed -i -E 's/ASCII/UTF-8/' $locale.po
    mkdir -p $locale/LC_MESSAGES/
    msgfmt -o $locale/LC_MESSAGES/basic.mo $locale.po
done
