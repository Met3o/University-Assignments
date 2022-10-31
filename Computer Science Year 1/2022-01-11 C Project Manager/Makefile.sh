#!/bin/bash
gcc -Wall -pedantic main.c pmfolder/checkdir/checkdir.c pmfolder/makedir/makedir.c pmfolder/deletedir/deletedir.c pmfolder/deletedir/deletedirP.c pmwrite/readTestfile.c pmfolder/foldersearch/subfoldersearch.c pmfolder/foldersearch/currentfoldersearch.c -o pmout
sudo cp -f pmout /usr/bin/pmfolder

chmod u+x pmgit/pmgitscript.sh
chmod u+x pmwrite/pmwritestuff.sh

sudo cp -f Makefile.sh /usr/bin/Makefile

sudo cp -f pmgit/pmgitscript.sh /usr/bin/pmgit
sudo cp -f pmwrite/pmwritestuff.sh /usr/bin/pmwrite

