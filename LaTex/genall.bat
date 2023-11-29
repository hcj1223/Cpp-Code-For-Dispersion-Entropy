@echo off
for %%a in (*.tex) do xelatex %%a
REM for %%b in (*.aux) do bibtex %%b
REM for %%c in (*.tex) do xelatex %%c
for %%c in (*.tex) do xelatex %%c 
REM move *.pdf build/
cls