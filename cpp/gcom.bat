@echo off
doskey cc=gcc -Wall -pipe -o2 -o a.out $* -lm
doskey ccp=g++ -Wall -pipe -o2 -o a.out $* -lm
doskey np=notepad $*
doskey npp=notepad++ $*
doskey cb=codeblocks $*
doskey sl=sublime_text.exe $* $* $*
